#include "String.class.h"
#include <iostream>
#include <string>
#include <cstring>

namespace {
	void test_case(const char *test_name, const char *test_case, const char *str1, const char *str2){
		std::cout << "Test name: " << test_name << " ";
		if (strcmp(str1, str2) == 0){
			std::cout << "\033[1;32m[OK]\033[0m" << std::endl;
		}
		else
		{
			std::cout << "\033[1;31m[KO]\033[0m" << std::endl;
		}
		std::cout << "Test case: " << test_case << std::endl;
		std::cout << "Result:" << std::endl;
		std::cout << "\033[1;33mstd::string :" << str1 << "\033[0m" << std::endl;
		std::cout << "\033[1;33mString class:" << str2 << "\033[0m" << std::endl;
		std::cout << "-----------------------------------------" << std::endl << std::endl;
	}

	void test_case(const char *test_name, const char *test_case, int cmp1, int cmp2){
		std::cout << "Test name: " << test_name << " ";
		if (cmp1 == cmp2){
			std::cout << "\033[1;32m[OK]\033[0m" << std::endl;
		}
		else
		{
			std::cout << "\033[1;31m[KO]\033[0m" << std::endl;
		}
		std::cout << "Test case: " << test_case << std::endl;
		std::cout << "Result:" << std::endl;
		std::cout << "\033[1;33mstd::string :" << cmp1 << "\033[0m" << std::endl;
		std::cout << "\033[1;33mString class:" << cmp2 << "\033[0m" << std::endl;
		std::cout << "-----------------------------------------" << std::endl << std::endl;
	}
}

int main(){
	/* Test construtor */
	std::cout << "--------------- String test -------------" << std::endl << std::endl;

	std::string t0_empty;
	String t0_Empty;
	test_case("Constructor test: ", "String();", t0_empty.c_str(), t0_Empty.c_str());
	
	std::string t0_str("Constructor");
	String t0_Str("Constructor");
	test_case("Constructor test: ", "String(const char *str);", t0_str.c_str(), t0_Str.c_str());

	std::string t0_copy(t0_str);
	String t0_Copy(t0_Str);
	test_case("Constructor test: ", "String(const String &other);", t0_copy.c_str(), t0_Copy.c_str());
	/* Test construtor end*/

	/* Test append */
	// Test #1
	std::string t1_str("test of ");
	std::string t1_append("append");
	String t1_Str("test of ");
	String t1_Append("append");

	t1_str.append(t1_append);
	t1_Str.append(t1_Append);
	test_case("Append method test: #1", "append(const String &str);",
										 t1_str.c_str(), t1_Str.c_str());
	
	// Test #2
	std::string sub_str("Hello");
	String sub_Str("Hello");
	t1_str.append(sub_str, 1, 3);
	std::cout << t1_str << std::endl;
	t1_Str.append(sub_Str, 1, 3);
	test_case("Append method test: #2", "append(const String& str, size_t subpos, size_t sublen);",
										 t1_str.c_str(), t1_Str.c_str());
	
	// Test #3
	char c_array[] = "char *";
	t1_str.append(c_array);
	t1_Str.append(c_array);
	test_case("Append method test: #3", "append(const char* s);",
									 t1_str.c_str(), t1_Str.c_str());
	
	// Test #4
	char c_buff[5];
	memcpy(c_buff, c_array, 5);
	t1_str.append(c_buff, 5);
	t1_Str.append(c_buff, 5);
	test_case("Append method test: #4", "append(const char* s, size_t n);",
										 t1_str.c_str(), t1_Str.c_str());
	
	// Test #5
	t1_str.append(10, '+');
	t1_Str.append(10, '+');
	test_case("Append method test: #5", "append(size_t n, char c);",
										 t1_str.c_str(), t1_Str.c_str());
	/* Test append end*/

	/* Test compare */
	
	// Test #1
	std::string t2_str("Compare method test");
	std::string t2_cmp1("Compare method test");
	std::string t2_cmp2("Compare method tes");
	std::string t2_cmp3("Compare method test   0");

	String t2_Str("Compare method test");
	String t2_Cmp1("Compare method test");
	String t2_Cmp2("Compare method tes");
	String t2_Cmp3("Compare method test   0");

	test_case("Compare method test: #1", "compare (const String& str) const noexcept;",
										 t2_str.compare(t2_cmp1), t2_Str.compare(t2_Cmp1));
	test_case("Compare method test: #1", "compare (const String& str) const noexcept;",
										 t2_str.compare(t2_cmp2), t2_Str.compare(t2_Cmp2));
	test_case("Compare method test: #1", "compare (const String& str) const noexcept;",
										 t2_str.compare(t2_cmp3), t2_Str.compare(t2_Cmp3));
	
	// Test #2
	std::string t2_2_str("Compare method test");
	std::string t2_2_cmp1("method");

	String t2_2_Str("Compare method test");
	String t2_2_Cmp1("method");

	test_case("Compare method test: #2", "compare (size_t pos, size_t len, const String& str) const;",
										 t2_2_str.compare(9, 6, t2_2_cmp1),
										 t2_2_Str.compare(9, 6, t2_2_Cmp1));
	test_case("Compare method test: #2", "compare (size_t pos, size_t len, const String& str) const;",
										 t2_2_str.compare(8, 6, t2_2_cmp1),
										 t2_2_Str.compare(8, 6, t2_2_Cmp1));
	test_case("Compare method test: #2", "compare (size_t pos, size_t len, const String& str) const;",
										 t2_2_str.compare(10, 6, t2_2_cmp1),
										 t2_2_Str.compare(10, 6, t2_2_Cmp1));

	// Test #3
	std::string t2_3_str("Compare method test");
	std::string t2_3_cmp1("Compare method test");

	String t2_3_Str("Compare method test");
	String t2_3_Cmp1("Compare method test");
	test_case("Compare method test: #3", "int compare (size_t pos, size_t len, const String& str, size_t subpos, size_t sublen) const;",
										 t2_3_str.compare(8, 6, t2_3_cmp1, 8, 6),
										 t2_3_Str.compare(8, 6, t2_3_Cmp1, 8, 6));

	test_case("Compare method test: #3", "int compare (size_t pos, size_t len, const String& str, size_t subpos, size_t sublen) const;",
										 t2_3_str.compare(9, 6, t2_3_cmp1, 8, 6),
										 t2_3_Str.compare(9, 6, t2_3_Cmp1, 8, 6));

	test_case("Compare method test: #3", "int compare (size_t pos, size_t len, const String& str, size_t subpos, size_t sublen) const;",
										 t2_3_str.compare(10, 6, t2_3_cmp1, 8, 6),
										 t2_3_Str.compare(10, 6, t2_3_Cmp1, 8, 6));

	test_case("Compare method test: #3", "int compare (size_t pos, size_t len, const String& str, size_t subpos, size_t sublen) const;",
										 t2_3_str.compare(8, 6, t2_3_cmp1, 8, 6),
										 t2_3_Str.compare(8, 6, t2_3_Cmp1, 8, 6));

	test_case("Compare method test: #3", "int compare (size_t pos, size_t len, const String& str, size_t subpos, size_t sublen) const;",
										 t2_3_str.compare(8, 6, t2_3_cmp1, 9, 6),
										 t2_3_Str.compare(8, 6, t2_3_Cmp1, 9, 6));

	test_case("Compare method test: #3", "int compare (size_t pos, size_t len, const String& str, size_t subpos, size_t sublen) const;",
										 t2_3_str.compare(8, 6, t2_3_cmp1, 10, 6),
										 t2_3_Str.compare(8, 6, t2_3_Cmp1, 10, 6));


	// Test #4
	std::string t2_4_str("Compare method test");
	String t2_4_Str("Compare method test");
	char t2_char_array1[] = "Compare method test";
	char t2_char_array2[] = "Compare method";
	char t2_char_array3[] = "Compare method test 2";
	test_case("Compare method test: #4", "compare (const char* s) const;",
										 t2_4_str.compare(t2_char_array1),
										 t2_4_Str.compare(t2_char_array1));

	test_case("Compare method test: #4", "compare (const char* s) const;",
										 t2_4_str.compare(t2_char_array2),
										 t2_4_Str.compare(t2_char_array2));

	test_case("Compare method test: #4", "compare (const char* s) const;",
										 t2_4_str.compare(t2_char_array3),
										 t2_4_Str.compare(t2_char_array3));

	// Test #5
	std::string t2_5_str("Compare method test");
	char t2_5_cmp1[] ="method";

	String t2_5_Str("Compare method test");
	char t2_5_Cmp1[] = "method";

	test_case("Compare method test: #5", "compare (size_t pos, size_t len, const char* s) const;",
										 t2_5_str.compare(9, 6, t2_5_cmp1),
										 t2_5_Str.compare(9, 6, t2_5_Cmp1));
	test_case("Compare method test: #5", "compare (size_t pos, size_t len, const char* s) const;",
										 t2_5_str.compare(8, 6, t2_5_cmp1),
										 t2_5_Str.compare(8, 6, t2_5_Cmp1));
	test_case("Compare method test: #5", "compare (size_t pos, size_t len, const char* s) const;",
										 t2_5_str.compare(10, 6, t2_5_cmp1),
										 t2_5_Str.compare(10, 6, t2_5_Cmp1));

	// Test #6
	char t2_6_arr[] = "array one";
	char t2_c_buff[5];
	memcpy(t2_c_buff, t2_6_arr, 5);
	std::string t2_6_str("this is array");
	String t2_6_Str("this is array");

	test_case("Compare method test:#6: ", "compare (size_t pos, size_t len, const char* s, size_t n) const;",
										 t2_6_str.compare(8, 5, t2_c_buff, 5),
										 t2_6_Str.compare(8, 5, t2_c_buff, 5));
	test_case("Compare method test:#6", "compare (size_t pos, size_t len, const char* s, size_t n) const;",
										 t2_6_str.compare(1, 6, t2_c_buff, 5),
										 t2_6_Str.compare(1, 6, t2_c_buff, 5));
	test_case("Compare method test:#6", "compare (size_t pos, size_t len, const char* s, size_t n) const;",
										 t2_6_str.compare(0, 5, t2_c_buff, 5),
										 t2_6_Str.compare(0, 5, t2_c_buff, 5));

	/* Test compare end*/

	/* Test insert */
	
	// Test #1
	std::string t3_1_str("aaaaa");
	String t3_1_Str("aaaaa");

	t3_1_str.insert(4, "bbbb");
	t3_1_Str.insert(4, "bbbb");
	test_case("Insert method test: #1", "insert (size_t pos, const char* s);",
										 t3_1_str.c_str(), t3_1_Str.c_str());

	// Test #2
	std::string t3_2_str("aaaaa");
	std::string t3_2_insert("bbb");
	String t3_2_Str("aaaaa");
	String t3_2_Insert("bbb");

	t3_2_str.insert(4, t3_2_insert);
	t3_2_Str.insert(4, t3_2_Insert);
	test_case("Insert method test: #2", "insert (size_t pos, const String& str);",
											t3_2_str.c_str(), t3_2_Str.c_str());

	// Test #3
	std::string t3_3_insert("aaabbcccc");
	String t3_3_Insert("aaabbcccc");
	t3_2_str.insert(7, t3_3_insert, 6,3);
	t3_2_Str.insert(7, t3_3_Insert, 6,3);
	test_case("Insert method test: #3 ", "insert (size_t pos, const String& str, size_t subpos, size_t sublen);",
											t3_2_str.c_str(), t3_2_Str.c_str());

	// Test #4
	
	t3_2_str.insert(9, "zzzzz", 3);
	t3_2_Str.insert(9, "zzzzz", 3);
	test_case("Insert method test: #4 ", "insert (size_t pos, const String& str, size_t subpos, size_t sublen);",
											t3_2_str.c_str(), t3_2_Str.c_str());

	// Test #5
	t3_2_str.insert(10, 10, '!');
	t3_2_Str.insert(10, 10, '!');
	test_case("Insert method test: #5 ", "insert (size_t pos,   size_t n, char c);",
											t3_2_str.c_str(), t3_2_Str.c_str());

	/* Test insert end */

	/* Test substr */
	// Test #1
	std::string t4_1_str("This is string to test strsub");
	std::string t4_1_sub("is");
	String t4_1_Str("This is string to test strsub");
	String t4_1_Sub("is");

	test_case("Substr (find) method test:#1 - 1", "substr (const String& str, size_t pos) const noexcept;",
										 t4_1_str.find(t4_1_sub, 0),
										 t4_1_Str.substr(t4_1_Sub, 0));
	std::string t4_1_2_sub("test");
	String t4_1_2_Sub("test");
	test_case("Substr (find) method test:#1 - 2", "substr (const String& str, size_t pos) const noexcept;",
										 t4_1_str.find(t4_1_2_sub,0),
										 t4_1_Str.substr(t4_1_2_Sub, 0));

	// Test #2
	test_case("Substr (find) method test:#2 - 1", "substr (const char* s, size_t pos) const;",
										 t4_1_str.find("string",0),
										 t4_1_Str.substr("string", 0));
	test_case("Substr (find) method test:#2 - 2", "substr (const char* s, size_t pos) const;",
										 t4_1_str.find("to",10),
										 t4_1_Str.substr("to", 10));

	// Test #3
	test_case("Substr (find) method test:#3", "substr (const char* s, size_t pos, size_t n) const;",
										 t4_1_str.find("is this",0, 2),
										 t4_1_Str.substr("is this", 0, 2));

	// Test #4
	test_case("Substr (find) method test:#4 - 1", "substr (char c, size_t pos) const noexcept",
										 t4_1_str.find('T',0),
										 t4_1_Str.substr('T', 0));
	test_case("Substr (find) method test:#4 - 2", "substr (char c, size_t pos) const noexcept",
										 t4_1_str.find('z',0),
										 t4_1_Str.substr('z', 0));
	/* Test substr end */

	/* Test resize*/

	// Test #1
	std::string t5_1_str("1234567890");
	String t5_1_Str("1234567890");

	t5_1_str.resize(5);
	t5_1_Str.resize(5);
	test_case("Resize #1 - 1 ", "resize (size_t n);",
					t5_1_str.c_str(), t5_1_Str.c_str());
	t5_1_str.resize(10);
	t5_1_Str.resize(10);
	test_case("Resize #1 - 2 ", "resize (size_t n);",
					t5_1_str.c_str(), t5_1_Str.c_str());

	// Test #2
	std::string t5_2_str("1234567890");
	String t5_2_Str("1234567890");

	t5_2_str.resize(5, '+');
	t5_2_Str.resize(5, '+');
	test_case("Resize method test #2 - 1 ", "resize (size_t n, char c);",
					t5_2_str.c_str(), t5_2_Str.c_str());
	t5_2_str.resize(10, '+');
	t5_2_Str.resize(10, '+');
	test_case("Resize method test  #2 - 2 ", "resize (size_t n, char c);",
					t5_2_str.c_str(), t5_2_Str.c_str());

	/* Test resize end*/

	/* Test swap */
	std::string t6_a("a");
	std::string t6_b("b");

	String t6_A("a");
	String t6_B("b");

	t6_a.swap(t6_b);
	t6_A.swap(t6_B);
	test_case("Swap method test #1 - b ", "resize (size_t n, char c);",
					t6_a.c_str(), t6_A.c_str());
	test_case("Swap method test #1 - a", "resize (size_t n, char c);",
					t6_b.c_str(), t6_B.c_str());

	/* Test swap end */

	/* Test clear */
	// Test #1
	t6_a.clear();
	t6_A.clear();
	test_case("Clear method test #1 ", "clear();",
					t6_a.c_str(), t6_A.c_str());
	/* Test clear end*/

	/* Test operator = */
	// Test #1
	std::string t7_1_str("string");
	std::string t7_1_assign;
	t7_1_assign = t7_1_str;

	String t7_1_Str("string");
	String t7_1_Assign;
	t7_1_Assign = t7_1_Str;
	test_case("Assign operator test #1", "String  = String;",
					t7_1_assign.c_str(), t7_1_Assign.c_str());
	/* Test operator = end */

	/* Test operator += */
	// Test #1
	std::string t8_str("initial string");
	String t8_Str("initial string");
	std::string t8_part(" part");
	String t8_Part(" part");

	t8_str += t8_part;
	t8_Str += t8_Part;
	test_case(" += operator test #1", "String  += String;",
					t8_str.c_str(), t8_Str.c_str());
	// Test #2
	t8_str += " char part";
	t8_Str += " char part";
	test_case(" += operator test #2", "String  += char*;",
					t8_str.c_str(), t8_Str.c_str());
	// Test #3
	t8_str += '.';
	t8_Str += '.';
	test_case(" += operator test #3", "String  += char;",
					t8_str.c_str(), t8_Str.c_str());

	/* Test operator += end*/

	/* test operator + */
	// Test #1
	std::string t9_str("+ test");
	std::string t9_part(" part");
	String t9_Str("+ test");
	String t9_Part(" part");
	std::string res = t9_str + t9_part;
	String Res = t9_Str + t9_Part;
	test_case(" + operator test #1", "String  + String",
					res.c_str(), Res.c_str());

	// Test #2
	std::string res1 = t9_str + " char part";
	String Res1 = t9_Str + " char part";
	test_case(" + operator test #2", "String  + char*",
					res1.c_str(), Res1.c_str());

	// Test #3
	std::string res2 = " char part" + t9_str;
	String Res2 = " char part" + t9_Str;
	test_case(" + operator test #3", "char* + String",
					res2.c_str(), Res2.c_str());

	// Test #4
	std::string res3 = t9_str + '.';
	String Res3 = t9_Str + '.';
	test_case(" + operator test #4", "String + char",
					res3.c_str(), Res3.c_str());

	// Test #5
	std::string res4 = '.' + t9_str;
	String Res4 = '.' + t9_Str;
	test_case(" + operator test #4", "char + String",
					res4.c_str(), Res4.c_str());
	/* test operator + end*/

	/* >> operator Test*/
	// Test #1
	std::string t10_str;
	String t10_Str;
	std::cout << "Enter string to test << operator (std::string): ";
	std::cin >> t10_str;
	std::cout << "Enter string to test << operator (String): ";
	std::cin >> t10_Str;
	test_case(" >> operator test #1", "",
					t10_str.c_str(), t10_Str.c_str());
	/* >> operator Test end*/

	/* == & =! test*/
	std::string t11_str1("true");
	std::string t11_str2("false");
	std::string t11_str3("true");

	String t11_Str1("true");
	String t11_Str2("false");
	String t11_Str3("true");
	test_case(" == operator test #1", "True",
					t11_str1 != t11_str3, t11_Str1 != t11_Str3);
	test_case(" == operator test #2", "False",
					t11_str1 != t11_str2, t11_Str1 != t11_Str2);

	test_case(" != operator test #1", "False",
					t11_str1 != t11_str3, t11_Str1 != t11_Str3);
	test_case(" != operator test #2", "True",
					t11_str1 != t11_str2, t11_Str1 != t11_Str2);

	/* == & =! test end*/
	return 0;

}