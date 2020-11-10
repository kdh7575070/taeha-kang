import tensorflow as tf

x_train = [1, 2, 3]
y_train = [1, 2, 3]

# 변수설정
W = tf.Variable(tf.random_normal([1], name='weight'))
b = tf.Variable(tf.random_normal([1], name='bias'))

# H(x)=Wx 모델구현, 코스트(Loss function)정의
hypothesis = x_train * W + y_train
cost = tf.reduce_mean(tf.square(hypothesis - y_train))

# 코스트 최소화 알고리즘 정의
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
train = optimizer.minimize(cost)

# 초기화 및 러닝준비
sess = tf.Session()
sess.run(tf.global_variables_initializer())

# Fit the line
for step in range(2001):
  sess.run(train)
  if step % 20 == 0:
    print(step, sess.run(cost), sess.run(W), sess.run(b))