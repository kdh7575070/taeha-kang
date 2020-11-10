import tensorflow as tf
import numpy as np
from matplotlib import pyplot as plt

from tensorflow.examples.tutorials.mnist import input_data

mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)
# Check out https://www.tensorflow.org/get_started/mnist/beginners for
# more information about the mnist dataset

img = mnist.train.images[0].reshape(28,28)
plt.imshow(img, cmap='gray') #3

sess= tf.InteractiveSession()

img = img.reshape(-1,28,28,1) #-1은 알아서 계산해 -n개데이터들어오는거알아서맞춰주는것임

w1 = tf.Variable(tf.random_normal([3,3,1,5], stddev=0.01)) # 3x3x1 이 5개 특히 color 1 맞춰주는걸로 에 주의
sess.run(tf.global_variables_initializer())

conv2d =tf.nn.conv2d(img, w1, strides=[1,2,2,1], padding='SAME') # same 하면 원래 레이어랑 같은 사이즈로 출력하도록 맞춰주는것
print(conv2d)
conv2d_img = conv2d.eval()
conv2d_img = np.swapaxes(conv2d_img, 0 ,3)

#for i, one_img in enumerate(conv2d_img):
#    plt.subplot(1,5,i+1), plt.imshow(one_img.reshape(14,14),cmap='gray')
#plt.show()

pool = tf.nn.max_pool(conv2d, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME') #커널은 풀링 사이즈 #strides가 점프!
print(pool)
pool_img = pool.eval()
pool_img = np.swapaxes(pool_img, 0, 3)

for i, one_img in enumerate(pool_img):
    plt.subplot(1,5,i+1), plt.imshow(one_img.reshape(7,7), cmap='gray')
plt.show()