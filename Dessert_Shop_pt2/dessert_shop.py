#AW Dessert Shop Part 2
from tabulate import tabulate

from dessert import *

class DessertShop():
    def user_prompt_candy(self):
        
        name = input("Enter name of candy: ")
        try:
            weight = int(input("Enter weight (lbs): "))
        except:
            print("Not a Number! Defaulting to 0.0")
            weight = 0.0
        try:
            price = int(input("Enter price per pound: "))
        except:
            print("Not a Number! Defaulting to 0.0")
            price = 0.0
        
        if weight < 0:
            print("Negative Number! Defaulting to 0.0")
            weight = 0.0
        if price < 0:
            print("Negative Number! Defaulting to 0.0")
            price = 0.0

        item = Candy(name, 7.25, weight, price)
        return item

    def user_prompt_cookie(self):
        name = input("Enter the type of the cookie: ")
        try:
            amount = int(input("Enter the amount: "))
        except:
            print("Not a Number! Defaulting to 0.0")
            amount = 0.0
        try:
            price = int(input("Enter price per dozen: "))
        except:
            print("Not a Number! Defaulting to 0.0")
            price = 0.0
        
        if amount < 0:
            print("Negative Number! Defaulting to 0.0")
            amount = 0.0
        if price < 0:
            print("Negative Number! Defaulting to 0.0")
            price = 0.0
        item = Cookie(name, 7.25, amount, price)
        return item

    def user_prompt_icecream(self):
        name = input("Enter the type of ice cream: ")
        try:
            scoops = int(input("Enter the number of scoops: "))
        except:
            print("Not a Number! Defaulting to 0.0")
            scoops = 0.0
        try:
            price = int(input("Enter the price per scoop: "))
        except:
            print("Not a Number! Defaulting to 0.0")
            price = 0.0
        
        if scoops < 0:
            print("Negative Number! Defaulting to 0.0")
            scoops = 0.0
        if price < 0:
            print("Negative Number! Defaulting to 0.0")
            price = 0.0
    
        item = IceCream(name, 7.25, scoops, price)
        return item

    def user_prompt_sundae(self):
        name = input("Enter the type of ice cream: ")
        try:
            scoops = int(input("Enter the number of scoops: "))
        except:
            print("Not a Number! Defaulting to 0.0")
            scoops = 0.0
        try:
            price = int(input("Enter the price per scoop: "))
        except:
            print("Not a Number! Defaulting to 0.0")
            price = 0.0

        top_name = input("Enter the topping: ")
        try:
            top_price = int(input("Enter the price for the topping: "))
        except:
            print("Not a Number! Defaulting to 0.0")
            top_price = 0.0
    
        
        if scoops < 0:
            print("Negative Number! Defaulting to 0.0")
            price = 0.0
        if price < 0:
            print("Negative Number! Defaulting to 0.0")
            price = 0.0
        if top_price < 0:
            print("Negative Number! Defaulting to 0.0")
            top_price = 0.0
        
        item = Sundae(name, 7.25, scoops, price, top_name, top_price)
        return item



def main():

    shop = DessertShop()
    order = Order()
    '''
    order.add(Candy("Candy Corn", 7.25, 1.5, .25))
    order.add(Candy("Gummy Bears", 7.25, 0.25, 0.35))
    order.add(Cookie("Chocolate Chip", 7.25, 6, 3.99))
    order.add(IceCream("Pistachio", 7.25, 2, 0.79))
    order.add(Sundae("Vanilla", 7.25, 3, 0.69, "Hot Fudge", 1.29))
    order.add(Cookie("Oatmeal Raisin", 7.25, 2, 3.45))
    '''
    done: bool = False
    # build the prompt string once
    prompt = '\n'.join([ '\n',
    '1: Candy',
    '2: Cookie',
    '3: Ice Cream',
    '4: Sundae',
    '\nWhat would you like to add to the order? (1-4, Enter for done): '
    ])
    while not done:
        choice = input(prompt)
        match choice:
            case '':
                done = True
            case '1':
                item = shop.user_prompt_candy()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '2':
                item = shop.user_prompt_cookie()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '3':
                item = shop.user_prompt_icecream()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '4':
                item = shop.user_prompt_sundae()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case _:
                print('Invalid response: Please enter a choice from the menu (1-4) or Enter')
    print()
            #
            # Add your code below here to print the receipt as the last thing in main()
            # Make sure that the output format matches the provided sample run
            #
    order_print = []
    whole_order_cost = 0
    whole_tax = 0
    for item in order.order:#prints out every item in the order list
        order_print.append([item.name, f"${item.calculate_cost()}", f"${DessertItem.calculate_tax(item, item.calculate_cost())}"])
        whole_order_cost += item.calculate_cost()
        whole_tax += DessertItem.calculate_tax(item, item.calculate_cost())
    print(tabulate(order_print + [["-"*20, "-"*6, "-"*5], ["Order Subtotals", f"${round(whole_order_cost, 2)}", f"${round(whole_tax, 2)}"], ["Order Total", "", f"${round(whole_order_cost + whole_tax, 2)}"], ["Total Items in the order: ", "", 6]], ["Name", "Cost", "Tax"], tablefmt="fsql"))
    


main()