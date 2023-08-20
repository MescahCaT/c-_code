#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"string.h"

using std::cout;
using std::endl;

int main()
{
	string s1("hello world");

	cout << s1.c_str() << endl;

	string s2(s1);
	cout << s2.c_str() << endl;

	string s3;
	s3 = s2;
	cout << s3.c_str() << endl;



	return 0;
}