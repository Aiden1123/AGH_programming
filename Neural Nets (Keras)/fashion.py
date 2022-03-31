from keras.layers.core import Flatten
import tensorflow
import sys
from tensorflow import keras
from keras.layers import Conv1D
from keras.layers import MaxPool1D
import matplotlib.pyplot as plt 
import numpy as np 

np.set_printoptions(suppress=True)

fashion_mnist = tensorflow.keras.datasets.fashion_mnist

(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()           #fashion

#(train_images, train_labels), (test_images, test_labels) = keras.datasets.mnist.load_data()     #numbers

processing = train_images.astype("float64")

mean = np.zeros((28,28))
std = np.zeros((28,28))

for image in train_images:
    mean = mean + image

mean = mean/60000

for image in train_images:
    temp = np.zeros((28,28))
    temp = temp + image
    temp = temp - mean
    temp = np.power(temp,2)
    temp = temp/60000
    std = std + temp

std = np.sqrt(std)

#print(mean)
#print(std)

print(processing.dtype)

for x in range(60000):

    processing[x] = processing[x] - mean
    processing[x] = processing[x] / std

print((train_images.shape))
#train_images = train_images.reshape(60000,784)
print((train_images.shape))
print((train_labels.shape))

print(test_images[0].shape)


 
#X = np.random.random((100, 100)) # sample 2D array
#figure, axis = plt.subplots(3, 3)
#for x in range(9): 
#    axis[x//3,x%3].imshow(test_images[x], cmap="gray") 
#plt.show()


model = keras.Sequential([
    keras.layers.Conv2D(filters=64, kernel_size=(3,3),padding="same", activation='relu',input_shape=(28,28,1)),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=32, kernel_size=(3,3),padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=16, kernel_size=(3,3),padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Flatten(),
    keras.layers.Dense(10, activation="sigmoid")
])

model.summary()

model.compile(optimizer="adam",
	          loss=keras.losses.SparseCategoricalCrossentropy(from_logits=False),
	          metrics=['accuracy'])

standardised_test = test_images.astype("float64")

for x in range(10000):

    standardised_test[x] = standardised_test[x] - mean
    standardised_test[x] = standardised_test[x] / std

print(processing.dtype)
print(train_labels.dtype)

processing = processing.reshape((60000,28,28,1))

model.fit(processing,train_labels, batch_size=50, epochs=2)

standardised_test = standardised_test.reshape((10000,28,28,1))

a = model.evaluate(standardised_test,test_labels)
print(a)
print(a[0])
#print(model.predict(test_images[:10]))
#print(test_labels[:10])


    