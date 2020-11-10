# 모듈 로딩 -------------------------------------
import pandas as pd
from sklearn import svm, metrics

# 데이버 변수 선언 --------------------------------
# XOR 연산
xor_input = [
    [0, 0, 0],
    [0, 1, 1],
    [1, 0, 1],
    [1, 1, 0]
]

# (1) 입력을 학습 전용 데이터와 테스트 전용 데이터로 분류
xor_df = pd.DataFrame(xor_input)
print("---- xor_df -----\n", xor_df )
xor_data = xor_df.iloc[:, 0:2]           #iloc[행, 열 index]
xor_label = xor_df.iloc[:,2]

print("---- xor_data -----\n", xor_data )
print("---- xor_label -----\n", xor_label )

# 데이터 학습과 예측
clf = svm.SVC()
clf.fit(xor_data, xor_label)  # 학습
pre = clf.predict(xor_data)   # 예측

# 정답 추출
ac_score = metrics.accuracy_score(xor_label, pre)
print("정답률 =", ac_score)