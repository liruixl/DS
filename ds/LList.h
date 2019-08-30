#pragma once
#include "List.h"

#include <iostream>
#include "NodeS.h"

template<typename Elem>
class LList : public List<Elem>
{
public:
	LList(){ init(); }
	~LList() { removeall(); }

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

private:

	void init()
	{
		head = tail = fence = new NodeS<Elem>;
		leftcnt = rightcnt = 0;
	}
	void removeall()
	{
		/*NodeS<Elem>* curr = head;
		while (curr)
		{
			delete curr;
			curr = curr->next;
		}
		init();*/

		while (head!=nullptr)
		{
			fence = head;
			head = head->next;
			delete fence;
		}
	}

	NodeS<Elem>* head;
	NodeS<Elem>* tail;
	//fence Node, pointer to last element on lefe side
	NodeS<Elem>* fence;
	int leftcnt;
	int rightcnt;
};

template <typename Elem>
bool LList<Elem>::insert(const Elem& item)
{
	NodeS<Elem>* node = new NodeS<Elem>(item);
	node->next = fence->next;
	fence->next = node;

	//fence->next = new NodeS<Elem>(item, fence->next);

	++rightcnt;

	if (tail == fence)
	{
		tail = fence->next;
	}
	return true;
}

template <typename Elem>
bool LList<Elem>::append(const Elem& item)
{
	tail->next = new NodeS<Elem>(item);
	tail = tail->next;
	++rightcnt;
	return true;
}

template <typename Elem>
bool LList<Elem>::remove(Elem& item)
{
	if (fence == tail) return false;

	NodeS<Elem>* curr = fence->next;
	item = curr->element;
	fence->next = curr->next;
	if (curr == tail)
	{
		tail = fence;
	}
	delete curr;
	--rightcnt;
	return true;
}

template <typename Elem>
void LList<Elem>::prev()
{
	if (fence == head) return;

	NodeS<Elem>* curr = head;
	while (curr->next != fence)
	{
		curr = curr->next;
	}
	fence = curr;
	--leftcnt;
	++rightcnt;
}

template <typename Elem>
bool LList<Elem>::setPos(int pos)
{
	if ((pos >= 0) && (pos <= leftcnt + rightcnt))
	{
		/*NodeS<Elem>* obj = head;
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
void LList<Elem>::print() const
{
	NodeS<Elem>* temp = head;
	std::cout << "<";
	while (temp != fence)
	{
		std::cout << temp->next->element << " ";
		temp = temp -> next;
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