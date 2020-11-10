import tensorflow as tf
import numpy as np
tf.set_random_seed(777) #난수를 일정하게 주겠다 - 몇번을 반복하든 어느컴퓨터에서 쓰든 같은난수배열

# numpy로 데이터 불러온다
xy = np.loadtxt('./DeepLearningZeroToAll-master/data-01-test-score.csv',
                delimiter=',', dtype=np.float32)
x_data = xy[:, 0:-1]
y_data = xy[:, [-1]] #따오는 건 판다스와 같다

print(x_data.shape, x_data, len(x_data))
print(y_data.shape, y_data)

#여기서부턴 그대로
X = tf.placeholder(tf.float32, shape=[None, 3]) #이제 이렇게 입력 셰입을 지정해주자
Y = tf.placeholder(tf.float32, shape=[None, 1]) #출력 셰입도

W = tf.Variable(tf.random_normal([3, 1], name='weight')) #그걸 받아주는 웨이트 셰입도 바꿔줘야겠지
b = tf.Variable(tf.random_normal([1], name='bias'))

# H(x)=Wx+b 모델구현, 코스트정의
hypothesis = tf.matmul(X,W) + b #행렬연산함수
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# 코스트 최소화 알고리즘 정의
optimizer = tf.train.GradientDescentOptimizer(learning_rate=1e-5)
train = optimizer.minimize(cost)

# 초기화 및 러닝준비
sess = tf.Session()
sess.run(tf.global_variables_initializer())

# Fit the line
for step in range(2001):
  cost_val, hy_val, _ = sess.run([cost, hypothesis, train],
                                 feed_dict={X:x_data, Y:y_data})
  if step % 10 == 0:
    print(step, "Cost:", cost_val, "\nPrediction:\n", hy_val)

# 내꺼예측 - 테스팅 -> 원래라면 정확도 예측도 구현해줘야지? 복잡해서 생략
print("Your score will be ", sess.run(hypothesis, feed_dict={X: [[100, 70, 101]]}))