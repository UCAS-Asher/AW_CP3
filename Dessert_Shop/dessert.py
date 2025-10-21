#AW Dessert Shop Part 1

class DessertItem():
    def __init__(self, name = ""):
        self.name = name

class Candy(DessertItem):
    def __init__(self, name = "", price_per_pound = 0.0, amount = 0):
        super().__init__(name)
        self.price_per_pound = price_per_pound
        self.amount = amount

class IceCream(DessertItem):
    def __init__(self, name = "", price_per_scoop = 0.0, scoops = 0):
        super().__init__(name)
        self.price_per_scoop = price_per_scoop
        self.scoops = scoops

class Cookie(DessertItem):
    def __init__(self, name = "", price_per_dozen = 0.0, amount_of_cookies = 0):
        super().__init__(name)
        self.price_per_dozen = price_per_dozen
        self.amount_of_cookies = amount_of_cookies

class Sundae(IceCream):
    def __init__(self, name = "", price_per_scoop = 0.0, scoops = 0, topping_name = "", topping_price = 0.0):
        super().__init__(name, price_per_scoop, scoops)
        self.topping_name =  topping_name
        self.topping_price = topping_price

class Order():
    def __init__(self):
        self.order = []

    def add(self, dessert_item):
        self.order.append(dessert_item)

    def __len__(self):
        return f"There are {len(self.order)} items in your order"