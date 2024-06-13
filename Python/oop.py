class Item:
#parameters of the init function must be passed when initialising objects
    pay_rate = 0.8
    all = []
    def __init__(self,name:str,price:float,quantity=0): #self is default name:str and price:float place restrictions on dataype for arguments passed. defaulting
        # qunatity to an integer is the same as quanity:int and so that has also been restricted

        #assert ensures the values entetered are legit. 
        assert price >= 0, f"{price} is not greater than zero"
        assert quantity >= 0, f"{quantity} is not greater than zero"
        #assigns arguments to object attributes that can be accessed:
        self.name = name
        self.price = price
        self.quantity = quantity

        #actions to be executed
        Item.all.append(self) #add each created instance to a list

    def calculate_total(self):  #self is default and necessary
        return self.price * self.quantity
    def apply_discount(self):
        self.price = self.price * self.pay_rate     #pay_rate is a class level attribute, not given to objects. As such, it can be reffered to as 
                                                #Item.pay_rate or self.pay_rate. if we wanna leave the opetion of changing payrate for specific objects,
                                                #it is better to use self.pay_rate. If this remains constant for any pbject, use Item.pay_rate.
    def __repr__(self): #Item.all is a list of all locations of instances, and so print locations. The repr function changes what it stored from location to 
        #data, It is the best practice to represent the instance with the same language as creating it. Can return anything,but go with this/      
        return f"Item({self.name}, {self.price}, {self.quantity})" 
'''
item1 = Item("Pixel",780,9)
item1.apply_discount()   #uses the default 0.8 in the class
print(item1.price)
item2 = Item("Laptop",1000, 4)
item2.pay_rate = 0.7 #set a custom pay_rate. only possible as we used self.pay_rate above. Otherwise, would be overridden if we had used Item.pay_rate
item2.apply_discount()
print(item2.price)
'''


item1 = Item("Phone", 100, 1)
item2 = Item("Laptop", 1000, 3)
item3 = Item("Cable", 10, 5)
item4 = Item("Mouse", 50, 5)
item5 = Item("Keyboard", 75, 5)

print(Item.all)

for instances in Item.all:
    print(instances.name)    #prints the name assigned to every created instance of the class Item(since they are all present in the list called all)
