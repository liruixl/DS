#pragma once
#include "ds/Stack.h"
#include "ds/NodeS.h"

template <typename T>
class LStack : public Stack<T>
{
public:
	LStack(int sz)
	{
		size = 0;
		top = nullptr;
	}
	~LStack() { clear(); }

	bool push(const T& item) override
	{
		top = new NodeS<T>(item, top);
		++size;
		return true;
	}
	bool pop(T& item) override
	{
		if (size == 0) return false;
		else
		{
			item = top->element;

			NodeS<T>* temp = top->next;
			delete top;
			top = temp;
			--size;
			return true;
		}

	}
	void clear() override
	{
		while (top)
		{
			NodeS<T>* curr = top;
			top = top->next;
			delete curr;
			--size;
		}
		if (size != 0)
		{
			std::cout << "clear bug;" << std::endl;
		}
	}
	bool topValue(T& item) const override
	{
		if (size == 0) return false;
		else
		{
			item = top->element;
			return true;
		}
	}
	int length() const override
	{
		return size;
	}

private:
	NodeS<T>* top;
	int size;
};