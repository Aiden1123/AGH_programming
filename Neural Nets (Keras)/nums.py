from keras.layers.core import Flatten
import tensorflow
import sys
from tensorflow import keras
from keras.layers import Conv1D
from keras.layers import MaxPool1D
import matplotlib.pyplot as plt 
import numpy as np 

np.set_printoptions(suppress=True)

(train_images, train_labels), (test_images, test_labels) = keras.datasets.mnist.load_data()     #numbers

print(train_images.shape[1:])

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
figure, axis = plt.subplots(3, 3)
for x in range(9): 
    axis[x//3,x%3].imshow(test_images[x], cmap="gray") 
plt.show()



"""
model = keras.Sequential([
	keras.layers.Dense(1024, input_shape=(784,), activation='relu'),
    keras.layers.Dropout(0.2),
    keras.layers.Dense(2048, activation='relu'),
    keras.layers.Dropout(0.2),
    keras.layers.Dense(2048, activation='relu'),
    keras.layers.Dropout(0.2),
    keras.layers.Dense(1024, activation='relu'),
    keras.layers.Dropout(0.2),
	keras.layers.Dense(10, activation='sigmoid')])
"""

model = keras.Sequential([
    Conv1D(filters=64, kernel_size=(3), activation='relu',input_shape=(28,28)),
    MaxPool1D(pool_size=(4), strides=1),
    Conv1D(filters=128, kernel_size=(3), activation='relu'),
    MaxPool1D(pool_size=(4), strides=1),
    Conv1D(filters=128, kernel_size=(3), activation='relu'),
    MaxPool1D(pool_size=(4), strides=1),
    Flatten(),
    keras.layers.Dense(10, activation="sigmoid")
]) 

model.compile(optimizer="adam",
	          loss=keras.losses.SparseCategoricalCrossentropy(from_logits=False),
	          metrics=['accuracy'])

standardised_test = test_images.astype("float64")

for x in range(10000):

    standardised_test[x] = standardised_test[x] - mean
    standardised_test[x] = standardised_test[x] / std

print(processing.dtype)
print(train_labels.dtype)
model.fit(train_images,train_labels, batch_size=100, epochs=4)



a = model.evaluate(test_images,test_labels)
print(a)
print(a[0])

#print(model.predict(test_images[:10]))
#print(test_labels[:10])


    