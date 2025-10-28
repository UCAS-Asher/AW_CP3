from dessert import *

def test_IceCream():
    test_item = IceCream()
    assert test_item.name == ""
    assert test_item.scoop_count == 0
    assert test_item.price_per_scoop == 0.0
    
    test_item = IceCream("Vanilla", 5, 1)
    assert test_item.name == "Vanilla"
    assert test_item.scoop_count == 5
    assert test_item.price_per_scoop == 1
    
    test_item.name = "Strawberry"
    test_item.scoop_count = 3
    test_item.price_per_scoop = 1.5
    assert test_item.name == "Strawberry"
    assert test_item.scoop_count == 3
    assert test_item.price_per_scoop == 1.5