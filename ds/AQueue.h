#pragma once
#include <iostream>
#include "ds/Queue.h"

template <typename T>
class AQueue : public Queue<T>
{
private:
	int maxsize;
	int _front;
	int _rear;
	T* listArray;
public:
	AQueue(int sz) 
	{
		maxsize = sz + 1; //mold operation
		_front = 0;
		_rear = sz;

		//_front = 1;
		//_rear = 0;

		//one more space
		listArray = new T[sz + 1];
	}
	~AQueue() { delete[] listArray; }

	bool front(T& val) const override
	{
		if (empty()) return false;
		else
		{
			val = listArray[_front];
			return true;
		}
	}
	bool back(T& val) const override
	{
		if (empty()) return false;
		else
		{
			val = listArray[_rear];
			return true;
		}
	}

	void push(const T& val) override
	{
		if (size() == maxsize - 1) return;
		if ((_rear + 2) % maxsize == _front) return;

		_rear = (_rear + 1) % maxsize;
		listArray[_rear] = val;
	}
	void pop() override
	{
		if (empty()) return;
		//_rear = (_rear + maxsize - 1) % maxsize;
		//_front!!

		_front = (_front + 1) % maxsize;
	}

	bool empty() const override
	{
		if ((_rear + 1) % maxsize == _front)
		{
			return true;
		}
		return false;
	}
	int size() const override
	{
		return (_rear - _front + 1 + maxsize) % maxsize;
	}

	void print()
	{
		std::cout << size() << " ";
		std::cout << _front << " ";
		std::cout << _rear << " " << std::endl;
	}
};