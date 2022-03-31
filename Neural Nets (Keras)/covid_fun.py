import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import tensorflow as tf
import sys
from tensorflow import keras
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split
from random import randrange

data = pd.read_csv("covid_data.csv")

cases = np.array(data['new_cases'])

#print(max(cases))

prediction_length = 320

x = []
y = []

for i in range(prediction_length, len(cases)):
    x.append(cases[i-prediction_length:i])
    y.append(cases[i])

x, y = np.array(x), np.array(y)

x_train = x
y_train = y

last_14_days = x_train[-1:]

"""
split = 570

x_test = x[split:]
x_train = x[:split]
y_test = y[split:]
y_train = y[:split]
"""

"""
for i in range(150):
    print("int: " + str(x_train[i]) + " val: " + str(y_train[i]))
"""
x_train = pd.DataFrame(x_train,columns=range(prediction_length))
y_train = pd.DataFrame(y_train,columns=["next_day_cases"])

model = keras.Sequential([
    keras.layers.Dense(256, input_shape=(prediction_length,), activation='relu'),
    keras.layers.Dropout(0.2),
    keras.layers.Dense(256, activation='relu'),
    keras.layers.Dropout(0.2),
    keras.layers.Dense(256, activation='relu'),
    keras.layers.Dropout(0.2),
	keras.layers.Dense(1)])

model.compile(optimizer='adam', 
	          loss="mean_squared_error",)

model.fit(x_train, y_train, batch_size=1, epochs=30)



"""
predictions = model.predict(x_train)
predictions = pd.DataFrame(predictions, columns=["predicted_value"])
#print(model.predict(x_train))
print(type(y_train))
print(type(predictions))
ax = predictions.plot()
y_train.plot(ax=ax)
plt.show()


print(last_14_days.shape)

x_test = pd.DataFrame(x_test,columns=range(14))
y_test = pd.DataFrame(y_test,columns=["next_day_cases"])

test_prediction = model.predict(x_test)
test_prediction = pd.DataFrame(test_prediction, columns=["predicted_value"])

ax = test_prediction.plot()
y_test.plot(ax=ax)
plt.show()
"""
period_len = 200
res = []

def shift_back(array):
    
    arr = array.copy()

    #print(arr)
    
    for i in range(prediction_length-1):
        arr[0][i] = arr[0][i+1]
        
    #print(arr)    
    return arr

for j in range(period_len):
    
    df = pd.DataFrame(last_14_days, columns=range(prediction_length))
    #print(df)
    current = model.predict(df)[0]  #+ randrange(10)

    #print(current)

    last_14_days = shift_back(last_14_days)

    last_14_days[0][prediction_length-1] = current

    res.append(current)

plt.plot(range(period_len),res)
plt.show()
