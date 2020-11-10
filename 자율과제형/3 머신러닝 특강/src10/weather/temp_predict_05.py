from sklearn.linear_model import LinearRegression
import pandas as pd
import matplotlib.pyplot as plt

# 데이터 변수 선언 -------------------------------------
TEMP_CSV = "./tem10y.csv"

# ----------------------------------------------------
# 함수
# ----------------------------------------------------
# 과거 6일 데이터 기반으로 학습 데이터 새로 생성 함수
def make_data(data):
    x = []                          # 학습 데이터
    y = []                          # 결과
    interval = 6                    # 6일 단위 누적평균
    temps = list(data["기온"])

    for i in range(len(temps)):
        if i < interval: continue
        y.append(temps[i]) #6개당 하나의 레이블 저장된다
        xa = []
        for p in range(interval):
            d = i + p - interval #6개를 값의 평균을 저장한다
            xa.append(temps[d])  #마이너스 라벨이 되겠지 -헷갈려
        x.append(xa)
        #뭐 굳이 이렇게 안하고 딕셔너리 만들어줄 수도 있겠지 더 안좋은 코드겠지만!
    return (x, y)

# ----------------------------------------------------
# 데이터 준비
# ----------------------------------------------------
df = pd.read_csv(TEMP_CSV, encoding="utf-8")

#  학습 전용과 테스트 전용 분리
train_year = (df["연"] <= 2015)
test_year  = (df["연"] >= 2016)

# 학습용 & 검증용 데이터 분리
data_train, label_train = make_data(df[train_year])
data_test, label_test   = make_data(df[test_year])

# ----------------------------------------------------
# 학습
# ----------------------------------------------------
lr = LinearRegression(normalize=True)
lr.fit(data_train, label_train)
pre = lr.predict(data_test)

# 결과 평가 - 직접하는 방법
diff = abs(pre - label_test)
print('average=', sum(diff)/len(diff))   # 오차 평균
print('max=', max(diff))                   # 최대값
print(lr.coef_, lr.intercept_) #w, b 보기

ac_score = lr.score(data_test, label_test)  #linear Regression 일때
print("정답률 =", ac_score)

# ----------------------------------------------------
# 출력 - 그래프로비교
# ----------------------------------------------------
plt.figure(figsize=(10, 6), dpi=100)
plt.plot(label_test, c='r')
plt.plot(pre, c='b')
plt.savefig('tenki-kion-lr.png')
plt.show()