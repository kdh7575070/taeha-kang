import os.path
import urllib.request as req
import pandas as pd
from sklearn import svm, metrics
from sklearn.model_selection import train_test_split

# urlopen()으로 데이터 수집
url = "https://raw.githubusercontent.com/pandas-dev/pandas/master/pandas/tests/data/iris.csv"
file = 'iris2'

if not os.path.exists('iris2'):
    print("Download Data")
    req.urlretrieve(url, file)

# 붓꽃의 CSV 데이터 읽어 들이기
csv = pd.read_csv(file)
csv_data = csv[["SepalLength","SepalWidth","PetalLength","PetalWidth"]]
csv_label = csv["Name"]

train_data, test_data, train_label,test_label = \
    train_test_split(csv_data,csv_label, test_size=0.25)

clf = svm.SVC()
clf.fit(train_data, train_label)
pre = clf.predict(test_data)

ac_score = metrics.accuracy_score(test_label, pre)
print("정답률 =", ac_score)