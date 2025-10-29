#AW Dessert Shop Part 1

from dessert import *

class DessertShop():
    def user_prompt_candy():
        pass

    def user_prompt_cookie():
        pass

    def user_prompt_icecream():
        pass

    def user_prompt_sundae():
        pass



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

    def main():
        shop = DessertShop()
        order = Order()
        '''
        order.add(Candy('Candy Corn', 1.5, 0.25))
        order.add(Candy('Gummy Bears', 0.25, 0.35))
        order.add(Cookie('Chocolate Chip', 6, 3.99))
        order.add(IceCream('Pistachio', 2, 0.79))
        order.add(Sundae('Vanilla', 3, 0.69, 'Hot Fudge', 1.29))
        order.add(Cookie('Oatmeal Raisin', 2, 3.45))
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



main()