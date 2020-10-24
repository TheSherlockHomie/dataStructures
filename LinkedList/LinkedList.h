#ifndef dslinkedlist
#define dslinkedlist

#include <memory>
#include <iostream>

namespace ds 
{
    struct Node {
        int data;
        std::unique_ptr<Node> next;

        Node(int input)
        {
            data = input;
            next = nullptr;
        }

        ~Node()
        {
            std::cout << "Destroyed node with data: " << data << '\n';
        }
    };
}

#endif
