#include <iostream>
#include <memory>

#include "LinkedList.h"

int main()
{
    auto n0 = std::make_unique<ds::Node>(0);

    auto n1 = std::make_unique<ds::Node>(1);
    n1->next = std::move(n0);

    auto n2 = std::make_unique<ds::Node>(2);
    n2->next = std::move(n1);
}

/*
* Output:
* Destroyed node with data: 2
* Destroyed node with data: 1
* Destroyed node with data: 0
* 
* Recursively deletes all Nodes.
* Could causde stack overflow if size of list is too large
*/