import pandas as pd
import numpy as np
import tensorflow as tf
from sklearn.model_selection import train_test_split

DEBUG = True

# (1)데이터 준비 --------------------------------------------
csv = pd.read_csv("../DATA/bmi.csv")

# (2) 데이터 가공 -------------------------------------------
# column이름으로 열단위 데이터 가져와 가공
csv["height"] = csv["height"] / 200    # 0~1사이값으로 정규화
csv["weight"] = csv["weight"] / 100    # 0~1사이값으로 정규화

# String 레이블명 배열로 변환하여 DataFrame에 추가
# thin=(1,0,0) / normal=(0,1,0) / fat=(0,0,1)
bclass = {"thin": [1,0,0], "normal": [0,1,0], "fat": [0,0,1]}
csv["label_pat"] = csv["label"].apply(lambda x : np.array(bclass[x]))
if DEBUG: print(csv.keys())

# 테스트를 위한 데이터 분류
train_csv = csv[:15000]
train_pat = train_csv[["weight","height"]]
train_ans = list(train_csv['label_pat'])

test_csv = csv[15000:20000]                 # csv[행번호] => 지정된 범위 가져오기
test_pat = test_csv[["weight","height"]]    # 지정된 범위의 2개 column 데이터 가져오기
test_ans = list(test_csv["label_pat"])      # one-hot encoding으로 값 리스트로 변경

x_train, x_test, y_train, y_test = train_test_split(test_pat, test_ans, train_size=0.8)

# (3) 데이터 플로우 그래프 구축 -----------------------------------
# 플레이스홀더 선언하기
x  = tf.placeholder(tf.float32, [None, 2])  # 키와 몸무게 데이터 넣기
y_ = tf.placeholder(tf.float32, [None, 3])  # 정답 레이블 넣기

# 변수 선언하기
W = tf.Variable(tf.zeros([2, 3]));          # 가중치
b = tf.Variable(tf.zeros([3]));             # 바이어스

# (4) 소프트맥스 회귀 정의 ---------------------------------------
y = tf.nn.softmax(tf.matmul(x, W) + b)      # Wx+b 가중값 softmax 실수로 변경

# 손실함수 및 최적화 함수 정의 --------------------------------------
cross_entropy = -tf.reduce_sum(y_ * tf.log(y))
#cross_entropy=tf.reduce_mean(-tf.reduce_sum(y_ * tf.log(y) , reduction_indices=[1]))
optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(cross_entropy)

# (5) 정답률 연산 정의 -------------------------------------------
predict = tf.equal(tf.argmax(y, 1), tf.argmax(y_,1))
accuracy = tf.reduce_mean(tf.cast(predict, tf.float32))

# (6) 세션 시작하기 --------------------------------------------
sess = tf.Session()
sess.run(tf.global_variables_initializer())
# 학습시키기
for step in range(3500):
    i = (step * 100) % 14000
    rows  = csv[1 + i : 1 + i + 100]
    x_pat = rows[["weight","height"]]
    y_ans = list(rows["label_pat"])
    fd = {x: x_pat, y_: y_ans}

    #sess.run(train, feed_dict=fd)
    sess.run(train, feed_dict={x: train_pat, y_: train_ans})

    if step % 500 == 0:
        cre = sess.run(cross_entropy, feed_dict=fd)
        acc = sess.run(accuracy, feed_dict={x: test_pat, y_: test_ans})
        #acc = sess.run(accuracy, feed_dict={x: x_train, y_: y_train})
        print("step=", step, "cre=", cre, "acc=", acc)

# 최종적인 정답률 구하기
acc = sess.run(accuracy, feed_dict={x: test_pat, y_: test_ans})
#acc = sess.run(accuracy, feed_dict={x: x_test, y_: y_test})
print("정답률 =", acc)