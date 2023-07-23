#define _CRT_SECURE_NO_WARNINGS 1
#include"日期类的实现.h"

// using namespace std;
using namespace std;


int main()
{
	// cout << "hello cplusplus" << endl;

	Date today(2023, 7, 23);
	Date Default(2022, 2, 22);
	cout << (today - Default) << endl;

	//today.print();
	//Default.print();

	//Default = today;
	//today.print();
	//Default.print();

	//today.operator=(Default);
	//today.print();
	//Default.print();

	//today += 200;
	//today.print();

	//Date tmp = today - 1800;
	//tmp.print();

	//today--;
	//today.print();

	return 0;
}

