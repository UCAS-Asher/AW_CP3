from dessert import *

def test_Sundae():
    test_item = Sundae()
    assert test_item.name == ""
    assert test_item.scoop_count == 0
    assert test_item.price_per_scoop == 0.0
    assert test_item.topping_name == ""
    assert test_item.topping_price == 0.0
    
    test_item = Sundae("Vanilla", 3, 1.3, "Cherry", 1)
    assert test_item.name == "Vanilla"
    assert test_item.scoop_count == 3
    assert test_item.price_per_scoop == 1.3
    assert test_item.topping_name == "Cherry"
    assert test_item.topping_price == 1
    
    test_item.name = "Strawberry"
    test_item.scoop_count = 4
    test_item.price_per_scoop = 1.5
    test_item.topping_name = "Sprinkles"
    test_item.topping_price = 0.3
    assert test_item.name == "Strawberry"
    assert test_item.scoop_count == 3
    assert test_item.price_per_scoop == 1.5
    assert test_item.topping_name == "Sprinkles"
    assert test_item.topping_price == 0.3