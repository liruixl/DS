#pragma once
#include "Stack.h"

template <typename T>
class AStack : public Stack<T>
{
public:
	AStack(int sz) 
	{ 
		maxsize = sz; 
		top = 0; 
		listArray = new T[sz]; 
	}
	~AStack() { delete[] listArray; }

	bool push(const T& item) override
	{
		if (top == maxsize) return false;
		else 
		{
			listArray[top++] = item;
			return true;
		}
	}
	bool pop(T& item) override
	{
		if (top == 0) return false;
		else 
		{
			item = listArray[--top];
			return true;
		} 

	}
	void clear() override
	{
		//delete[] listArray;
		top = 0;
	}
	bool topValue(T& item) const override
	{
		if (top == 0) return false;
		else
		{
			item = listArray[top - 1];
			return true;
		}
	}
	int length() const override
	{
		return top;
	}

private:
	int maxsize;
	int top;
	T* listArray;
};