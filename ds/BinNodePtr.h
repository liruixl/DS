#pragma once
#include "ds/BinNode.h"

template <typename T>
class BinNodePtr : public BinNode<T>
{
private:
	T elem;
	BinNodePtr* lc;
	BinNodePtr* rc;
public:

	BinNodePtr() { lc = rc = nullptr; }
	BinNodePtr(const T& value, BinNodePtr* left = nullptr, BinNodePtr* right = nullptr)
	{
		elem = value;
		lc = left;
		rc = right;
	}

	T& val() override { return elem; }
	void setVal(const T& value) override { elem = value; }

	BinNode<T>* left() const override
	{
		//return (BinNode*)lc;
		return lc; //subclass -> baseclass
	}
	BinNode<T>* right() const override
	{
		//return (BinNode*)rc;
		return rc;
	}

	void setLeft(BinNode<T>* left) override
	{
		lc = dynamic_cast<BinNodePtr*>(left);
	}
	void setRight(BinNode<T>* right) override
	{
		rc = dynamic_cast<BinNodePtr*>(right);
	}

	bool isLeaf() const override
	{
		return (lc == nullptr) && (rc == nullptr);
	}
};

