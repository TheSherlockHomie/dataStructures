#ifndef dsbheap
#define dsbheap

#include<iostream>
#include<vector>

namespace ds
{
	template<typename T> 
	class BinaryHeap 
	{
		//private data members and member functions.
	private:
		std::vector <T> heap;
		size_t parent(size_t child);
		size_t left(size_t parent);
		size_t right(size_t parent);
		void bubbleup(size_t index);
		void bubbledown(size_t index);

		//public data members and member functions.
	public:
		BinaryHeap() {}
		size_t Size();
		void Insert(T n);
		void Poll();
		void Delete(T n);
		void Display();

	};
}

#endif
