#AW Dessert Shop Part 2
from abc import ABC, abstractmethod

class DessertItem(ABC):
    def __init__(self, name = "", tax_percent = 7.25):
        self.name = name
        self.tax_percent = tax_percent

    @abstractmethod
    def calculate_cost():
        pass
    
    def calaculate_tax(self, item_cost):
        return round((item_cost*self.tax_percent), 2)
    

class Candy(DessertItem):
    def __init__(self, name = "", tax_percent = 7.25, candy_weight = 0.0, price_per_pound = 0.0):
        super().__init__(name, tax_percent)
        self.candy_weight = candy_weight
        self.price_per_pound = price_per_pound

    def calculate_cost(self):
        return round((self.candy_weight*self.price_per_pound), 2)

class Cookie(DessertItem):
    def __init__(self, name = "", cookie_quantity = 0, price_per_dozen = 0.0):
        super().__init__(name)
        self.cookie_quantity = cookie_quantity
        self.price_per_dozen = price_per_dozen

    def calculate_cost(self):
        return round(((self.cookie_quantity/12)*self.price_per_dozen), 2)

class IceCream(DessertItem):
    def __init__(self, name = "", scoop_count = 0, price_per_scoop = 0.0):
        super().__init__(name)
        self.scoop_count = scoop_count
        self.price_per_scoop = price_per_scoop

    def calculate_cost(self):
        return round((self.scoop_count*self.price_per_scoop), 2)

class Sundae(IceCream):
    def __init__(self, name = "", scoop_count = 0, price_per_scoop = 0.0, topping_name = "", topping_price = 0.0):
        super().__init__(name, scoop_count, price_per_scoop)
        self.topping_name =  topping_name
        self.topping_price = topping_price

    def calculate_cost(self):
        return round(((self.scoop_count*self.price_per_scoop) + self.topping_price), 2)

class Order():
    def __init__(self):
        self.order = []

    def add(self, dessert_item):# Adds a desert item to a list of your order
        self.order.append(dessert_item)

    def __len__(self):
        return f"There are {len(self.order)} items in your order"
    
    def order_cost(self):
        order_cost = 0
        for item in self.order:
            order_cost += item.calculate_cost()
        return order_cost
    
    def order_tax(self):
        order_tax = 0
        for item in self.order:
            order_tax += item.calculate_tax(item.calculate_cost())
        return order_tax
