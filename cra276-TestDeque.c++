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
struct TestDeque : CppUnit::TestFixture {
    // ----
    // size
    // ----

    void test_default_1() {
        C x;
        CPPUNIT_ASSERT(x.size() == 0);}
		
		void test_default_2() {
				C x(5);
				CPPUNIT_ASSERT(x.size() == 5);}
		
		void test_default_3() {
				C x(15);
				CPPUNIT_ASSERT(x.size() == 15);}
		
		void test_default_4() {
				C x(16);
				CPPUNIT_ASSERT(x.size() == 16);}
		
		void test_fill_1() {
				C x(5, 1);
				CPPUNIT_ASSERT(x.size() == 5);
				CPPUNIT_ASSERT(x[0] == 1);
				CPPUNIT_ASSERT(x[2] == 1);
				CPPUNIT_ASSERT(x[4] == 1);}
		
		void test_fill_2() {
				C x(15, 1);
				CPPUNIT_ASSERT(x.size() == 15);
				CPPUNIT_ASSERT(x[0]  == 1);
				CPPUNIT_ASSERT(x[7]  == 1);
				CPPUNIT_ASSERT(x[14] == 1);}

		void test_fill_3() {
				C x(16, 1);
				CPPUNIT_ASSERT(x.size() == 16);
				CPPUNIT_ASSERT(x[0]  == 1);
				CPPUNIT_ASSERT(x[8]  == 1);
				CPPUNIT_ASSERT(x[15] == 1);}

		void test_copy_1() {
				const C x(5, 1);
				const C y(x);
				CPPUNIT_ASSERT(y.size() == 5);
				CPPUNIT_ASSERT(y[0] == 1);
				CPPUNIT_ASSERT(y[2] == 1);
				CPPUNIT_ASSERT(y[4] == 1);}

		void test_copy_2() {
				const C x(15, 1);
				const C y(x);
				CPPUNIT_ASSERT(y.size() == 15);
				CPPUNIT_ASSERT(y[0]  == 1);
				CPPUNIT_ASSERT(y[7]  == 1);
				CPPUNIT_ASSERT(y[14] == 1);}

		void test_copy_3() {
				const C x(16, 1);
				const C y(x);
				CPPUNIT_ASSERT(y.size() == 16);
				CPPUNIT_ASSERT(y[0]  == 1);
				CPPUNIT_ASSERT(y[8]  == 1);
				CPPUNIT_ASSERT(y[15] == 1);}

		void test_iterator_equal_equal_1() {
				C x(5, 1);
				typename C::iterator i1 = x.begin();
				typename C::iterator i2 = x.begin();
				CPPUNIT_ASSERT(i1 == i2);}
		
		void test_const_iterator_equal_equal_1() {
				const C x(5,2);
				typename C::const_iterator i1 = x.begin();
				typename C::const_iterator i2 = x.begin();
				CPPUNIT_ASSERT(i1 == i2);}
		
		void test_iterator_plus_1() {
				C x(10, 1);
				typename C::iterator i1 = x.begin();
				typename C::iterator i2 = x.end();
				i1 = i1 + 10;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_iterator_plus_2() {
				C x(10, 1);
				typename C::iterator i1 = x.begin();
				typename C::iterator i2 = x.end();
				i1 += 10;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_iterator_plus_3() {
				C x(10, 1);
				typename C::iterator i1 = x.begin();
				typename C::iterator i2 = x.end();
				for (int i = 0; i < 10; ++i)
					++i1;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_const_iterator_plus_1() {
				const C x(10, 1);
				typename C::const_iterator i1 = x.begin();
				typename C::const_iterator i2 = x.end();
				i1 = i1 + 10;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_const_iterator_plus_2() {
				const C x(10, 1);
				typename C::const_iterator i1 = x.begin();
				typename C::const_iterator i2 = x.end();
				i1 += 10;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_const_iterator_plus_3() {
				const C x(10, 1);
				typename C::const_iterator i1 = x.begin();
				typename C::const_iterator i2 = x.end();
				for (int i = 0; i < 10; ++i)
					++i1;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_iterator_minus_1() {
				C x(10, 1);
				typename C::iterator i1 = x.begin();
				typename C::iterator i2 = x.end();
				i2 = i2 - 10;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_iterator_minus_2() {
				C x(10, 1);
				typename C::iterator i1 = x.begin();
				typename C::iterator i2 = x.end();
				i2 -= 10;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_iterator_minus_3() {
				C x(10, 1);
				typename C::iterator i1 = x.begin();
				typename C::iterator i2 = x.end();
				for (int i = 0; i < 10; ++i)
					--i2;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_const_iterator_minus_1() {
				const C x(10, 1);
				typename C::const_iterator i1 = x.begin();
				typename C::const_iterator i2 = x.end();
				i2 = i2 - 10;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_const_iterator_minus_2() {
				const C x(10, 1);
				typename C::const_iterator i1 = x.begin();
				typename C::const_iterator i2 = x.end();
				i2 -= 10;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_const_iterator_minus_3() {
				const C x(10, 1);
				typename C::const_iterator i1 = x.begin();
				typename C::const_iterator i2 = x.end();
				for (int i = 0; i < 10; ++i)
					--i2;
				CPPUNIT_ASSERT(i1 == i2);}

		void test_deque_equal_equal_1() {
				C x(5, 5);
				C y(5, 5);
				CPPUNIT_ASSERT(x == y);}
		
		void test_deque_equal_equal_2() {
				const C x(5,5);
				const C y(x);
				CPPUNIT_ASSERT(x == y);}

		void test_deque_equal_equal_3() {
				C x(10,1);
				C y(10);
				y = x;
				CPPUNIT_ASSERT(x == y);}

		void test_deque_less_than() {
				C x(5, 5);
				C y(10, 5);
				CPPUNIT_ASSERT(x < y);}
		
		void test_deque_push_back_1() {
				C x(5, 1);
				x.push_back(3);
				CPPUNIT_ASSERT(x.size() == 6);
				CPPUNIT_ASSERT(x.back() == 3);}
		
		void test_deque_push_back_2() {
				C x(10, 2);
				x.push_back(55);
				x.push_back(100);
				CPPUNIT_ASSERT(x.size() == 12);
				CPPUNIT_ASSERT(x.back() == 100);}		

		void test_deque_push_back_3() { 
				C x(2, 1);
				CPPUNIT_ASSERT(x.size() == 2);
				x.push_back(10);
				CPPUNIT_ASSERT(x.size() == 3);
				x.push_back(10);
				CPPUNIT_ASSERT(x.size() == 4);
				x.push_back(10);
				CPPUNIT_ASSERT(x.size() == 5);
				x.push_back(10);
				CPPUNIT_ASSERT(x.size() == 6);
				x.push_back(10);
				CPPUNIT_ASSERT(x.size() == 7);}

		void test_deque_push_front_1() {
				C x(5, 1);
				x.push_front(2);
				CPPUNIT_ASSERT(x.size() == 6);
				CPPUNIT_ASSERT(x.front() == 2);}
		
		void test_deque_push_front_2() {
				C x(2,1);
				x.push_front(3);
				x.push_front(3);
				x.push_front(3);
				x.push_front(3);
				CPPUNIT_ASSERT(x.size() == 6);}
		
		void test_deque_back() {
				C x(5, 2);
				CPPUNIT_ASSERT(x.back() == 2);}
		
		void test_deque_front() {
				C x(10, 4);
				CPPUNIT_ASSERT(x.front() == 4);
				x.push_front(1);
				CPPUNIT_ASSERT(x.front() == 1);}
	
		void test_deque_pop_back() {
				C x(10, 2);
				CPPUNIT_ASSERT(x.size() == 10);
				x.pop_back();
				x.pop_back();
				CPPUNIT_ASSERT(x.size() == 8);}

		void test_deque_pop_front() {
				C x(20, 1);
				CPPUNIT_ASSERT(x.size() == 20);
				x.pop_front();
				x.pop_front();
				x.pop_front();
				CPPUNIT_ASSERT(x.size() == 17);}

		void test_deque_clear() {
				C x(5, 12);
				CPPUNIT_ASSERT(x.size() == 5);
				x.clear();
				CPPUNIT_ASSERT(x.size() == 0);}

		void test_deque_erase_1() {
				C x(5, 3);
				x.push_back(6);
				CPPUNIT_ASSERT(x.size() == 6);
				typename C::iterator i1 = x.begin();
				++i1;
				x.erase(i1);
				CPPUNIT_ASSERT(x.size() == 5);
				CPPUNIT_ASSERT(x.back() == 6);}
		
		void test_deque_erase_2() {
				C x(5,3);
				x.push_front(2);
				CPPUNIT_ASSERT(x.size() == 6);
				CPPUNIT_ASSERT(x.front() == 2);
        x.erase(x.begin());
				CPPUNIT_ASSERT(x.size() == 5);
				CPPUNIT_ASSERT(x.front() == 3);}

		void test_deque_insert_1() {
				C x(5, 3);
				CPPUNIT_ASSERT(x.size() == 5);
				typename C::iterator i1 = x.begin();
				i1 += 2;
				x.insert(i1, 1000);
				CPPUNIT_ASSERT(x.size() == 6);
				CPPUNIT_ASSERT(x.back() == 3);
				CPPUNIT_ASSERT(x[2] == 1000);}

		void test_deque_assign_1() {
				C x(10,5);
				C y(10);
				y = x;
				CPPUNIT_ASSERT(y[4] == 5);}
	
		void test_deque_assign_2() {
				C x(10,5);
				C y(35,1);
				y = x;
				CPPUNIT_ASSERT(y.size() == 10);
				CPPUNIT_ASSERT(y == x);}
	
		void test_deque_resize_large() {
				C x(5, 5);
				CPPUNIT_ASSERT(x.size() == 5);
				x.resize(10, 1);
				CPPUNIT_ASSERT(x.size() == 10);
				CPPUNIT_ASSERT(x.front() == 5);
				CPPUNIT_ASSERT(x[5] == 1);}

		void test_deque_resize_small() {
				C x(20, 5);
				CPPUNIT_ASSERT(x.size() == 20);
				x.push_front(1);
				x.resize(10);
				CPPUNIT_ASSERT(x.size() == 10);
				CPPUNIT_ASSERT(x.front() == 1);}
	
		void test_deque_resize_zero() {
				C x(100, 20);
				x.resize(0);
				CPPUNIT_ASSERT(x.size() == 0);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
   	CPPUNIT_TEST(test_default_1);
		CPPUNIT_TEST(test_default_2);
		CPPUNIT_TEST(test_default_3);
		CPPUNIT_TEST(test_default_4);
		CPPUNIT_TEST(test_fill_1);
		CPPUNIT_TEST(test_fill_2);
		CPPUNIT_TEST(test_fill_3);
		CPPUNIT_TEST(test_copy_1);
		CPPUNIT_TEST(test_copy_2);
		CPPUNIT_TEST(test_copy_3);
		CPPUNIT_TEST(test_iterator_equal_equal_1);
		CPPUNIT_TEST(test_const_iterator_equal_equal_1);
		CPPUNIT_TEST(test_iterator_plus_1);
		CPPUNIT_TEST(test_iterator_plus_2);
		CPPUNIT_TEST(test_iterator_plus_3);
		CPPUNIT_TEST(test_const_iterator_plus_1);
		CPPUNIT_TEST(test_const_iterator_plus_2);
		CPPUNIT_TEST(test_const_iterator_plus_3);
		CPPUNIT_TEST(test_iterator_minus_1);
		CPPUNIT_TEST(test_iterator_minus_2);
		CPPUNIT_TEST(test_iterator_minus_3);
		CPPUNIT_TEST(test_const_iterator_minus_1);
		CPPUNIT_TEST(test_const_iterator_minus_2);
		CPPUNIT_TEST(test_const_iterator_minus_3);
		CPPUNIT_TEST(test_deque_equal_equal_1);
		CPPUNIT_TEST(test_deque_equal_equal_2);
		CPPUNIT_TEST(test_deque_equal_equal_3);
		CPPUNIT_TEST(test_deque_less_than);
		CPPUNIT_TEST(test_deque_push_back_1);
		CPPUNIT_TEST(test_deque_push_back_2);
		CPPUNIT_TEST(test_deque_push_back_3);
    CPPUNIT_TEST(test_deque_push_front_1);
		CPPUNIT_TEST(test_deque_push_front_2);
		CPPUNIT_TEST(test_deque_back);
		CPPUNIT_TEST(test_deque_front);
		CPPUNIT_TEST(test_deque_pop_back);
		CPPUNIT_TEST(test_deque_pop_front);
		CPPUNIT_TEST(test_deque_clear);
		CPPUNIT_TEST(test_deque_erase_1);
		CPPUNIT_TEST(test_deque_erase_2);
		CPPUNIT_TEST(test_deque_insert_1);
		CPPUNIT_TEST(test_deque_assign_1);
		CPPUNIT_TEST(test_deque_assign_2);
		CPPUNIT_TEST(test_deque_resize_large);
		CPPUNIT_TEST(test_deque_resize_small);
		CPPUNIT_TEST(test_deque_resize_zero);
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
