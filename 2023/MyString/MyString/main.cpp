#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include"MyString.h"

using WZN::string;
using std::cout;
using std::endl;

void my_stringTEXT1()
{
	string s1;
	s1.push_back('1');
	s1.push_back('2');
	s1.push_back('3');
	s1.push_back('4');
	s1.push_back('5');

	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *(it++);
	}
	cout << endl;
}

void my_stringTEXT2()
{
	string s1;
	s1 += '0';
	s1 += '1';
	s1 += '2';
	s1 += '3';
	s1 += '4';
	s1 += '5';

	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *(it++);
	}
	cout << endl;

	s1.append("123456");
	cout << s1.c_str() << endl;

	s1 += "xxxxxx";
	cout << s1.c_str() << endl;

}


void my_stringTEXT3()
{
	
	string s("hello world");

	cout << s.capacity() << endl;
	cout << s.size() << endl;
	//s.insert(10, "xxx");

	string s1("¼¦Äã");
	string s2("Ì«ÃÀ");
	cout << s.c_str() << endl;

	//s.insert(0, s2);
	//s.insert(0, s1);


	s.erase(0, 15);
	cout << s.c_str() << endl;
	//cout << s.capacity() << endl;
	//cout << s.c_str() << endl;
}

void my_stringTEXT4()
{
	string s1("123");
	string ss1("111");
	string s2("124");
	string ss2("1111");

	if (s1 > s2)
		cout << "s1 > s2" << endl;
	else if (s1 < s2)
		cout << "s2 < s1" << endl;

	if (s1 > ss2)
		cout << "s1 > ss2" << endl;
	else if (s1 < ss2)
		cout << "ss2 < s1" << endl;

	if (s1 == ss1)
		cout << "ss1 == s1" << endl;
	else
		cout << "ss1 != s1" << endl;
}

int main()
{

	my_stringTEXT4();
	
	return 0;
}