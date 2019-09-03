#pragma once

template <typename T>
class Stack
{
	virtual bool push(const T& item) = 0;
	virtual bool pop(T& item) = 0;
	virtual void clear() = 0;
	virtual bool topValue(T& item) const = 0;
	virtual int length() const = 0;
};
