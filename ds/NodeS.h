#pragma once

template<typename Elem>
class NodeS
{
public:
	Elem element;
	NodeS* next;
	NodeS(const Elem& elemval, NodeS* nextval = nullptr)
	{
		element = elemval;
		next = nextval;
	}
	NodeS(NodeS* nextval = nullptr)
	{
		next = nextval;
	}
};
