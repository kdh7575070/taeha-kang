#모듈로딩 -------------------------------------------
import matplotlib.pyplot as plt
import cv2

# 데이터변수선언 ------------------------------------------------
IMG_FILE     = '../DATA/IMAGE/cat.jpg'
MOSAC_IMG    = '../DATA/IMAGE/cat-mosaic.jpg'
DEBUG        = True

# 지정된 부분 모자이크 처리 함수 -----------------------------
def mosaic(img, rect, size):
    # 모자이크 적용할 부분 추출하기
    (x1, y1, x2, y2) = rect
    w = x2 - x1
    h = y2 - y1
    i_rect = img[y1:y2, x1:x2]
    print('i_rect.shape => {}\n'.format(i_rect.shape))

    # 축소하고 확대하기
    i_small = cv2.resize(i_rect, (size, size))
    print('i_small.shape => {}\n'.format(i_small.shape))
    # interpolation(보간법): 영상 이미지 변형시 주변 pixel 정보 값 으로 픽셀 값 설정
    i_mos = cv2.resize(i_small, (w, h), interpolation=cv2.INTER_AREA)
    print('i_mos.shape => {}\n'.format(i_mos.shape))

    # 모자이크 적용하기
    img2 = img.copy()
    img2[y1:y2, x1:x2] = i_mos
    return img2


# 모자이크 처리하기 --------------------------------
img = cv2.imread(IMG_FILE)
mos = mosaic(img, (50, 50, 250, 250), 10)

# 이미지 출력하기
cv2.imwrite( MOSAC_IMG , mos)
plt.imshow(cv2.cvtColor(mos, cv2.COLOR_BGR2RGB))
plt.show()