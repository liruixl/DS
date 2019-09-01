#pragma once
#include "Dictionary.h"
#include "ds/SAList.h"

template <typename Key, typename Elem, typename KEComp, typename EEComp>
class SALDict : public Dictionary<Key,Elem,KEComp,EEComp>
{
public:

	SALDict(int size) { list = new SAList<Elem,EEComp>(size); }
	~SALDict() { delete list; }
	void clear() override { list->clear(); }
	bool insert(const Elem& item) override { return list->insert(item); }
	bool remove(const Key& k, Elem& e) override
	{
		for (list->setStart(); list->getValue(e); list->next())
		{
			if (KEComp::eq(k, e))
			{
				list->remove(e);
				return true;
			}
		}
		return false;
	}
	bool removeAny(Elem& e) override
	{
		if (size() == 0) return false;
		list->setEnd();
		list->prev();
		list->remove(e);
		return true;
	}
	bool find(const Key& k, Elem& e) const override
	{
		int left = -1;
		int right = size();
		while (left + 1 != right)
		{
			int mid = (left + right) / 2;
			list->setPos(mid);
			list->getValue(e);

			if (KEComp::eq(k, e))
				return true;
			if (KEComp::lt(k, e))
				right = mid;
			if(KEComp::gt(k,e))
				left = mid;
		}
		return false;
	}
	int  size() const override { return list->leftLength() + list->rightLength(); }

private:
	SAList<Elem, EEComp>* list;
};
