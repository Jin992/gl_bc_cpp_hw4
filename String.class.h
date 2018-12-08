#include <iostream>
#include <cstring>

class String
{
public:
	String();
	String(const char *str);
	virtual ~String();

	char *getString() const;

private:
	char *_str;
};

std::ostream & operator<<(std::ostream &os, const String &str);