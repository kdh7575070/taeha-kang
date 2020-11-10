import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
import matplotlib.pyplot as plt
import random
import ssl #오류방지로 넣어주자
ssl._create_default_https_context=ssl._create_unverified_context()

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True) #읽어올때 바로 one_hot처리

nb_classes = 10
X = tf.placeholder(tf.float32, shape=[None, 784])
Y = tf.placeholder(tf.float32, shape=[None, nb_classes])

W = tf.Variable(tf.random_normal([784, nb_classes]))
b = tf.Variable(tf.random_normal([nb_classes]))

hypothesis = tf.nn.softmax(tf.matmul(X, W) + b)
cost = tf.reduce_mean(-tf.reduce_sum(Y*tf.log(hypothesis), axis=1))
train = tf.train.GradientDescentOptimizer(learning_rate=0.1).minimize(cost)

correct_prediction = tf.equal(tf.argmax(hypothesis, 1), tf.argmax(Y, 1)) #합쳐서적음- 예측실제 같으면 true 다르면 false 함수
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

training_epochs = 15 # step 즉 전체데이타를 한번 다 돌린 것이 1 에폭
batch_size = 100 # 메모리에 한번에 다올리기에는 데이터가 너무 많아서 잘라서 트레이닝해준다

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    #트레이닝 사이클
    for epoch in range(training_epochs):
        avg_cost = 0
        total_batch = int(mnist.train.num_examples / batch_size)

        #i 는 iteration
        for i in range(total_batch): #전체데이터의 개수를 배치사이즈로 나눈 것이 한 iteration이 된다
            batch_xs, batch_ys = mnist.train.next_batch(batch_size) #각 iteration당 100개(배치사이즈)씩을 읽어와서 트레이닝 하겠다
            c, _ = sess.run([cost, train], feed_dict={X:batch_xs, Y:batch_ys})
            avg_cost += c /total_batch #batch마다 구한 cost를 평균내는 것

    print("Epoch: ", "%04d" %(epoch+1), "Cost =", "{:.9f}".format(avg_cost))

    print("Accuracy: ", accuracy.eval(session=sess, feed_dict={X:mnist.test.images, Y:mnist.test.labels}))
    #print("Accuracy: ", sess.run(accuracy, feed_dict={X:mnist.test.images, Y:mnist.test.labels})) 같은말

    r = random.randint(0, mnist.test.num_examples -1)
    print("Label: ", sess.run(tf.argmax(mnist.test.labels[r:r+1], 1))) #one_hot으로 돼있으니까 이렇게 label이 얼마인가를 찾아내
    print("Prediction: ", sess.run(tf.argmax(hypothesis, 1), feed_dict={X:mnist.test.images[r:r+1]})) #hyp로 구한 one_hot 예측값 찾아내
    plt.imshow(mnist.test.images[r:r+1].reshape(28,28),cmap='Greys', interpolation='nearest') #해당 이미지를 한번 볼까
    plt.show()