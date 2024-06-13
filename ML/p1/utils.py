import numpy as np

def load_data():
    data = np.loadtxt("data/ex1data1.txt", delimiter=',')
    X = data[:,0]    #the first argument means all values, and the second says which column. So this extracts all values from column 0
    y = data[:,1]   #the first argument means all values, and the second says which column. So this extracts all values from column 1
    return X, y

def load_data_multi():
    data = np.loadtxt("data/ex1data2.txt", delimiter=',')
    X = data[:,:2]      #the first argument says all values and the second gives a range of columns (0 to 2, with 2 excluded. so only 0 and 1)
    y = data[:,2]       # this is all values of column 2 only
    return X, y
