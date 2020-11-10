import tensorflow as tf
import numpy as np
from matplotlib import pyplot as plt

sess= tf.InteractiveSession()
image = np.array([[[[1],[2],[3]],
                    [[4],[5],[6]],
                    [[7],[8],[9]]]], dtype=np.float32)

print(image.shape)
# [1,3,3,1]
# 1 개짜리 세묶음이 세개가 한개
# 첫 1 -> 데이터개수  / 3,3 -> 3X3 배치  /  마지막 1-> 색상
plt.imshow(image.reshape(3,3), cmap='Greys')
plt.show()

weight = tf.constant([[[[1.,10.,-1.]],[[1.,10.,-1.]]],
                        [[[1.,10.,-1.]],[[1.,10.,-1.]]]])
print(weight.shape)

conv2d =tf.nn.conv2d(image, weight, strides=[1,1,1,1], padding="SAME")
conv2d_img = conv2d.eval()
print(conv2d_img.shape)

conv2d_img = np.swapaxes(conv2d_img, 0 ,3)
for i, one_img in enumerate(conv2d_img) :
    print(one_img.reshape(3,3))
    plt.subplot(1,3,i+1), plt.imshow(one_img.reshape(3,3), cmap='gray')
    plt.show()

pool = tf.nn.max_pool(image, ksize=[1,2,2,1], strides=[1,1,1,1], padding='SAME') #2x2짜리로 1step씩 풀링
print(pool.shape)
print(pool.eval())
