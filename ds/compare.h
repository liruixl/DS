#pragma once

template <typename T>
class compare
{
	bool operator()(const T& lhs, const T& rhs)
	{
		return lhs < rhs;
	}
};