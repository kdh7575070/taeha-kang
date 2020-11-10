# 모듈로딩 --------------------------------------------
import pandas as pd
from sklearn import svm, metrics
from sklearn.model_selection import train_test_split
import os.path
from urllib import request

# 데이터 변수 선언 ---------------------------------------
DEBUG = True

# 데이터 다운로드 및 파일 저장 ----------------------------
DATA_URL = "https://raw.githubusercontent.com/pandas-dev/pandas/master/pandas/tests/data/iris.csv"
CSV_FILE = '../DATA/iris.csv'

# 붓꽃 데이터 파일 다운로드 ---------------------------------
if not os.path.exists(CSV_FILE):
    print("Download DATA")
    request.urlretrieve(DATA_URL, CSV_FILE)

# 붓꽃 CSV 데이터 수집 ----------------------------------
csv = pd.read_csv(CSV_FILE)
if DEBUG :
    print('type(csv) =>', type(csv))
    print(csv.columns)
    print(csv.index)
    print(csv.iloc[0,2])

# 필요한 데이터(column) 추출 ------------------------------
print(csv.columns)
print(csv.index)

csv_data  = csv[["SepalLength","SepalWidth","PetalLength","PetalWidth"]]
csv_label = csv["Name"]

# 학습 데이터와 테스트 전용 데이터 분류 ----------------------
train_data, test_data, train_label, test_label = \
    train_test_split(csv_data, csv_label)

# 데이터 학습 & 예측 ------------------------------------
clf = svm.SVC()
clf.fit(train_data, train_label)    # 학습
pre = clf.predict(test_data)        # 테스트
print('type(clf)=', type(clf))

# 정확도 검사 -----------------------------------------
ac_score = metrics.accuracy_score(test_label, pre)
print("정답률 =", ac_score)