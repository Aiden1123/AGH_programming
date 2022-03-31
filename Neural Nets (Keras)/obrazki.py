from tensorflow import keras
import sys

from tensorflow.python.ops.gen_batch_ops import batch

dataset = keras.datasets.cifar10

(train_images, train_labels), (test_images, test_labels) = dataset.load_data() 

print(type(train_images))
print(train_images.shape)

print(type(train_labels))
print(train_labels.shape)


#sys.exit(0)

model = keras.Sequential([
    keras.layers.Conv2D(filters=256, kernel_size=(3,3),padding="same", activation='relu',input_shape=(32,32,3)),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=128, kernel_size=(3,3),padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=64, kernel_size=(3,3),padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Flatten(),
    keras.layers.Dense(10, activation="sigmoid")
])

model.compile(optimizer="adam",
	          loss=keras.losses.SparseCategoricalCrossentropy(from_logits=False),
	          metrics=['accuracy'])

model.fit(train_images, train_labels, batch_size=200, epochs=4)

model.evaluate(test_images, test_labels)