#AW Dessert Shop Part 1

from dessert import *


def main():
    order = Order()
    order.add(Candy("Candy Corn", 1.5, .25))
    order.add(Candy("Gummy Bears", .25, .35))
    order.add(Cookie("Chocolate Chip", 6, 3.99))
    order.add(IceCream("Pistachio", 2, .79))
    order.add(Sundae("Vanilla", 3, .69, "Hot Fudge", 1.29))
    order.add(Cookie("Oatmeal Raisin", 2, 3.45))

    for item in order.order:#prints out every item in the order list
        print(item.name)
    print(order.__len__())#prints out the amount of items in the order list


main()