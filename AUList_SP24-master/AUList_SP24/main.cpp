#include <iostream>
#include "AUList.h"
#include "ItemType.h"




//Is the error in the AUList .cpp file? With the way that the getitem function is written.
// Cap the length of the list - set to 20 still not working infinte loop still
// ItemType not used constructor 
//



int main() {
    AUList myList;

    // Insert items
    ItemType item1, item2, item3;
    item1.setValue(5);
    item2.setValue(10);
    item3.setValue(7);

    myList.PutItem(item1);
    myList.PutItem(item2);
    myList.PutItem(item3);

    // Print items
    std::cout << "Items in the list: ";
    myList.ResetList();
    ItemType currentItem;
    while ((currentItem = myList.GetNextItem()).getValue() != -1) {
        std::cout << currentItem.getValue() << " ";
    }
    std::cout << std::endl;

    // Restoring list position after ResetList
    myList.ResetList();

    // Search for an item
    ItemType searchItem;
    searchItem.setValue(10);
    searchItem.setValue(4); // Not in the list
    bool found = false;
    ItemType foundItem = myList.GetItem(searchItem, found);

    if (found) {
        std::cout << "Item found: " << foundItem.getValue() << std::endl;
    }
    else {
        std::cout << "Item not found." << std::endl;
    }

    // Delete an item
    ItemType deleteItem;
    deleteItem.setValue(5);
    myList.DeleteItem(deleteItem);

    // Print items after deletion
    std::cout << "Items in the list after deletion: ";
    myList.ResetList();
    while ((currentItem = myList.GetNextItem()).getValue() != -1) {
        std::cout << currentItem.getValue() << " ";
    }
    std::cout << std::endl;

    return 0;
}
