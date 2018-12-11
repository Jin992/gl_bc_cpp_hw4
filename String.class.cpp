#include "String.class.h"

static char *str_join(const char *str1, const char *str2, size_t len = 0) {
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

/* str_filler allocate memory, need to delete [] manualy, after usage*/
static char * str_filler(size_t n, char c){
	char *res = new char[n + 1]();
	memset(res, c, n);
	return res;
}


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

char* String::c_str() const {
		return _str;
}

void String::set_str(char *s){
	if (_str != nullptr) {
		delete [] _str;
		_str = nullptr;
	}
	_str = new char[strlen(s) + 1]();
	memcpy(_str, s, strlen(s));
}

size_t String::length() const {
		return strlen(_str);
}


String & String::append(const char* s, size_t n) {
	char *tmp_buff = nullptr;

	if (strlen(s) < n){
		n = strlen(s);
	}
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
	if (subpos > rhs.length()){
		throw std::out_of_range("position is to big");
	}
	return append(rhs._str + subpos, sublen);
}

String & String::append(const char* s) {
	return append(s, 0);
}

String & String::append(size_t n, char c) {
	char *str = str_filler(n, c);
	append(str);
	delete [] str;
	return *this;
}

int String::compare (const char* s) const {
	if (s == nullptr){
		throw std::invalid_argument("compare nullptr argument");
	}
	if (strlen(s) == length()){
		int cmp_res = strcmp(_str, s);
		if (cmp_res > 0){
			return 1;
		}
		else if (cmp_res < 0){
			return -1;
		}
		return 0;
	}
	return static_cast<int>(length()) - static_cast<int>(strlen(s));
}

int String::compare (const String& str) const {
	return compare(str._str);
}

int String::compare (size_t pos, size_t len, const char* s) const {
	if (s == nullptr){
		throw std::invalid_argument("compare nullptr argument");
	}
	if (pos > length()){
		throw std::out_of_range("position is to big");
	}
	if (pos + len > length()){
		len = length() - pos;
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

String& String::insert (size_t pos, const char* s){
	if (s == nullptr){
		throw std::invalid_argument("Error: insert nullptr as argument");
	}
	if (pos > length()){
		throw std::out_of_range("insert pos out of range");
	}
	char *before = new char[pos + 1]();
	char *after = new char[length() - pos + 1]();
	memcpy(before, _str, pos);
	memcpy(after, _str + pos, length() - pos);
	clear();
	if (pos != 0){
		append(before);	
	}
	append(s);
	append(after);
	delete [] before;
	delete [] after;
	return *this;
}

String& String::insert (size_t pos, const String& str){
	return insert(pos, str._str);
}

String& String::insert (size_t pos, const String& str, size_t subpos, size_t sublen){
	if (subpos > str.length()){
		throw std::out_of_range("insert pos out of range");
	}
	char *tmp = new char[sublen + 1]();
	memcpy(tmp, str._str + subpos, sublen);
	insert(pos, tmp);
	delete [] tmp;
	return *this;
}

String& String::insert (size_t pos,   size_t n, char c){
	char *str = str_filler(n, c);
	insert(pos, str);
	delete [] str;
	return *this;
}

String& String::insert (size_t pos, const char* s, size_t n){
	char *tmp = new char[n + 1]();
	memcpy(tmp, s, n);
	insert(pos, tmp);
	delete [] tmp;
	return *this;
}	

size_t String::substr (const char* s, size_t pos = 0) const{
	if (s == nullptr || pos > length()){
		throw std::invalid_argument("Error: substr nullptr as argument");
	}
	char *ptr = strstr(_str + pos, s);
	if (ptr == nullptr){
		return -1;
	}
	return ptr - _str;
}

size_t String::substr (const char* s, size_t pos, size_t n) const{
	if (s == nullptr){
		throw std::invalid_argument("Error: substr nullptr as argument");
	}
	char *tmp = new char[n + 1]();
	memcpy(tmp, s, n);
	size_t res = substr(tmp, pos);
	delete [] tmp;
	return  res;
}

size_t String::substr (char c, size_t pos = 0) const noexcept{
	char *ptr = strchr(_str, c);
	if (ptr == nullptr || pos > length()){
		return -1;
	}
	return ptr - _str;
}

size_t String::substr (const String& str, size_t pos = 0) const noexcept {
	return substr(str._str, pos);
}

void String::resize (size_t n){
	if (length() > n) {
		char *tmp = new char[n + 1]();
		memcpy(tmp, _str, n);
		delete [] _str;
		_str = tmp;
	}
}

void String::resize (size_t n, char c){
	if (length() > n){
		resize(n);
	}
	else if (length() < n){
		append(n - length(), c);
	}
}

String& String::operator=(const String& str){
	if (_str != nullptr){
		delete [] _str;
		_str = nullptr;
	}
	_str = new char[str.length() + 1]();
	memcpy(_str, str._str, str.length());
	return *this;
}

String& String::operator= (const char* s){
	if (_str != nullptr){
		delete [] _str;
		_str = nullptr;
	}
	_str = new char[strlen(s) + 1]();
	memcpy(_str, s, strlen(s));
	return *this;
}

String& String::operator=(char c){
	if (_str != nullptr){
		delete [] _str;
		_str = nullptr;
	}
	_str = new char[2]();
	_str[0] = c;
	return *this;
}

String& String::operator+=(const String& str){
	append(str);
	return *this;
}

String& String::operator+=(const char* s){
	append(s);
	return *this;
}

String& String::operator+=(char c){
	resize(length() + 1, c);
	return *this;
}

bool String::operator==(const String& str) {
	if (compare(str) == 0){
		return true;
	}
	return false;
}

bool String::operator!=(const String& str){
	if (compare(str) == 0){
		return false;
	}
	return true;
}

String operator+(const String& lhs, const String& rhs){
	String res;
	res.append(lhs);
	res.append(rhs);
	return res;
}

String operator+(const String& lhs, const char*   rhs){
	String res;
	res.append(lhs);
	res.append(rhs);
	return res;
}

String operator+(const char*   lhs, const String& rhs){
	String res;
	res.append(lhs);
	res.append(rhs);
	return res;
}

String operator+(const String& lhs, char          rhs){
	String res;
	res.append(lhs);
	res.resize(res.length() + 1, rhs);
	return res;
}

String operator+(char          lhs, const String& rhs){
	String res;
	res.resize(res.length() + 1, lhs);
	res.append(rhs);
	return res;
}

std::ostream & operator<<(std::ostream &os, const String &str){
	os << str.c_str();
	return os;
}

std::istream & operator>>(std::istream& is, String& str){
	char tmp[6000] = {0};

	is >> tmp;
	str.set_str(tmp);
	return is;
}