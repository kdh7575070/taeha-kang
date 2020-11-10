import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt

x_train = [1,2,3,5]
y_train = [1,4,8,14]

W = tf.Variable(tf.random_normal([1]),name = 'weight')
b = tf.Variable(tf.random_normal([1]),name = 'bias')

hypothesis = x_train*W + b
cost = tf.reduce_mean(tf.square(hypothesis - y_train))

optimizer = tf.train.GradientDescentOptimizer(learning_rate = 0.01)
train = optimizer.minimize(cost)

sess = tf.Session()
sess.run(tf.global_variables_initializer())

t = np.arange(0., 5., 0.2)

for step in range(2001):
  sess.run(train)
  if step < 10:
    plt.plot(t, t*sess.run(W)+sess.run(b), 'r')
  if step % 20 == 0:
    print(step, sess.run(cost),sess.run(W),sess.run(b))
    plt.show()