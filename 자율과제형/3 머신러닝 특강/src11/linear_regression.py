# -*- coding: utf-8 -*-
import tensorflow as tf

# (1) 노드 정의 ---------------------------------
# 선형회귀 모델(Wx + b)을 정의
W = tf.Variable(tf.random_normal(shape=[1]))
b = tf.Variable(tf.random_normal(shape=[1]))
x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)

# 선형회귀 모델 연산 정의
linear_model = W*x + b
# 손실 함수 정의 - MSE 손실함수, Square Error
loss = tf.reduce_mean(tf.square(linear_model - y))

# 텐서보드를 위한 요약정보(scalar) 정의
tf.summary.scalar('loss', loss)

# 최적화를 위한 그라디언트 디센트 옵티마이저 정의
# 러닝 레이트 => 학습 속도 설정
optimizer = tf.train.GradientDescentOptimizer(0.01)
train_step = optimizer.minimize(loss)

# 트레이닝을 위한 입력값과 출력값을 준비
x_train = [1, 2, 3, 4]
y_train = [2, 4, 6, 8]

# (2) 세션 실행하고 파라미터(W,b)를 normal distirubtion에서 추출한 임의의 값으로 초기화
sess = tf.Session()
sess.run(tf.global_variables_initializer())  # random_normal()에서 임의의 값으로 변수 초기값 할당


# 텐서보드 전달 정보 설정
merged = tf.summary.merge_all()    # 전달 정보 모두 합치기
# 텐서보드 summary 정보들을 저장할 폴더 경로 설정
tensorboard_writer = tf.summary.FileWriter('./linear', sess.graph)

# (3) 모델 학습 실행 : 경사하강법을 1000번 수행
for i in range(1000):
  sess.run(train_step, feed_dict={x: x_train, y: y_train})  # 입력 데이터 지정
  print( i, sess.run(W), sess.run(b))

  # 매스텝마다 텐서보드 요약정보값들을 계산해서 지정된 경로('./tensorboard_log')에 저장
  summary = sess.run(merged, feed_dict={x: x_train, y: y_train})
  tensorboard_writer.add_summary(summary, i)

# (4) 테스트 진행
x_test = [3.5, 5, 5.5, 6]
# 테스트 데이터를 이용해 학습된 선형회귀 모델이 데이터의 경향성(y=2x)을 잘 학습했는지 측정합니다.
# 예상되는 참값 : [7, 10, 11, 12]
print(sess.run(linear_model, feed_dict={x: x_test}))

# (5) 종료
sess.close()