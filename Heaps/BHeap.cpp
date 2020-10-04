#include "BHeap.h"

// Returns size of heap.
int ds::BinaryHeap::Size()
{
	return heap.size();
}

// Returns left child.
int ds::BinaryHeap::left(int parent)
{
	int l = 2 * parent + 1;
	if (l < Size())
		return l;
	else
		return -1;
}

// Returns right child.
int ds::BinaryHeap::right(int parent)
{
	int r = 2 * parent + 2;
	if (r < Size())
		return r;
	else
		return -1;
}

//Returns parent.
int ds::BinaryHeap::parent(int child)
{
	if (child == 0)
		return -1;
	int p = (child - 1) / 2;
	return p;
}

//Bubble UP: Used for implementing heap operations.
void ds::BinaryHeap::bubbleup(int in)
{
	if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
	{
		int temp = heap[in];
		heap[in] = heap[parent(in)];
		heap[parent(in)] = temp;
		bubbleup(parent(in));
	}
}

//Bubble DOWN : Used for implementing heap operations.
void ds::BinaryHeap::bubbledown(int in)
{

	int child = left(in);
	int child1 = right(in);

	// Finding minimum of left and right child if both of them exists.
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

//Heap Operation : Insertion.
void ds::BinaryHeap::Insert(int n) {
	heap.push_back(n);
	bubbleup(Size() - 1);
}

//Heap Operation : Return TOP of heap. 
void ds::BinaryHeap::Poll()
{
	if (Size() == 0)
	{
		std::cerr << "Heap is Empty" << "\n";
		return;
	}
	std::cout << "TOP element of heap is : " << heap[0] << "\n";
}

//Heap Operation : Display all elements in heap.
void ds::BinaryHeap::Display()
{
	if (Size() == 0)
	{
		std::cout << " Heap is Empty " << "\n";
		return;
	}
	std::cout << "Elements of Heap: ";
	int pos = 0;
	while (pos != Size())
	{
		std::cout << heap[pos] << " ";
		pos++;
	}
	std::cout << "\n";
}

//Heap Operation : Delete an element from heap.
void ds::BinaryHeap::Delete(int n) {
	int pos = 0;
	while (heap[pos] != n && pos < Size())
	{
		pos++;
		if (pos == Size())
		{
			std::cerr << "Element not present in heap" << "\n";
			return;
		}
	}
	// Interchange element with last element present in heap.
	heap[pos] = heap[Size() - 1];
	heap.pop_back();
	bubbledown(pos);
	std::cout << "Element Deleted" << "\n";
}