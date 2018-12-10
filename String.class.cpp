#include "String.class.h"

String::String():_str(new char())
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



int String::compare (const char* s) const {
	return strcmp(_str, s);
}

int String::compare (const String& str) const noexcept {
	return compare(str._str);
}

int String::compare (size_t pos, size_t len, const char* s) const {
	if (s == nullptr){
		throw std::invalid_argument("compare nullptr argument");
	}
	char *tmp = new char[len + 1]();
	memcpy(tmp, _str + pos, len);
	int cmp_res = strcmp(tmp, s);
	delete [] tmp;
	return cmp_res;
	
}

int String::compare (size_t pos, size_t len, const String& str) const{
	return compare(pos, len, str._str);
}

int String::compare (size_t pos, size_t len, const String& str,
             size_t subpos, size_t sublen) const {
	char *tmp = new char[sublen + 1]();
	memcpy(tmp, str._str + subpos, sublen);
	int cmp_res = compare(pos, len, tmp);
	delete [] tmp;
	return cmp_res;
}

int String::compare (size_t pos, size_t len, const char* s, size_t n) const {
	char *tmp = new char[n + 1]();
	memcpy(tmp, s, n);
	std::cout << tmp << std::endl;
	int cmp_res = compare(pos, len, tmp);
	delete [] tmp;
	return cmp_res;
}

void String::swap (String& str){
	char * tmp_ptr = _str;
	_str = str._str;
	str._str = tmp_ptr;

}

void String::clear() noexcept{
	if (_str != nullptr){
		delete [] _str;
		_str = new char();
	}
}

std::ostream & operator<<(std::ostream &os, const String &str){
	os << str.getString();
	return os;
}