# 1 직접 리스트만들어 떼주는 방법

# 모듈로딩 -----------------------------------
from urllib import request
import os
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn import svm, metrics

# 데이터 변수 선언 ----------------------------
WINE_URL='https://archive.ics.uci.edu/ml/machine-learning-databases/wine-quality/winequality-whitewine.csv'
WINE_CSV='../DATA/WINE/'    # CSV파일 저장 경로
DEBUG = True

# (1) 데이터 준비 -------------------------------
# URL에서 다운로드
# 데이터 파일 저장 폴더 체크
if not os.path.exists(WINE_CSV): os.makedirs(WINE_CSV)

# 데이터 파일 다운로드
WINE_CSV += 'winequality-white.csv'
if DEBUG: print('WINE_CSV =', WINE_CSV)
request.urlretrieve(WINE_URL, WINE_CSV)

# (2) 데이터 추출 ----------------------------
winecsv= pd.read_csv(WINE_CSV, sep=';', encoding='utf-8')
if DEBUG:
    print('type(winecsv) = {}'.format(type(winecsv)))
    print('winecsv.shape = {}'.format(winecsv.shape))
    print('행(row) 갯수 : winecsv.shape[0] = {}'.format(winecsv.shape[0]))
    print('열(column) 갯수 : winecsv.shape[1] = {}'.format(winecsv.shape[1]))
    print('=== winecsv \n{}\n'.format(winecsv))
    print('=== winecsv.index \n{}\n'.format(winecsv.index))
    print('=== winecsv.columns \n{}\n'.format(winecsv.columns))
    print('=== type(winecsv.columns) \n{}\n'.format(type(winecsv.columns)))
    print('=== winecsv.iloc[0] \n{}\n'.format(winecsv.iloc[0]))


# (3) 학습 & 테스트 데이터 준비 ----------------------------------
list_columns = list(winecsv.columns)  # Index object -> List Object
#data_cols = winecsv[list_columns[:len(winecsv.columns) - 1]]  # 11가지 Wine 성분 데이터 추출
#lable_cols = winecsv[ list_columns[ len(winecsv.columns)-1] ]  # Wine 품질 데이터 추출
data_cols  = winecsv[ list_columns[:winecsv.shape[1]-1] ]
lable_cols = winecsv[ list_columns[ winecsv.shape[1]-1] ]  # Wine 품질 데이터 추출

if DEBUG:
    print('=== data_cols \n{}\n'.format(data_cols))
    print('=== lable_cols \n{}\n'.format(lable_cols))

# 학습용 & 테스트용 데이터 레이블 만들기 75%:25% (기본)
# test_size=값 ( 0.0 ~ 1.0) 범위 => 비율 조절
train_data, test_data, train_label, test_label = \
    train_test_split(data_cols, lable_cols, test_size=0.2)
if DEBUG:
    print('=== train_data 갯수 :{}\n'.format(train_data.shape[0]))
    print('=== test_data 갯수 : {}\n'.format(test_data.shape[0]))

# (4) 학습 & 테스트 ----------------------------------
svc=svm.SVC(gamma='scale')
svc.fit(train_data, train_label)        # 학습
prevalue = svc.predict(test_data)       # 테스트

# 정확도 검사 -----------------------------------------
ac_score = metrics.accuracy_score(test_label, prevalue)
print("정답률 =", ac_score)