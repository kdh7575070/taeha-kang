import matplotlib.pyplot as plt
import cv2
from scipy import ndimage

# 데이터변수선언 ------------------------------------------------
HAAR_CASCADE = "../DATA/CV_DATA/haarcascade_frontalface_alt.xml"
IMG_FILE     = '../DATA/IMAGE/girl.jpg'
DEBUG        = True

# (1) 캐스케이드 파일 지정해서 검출기 생성
cascade = cv2.CascadeClassifier(HAAR_CASCADE)
if DEBUG: print('cascade = {}'.format(cascade))

# (2) 이미지를 읽어 들이고 그레이스케일로 변환
img = cv2.imread(IMG_FILE)

# 얼굴 검출하고 영역 표시하기
def face_detect(img):
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    face_list = cascade.detectMultiScale(img_gray, minSize=(300,300))
    # 인식한 부분 표시하기
    for (x,y,w,h) in face_list:
        print("얼굴의 좌표 =", x, y, w, h)
        red = (0, 0, 255)
        cv2.rectangle(img, (x, y), (x+w, y+h), red, thickness=30)

# 여러 각도의 이미지를 만들고 테스트하기
for i in range(0, 9):
    ang = i * 10
    print("---" + str(ang) + "---")
    img_r = ndimage.rotate(img, ang)
    face_detect(img_r)
    plt.subplot(3, 3, i + 1)
    plt.axis("off")
    plt.title("angle=" + str(ang))
    plt.imshow(cv2.cvtColor(img_r, cv2.COLOR_BGR2RGB))
        
plt.show()

