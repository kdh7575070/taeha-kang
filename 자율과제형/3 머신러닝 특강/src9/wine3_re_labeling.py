# 2-3 앞의 분석 모델 한계 극복

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier 
from sklearn.metrics import accuracy_score
from sklearn.metrics import classification_report

# 데이터변수 선언 -----------------------------------------------------
WINE_CSV='../DATA/WINE/winequality-whitewine.csv'    # CSV파일 저장 경로

# --------------------------------------------------------------------
# 데이터 준비
# --------------------------------------------------------------------
# 데이터 읽기
wine = pd.read_csv(WINE_CSV, sep=";", encoding="utf-8")
# 학습 전용과 테스트 전용으로 분리하기

y = wine["quality"]
x = wine.drop("quality", axis=1)

# y 레이블 변경-
newlist = []
for v in list(y):
    if v <= 4:
        newlist += [0]
    elif v <= 7:
        newlist += [1]
    else:
        newlist += [2]
y = newlist

print('newlist =>', newlist)

# --------------------------------------------------------------------
# 학습
# --------------------------------------------------------------------
# 학습 전용과 테스트 전용으로 분리하기
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)

# 학습
model = RandomForestClassifier()
model.fit(x_train, y_train)

# --------------------------------------------------------------------
# 평가 및 성능
# --------------------------------------------------------------------
y_pred = model.predict(x_test)
print(classification_report(y_test, y_pred))
print("정답률=", accuracy_score(y_test, y_pred))