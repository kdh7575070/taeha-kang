import tensorflow as tf

x_data = [[1,2,1,1,],[2,1,3,2],[3,1,3,4],[4,1,5,5],[1,7,5,5],[1,2,5,6],[1,6,6,6],[1,7,7,7]]
y_data = [[0,0,1],[0,0,1],[0,0,1],[0,1,0],[0,1,0],[0,1,0],[1,0,0],[1,0,0]] #one-hot 인코딩을 통해 ABC세개의 분류를 이렇게 정의

X = tf.placeholder(tf.float32, shape=[None, 4]) #이제 항상 셰입에 주의!!
Y = tf.placeholder(tf.float32, shape=[None, 3])
nb_classes = 3 #yshape받아서

W = tf.Variable(tf.random_normal([4, nb_classes], name='weight')) #굳이...?흠
b = tf.Variable(tf.random_normal([nb_classes], name='bias'))

hypothesis = tf.nn.softmax(tf.matmul(X, W) + b) #소프트맥스를 씌워줘야한다
cost = tf.reduce_mean(-tf.reduce_sum(Y*tf.log(hypothesis), axis=1))
train = tf.train.GradientDescentOptimizer(learning_rate=0.01).minimize(cost)

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    # Fit the line
    for step in range(2001):
        sess.run(train, feed_dict={X:x_data, Y:y_data})
        if step % 200 == 0:
            print(step, sess.run(cost, feed_dict={X:x_data, Y:y_data}))

    # 예측도해보자
    a = sess.run(hypothesis, feed_dict={X:[[1,11,7,9],
                                           [1,3,4,3],
                                           [1,1,0,1]]})
    print(a, sess.run(tf.argmax(a,1))) #정확도 계산 하려면 -> 예측값의 가장큰 값을 리턴해주는 함수 argmax