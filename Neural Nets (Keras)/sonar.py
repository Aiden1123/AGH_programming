import keras
import pandas as pd
from sklearn.model_selection import train_test_split

data = pd.read_csv("sonar\sonar_data.csv")

data = data.sample(frac=1).reset_index(drop=True)

x = data.copy()

del x["category"]

y = data["category"]

model = keras.Sequential([
	keras.layers.Dense(32, input_shape=(60,), activation='relu'),
    keras.layers.Dense(16, activation='relu'),
    keras.layers.Dropout(0.2),
	keras.layers.Dense(2, activation='sigmoid')])

model.compile(optimizer="adam", 
                loss=keras.losses.SparseCategoricalCrossentropy(from_logits=False), 
                metrics = ["accuracy"])

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.1, random_state=420)

model.fit(x_train, y_train, batch_size=1, epochs = 4)

evaluation = model.evaluate(x_test,y_test)

model.save("sonar\model")

print(type(evaluation))