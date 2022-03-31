from tensorflow import keras
import pandas as pd
from tensorflow.python.ops.gen_batch_ops import batch

x = pd.read_csv("nasionka/test_x.csv")
y = pd.read_csv("nasionka/test_y.csv")

del x["Unnamed: 0"]
del y["Unnamed: 0"]

max = 0 #possible values range from 0 to 1
max_name = None

for name in ["model0","model1","model2","model3","model4"]:
    model = keras.models.load_model(name)

    val = model.evaluate(x,y,batch_size=1)[1]
    
    if (val>=max):
        max = val
        max_name = name
    
print(max_name + " reached highest accuracy with " + str(max * 100) + "%")
