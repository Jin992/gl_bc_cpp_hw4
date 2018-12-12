#ifndef STRING_JIN_H
#define STRING_JIN_H
#include <iostream>

class String
{
public:
	String();
	String(const char *str);
	String(const String &other);
	virtual ~String();

	const char *c_str() const;
	void set_str(char *);
	size_t length() const;
	String & append(const String &str);
	String & append(const String& str, size_t subpos, size_t sublen);
	String & append(const char* s);
	String & append(const char* s, size_t n);
	String & append(size_t n, char c);

	int compare (const String& str) const;
	int compare (size_t pos, size_t len, const String& str) const;
	int compare (size_t pos, size_t len, const String& str,
			 size_t subpos, size_t sublen) const;
	int compare (const char* s) const;
	int compare (size_t pos, size_t len, const char* s) const;
	int compare (size_t pos, size_t len, const char* s, size_t n) const;

	String& insert (size_t pos, const String& str);
	String& insert (size_t pos, const String& str, size_t subpos, size_t sublen);
	String& insert (size_t pos, const char* s);
	String& insert (size_t pos, const char* s, size_t n);	
	String& insert (size_t pos,   size_t n, char c);

	size_t substr (const String& str, size_t pos) const noexcept;	
	size_t substr (const char* s, size_t pos) const;
	size_t substr (const char* s, size_t pos, size_t n) const;
	size_t substr (char c, size_t pos) const noexcept;

	void resize (size_t n);
	void resize (size_t n, char c);

	void swap (String& str);
	void clear() noexcept;

	String& operator=(const String& str);
	String& operator=(const char* s);
	String& operator=(char c);

	String& operator+=(const String& str);	
	String& operator+=(const char* s);	
	String& operator+=(char c);

	bool operator==(const String& str);
	bool operator!=(const String& str);


private:
	char *_str;
};

String operator+(const String& lhs, const String& rhs);
String operator+(const String& lhs, const char*   rhs);
String operator+(const char*   lhs, const String& rhs);
String operator+ (const String& lhs, char          rhs);
String operator+ (char          lhs, const String& rhs);
std::ostream & operator<<(std::ostream &os, const String &str);
std::istream & operator>>(std::istream& is, String& str);

#endif