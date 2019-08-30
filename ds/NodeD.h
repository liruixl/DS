#pragma once

template<typename Elem>
class NodeD
{
public:
	Elem element;
	NodeD* prev;
	NodeD* next;
	NodeD(const Elem& elemval, NodeD* prevval = nullptr, NodeD* nextval = nullptr)
	{
		element = elemval;
		prev = prevval;
		next = nextval;
	}
	NodeD(NodeD* prevval = nullptr,NodeD* nextval = nullptr)
	{
		prev = prevval;
		next = nextval;
	}
};
