#pragma once

template <typename T>
class Queue
{
public:
	virtual bool front(T&) const = 0;
	virtual bool back(T&) const = 0;

	virtual void push(const T& val) = 0;
	virtual void pop() = 0;

	virtual bool empty() const = 0;
	virtual int size() const = 0;
};