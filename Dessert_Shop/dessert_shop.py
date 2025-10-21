#AW Dessert Shop Part 1

from dessert import *

# add to order
# "gummy bears", 0.34, 1.25
# "candy corn", 2.45, 0.36
# "chocolate chip", 6, 2.17
# "mint chocolate chip", 2, 1.66
# "cookies and cream", 1, 1.52
# "vannila sundae", 2, 1.00, "fudge", 0.33

#print out name of each item and how many items in the order

def main():
    order = Order()
    order.add(Candy("Candy Corn", 1.5, .25))
    order.add(Candy("Gummy Bears", .25, .35))
    order.add(Cookie("Chocolate Chip", 6, 3.99))
    order.add(IceCream("Pistachio", 2, .79))
    order.add(Sundae("Vanilla", 3, .69, "Hot Fudge", 1.29))
    order.add(Cookie("Oatmeal Raisin", 2, 3.45))

    print("Items:")
    for item in order.order:
        print(item.name)
    print(order.__len__())


main()