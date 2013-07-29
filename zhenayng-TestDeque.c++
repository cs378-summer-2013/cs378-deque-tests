// ----------------------------
// projects/deque/TestDeque.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Deque.c++ TestDeque.c++ -o TestDeque -lcppunit -ldl
    % valgrind TestDeque > TestDeque.out
*/

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <deque>     // deque
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Deque.h"

// ---------
// TestDeque
// ---------

template <typename C>
struct TestDeque : CppUnit::TestFixture{
    // ----
    // size
    // ----
    typedef typename C::value_type value_type;
    //const typename C::value_type& v1="abc";

    void test_size () {
        const C x;
        CPPUNIT_ASSERT(x.size() == 0);}

    void test_mydeque_equal () {
        C x;
        C y;
        CPPUNIT_ASSERT(x == y);}

    void test_mydeque_equal2 () {
        const C x;
        const C y;
        CPPUNIT_ASSERT(x == y);}

    void test_iterator_equal3 () {
    	 C x(101);
    	 C y(101);
        CPPUNIT_ASSERT(x == y);}

    void test_defaultConstructor(){
    	const C x;
    	CPPUNIT_ASSERT(x.empty());
    	CPPUNIT_ASSERT(x.size() == 0);
    }

    void test_defaultConstructor1(){
    	 C x(101);
   	 CPPUNIT_ASSERT(!x.empty());
   	 CPPUNIT_ASSERT(x.size() == 101);
    }
    void test_assignConstructor1(){
    	 C x(101);
   	 CPPUNIT_ASSERT(!x.empty());
	 C y(10);
	 y=x;
   	 CPPUNIT_ASSERT(y.size() == 101);
    }
    void test_assignConstructor2(){
    	 C x(106);
   	 CPPUNIT_ASSERT(!x.empty());
	 C y(101);
	 x=y;
   	 CPPUNIT_ASSERT(x.size() == 101);

    }
    void test_assignConstructor3(){
    	 C x(106,6);
   	 CPPUNIT_ASSERT(!x.empty());
	 C y(101);
	 x=y;
   	 CPPUNIT_ASSERT(x.size() == 101);

    }
    void test_copyConstructor1(){
	const int a =5;
   	C x(15,a);
   	C y(x);
   	CPPUNIT_ASSERT(y.size() == 15);
    	CPPUNIT_ASSERT(!y.empty());
	typename C::iterator b = y.begin();
  	CPPUNIT_ASSERT(*(b) == 5);
	CPPUNIT_ASSERT(std::count(y.begin(), y.end(),a) == 15);
    }
    void test_copyConstructor2(){
	//const int a =5;
	const int a =5;
   	C x(105,a);
   	C y(x);
   	CPPUNIT_ASSERT(y.size() == 105);
    	CPPUNIT_ASSERT(!y.empty());
	typename C::iterator b = y.begin();
  	CPPUNIT_ASSERT(*(b) == 5);
	CPPUNIT_ASSERT(std::count(y.begin(), y.end(),a) == 105);

    }
    void test_copyConstructor3(){
	//const int a =5;
	const int a =5;
   	C x(99,a);
   	C y(x);
   	CPPUNIT_ASSERT(y.size() == 99);
    	CPPUNIT_ASSERT(!y.empty());
	typename C::iterator b = y.begin();
  	CPPUNIT_ASSERT(*(b) == 5);
	CPPUNIT_ASSERT(std::count(y.begin(), y.end(),a) == 99);

    }
    void test_iterator1(){
	//const int a =5;
	int a =5;
   	C x(15,a);
   	CPPUNIT_ASSERT(x.size() == 15);
	typename C::iterator b = x.begin();
    	CPPUNIT_ASSERT(!x.empty());
  	CPPUNIT_ASSERT(*b == 5);
  	CPPUNIT_ASSERT(*(++b) == 5);
	*b=10;
	CPPUNIT_ASSERT(*b == 10);

	CPPUNIT_ASSERT(*(--b) == 5);
	CPPUNIT_ASSERT(*(++b) == 10);

    }

    void test_iterator2(){
	//const int a =5;
	int a =5;
   	C x(25,a);
   	CPPUNIT_ASSERT(x.size() == 25);
	typename C::iterator bb = x.end();
    	CPPUNIT_ASSERT(!x.empty());
  	CPPUNIT_ASSERT(*(--bb) == 5);

	*bb=10;
	CPPUNIT_ASSERT(*bb == 10);
	CPPUNIT_ASSERT(*(--bb) == 5);

    }

    void test_iterator3(){
	//const int a =5;
	int a =5;
   	C x(105,a);
   	CPPUNIT_ASSERT(x.size() == 105);
	typename C::iterator bb = x.end();
    	CPPUNIT_ASSERT(!x.empty());
  	CPPUNIT_ASSERT(*(--bb) == 5);

	*bb=10;
	CPPUNIT_ASSERT(*bb == 10);
	CPPUNIT_ASSERT(*(--bb) == 5);

    }
    void test_iterator4(){
	int a =5;
   	C x(105,a);
   	CPPUNIT_ASSERT(x.size() == 105);

    	CPPUNIT_ASSERT(!x.empty());

   	CPPUNIT_ASSERT(std::count(x.begin(), x.end(), a) == 105);
    }
    void test_iterator5(){
	int a =5;
   	C x(5,a);
   	CPPUNIT_ASSERT(x.size() == 5);
	typename C::iterator b = x.begin();
    	CPPUNIT_ASSERT(!x.empty());
  	CPPUNIT_ASSERT(*b == 5);
	CPPUNIT_ASSERT(*(++b) == 5);

   	CPPUNIT_ASSERT(std::count(x.begin(), x.end(), a) == 5);
    }


    void test_resize1(){
	    C x(20,5);
	    CPPUNIT_ASSERT(x.size() == 20);
	    x.resize(21);

	    CPPUNIT_ASSERT(x.size() == 21);
    }

    void test_resize2(){
	    C x(201,5);
	    CPPUNIT_ASSERT(x.size() == 201);
	    x.resize(300,6);
	    typename C::iterator b = x.begin();
	    CPPUNIT_ASSERT(*(b+201) == 6);
	    CPPUNIT_ASSERT(x.size() == 300);
    }
    void test_resize3(){
	    C x(20,5);
	    CPPUNIT_ASSERT(x.size() == 20);
	    x.resize(5);
	    CPPUNIT_ASSERT(x.size() == 5);
    }
    void test_resize4(){
	    C x(20,5);
	    CPPUNIT_ASSERT(x.size() == 20);
	    x.resize(0);
	    CPPUNIT_ASSERT(x.size() == 0);
    }
    void test_resize5(){
	    C x(19,5);
	    CPPUNIT_ASSERT(x.size() == 19);
	    x.resize(20,7);
	    CPPUNIT_ASSERT(x.size() == 20);
	    typename C::iterator b = x.begin();

	    CPPUNIT_ASSERT(*(b+19) == 7);
	    CPPUNIT_ASSERT(*(b+18) == 5);
    }
    void test_resize6(){
	    C x(21,5);
	    CPPUNIT_ASSERT(x.size() == 21);
	    x.resize(20);
	    CPPUNIT_ASSERT(x.size() == 20);
    }
    void test_resize7(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.resize(20,7);
	    CPPUNIT_ASSERT(x.size() == 20);
	    typename C::iterator b = x.begin();

	    CPPUNIT_ASSERT(*(b+18) == 7);
	    CPPUNIT_ASSERT(*(b+17) == 5);
    }
    void test_erase1(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.resize(20,7);
	    CPPUNIT_ASSERT(x.size() == 20);
	    typename C::iterator b = x.begin();
	    CPPUNIT_ASSERT(*(b+18) == 7);
	    CPPUNIT_ASSERT(*(b+17) == 5);
	    x.erase(x.begin()+17);
	    b = x.begin();
	    CPPUNIT_ASSERT(*(b+18) == 7);
	    CPPUNIT_ASSERT(*(b+17) == 7);
	    CPPUNIT_ASSERT(x.size() == 19);
	    x.insert(x.begin()+17,100);
	    b = x.begin();
	    CPPUNIT_ASSERT(*(b+18) == 7);
	    CPPUNIT_ASSERT(*(b+17) == 100);
	    CPPUNIT_ASSERT(x.size() == 20);
	    CPPUNIT_ASSERT(x.front() == 5);
	    CPPUNIT_ASSERT(x.back() == 7);
	    
    }
    void test_erase2(){
	    C x(18,5);
	    x.erase(x.begin()+5);
	    x.erase(x.begin()+6);
	    CPPUNIT_ASSERT(x.size() == 16);
    }
    void test_erase3(){
	    C x(18,5);
	    x.erase(x.begin()+5);
	    x.erase(x.begin()+6);
	    CPPUNIT_ASSERT(x.size() == 16);
    }
    void test_push_back1(){
	    
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    CPPUNIT_ASSERT(x.size() == 19);
	    x.push_back(7);
	    CPPUNIT_ASSERT(x.size() == 20);
	    x.push_back(8);
	    CPPUNIT_ASSERT(x.size() == 21);
	    typename C::iterator b = x.begin();
	    CPPUNIT_ASSERT(*(b+18) == 6);
	    CPPUNIT_ASSERT(*(b+17) == 5);
	    CPPUNIT_ASSERT(*(b+19) == 7);
	    CPPUNIT_ASSERT(*(b+20) == 8);
	    x.pop_back();
	    CPPUNIT_ASSERT(x.size() == 20);
	    typename C::iterator bb = x.begin();
	    CPPUNIT_ASSERT((*bb)== 5);
	    x.push_front(10);
	    CPPUNIT_ASSERT(x.size() == 21);
	    typename C::iterator bbb = x.begin();
	    CPPUNIT_ASSERT(*(bbb) == 10);
	    CPPUNIT_ASSERT(*(bbb+1) == 5);

	    x.push_front(11);
	    CPPUNIT_ASSERT(x.size() == 22);
	    typename C::iterator bbbbb = x.begin();
	    CPPUNIT_ASSERT(*(bbbbb) == 11);
	    CPPUNIT_ASSERT(*(bbbbb+1) == 10);
	    CPPUNIT_ASSERT(*(bbbbb+2) == 5);

	    x.pop_front();
	    x.pop_front();
	    CPPUNIT_ASSERT(x.size() == 20);
	    typename C::iterator aa = x.begin();
	    CPPUNIT_ASSERT(*(aa) == 5);
	    CPPUNIT_ASSERT(*(aa+1) == 5);
	    CPPUNIT_ASSERT(*(aa+2) == 5);

	    x.pop_front();
	    CPPUNIT_ASSERT(x.size() == 19);
	    typename C::iterator aaa = x.begin();
	    CPPUNIT_ASSERT(*(aaa) == 5);
	    CPPUNIT_ASSERT(*(aaa+1) == 5);
	    CPPUNIT_ASSERT(x[0] == 5);
	    CPPUNIT_ASSERT(x.at(0) == 5);
	    x[0]=3;
	    CPPUNIT_ASSERT(x[0] == 3);
    }


    void test_push_back2(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    x.push_back(6);
	    x.push_back(6);
	    x.push_back(6);
	    x.push_back(6);
	    CPPUNIT_ASSERT(x.size() == 23);

    }
    void test_push_back3(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    x.push_back(6);
	    x.push_back(3);
	    CPPUNIT_ASSERT(x.size() == 21);
    }
    void test_index_1(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    CPPUNIT_ASSERT(x.back() == 6);
            CPPUNIT_ASSERT(x[0] == 5);
	    CPPUNIT_ASSERT(x[18] == 6);
            CPPUNIT_ASSERT(x[17] == 5);

    }
    void test_index_2(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    x.push_back(6);
	    x.push_back(6);
	    x.push_back(6);
	    x.push_back(6);
	    CPPUNIT_ASSERT(x.size() == 23);
            CPPUNIT_ASSERT(x[0] == 5);
	    CPPUNIT_ASSERT(x[21] == 6);
            CPPUNIT_ASSERT(x[22] == 6);

    }
    void test_index_3(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    x.push_back(6);
	    x.push_back(3);
	    CPPUNIT_ASSERT(x.size() == 21);
            CPPUNIT_ASSERT(x[20] == 3);
	    CPPUNIT_ASSERT(x[19] == 6);
            CPPUNIT_ASSERT(x[17] == 5);
    }
    void test_back1(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    CPPUNIT_ASSERT(x.back() == 6);

    }
    void test_back2(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    CPPUNIT_ASSERT(x.back() == 5);
    }
    void test_back3(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    x.push_back(7);
	    CPPUNIT_ASSERT(x.back() == 7);

    }
    void test_front1(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.push_back(6);
	    CPPUNIT_ASSERT(x.front() == 5);

    }
    void test_front2(){
	    C x(1,5);
	    CPPUNIT_ASSERT(x.size() == 1);
	    CPPUNIT_ASSERT(x.front() == 5);
    }
    void test_front3(){
	    C x(8,5);
	    CPPUNIT_ASSERT(x.size() == 8);
	    CPPUNIT_ASSERT(x.front() == 5);

    }
    void test_pop_front1(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.pop_front();
	    CPPUNIT_ASSERT(x.front() == 5);

    }
    void test_pop_front2(){
	    C x(2,5);
	    CPPUNIT_ASSERT(x.size() == 2);
	    x.pop_front();
	    CPPUNIT_ASSERT(x.front() == 5);
    }
    void test_pop_front3(){
	    C x(8,5);
	    CPPUNIT_ASSERT(x.size() == 8);
	    x.pop_front();
	    CPPUNIT_ASSERT(x.front() == 5);
	    CPPUNIT_ASSERT(x.size() == 7);

    }
    void test_pop_back1(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    CPPUNIT_ASSERT(x.size() == 13);

    }
    void test_pop_back2(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    CPPUNIT_ASSERT(x.size() == 15);
    }
    void test_pop_back3(){
	    C x(18,5);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    x.push_back(6);
	    CPPUNIT_ASSERT(x.size() == 15);

    }
    void test_swap1(){
	    C y(18,5);
	    C x(9,9);
	    y.swap(x);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    CPPUNIT_ASSERT(x.size() == 15);
    }
    void test_swap2(){
	    C y(18,5);
	    C x(90,90);
	    y.swap(x);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    CPPUNIT_ASSERT(x.size() == 15);
    }
    void test_swap3(){
	    C y(18,5);
	    C x(1,1);
	    y.swap(x);
	    CPPUNIT_ASSERT(x.size() == 18);
	    x.pop_back();
	    x.pop_back();
	    x.pop_back();
	    CPPUNIT_ASSERT(x.size() == 15);
    }
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
    CPPUNIT_TEST(test_size);
    CPPUNIT_TEST(test_mydeque_equal);
    CPPUNIT_TEST(test_mydeque_equal2);
    CPPUNIT_TEST(test_defaultConstructor);
    CPPUNIT_TEST(test_defaultConstructor1);
    CPPUNIT_TEST(test_assignConstructor1);
    CPPUNIT_TEST(test_assignConstructor2);
    CPPUNIT_TEST(test_copyConstructor1);
    CPPUNIT_TEST(test_copyConstructor2);
    CPPUNIT_TEST(test_iterator1);
    CPPUNIT_TEST(test_iterator2);
    CPPUNIT_TEST(test_iterator3);
    CPPUNIT_TEST(test_iterator4);
    CPPUNIT_TEST(test_iterator5);
    CPPUNIT_TEST(test_resize1);
    CPPUNIT_TEST(test_resize2);
    CPPUNIT_TEST(test_resize3);
    CPPUNIT_TEST(test_resize4);
    CPPUNIT_TEST(test_resize5);
    CPPUNIT_TEST(test_resize6);
    CPPUNIT_TEST(test_resize7);
    CPPUNIT_TEST(test_erase1);
    CPPUNIT_TEST(test_push_back1);
    CPPUNIT_TEST(test_push_back2);
    CPPUNIT_TEST(test_push_back3);
    CPPUNIT_TEST(test_back1);
    CPPUNIT_TEST(test_back2);
    CPPUNIT_TEST(test_back3);
    CPPUNIT_TEST(test_index_1);
    CPPUNIT_TEST(test_index_2);
    CPPUNIT_TEST(test_index_3);
    CPPUNIT_TEST(test_front1);
    CPPUNIT_TEST(test_front2);
    CPPUNIT_TEST(test_front3);
    CPPUNIT_TEST(test_swap1);
    CPPUNIT_TEST(test_swap2);
    CPPUNIT_TEST(test_swap3);
    CPPUNIT_TEST(test_pop_front1);
    CPPUNIT_TEST(test_pop_front2);
    CPPUNIT_TEST(test_pop_front3);
    CPPUNIT_TEST(test_pop_back1);
    CPPUNIT_TEST(test_pop_back2);
    CPPUNIT_TEST(test_pop_back3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);        // turn off synchronization with C I/O
    cout << "TestDeque.c++" << endl << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDeque< MyDeque<int> >::suite());
    tr.addTest(TestDeque<   deque<int> >::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
