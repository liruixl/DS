#pragma once

#include <iostream>
#include "ds/BinNode.h"

class Util
{
public:
	Util() {};
	~Util() {};

	template<typename T>
	void visit(BinNode<T>* node) const
	{
		std::cout << node->val() << " ";
	}

	template<typename T>
	void preorder(BinNode<T>* subroot) const
	{
		if (subroot == nullptr) return;

		visit(subroot);
		preorder(subroot->left());
		preorder(subroot->right());
	}

	template<typename T>
	void inorder(BinNode<T>* subroot) const
	{
		if (subroot == nullptr) return;

		inorder(subroot->left());
		visit(subroot);
		inorder(subroot->right());
	}

	template<typename T>
	void postorder(BinNode<T>* subroot) const
	{
		if (subroot == nullptr) return;

		postorder(subroot->left());
		postorder(subroot->right());
		visit(subroot);
	}

};
