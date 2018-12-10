#include <iostream>
#include "String.class.h"
#include <string>

int main(){
	String str("Hello, ");
	char add[] = "world!";
	//std::string a("hello, ");
	//std::string b("World!");
	//std::cout << b.compare(a) << std::endl;
	// String c = str.append(static_cast<size_t>(10), '!');
	// std::cout << str << std::endl;
	// std::cout << b << std::endl;
	// std::cout << c << std::endl;
	// //std::cout << str << std::endl;
	String sa("Hello world!");
	String sb("b");
	String saa("a");

	std::string a("Hello world!");
	std::string b("b");
	std::string aa("a");
	std::cout << a.compare(6,5,add) << std::endl;
	std::cout << b.compare(a) << std::endl;
	std::cout << a.compare(aa) << std::endl;
	std::cout << "My  implementation" << std::endl;
	std::cout << sa.compare(6, 5, add) << std::endl;
	std::cout << sb.compare(sa) << std::endl;
	std::cout << sa.compare(saa) << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::string tt1("Hello world!");
	std::string tt2("world is big");
	std::cout << tt1.compare(6, 5, add,6) <<std::endl;
	std::cout << "My  implementation" << std::endl;
	String stt1("Hello world!");
	String stt2("world is big");
	std::cout << stt1.compare(6, 5, add, 6) <<std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::string pa("a");
	std::string pb("b");
	std::cout << pa << std::endl;
	std::cout << pb << std::endl;
	pa.swap(pb);
	std::cout << pa << std::endl;
	std::cout << pb << std::endl;

	String psa("a");
	String psb("b");
	std::cout << psa << std::endl;
	std::cout << psb << std::endl;
	psa.swap(psb);
	std::cout << psa << std::endl;
	std::cout << psb << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::string nul;
	std::cout << nul << std::endl;
	return 0;

}