#pragma once

#include <iostream>
#include "ds/BinNodeKey.h"

#include "ds/compare.h"

template <typename Key, typename T, typename Compare = compare<T>>
class BST
{
private:
	BinNodeKey<Key, T>* root;
	int nodeCount;

	BinNode<T>* minNode(BinNode<T>* subroot)
	{
		//����������Զ����nullptr�ˡ���������
		/*if (subroot == nullptr) return nullptr;
		return minNode(subroot->left());*/

		//end condition should be ��
		if (subroot->left() == nullptr) return subroot;
		return minNode(subroot->left());
		//still may be a tree
	}

	//return the tree with the minimum node deleted
	//�������û�й¶�ڴ棬��Ϊû��delete���ȵ���minNode�õ�ָ�룬���û�����
	BinNode<T>* removeMin(BinNode<T>* subroot)
	{
		if (subroot->left() == nullptr) //min
		{
			return subroot->right();
		}
		else
		{
			subroot->setLeft(removeMin(subroot->left()));
		}
		return subroot;
	}

public:
	BST() { root = nullptr; nodeCount = 0; }
	~BST() { clearhelp(root); };

	void clear()
	{
		clearhelp(root);
		root = nullptr;
		nodeCount = 0;
	}
	void insert(const Key& k, const T& value)
	{
		root = dynamic_cast<BinNodeKey<Key,T>*>(inserthelp(root, k, value));
	}

	//whether to 'delete' is determined by the user
	bool remove(const Key& k, T& item)
	{
		BinNode<T>* del;
		root = dynamic_cast<BinNodeKey<Key, T>*>(removehelp(root, k, del));
		if (del == nullptr) return false;
		else
		{
			item = del->val();
			delete del;
			--nodeCount;
			return true;
		}

		
	}
	T* find(const Key& k)
	{
		return findhelp(root, k);
	}

	int size() const { return nodeCount; }
	bool empty() const { return nodeCount == 0; }

	void print()
	{
		if (root == nullptr)
			std::cout << "empty tree" << std::endl;
		printhelp(root, 0);
	}

private:
	void clearhelp(BinNode<T>* subroot)
	{
		//��������
		if (subroot == nullptr) return;

		clearhelp(subroot->left());
		clearhelp(subroot->right());

		delete subroot;
	}

	BinNode<T>* inserthelp(BinNode<T>* subroot, const Key& k, const T& value)
	{
		BinNodeKey<Key, T>* rootKey = dynamic_cast<BinNodeKey<Key, T>*>(subroot);

		if (subroot == nullptr)
		{
			++nodeCount;
			return new BinNodeKey<Key, T>(k, value);
		}
		

		if (rootKey->getKey() == k) {
			subroot->setVal(value);
		}
		else if (k < rootKey->getKey())
		{
			subroot->setLeft(inserthelp(subroot->left(),k, value));
		}
		else if (k > rootKey->getKey())
		{
			subroot->setRight(inserthelp(subroot->right(), k, value));
		}

		return subroot;
	}

	T* findhelp(BinNode<T>* subroot, const Key& k)
	{
		BinNodeKey<Key, T>* rootKey = dynamic_cast<BinNodeKey<Key, T>*>(subroot);


		if (subroot == nullptr) return nullptr;
		if (rootKey->getKey() == k) return &(subroot->val());

		if (k < rootKey->getKey())
		{
			return findhelp(subroot->left(),k);
		}
		else
		{
			return findhelp(subroot->right(),k);
		}
	}

	BinNode<T>* removehelp(BinNode<T>* subroot, const Key& k, BinNode<T>*& del)
	{
		if (subroot == nullptr) return nullptr; //has not
		
		if (k == dynamic_cast<BinNodeKey<Key, T>*>(subroot)->getKey())
		{

			del = subroot;
			//find it
			if (subroot->left() == nullptr)
			{
				return subroot->right();
			}
			if (subroot->right() == nullptr)
			{
				return subroot->left();
			}

			//BinNode<T>* min = minNode(subroot); //error
			BinNode<T>* min = minNode(subroot->right()); //�����ӽڵ���Сֵ
			BinNode<T>* newRight = removeMin(subroot->right());

			//��minȡ��
			min->setLeft(subroot->left());
			min->setRight(newRight);

			return min;

		}
		else if (k < dynamic_cast<BinNodeKey<Key, T>*>(subroot)->getKey())
		{
			subroot->setLeft(removehelp(subroot->left(), k, del));
		}
		else if (k > dynamic_cast<BinNodeKey<Key, T>*>(subroot)->getKey())
		{
			subroot->setRight(removehelp(subroot->right(), k, del));

		}

		return subroot;
	}

	void printhelp(BinNode<T>* subroot, int level)
	{
		if (subroot == nullptr) return;

		printhelp(subroot->left(),level+1);

		for (int i = 0; i < level; ++i)
		{
			std::cout << " ";
		}
		std::cout << subroot->val() << "\n";

		printhelp(subroot->right(),level+1);
	}
};