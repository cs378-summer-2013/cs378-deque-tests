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
#include <iostream>

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
        
     // -----
     // iterator_begin
     // -----
    
    void test_iterator_begin() {
        C x(1,4);
  typename C::iterator b = x.begin();
	CPPUNIT_ASSERT(x.size() == 1);
	CPPUNIT_ASSERT(*b == 4);}
	    
     // -----
     // push_back
     // -----
	
    void test_push_back() {
        C x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	typename C::iterator b = x.begin();
	CPPUNIT_ASSERT(x.size() == 3);
	CPPUNIT_ASSERT(*b == 1);
	CPPUNIT_ASSERT(*b+1 == 2);
        CPPUNIT_ASSERT(*b+2 == 3);}
        
    void test_push_back2() {
        C x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	x.push_back(4);
	x.push_back(5);
	x.push_back(6);
	x.push_back(7);
	x.push_back(8);
	x.push_back(9);
	x.push_back(10);
	x.push_back(11);
	x.push_back(12);
	x.push_back(13);
	x.push_back(14);
	x.push_back(15);
	typename C::iterator b = x.begin();
	CPPUNIT_ASSERT(x.size() == 15);
        CPPUNIT_ASSERT(*(b+14) == 15);}
        
        
	
        
     // -----
     // iterator_end
     // -----
	
    void test_iterator_end() {
        C x(2,5);
	x.push_back(4);
	typename C::iterator b = x.begin();
	typename C::iterator e = x.end()-1;
	CPPUNIT_ASSERT(x.size() == 3);
	CPPUNIT_ASSERT(*b == 5);
	CPPUNIT_ASSERT(*e == 4);}
	
    void test_iterator_plusplus() {
        C x(3,2);
	typename C::iterator b = x.begin();
	typename C::iterator e = x.end();
        CPPUNIT_ASSERT(b!=e);
	++b;
	++b;
	++b;
	CPPUNIT_ASSERT(b == e);}
	
	void test_iterator_minusminus() {
        C x(3,2);
	typename C::iterator b = x.begin();
	typename C::iterator e = x.end();
        CPPUNIT_ASSERT(b!=e);
	--e;
	--e;
	--e;
	CPPUNIT_ASSERT(b == e);}
	
     // -----
     // iterator_traversal_with_pushback
     // -----
     
     void test_iterator_traversal_with_pushback() {
	C x;
	x.push_back(3);
	typename C::iterator       b = x.begin();
	typename C::iterator e = x.end();
	CPPUNIT_ASSERT(x.size() == 1);
	++b;
	CPPUNIT_ASSERT(b == e);
	--b;
	CPPUNIT_ASSERT(*b == 3);
	++b;
        CPPUNIT_ASSERT(b == e);}
        
     // -----
     // resize
     // -----
	
    void test_resize() {
	C x(2,0);
	CPPUNIT_ASSERT(x.size() == 2);
	x.resize(10,0);
	CPPUNIT_ASSERT(x.size() == 10);}
	
     // -----
     // clear
     // -----
	
    void test_clear() {
	C x(24,4);
	CPPUNIT_ASSERT(!x.empty());
	x.clear();
	CPPUNIT_ASSERT(x.empty());}
	
     // -----
     // swap
     // -----
	
    void test_swap() {
	C x(1,1);
	C y(2,2);
	CPPUNIT_ASSERT(x != y);
	typename C::iterator xe = x.end()-1;
	typename C::iterator ye = y.end()-1;
	CPPUNIT_ASSERT(x.size() == 1);
	CPPUNIT_ASSERT(y.size() == 2);
	CPPUNIT_ASSERT(*xe == 1);
	CPPUNIT_ASSERT(*ye == 2);
	x.push_back(66);
	xe = x.end()-1;
	y.push_back(22);
	ye = y.end()-1;
	CPPUNIT_ASSERT(x.size() == 2);
	CPPUNIT_ASSERT(y.size() == 3);
	x.swap(y);
	xe = x.end()-1;
	ye = y.end()-1;
	CPPUNIT_ASSERT(*xe == 22);
	CPPUNIT_ASSERT(*ye == 66);
	CPPUNIT_ASSERT(x.size() == 3);
	CPPUNIT_ASSERT(y.size() == 2);}
	
     // -----
     // iterator_plus_equals
     // -----
        
    void test_iterator_plus_equals() {
        C x(9,7);
	typename C::iterator b = x.begin();
	typename C::iterator e = x.end();
	CPPUNIT_ASSERT(*b == 7);
	x.push_front(8);
	b = x.begin();
	CPPUNIT_ASSERT(*b == 8);
	x.push_back(9);
	e = x.end()-1;
	CPPUNIT_ASSERT(x.size() == 11);
	b += x.size()-1;
	CPPUNIT_ASSERT(*b == 9);
	CPPUNIT_ASSERT(b == e);}
	
     // -----
     // iterator_minus_equals
     // -----
	
    void test_iterator_minus_equals() {
        C x(9,7);
	typename C::iterator b = x.begin();
	typename C::iterator e = x.end();
	typename C::iterator y;
	CPPUNIT_ASSERT(*b == 7);
	x.push_front(8);
	b = x.begin();
	CPPUNIT_ASSERT(*b == 8);
	x.push_back(11);
	e = x.end();
	y = e - 1;
	CPPUNIT_ASSERT(x.size() == 11);
	e -= *y;
	CPPUNIT_ASSERT(*e == 8);
	CPPUNIT_ASSERT(b == e);}
	
     // -----
     // pop_back
     // -----
	
    void test_pop_back() {
        C x(2,2);
	x.push_back(3);
	typename C::iterator b = x.begin();
	typename C::iterator e = x.end();
	CPPUNIT_ASSERT(x.size() == 3);
	CPPUNIT_ASSERT(*b == 2);
	--e;
	CPPUNIT_ASSERT(*e == 3);
	x.pop_back();
	e = x.end();
	--e;
	CPPUNIT_ASSERT(x.size() == 2);
	CPPUNIT_ASSERT(*e == 2);}
	
	     // -----
     // pop_front
     // -----	
     
    void test_pop_front() {
        C x;
	x.push_back(1);
	x.push_back(2);
	typename C::iterator b = x.begin();
	CPPUNIT_ASSERT(x.size() == 2);
	CPPUNIT_ASSERT(*b == 1);
	x.pop_front();
	b = x.begin();
	CPPUNIT_ASSERT(x.size() == 1);
	CPPUNIT_ASSERT(*b == 2);}
	
	
     // -----
     // push_front
     // -----
     
    void test_push_front() {
        C x;
	x.push_front(1);
	x.push_front(2);
	x.push_back(4);
	x.push_back(5);
	x.push_front(7);
	typename C::iterator b = x.begin();
	CPPUNIT_ASSERT(x.size() == 5);
	CPPUNIT_ASSERT(*b == 7);}
	

	

	


	

	
	
	

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
    CPPUNIT_TEST(test_size);
    CPPUNIT_TEST(test_iterator_begin);
    CPPUNIT_TEST(test_push_back);
    CPPUNIT_TEST(test_push_back2);
    CPPUNIT_TEST(test_iterator_end);
    CPPUNIT_TEST(test_iterator_plusplus);
    CPPUNIT_TEST(test_iterator_minusminus);
    CPPUNIT_TEST(test_iterator_traversal_with_pushback);
    CPPUNIT_TEST(test_resize);
    CPPUNIT_TEST(test_clear);
    CPPUNIT_TEST(test_swap);
    CPPUNIT_TEST(test_pop_back);
    CPPUNIT_TEST(test_pop_front);
    //CPPUNIT_TEST(test_iterator_plus_equals);
    //CPPUNIT_TEST(test_iterator_minus_equals);
    /*(CPPUNIT_TEST(test_push_front);*/
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
