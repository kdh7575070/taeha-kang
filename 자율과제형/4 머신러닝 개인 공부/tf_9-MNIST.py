import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

tf.set_random_seed(777)

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

nb_classes = 10

X = tf.placeholder(tf.float32, shape=[None, 784])
Y = tf.placeholder(tf.float32, shape=[None, nb_classes])

W1 = tf.Variable(tf.random_normal([784, 256]), name='weight1')
b1 = tf.Variable(tf.random_normal([256]), name='bias1')
layer1 = tf.nn.softmax(tf.matmul(X, W1) + b1)

W2 = tf.Variable(tf.random_normal([256, 256]), name='weight2')
b2 = tf.Variable(tf.random_normal([256]), name='bias2')
layer2 = tf.nn.softmax(tf.matmul(layer1, W2) + b2)

W3 = tf.Variable(tf.random_normal([256, nb_classes]), name='weight3')
b3 = tf.Variable(tf.random_normal([nb_classes]), name='bias3')
hypothesis = tf.nn.softmax(tf.matmul(layer2, W3) + b3)

cost = tf.reduce_mean(-tf.reduce_sum(Y*tf.log(hypothesis), axis=1))
train = tf.train.GradientDescentOptimizer(learning_rate=0.01).minimize(cost)

correct_prediction = tf.equal(tf.argmax(hypothesis, 1), tf.argmax(Y, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

training_epochs = 15
batch_size = 100

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    for epoch in range(training_epochs):
        avg_cost = 0
        total_batch = int(mnist.train.num_examples / batch_size)

        for i in range(total_batch):
            batch_xs, batch_ys = mnist.train.next_batch(batch_size)
            c, _ = sess.run([cost, train], feed_dict={X:batch_xs, Y:batch_ys})
            avg_cost += c /total_batch

    print("Epoch: ", "%04d" %(epoch+1), "Cost =", "{:.9f}".format(avg_cost))

    print("Accuracy: ", accuracy.eval(session=sess, feed_dict={X:mnist.test.images, Y:mnist.test.labels}))


### Layer만 늘림으로써도 좋아졌지만 사실 더 좋아지게 할 방법은 많다

### Cell전체 수, 레이어수, 히든셀종류(컨벌루셔널...)
### 액티베이션함수, weight 초기화, 러닝 레이트, 액티베이션주기
### 드랍아웃(학습 때는 랜덤하게 몇개 뉴런을 잘라내서 학습시키기->실전에는 1로 꼭), 앙상블
### 로스함수, 로스알고리즘, 배치사이즈, 에폭 모두 영향을 미친다

### 다음에서는 로스알고리즘으로 Adams옵티마이저와 ReLu를 사용해보겠다!!!