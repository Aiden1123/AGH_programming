from keras.layers.core import Flatten
import tensorflow
from tensorflow import keras

batch_num = 50

train_data = tensorflow.keras.preprocessing.image.ImageDataGenerator(preprocessing_function=tensorflow.keras.applications.vgg16.preprocess_input). \
    flow_from_directory(directory = 'pictures\seg_train',
                        target_size = (80,80),
                        class_mode="sparse" ,
                        classes=["buildings","forest","glacier","mountain","sea","street"],
                        batch_size=batch_num)

test_data = tensorflow.keras.preprocessing.image.ImageDataGenerator(preprocessing_function=tensorflow.keras.applications.vgg16.preprocess_input). \
                flow_from_directory(directory='pictures\seg_test\seg_test', 
                                    target_size = (80,80), 
                                    class_mode="sparse", 
                                    classes=["buildings","forest","glacier","mountain","sea","street"], 
                                    batch_size=batch_num)

model = keras.Sequential([
    keras.layers.Rescaling(1./255),
    keras.layers.Conv2D(filters=128, kernel_size=(3,3), padding="same", activation='relu', input_shape=(80,80,3)),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=64, kernel_size=(3,3), padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    keras.layers.Conv2D(filters=32, kernel_size=(3,3), padding="same", activation='relu'),
    keras.layers.MaxPool2D(pool_size=(2,2), strides=(2,2)),
    Flatten(),
    keras.layers.Dense(6, activation="sigmoid")
])

model.compile(optimizer="adam",
            loss=keras.losses.SparseCategoricalCrossentropy(from_logits=False),
            metrics = ["accuracy"])

res = model.fit(train_data, validation_data = test_data, epochs = 2, verbose = 2)
print(res.history)

prediction = tensorflow.keras.preprocessing.image.ImageDataGenerator(preprocessing_function=tensorflow.keras.applications.vgg16.preprocess_input). \
                flow_from_directory(directory='pictures\se', target_size = (80,80), batch_size=batch_num)

img, lab = next(prediction)

print(model.predict(img))

