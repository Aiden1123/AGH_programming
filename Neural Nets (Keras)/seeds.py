from tensorflow import keras
import pandas as pd

data = pd.read_csv("nasionka/new_data.csv")

data = data.sample(frac=1).reset_index(drop=True)

print(data.info())


train = data[:189]
test = data[189:]

x = train.copy()
del x["category"]
y = train["category"]


test_x = test.copy()
del test_x["category"]
test_y = test["category"]

test_x.to_csv("nasionka/test_x.csv")
test_y.to_csv("nasionka/test_y.csv")

model_a = keras.Sequential([
		keras.layers.Dense(64, input_shape=(7,), activation='relu'),
		keras.layers.Dropout(0.2),
		keras.layers.Dense(32, activation='relu'),
		keras.layers.Dropout(0.2),
		keras.layers.Dense(32, activation='relu'),
		keras.layers.Dropout(0.2),
		keras.layers.Dense(3, activation='sigmoid')])

model_b = keras.Sequential([
		keras.layers.Dense(128, input_shape=(7,), activation='relu'),
		keras.layers.Dense(64, activation='relu'),
		keras.layers.Dense(32, activation='relu'),
		keras.layers.Dense(3, activation='sigmoid')])

model_c = keras.Sequential([
		keras.layers.Dense(64, input_shape=(7,), activation='relu'),
		keras.layers.Dense(32, activation='relu'),
		keras.layers.Dense(3, activation='sigmoid')])

model_d = keras.Sequential([
		keras.layers.Dense(7, input_shape=(7,), activation='relu'),
		keras.layers.Dense(3, activation='relu'),
		keras.layers.Dense(3, activation='sigmoid')])

model_e = keras.Sequential([
		keras.layers.Dense(32, input_shape=(7,), activation='relu'),
		keras.layers.Dropout(0.2),
		keras.layers.Dense(32, activation='relu'),
		keras.layers.Dropout(0.2),
		keras.layers.Dense(3, activation='sigmoid')])


models = [model_a,model_b,model_c,model_d,model_e]

for index, model in enumerate(models):

	model.compile(optimizer="adam",
				loss=keras.losses.SparseCategoricalCrossentropy(from_logits=False),
				metrics=['accuracy'])

	model.fit(x, y, batch_size=1,epochs = 5)

	model.save("model"+str(index))
