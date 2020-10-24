#ifndef dslinkedlist
#define dslinkedlist

#include <memory>
#include <iostream>

namespace ds 
{
    struct _Node 
    {
        int data;
        std::shared_ptr<_Node> next;

        _Node(int input)
        {
            data = input;
            next = nullptr;
        }

        ~_Node()
        {
            std::cout << "Destroyed node with data: " << data << '\n';
        }
    };

    class LList
    {
    public:
        LList();

        void push_back(int);

    private:
        std::shared_ptr<_Node> head;
    };
}

ds::LList::LList()
{
    head = nullptr;
}

void ds::LList::push_back(int data)
{
    auto temp = std::make_shared<ds::_Node>(data);

    if (head)
    {
        std::shared_ptr<_Node> iter = head;
        while (iter->next)
        {
            iter = iter->next;
        }
        iter->next = std::move(temp);
    }
    else
    {
        head = std::move(temp);
    }
}

#endif
