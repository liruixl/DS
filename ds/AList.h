#pragma once
#include "List.h"
#include <iostream>

template<typename Elem>
class AList : public List<Elem>
{
public:
	AList(int size)
	{
		maxSize = size;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}
	~AList() { delete[] listArray; }

	void clear() override
	{
		delete[] listArray;
		listSize = fence = 0;
		listArray = new Elem[maxSize];
	}
	bool insert(const Elem&) override;
	bool append(const Elem&) override;
	bool remove(Elem&) override;
	void setStart() override { fence = 0; }
	void setEnd() override { fence = listSize; }
	void prev() override { if (fence != 0) --fence; }
	void next() override { if (fence <= listSize) ++fence; }
	int	 leftLength() const override { return fence; }
	int  rightLength() const override { return listSize - fence; }
	bool setPos(int pos) override 
	{ 
		if ((pos >= 0) && (pos <= listSize)) fence = pos; 
		return (pos >= 0) && (pos <= listSize);
	}
	bool getValue(Elem& it) const override
	{
		if (rightLength() == 0) return false;
		else
		{
			it = listArray[fence];
			return true;
		}
	}
	void print() const override
	{
		int temp = 0;
		std::cout << "< ";
		while (temp < fence) std::cout << listArray[temp++] << " ";
		std::cout << "| ";
		while (temp < listSize) std::cout << listArray[temp++] << " ";
		std::cout << ">\n";
	}

private:
	int maxSize;
	int listSize;
	int fence;
	Elem* listArray;
};

template <typename Elem>
bool AList<Elem>::insert(const Elem& item)
{
	if (listSize == maxSize) return false;
	for (int i = listSize; i != fence; --i)
	{
		listArray[i] = listArray[i - 1];
	}
	listArray[fence] = item;
	++listSize;
	return true;
}

template <typename Elem>
bool AList<Elem>::append(const Elem& item)
{
	if (listSize == maxSize) return false;
	//listArray[listSize] = item;
	//listSize++;
	listArray[listSize++] = item;
	return true;
}

template <typename Elem>
bool AList<Elem>::remove(Elem& item)
{
	if (fence == listSize) return false;
	item = listArray[fence];
	for (int i = fence; i < listSize - 1; ++i)
	{
		listArray[i] = listArray[i + 1];
	}
	--listSize;
	return true;
}