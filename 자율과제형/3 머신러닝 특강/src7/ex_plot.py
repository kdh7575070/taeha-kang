# 모듈 로딩 ------------------------------------
from matplotlib import pyplot as plt        # 그래프용
from matplotlib import font_manager as fm   # 한글 폰트 설정
import numpy as np
import matplotlib as mpl
import pandas as pd

# 데이터 변수 선언 ------------------------------
KIND = 12                                  # 예제 동작 번호

# 다양한 plot 예제 -----------------------------
print('Version - ', mpl.__version__)
print('Version - ', mpl.__version__)

# 한글 폰트 설정 ---------------------------------------
font_path = r'C:\Windows\Fonts\malgun.ttf'
font_name = fm.FontProperties(fname=font_path).get_name()
print(font_name)
plt.rc('font', family=font_name)     # mpl.rcParams['font.family'] = 'Gullim'
plt.rc('axes', unicode_minus=False)  # mpl.rcParams['axes.unicode_minus'] = False
# -----------------------------------------------------


if KIND == 1:
    for i in plt.style.available:
        print(i)

    plt.title('라인 플로트')
    plt.plot(['a','c','e'],[3,5,7], 'v')
    plt.plot(['a','b','c','d'], [1,2,3,4])       # 데이터 plot(x축 데이터, y축 데이터)
    plt.xlabel('value')
    plt.ylabel('data')
    plt.legend(['DATA','NEW-DATA'])              # 범례
    plt.show()                                   # 그래프 렌더리 후 화면 출력 & 마우스 이벤트 대기

elif KIND == 2:
    t = np.arange(0., 5., 0.2)
    print('t => ', t)
    plt.title("라인 플롯에서 여러개의 선 그리기")
    plt.plot(t, t, 'r--', t, 0.5 * t ** 2, 'bs:', t, 0.2 * t ** 3, 'g^-')
    plt.show()

elif KIND == 3:
    # x, y color, 선굵기, 선스타일, 마커, 마커크기, 마커선색, 마커선굵기, 마커내부색
    plt.plot([10, 20, 30, 40], [1, 4, 9, 16], c="b",
             lw=6, ls="--", marker="p", ms=15, mec="g", mew=5, mfc="r")
    plt.title("스타일 적용 예")
    plt.xlim(0,50)
    plt.ylim(-10,20)
    plt.show()

elif KIND==4:
    X = np.linspace(-np.pi, np.pi, 256)
    print(len(X), X)
    C = np.cos(X)
    print(len(C), C)
    plt.title("tick label SET")
    plt.plot(X, C)
    plt.xticks([-np.pi, -np.pi / 2, 0, np.pi / 2, np.pi])
    plt.yticks([-1, 0, +1])
    plt.show()

elif KIND == 5:
    y = [5, 3, 7, 10, 9, 5, 3.5, 8]
    x = range(len(y))
    plt.title('바 플로트')
    #plt.bar(x, y, width=0.7, color="blue")
    plt.barh(x, y, height=0.7, color="blue")
    plt.show()

elif KIND==6:
    names  = ['group_a', 'group_b', 'group_c']
    values = [1, 10, 100]

    plt.figure(figsize=(10,10))

    plt.subplot(311)                    # 행,열,번호 131
    plt.bar(names, values)

    plt.subplot(312)                    # 행,열,번호 132
    plt.scatter(names, values)

    plt.subplot(313)
    plt.plot(names, values)

    plt.suptitle('Categorical Plotting')
    plt.show()

elif KIND == 7:
    def f(t):
        return np.exp(-t) * np.cos(2 * np.pi * t)

    t1 = np.arange(0.0, 5.0, 0.1)
    t2 = np.arange(0.0, 5.0, 0.02)
    plt.figure()
    plt.subplot(211)
    plt.plot(t1, f(t1), 'bo', t2, f(t2), 'k')

    plt.subplot(212)
    plt.plot(t2, np.cos(2 * np.pi * t2), 'r--')
    plt.show()
elif KIND == 8:
    np.random.seed(0)
    f1 = plt.figure(figsize=(10, 2))
    plt.title("figure size : (10, 2)")
    plt.plot(np.random.randn(100))
    plt.show()
elif KIND == 9:
    n = 256
    X = np.linspace(-np.pi, np.pi, n, endpoint=True)
    Y = np.sin(2 * X)

    plt.figure(figsize=(10, 8))
    plt.plot(X, Y + 1, color='blue', alpha=1.00)
    plt.fill_between(X, 1, Y + 1, color='blue', alpha=.25)   # 색상 채우기

    plt.plot(X, Y - 1, color='blue', alpha=1.00)
    plt.fill_between(X, -1, Y - 1, (Y - 1) > -1, color='blue', alpha=.25)
    plt.fill_between(X, -1, Y - 1, (Y - 1) < -1, color='red', alpha=.25)

    plt.xlim(-np.pi, np.pi), plt.xticks([])
    plt.ylim(-2.5, 2.5), plt.yticks([])
    plt.show()

elif KIND == 10:
    iris = pd.read_csv('../DATA/iris.csv')
    print('iris.info(0 => ', iris.info())
    print('iris.head(0 => ', iris.head())

    plt.scatter(iris['SepalLength'], iris['SepalWidth'])
    plt.xlabel('SepalLength')
    plt.ylabel('SepalWidth')
    plt.title("IRIS Sepal")
    plt.show()
elif KIND == 11:
    iris = pd.read_csv('../DATA/iris.csv')
    print('iris.info(0 => ', iris.info())
    print('iris.head(0 => ', iris.head())

    colors=[]
    for i in iris['Name']:
        if i == 'Iris-setosa': colors.append(1)
        elif i == 'Iris-versicolor': colors.append(2)
        else: colors.append(3)

    plt.scatter(iris['SepalLength'], iris['PetalLength'], c=colors )
    plt.xlabel('SepalLength')
    plt.ylabel('PetalLength')
    plt.title("IRIS Sepal")
    plt.show()

elif KIND == 12:
    iris = pd.read_csv('../DATA/iris.csv')
    print('iris.info(0 => ', iris.info())
    print('iris.head(0 => ', iris.head())

    colors=[]
    for i in iris['Name']:
        if i == 'Iris-setosa': colors.append(1)
        elif i == 'Iris-versicolor': colors.append(2)
        else: colors.append(3)

    plt.scatter(iris['SepalLength'],
                iris['SepalWidth'],
                s=100*iris['PetalWidth'],
                c=colors,
                label=iris['Name'])
    plt.xlabel('SepalLength')
    plt.ylabel('SepalWidth')
    plt.title("IRIS FLOWER")
    print(iris.columns)
    cb=plt.colorbar()
    plt.show()
