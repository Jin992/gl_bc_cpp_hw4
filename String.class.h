#include <iostream>
#include <cstring>

class String
{
public:
	String();
	String(const char *str);
	String(const String &other);
	virtual ~String();

	char *getString() const;
	size_t length() const;
	String & append(const String &str);
	String & append(const String& str, size_t subpos, size_t sublen);
	String & append(const char* s);
	String & append(const char* s, size_t n);
	String & append(size_t n, char c);


private:
	char *_str;
};

std::ostream & operator<<(std::ostream &os, const String &str);