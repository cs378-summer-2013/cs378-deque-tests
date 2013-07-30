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

#include "gtest/gtest.h"

#include "Deque.h"


TEST(MyDequeTest, Constructor1) {
	MyDeque<int> a;
	ASSERT_EQ(a.size(), 0);
	ASSERT_EQ(a.begin(), a.end()); }

TEST(MyDequeTest, Constructor2) {
	MyDeque<int> a(9,1);
	ASSERT_EQ(a.size(),9);
	ASSERT_EQ(a.begin() + 9, a.end());
	ASSERT_EQ(*(a.begin()), 1); }

TEST(MyDequeTest, Constructor3) {
	MyDeque<int> a(10,1);
	ASSERT_EQ(a.size(),10);
	ASSERT_EQ(a.begin() + 10, a.end());
	ASSERT_EQ(*(a.begin()), 1); }

TEST(MyDequeTest, Constructor4) {
	MyDeque<int> a(11,1);
	ASSERT_EQ(a.size(),11);
	ASSERT_EQ(a.begin() + 11, a.end());
	ASSERT_EQ(*(a.begin()), 1); }

TEST(MyDequeTest, Constructor5) {
	MyDeque<int> a(10000,1);
	ASSERT_EQ(a.size(),10000);
	ASSERT_EQ(a.begin() + 10000, a.end());
	ASSERT_EQ(*(a.begin()), 1); }

TEST(MyDequeTest, Destructor1) {
	MyDeque<int> a;
	a.~MyDeque(); }

TEST(MyDequeTest, Destructor2) {
	MyDeque<int> a(9,1);
	a.~MyDeque(); }

TEST(MyDequeTest, Destructor3) {
	MyDeque<int> a(10,1);
	a.~MyDeque(); }

TEST(MyDequeTest, Destructor4) {
	MyDeque<int> a(11,1);
	a.~MyDeque(); }

TEST(MyDequeTest, begin1) {
	MyDeque<int> a;
	a.push_back(1);
	ASSERT_EQ(*a.begin(), 1);
	ASSERT_EQ(a.begin(), a.end() - 1); }

TEST(MyDequeTest, begin2) {
	MyDeque<int> a(100,11521);
	ASSERT_EQ(*a.begin(), 11521);
	ASSERT_EQ(a.begin() + 100, a.end()); }

TEST(MyDequeTest, begin3) {
	MyDeque<int> a(14124,12);
	ASSERT_EQ(*a.begin(), 12);
	ASSERT_EQ(a.begin(), a.end() - 14124); }

TEST(MyDequeTest, end1) {
	MyDeque<int> a;
	a.push_back(1);
	ASSERT_EQ(*(a.end() - 1), 1);
	ASSERT_EQ(a.begin(), a.end() - 1); }

TEST(MyDequeTest, end2) {
	MyDeque<int> a(10,1);
	a.push_back(2);
	ASSERT_EQ(*(a.end() - 1), 2);
	ASSERT_EQ(a.begin() + 11, a.end()); }

TEST(MyDequeTest, end3) {
	MyDeque<int> a(19080,1);
	a.push_back(2);
	ASSERT_EQ(*(a.end() - 1), 2);
	ASSERT_EQ(a.begin() + 19081, a.end()); }

TEST(MyDequeTest, size1) {
	MyDeque<int> a;
	ASSERT_EQ(a.size(), 0); }

TEST(MyDequeTest, size2) {
	MyDeque<int> a(9,1);
	ASSERT_EQ(a.size(), 9); }

TEST(MyDequeTest, size3) {
	MyDeque<int> a(10,1);
	ASSERT_EQ(a.size(), 10); }

TEST(MyDequeTest, size4) {
	MyDeque<int> a(11,1);
	a.pop_back();
	ASSERT_EQ(a.size(), 10); }

TEST(MyDequeTest, size5) {
	MyDeque<int> a(10,1);
	a.push_back(1);
	ASSERT_EQ(a.size(), 11); }

TEST(MyDequeTest, resize1) {
	MyDeque<int> a;
	a.resize(1);
	ASSERT_EQ(a.size(), 1);
	ASSERT_EQ(*a.begin(), 0); }

TEST(MyDequeTest, resize2) {
	MyDeque<int> a(10,1);
	a.resize(11);
	ASSERT_EQ(a.size(), 11);
	ASSERT_EQ(*--a.end(), 0); }

TEST(MyDequeTest, resize3) {
	MyDeque<int> a(11,1);
	a.resize(10);
	ASSERT_EQ(a.size(), 10);
	ASSERT_EQ(*--a.end(), 1); }

TEST(MyDequeTest, empty1) {
	MyDeque<int> a;
	ASSERT_EQ(a.size(), 0);
	ASSERT_TRUE(a.empty()); }

TEST(MyDequeTest, empty2) {
	MyDeque<int> a;
	a.push_back(1);
	ASSERT_EQ(a.size(), 1);
	ASSERT_TRUE(!a.empty()); }

TEST(MyDequeTest, empty3) {
	MyDeque<int> a(1,1);
	a.pop_back();
	ASSERT_EQ(a.size(), 0);
	ASSERT_TRUE(a.empty()); }

TEST(MyDequeTest, index1) {
	MyDeque<int> a(10,1);
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	ASSERT_EQ(a[9], 1);
	ASSERT_EQ(a[10], 10);
	ASSERT_EQ(a[11], 11);
	ASSERT_EQ(a[12], 12);}

TEST(MyDequeTest, index2) {
	MyDeque<int> a;
	for(int i = 0; i < 20; ++i)
		a.push_back(i);
	ASSERT_EQ(a[9], 9);
	ASSERT_EQ(a[10], 10);
	ASSERT_EQ(a[11], 11);
	ASSERT_EQ(a[19], 19); }

TEST(MyDequeTest, index3) {
	MyDeque<int> a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	ASSERT_EQ(a[0], 0);
	ASSERT_EQ(a[1], 1);
	ASSERT_EQ(a[2], 2); }

TEST(MyDequeTest, at1) {
	MyDeque<int> a(10,1);
	ASSERT_EQ(a[9], 1); }

TEST(MyDequeTest, at2) {
	MyDeque<int> a(10,1);
	a.push_back(1);
	ASSERT_EQ(a[10], 1); }

TEST(MyDequeTest, at3) {
	MyDeque<int> a(11,10);
	a.pop_back();
	ASSERT_EQ(*--a.end(), 10); }

TEST(MyDequeTest, front1) {
	MyDeque<int> a(20,1);
	a.push_front(10);
	ASSERT_EQ(a.front(), 10); }

TEST(MyDequeTest, front2) {
	MyDeque<int> a;
	a.push_front(10);
	ASSERT_EQ(a.front(), 10); }

TEST(MyDequeTest, front3) {
	MyDeque<int> a(100,1);
	a.push_front(10);
	ASSERT_EQ(a.front(), 10); }

TEST(MyDequeTest, back1) {
	MyDeque<int> a(20,1);
	a.push_back(10);
	ASSERT_EQ(a.back(), 10); }

TEST(MyDequeTest, back2) {
	MyDeque<int> a;
	a.push_back(10);
	ASSERT_EQ(a.back(), 10); }

TEST(MyDequeTest, back3) {
	MyDeque<int> a(1,1);
	a.push_back(10);
	ASSERT_EQ(a.back(), 10); }

TEST(MyDequeTest, push_back1) {
	MyDeque<int> a(1,1);
	a.push_back(2);
	ASSERT_EQ(*a.begin(), 1);
	ASSERT_EQ(*a.begin() + 1, 2);}

TEST(MyDequeTest, push_back2) {
	MyDeque<int> a(1,1);
	a.push_back(10421);
	ASSERT_EQ(*a.begin(), 1);
	ASSERT_EQ(*(a.begin() + 1), 10421);}

TEST(MyDequeTest, push_back3) {
	MyDeque<int> a;
	a.push_back(10421);
	ASSERT_EQ(*a.begin(), 10421);}

TEST(MyDequeTest, push_front1) {
	MyDeque<int> a(20,1);
	a.push_front(2);
	ASSERT_EQ(*a.begin(), 2);
	ASSERT_EQ(*(a.begin() + 1), 1);}

TEST(MyDequeTest, push_front2) {
	MyDeque<int> a(20,1);
	a.push_front(10421);
	ASSERT_EQ(*(a.begin() + 1), 1);
	ASSERT_EQ(*a.begin(), 10421);}

TEST(MyDequeTest, push_front3) {
	MyDeque<int> a;
	a.push_front(10421);
	ASSERT_EQ(*a.begin(), 10421);}

TEST(MyDequeTest, insert1) {
	MyDeque<int> a(100,1);
	a.insert(a.begin() + 50, 173);
	ASSERT_EQ(*(a.begin() + 50), 173);}

TEST(MyDequeTest, insert2) {
	MyDeque<int> a(100,1);
	a.insert(a.begin() , 173);
	ASSERT_EQ(*(a.begin()), 173);}

TEST(MyDequeTest, insert3) {
	MyDeque<int> a(100,1);
	a.insert(a.begin() + 70, 173);
	ASSERT_EQ(*(a.begin() + 70), 173);}

TEST(MyDequeTest, erase1) {
	MyDeque<int> a(100,1);
	a.insert(a.begin() + 50, 173);
	a.erase(a.begin() + 50);
	ASSERT_EQ(*(a.begin() + 50), 1);}

TEST(MyDequeTest, erase2) {
	MyDeque<int> a(100,1);
	a.erase(a.begin() + 50);
	ASSERT_EQ(a.size(), 99);}

TEST(MyDequeTest, erase3) {
	MyDeque<int> a(100,1);
	a.insert(a.begin() + 70, 173);
	a.erase(a.begin() + 70);
	ASSERT_EQ(*(a.begin() + 70), 1);}

TEST(MyDequeTest, swap1) {
	MyDeque<int> a(100,1);
	MyDeque<int> b(1,100);
	a.swap(b);
	ASSERT_EQ(a.size(), 1); 
	ASSERT_EQ(b.size(), 100);}

TEST(MyDequeTest, swap2) {
	MyDeque<int> a(100,1);
	MyDeque<int> b(1,100);
	a.push_back(13);
	b.push_back(31);
	a.swap(b);
	ASSERT_EQ(a.size(), 2); 
	ASSERT_EQ(b.size(), 101);
	ASSERT_EQ(a.back(), 31);
	ASSERT_EQ(b.back(), 13);}

TEST(MyDequeTest, clear1) {
	MyDeque<int> a(100,1);
	a.clear();
	ASSERT_EQ(a.size(), 0); }

TEST(MyDequeTest, clear2) {
	MyDeque<int> a(100,1);
	a.clear();
	a.push_back(1);
	ASSERT_EQ(a.size(), 1); }

TEST(MyDequeTest, clear3) {
	MyDeque<int> a;
	a.clear();
	ASSERT_EQ(a.size(), 0); }

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS(); }