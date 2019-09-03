
#include <iostream>
#include "ds/AList.h"
#include "ds/LList.h"
#include "ds/DLList.h"
#include "dict/SALdict.h"

#include "ds/AStack.h"
#include "ds/LStack.h"

#include "ds/AQueue.h"

#include "entity/Person.h"

void testAList()
{
	AList<int> myList(10);

	myList.insert(6);
	myList.insert(6);
	myList.insert(6);
	myList.insert(6);
	myList.setPos(4);
	myList.print();
}

void testLList()
{
	LList<int> myList;
	myList.insert(99);
	myList.insert(88);
	myList.insert(77);
	myList.insert(66);
	myList.insert(55);
	myList.insert(44);
	myList.append(1);
	myList.append(2);

	myList.setPos(3);
	myList.print();

	int b;
	myList.getValue(b);
	std::cout << b << std::endl;

	int a;
	myList.remove(a);
	std::cout << a << std::endl;

	myList.print();

	myList.getValue(b);
	std::cout << b << std::endl;

	myList.prev();
	myList.print();
	myList.next();
	myList.print();
}


void testDLList()
{
	DLList<int> myList;
	myList.insert(99);
	myList.insert(88);
	myList.insert(77);
	myList.insert(66);
	myList.insert(55);
	myList.insert(44);
	myList.append(1);
	myList.append(2);

	myList.setPos(3);
	myList.print();
	myList.printUpdown();

	int b;
	myList.getValue(b);
	std::cout << b << std::endl;

	int a;
	myList.remove(a);
	std::cout << a << std::endl;

	myList.print();
	myList.printUpdown();


	myList.getValue(b);
	std::cout << b << std::endl;

	myList.prev();
	myList.print();
	myList.next();
	myList.print();

	myList.printUpdown();
}

std::ostream & operator<<(std::ostream & os, const Person & p)
{
	os << p.getName() << " : " << p.getAge() << "; ";
	return os;
}


void testSAList()
{
	Person lirui;
	lirui.setName("lirui");
	SALDict<int,Person,KeyComp,AgeComp> dict(20);

	for (int i = 0; i < 20; ++i)
	{
		lirui.setAge(i);
		dict.insert(lirui);
	}

	dict.find(17, lirui);

	std::cout << lirui.getAge() << std::endl;

}

void testAStack()
{
	AStack<int> s(10);
	
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	std::cout << s.length() << std::endl;;
}

void testLStack()
{
	LStack<int> s(10);

	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	std::cout << s.length() << std::endl;

	int p;

	s.pop(p);
	std::cout << p << std::endl;

	s.pop(p);
	std::cout << p << std::endl;

	std::cout << s.length() << std::endl;

	s.clear();
	std::cout << s.length() << std::endl;

}

void testAQueue()
{
	AQueue<int> aq(5);
	std::cout << aq.size() << std::endl;

	aq.push(66);
	aq.print();
	aq.push(66);
	aq.print();
	aq.push(66);
	aq.print();
	aq.push(66);
	aq.print();
	aq.push(66);
	aq.print();
	aq.push(66);
	aq.print();
	aq.push(66);

}

int main()
{
	
	testAQueue();
}
