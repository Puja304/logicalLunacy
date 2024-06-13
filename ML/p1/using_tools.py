#myenv\Scripts\activate in terminal if needed
import numpy as np
import matplotlib.pyplot as plt
from sklearn .linear_model import SGDRegressor
from sklearn.preprocessing import StandardScaler
from lab_utils_multi import load_house_data
from lab_utils_common import dlc
np.set_printoptions(precision=2)
plt.style.use('./deeplearning.mplstyle')


x_train, y_train = load_house_data()
X_features = ['size(sqft)','bedrooms','floors','age']



#scale the data (normalize it with mean = 0):
scaler = StandardScaler()   
X_norm = scaler.fit_transform(x_train)


#create and fill the regression model:
sgdr = SGDRegressor(max_iter=1000)
sgdr.fit(X_norm, y_train)


#view parameters:
b_norm = sgdr.intercept_
w_norm = sgdr.coef_
print("w = ",w_norm)
print("b = ",b_norm)


#make predictions:

y_pred_sgd = sgdr.predict(X_norm)

y_pred = np.dot(X_norm , w_norm) + b_norm

print(f"prediction using np.dot() and sgdr.predict match: {(y_pred == y_pred_sgd).all()}")

print(f"Prediction on training set:\n{y_pred[:4]}" )
print(f"Target values \n{y_train[:4]}")


#plot:
fig,ax=plt.subplots(1,4,figsize=(12,3),sharey=True)
for i in range(len(ax)):
    ax[i].scatter(x_train[:,i],y_train, label = 'target')
    ax[i].set_xlabel(X_features[i])
    ax[i].scatter(x_train[:,i],y_pred,color=dlc["dlorange"], label = 'predict')
ax[0].set_ylabel("Price"); ax[0].legend();
fig.suptitle("target versus prediction using z-score normalized model")
plt.show()

#

