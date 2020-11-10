# 2-2 간단하게 빼서 분석하기

import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics
from sklearn.model_selection import train_test_split

#데이터 읽어 들이기
wine = pd.read_csv("../DATA/WINE/winequality-whitewine.csv", sep=';', encoding="utf-8")
#구분자가 ;니까 이렇게 읽어와야한다 ;때문에 utf처리도

#리스트, 딕셔너리화
y = wine["quality"]
x = wine.drop("quality", axis=1)  #원래는 슬라이싱해왔는데 이번에는 drop이라는 방법을 쓴다
                                  #즉 quality를 빼고 열방향으로 쪼개서 11개를 만드는 것

#학습 전용과 테스트 전용 데이터로 나누기
data_train, data_test, label_train, label_test = \
    train_test_split(x, y, test_size=0.2)

#데이터 학습시키기
clf = RandomForestClassifier()
clf.fit(data_train, label_train)

#데이터 예측하기
predict = clf.predict(data_test)

#결과 테스트하기
ac_score = metrics.accuracy_score(label_test, predict)
cl_report = metrics.classification_report(label_test, predict)
print("정답률 =", ac_score)
print("리포트 =", cl_report)

#이번껀 각각의 속성마다 하나의 값(숫자)를 가지므로 표준화를 안해줘도 된다
#결과가 좋지 않다 - 이렇게 데이터를 가공하면 안되는 것이다
#왜그럴까? 1등급과 10등급이 골고루 분포되있지 않기 때문 -> 그 확률 분포를 알아내서 확률에 따라 정규화 시켜주어야한다
#살펴보면 6쪽에 절반 이상이 쏠려있다 - 10등급 짜리를 3등급 짜리로 구간을 바꾸는 방법으로 레이블을 조정해주어야한다
#재 레이블링 후에는 상중하로도 분석이 안되면 ??? 레벨링을 다른방식으로 해주던지 디씨젼트리의 속성을 튜닝해줘야한다
#즉 애초에 데이터 분석을 제대로 한 후에 정확한 모델/혹은 방식으로 접근해야 하는것 -다른 고차원 모델이 존재할 수도 있다!!