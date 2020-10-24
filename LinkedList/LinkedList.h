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
        ~LList();

        void push_back(int);
        void pop_back();

    private:
        std::shared_ptr<_Node> head;

        void clean();
    };
}

//Constructors and Destructors

ds::LList::LList()
{
    head = nullptr;
}

ds::LList::~LList()
{
    clean();
}


//Public functions

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

void ds::LList::pop_back()
{
    if (head)
    {
        if (!head->next)
        {
            head = std::move(nullptr);
        }
        else
        {
            std::shared_ptr<_Node> iter = head;

            while (iter->next->next)
            {
                iter = iter->next;
            }

            iter->next = std::move(nullptr);
        }
    }
}


//Private Functions

void ds::LList::clean()
{
    //Goes through and destructs each node in the list iteratively
    //Otherwise recursive calls to ~_Node() will cause a stack overflow
    while (head)
    {
        head = std::move(head->next);
    }
}

#endif
