#gcd
def gcd(x,y):
    list_of_vals = []
    while y != 0:
        x = (x//y)*y  + (x%y)
        list_of_vals.append(x%y)
        x = y
        y = x%y
    print(list_of_vals)


gcd(250,111)