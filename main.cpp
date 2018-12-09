#include <iostream>
#include "String.class.h"
#include <string>

int main(){
	String str("Hello, ");
	char add[] = "World!";
	//std::string a("hello, ");
	String b("World!");
	String c = str.append(static_cast<size_t>(10), '!');
	std::cout << str << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	//std::cout << str << std::endl;
	return 0;

}