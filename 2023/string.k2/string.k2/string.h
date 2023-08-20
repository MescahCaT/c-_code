#pragma once


class string
{
public:
	string(const char* str = "")
		:_capacity(strlen(str))
		,_size(_capacity)
	{
		size_t len = strlen(str);
		_str = new char[len + 1];
		memcpy(_str, str, len);

		_str[_size] = '\0';
	}

	string(const string& s)
	{
		_capacity = s._capacity;
		_size = s._size;

		_str = new char[_capacity + 1];
		memcpy(_str, s._str, s._size);
		_str[_size] = '\0';
	}

	string& operator=(const string& s)
	{
		_capacity = s._capacity;
		_size = s._size;

		_str = new char[_capacity + 1];
		memcpy(_str, s._str, s._size);
		_str[_size] = '\0';
		return *this;
	}
	
	~string()
	{
		delete[] _str;
		_str = nullptr;

		_capacity = _size = 0;
	}

	char* c_str()
	{
		return _str;
	}

private:
	char* _str;
	size_t _capacity;
	size_t _size;
};