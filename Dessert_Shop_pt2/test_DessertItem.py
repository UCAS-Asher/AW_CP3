from dessert import *

def test_Item():
    test_item = DessertItem()
    assert test_item.name == ""
    test_item = DessertItem("Mango")
    assert test_item.name == "Mango"
    test_item.name = "Mustard"
    assert test_item.name == "Mustard"