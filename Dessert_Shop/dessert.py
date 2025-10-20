#holds classes

#dessert item: parent class
    #name: string
        #default ""
    #init method

#candy: child class
    #price_per_pound : float
        # default 0.0
    #amount : float
        #0.0
    #init method

#icecream: child class
    #price_per_scoop: float
        #0.0
    #scoops; int
        #0
    #init method

#cookies: child class
    #price_per_dozen: float
        #0.0
    #amount_of_cookies: int
        #0
    #init method

#sundae: child of icecream
    #inherits price per scoop and scoops
    #topping_name: str
        # default ""
    #topping_price: float
        #0.0

#order: not a child
    #order: list
    #add(Dessertitem)
    #__len__() Get the # of items in the order


class DessertItem():
    def __init__(self, name = ""):
        self.name = name

class Candy(DessertItem):
    def __init__(self, name = "", price_per_pound = 0.0, amount = 0):
        super().__init__(name)
        self.price_per_pound = price_per_pound
        self.amount = amount

class IceCream(DessertItem):
    def __init__(self, name, price_per_scoop = 0.0, scoops = 0):
        super().__init__(name)
        self.price_per_scoop = price_per_scoop
        self.scoops = scoops

class Cookies(DessertItem):
    def __init__(self, name, price_per_dozen = 0.0, amount_of_cookies = 0):
        super().__init__(name)
        self.price_per_dozen = price_per_dozen
        self.amount_of_cookies = amount_of_cookies

class Sundae(IceCream):
    def __init__(self, price_per_scoop, scoops, topping_name = "", topping_price = 0.0):
        super().__init__(price_per_scoop, scoops)

class Order():
    def __init__(self):
        self.order = []

    def add(self, dessert_item):
        self.order.append(dessert_item)

    def __len__():
        pass