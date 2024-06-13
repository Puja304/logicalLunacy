import requests
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
from sklearn.preprocessing import StandardScaler

base_url = 'https://api.themoviedb.org/3'

headers = {
    "accept": "application/json",
    "Authorization": "Bearer eyJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJlN2JlNGJhMmQ4NGY5Y2Q5MzFiMmU5N2NiODFkNzkyYyIsInN1YiI6IjY2NGJmZDU0NjU4YmViMmIwNjk2NTQ1NCIsInNjb3BlcyI6WyJhcGlfcmVhZCJdLCJ2ZXJzaW9uIjoxfQ.weI7G6BeEVnK75NRo2AyIzmkbtJvusOe8K_0fQas3dg"
}

api_key = 'e7be4ba2d84f9cd931b2e97cb81d792c'

def get_movie_details(movie_id):
    url = f'{base_url}/movie/{movie_id}?api_key={api_key}&language=en-US'
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        return  {        
            'revenue': data.get('revenue'),
            'budget': data.get('budget'),
            'runtime': data.get('runtime'),
            'popularity': data.get('popularity')
        }
    else:
        return None
    
x_train = np.zeros((101,3))
y_train = np.zeros((101,1))

movNum = 0
row_num = 0
while(movNum < 100):
    movie_details = get_movie_details(row_num)
    if movie_details:
        x_train[movNum,0] = movie_details['budget']
        x_train[movNum,1] = movie_details['runtime']
        x_train[movNum,2] = movie_details['popularity']
        y_train[movNum,0] = movie_details['revenue'] 
        movNum+=1
    row_num+=1


X_train, X_test, Y_train, Y_test = train_test_split(x_train, y_train, test_size=0.2, random_state=42)
model = LinearRegression()
model.fit(X_train, Y_train)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# Train the model on scaled features
model = LinearRegression()
model.fit(X_train_scaled, Y_train)


y_pred  = model.predict(X_test)

mse = mean_squared_error(Y_test, y_pred)

print(f'Mean Squared Error: {mse}')

# Print coefficients
print('Coefficients:', model.coef_)
print('Intercept:', model.intercept_)

trial1 = [[50000000, x_train[5,1], x_train[7,2]]]

print(model.predict(trial1))