#pragma once
#include "List.h"

#include <iostream>
#include "NodeD.h"


template<typename Elem>
class DLList : public List<Elem>
{
public:
	DLList() { init(); }
	~DLList() { removeall(); }

	void clear() override
	{
		removeall();
		init();
	}
	bool insert(const Elem&) override;
	bool append(const Elem&) override;
	bool remove(Elem&) override;
	void setStart() override { fence = head; leftcnt = 0; rightcnt += leftcnt; }
	void setEnd() override { fence = tail; rightcnt = 0; leftcnt += rightcnt; }
	void prev() override;
	void next() override
	{
		if (fence != tail)
		{
			fence = fence->next; ++leftcnt; --rightcnt;
		}
	}
	int	 leftLength() const override { return leftcnt; }
	int  rightLength() const override { return rightcnt; }
	bool setPos(int pos) override;
	bool getValue(Elem& it) const override
	{
		if (rightLength() == 0) return false;
		it = fence->next->element;
		return true;
	}
	void print() const override;

	void printUpdown() const;
private:

	void init()
	{
		head = tail = fence = new NodeD<Elem>;
		leftcnt = rightcnt = 0;
	}
	void removeall()
	{
		while (head != nullptr)
		{
			fence = head;
			head = head->next;
			delete fence;
		}
	}

	NodeD<Elem>* head;
	NodeD<Elem>* tail;
	//fence Node, pointer to last element on lefe side
	NodeD<Elem>* fence;
	int leftcnt;
	int rightcnt;
};

template <typename Elem>
bool DLList<Elem>::insert(const Elem& item)
{
	/*NodeD<Elem>* node = new NodeD<Elem>(item);

	node->next = fence->next;
	node->prev = fence;

	fence->next = node;*/

	fence->next = new NodeD<Elem>(item, fence, fence->next);

	if (tail == fence)
	{
		tail = fence->next;
	}
	else
	{
		fence->next->next->prev = fence->next;
	}

	++rightcnt;
	return true;
}

template <typename Elem>
bool DLList<Elem>::append(const Elem& item)
{
	tail->next = new NodeD<Elem>(item,tail,nullptr);
	tail = tail->next;
	++rightcnt;
	return true;
}

template <typename Elem>
bool DLList<Elem>::remove(Elem& item)
{
	if (fence == tail) return false;

	NodeD<Elem>* curr = fence->next;
	item = curr->element;

	fence->next = curr->next;

	if (curr == tail)
	{
		tail = fence;
	}
	else
	{
		//fence->next->next->prev = fence;
		curr->next->prev = fence;
	}

	delete curr;
	--rightcnt;
	return true;
}

template <typename Elem>
void DLList<Elem>::prev()
{
	if (fence == head) return;

	fence = fence->prev;
	--leftcnt;
	++rightcnt;
}

template <typename Elem>
bool DLList<Elem>::setPos(int pos)
{
	if ((pos >= 0) && (pos <= leftcnt + rightcnt))
	{
		/*NodeD<Elem>* obj = head;
		for (int i = 1; i <= pos; ++i)
		{
			obj = obj->next;
		}
		fence = obj;*/

		fence = head;
		for (int i = 0; i < pos; ++i) fence = fence->next;

		rightcnt = leftcnt + rightcnt - pos;
		leftcnt = pos;

		return true;
	}

	return false;

}

template <typename Elem>
void DLList<Elem>::print() const
{
	NodeD<Elem>* temp = head;
	std::cout << "<";
	while (temp != fence)
	{
		std::cout << temp->next->element << " ";
		temp = temp->next;
	}
	std::cout << "| ";
	while (temp != tail)
	{
		std::cout << temp->next->element << " ";
		temp = temp->next;
	}
	std::cout << ">\n";
	std::cout << "left : " << leftcnt << " right : " << rightcnt << "\n";
}

template<typename Elem>
void DLList<Elem>::printUpdown() const
{
	NodeD<Elem>* temp = tail;
	std::cout << "<";
	while (temp != fence)
	{
		std::cout << temp->element << " ";
		temp = temp->prev;
	}


	std::cout << "| ";
	while (temp != head)
	{
		std::cout << temp->element << " ";
		temp = temp->prev;
	}
	std::cout << ">\n";
	std::cout << "left : " << leftcnt << " right : " << rightcnt << "\n";
}
