#include "AUList.h"
#include "ItemType.h"

// I tryed to fix the getitem function but I am not sure....
// Had to revert back to the original code


AUList::AUList()
{
    length = 0;
    loc = -1;
}

AUList::~AUList()
{
}

void AUList::MakeEmpty()
{
    length = 0;
}

bool AUList::IsFull() const
{
    return length == MAX_ITEMS;
   // return length == 20;
}

ItemType AUList::GetItem(ItemType item, bool& found)
{
    found = false;

    int index = findItem(item);

    if (index != -1)
    {
        found = true;
        return Items[index];
    }
    else
        return ItemType(); // Return a default-constructed item or handle it differently
}

void AUList::PutItem(ItemType item)
{
    if (!IsFull()) {
        Items[length] = item;
        length++;
    }
    else {
        // Handle the case where the list is full
        // You might throw an exception, log a message, or handle it differently
    }
}

void AUList::DeleteItem(ItemType item)
{
    int index = findItem(item);
    if (index != -1)
    {
        Items[index] = Items[length - 1];
        length--;
    }
}

void AUList::ResetList()
{
    loc = -1;
}

ItemType AUList::GetNextItem()
{
    loc++;
    if (loc < length) {
        return Items[loc];
    }
    else {
        // Handle the case where loc is out of bounds
        // You might throw an exception or reset loc to a valid state
        // depending on your application's requirements.
        // For simplicity, resetting loc to -1 here.
        loc = -1;
        return ItemType(); // Return a default-constructed item or handle it differently
    }
}

int AUList::findItem(ItemType item)
{
    int i = 0;
    while (i < length)
    {
        if (Items[i].getValue() == item.getValue())
        {
            return i;
        }
        else
            i++;
    }
    return -1;
}
