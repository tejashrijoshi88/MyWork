import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt


from sklearn.model_selection import train_test_split
# --- Model ---
from sklearn.linear_model import LinearRegression
# --- Evaluation ---
from sklearn.metrics import mean_squared_error
from sklearn.metrics import r2_score
housedf= pd.read_csv("kc_house_data.csv")
housedf['yr_sold']=housedf['date'].str[:4].astype(int)
housedf[(housedf['yr_sold']<housedf['yr_built'])]

housedf.shape

# to check null values
sns.heatmap(housedf.isnull(),yticklabels=False,cbar=False)

#housedf.info()

correlation_matrix = housedf.corr().round(2)
# annot = True to print the values inside the square
sns.heatmap(data=correlation_matrix, annot=True)
plt.show()

# sqft living is highly co related with price ,
# sqft living with highly corelated with other attribute sqft_above  = 0.88 so we can take only one
# sqft_above is corelated with grade

# price code has negative highest co relation with price -0.05
# low co relation is condition with price

plt.scatter(housedf['sqft_above'], housedf['price'], marker='o')
plt.title('price Vs sqft_above')
plt.xlabel('sqft_above')
plt.ylabel('price1')
plt.show

plt.scatter(housedf['grade'], housedf['price'], marker='o')
plt.title('grade Vs sqft_above')
plt.xlabel('grade')
plt.ylabel('price2')
plt.show


feature_names = ['sqft_above', 'grade']
X = housedf[feature_names]
Y = housedf['price']

X_train, X_test, Y_train, Y_test = train_test_split(X, Y,test_size = 0.2)

lin_model = LinearRegression()

lin_model.fit(X_train, Y_train)
y_train_predict = lin_model.predict(X_train)

rmse = (np.sqrt(mean_squared_error(Y_train, y_train_predict)))
r2 = r2_score(Y_train, y_train_predict)
print("The model performance for training set")
print("--------------------------------------")
print('RMSE is {}'.format(rmse))
print('R2 score is {}'.format(r2))
print("\n")

# model evaluation for testing set
y_test_predict = lin_model.predict(X_test)
rmse = (np.sqrt(mean_squared_error(Y_test, y_test_predict)))
r2 = r2_score(Y_test, y_test_predict)
print("The model performance for testing set")
print("--------------------------------------")
print('RMSE is {}'.format(rmse))
print('R2 score is {}'.format(r2))
