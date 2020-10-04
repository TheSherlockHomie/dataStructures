#pragma once

#include<iostream>
#include<vector>

namespace ds
{
	class BinaryHeap
	{
		//private data members and member functions.
	private:
		std::vector <int> heap;
		int parent(int child);
		int left(int parent);
		int right(int parent);
		void bubbleup(int index);
		void bubbledown(int index);

		//public data members and member functions.
	public:
		BinaryHeap() {}
		int Size();
		void Insert(int n);
		void Poll();
		void Delete(int n);
		void Display();

	};
}
