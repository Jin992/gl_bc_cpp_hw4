#include "String.class.h"

String::String():_str(nullptr)
{}

String::String(const char *str): _str(nullptr) {
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

String::String(const String &other){
	if (other._str != nullptr) {
		_str = new char [other.length() + 1]();
		memcpy(_str, other._str, other.length());
	}
}

String::~String() {
	if (_str != nullptr) {
		delete [] _str;
		_str = nullptr;
	}
}

char* String::getString() const {
		return _str;
}

size_t String::length() const {
		return strlen(_str);
}

char *str_join(const char *str1, const char *str2, size_t len = 0) {
	if (str1 == nullptr || str2 == nullptr){
		return nullptr;
	}
	if (*str1 == '\0' && *str2 == '\0') {
		return new char();
	}
	size_t len_str1 = strlen(str1);
	if (len == 0) {
		len = strlen(str2);
	}
	char *res_str = new char [len_str1 + len + 1]();
	memcpy(res_str, str1, len_str1);
	memcpy(res_str + len_str1, str2, len);
	return res_str;
}

String & String::append(const char* s, size_t n) {
	char *tmp_buff = nullptr;

	tmp_buff = str_join(_str, s, n);
	if (tmp_buff == nullptr) {
			throw std::invalid_argument("Error: append string is nullptr");
	}
	delete [] _str;
	_str = tmp_buff;
	
	return *this;
}

String & String::append(const String &rhs) {
	return append(rhs._str, 0);
}

String & String::append(const String& rhs, size_t subpos, size_t sublen) {
	return append(rhs._str + subpos, sublen);
}

String & String::append(const char* s) {
	return append(s, 0);
}

String & String::append(size_t n, char c) {
	char *str = new char[n]();
	memset(str, c, n);
	String &tmp = append(str, 0);
	delete [] str;
	return tmp;
}

std::ostream & operator<<(std::ostream &os, const String &str){
	os << str.getString();
	return os;
}