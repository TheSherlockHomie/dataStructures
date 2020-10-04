#include<iostream>

using namespace std;

struct Node
{
    Node* next;
    int data;
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList()
    {
        head = nullptr;
    }
    void Insert(int nincompoop)
    {
        Node* var = new Node;
        Node* tmp = new Node;
        if (head == nullptr)
        {
            head = var;
            head->data = nincompoop;
            head->next = nullptr;
        }
        else
        {
            tmp = head;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = var;
            var->data = nincompoop;
            var->next = nullptr;
        }
    }
    void Scan()
    {
        Node* tmp = new Node;
        if (head == nullptr)
        {
            cout << "empty";
        }
        else
        {
            tmp = head;
            while (tmp != nullptr)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }
    }
    int size()
    {
        Node* tmp = new Node;
        int count = 0;
        if (head == nullptr)
        {
            count = 0;
        }
        else
        {
            tmp = head;
            while (tmp != nullptr)
            {
                tmp = tmp->next;
                count++;
            }
        }
        return count;
    }
};


int main()
{
    LinkedList LL;
    /*LL.Insert(1);
    LL.Insert(2);
    LL.Insert(3);
    LL.Insert(4);
    LL.Insert(5);
    LL.Scan();*/
    cout<<"\nSize of the Linked List = "<<LL.size();
}