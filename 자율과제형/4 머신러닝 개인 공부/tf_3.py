import tensorflow as tf
import matplotlib.pyplot as plt

x_train = [1,2,3]
y_train = [1,2,3]

#변수설정
# W = tf.Variable(tf.random_normal([1], name='weight') 기존에는 이렇게 했다가
# b = tf.Variable(tf.random_normal([1], name='bias')
W = tf.placeholder(tf.float32) #이번엔 W,b를 placeholder로 해서 나중에 feed 가능

#H(x)=Wx 모델구현, 코스트정의
hypothesis = x_train * W
cost = tf.reduce_mean(tf.square(hypothesis - y_train))

#초기화 및 러닝준비
sess = tf.Session()
sess.run(tf.global_variables_initializer())

#출력할리스트만들어주기
W_val = []
cost_val = []

for i in range(-30, 50):
  feed_W = i * 0.1 #W를 직접 바꿔 그래프를 그려보겠다
  curr_cost, curr_W = sess.run([cost, W], feed_dict={W : feed_W})
  W_val.append(curr_W)
  cost_val.append(curr_cost)

plt.plot(W_val, cost_val)
plt.show()