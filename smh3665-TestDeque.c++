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

    void test_size () {
        const C x;
        CPPUNIT_ASSERT(x.size() == 0);}
	void test_size_1() {
		const C x (10);
		CPPUNIT_ASSERT(x.size() == 10);
	}
	void test_size_2 () {
		const C x (10, 5);
		CPPUNIT_ASSERT(x.size() == 10);
	}
	
	// ------
	// resize
	// ------
	
	void test_resize () {
		C x (5);
		CPPUNIT_ASSERT(x.size () == 5);
		x.resize (5);
		CPPUNIT_ASSERT(x.size () == 5);
	}
	
	void test_resize_1 () {
		C x (10);
		CPPUNIT_ASSERT(x.size () == 10);
		x.resize (5);
		CPPUNIT_ASSERT(x.size ()  == 5);
	}
	
	void test_resize_2 () {
		C x (5);
		CPPUNIT_ASSERT(x.size () ==  5);
		x.resize (10);
		CPPUNIT_ASSERT(x.size () == 10);
	}
	
	void test_resize_3 () {
		C x (5);
		CPPUNIT_ASSERT(x.size () ==  5);
		x.resize (13);
		CPPUNIT_ASSERT(x.size () == 13);
	}
		
	// ----------
	// operator[]
	// ----------
    void test_index () {
		C x (5);
		CPPUNIT_ASSERT(x[0] == 0);
		CPPUNIT_ASSERT(x[4] == 0);
	}
	
	void test_index_1 () {
		C x (5, 2);
		x[0] = 0;
		CPPUNIT_ASSERT(x[0] == 0);
		CPPUNIT_ASSERT(x[1] == 2);
	}
	
	void test_index_2 () {
		const C x (5, 2);
		CPPUNIT_ASSERT(x[3] == 2);
	}
	
	// -----
	// begin
	// -----
	
	void test_begin () {
		C x (5, 2);
		auto it = x.begin ();
		CPPUNIT_ASSERT(*it == 2);
		++it;
		CPPUNIT_ASSERT(*it == 2);
	}
	
	void test_begin_1 () {
		C x (5);
		auto it = x.begin ();
		it += 2;
		*it = 2;
		CPPUNIT_ASSERT(*it == 2);
		++it;
		CPPUNIT_ASSERT(*it == 0);
	}
	
	// ---
	// end
	// ---
	
	void test_end () {
		C x;
		CPPUNIT_ASSERT(x.begin () == x.end ());
	}
	
	void test_end_1 () {
		C x (5);
		auto it = x.end();
		CPPUNIT_ASSERT(x.begin () != x.end ());
		--it;
		CPPUNIT_ASSERT(*it == 0);
		--it;
		*it = 1;
		CPPUNIT_ASSERT(*it == 1);
		CPPUNIT_ASSERT(it != x.end ());
	}
	
	// -----------
	// const begin
	// -----------
	
	void test_begin_2 () {
		const C x (5);
		auto it = x.begin ();
		while(it != x.end ()){
			CPPUNIT_ASSERT(*it == 0);
			++it;
		}
	}
    
	// ---------
	// const end
	// ---------
	void test_end_2 () {
		const C x (5, 1);
		auto it = x.end ();
		while(--it != x.begin ()){
			CPPUNIT_ASSERT(*it == 1);
		}
	}
	
	// ----
	// push
	// ----
	
	void test_push_front () {
		C x;
		x.push_front (2);
		CPPUNIT_ASSERT(x[0]		 == 2);
		CPPUNIT_ASSERT(x.size () == 1);
	}
	
	void test_push_front_1 () {
		C x (5);
		x.push_front (2);
		CPPUNIT_ASSERT(x[0]		 == 2);
		CPPUNIT_ASSERT(x.size () == 6);
	}
	
	void test_push_front_2 () {
		C x (2, 2);
		CPPUNIT_ASSERT(x[0]		 == 2);
		x.push_front (3);
		CPPUNIT_ASSERT(x[0]		 == 3);
		CPPUNIT_ASSERT(x.size () == 3);
	}
	
	void test_push_back () {
		C x;
		x.push_back (2);
		CPPUNIT_ASSERT(x[0]		 == 2);
		CPPUNIT_ASSERT(x.size () == 1);
	}
	
	void test_push_back_1 () {
		C x (5);
		x.push_back (2);
		int y [] = {0, 0, 0, 0, 0, 2};
		CPPUNIT_ASSERT(x[0]		 == 0);
		CPPUNIT_ASSERT(x[5]		 == 2);
		CPPUNIT_ASSERT(x.size () == 6);
		CPPUNIT_ASSERT(std::equal(x.begin (), x.end (), y));
	}
	
	void test_push_back_2 () {
		C x (2, 2);
		CPPUNIT_ASSERT(x[1]		 == 2);
		x.push_back (3);
		CPPUNIT_ASSERT(x[2]		 == 3);
		CPPUNIT_ASSERT(x.size () == 3);
	}
	
	// ---
	// pop
	// ---
	
	void test_pop_back () {
		C x (1);
		x.pop_back ();
		CPPUNIT_ASSERT(x.size () == 0);
	}
	
	void test_pop_back_1 () {
		C x (2, 2);
		x.pop_back ();
		CPPUNIT_ASSERT(x.size () == 1);
		//CPPUNIT_ASSERT(x[0] == 2);
	}
	
	void test_pop_back_2 () {
		C x;
		x.push_back (2);
		x.push_back (3);
		CPPUNIT_ASSERT(x.size () == 2);
		x.pop_back ();
		CPPUNIT_ASSERT(x.size () == 1);
		//CPPUNIT_ASSERT(x[0] == 2);
	}
	
	void test_pop_front () {
		C x (1);
		CPPUNIT_ASSERT(x.size () == 1);
		x.pop_front ();
		CPPUNIT_ASSERT(x.size () == 0);
	}
	
	void test_pop_front_1 () {
		C x (2, 2);
		CPPUNIT_ASSERT(x.size () == 2);
		x.pop_back ();
		CPPUNIT_ASSERT(x.size () == 1);
	}
	
	void test_pop_front_2 () {
		C x;
		x.push_front (2);
		x.push_back (3);
		CPPUNIT_ASSERT(x.size () == 2);
		x.pop_front ();
		x.pop_front ();
		CPPUNIT_ASSERT(x.size () == 0);
	}
	
	// ------
	// insert
	// ------
	
	void test_insert () { //test insert after default ctor
		C x (2);
		int y[] = {0, 3, 0};
		auto it = x.begin();
		++it;
		it = x.insert (it, 3);
		/* for(int i : x){
			std::cout << i << " ";
		}
		std::cout << std::endl; */
		CPPUNIT_ASSERT(std::equal (x.begin (), x.end (), y));
	}
	
	void test_insert_1 () {	// testing empty insert
		C x;
		int y[] = {1};
		auto it = x.begin ();
		x.insert (it, 1);
		CPPUNIT_ASSERT(std::equal (x.begin (), x.end (), y));
	}
	
	void test_insert_2 () { // testing fill/range insert not necessary
		
	}
	
	// -----
	// front
	// -----
	
	void test_front () {
		C x;
		x.push_back (1);
		x.push_back (2);
		x.push_back (3);
		CPPUNIT_ASSERT(x.front () == 1);
	}
	
	void test_front_1 () { // testing front modification
		C x;
		x.push_back (1);
		x.push_back (2);
		x.push_back (3);
		x.front () = 0;
		CPPUNIT_ASSERT(x.front () == 0);
	}
	
	// ----
	// back
	// ----
	
	void test_back () {
		C x;
		x.push_back (1);
		x.push_front (1);
		x.push_back (2);
		x.push_front (2);
		CPPUNIT_ASSERT(x.back () == 2);
	}
	
	void test_back_1 () {
		C x;
		x.push_back (1);
		x.push_front (1);
		x.push_back (2);
		x.push_front (2);
		x.back () = 0;
		CPPUNIT_ASSERT(x.back () == 0);
	}
	
	void test_back_2 () { // back after pop
		C x;
		x.push_back (1);
		x.push_front (1);
		x.push_back (2);
		x.push_front (2);
		x.pop_back ();
		CPPUNIT_ASSERT(x.back () == 1);
	}
	
	//const
	void test_back_3 () {
		const C x (2, 2);
		CPPUNIT_ASSERT(x.back () == 2);
	}
	
	// -----
	// erase
	// -----
	
	void test_erase () {
		C x (1);
		auto it = x.begin ();
		x.erase (it);
		CPPUNIT_ASSERT(x.size () == 0);
	}
	
	void test_erase_1 () {
		C x (3, 5);
		int y [] = {5, 5};
		auto it = x.begin ();
		++it;
		x.erase (it);
		CPPUNIT_ASSERT(x.size () == 2);
		CPPUNIT_ASSERT(std::equal (x.begin (), x.end (), y));
	}
	
	// -----
	// empty
	// -----
	
	void test_empty () {
		C x;
		CPPUNIT_ASSERT(x.empty ());
	}
	
	void test_empty_1 () {
		C x (5);
		CPPUNIT_ASSERT(!x.empty ());
	}
	
	void test_empty_2 () {
		C x (2);
		x.pop_back ();
		x.pop_front ();
		CPPUNIT_ASSERT(x.empty ());
	}
	
	// -----
	// clear
	// -----
	
	void test_clear () {
		C x;
		CPPUNIT_ASSERT(x.empty ());
		x.clear ();
		CPPUNIT_ASSERT(x.empty ());
	}
	
	void test_clear_1 () {
		C x (10, 2);
		CPPUNIT_ASSERT(x.size () == 10);
		x.clear ();
		CPPUNIT_ASSERT(x.size () == 0);
		CPPUNIT_ASSERT(x.empty ());
	}
	
	// -- 
	// at
	// --
	
	void test_at () {
		C x;
		try {
			x.at (0);
			CPPUNIT_ASSERT(false);
		}
		catch (std::out_of_range& e) {
			CPPUNIT_ASSERT(std::string(e.what ()) == "deque::_M_range_check");
		}
	}
	
	void test_at_1 () {
		C x (10, 3);
		try {
			CPPUNIT_ASSERT(x.at (3) == 3);
			CPPUNIT_ASSERT(x.at (0) == 3);
		}
		catch (std::out_of_range& e) {
			CPPUNIT_ASSERT(false);
		}
	}
	
	void test_at_2 () {
		C x (10, 3);
		x.at (0) = 1;
		try {
			CPPUNIT_ASSERT(x.at (3) == 3);
			CPPUNIT_ASSERT(x.at (0) == 1);
		}
		catch (std::out_of_range& e) {
			CPPUNIT_ASSERT(false);
		}
	}
	
	//const
	void test_at_3 () {
		const C x (10, 3);
		try {
			CPPUNIT_ASSERT(x.at (4) == 3);
		}
		catch (std::out_of_range& e) {
			CPPUNIT_ASSERT(false);
		}
	}
	
	// ----
	// swap
	// ----
	
	void test_swap () {
		C x (5, 2);
		C y (10, 3);
		x.swap (y);
		CPPUNIT_ASSERT(y.size () == 5);
		CPPUNIT_ASSERT(x.size () == 10);
		for( auto it : x) {
			CPPUNIT_ASSERT(it == 3);
		}
		for (auto it : y) {
			CPPUNIT_ASSERT(it == 2);
		}
	}
	
	void test_swap_1() {
		C x (5, 2);
		C y (x);
		x.swap (y);
		CPPUNIT_ASSERT(std::equal(x.begin (), x.end (), y.begin ()));
	}
	
	
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
    CPPUNIT_TEST(test_size);
	CPPUNIT_TEST(test_size_1);
	CPPUNIT_TEST(test_size_2);
	
	CPPUNIT_TEST(test_resize);
/*	CPPUNIT_TEST(test_resize_1);
	CPPUNIT_TEST(test_resize_2);
	CPPUNIT_TEST(test_resize_3);
	
	CPPUNIT_TEST(test_index);
	CPPUNIT_TEST(test_index_1);
	CPPUNIT_TEST(test_index_2);
	
	CPPUNIT_TEST(test_begin);
	CPPUNIT_TEST(test_begin_1);
	CPPUNIT_TEST(test_begin_2);
	CPPUNIT_TEST(test_end);
	CPPUNIT_TEST(test_end_1);
	CPPUNIT_TEST(test_end_2);
	
	CPPUNIT_TEST(test_push_front);
	CPPUNIT_TEST(test_push_front_1);
	CPPUNIT_TEST(test_push_front_2);
	CPPUNIT_TEST(test_push_back);
	CPPUNIT_TEST(test_push_back_1);
	CPPUNIT_TEST(test_push_back_2);
    
	CPPUNIT_TEST(test_pop_back);
	CPPUNIT_TEST(test_pop_back_1);
	CPPUNIT_TEST(test_pop_back_2);
	CPPUNIT_TEST(test_pop_front);
	CPPUNIT_TEST(test_pop_front_1);
	CPPUNIT_TEST(test_pop_front_2);

	CPPUNIT_TEST(test_insert);
	CPPUNIT_TEST(test_insert_1);
	CPPUNIT_TEST(test_insert_2);
	
	CPPUNIT_TEST(test_front);
	CPPUNIT_TEST(test_front_1);
	CPPUNIT_TEST(test_back);
	CPPUNIT_TEST(test_back_1);
	CPPUNIT_TEST(test_back_2);
	CPPUNIT_TEST(test_back_3);
	
	CPPUNIT_TEST(test_erase);
	CPPUNIT_TEST(test_erase_1);
	
	CPPUNIT_TEST(test_empty);
	CPPUNIT_TEST(test_empty_1);
	CPPUNIT_TEST(test_empty_2);
	
	CPPUNIT_TEST(test_clear);
	CPPUNIT_TEST(test_clear_1);
	
	CPPUNIT_TEST(test_at);
	CPPUNIT_TEST(test_at_1);
	CPPUNIT_TEST(test_at_2);
	CPPUNIT_TEST(test_at_3);
	
	CPPUNIT_TEST(test_swap);
	CPPUNIT_TEST(test_swap_1);
*/	
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
