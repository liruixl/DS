#pragma once
//Binary tree node's element

template <typename T>
class BinNode
{
public:
	virtual T& val() = 0;
	virtual void setVal(const T&) = 0;

	virtual BinNode* left() const = 0;
	virtual BinNode* right() const = 0;

	virtual void setLeft(BinNode*) = 0;
	virtual void setRight(BinNode*) = 0;

	virtual bool isLeaf() const = 0;

};