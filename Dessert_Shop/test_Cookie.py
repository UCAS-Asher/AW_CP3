from dessert import *

def test_Cookie():
    test_item = Cookie()
    assert test_item.name == ""
    assert test_item.cookie_quantity == 0
    assert test_item.price_per_dozen == 0.0
    
    test_item = Cookie("Chocolate Chip", 2, 1.5)
    assert test_item.name == "Chocolate Chip"
    assert test_item.cookie_quantity == 2
    assert test_item.price_per_dozen == 1.5
    
    test_item.name = "Sugar"
    test_item.cookie_quantity = 4
    test_item.price_per_dozen = 2
    assert test_item.name == "Sugar"
    assert test_item.cookie_quantity == 4
    assert test_item.price_per_dozen == 2