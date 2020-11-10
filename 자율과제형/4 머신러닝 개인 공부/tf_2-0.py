import tensorflow as tf

#변수설정
W = tf.Variable(tf.random_normal([1], name='weight'))
b = tf.Variable(tf.random_normal([1], name='bias'))

X = tf.placeholder(tf.float32, shape=[None]) #이렇게 해서 나중에 feed 가능
Y = tf.placeholder(tf.float32, shape=[None])

#H(x)=Wx 모델구현, 코스트정의
hypothesis = X*W + b
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# 코스트 최소화 알고리즘 정의
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
train = optimizer.minimize(cost)

#초기화 및 러닝준비
sess = tf.Session()
sess.run(tf.global_variables_initializer())

#출력할리스트만들어주기
W_val = []
cost_val = []

#Fit the line
for step in range(2001):
  cost_val, W_val, b_val, _ = \
    sess.run([cost, W, b, train], feed_dict={X: [1,2,3], Y: [1,2,3]})
  if step % 20 == 0:
     print(step, cost_val, W_val, b_val)