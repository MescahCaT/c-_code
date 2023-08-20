#pragma once


using std::ostream;
using std::istream;

namespace WZN
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const WZN::string& s);
        friend istream& operator>>(istream& _cin, WZN::string& s);

    public:
        typedef char* iterator;

        // 构造函数
        string(const char* str = "")
            :_capacity(strlen(str))
            , _size(_capacity)
        {
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        // 拷贝构造
        string(const string& s)
        {
            _capacity = s.capacity();
            _size = s.size();
            _str = new char[_capacity + 1];
            strcpy(_str, s.c_str());
        }

        void swap(string s1 , string s2)
        {
            std::swap(s1._str, s2._str);
            std::swap(s1._size, s2._size);
            std::swap(s1._capacity, s2._capacity);
        }

        // 赋值重载
        string& operator=(const string& s)
        {
            if (&s != this)
            {
                string tmp(s);

                swap(*this, tmp);
            }

        }

        // 析构函数
        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _capacity = _size = 0;
        }

        //////////////////////////////////////////////////////////////

        // iterator
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }


        // modify

        void push_back(char c)
        {
            if (_capacity == _size)
            {
                _capacity = _capacity == 0 ? 4 : 2 * _capacity;
                reserve(_capacity);
            }

            _str[_size] = c;
            _size++;
            _str[_size] = '\0';
        }

        string& operator+=(char c)
        {
            push_back(c);
            return *this;
        }


        void append(const char* str)
        {
            size_t length = strlen(str);
            if (_capacity <= _size + length)
            {
                _capacity = _capacity + length;
                reserve(_capacity);
            }
            
            while (_size < _capacity)
            {
                _str[_size++] = *(str++);
            }
            _str[_capacity] = '\0';
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }


        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }
        void swap(string& s)
        {
            _size = s._size;
            _capacity = s._capacity;
            char* tmp = s._str;
            s._str = _str;
            _str = tmp;
        }
        const char* c_str()const
        {
            return _str;
        }



        /////////////////////////////////////////////////////////////
        // capacity
        size_t size()const
        {
            return _size;
        }
        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0')
        {
            if (n <= _size)
            {
                _str[n] = '\0';
                _size = n;
            }
            else
            {
                reserve(n);
                size_t end = n;
                while (_size < end)
                {
                    _str[_size++] = c;
                }
                _str[_size] = '\0';
            }
        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                _capacity = n;
                char* tmp = new char[_capacity + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
            }
        }

        /////////////////////////////////////////////////////////////
        // access

        char& operator[](size_t index)
        {
            assert(index < _size);
            return this->_str[index];

        }
        const char& operator[](size_t index)const
        {
            assert(index < _size);
            return this->_str[index];
        }

        /////////////////////////////////////////////////////////////
        //relational operators

        bool operator<(const string& s)
        {
            return strcmp(_str,s.c_str()) == -1;
        }
        bool operator<=(const string& s)
        {
            return strcmp(_str, s.c_str()) == 0 || strcmp(_str,s.c_str()) == -1;

        }
        bool operator>(const string& s)
        {
            return !(*this <= s);
        }
        bool operator>=(const string& s)
        {
            return !(*this < s);
        }
        bool operator==(const string& s)
        {
            return strcmp(_str, s.c_str()) == 0;
        }
        bool operator!=(const string& s)
        {
            return strcmp(_str, s.c_str());
        }

        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const
        {
            assert(pos < _size);

            size_t i = pos;
            while (i < _size)
            {
                if (_str[i] == c)
                    return i;
                i++;
            }
            return -1;
        }

        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const
        {
            assert(pos < _size);

            const char* point = strstr(this->_str + pos, s);
            if(point != nullptr)
                return find(*point, pos);
            return -1;
        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c)
        {
            assert(pos <= _size);
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }

            size_t end = _size + 1;
            while (end > pos)
            {
                _str[end] = _str[end - 1];
                end--;
            }
            _str[pos] = c;
            _size++;
            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);

            size_t len = strlen(str);
            if (_capacity < _size + len)
            {
                reserve(_capacity + len);
            }

            size_t end = _size + len;
            while (end > pos) 
            {
                _str[end] = _str[end - len];
                end--;
            }
            for (size_t i = 0; i < len; i++)
            {
                _str[pos++] = str[i];
            }
            _size += len;

            return *this;
        }

        string& insert(size_t pos, const string str)
        {
            assert(pos <= _size);

            insert(pos, str.c_str());
            return *this;
        }


        // 删除pos位置上的元素，并返回字符串
        string& erase(size_t pos, size_t len)
        {
            assert(pos < _size);
            assert(pos + len < _size);
            
            size_t begin = pos + len;
            while (begin <= _size + 1)
            {
                _str[begin - len] = _str[begin];
                begin++;
            }
            return *this;
        }

    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };

};