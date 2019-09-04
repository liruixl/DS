#pragma once

#pragma once
#include <iostream>
#include "ds/Queue.h"
#include "ds/NodeS.h"

template <typename T>
class LQueue : public Queue<T>
{
private:
	int _size;
	NodeS<T>* _front;
	NodeS<T>* _rear;

public:
	LQueue()
	{
		_size = 0;
		_front = nullptr;
		_rear = nullptr;
	}
	~LQueue()
	{
		while (_front)
		{
			auto temp = _front;
			_front = _front->next;
			delete temp;
		}
		_rear = nullptr;
		_size = 0;
	}

	bool front(T& val) const override
	{
		if (_front)
		{
			val = _front->element;
			return true;
		}
		return false;
	}
	bool back(T& val) const override
	{
		if (_rear)
		{
			val = _rear->element;
			return true;
		}
		return false;
	}

	void push(const T& val) override
	{
		if (_rear)
		{
			_rear->next = new NodeS<T>(val);
			_rear = _rear->next;
		}
		else
		{
			_front = _rear = new NodeS<T>(val);
		}
		++_size;
	}
	void pop() override
	{
		//if (_front == nullptr) return;
		if (_size == 0) return;

		auto temp = _front;
		_front = _front->next;
		delete temp;

		if (_front == nullptr)
			_rear = nullptr;
		--_size;
	}

	bool empty() const override
	{
		return _size == 0;
	}
	int size() const override
	{
		return _size;
	}

	void print()
	{
		std::cout << size() << " ";
		std::cout << _front->element << " ";
		std::cout << _rear->element << " " << std::endl;
	}
};