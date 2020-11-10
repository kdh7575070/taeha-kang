import matplotlib.pyplot as plt
import cv2
import os

# 데이터변수선언 ------------------------------------------------
HAAR_CASCADE = "../DATA/CV_DATA/haarcascade_frontalface_alt.xml"
IMG_FILE     = '../DATA/IMAGE/family.jpg'

# (1) 캐스케이드 파일 지정해서 검출기 생성 ------------------------
cascade = cv2.CascadeClassifier(HAAR_CASCADE)

# 지정된 부분 모자이크 처리 함수 ---------------------------------
def mosaic(img, rect, size):
    # 모자이크 적용할 부분 추출하기
    (x1, y1, x2, y2) = rect
    w = x2 - x1
    h = y2 - y1
    i_rect = img[y1:y2, x1:x2]

    # 축소하고 확대하기
    i_small = cv2.resize(i_rect, (size, size))
    # interpolation(보간법): 영상 이미지 변형시 주변 pixel 정보 값 으로 픽셀 값 설정
    i_mos = cv2.resize(i_small, (w, h), interpolation=cv2.INTER_AREA)

    # 모자이크 적용하기
    img2 = img.copy()
    img2[y1:y2, x1:x2] = i_mos
    return img2

# (2) 이미지를 읽어 들이고 그레이스케일로 변환 ----------------------------
img = cv2.imread(IMG_FILE)
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# (3) 얼굴 검출하기
face_list = cascade.detectMultiScale(img_gray, minSize=(150,150))
if len(face_list) == 0: quit()

# (4) 인식한 부분에 모자이크 처리
for (x,y,w,h) in face_list:
    img = mosaic(img, (x, y, x+w, y+h), 10)

# (5) 이미지 출력하기
newfile=os.path.dirname(IMG_FILE) + '/family-mosaic.png'
print('newfile = ', newfile)
cv2.imwrite(newfile, img)
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
plt.show()


