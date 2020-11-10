#모듈로딩
from sklearn import svm, metrics
import random, re

# 붓꽃의 CSV 데이터 읽어 들이기
csv = []
with open ('./DATA/iris.csv', 'r', encoding='utf 8') as fp:
    # 한 줄씩 읽어 들이기
    for line in fp:
        line = line.strip() # 줄바꿈 제거
        cols = line.split(',') # 쉼표로 자르기
        # 문자열 데이터를 숫자로 변환하기
        fn = lambda n : float (n) if re.match(r'^[0-9\.]+$',n) else n
        cols = list(map(fn,cols))
        csv.append(cols)

# 가공 데이터 확인
for item in csv: print(item)

# 가장 앞 줄의 헤더 제거
del csv[0]

#학습 데이터 & 테스트 데이터 분할
random.shuffle(csv)

#데이터 분할하기 (2:1 비율)
total_len = len(csv)
train_len = int(total_len*8/9)
train_data = []
train_label = []
test_data = []
test_label = []

for i in range(total_len):
    data = csv[i][0:4]
    label = csv[i][4]
    if i < train_len :
        train_data.append(data)
        train_label.append(label)
    else :
        test_data.append(data)
        test_label.append(label)

# 데이터 학습 & 예측하기
clf = svm.SVC()
clf.fit(train_data, train_label) #학습
pre = clf.predict(test_data) # 테스트

# 정확도 검사
ac_score = metrics.accuracy_score(test_label, pre)
print("정답률 =", ac_score)