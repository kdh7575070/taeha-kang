import tensorflow as tf
# 이렇게 변수가 여러개라고 보자
x1_data = [73., 93., 89., 96., 73.,]
x2_data = [80., 88., 91., 98., 66.,]
x3_data = [75., 93., 90., 100., 70.,]
y_data = [152., 185., 180., 196., 142.,]

# 변수설정 -> 코드반복 -> 좋지않다
x1 = tf.placeholder(tf.float32)
x2 = tf.placeholder(tf.float32)
x3 = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

w1 = tf.Variable(tf.random_normal([1], name='weight1'))
w2 = tf.Variable(tf.random_normal([1], name='weight2'))
w3 = tf.Variable(tf.random_normal([1], name='weight3'))
#웨이트도 맞춰서 넣어주기
b = tf.Variable(tf.random_normal([1], name='bias'))

# H(x) 모델구현, 코스트정의
hypothesis = x1*w1 + x2*w2 + x3*w3 + b
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
                                 feed_dict={x1: x1_data, x2: x2_data, x3: x3_data, Y:y_data})
  if step % 10 == 0:
    print(step, "Cost:", cost_val, "\nPrediction:\n", hy_val)