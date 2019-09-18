#pragma once
#include <utility>

template<typename T>
class MaxHeap
{
private:
	T* Heap;
	int size; //maximum size of the heap
	int n;    //number of elements now in the heap
	void siftdown(int);

public:
	MaxHeap(T* h, int num, int max)
	{
		Heap = h;
		size = max;
		n = num;
		buildHeap();
	}

	int heapsize() const { return n; }
	bool isLeaf(int pos) const
	{
		return (pos >= n / 2) && (pos < n);
	}
	int leftchild(int pos) const
	{
		return 2 * pos + 1;
	}
	int rightchild(int pos) const
	{
		return 2 * pos + 2;
	}
	int parent(int pos) const
	{
		return (pos - 1) / 2;
	}

	bool insert(const T*);
	bool removemax(T&);
	bool remove(int, T&);
	void buildHeap()
	{
		for (int i = n / 2 - 1; i >= 0; --i)
		{
			siftdown(i);
		}
	}
};

template<typename T>
void MaxHeap<T>::siftdown(int pos)
{
	if (isLeaf(pos)) return;

	int j = leftchild(pos);
	int rc = rightchild(pos);

	if ((rc < n) && Heap[j] < Heap[rc])
	{
		j = rc;//set j to greater child's value
	}


	if (Heap[pos] < Heap[j])
	{
		std::swap(Heap[pos], Heap[j]);
		siftdown(j);
	}
	else
	{
		return;
	}
}

template<typename T>
bool MaxHeap<T>::insert(const T* item)
{
	if (n >= size) return false;

	int curr = n++;

	Heap[curr] = item;

	while (curr > 0) 
	{
		int p = parent(curr);

		if (Heap[p] < Heap[curr])
		{
			std::swap(Heap[p], Heap[curr]);
			curr = p;
		}
	}

	return true;
}

template<typename T>
bool MaxHeap<T>::removemax(T& item)
{
	if (n == 0) return false;

	std::swap(Heap[0], Heap[--n]);

	item = Heap[n];

	if (n != 0) siftdown(0);
	
	return true;
}

template<typename T>
bool MaxHeap<T>::remove(int pos, T& item)
{
	if ((pos < 0) || pos >= n) return false;
	std::swap(Heap[pos], Heap[--n]);
	while (pos != 0 && Heap[parent(pos)] < Heap[pos])
	{
		std::swap(Heap[parent(pos)], Heap[pos]);
		pos = parent(pos);
	}

	siftdown(pos);

	item = Heap[n];
	return true;
}