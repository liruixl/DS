#pragma once
#include "ds/BinNode.h"

template <typename Key, typename T>
class BinNodeKey : public BinNode<T>
{
private:
	Key key;
	T elem;
	BinNodeKey* lc;
	BinNodeKey* rc;
public:

	BinNodeKey() { lc = rc = nullptr; }
	BinNodeKey(const Key& k,const T& value, BinNodeKey* left = nullptr, BinNodeKey* right = nullptr)
	{
		key = k;
		elem = value;
		lc = left;
		rc = right;
	}
	~BinNodeKey() {} //Ë­¸ºÔðdeleteÂï?

	Key getKey() const { return key; }

	T& val() override { return elem; }
	void setVal(const T& value) override { elem = value; }

	BinNode<T>* left() const override
	{
		return lc; //subclass -> baseclass
	}
	BinNode<T>* right() const override
	{
		return rc;
	}

	void setLeft(BinNode<T>* left) override
	{
		lc = dynamic_cast<BinNodeKey*>(left);
	}
	void setRight(BinNode<T>* right) override
	{
		rc = dynamic_cast<BinNodeKey*>(right);
	}

	bool isLeaf() const override
	{
		return (lc == nullptr) && (rc == nullptr);
	}
};
