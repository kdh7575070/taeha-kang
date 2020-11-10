import tensorflow as tf

X = [1,2,3]
Y = [1,2,3]

#변수설정
W = tf.Variable(5.0) #W는 결국 1으로 갈껀데 5니까 오른쪽에서 접근하는 과정 보여주겠지 -5면 왼쪽에서 접근할거고

#H(x)=Wx 모델구현, 코스트정의
hypothesis = X * W
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# 코스트 최소화 알고리즘 정의
optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(cost)

#초기화 및 러닝준비
sess = tf.Session()
sess.run(tf.global_variables_initializer())

#W가 어디로 가나 보자
for step in range(100):
  print(step, sess.run(W))
  sess.run(train)