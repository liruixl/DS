
#include <iostream>
#include "ds/AList.h"
#include "ds/LList.h"
#include "ds/DLList.h"
#include "dict/SALdict.h"

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

	dict.find(12, lirui);

	std::cout << lirui.getAge() << std::endl;

}

int main()
{
	testSAList();
}
