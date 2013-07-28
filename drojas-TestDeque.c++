/*
To test the program:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

    % g++ -pedantic -std=c++0x -Wall Deque.h TestDeque.c++ -o TestDeque -lgtest -lpthread -lgtest_main

    % valgrind TestDeque > TestDeque.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "Deque.h"

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <deque>     // deque
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==
#include <memory>    // allocator
#include <cstdlib>   // rand

#include "gtest/gtest.h"

#include "Deque.h"

// ---------
// TestDeque
// ---------

typedef testing::Types<std::deque<int>, MyDeque<int> > deques;

template <typename T>
class gtestForDeque : public testing::Test {
    protected:
		typedef typename T::value_type type;
		typedef typename MyDeque<int>::iterator myIterator;

		T _d1, _d2;        	
		type _t1, _t2;

		


    		gtestForDeque() :
			_t1(), _t2() {
	        }

    		void setSame() {
			_d1 = T (100, 2);
			_d2 = T (100, 2);
    		}
    		
    		void defConstruction() {
			_d1 = T ();
			_d2 = T ();
    		}
    		
    		void pushBack() {
			for (int i=1; i<50; ++i) _d1.push_back(i);
			for (int i=1; i<50; ++i) _d2.push_back(i);
    		}
    		
    		void pushFront() {			
			for (int i=1; i<50; ++i) _d1.push_front(i);
			for (int i=1; i<50; ++i) _d2.push_front(i);
    		}
    		
    		void pushBack2() {
			for (int i=1; i<150; ++i) _d1.push_back(i);
			for (int i=1; i<150; ++i) _d2.push_back(i);
    		}
    		
    		void pushFront2() {			
			for (int i=1; i<150; ++i) _d1.push_front(i);
			for (int i=1; i<150; ++i) _d2.push_front(i);
    		}
    		
    		void printAll() {
			//_d1.print();
			//_d2.print();
    		}
    		
    		void resize() {
			_d1.resize(1000);
			_d2.resize(1000);
		}
		
		void resize2() {
			_d1.resize(1500);
			_d2.resize(1500);
		}
		
		void resize3() {
			_d1.resize(4500);
			_d2.resize(4500);
		}
		
		void clear() {
			_d1.clear();
			_d2.clear();
		}
		


};

TYPED_TEST_CASE(gtestForDeque, deques);

TYPED_TEST(gtestForDeque, constructor1){
    
    this->defConstruction();
    ASSERT_EQ(this->_d1.size(), this->_d2.size());}
    
TYPED_TEST(gtestForDeque, constructor2){
    
    this->setSame();
    ASSERT_EQ(this->_d1.size(), this->_d2.size());}
    
    
TYPED_TEST(gtestForDeque, pushFront1){
    this->setSame();
    this->resize();
    this->pushFront();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, pushFront2){
    this->setSame();
    this->resize();
    this->pushFront();
    this->clear();
    this->pushFront();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, pushFront3){
    this->setSame();
    this->resize();
    this->pushFront2();
    this->resize();
    this->pushFront2();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, pushFront4){
    this->setSame();
    this->resize();
    this->pushFront();
    this->pushBack2();
    this->resize2();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
    
TYPED_TEST(gtestForDeque, pushBack1){
    this->setSame();
    this->resize();
    this->pushBack();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
    
TYPED_TEST(gtestForDeque, pushBack2){
    this->setSame();
    this->resize2();
    this->pushBack2();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
  
TYPED_TEST(gtestForDeque, pushBack3){
    this->setSame();
    this->resize();
    this->pushBack();
    this->pushBack();
    this->pushBack();
    this->pushBack();
    this->pushBack();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
    
TYPED_TEST(gtestForDeque, pushBack4){
    this->setSame();
    this->resize();
    this->pushBack();
    this->pushBack2();
    this->resize2();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, resize1){
    this->setSame();
    this->resize2();
    this->pushBack();
    this->pushBack();
    this->pushFront();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, resize2){
    this->setSame();
    //this->resize();
    this->resize2();
    this->pushFront();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
    
TYPED_TEST(gtestForDeque, resize3){
    this->setSame();
    this->resize3();
    this->pushBack();
    this->pushFront();
    
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, resize4){
    this->setSame();
    this->clear();
    this->resize();
    this->pushFront();
    this->pushBack();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
    
TYPED_TEST(gtestForDeque, clear1){
    this->setSame();
    this->resize2();
    this->pushBack();
    this->pushFront();
    this->clear();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, clear2){
    this->setSame();
    this->resize2();
    this->pushBack();
    this->pushFront();
    this->pushFront();
    this->pushFront();
    this->pushFront();
    this->pushFront();
    this->pushFront();
    this->clear();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, clear3){
    this->setSame();
    this->resize2();
    this->pushBack();
    this->pushFront();
    this->pushBack();
    this->pushFront();
    this->pushBack();
    this->pushFront();
    this->pushBack();
    this->pushFront();
    this->clear();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    
TYPED_TEST(gtestForDeque, clear4){
    this->setSame();
    this->clear();
    
    ASSERT_TRUE(std::equal(this->_d1.begin(), this->_d1.end(), this->_d2.begin()));}
    





