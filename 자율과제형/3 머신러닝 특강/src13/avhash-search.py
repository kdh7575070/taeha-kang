from PIL import Image
import numpy as np
import os, re

# 데이터 변수 선언 ----------------------------------------------
search_dir = "../DATA/101_ObjectCategories"
cache_dir = "../DATA/cache_avhash"

if not os.path.exists(cache_dir):  os.mkdir(cache_dir)

# 이미지 데이터를 Average Hash로 변환 함수 -------------------------
def average_hash(fname, size = 16):
    fname2 = fname[len(search_dir):]

    # 이미지 캐시하기
    cache_file = cache_dir + "/" + fname2.replace('/', '_') + ".csv"
    print('cache_file => ', cache_file)

    if not os.path.exists(cache_file): # 해시 생성하기
        img = Image.open(fname)
        img = img.convert('L').resize((size, size), Image.ANTIALIAS)
        pixels = np.array(img.getdata()).reshape((size, size))
        avg = pixels.mean()
        px = 1 * (pixels > avg)
        np.savetxt(cache_file, px, fmt="%.0f", delimiter=",")   # 파일저장
    else: # 캐시돼 있다면 읽지 않기
        print('average_hash')
        px = np.loadtxt(cache_file, delimiter=",")
    return px

# 해밍 거리 측정 함수 --------------------------------------------
def hamming_dist(a, b):
    aa = a.reshape(1, -1)    # 1차원 배열로 변환하기
    ab = b.reshape(1, -1)
    dist = (aa != ab).sum()
    return dist

# 모든 폴더에 처리 적용 -----------------------------------------
def enum_all_files(path):
    for root, dirs, files in os.walk(path):
        for f in files:
            _fname = str(root).replace('\\','/')
            _fname = _fname + '/' + f
            if re.search(r'.(jpg|jpeg|png)$', _fname):
                yield _fname

# 이미지 찾기 ---------------------------------------------------
def find_image(fname, rate):
    # 찾을 이미지
    src = average_hash(fname)

    # 전체 이미지에서 지정한 이미지 찾기
    for fname in enum_all_files(search_dir):
        dst = average_hash(fname)
        diff_r = hamming_dist(src, dst) / 256

        if diff_r < rate:
            yield (diff_r, fname)

# 찾기 ---------------------------------------------------------
srcfile = search_dir + "/chair/image_0016.jpg"
html = ""
sim = list(find_image(srcfile, 0.25))
print('sim =>', sim )

sim = sorted(sim, key=lambda x:x[0])
for r, f in sim:
    print(r, ">", f)
    s = '<div style="float:left;"><h3>[ 차이 :' + str(r) + '-' + \
        os.path.basename(f) + ']</h3>'+ \
        '<p><a href="' + f + '"><img src="' + f + '" width=400>'+ \
        '</a></p></div>'
    html += s

# HTML로 출력-------------------------------------------------------
html = """<html><head><meta charset="utf8"></head>
<body><h3>원래 이미지</h3><p>
<img src='{0}' width=400></p>{1}
</body></html>""".format(srcfile, html)
with open("./avhash-search-output.html", "w", encoding="utf-8") as f:
    f.write(html)
print("ok")