import tensorflow as tf
# 편하게 배열로 들어간다
x_data = [[73., 80., 75.], [93., 88., 93.], [89., 91., 90.], [ 96., 98., 100.], [73., 66., 70.]]
y_data = [[152.], [185.], [180.], [196.], [142.]]

# 변수설정
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