#pragma once
#include <string>
#include <iostream>
class Person
{
public:
	Person(){}
	~Person(){}
	
	int getAge() const { return age; }
	void setAge(int age) { this->age = age; }

	std::string getName() const { return name; }
	void setName(std::string name) { this->name = name; }

	bool operator<(const Person& rhs) const
	{
		return this->age < rhs.age;
	}


	//应该是重载cout的<<运算符吧
	/*std::ostream & operator << (std::ostream & os)
	{
		os << this->name << " : " << this->age << "; ";
		return os;
	}*/

	
private:
	int age;
	std::string name;
};

class AgeComp
{
public:
	static bool lt(const Person& lhs, const Person& rhs)
	{
		return lhs < rhs;
	}
	static bool eq(const Person& lhs, const Person& rhs)
	{
		return !(lhs < rhs) && !(rhs < lhs);
	}
	static bool gt(const Person& lhs, const Person& rhs)
	{
		return rhs < lhs;
	}
};

class NameComp
{
public:
	static bool lt(const Person& lhs, const Person& rhs)
	{
		return lhs.getName() < rhs.getName();
	}
	static bool eq(const Person& lhs, const Person& rhs)
	{
		return lhs.getName() == rhs.getName();
	}
	static bool gt(const Person& lhs, const Person& rhs)
	{
		lhs.getName() > rhs.getName();
	}
};

class KeyComp
{
public:
	static bool lt(int lhs, const Person& rhs)
	{
		return lhs < rhs.getAge();
	}
	static bool eq(int lhs, const Person& rhs)
	{
		return lhs == rhs.getAge();
	}
	static bool gt(int lhs, const Person& rhs)
	{
		return lhs > rhs.getAge();
	}
};