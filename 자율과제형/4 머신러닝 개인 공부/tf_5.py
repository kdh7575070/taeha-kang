import tensorflow as tf

x_data = [[1,2],[2,3],[3,1],[4,3],[5,3],[6,2]]
y_data = [[0],[0],[0],[1],[1],[1]]

X = tf.placeholder(tf.float32, shape=[None, 2])
Y = tf.placeholder(tf.float32, shape=[None, 1])

W = tf.Variable(tf.random_normal([2, 1], name='weight'))
b = tf.Variable(tf.random_normal([1], name='bias'))

# H(x) 모델구현, 코스트정의
hypothesis = tf.sigmoid(tf.matmul(X, W) + b) #시그모이드를 씌워줘야한다

cost = -tf.reduce_mean(Y*tf.log(hypothesis) + (1-Y)*tf.log(1 - hypothesis))

# 코스트 최소화 알고리즘 정의 - 한번에
train = tf.train.GradientDescentOptimizer(learning_rate=0.01).minimize(cost)

# 정확도 계산
# 1. 결과를 T/F로 판단해서 float 타입으로 저장한 후에 train을 돌린다
# 2. 예측값과 실제값비교해서 그 결과를 또 float타입으로 저장해서 그걸 평균낸다 -> 정확도 계산
predicted = tf.cast(hypothesis > 0.5, dtype=tf.float32)
accuracy = tf.reduce_mean(tf.cast(tf.equal(predicted, Y), dtype=tf.float32))

# 학습 - 예외처리
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    # Fit the line
    for step in range(10001):
        cost_val, _ = sess.run([cost, train],
                                     feed_dict={X:x_data, Y:y_data})
        if step % 20 == 0:
            print(step, "Cost:", cost_val)

    # 훈련시킨 모델 가지고 원래 데이터 정확도 예측 - 테스팅
    h, c, a = sess.run([hypothesis, predicted, accuracy],
                       feed_dict={X:x_data, Y:y_data})
    print("\nHypothesis: ", h, "\nCorrect (Y): ", c, "\nAccuracy: ", a)