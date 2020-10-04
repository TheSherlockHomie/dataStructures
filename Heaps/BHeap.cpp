#include "BHeap.h"

// Returns size of heap.
template <typename T>
size_t ds::BinaryHeap<T>::Size()
{
	return heap.size();
}

// Returns left child.
template <typename T>
size_t ds::BinaryHeap<T>::left(size_t parent)
{
	size_t l = 2 * parent + 1;
	if (l < Size())
		return l;
	else
		throw "Child does not exist";
}

// Check if left child exists.
template <typename T>
bool ds::BinaryHeap<T>::leftexist(size_t parent)
{
	size_t l = 2 * parent + 1;
	if (l < Size())
		return true;
	else
		return false;
}


// Returns right child.
template <typename T>
size_t ds::BinaryHeap<T>::right(size_t parent)
{
	size_t r = 2 * parent + 2;
	if (r < Size())
		return r;
	else
		throw "Child does not exist";
}

// Check if right child exists.
template <typename T>
bool ds::BinaryHeap<T>::rightexist(size_t parent)
{
	size_t r = 2 * parent + 2;
	if (r < Size())
		return true;
	else
		return false;
}

//Returns parent.
template <typename T>
size_t ds::BinaryHeap<T>::parent(size_t child)
{
	if (child == 0)
		throw "Parent does not exist";
	size_t p = (child - 1) / 2;
	return p;
}

//Bubble UP: Used for implementing heap operations.
template <typename T>
void ds::BinaryHeap<T>::bubbleup(size_t in)
{
	if (in > 0  && heap[parent(in)] > heap[in])
	{
		T temp = heap[in];
		heap[in] = heap[parent(in)];
		heap[parent(in)] = temp;
		bubbleup(parent(in));
	}
}

//Bubble DOWN : Used for implementing heap operations.
template <typename T>
void ds::BinaryHeap<T>::bubbledown(size_t in)
{
	size_t child, child1;
	if (rightexist(in))
		child1 = right(in);
	if (leftexist(in))
		child = left(in);
	

	// Finding minimum of left and right child if both of them exists.
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

//Heap Operation : Insertion.
template <typename T>
void ds::BinaryHeap<T>::Insert(T n) {
	heap.push_back(n);
	bubbleup(Size() - 1);
}

//Heap Operation : Return TOP of heap.
template <typename T>
T ds::BinaryHeap<T>::Poll()
{
	if (Size() == 0)
	{
		throw "Heap is Empty";
	}
	return heap[0];
}

//Heap Operation : Display all elements in heap.
template <typename T>
void ds::BinaryHeap<T>::Display()
{
	if (Size() == 0)
	{
		std::cout << " Heap is Empty " << "\n";
		return;
	}
	std::cout << " Heap: ";
	size_t pos = 0;
	while (pos != Size())
	{
		std::cout << heap[pos] << " ";
		pos++;
	}
	std::cout << "\n";
}

//Heap Operation : Delete an element from heap.
template <typename T>
void ds::BinaryHeap<T>::Delete(T n) {
	size_t pos = 0;
	while (heap[pos] != n && pos < Size())
	{
		pos++;
		if (pos == Size())
		{
			throw "Element not present in heap";
		}
	}
	// interchange element with last element present in heap.
	heap[pos] = heap[Size() - 1];
	heap.pop_back();
	bubbledown(pos);
	std::cout << "Element Deleted" << "\n";
}