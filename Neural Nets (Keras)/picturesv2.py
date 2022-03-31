from keras.layers.core import Flatten
import tensorflow
from tensorflow.keras.metrics import categorical_crossentropy
import sys
from tensorflow import keras
import matplotlib.pyplot as plt 
import numpy as np 

batch_size=5

train_data = tensorflow.keras.utils.image_dataset_from_directory(
    "pictures\seg_train",
  seed=123,
  image_size=(256, 256),
  batch_size=batch_size)

test_data =  tensorflow.keras.utils.image_dataset_from_directory(
    "pictures\seg_test\seg_test",
  seed=123,
  image_size=(256, 256),
  batch_size=batch_size)

model = keras.Sequential([
    keras.layers.Conv2D(filters=32, kernel_size=(3,3),padding="same", activation='relu',input_shape=(256,256,3)),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=64, kernel_size=(3,3),padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=64, kernel_size=(3,3),padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    Flatten(),
    keras.layers.Dense(6, activation="sigmoid")
])


"""
model = tensorflow.keras.Sequential([
  tensorflow.keras.layers.Conv2D(32, 3, activation='relu'),
  tensorflow.keras.layers.MaxPooling2D(),
  tensorflow.keras.layers.Conv2D(32, 3, activation='relu'),
  tensorflow.keras.layers.MaxPooling2D(),
  tensorflow.keras.layers.Conv2D(32, 3, activation='relu'),
  tensorflow.keras.layers.MaxPooling2D(),
  tensorflow.keras.layers.Flatten(),
  tensorflow.keras.layers.Dense(128, activation='relu'),
  tensorflow.keras.layers.Dense(6)
])
"""

print(type(train_data))

model.compile(optimizer="adam", 
                loss=keras.losses.SparseCategoricalCrossentropy(from_logits=False), 
                metrics = ["accuracy"])

model.fit(train_data, validation_data = test_data, epochs = 5, verbose = 2)

