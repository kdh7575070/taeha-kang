import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics
from sklearn.model_selection import train_test_split

#데이터 읽어 들이기
mr = pd.read_csv("../DATA/MUSH/mushroom.csv", header = None) #헤더를 받아서 쓸꺼면 빼고 안받고 익덱스로 쓸꺼면 None 해준다
                                                             #여기는 헤더가 없다

#데이터 내부의 기호를 숫자로 변환하기
label = []
data = []

for row_index, row in mr.iterrows():
    print('row_index =>', row_index)
    print('row =>', row)
    label.append(row.iloc[0]) #라벨 하나씩 떼서 넣는다
    print('label =>', row.iloc[0])

    row_data = []
    for v in row.iloc[1:]: #데이터는 쭉 떼서 리스트로 넣는다
        row_data.append(ord(v))

    print('row_data =>', row_data)
    data.append(row_data)

#학습 전용과 테스트 전용 데이터로 나누기
data_train, data_test, label_train, label_test = \
    train_test_split(data, label)

#데이터 학습예측
clf = RandomForestClassifier()
clf.fit(data_train, label_train)
predict = clf.predict(data_test)

#결과 테스트하기
ac_score = metrics.accuracy_score(label_test, predict)
cl_report = metrics.classification_report(label_test, predict)
print("정답률 =", ac_score)
print("리포트 =", cl_report)