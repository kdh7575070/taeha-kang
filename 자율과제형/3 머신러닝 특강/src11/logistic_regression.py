import tensorflow as tf

# 데이터 준비 & 노드 정의 -------------------------------------
# 학습 데이터
x_data = [[1, 2],[2, 3],[3, 1],[4, 3],[5, 3],[6, 2]]
y_data = [[0],[0],[0],[1],[1],[1]]

# 변수
X = tf.placeholder(tf.float32, shape=[None, 2])
Y = tf.placeholder(tf.float32, shape=[None, 1])
W = tf.Variable(tf.random_normal([2, 1]), 'weight')
b = tf.Variable(tf.random_normal([1]), 'bias')

# 가설 정의 => 출력결과값 0 ~ 1 사이 범위 변환
hypothesis = tf.sigmoid(tf.matmul(X, W) + b)

# 비용 함수 정의 => Y가 0일때, Y가 1일때별 COST 계산
cost = -tf.reduce_mean(Y * tf.log(hypothesis) + (1 - Y) * tf.log(1 - hypothesis))

# 텐서보드를 위한 요약정보(scalar) 정의
tf.summary.scalar('cost', cost)

# cost function 최소화
optimizer = tf.train.GradientDescentOptimizer(learning_rate=1e-2)
train = optimizer.minimize(cost)

# True if hypothesis > 0.5 else false
predicted = tf.cast(hypothesis > 0.5, dtype=tf.float32)
# 정확도 체크
accuracy = tf.reduce_mean(tf.cast(tf.equal(predicted, Y), dtype=tf.float32))

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    for step in range(10001):
        cost_val, train_val = sess.run(
            [cost, train],
            feed_dict={X: x_data, Y: y_data}
        )
        if step % 200 == 0:
            print(step, "\tcost : ", cost_val)

    # Accuracy report
    hypo_val, predict_val, acc_val = sess.run( [hypothesis, predicted, accuracy],feed_dict={X: x_data, Y: y_data})

    print("\nHypothesis : ", hypo_val, "\nCorrect(Y) : ", predict_val, "\nAccuracy : ", acc_val)