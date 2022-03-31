import sys
import pandas as pd
import numpy as np
import tensorflow as tf
from sklearn.model_selection import train_test_split
from tensorflow import keras

raw_data = pd.read_csv("weatherHistory.csv") #https://www.kaggle.com/budincsevity/szeged-weather
raw_data = raw_data.dropna()
del raw_data["Formatted Date"]
del raw_data["Precip Type"]
del raw_data["Daily Summary"]

acceptable_values = ["Clear", "Mostly Cloudy", "Partly Cloudy", "Overcast"]
raw_data = raw_data[raw_data["Summary"].isin(acceptable_values)]

d = {"Clear": 0, "Partly Cloudy": 1, "Mostly Cloudy": 2, "Overcast": 3}
raw_data["Summary"] = raw_data.Summary.apply(lambda x: d[x])

raw_data = raw_data.sample(frac=1).reset_index(drop=True)

model = keras.Sequential([
	keras.layers.Dense(32, input_shape=(8,), activation='relu'),
    #keras.layers.Dense(64, activation='relu'),
    keras.layers.Dropout(0.2),
	keras.layers.Dense(4, activation='sigmoid')])

model.compile(optimizer='adam', 
	          loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
	          metrics=['accuracy']
             )

x = raw_data.copy()
del x["Summary"]
y = raw_data["Summary"]

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.1, random_state=420)

print(type(x_train))
print(x_train.shape)
#sys.exit(0)

model.fit(x_train, y_train, batch_size=10, epochs=5)

model.evaluate(x_test, y_test)