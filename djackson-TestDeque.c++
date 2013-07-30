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

    void test_size_1 ()
	{
        const C x;
        CPPUNIT_ASSERT(x.size() == 0);
	}
	
	void test_size_2 ()
	{
		const C x(12);
		CPPUNIT_ASSERT(x.size() == 12);
	}

	
	// ---------
	// push_back
	// ---------

    void test_push_back_1 ()
	{		
		C x;
		x.push_back(34);
		CPPUNIT_ASSERT(x.size() ==  1);
		CPPUNIT_ASSERT(x[0] 	== 34);
	}	
	void test_push_back_2 ()
	{
		C x;
		x.push_back(21);
		x.push_back(232);
		CPPUNIT_ASSERT(x.size() == 	   2);
		CPPUNIT_ASSERT(x[0] 	== 	  21);
		CPPUNIT_ASSERT(x[1]		==   232);
	}
	void test_push_back_3 ()
	{
		C x(12, 2);
		x.push_back(32523);
		x.push_back(234);
		CPPUNIT_ASSERT(x.size() == 		14);
		CPPUNIT_ASSERT(x[12] 	== 	 32523);
		CPPUNIT_ASSERT(x[13] 	== 	   234);
	}


	// ----------
	// push_front
	// ----------

    void test_push_front_1 ()
	{
		C x;
		x.push_front(34);
		CPPUNIT_ASSERT(x.size() ==  1);
		CPPUNIT_ASSERT(x[0] 	== 34);
	}		
	void test_push_front_2 ()
	{
		C x;
		x.push_front(21);
		x.push_front(232);
		CPPUNIT_ASSERT(x.size() == 	   2);
		CPPUNIT_ASSERT(x[1] 	== 	  21);
		CPPUNIT_ASSERT(x[0]		==   232);
	}
	void test_push_front_3 ()
	{
		C x(12, 2);
		x.push_front(32523);
		x.push_front(234);
		CPPUNIT_ASSERT(x.size() == 		14);
		CPPUNIT_ASSERT(x[1] 	== 	 32523);
		CPPUNIT_ASSERT(x[0] 	== 	   234);
	}


	// --------
	// pop_back
	// --------

    void test_pop_back_1 ()
	{
		C x;
		x.push_back(34);
		CPPUNIT_ASSERT(x.size()	==  1);
		x.pop_back();
		CPPUNIT_ASSERT(x.size()	==  0);
	}	
	void test_pop_back_2 ()
	{
		C x;
		x.push_back(21);
		x.push_back(232);
		CPPUNIT_ASSERT(x.size() == 2);
		x.pop_back();
		x.pop_back();
		CPPUNIT_ASSERT(x.size() == 0);
	}
	void test_pop_back_3 ()
	{
		C x(12, 2);
		x.push_back(32523);
		x.push_back(234);
		CPPUNIT_ASSERT(x.size() == 	14);
		x.pop_back();
		x.pop_back();
		x.pop_back();
		CPPUNIT_ASSERT(x.size() == 	11);
	}


	// ---------
	// pop_front
	// ---------

    void test_pop_front_1 ()
	{
		C x;   
		x.push_front(34);    
		CPPUNIT_ASSERT(x.size()	==  1);     
		x.pop_front();
		CPPUNIT_ASSERT(x.size()	==  0);
	}	
	void test_pop_front_2 ()
	{
		C x;
		x.push_front(21);
		x.push_front(232);
		CPPUNIT_ASSERT(x.size()	==  2);
		x.pop_front();
		x.pop_front();
		CPPUNIT_ASSERT(x.size()	== 	0);
	}
	void test_pop_front_3 ()
	{
		C x(12, 2);
		x.push_front(32523);
		x.push_front(234);
		CPPUNIT_ASSERT(x.size()	== 	14);
		x.pop_front();
		x.pop_front();
		x.pop_front();
		CPPUNIT_ASSERT(x.size()	== 	11);
	}



	// ------
	// resize
	// ------

    void test_resize_1 ()
	{
		C x(12);        
		CPPUNIT_ASSERT(x.size() == 12);
		x.resize(12);
		CPPUNIT_ASSERT(x.size() == 12);
	}	
	void test_resize_2 ()
	{
		C x(24);   
		CPPUNIT_ASSERT(x.size() == 24);
		x.resize(4);
		CPPUNIT_ASSERT(x.size() == 4);
	}
	void test_resize_3 ()
	{
		C x(12);        
		CPPUNIT_ASSERT(x.size() == 12);
		x.resize(45);
		CPPUNIT_ASSERT(x.size() == 45);
	}
	void test_resize_4 ()
	{
		C x(427);
		CPPUNIT_ASSERT(x.size() == 427);
	}


	// --------------
	// iterator_begin
	// --------------

    void test_iter_begin_1 ()
	{
        C x;
		x.push_back(2);
		x.push_back(3);
		
		CPPUNIT_ASSERT(*(x.begin()) == 2);

	}	
	void test_iter_begin_2 ()
	{
        C x;

		x.push_back(2);
		x.push_front(23);
		x.push_front(21);
		CPPUNIT_ASSERT(*(x.begin()) == 21);

	}	
	void test_iter_begin_3 ()
	{
        C x;
		
		x.push_back(5);
		x.push_back(23);
		x.push_back(21);
		CPPUNIT_ASSERT(*(x.begin()) == 5);
	}	


	// ------------
	// iterator_end
	// ------------

    void test_iter_end_1 ()
	{
        C x;
		x.push_back(2);
		x.push_back(3);
		CPPUNIT_ASSERT(*(--x.end()) == 2);
	}	
	void test_iter_end_2 ()
	{
        C x;
		x.push_back(2);
		x.push_back(23);
		x.push_back(21);
		x.pop_front();
		CPPUNIT_ASSERT(*(--x.end()) == 2);
	}	
	void test_iter_end_3 ()
	{
        C x;
		x.push_back(2);
		x.push_back(23);
		x.push_back(21);
		CPPUNIT_ASSERT(*(--x.end()) == 21);
	}	


	// -----------
	// iterator_++
	// -----------

    void test_iter_plusplus_1 ()
	{
        C x;
		x.push_front(2);
		x.push_front(3);
		CPPUNIT_ASSERT(*(++x.begin()) == 2);
	}	
	void test_iter_plusplus_2 ()
	{
        C x;
		x.push_front(2);
		CPPUNIT_ASSERT(*x.begin() == 2);
		CPPUNIT_ASSERT(++x.begin() == x.end());
	}	
	void test_iter_plusplus_3 ()
	{
        C x;
		x.push_back(2);
		x.push_back(23);
		x.push_back(21);
		CPPUNIT_ASSERT(*(++x.begin()) == 23);
	}	


	// -----------
	// iterator_--
	// -----------

    void test_iter_minusminus_1 ()
	{
		C x;
		x.push_back(234);
		x.push_back(24);
		x.push_back(12);
		typename C::iterator e = x.end();
		e--;
		e--;
        CPPUNIT_ASSERT(*e == 24);
	}	


	// ----------
	// iterator_*
	// ----------

    void test_iter_add_1 ()
	{
		C x;
		x.push_back(234);
		x.push_back(24);
		x.push_back(12);
		typename C::iterator e = x.end();
		e--;
		e--;
        CPPUNIT_ASSERT(*e == 24);
	}		
	void test_iter_add_2 ()
	{
        C x;
		x.push_back(2);
		x.push_back(23);
		x.push_back(21);
		CPPUNIT_ASSERT(*(x.begin()) == 2);
	}


	// -----
	// clear
	// -----

    void test_clear_1 ()
	{
        C x(124, 12);
		CPPUNIT_ASSERT(x.size() == 124);
		x.clear();
		CPPUNIT_ASSERT(x.size() == 0);
	}	
	void test_clear_2 ()
	{
		C x;
		x.push_back(234);
		x.push_back(24);
		x.push_back(12);
		CPPUNIT_ASSERT(x.size() == 3);
		x.clear();
		CPPUNIT_ASSERT(x.size() == 0);
	}
	void test_clear_3 ()
	{
        C x;
		x.clear();
		CPPUNIT_ASSERT(x.size() == 0);
	}	


	// ----
	// swap
	// ----

    void test_swap_1 ()
	{
        C x(3, 10);
		C y(2, 5);
		x.swap(y);
		CPPUNIT_ASSERT(x.size() == 2);
		CPPUNIT_ASSERT(y.size() == 3);
		CPPUNIT_ASSERT(x[0] ==5);
		CPPUNIT_ASSERT(x[1] ==5);
		CPPUNIT_ASSERT(y[0] ==10);
		CPPUNIT_ASSERT(y[1] ==10);
		CPPUNIT_ASSERT(y[2] ==10);
	}	
	void test_swap_2 ()
	{
		C x(2, 5);
		C y = x;
		x.swap(y);
		CPPUNIT_ASSERT(x == y);
	}
	void test_swap_3 ()
	{
		C x(3, 5);
		C y(3, 2);
		x.swap(y);
		CPPUNIT_ASSERT(x.size() == y.size());
		CPPUNIT_ASSERT(x[0] == 2);
		CPPUNIT_ASSERT(x[1] == 2);
		CPPUNIT_ASSERT(x[2] == 2);
		CPPUNIT_ASSERT(y[0] == 5);
		CPPUNIT_ASSERT(y[1] == 5);
		CPPUNIT_ASSERT(y[2] == 5);
	}


	// -----
	// index
	// -----

    void test_index_1 ()
	{
        C x(3, 10);
		CPPUNIT_ASSERT(x.size() == 3);
		CPPUNIT_ASSERT(x[0] ==10);
		CPPUNIT_ASSERT(x[1] ==10);
		CPPUNIT_ASSERT(x[2] ==10);
	}		
	void test_index_2 ()
	{
		C x;
		x.push_back(2);
		x.push_back(3);
		x.push_back(4);
		CPPUNIT_ASSERT(x[0] == 2);
		CPPUNIT_ASSERT(x[1] == 3);
		CPPUNIT_ASSERT(x[2] == 4);
	}
	void test_index_3 ()
	{
		C x;
		x.push_front(2);
		x.push_front(3);
		x.push_front(4);
		CPPUNIT_ASSERT(x[0] == 4);
		CPPUNIT_ASSERT(x[1] == 3);
		CPPUNIT_ASSERT(x[2] == 2);
	}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
	CPPUNIT_TEST(test_size_1);
	CPPUNIT_TEST(test_size_2);
	CPPUNIT_TEST(test_push_back_1);
	CPPUNIT_TEST(test_push_back_2);
	CPPUNIT_TEST(test_push_back_3);
	CPPUNIT_TEST(test_push_front_1);
	CPPUNIT_TEST(test_push_front_2);
	CPPUNIT_TEST(test_push_front_3);
	CPPUNIT_TEST(test_pop_back_1);
	CPPUNIT_TEST(test_pop_back_2);
	CPPUNIT_TEST(test_pop_back_3);
	CPPUNIT_TEST(test_pop_front_1);
	CPPUNIT_TEST(test_pop_front_2);
	CPPUNIT_TEST(test_pop_front_3);
	CPPUNIT_TEST(test_resize_1);
	CPPUNIT_TEST(test_resize_2);
	CPPUNIT_TEST(test_resize_3);
	CPPUNIT_TEST(test_resize_4);
	CPPUNIT_TEST(test_iter_begin_1);	
	CPPUNIT_TEST(test_iter_begin_2);
	CPPUNIT_TEST(test_iter_begin_3);
	CPPUNIT_TEST(test_iter_end_1);
	CPPUNIT_TEST(test_iter_end_2);
	CPPUNIT_TEST(test_iter_end_3);
	CPPUNIT_TEST(test_iter_plusplus_1);
	CPPUNIT_TEST(test_iter_plusplus_2);
	CPPUNIT_TEST(test_iter_plusplus_3);
	CPPUNIT_TEST(test_iter_minusminus_1);
	CPPUNIT_TEST(test_iter_add_1);
	CPPUNIT_TEST(test_iter_add_2);
	CPPUNIT_TEST(test_clear_1);
	CPPUNIT_TEST(test_clear_2);
	CPPUNIT_TEST(test_clear_3);	
	CPPUNIT_TEST(test_swap_1);
	CPPUNIT_TEST(test_swap_2);
	CPPUNIT_TEST(test_swap_3);	
	CPPUNIT_TEST(test_index_1);
	CPPUNIT_TEST(test_index_2);
	CPPUNIT_TEST(test_index_3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);        // turn off synchronization with C I/O
    cout << "TestDeque.c++" << endl << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDeque< MyDeque<int> >::suite() );
    tr.addTest(TestDeque<   deque<int> >::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
