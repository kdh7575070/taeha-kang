import joblib
from sklearn import model_selection, svm, metrics
from sklearn.model_selection import train_test_split
import pandas as pd

#키와 몸무게 데이터 읽기
tbl = pd.read_csv("../DATA/bmi.csv")

#칼럼 자르고 정규화해서 붙이기
label = tbl["label"]
w = tbl["weight"] / 100 #최대 100kg 이라고 가정
h = tbl["height"] / 200 #최대 200kg 이라고 가정
wh = pd.concat([w,h], axis=1) #axis =0 은 로우, axis =1 은 컬럼 즉 두 컬럼을 붙이겠다는 뜻
print(wh)
print(label)

#학습 전용 데이터와 테스트 전용 나누기
data_train, data_test, label_train, label_test = \
    train_test_split(wh, label)

#데아터 학습하기
clf = svm.SVC()
clf.fit(data_train,label_train)

#데이터 예측하기
predict = clf.predict(data_test)

#결과테스트하기
ac_score = metrics.accuracy_score(label_test, predict)
cl_report = metrics.classification_report(label_test, predict)
print("정답률 =", ac_score)
print("리포트 =",cl_report)
print(wh)

#저장
joblib.dump(clf, "../DATA/bmi.pkl")  # 검출/분류기 파일 저장
print("ok")