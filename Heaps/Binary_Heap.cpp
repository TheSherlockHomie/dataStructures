#include<iostream>
#include<vector>

using namespace std;

class BinaryHeap
{
    private:
        vector <int> heap;
        int parent(int child);
        int left(int parent);
        int right(int parent);
        void bubbleup(int index);
        void bubbledown(int index);

    public:
        BinaryHeap(){}
        int Size();
};

int BinaryHeap::Size()
{
    return heap.size();
}

int BinaryHeap::left(int parent)
{
    int l = 2 * parent + 1;
    if (l < Size())
        return l;
    else
        return -1;
}

int BinaryHeap::right(int parent)
{
    int r = 2 * parent + 2;
    if (r < Size())
        return r;
    else
        return -1;
}

int BinaryHeap::parent(int child)
{
    if (child == 0)
        return -1;
    int p = (child - 1) / 2;
    return p;
}

void BinaryHeap::bubbleup (int in)
{
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        bubbleup(parent(in));
    }
}

void BinaryHeap::bubbledown(int in)
{

    int child = left(in);
    int child1 = right(in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])
    {
        child = child1;
    }
    if (child > 0 && heap[in] > heap[child])
    {
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        bubbledown(child);
    }
}

int main()
{
    BinaryHeap obj;
}
