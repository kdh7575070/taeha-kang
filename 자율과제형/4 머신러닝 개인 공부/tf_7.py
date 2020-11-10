import tensorflow as tf
#train test set 분리

x_data = [[1,2,1,1,],[2,1,3,2],[3,1,3,4],[4,1,5,5],[1,7,5,5],[1,2,5,6],[1,6,6,6],[1,7,7,7]]
y_data = [[0,0,1],[0,0,1],[0,0,1],[0,1,0],[0,1,0],[0,1,0],[1,0,0],[1,0,0]]
x_test = [[1,7,7,8]]
y_test = [[1,0,0]]

X = tf.placeholder(tf.float32, shape=[None, 4])
Y = tf.placeholder(tf.float32, shape=[None, 3])

W = tf.Variable(tf.random_normal([4, 3], name='weight'))
b = tf.Variable(tf.random_normal([3], name='bias'))

hypothesis = tf.nn.softmax(tf.matmul(X, W) + b)
cost = tf.reduce_mean(-tf.reduce_sum(Y*tf.log(hypothesis), axis=1))
train = tf.train.GradientDescentOptimizer(learning_rate=1.2).minimize(cost)
#Cost함수의 최적점을 지나 튕겨나가버렸다 -러닝포기
#코스트에 갑자기 Nan이 쭉 등장한다? -> 러닝 레이트가 너무 큰 것일 가능성

#train = tf.train.GradientDescentOptimizer(learning_rate=1e-10).minimize(cost)
#Cost함수의 local minimum에 빠져 코스트가 변하지 않는다
#코스트가 일정순간 변하지 않는다? -> 러닝 레이트가 너무 작은 것일 가능성

#Nan이 등장할 수 있는 또다른 가능성?
#데이터 폭이 큰 데 정규화 해주지 않으면 Cost함수에서 최적점으로 가기도 전에 튕겨나가겠지
#이중리스트 형태일 경우 sklearn의 함수 쓰면 xy=MinMaxScaler(xy) 써주면 행마다 최대값을 1 최소값을 0 로 놓고 정규화해준디
#딕셔너리 형태일 경우 csv데이터 전처리 과정에서 이중리스트로 만들어주거나 함수를 직접 만들어서 적용시켜줘야한다

prediction = tf.argmax(hypothesis, 1)
correct_prediction = tf.equal(prediction, tf.argmax(Y, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    for step in range(201):
        cost_val, W_val, _ = sess.run([cost, W, train], feed_dict={X:x_data, Y:y_data})
        print(step, cost_val, W_val)

    print("Prediction: ", sess.run(prediction, feed_dict={X:x_test}))
    print("Accuracy: ", sess.run(accuracy, feed_dict={X:x_test, Y:y_test}))