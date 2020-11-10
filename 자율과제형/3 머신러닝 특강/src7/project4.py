import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics
from sklearn.model_selection import train_test_split

#데이터 읽어 들이기
train = pd.read_csv("./mnist/train.csv", header = None)
test = pd.read_csv("./mnist/t10k.csv", header = None)

#데이터 내부의 숫자떼자
label = []
data = []

def learn(x):
    for row_index, row in x.iterrows():
        label.append(row.iloc[0]) #라벨 하나씩 떼서 넣는다
        print('label =>', row.iloc[0])

        row_data = []
        for v in row.iloc[1:]: #데이터는 쭉 떼서 리스트로 넣는다
            row_data.append(v)

        print('row_data =>', row_data)
        data.append(row_data)

learn(train)
learn(test)

#학습 전용과 테스트 전용 데이터로 나누기
data_train, data_test, label_train, label_test = \
    train_test_split(data, label, test_size=0.3)

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