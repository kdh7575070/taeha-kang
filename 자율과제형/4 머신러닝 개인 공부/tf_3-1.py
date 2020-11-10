import tensorflow as tf

x_train = [1,2,3]
y_train = [1,2,3]

#변수설정
W = tf.Variable(tf.random_normal([1]), name='weight')
X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

#H(x)=Wx 모델구현, 코스트정의
hypothesis = X * W
cost = tf.reduce_sum(tf.square(hypothesis - Y))

#Gradient descent 풀어서 정의해보자
learning_rate = 0.1
gradient = tf.reduce_mean((W * X - Y) * X)
descent = W - learning_rate*gradient
update = W.assign(descent)

#초기화 및 러닝준비
sess = tf.Session()
sess.run(tf.global_variables_initializer())

# W가 어디로 가나보자
for step in range(21):
  sess.run(update, feed_dict={X: x_train, Y: y_train})
  print(step, sess.run(cost,feed_dict={X: x_train, Y: y_train}), sess.run(W))