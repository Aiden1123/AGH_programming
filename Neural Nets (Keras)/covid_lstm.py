import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import tensorflow as tf
import sys
from tensorflow import keras
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split

data = pd.read_csv("covid_data.csv")

cases = np.array(data['new_cases'])

#print(max(cases))

prediction_length = 14

x = []
y = []

for i in range(prediction_length, len(cases)):
    x.append(cases[i-prediction_length:i])
    y.append(cases[i])

x, y = np.array(x), np.array(y)

x= x.reshape(590,14,1)

#print(x)

#x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.1, random_state=420)

split = 570

x_test = x[split:]
x_train = x[:split]
y_test = y[split:]
y_train = y[:split]


"""
for i in range(150):
    print("int: " + str(x_train[i]) + " val: " + str(y_train[i]))
"""
#print(x_train.shape[1:])

model = keras.Sequential()
model.add(keras.layers.LSTM(128,input_shape = (14,1), activation='relu', return_sequences = True))
model.add(keras.layers.Dropout(0.2))
model.add(keras.layers.LSTM(128, activation='relu', return_sequences = True))
model.add(keras.layers.Dropout(0.2))
model.add(keras.layers.LSTM(128, activation='relu'))
model.add(keras.layers.Dropout(0.2))
model.add(keras.layers.Dense(1))

model.compile(optimizer='adam', 
	          loss="mean_squared_error",)

model.fit(x_train, y_train, batch_size=1, epochs=10)



predictions = model.predict(x_train)
predictions = pd.DataFrame(predictions, columns=["predicted value"])
#print(model.predict(x_train))
print(type(y_train))
print(type(predictions))
ax = predictions.plot()
y_train = pd.DataFrame(y_train,columns=["next_day_cases"])
y_train.plot(ax=ax)
plt.show()

test_prediction = model.predict(x_test)
test_prediction = pd.DataFrame(test_prediction, columns=["predicted value"])
"""
ax = test_prediction.plot(style=".")
y_test.plot(ax=ax, style = ".")
"""
ax = test_prediction.plot()
y_test = pd.DataFrame(y_test,columns=["next_day_cases"])
y_test.plot(ax=ax)


plt.show()