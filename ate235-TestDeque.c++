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
#include <cstring> // strcmp
#include <deque> // deque
#include <sstream> // ostringstream
#include <stdexcept> // invalid_argument
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TestRunner

#include "Deque.h"

// ---------
// TestDeque
// ---------

template <typename C>
struct TestDeque : CppUnit::TestFixture {
    
	//test construct

    void test_construct_1 () {
        const C x;
        CPPUNIT_ASSERT(x.size() == 0);
	}

    void test_construct_2 () {
        const C x(18);
        CPPUNIT_ASSERT(x.size() == 18);
	}

    void test_construct_3 () {
        const C x(1, 0);
        CPPUNIT_ASSERT(x.size() == 1);
	}

	void test_construct_4 () {
        const C x(7, 7);
        CPPUNIT_ASSERT(x.size() == 7);
	}

	//test size
    void test_size_1 () {
        const C x(17, 0);
        CPPUNIT_ASSERT(x.size() == 17);
	}

    void test_size_2 () {
        const C x(55, 0);
        CPPUNIT_ASSERT(x.size() == 55);
	}

	void test_size_3 () {
        const C x(123, 0);
		
        CPPUNIT_ASSERT(x.size() == 123);
	}

    void test_size_4 () {
        const C x(154, 2);
        CPPUNIT_ASSERT(x.size() == 154);
	}
	
	//test iter construct

	void test_iter_construct_1(){
		C x(6,1);
		typename C::iterator b = x.begin();
		assert(*b == 1);
	}

	void test_iter_construct_2(){
		C x(7,1);
		typename C::iterator b = x.begin();
		assert(*b == 1);
		b += 12;
		assert(*b == 0);
	}

	void test_iter_construct_3(){
		C x(46,3);
		typename C::iterator b = x.begin();
		assert(*b == 3);
		b += 21;
		assert(*b == 3); 
	}
	void test_iter_construct_4(){
		C x(46,3);
		typename C::iterator b = x.begin();
		assert(*b == 3);
		b += 27;
		assert(*b == 3); 
	}
	void test_iter_construct_5(){
		C x(46,3);
		typename C::iterator b = x.begin();
		assert(*b == 3);
		b += 23;
		assert(*b == 3); 
	}
	
	//test iter plusplus

	void test_iter_plusplus_1(){
		C x(13,0);
		typename C::iterator b = x.begin();
		assert(*b == 0);
		++b;
		assert(*b == 0);
	}

	void test_iter_plusplus_2(){
		C x(46,2);
		typename C::iterator b = x.begin();
		assert(*b == 2);
		++b;
		assert(*b == 2);
		++b;
		assert(*b == 2);
	}

	void test_iter_plusplus_3(){
		C x(4,5);
		typename C::iterator b = x.begin();
		assert(*b == 5);
		++b;
		assert(*b == 5);
		++b;
		assert(*b == 5);
	}

	//test iter minusminus
	
	void test_iter_minusminus_1(){
		C x(2,0);
		typename C::iterator b = x.end();
		assert(*b == 0);
		--b;
		--b;
		assert(*b == 0);
	}

	void test_iter_minusminus_2(){
		C x(46,2);
		typename C::iterator b = x.end();
		assert(*b == 2);
		--b;
		assert(*b == 2);
		--b;
		assert(*b == 2);
	}

	void test_iter_minusminus_3(){
		C x(4,5);
		typename C::iterator b = x.end();
		assert(*b == 5);
		--b;
		assert(*b == 5);
		--b;
		assert(*b == 5);
	}

	//test iter plusequals

	void test_iter_plus_equals_1(){
		C x(5,0);
		typename C::iterator b = x.begin();
		assert(*b == 0);
		b += 2;
		assert(*b == 0);
	}

	void test_iter_plus_equals_2(){
		C x(56,2);
		typename C::iterator b = x.begin();
		assert(*b == 2);
		b += 2;
		assert(*b == 2);
		b += 17;
		assert(*b == 2);
	}

	void test_iter_plus_equals_3(){
		C x(25,14);
		typename C::iterator b = x.begin();
		assert(*b == 14);
		b += 10;
		assert(*b == 14); 
	}
	
	void test_iter_minus_equals_1(){
		C x(5,0);
		typename C::iterator b = x.begin();
		assert(*b == 0);
		b += 2;
		assert(*b == 0);
	}

	void test_iter_minus_equals_2(){
		C x(56,2);
		typename C::iterator b = x.begin();
		assert(*b == 2);
		b += 2;
		assert(*b == 2);
		b += 17;
		assert(*b == 2);
	}

	void test_iter_minus_equals_3(){
		C x(25,14);
		typename C::iterator b = x.begin();
		assert(*b == 14);
		b += 10;
		assert(*b == 14); 
	}
	
	
	
	
	
	
	
	// const iter tests
	
	void test_const_iter_construct_1(){
		const C x(6,1);
		typename C::const_iterator b = x.begin();
		assert(*b == 1);
	}

	void test_const_iter_construct_2(){
		const C x(7,1);
		typename C::const_iterator b = x.begin();
		assert(*b == 1);
		b += 12;
		assert(*b == 0);
	}

	void test_const_iter_construct_3(){
		const C x(46,3);
		typename C::const_iterator b = x.begin();
		assert(*b == 3);
		b += 21;
		assert(*b == 3); 
	}
	void test_const_iter_construct_4(){
		const C x(46,3);
		typename C::const_iterator b = x.begin();
		assert(*b == 3);
		b += 27;
		assert(*b == 3); 
	}
	void test_const_iter_construct_5(){
		const C x(46,3);
		typename C::const_iterator b = x.begin();
		assert(*b == 3);
		b += 23;
		assert(*b == 3); 
	}
	
	//test iter plusplus

	void test_const_iter_plusplus_1(){
		const C x(13,0);
		typename C::const_iterator b = x.begin();
		assert(*b == 0);
		++b;
		assert(*b == 0);
	}

	void test_const_iter_plusplus_2(){
		const C x(46,2);
		typename C::const_iterator b = x.begin();
		assert(*b == 2);
		++b;
		assert(*b == 2);
		++b;
		assert(*b == 2);
	}

	void test_const_iter_plusplus_3(){
		const C x(4,5);
		typename C::const_iterator b = x.begin();
		assert(*b == 5);
		++b;
		assert(*b == 5);
		++b;
		assert(*b == 5);
	}

	//test iter minusminus
	
	void test_const_iter_minusminus_1(){
		const C x(2,0);
		typename C::const_iterator b = x.end();
		assert(*b == 0);
		--b;
		--b;
		assert(*b == 0);
	}

	void test_const_iter_minusminus_2(){
		const C x(46,2);
		typename C::const_iterator b = x.end();
		assert(*b == 2);
		--b;
		assert(*b == 2);
		--b;
		assert(*b == 2);
	}

	void test_const_iter_minusminus_3(){
		const C x(4,5);
		typename C::const_iterator b = x.end();
		assert(*b == 5);
		--b;
		assert(*b == 5);
		--b;
		assert(*b == 5);
	}

	//test iter plusequals

	void test_const_iter_plus_equals_1(){
		const C x(5,0);
		typename C::const_iterator b = x.begin();
		assert(*b == 0);
		b += 2;
		assert(*b == 0);
	}

	void test_const_iter_plus_equals_2(){
		const C x(56,2);
		typename C::const_iterator b = x.begin();
		assert(*b == 2);
		b += 2;
		assert(*b == 2);
		b += 17;
		assert(*b == 2);
	}

	void test_const_iter_plus_equals_3(){
		const C x(21,14);
		typename C::const_iterator b = x.begin();
		assert(*b == 14);
		b += 10;
		assert(*b == 14); 
	}
	
	void test_const_iter_minus_equals_1(){
		const C x(5,0);
		typename C::const_iterator b = x.begin();
		assert(*b == 0);
		b += 2;
		assert(*b == 0);
	}

	void test_const_iter_minus_equals_2(){
		const C x(56,2);
		typename C::const_iterator b = x.begin();
		assert(*b == 2);
		b += 2;
		assert(*b == 2);
		b += 17;
		assert(*b == 2);
	}

	void test_const_iter_minus_equals_3(){
		const C x(21,14);
		typename C::const_iterator b = x.begin();
		assert(*b == 14);
		b += 10;
		assert(*b == 14); 
	}

	//test equal

	void test_equal_1(){
		const C x(5,0);
		const C y(5,0);
		assert(x == y);
	}

	void test_equal_2(){
		const C x(5,2);
		const C y(5,0);
		assert(x != y);
	}

	void test_equal_3(){
		const C x(1000,1);
		const C y(1002,1);
		assert(x == y);
	}
	
	//test resize
	
	void test_resize_1(){
		C x(12, 5);
		assert(x.size() == 12);
		x.resize(15, 7);
		assert(x.size() == 15);
	}
	void test_resize_2(){
		C x(12, 5);
		assert(x.size() == 12);
		x.resize(12, 7);
		assert(x.size() == 12);
	}
	void test_resize_3(){
		C x(12, 5);
		assert(x.size() == 12);
		x.resize(6, 7);
		assert(x.size() == 6);
	}
	void test_resize_4(){
		C x(12, 5);
		assert(x.size() == 12);
		x.resize(7, 7);
		assert(x.size() == 7);
	}
	void test_resize_5(){
		C x(12, 5);
		assert(x.size() == 12);
		x.resize(1, 7);
		assert(x.size() == 1);
	}
	void test_resize_6(){
		C x(12, 5);
		assert(x.size() == 12);
		x.resize(0, 7);
		assert(x.size() == 0);
	}
	
	


	

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
	CPPUNIT_TEST(test_construct_1);
	CPPUNIT_TEST(test_construct_2);
	CPPUNIT_TEST(test_construct_3);
	CPPUNIT_TEST(test_construct_4);

	CPPUNIT_TEST(test_size_1);
	CPPUNIT_TEST(test_size_2);
	CPPUNIT_TEST(test_size_3);
	CPPUNIT_TEST(test_size_4);

	CPPUNIT_TEST(test_iter_construct_1);
	CPPUNIT_TEST(test_iter_construct_2);
	CPPUNIT_TEST(test_iter_construct_3);
	CPPUNIT_TEST(test_iter_construct_4);
	CPPUNIT_TEST(test_iter_construct_5);

	CPPUNIT_TEST(test_iter_plusplus_1);
	CPPUNIT_TEST(test_iter_plusplus_2);
	CPPUNIT_TEST(test_iter_plusplus_3);

	CPPUNIT_TEST(test_iter_minusminus_1);
	CPPUNIT_TEST(test_iter_minusminus_2);
	CPPUNIT_TEST(test_iter_minusminus_3);
	

	CPPUNIT_TEST(test_iter_plus_equals_1);
	CPPUNIT_TEST(test_iter_plus_equals_2); 
	CPPUNIT_TEST(test_iter_plus_equals_3);

	CPPUNIT_TEST(test_iter_minus_equals_1);
	CPPUNIT_TEST(test_iter_minus_equals_2); 
	CPPUNIT_TEST(test_iter_minus_equals_3);
/*
	CPPUNIT_TEST(test_const_iter_construct_1);
	CPPUNIT_TEST(test_const_iter_construct_2);
	CPPUNIT_TEST(test_const_iter_construct_3);
	CPPUNIT_TEST(test_const_iter_construct_4);
	CPPUNIT_TEST(test_const_iter_construct_5);

	CPPUNIT_TEST(test_const_iter_plusplus_1);
	CPPUNIT_TEST(test_const_iter_plusplus_2);
	CPPUNIT_TEST(test_const_iter_plusplus_3);

	CPPUNIT_TEST(test_const_iter_minusminus_1);
	CPPUNIT_TEST(test_const_iter_minusminus_2);
	CPPUNIT_TEST(test_const_iter_minusminus_3);
	

	CPPUNIT_TEST(test_const_iter_plus_equals_1);
	CPPUNIT_TEST(test_const_iter_plus_equals_2); 
	CPPUNIT_TEST(test_const_iter_plus_equals_3);
	
	CPPUNIT_TEST(test_const_iter_minus_equals_1);
	CPPUNIT_TEST(test_const_iter_minus_equals_2); 
	CPPUNIT_TEST(test_const_iter_minus_equals_3);

	CPPUNIT_TEST(test_equal_1);
	CPPUNIT_TEST(test_equal_2);
	CPPUNIT_TEST(test_equal_3);
*/	
//	CPPUNIT_TEST(test_resize_1);
//	CPPUNIT_TEST(test_resize_2);
//	CPPUNIT_TEST(test_resize_3);
//	CPPUNIT_TEST(test_resize_4);
//	CPPUNIT_TEST(test_resize_5);
//	CPPUNIT_TEST(test_resize_6);

    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestDeque.c++" << endl << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDeque< MyDeque<int> >::suite());
    //tr.addTest(TestDeque< deque<int> >::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
