#ifndef dsbheap
#define dsbheap

#include<iostream>
#include<vector>
#include<string>

namespace ds
{
    template<typename T>
    class BinaryHeap
    {
        //public data members and member functions.
    public:
        BinaryHeap() {}

        size_t Size();
        T Poll();

        void Insert(T n);
        void Delete(T n);

        void Display();

        //private data members and member functions.
    private:
        std::vector <T> heap;

        size_t parent(size_t child);
        size_t left(size_t parent);
        size_t right(size_t parent);

        bool leftexist(size_t parent);
        bool rightexist(size_t parent);

        void bubbleup(size_t index);
        void bubbledown(size_t index);
    };
}

//Returns size of heap.
template <typename T>
size_t ds::BinaryHeap<T>::Size()
{
    return heap.size();
}

//Returns top of heap.
template <typename T>
T ds::BinaryHeap<T>::Poll()
{
    if (Size() == 0)
    {
        throw std::string("Heap is Empty");
    }
    return heap[0];
}

//Insert element into heap
template <typename T>
void ds::BinaryHeap<T>::Insert(T n) {
    heap.push_back(n);
    bubbleup(Size() - 1);
}

//Delete an element from heap
template <typename T>
void ds::BinaryHeap<T>::Delete(T n) {
    if (Size() == 0)
    {
        throw std::string("Heap is Empty");
    }

    size_t pos = 0;
    while (heap[pos] != n && pos < Size())
    {
        pos++;
        if (pos == Size())
        {
            throw std::string("Element not present in heap");
        }
    }

    //swap element with last element present in heap.
    heap[pos] = heap[Size() - 1];
    heap.pop_back(); //delete element

    bubbledown(pos); //heapify
}

//Display all elements in heap
template <typename T>
void ds::BinaryHeap<T>::Display()
{
    if (Size() == 0)
    {
        std::cout << "Heap is Empty" << "\n";
        return;
    }

    std::cout << "Heap: ";
    for (auto el : heap)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";
}


//Private members:

//Returns index of parent element
template <typename T>
size_t ds::BinaryHeap<T>::parent(size_t child)
{
    if (child == 0)
        throw std::string("Parent does not exist");

    size_t p = (child - 1) / 2;
    return p;
}

//Returns index of left child
template <typename T>
size_t ds::BinaryHeap<T>::left(size_t parent)
{
    size_t l = 2 * parent + 1;

    if (l < Size())
        return l;
    else
        throw std::string("Child does not exist");
}

//Returns index of right child
template <typename T>
size_t ds::BinaryHeap<T>::right(size_t parent)
{
    size_t r = 2 * parent + 2;

    if (r < Size())
        return r;
    else
        throw std::string("Child does not exist");
}

//Check if left child exists
template <typename T>
bool ds::BinaryHeap<T>::leftexist(size_t parent)
{
    size_t l = 2 * parent + 1;

    if (l < Size())
        return true;
    else
        return false;
}

//Check if right child exists
template <typename T>
bool ds::BinaryHeap<T>::rightexist(size_t parent)
{
    size_t r = 2 * parent + 2;

    if (r < Size())
        return true;
    else
        return false;
}


//Bubble Up given element in the heap
template <typename T>
void ds::BinaryHeap<T>::bubbleup(size_t in)
{
    if (in > 0 && heap[parent(in)] > heap[in])
    {
        T temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;

        bubbleup(parent(in));
    }
}

//Bubble Down given element in the heap
template <typename T>
void ds::BinaryHeap<T>::bubbledown(size_t in)
{
    size_t child = 0, child1 = 0;

    if (rightexist(in))
        child1 = right(in);

    if (leftexist(in))
        child = left(in);

    // Finding minimum of left and right child iff both of them exist
    if (rightexist(in) && leftexist(in) && heap[child] > heap[child1])
    {
        child = child1;
    }

    if (leftexist(in) && heap[in] > heap[child])
    {
        T temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;

        bubbledown(child);
    }
}

#endif
