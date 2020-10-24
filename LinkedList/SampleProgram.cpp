#include <iostream>
#include <memory>

#include "LinkedList.h"

int main()
{
    ds::LList list;
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);

    list.pop_back();
}
