#include <iostream>
#include <memory>

#include "LinkedList.h"

int main()
{
    auto n0 = std::make_unique<Node>(0);

    auto n1 = std::make_unique<Node>(1);
    n1->next = std::move(n0);

    auto n2 = std::make_unique<Node>(2);
    n2->next = std::move(n1);
}