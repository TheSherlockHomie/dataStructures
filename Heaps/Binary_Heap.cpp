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
	BinaryHeap() {}
	int Size();
	void Insert(int n);
	void Poll();
	void Delete(int n);
	void Display();

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

void BinaryHeap::bubbleup(int in)
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

void BinaryHeap::Insert(int n) {
	heap.push_back(n);
	bubbleup(Size() - 1);
}

void BinaryHeap::Poll() 
{
	if (Size() == 0) 
	{
		cout << "Heap is Empty" << "\n";
		return;
	}
	heap[0] = heap[Size() - 1];
	heap.pop_back();
	bubbledown(0);
	cout << "Root Element Deleted" << "\n";
}

void BinaryHeap::Display() 
{
	if (Size() == 0)
	{
		cout << " Heap is Empty " << "\n";
		return;
	}
	cout << "Elements of Heap: ";
	int pos = 0;
	while (pos != Size()) 
	{
		cout << heap[pos] << " ";
		pos++;
	}
	cout << "\n";
}

void BinaryHeap::Delete(int n) {
	int pos = 0;
	while (heap[pos] != n && pos < Size())
	{
		pos++;
		if (pos == Size())
		{
			cout << "Element not present in heap" << "\n";
			return;
		}
	}
	heap[pos] = heap[Size() - 1];
	heap.pop_back();
	bubbledown(pos);
	cout << "Element Deleted" << "\n";
}

int main()
{
	BinaryHeap obj;
	while (1) 
	{
		int c, ele;
		cout << "1.Insert Element" << "\n";
		cout << "2.Delete Minimum Element" << "\n";
		cout << "3.Delete Element" << "\n";
		cout << "4.Display Heap" << "\n";
		cout << "5.Exit" << "\n";
		cout << "Enter your choice: ";
		cin >> c;
		switch (c) 
		{
		case 1:
			cout << "Enter the element to be inserted: ";
			cin >> ele;
			obj.Insert(ele);
			break;
		case 2:
			obj.Poll();
			break;
		case 3:
			cout << "Enter the element to be deleted: ";
			cin >> ele;
			obj.Delete(ele);
			obj.Display();
			break;
		case 4:
			obj.Display();
			break;
		case 5:
			exit(1);
		default:
			cout << "Enter Correct Choice ... Try Again " << "\n";
		}
	}
	return 0;
}

