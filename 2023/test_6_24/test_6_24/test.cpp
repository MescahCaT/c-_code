#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

// using namespace std;

namespace use_one
{
	int a = 0;
	double b = 0;
	std::string str;

	struct stu
	{
		std::string name;
		int age;
		double weigh;
	};
}

int main()
{

	//use_one::a = 100;
	//cout << use_one::a << endl;
	//struct use_one::stu a;
	//a.age = 20;
	//a.name = "xiaoming";
	//a.weigh = 123.55;

	//cout<<"____________________________________________________"<<"\n";
	//cout << use_one::a << endl;
	//cout << a.age << ',' << a.name << ',' << a.weigh << endl;
	//printf("----------------------------------------------------------------\n");

	//printf("use_one::a = %d\n", use_one::a);
	//printf("a's age = %d\na'name = %s\na'weight = %lf", a.age, a.name, a.weigh);


	//printf("hello world\n");
	//cout << "hello world" << endl;

	//int a = 0;
	//double b = 0;
	//std::string str;

	//scanf("%d %lf", &a , &b);

	//printf("a:%d b:%lf\n",a, b);
	//cout << "a:" << a << ' ' << "b:" << b << endl;

	use_one::a = 10;
	use_one::b = 0.99;
	use_one::str = "¼°ÄãÌ«ÃÀ";

	std::cout << "a:" << use_one::a << std::endl << "b:" << use_one::b << std::endl << "str:" << use_one::str << std::endl;


	return 0;

}