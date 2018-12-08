#include <iostream>
#include <cstring>

class String
{
public:
	String(): _str(nullptr)
	{}
	String(const char *str): _str(nullptr)
	{
		if (str != nullptr) {
			std::size_t len = strlen(str);
			_str = new char[len + 1];
			memset(_str, 0, len + 1);
			memcpy(_str, str, len);
		}
		else {
			throw std::invalid_argument("error");
		}
	}
	virtual ~String()
	{
		if (_str != nullptr) {
			delete [] _str;
			_str = nullptr;
		}
	}



private:
	char *_str;
};