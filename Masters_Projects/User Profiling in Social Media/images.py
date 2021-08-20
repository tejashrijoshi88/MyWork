# images.py
# name: Tejashri Joshi
# description: Preprocess, filter , Augment image data and train a CNN for gender classification

import cv2
import matplotlib.pyplot as plt
import os
import numpy as np
import pandas as pd
from keras.preprocessing.image import ImageDataGenerator
from keras.models import load_model
from sklearn.model_selection import train_test_split
from keras.models import Sequential
from keras.layers import Dense
from keras.utils import np_utils
from keras.layers import Conv2D,MaxPooling2D,Activation,Dropout,Flatten

df=pd.read_csv('profile.csv')
images_data = df.loc[:,['userid', 'gender']]
X_training_data=[]
y_training_data=[]
IMG_Size=100
data_lib = r'D:\python\training data\training data\training\image'
save_plot = r'D:\python'

#detection of faces and adding those images to train and test data arrays
for i in images_data.index:
    if os.path.isfile(os.path.join(data_lib, images_data['userid'][i] + '.jpg')):
        # read image with grayscale
        image_array = cv2.imread(os.path.join(data_lib, images_data['userid'][i] + '.jpg'), cv2.IMREAD_GRAYSCALE)
        # detect faces
        haar_cascade_face = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
        faces_rects = haar_cascade_face.detectMultiScale(image_array, scaleFactor=1.2, minNeighbors=5)
        face_count = len(faces_rects)
    # add to training data only if there is face in image
        if face_count >0:
            for (x, y, w, h) in faces_rects:
                cv2.rectangle(image_array, (x, y), (x + w, y + h), (0, 255, 0), 2)
                roi_color = image_array[y:y + h, x:x + w]
                # resize the image to 100*100
                new_array = cv2.resize(roi_color, (IMG_Size, IMG_Size))
                X_training_data.append([np.array(new_array)])
                y_training_data.append(images_data['gender'][i])

# splitting data as 80 % for train and 20% as validation
X_train, X_test, y_train, y_test = train_test_split(X_training_data, y_training_data, test_size=0.2)

# Reshaping the image array
X_train = np.array(X_train).reshape(len(X_train),IMG_Size,IMG_Size,1)
X_test = np.array(X_test).reshape(len(X_test),IMG_Size,IMG_Size,1)
y_train = np.array(y_train)
y_test = np.array(y_test)

# normalize inputs from 0-255 to 0-1
X_train = X_train / 255
X_test = X_test / 255

# one hot encode outputs
y_train =np_utils.to_categorical(y_train)
y_test = np_utils.to_categorical(y_test)
num_classes = y_test.shape[1]
#print(num_classes)

# function to build CNN
def Conv_model():
    model = Sequential()
    model.add(Conv2D(32, (3, 3), input_shape=(IMG_Size,IMG_Size,1)))
    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))

    model.add(Conv2D(32, (3, 3)))
    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Conv2D(64, (3, 3)))
    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))

    model.add(Conv2D(64, (3, 3)))
    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))

    model.add(Conv2D(64, (3, 3)))
    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))

    model.add(Flatten())
    model.add(Dense(512))
    model.add(Activation('relu'))
    model.add(Dropout(0.5))
    model.add(Dense(num_classes, activation='softmax'))
    # Compile model
    model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])
    return model


# data generator for image augmentation
datagen = ImageDataGenerator(shear_range=0.2,
                             zoom_range=0.2,
                             horizontal_flip=True)
# build the model
model = Conv_model()
# Fit the model
datagen.fit(X_train)
history = model.fit_generator(datagen.flow(X_train, y_train, batch_size=64),
                              steps_per_epoch=len(X_train),
                              epochs=20,validation_data=(X_test, y_test))

 # save model
model_name = 'gender_classification_CNN.h5'
model.save(model_name)
# # Final evaluation of the model
# list all data in history
# summarize history for accuracy
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.title('model accuracy')
plt.ylabel('accuracy')
plt.xlabel('epoch')
plt.legend(['train', 'test'], loc='upper left')
plt.savefig('CNN_accuracy.png', format='png')
#plt.show()
# summarize history for loss
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('model loss')
plt.ylabel('loss')
plt.xlabel('epoch')
plt.legend(['train', 'test'], loc='upper left')
plt.savefig('CNN_loss.png', format='png')
plt.show()
model = load_model("gender_classification_CNN.h5")
scores = model.evaluate(X_test, y_test, verbose=0)
print(" Accuracy: %.2f%%" % (scores[1]*100))
print(" Error: %.2f%%" % (100-scores[1]*100))
# # predicted=model.predict(X_test[0])
# # print(predicted)


