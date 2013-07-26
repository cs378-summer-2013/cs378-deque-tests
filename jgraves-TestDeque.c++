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

using namespace std;

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
        
    void test_size1 () {
        const C x(5,0);
	CPPUNIT_ASSERT(x.size() == 5);}

    void test_size2 () {
        const C x(4,0);
	CPPUNIT_ASSERT(x.size() == 4);}
	
	
    void test_size3 () { 
	C x(13, 7);
	CPPUNIT_ASSERT(x.size() == 13);
    }
    
    void test_brackets() {
        C x(5,1);
	for (int i = 0; i < 5; i++) {
	 CPPUNIT_ASSERT(x[i] == 1); 
	}
    }
    
    void test_brackets1() {
        C x(4,2);
	for (int i = 0; i < 4; i++) {
	  CPPUNIT_ASSERT(x[i] == 2); 
	}
    }
    
    void test_brackets2() {
        C x(13,7);
	for (int i = 0; i < 13; i++) {
	  CPPUNIT_ASSERT(x[i] == 7); 
	}
    }
    
    void test_at() {
        C x(5,1);
	for (int i = 0; i < 5; i++) {
	 CPPUNIT_ASSERT(x.at(i) == 1); 
	}
    }
    
    void test_at1() {
        C x(4,2);
	for (int i = 0; i < 4; i++) {
	  CPPUNIT_ASSERT(x.at(i) == 2); 
	}
    }
    
    void test_at2() {
        C x(13,7);
	for (int i = 0; i < 13; i++) {
	  CPPUNIT_ASSERT(x.at(i) == 7); 
	}
    }
    
    void test_front() {
      C x(4, 3);
      CPPUNIT_ASSERT(x.front() == 3);
    }
    
    void test_front1() {
      C x(5, 2);
      CPPUNIT_ASSERT(x.front() == 2);
    }
    
    void test_back() {
      C x(4, 3);
      CPPUNIT_ASSERT(x.back() == 3);
    }
    
    void test_back1() {
      C x(5, 4);
      CPPUNIT_ASSERT(x.back() == 4);
    }
    
    void test_back2() {
      C x(7, 5);
      CPPUNIT_ASSERT(x.back() == 5);
    }
    
    void test_push_front() {
	C x(4, 1);
	x.push_front(2);
	CPPUNIT_ASSERT(x.front() == 2);
    }
    
    void test_push_front1() {
	C x(5, 3);
	x.push_front(6);
	CPPUNIT_ASSERT(x.front() == 6);
    }
    void test_push_front2() {
	C x(6, 3);
	x.push_front(6);
	CPPUNIT_ASSERT(x.front() == 6);
    }
    
    void test_push_front3() {
	C x;
	x.push_front(6);
	CPPUNIT_ASSERT(x.front() == 6);
    }
    
     void test_push_front4() {
	C x;
	x.push_front(5);
	x.push_front(4);
	x.push_front(3);
	x.push_front(2);
	x.push_front(1);
	for (int i = 0 ; i < 5; i++ ) {
	  cout << "Testing is x[" << i << "] == " << i+1 << endl;
	  cout << "x[" << i << "] ? " << i  << endl;
	  CPPUNIT_ASSERT(x[i] == i+1);
	}
    }
    
    void test_push_front5() {
	C x;
	for (int i = 19 ; i >= 0; i-- ) {
	    x.push_front(i);
	    CPPUNIT_ASSERT(x.front() == i);
	}
	for (int i = 0 ; i < 20; i++ ) {
	  cout << "Testing is x[" << i << "] == " << i << endl;
	  cout << "x[" << i << "] ? " << i  << endl;
	  CPPUNIT_ASSERT(x[i] == i);
	}
    }
    
    void test_push_back() {
	C x(4, 2);
	x.push_back(1);
	CPPUNIT_ASSERT(x[4] == 1);
      
    }
    
    void test_push_back1() {
	C x(5, 3);
	x.push_back(4);
	CPPUNIT_ASSERT(x[5] == 4);
      
    }
    
    void test_push_back2() {
	C x(6, 2);
	x.push_back(1);
	CPPUNIT_ASSERT(x.back() == 1);
    }
    
    void test_push_back3() {
	C x;
	x.push_back(1);
	CPPUNIT_ASSERT(x.back() == 1);
    }
    
    void test_push_back4() {
	C x;
	x.push_back(4);
	CPPUNIT_ASSERT(x[0] == 4);
      
    }
    
    void test_pop_front() {
	C x(4, 5);
	x.pop_front();
	CPPUNIT_ASSERT(x.size() ==3);
	CPPUNIT_ASSERT(x.front() == 5);
    }
    
     void test_pop_front1() {
	C x(4, 5);
	x.push_front(6);
	x.push_front(7);
	x.pop_front();
	CPPUNIT_ASSERT(x.size() == 5);
	CPPUNIT_ASSERT(x.front() == 6);
    }
    
    void test_pop_front2() {
	C x(1, 5);
	x.push_front(2);
	x.pop_front();
	CPPUNIT_ASSERT(x.size() == 1);
	CPPUNIT_ASSERT(x.front() == 5);
    }
    
    void test_pop_front3() {
	C x(5, 8);
	x.pop_front();
	CPPUNIT_ASSERT(x.size() == 4);
	CPPUNIT_ASSERT(x.front() == 8);
    }
    
    void test_clear() {
	C x(5,8);
	CPPUNIT_ASSERT(x.size() == 5);
	x.clear();
	CPPUNIT_ASSERT(x.size() == 0);
    }
    
    void test_clear1() {
	C x(5,8);
	CPPUNIT_ASSERT(x.size() == 5);
	x.clear();
	CPPUNIT_ASSERT(x.size() == 0);
	x.push_back(1);
	CPPUNIT_ASSERT(x.back() == 1);
 	CPPUNIT_ASSERT(x.front() == 1);
	CPPUNIT_ASSERT(x[0] == 1);
    }
    
    void test_clear2() {
	C x(5,8);
	CPPUNIT_ASSERT(x.size() == 5);
	x.clear();
	CPPUNIT_ASSERT(x.size() == 0);
	x.push_back(1);
	CPPUNIT_ASSERT(x.back() == 1);
 	CPPUNIT_ASSERT(x.front() == 1);
	CPPUNIT_ASSERT(x[0] == 1);
	x.push_front(1);
	CPPUNIT_ASSERT(x.front() == 1);
	x.push_front(2);
	x.clear();
	CPPUNIT_ASSERT(x.size() == 0);
    }
    
    
    void test_copy_constr() {
      C x(5,4);
      C y(x);
      CPPUNIT_ASSERT(y.size() == 5);
      for (int i = 0; i < 5; i++) {
	CPPUNIT_ASSERT(y[i] == 4);
      }
    }
    
    
    /** Need to test more thorougly */
    void test_end() {
      C x(3,2);
      cout << endl << "Testing end() " << endl;
      cout << "*(x.end()) = " << *(x.end()) << endl;
      cout << "x.back() = " << x.back() << endl;
      CPPUNIT_ASSERT(*(--x.end()) == x.back());
    }
    
    void test_end1() {
      C x(4,2);
      CPPUNIT_ASSERT(*(x.end()) == x.back());
    }
    
    void test_begin() {
      C x(3,2);
      CPPUNIT_ASSERT(*x.begin() == x.front());
      CPPUNIT_ASSERT(*x.begin() == x[0]);
    }
    
    void test_begin1() {
     C x;
     x.push_back(1);
     CPPUNIT_ASSERT(*(x.begin()) == x[0]); 
     CPPUNIT_ASSERT(*(x.begin()) == x.front());
    }
    
     void test_begin2() {
     C x;
     x.push_front(2);
     CPPUNIT_ASSERT(*x.begin() == x[0]); 
     CPPUNIT_ASSERT(*x.begin() == x.front());
    }
    
    void test_it_plusplus_op () {
      C x(3,2);
      CPPUNIT_ASSERT(*(x.begin()) == x[2]);
    }
    
    void test_pop_back() {
      C x(3,2);
      x.pop_back();
      CPPUNIT_ASSERT(x.size() == 2);
    }
    void test_pop_back1() {
      C x(3,2);
      x.push_back(1);
      x.push_back(3);
      x.push_back(4);
      CPPUNIT_ASSERT(x.back() == 4);
      x.pop_back();
      CPPUNIT_ASSERT(x.back() == 3);
      x.pop_back();
      CPPUNIT_ASSERT(x.back() == 1);
    }
    
    void test_swap() {
     C x(5, 3);
     C y(7, 4);
     x.swap(y);
     CPPUNIT_ASSERT(y.size() == 5);
     CPPUNIT_ASSERT(y[0] == 3);
     CPPUNIT_ASSERT(x.size() == 7);
     CPPUNIT_ASSERT(x[0] == 4);
    }
    
    void test_swap1() {
     C x(5, 3);
     C y;
     x.swap(y);
     CPPUNIT_ASSERT(y.size() == 5);
     CPPUNIT_ASSERT(y[0] == 3);
     CPPUNIT_ASSERT(x.size() == 0);
    }
    
    void test_it_minusminus() {
     C x(4,7);
     CPPUNIT_ASSERT(*(--x.end()) == 7);
    }
    
    void test_it_minusminus1() {
     C x(3,7);
     CPPUNIT_ASSERT(*(--(--x.end())) == 7);
    }
    
    void test_equalequal() {
     const C x(3,7);
     const C y(3,8);
     CPPUNIT_ASSERT(x != y);
    }
    
    void test_equalequal1() {
     const C x(3, 7);
     const C y(4, 7);
     CPPUNIT_ASSERT(x != y);
    }
    
    void test_equalequal2() {
     const C x(3,7);
     const C y(3,3);
     CPPUNIT_ASSERT(y != x);
    }
    
    void test_assignment() {
     C x(14, 5);
     C y = x;
     
     CPPUNIT_ASSERT(y.size() == 14);
     CPPUNIT_ASSERT(y.front() == 5);
     CPPUNIT_ASSERT(y.back() == 5);
    }
    
	/*
    void test_size2 () {
	const C x(5, 0);
	const C y(x);
	CPPUNIT_ASSERT(y.size() == 5);
    }
    
    void test_brackets1 () {
       const C x(5,1);
       CPPUNIT_ASSERT(x[2] == 1);
       CPPUNIT_ASSERT(x[0] == 1);
    }
    
    void test_brackets2() {
      cout << endl << "Testing Brackets "<< endl << endl;
      C x(5, 10);
      for (int i = 0; i < 5; i++ ) {
	  CPPUNIT_ASSERT(x[i] == 10);
      }
      cout << endl << "end testing brackets" << endl;
    }
    
    void test_push_front () {
       C x(5,1);
       x.push_front(2);
       CPPUNIT_ASSERT(x[0] == 2);
       CPPUNIT_ASSERT(x.size() == 6);
       CPPUNIT_ASSERT(x[5] == 1);
    }

    void test_push_front1 () {
       C x;
       x.push_front(1);
       CPPUNIT_ASSERT(x[0] == 1);
       CPPUNIT_ASSERT(x.size() == 1);
    }
    
    void test_push_front2 () {
       C x;
       x.push_front(1);
       CPPUNIT_ASSERT(x[0] == 1);
       CPPUNIT_ASSERT(x.size() == 1);
       x.push_front(2);
       CPPUNIT_ASSERT(x[0] == 2);
       CPPUNIT_ASSERT(x[1] == 1);
       CPPUNIT_ASSERT(x.size() == 2);       
    }
    
    void test_at() {
      C x;
      x.push_front(1);
      x.push_front(2);
      CPPUNIT_ASSERT(x.size() == 2);
      CPPUNIT_ASSERT(x.at(0) == 2);
    }
     
    void test_at1() {
      C x(5, 10);
      CPPUNIT_ASSERT(x.at(0) == 10);
      CPPUNIT_ASSERT(x.at(4) == 10);
    }
    
    void test_back () {
     C x(5, 11);
     CPPUNIT_ASSERT(x.size() == 5);
     CPPUNIT_ASSERT(x.back() == 11);
    }
    
    void test_back1 () {
     cout << endl << endl << "Testing back1 " << endl;
     C x;
     x.push_front(1);
     x.push_front(2);
     CPPUNIT_ASSERT(x.size() == 2);
     CPPUNIT_ASSERT(x[0] == 2);
     CPPUNIT_ASSERT(x[1] == 1);
     cout << "x.back() " << x.back() << endl;
     CPPUNIT_ASSERT(x.back() == 1);
    }
    
    void test_back2 () {
      C x;
      x.push_back(1);
      x.push_back(2);
      CPPUNIT_ASSERT(x.size() == 2);
      CPPUNIT_ASSERT(x[0] == 1);
      CPPUNIT_ASSERT(x[1] == 2);
      CPPUNIT_ASSERT(x.back() == 2);
    }
    
    void test_back3 () {
     C x;
     x.push_front(1);
     x.push_front(2);
     x.pop_back();
     CPPUNIT_ASSERT(x.size() == 1);
     CPPUNIT_ASSERT(x.back() == 2);
    }
    
    void test_back4() {
     C x;
     x.push_back(1);
     x.push_back(2);
     x.pop_back();
     CPPUNIT_ASSERT(x.back() == 1);
      
    }
    
    
    void test_pop_back() { 
     C x(5, 11);
     CPPUNIT_ASSERT(x.size() == 5);
     x.pop_back();
     CPPUNIT_ASSERT(x.size() == 4);
    }
    
    void test_pop_back1() { 
     C x;
     x.push_front(1);
     x.push_front(2);
     CPPUNIT_ASSERT(x[0] == 2);
     CPPUNIT_ASSERT(x[1] == 1);
     x.pop_back();
     CPPUNIT_ASSERT(x.size() == 1);
     CPPUNIT_ASSERT(x[0] == 2);
    }
    
    void test_pop_back2() { 
     C x;
     x.push_back(1);
     x.push_back(2);
     CPPUNIT_ASSERT(x[0] == 1);
     CPPUNIT_ASSERT(x[1] == 2);
     x.pop_back();
     CPPUNIT_ASSERT(x.size() == 1);
     CPPUNIT_ASSERT(x[0] == 1);
    }
    
    void test_pop_front() {
      C x(5, 1);
      CPPUNIT_ASSERT(x.size() == 5);
      x.pop_front();
      CPPUNIT_ASSERT(x.size() == 4);
    }
       
    void test_pop_front1 () {
      C x;
      x.push_back(1);
      CPPUNIT_ASSERT(x.size() == 1);
      x.push_back(2);
      CPPUNIT_ASSERT(x.size() == 2);
      x.pop_front();
      CPPUNIT_ASSERT(x.size() == 1);
      CPPUNIT_ASSERT(x[0] == 2);
    }
    
    void test_pop_front2 () {
      C x;
      x.push_front(1);
      CPPUNIT_ASSERT(x.size() == 1);
      x.push_front(2);
      CPPUNIT_ASSERT(x.size() == 2);
      x.pop_front();
      CPPUNIT_ASSERT(x.size() == 1);
      CPPUNIT_ASSERT(x[0] == 1);
    }
    
    void test_front () {
      C x(10, 6);
      CPPUNIT_ASSERT(x.size() == 10);
      CPPUNIT_ASSERT(x.front() == 6);
    }
    
    void test_front1 () {
     C x;
     x.push_front(1);
     CPPUNIT_ASSERT(x.size() == 1);
     CPPUNIT_ASSERT(x.front() == 1);
    }
    
    void test_front2() {
      cout << endl <<  "Testing front2 " << endl;
     C x;
     x.push_back(1);
     CPPUNIT_ASSERT(x.size() == 1);
     CPPUNIT_ASSERT(x.front() == 1);
    }
    
    void test_front3() {
     C x;
     x.push_front(1);
     x.push_front(2);
     x.pop_back();
     CPPUNIT_ASSERT(x.size() == 1);
     CPPUNIT_ASSERT(x.front() == 2);
    }
    
    void test_front4() {
      C x;
      x.push_back(1);
      x.push_back(2);
      x.pop_front();
      CPPUNIT_ASSERT(x.size() == 1);
      CPPUNIT_ASSERT(x.front() == 2);    
    } 
    
    
    void test_resize() {
      cout << endl <<"Testing resize" <<endl;
      C x;
      x.resize(5, 10);
      CPPUNIT_ASSERT(x.size() == 5);   
      cout << endl;
    }
    
    void test_resize1() {
     cout << endl <<"Testing resize1" <<endl;
      C x;
      int size = 5;
      x.resize(size, 10);
      CPPUNIT_ASSERT(x.size() == size);
      for (int i = 0; i < size; i++) {
	cout << "i = " << i << " " << x[i] << endl;
	CPPUNIT_ASSERT(x[i] == 10);
      }
      cout << endl;
    }
    
    
    void test_begin() {
     C x;
     x.push_back(1);
     CPPUNIT_ASSERT(*x.begin() == x[0]);
    }
    
    void test_begin1() {
     C x;
     x.push_front(1);
     CPPUNIT_ASSERT(*x.begin() == x[0]);
    }
    
    void test_begin2() {
      C x(4,9);
      CPPUNIT_ASSERT(x[0] == 9);
      CPPUNIT_ASSERT(x[3] == 9);
      cout << "*x.begin() " << *x.begin() << endl;
      cout << "x[0]" << x[0] << endl;
      CPPUNIT_ASSERT(*x.begin() == x[0]);
    }
    */
    // -----
    // suite
    // -----

     CPPUNIT_TEST_SUITE(TestDeque);
     CPPUNIT_TEST(test_size);
     CPPUNIT_TEST(test_size1);
     CPPUNIT_TEST(test_size2);
     CPPUNIT_TEST(test_size3);
     CPPUNIT_TEST(test_brackets);
     CPPUNIT_TEST(test_brackets1);
     CPPUNIT_TEST(test_brackets2);
     CPPUNIT_TEST(test_at);
     CPPUNIT_TEST(test_at1);
     CPPUNIT_TEST(test_at2);
     CPPUNIT_TEST(test_front);
     CPPUNIT_TEST(test_front1);
     CPPUNIT_TEST(test_back);
     CPPUNIT_TEST(test_back1);
     CPPUNIT_TEST(test_back2);
     CPPUNIT_TEST(test_push_front);
     CPPUNIT_TEST(test_push_front1);
     CPPUNIT_TEST(test_push_front2);
     CPPUNIT_TEST(test_push_front3);
     CPPUNIT_TEST(test_push_front4);
     CPPUNIT_TEST(test_push_front5);
     CPPUNIT_TEST(test_push_back);
     CPPUNIT_TEST(test_push_back1);
     CPPUNIT_TEST(test_push_back2);
     CPPUNIT_TEST(test_push_back3);
     CPPUNIT_TEST(test_push_back4);
     CPPUNIT_TEST(test_pop_front);
     CPPUNIT_TEST(test_pop_front1);
     CPPUNIT_TEST(test_pop_front2);
     CPPUNIT_TEST(test_pop_front3);
     CPPUNIT_TEST(test_clear);
     CPPUNIT_TEST(test_clear1);
     CPPUNIT_TEST(test_clear2);
     //CPPUNIT_TEST(test_end);
    // CPPUNIT_TEST(test_end1);
     CPPUNIT_TEST(test_begin);
     CPPUNIT_TEST(test_begin1);
     CPPUNIT_TEST(test_begin2);
     CPPUNIT_TEST(test_it_plusplus_op);
     CPPUNIT_TEST(test_copy_constr);
     CPPUNIT_TEST(test_pop_back);
     CPPUNIT_TEST(test_pop_back1);
     CPPUNIT_TEST(test_swap);
     CPPUNIT_TEST(test_swap1);
     CPPUNIT_TEST(test_it_minusminus);
     CPPUNIT_TEST(test_it_minusminus1);
     CPPUNIT_TEST(test_equalequal);
     CPPUNIT_TEST(test_equalequal1);
     CPPUNIT_TEST(test_equalequal2);
     CPPUNIT_TEST(test_assignment);
 
    /*
    CPPUNIT_TEST(test_size2);
    CPPUNIT_TEST(test_brackets1);
    CPPUNIT_TEST(test_brackets2);
    CPPUNIT_TEST(test_push_front);
    CPPUNIT_TEST(test_push_front1);
    CPPUNIT_TEST(test_push_front2);
    CPPUNIT_TEST(test_at);
    CPPUNIT_TEST(test_at1);
    CPPUNIT_TEST(test_back);
    CPPUNIT_TEST(test_back1);
    CPPUNIT_TEST(test_back2);
    CPPUNIT_TEST(test_back3);
    CPPUNIT_TEST(test_back4);
    CPPUNIT_TEST(test_pop_back);
    CPPUNIT_TEST(test_pop_back1);
    CPPUNIT_TEST(test_pop_back2);
    CPPUNIT_TEST(test_pop_front);
    CPPUNIT_TEST(test_pop_front1);
    CPPUNIT_TEST(test_pop_front2);
    CPPUNIT_TEST(test_front);
    CPPUNIT_TEST(test_front1);
    CPPUNIT_TEST(test_front2);
    CPPUNIT_TEST(test_front3);
    CPPUNIT_TEST(test_front4);
    CPPUNIT_TEST(test_resize);
    CPPUNIT_TEST(test_resize1);
    CPPUNIT_TEST(test_begin);
    CPPUNIT_TEST(test_begin1);
    CPPUNIT_TEST(test_begin2);
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