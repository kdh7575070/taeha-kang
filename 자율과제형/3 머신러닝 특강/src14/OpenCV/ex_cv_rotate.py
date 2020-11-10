# 모듈 로딩 -----------------------------------------------
import matplotlib.pyplot as plt
import cv2

# 데이터변수선언 ------------------------------------------------
HAAR_CASCADE = "../DATA/CV_DATA/haarcascade_frontalface_alt.xml"
IMG_NAME     = '../DATA/IMAGE/girl.jpg'

# (1) 캐스케이드 파일 지정해서 검출기 생성
cascade = cv2.CascadeClassifier(HAAR_CASCADE)

# 얼굴 검출하고 영역 표시하기
def face_detect(img):
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    face_list = cascade.detectMultiScale(img_gray, minSize=(300,300))
    # 인식한 부분 표시하기
    for (x,y,w,h) in face_list:
        print("얼굴의 좌표 =", x, y, w, h)
        red = (0, 0, 255)
        cv2.rectangle(img, (x, y), (x+w, y+h), red, thickness=30)

# (1) 이미지 읽기 --------------------------------------
img=cv2.imread(IMG_NAME)
if DEBUG:
    print('type(img) = {}'.format(type(img)))
    print('img.shape = {}'.format(img.shape))

# (2) 이미지 회전 --------------------------------------
height, width, channel = img.shape
print('height {}, width {}, channel {}'.format(height,width,channel))

plt.figure(figsize=(30,50))
for i in range(10):
    ang = i * 10
    # cv2.getRotationMatrix2D((중심점 X좌표, 중심점 Y좌표), 회전각도, 스케일)
    matrix = cv2.getRotationMatrix2D((width/2, height/2), ang, 1)
    # cv2.warpAffine(원본 이미지, 배열, (결과 이미지 너비, 결과 이미지 높이))
    dst = cv2.warpAffine(img, matrix, (width, height))
    face_detect(dst)
    plt.subplot(6, 2, i + 1)
    plt.axis("off")
    plt.title("angle=" + str(ang))
    plt.imshow(cv2.cvtColor(dst, cv2.COLOR_BGR2RGB))

plt.show()