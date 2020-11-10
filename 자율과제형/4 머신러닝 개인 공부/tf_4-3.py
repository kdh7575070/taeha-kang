import tensorflow as tf

# step 1 : 파일들의 리스트를 가지고오기- 있는 파일 다 가지고올 수 있다
filename_queue = tf.train.string_input_producer(
    ['./DeepLearningZeroToAll-master/data-01-test-score.csv'], shuffle=False, name='filename_queue')

#shuffle 하고 싶다면? True를 쓰면 된다 아래가 그 함수모델
"""
min_after_dequeue = 10000
capacity = min_after_dequeue +  3 * batch_size
example_batch, label_batch = tf.train.shuffle_batch(
    [example, label], batch_size=batch_size, capacity=capacity, minafter_dequeue=min_after_dequeue)
"""

# step 2 : 파일을 읽어올 리더를 정의하고 읽어온다 -text 읽을꺼니까 이렇게 정의
reader = tf.TextLineReader()
key, value = reader.read(filename_queue)

# step 3 : 읽어온 밸류값을 어떻게 parsing 할 것인가를 정의해준다
record_defaults = [[0.], [0.], [0.], [0.]] #데이터타입을 플로팅포인트로 구성된 네개의 리스트로 정의한다
# 원래 되는데 버전 에러나서 일단은 0. 대신 0 으로 int 타입으로 0 을 넣었다가 다시 복구해서 컴파일 해주었다
# 열이 많다면 record_defaults = [[0.] for row in range(10000)] 요렇게 해줄 수 있겠지
xy = tf.decode_csv(value, record_defaults=record_defaults)

# step 4 : 배치를 통해서 그 값들을 읽어온다
train_x_batch, train_y_batch = \
    tf.train.batch([xy[0:-1], xy[-1:]], batch_size=10) #여기서는 10개씩 묶어서 읽어오는 것이다
### 데이터가 이렇게 작을수록 batch_size를 작게하면 분석이 안된다 batch는 클수록 좋지만 속도문제로 나누는 것 뿐

#여기서부턴 그대로
X = tf.placeholder(tf.float32, shape=[None, 3]) #이제 이렇게 입력 셰입을 지정해주자
Y = tf.placeholder(tf.float32, shape=[None, 1]) #출력 셰입도

W = tf.Variable(tf.random_normal([3, 1], name='weight')) #그걸 받아주는 웨이트 셰입도 바꿔줘야겠지
b = tf.Variable(tf.random_normal([1], name='bias'))

# H(x)=Wx+b 모델구현, 코스트정의
hypothesis = tf.matmul(X, W) + b #행렬연산함수
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# 코스트 최소화 알고리즘 정의
optimizer = tf.train.GradientDescentOptimizer(learning_rate=1e-5)
train = optimizer.minimize(cost)

# 초기화 및 러닝준비
sess = tf.Session()
sess.run(tf.global_variables_initializer())

# Step 5 : 통상적으로 이렇게 쓴다고 알아두라
coord = tf.train.Coordinator()
threads = tf.train.start_queue_runners(sess=sess, coord=coord)

# Fit the line
for step in range(2001):
    x_batch, y_batch = sess.run([train_x_batch, train_y_batch]) #배치를 꼭 먼저 세션해준다!!
    cost_val, hy_val, _ = sess.run([cost, hypothesis, train],
                                 feed_dict={X:x_batch, Y:y_batch})
    if step % 10 == 0:
        print(step, "Cost:", cost_val,
              "\nPrediction:\n", hy_val)

print("Your score will be ", sess.run(hypothesis, feed_dict={X: [[100, 70, 101]]}))

# Step 6 : 통상적으로 이렇게 쓴다고 알아두라
coord.request_stop()
coord.join(threads)