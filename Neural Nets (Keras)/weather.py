from keras.layers.core import Flatten
import tensorflow
from tensorflow.keras.metrics import categorical_crossentropy
import sys
from tensorflow import keras
import matplotlib.pyplot as plt 
import numpy as np 

np.set_printoptions(suppress=True)

size_of_batch = 10
data_path = "weather\dataset2"
preprocessing = tensorflow.keras.applications.vgg16.preprocess_input

train_data = tensorflow.keras.preprocessing.image.ImageDataGenerator(preprocessing_function=preprocessing).flow_from_directory(directory=data_path,target_size = (80,80), class_mode="sparse" ,classes=["cloudy","rain","shine","sunrise"], batch_size=size_of_batch)
test_data = tensorflow.keras.preprocessing.image.ImageDataGenerator(preprocessing_function=preprocessing).flow_from_directory(directory="weather\\validation", target_size = (80,80), class_mode="sparse", classes=["cloudy","rain","shine","sunrise"], batch_size=size_of_batch)
prediction = tensorflow.keras.preprocessing.image.ImageDataGenerator(preprocessing_function=preprocessing).flow_from_directory(directory="weather\\pred", target_size = (80,80), batch_size=size_of_batch)

model = keras.Sequential([
    keras.layers.Conv2D(filters=64, kernel_size=(3,3),padding="same", activation='relu',input_shape=(80,80,3)),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=64, kernel_size=(3,3),padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=32, kernel_size=(3,3),padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    Flatten(),
    keras.layers.Dense(4, activation="sigmoid")
])

print(type(train_data))

model.compile(optimizer="adam", 
                loss=keras.losses.SparseCategoricalCrossentropy(from_logits=False), 
                metrics = ["accuracy"])

model.fit(train_data,validation_data = test_data, epochs = 3, verbose = 2)

img, lab = next(prediction)

print(img.shape)

print(train_data.class_indices)

print(model.predict(img))

