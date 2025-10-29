from dessert import *

def test_Candy():
    test_item = Candy()
    assert test_item.name == ""
    assert test_item.tax_percent == 7.25
    assert test_item.candy_weight == 0.0
    assert test_item.price_per_pound == 0.0
    
    test_item = Candy("Snickers", 6.70, 1, 1)
    assert test_item.name == "Snickers"
    assert test_item.tax_percent == 6.70
    assert test_item.candy_weight == 1
    assert test_item.price_per_pound == 1
    
    test_item.name = "Twix"
    test_item.tax_percent = 7.60
    test_item.candy_weight = 0.5
    test_item.price_per_pound = 2
    assert test_item.name == "Twix"
    assert test_item.tax_percent == 7.60
    assert test_item.candy_weight == 0.5
    assert test_item.price_per_pound == 2

    assert test_item.calculate_cost() == 1
    assert test_item.calaculate_tax() == 0.08