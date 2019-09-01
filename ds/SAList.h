#pragma once
#include "AList.h"

template<typename Elem, typename Compare>
class SAList : protected AList<Elem>
{
public:
	SAList(int size) : AList<Elem>(size){}
	~SAList(){}

	bool insert(const Elem& item) override
	{
		Elem curr;
		for (setStart(); getValue(curr); next())
		{
			if(!Compare::lt(curr, item)) break;
		}
		return AList<Elem>::insert(item);
	}

	//All remaining methods are exposed from AList
	//except expand
	AList<Elem>::clear;
	AList<Elem>::remove;
	AList<Elem>::setStart;
	AList<Elem>::setEnd;
	AList<Elem>::prev;
	AList<Elem>::next;
	AList<Elem>::leftLength;
	AList<Elem>::rightLength;
	AList<Elem>::setPos;
	AList<Elem>::getValue;
	AList<Elem>::print;
};
