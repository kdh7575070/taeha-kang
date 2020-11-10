# 모듈 로딩 -------------------------------------------------
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics
from sklearn.model_selection import train_test_split

DEBUG = False

# --------------------------------------------------
# 데이터 준비
# --------------------------------------------------
# 데이터 가져오기
mr = pd.read_csv("../DATA/MUSH/mushroom.csv", header=None)
# 데이터 내부의 분류 변수 전개하기
label = []
data = []

#데이터 표준화를 위한 정규화 방법...
#리스트를 만들어 속성마다 카운팅을 해주는 것이다
#카운팅 리스트를 만드는 것이 매우 복잡하다
attr_list = []
for row_index, row in mr.iterrows():
    label.append(row.iloc[0])                   # 독버섯 & 일반버섯 분류
    print('row.iloc[0] =>', row.iloc[0])

    exdata = []
    for col, v in enumerate(row.iloc[1:]):      # 버섯 22가지 속성 데이터
                                                # 반복문 사용 시 몇 번째 반복문인지 확인이 필요할 수 있습니다. 이때 사용합니다.
                                                # 인덱스 번호와 컬렉션의 원소를 tuple형태로 반환합니다.

        if row_index == 0:
            attr = {"dic": {}, "cnt":0}
            attr_list.append(attr)              # 가로 인덱스니까 아무것도 안넣는다
        else:
            attr = attr_list[col]
        if DEBUG: print(row_index, col, 'attr =>', attr)  # 최초값 (1,1, 아니고 (0,0, 임 라벨링 주의
        if DEBUG: print(row_index, col, 'attr_list =>', attr_list)

        # 버섯 특징 기호 저장 최소 2개 ~ 최대 12개
        d = [0,0,0,0,0,0,0,0,0,0,0,0] #하나의 속성마다 값을 넣어준다 최소2개~최대12개라서 12개짜리 리스트를 만드는 것
                                      #즉 마지막에는 12 X 23(속성)-1(속성라벨은떼기) 짜리 리스트가 만들어진다 cnt는 모두 총인덱스의개수 약 8000 이 될것임
        if v in attr["dic"]:
            idx = attr["dic"][v]
            if DEBUG: print('v =>', v,  'attr["dic"][v] = ', idx)
        else:
            idx = attr["cnt"]
            attr["dic"][v] = idx
            attr["cnt"] += 1
            if DEBUG: print('idx =>', idx, 'attr["dic"][v] = ', attr["dic"][v])
        d[idx] = 1
        exdata += d
        if DEBUG: print(row_index, col, 'd[idx] =>', d[idx])
        if DEBUG: print(row_index, col, 'd =>', d, "exdata=>", exdata)
        if DEBUG: print(row_index, col, 'attr =>', attr)
        if DEBUG: print(row_index, col, 'attr_list =>', attr_list)
        if DEBUG: print("\n")
    data.append(exdata)

# --------------------------------------------------
# 학습
# --------------------------------------------------
# 학습 전용과 테스트 전용 데이터 준비
data_train, data_test, label_train, label_test = \
train_test_split(data, label)

# 데이터 학습
clf = RandomForestClassifier()
clf.fit(data_train, label_train)

# 데이터 예측
predict = clf.predict(data_test)

# --------------------------------------------------
# 결과 출력
# --------------------------------------------------
# 결과 테스트
ac_score = metrics.accuracy_score(label_test, predict)
print("정답률 =", ac_score)