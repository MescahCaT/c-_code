#define _CRT_SECURE_NO_WARNINGS 1
#include"日期类的实现.h"

// 当天的日期打印
void Date::print()
{
	cout << _year << "." << _month << "." << _day << endl;
}

inline bool IsLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int Date::GetMonthDay(int year, int month)
{
	int monthArr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && IsLeapYear(year))
	{
		return 29;
	}
	return monthArr[month];
}

// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
	Date::_year = year;
	Date::_month = month;
	Date::_day = day;
}

// 拷贝构造函数
// d2(d1)
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

// 析构函数
Date::~Date()
{
	Date::_year = 1900;
	Date::_month = 1;
	Date::_day = 1;
}

// 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(Date& d)
{
	d._year = _year;
	d._month = _month;
	d._day = _day;

	return d;
}

// 日期+天数
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13)
		{
			tmp._month = 1;
			tmp._year += 1;
		}
	}

	return tmp;
}


// 日期+=天数
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year += 1;
		}
	}
	return *this;
}

// 日期-天数
Date Date::operator-(int day)
{
	Date ret = *this;

	while (day)
	{
		if (day > ret._day)
		{
			day -= ret._day;
			ret._month -= 1;
			ret._day = GetMonthDay(ret._year,ret._month);
			if (ret._month == 0)
			{
				ret._month = 12;
				ret._year--;
				ret._day = 31;
			}
			continue;
		}
		else
		{
			ret._day -= day;
			break;
		}
	}

	//int count = ret._day;
	//// 统计出该年过了几天
	//for (int tmp_mouth = ret._month - 1; tmp_mouth > 0; tmp_mouth--)
	//{
	//	count += GetMonthDay(ret._year, tmp_mouth);
	//}

	//
	//if (day > count)
	//{
	//	day -= count;
	//	ret._day = 31;
	//	ret._month = 12;
	//	ret._year -= 1;
	//}

	//bool flag = IsLeapYear(ret._year);
	//while (day > (flag ? 366 : 365))
	//{
	//	if (flag)
	//	{
	//		day -= 366;
	//	}
	//	else
	//	{
	//		day -= 365;
	//	}
	//	ret._year -= 1;
	//	flag = IsLeapYear(ret._year);
	//}

	//while (day > 0)
	//{
	//}

	return ret;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	while (day)
	{
		if (day > this->_day)
		{
			day -= this->_day;
			this->_month -= 1;
			this->_day = GetMonthDay(this->_year, this->_month);
			if (this->_month == 0)
			{
				this->_month = 12;
				this->_year--;
				this->_day = 31;
			}
			continue;
		}
		else
		{
			this->_day -= day;
			break;
		}
	}
	return *this;
}

// 前置++
Date& Date::operator++()
{
	return *this += 1;
}

// 后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp + 1;
}

// 后置--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp - 1;
}

// 前置--
Date& Date::operator--()
{
	return *this -= 1;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	if (this->_year > d._year)
		return true;
	else if (this->_year == d._year && this->_month > d._month)
		return true;
	else if (this->_year == d._year && this->_month == d._month && this->_day > d._day)
		return true;
	return false;
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	return this->_year == d._year && this->_month == d._month && this->_day == d._day;
}

// >=运算符重载
bool Date::operator >= (const Date& d)
{
	return (*this > d) || (*this == d);
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// <运算符重载
bool Date::operator < (const Date& d)
{
	return(!(*this > d) && (*this != d));
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return ((*this < d) && (*this == d));
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	int ret = 0;
	Date Later = *this;
	Date Early = d;
	if (*this < d)
	{
		Date Later(d);
		Date Early(*this);
	}

	while (Later != Early)
	{
		Later--;
		ret++;
	}
	return ret;
}
