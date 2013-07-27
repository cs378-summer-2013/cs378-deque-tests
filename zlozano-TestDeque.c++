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

// make private stuff public
#define private public
#define protected public

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <deque>     // deque
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

/*
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner
*/

#include "Deque.h"

#include "gtest/gtest.h"	// Google test harness


// -----------------
// Google Test Suite
// -----------------

// -------------
// MyDeque Tests
// -------------

// ---------
// test_size
// ---------

TEST (MyDeque, Size1) {
	MyDeque<int> x;
	ASSERT_TRUE (x.size() == 0);
}

TEST (MyDeque, Size2) {
	MyDeque<int> x(20, 1);
	ASSERT_TRUE (x.size() == 20);
}

TEST (MyDeque, Size3) {
	MyDeque<int> x(1);
	ASSERT_TRUE (x.size() == 1);
}

// ---------------------
// test_fill_constructor
// ---------------------

TEST (MyDeque, FillConstructor1) {
	MyDeque<int> con (20, 5);
	ASSERT_TRUE (*(con.front_elem) == 5);
	ASSERT_TRUE (*(con.back_elem)  != 5);
	ASSERT_TRUE (con.container[0][4] != 5);
	ASSERT_TRUE (con.container[0][5] == 5);
	ASSERT_TRUE (con.container[1][5] == 5);
	ASSERT_TRUE (con.container[2][4] == 5);
	ASSERT_TRUE (con.container[2][5] != 5);
}

TEST (MyDeque, FillConstructor2) {
	MyDeque<int> con (9, 1);
	ASSERT_TRUE (*(con.front_elem) == 1);
	ASSERT_TRUE (*(con.back_elem)  != 1);
	ASSERT_TRUE (con.total_size == 9);
	ASSERT_TRUE (con.total_capacity == 10);
	ASSERT_TRUE (con.container[0][0] == 1);
	ASSERT_TRUE (con.container[0][9] != 1);
}

TEST (MyDeque, FillConstructor3) {
	MyDeque<int> con (1, 1);
	ASSERT_TRUE (*(con.front_elem) == 1);
	ASSERT_TRUE (*(con.back_elem)  != 1);
	ASSERT_TRUE (con.total_size == 1);
	ASSERT_TRUE (con.total_capacity == 10);
	ASSERT_TRUE (con.container[0][1] != 1);
	ASSERT_TRUE (con.container[0][4] == 1);
	ASSERT_TRUE (con.container[0][5] != 1);
}

// ---------------------
// test_copy_constructor
// ---------------------
TEST (MyDeque, CopyConstructor1) {
	MyDeque<int> con (20, 5);
	MyDeque<int> con2 (con);

	ASSERT_TRUE (con.front_elem != con2.front_elem);
	ASSERT_TRUE (*(con.front_elem) == *(con2.front_elem));
	ASSERT_TRUE (con.back_elem != con2.back_elem);
	ASSERT_TRUE (*(con.back_elem) == *(con2.back_elem));
}

TEST (MyDeque, CopyConstructor2) {
	MyDeque<int> con (9, 1);
	MyDeque<int> con2 (con);

	ASSERT_TRUE (con.front_elem != con2.front_elem);
	ASSERT_TRUE (*(con.front_elem) == *(con2.front_elem));
	ASSERT_TRUE (con.back_elem != con2.back_elem);
	ASSERT_TRUE (*(con.back_elem) == *(con2.back_elem));
}

TEST (MyDeque, CopyConstructor3) {
	MyDeque<int> con (1, 1);
	MyDeque<int> con2 (con);

	ASSERT_TRUE (con.front_elem != con2.front_elem);
	ASSERT_TRUE (*(con.front_elem) == *(con2.front_elem));
	ASSERT_TRUE (con.back_elem != con2.back_elem);
	ASSERT_TRUE (*(con.back_elem) == *(con2.back_elem));
}

// ---------------
// test_assignment
// ---------------

TEST (MyDeque, Assignment1) {
	MyDeque<int> con1 (5, 5);
	MyDeque<int> con2 = con1;

	ASSERT_TRUE (con1.size() == con2.size());
}

TEST (MyDeque, Assignment2) {
	MyDeque<int> con1;
	MyDeque<int> con2 = con1;

	ASSERT_TRUE (con1.size() == con2.size());
}

TEST (MyDeque, Assignment3) {
	MyDeque<int> con1 (5, 5);
	MyDeque<int> con2;

	con1 = con2;

	ASSERT_TRUE (con1.size() == con2.size());
}
// -------------
// test_equality
// -------------
TEST (MyDeque, Equality1) {
	MyDeque<int> con1 (1, 1);
	MyDeque<int> con2 (1, 1);
	ASSERT_TRUE (con1 == con2);
}

TEST (MyDeque, Equality2) {
	MyDeque<int> con1 (10, 1);
	MyDeque<int> con2 (20, 1);
	ASSERT_FALSE (con1 == con2);
}

TEST (MyDeque, Equality3) {
	MyDeque<int> con1 (20, 1);
	MyDeque<int> con2 (20, 2);
	ASSERT_FALSE (con1 == con2);
}

TEST (MyDeque, Equality4) {
	MyDeque<int> con1;
	MyDeque<int> con2;
	ASSERT_TRUE (con1 == con2);
}


// ----------------------------
// test_lexicographical_compare
// ----------------------------
TEST (MyDeque, Lexicographical1) {
	MyDeque<int> con1 (1, 1);
	MyDeque<int> con2 (1, 1);
	ASSERT_FALSE (con1 < con2);
}

TEST (MyDeque, Lexicograhpical2) {
	MyDeque<int> con1 (10, 1);
	MyDeque<int> con2 (20, 1);
	ASSERT_TRUE (con1 < con2);
}

TEST (MyDeque, Lexicographical3) {
	MyDeque<int> con1 (20, 1);
	MyDeque<int> con2 (20, 2);
	ASSERT_TRUE (con1 < con2);
}

// ---------------
// test_operator[]
// ---------------
TEST (MyDeque, Index1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1[0] == 5);
	ASSERT_TRUE (&con1[0] == &con1.container[con1.f_outeri][con1.f_inneri]);
}

TEST (MyDeque, Index2) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1[19] == 5);
	ASSERT_TRUE (&con1[19] == &con1.container[con1.b_outeri][con1.b_inneri - 1]);
}

TEST (MyDeque, Index3) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1[20] != 5);
	ASSERT_TRUE (&con1[20] == &con1.container[con1.b_outeri][con1.b_inneri]);
}

// -------
// test_at
// -------
TEST (MyDeque, At1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.at(0) == 5);
	ASSERT_TRUE (&con1.at(0) == &con1[0]);
	ASSERT_TRUE (&con1.at(0) == &con1.container[con1.f_outeri][con1.f_inneri]);
}

TEST (MyDeque, At2) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.at(19) == 5);
	ASSERT_TRUE (&con1.at(19) == &con1[19]);
	ASSERT_TRUE (&con1.at(19) == &con1.container[con1.b_outeri][con1.b_inneri - 1]);
}

TEST (MyDeque, At3) {
	MyDeque<int> con1 (20, 5);
	try {
		ASSERT_TRUE (con1.at(20) != 5);
		ASSERT_TRUE (false);
	}
	catch (...) {
		ASSERT_TRUE (true);	
	}
}

// ---------
// test_back
// ---------

TEST (MyDeque, Back1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.back() == 5);
	ASSERT_TRUE (&con1.back() == &con1.at(19)); }

TEST (MyDeque, Back2) {
	MyDeque<int> con1 (1, 5);
	ASSERT_TRUE (con1.back() == 5);
	ASSERT_TRUE (&con1.back() == &con1.at(0)); }

TEST (MyDeque, Back3) {
	MyDeque<int> con1 (5, 5);
	ASSERT_TRUE (con1.back() == 5);
	con1.back() = 9000000;
	ASSERT_TRUE (con1.back() == 9000000);
	ASSERT_TRUE (&con1.back() == &con1.at(4)); }

// ---------
// test_front
// ---------

TEST (MyDeque, Front1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.front() == 5);
	ASSERT_TRUE (&con1.front() == &con1.at(0)); }

TEST (MyDeque, Front2) {
	MyDeque<int> con1 (1, 5);
	ASSERT_TRUE (con1.front() == 5);
	ASSERT_TRUE (&con1.front() == &con1.at(0)); }

TEST (MyDeque, Front3) {
	MyDeque<int> con1 (5, 5);
	ASSERT_TRUE (con1.front() == 5);
	con1.front() = 9000000;
	ASSERT_TRUE (con1.front() == 9000000);
	ASSERT_TRUE (&con1.front() == &con1.at(0)); }

// ----------
// test_begin
// ----------

TEST (MyDeque, Begin1) {
	MyDeque<int> con1 (20, 5);
	MyDeque<int>::iterator iter = con1.begin();
	ASSERT_TRUE (*iter == 5);
	ASSERT_TRUE (&*iter == &con1[0]);
	ASSERT_TRUE (&*iter == &con1.front()); }

TEST (MyDeque, Begin2) {
	MyDeque<int> con1 (1, 5);
	MyDeque<int>::iterator iter = con1.begin();
	ASSERT_TRUE (*iter == 5);
	ASSERT_TRUE (&*iter == &con1[0]);
	ASSERT_TRUE (&*iter == &con1.front()); }

TEST (MyDeque, Begin3) {
	MyDeque<int> con1 (1, 5);
	MyDeque<int>::iterator iter = con1.begin();
	ASSERT_TRUE (*iter == 5);
	*iter = 789;
	ASSERT_TRUE (*iter == 789);
	ASSERT_TRUE (&*iter == &con1[0]);
	ASSERT_TRUE (&*iter == &con1.front()); }

// ----------
// test_end
// ----------

TEST (MyDeque, End1) {
	MyDeque<int> con1 (20, 5);
	MyDeque<int>::iterator iter = con1.end();
	--iter;
	ASSERT_TRUE (*iter == 5);
	ASSERT_TRUE (&*iter == &con1[19]);
	ASSERT_TRUE (&*iter == &con1.back()); }

TEST (MyDeque, End2) {
	MyDeque<int> con1 (1, 5);
	MyDeque<int>::iterator iter = con1.end();
	--iter;
	ASSERT_TRUE (*iter == 5);
	ASSERT_TRUE (&*iter == &con1[0]);
	ASSERT_TRUE (&*iter == &con1.back()); }

TEST (MyDeque, End3) {
	MyDeque<int> con1 (1, 5);
	MyDeque<int>::iterator iter = con1.end();
	--iter;
	ASSERT_TRUE (*iter == 5);
	*iter = 789;
	ASSERT_TRUE (*iter == 789);
	ASSERT_TRUE (&*iter == &con1[0]);
	ASSERT_TRUE (&*iter == &con1.back()); }

TEST (MyDeque, End4) {
	MyDeque<int> con1 (1, 5);
	MyDeque<int>::iterator iter_f = con1.begin();
	MyDeque<int>::iterator iter_b = con1.end();
	--iter_b;
	ASSERT_TRUE (*iter_f == 5);
	ASSERT_TRUE (*iter_b == 5);
	ASSERT_TRUE (iter_f == iter_b); 
	ASSERT_TRUE (&*iter_f == &*iter_b); }

// ----------
// test_erase
// ----------

TEST (MyDeque, Erase1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	MyDeque<int>::iterator pos = con1.end();
	con1.erase(pos-3);
	ASSERT_TRUE(con1.size() == 19);
	ASSERT_TRUE(con1[18] == 5); }

TEST (MyDeque, Erase2) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	MyDeque<int>::iterator pos = con1.begin();
	con1.erase(pos);
	ASSERT_TRUE(con1.size() == 19);
	ASSERT_TRUE(con1[0] == 5); 
}
TEST (MyDeque, Erase3) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	MyDeque<int>::iterator pos = con1.end();
	con1.erase(pos-1);
	ASSERT_TRUE(con1.size() == 19);
}


// -----------
// test_insert
// -----------

TEST (MyDeque, Insert1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	MyDeque<int>::iterator pos = con1.end();
	con1.insert(pos-3, 3);
	ASSERT_TRUE(con1.size() == 21);
	ASSERT_TRUE(con1[17] == 3); 
	ASSERT_TRUE(con1[20] == 5); }

TEST (MyDeque, Insert2) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	MyDeque<int>::iterator pos = con1.begin();
	con1.insert(pos, 3);
	ASSERT_TRUE(con1.size() == 21);
	ASSERT_TRUE(con1[0] == 3); 
	ASSERT_TRUE(con1[20] == 5); }

TEST (MyDeque, Insert3) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	MyDeque<int>::iterator pos = con1.end();
	con1.insert(pos-1, 3);
	ASSERT_TRUE(con1.size() == 21);
	ASSERT_TRUE(con1[19] == 3); 
	ASSERT_TRUE(con1[20] == 5); }

// -------------
// test_pop_back
// -------------

TEST (MyDeque, PopBack1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	con1.back() = 3;
	con1.pop_back();
	ASSERT_TRUE (con1.size() == 19);
	ASSERT_TRUE (con1.back() == 5); }

TEST (MyDeque, PopBack2) {
	MyDeque<int> con1 (10, 5);
	ASSERT_TRUE (con1.size() == 10);
	for (int i = 0; i < 10; ++i) {
		con1.pop_back();}
	ASSERT_TRUE(con1.size() == 0); }

TEST (MyDeque, PopBack3) {
	MyDeque<int> con1 (1, 5);
	ASSERT_TRUE (con1.size() == 1);
	con1.pop_back();
	ASSERT_TRUE (con1.size() == 0); }

// --------------
// test_pop_front
// --------------

TEST (MyDeque, PopFront1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	con1.front() = 3;
	con1.pop_front();
	ASSERT_TRUE (con1.size() == 19);
	ASSERT_TRUE (con1.front() == 5); }

TEST (MyDeque, PopFront2) {
	MyDeque<int> con1 (10, 5);
	ASSERT_TRUE (con1.size() == 10);
	for (int i = 0; i < 10; ++i) {
		con1.pop_front();}
	ASSERT_TRUE(con1.size() == 0); }

TEST (MyDeque, PopFront3) {
	MyDeque<int> con1 (1, 5);
	ASSERT_TRUE (con1.size() == 1);
	con1.pop_front();
	ASSERT_TRUE (con1.size() == 0); }

// --------------
// test_push_back
// --------------

TEST (MyDeque, PushBack1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	ASSERT_TRUE (con1.back() ==  5);
	con1.push_back(3);
	ASSERT_TRUE (con1.size() == 21);
	ASSERT_TRUE (con1.back() ==  3); }

TEST (MyDeque, PushBack2) {
	MyDeque<int> con1 (9, 5);
	ASSERT_TRUE (con1.size() == 9);
	ASSERT_TRUE (con1.back() ==  5);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	con1.push_back(3);
	ASSERT_TRUE (con1.size() == 20);
	ASSERT_TRUE (con1.back() ==  3); }

TEST (MyDeque, PushBack3) {
	MyDeque<int> con1;
	ASSERT_TRUE (con1.size() == 0);
	con1.push_back(3);
	ASSERT_TRUE (con1.size() == 1);
	ASSERT_TRUE (con1.back() == 3); }

// --------------
// test_push_front
// --------------

TEST (MyDeque, PushFront1) {
	MyDeque<int> con1 (20, 5);
	ASSERT_TRUE (con1.size() == 20);
	ASSERT_TRUE (con1.front() ==  5);
	con1.push_front(3);
	ASSERT_TRUE (con1.size() == 21);
	ASSERT_TRUE (con1.front() ==  3); }

TEST (MyDeque, PushFront2) {
	MyDeque<int> con1 (9, 5);
	ASSERT_TRUE (con1.size() == 9);
	ASSERT_TRUE (con1.front() ==  5);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	con1.push_front(3);
	ASSERT_TRUE (con1.size() == 20);
	ASSERT_TRUE (con1.front() ==  3); }

TEST (MyDeque, PushFront3) {
	MyDeque<int> con1;
	ASSERT_TRUE (con1.size() == 0);
	con1.push_front(3);
	ASSERT_TRUE (con1.size() == 1);
	ASSERT_TRUE (con1.front() == 3); }

// -----------
// test_resize
// -----------

TEST (MyDeque, Resize1) {
	MyDeque<int> con1 (10, 5);
	con1.resize(5);
	for (int i = 0; i < 5; ++i) {
		ASSERT_TRUE (con1[i] == 5);
	}

	ASSERT_TRUE (con1.size() == 5);
}

TEST (MyDeque, Resize2) {
	MyDeque<int> con1 (10, 5);
	con1.resize(15, 5);
	for (int i = 0; i < 15; ++i) {
		ASSERT_TRUE (con1[i] == 5);
	}

	ASSERT_TRUE (con1.size() == 15);
}

TEST (MyDeque, Resize3) {
	MyDeque<int> con1;
	con1.resize(20, 5);
	for (int i = 0; i < 20; ++i) {
		ASSERT_TRUE (con1[i] == 5);
	}

	ASSERT_TRUE (con1.size() == 20);
}

TEST (MyDeque, Resize4) {
	MyDeque<int> con1(10, 5);
	con1.resize(10);
	ASSERT_TRUE (con1.size() == 10);
}


// ----------
// test_clear
// ----------

TEST (MyDeque, Clear1) {
	MyDeque<int> con1;
	con1.clear();
	ASSERT_TRUE(con1.size() == 0);
}

TEST (MyDeque, Clear2) {
	MyDeque<int> con1 (9, 5);
	con1.clear();
	ASSERT_TRUE(con1.size() == 0);
}

TEST (MyDeque, Clear3) {
	MyDeque<int> con1 (100, 6);
	con1.clear();
	ASSERT_TRUE(con1.size() == 0);
}

// ---------
// test_swap
// ---------

TEST (MyDeque, Swap1) {
	MyDeque<int> con1(5,  5);
	MyDeque<int> con2(10, 3);
	ASSERT_TRUE (con1.size() ==  5);
	ASSERT_TRUE (con2.size() == 10);
	con1.swap(con2);
	ASSERT_TRUE (con2.size() ==  5);
	ASSERT_TRUE (con1.size() == 10);
}	

TEST (MyDeque, Swap2) {
	MyDeque<int> con1(5,  5);
	MyDeque<int> con2(10, 3);
	ASSERT_TRUE (con1.front() ==  5);
	ASSERT_TRUE (con2.front() ==  3);
	con1.swap(con2);
	ASSERT_TRUE (con2.front() ==  5);
	ASSERT_TRUE (con1.front() ==  3);
}	
// --------------
// Iterator Tests
// --------------

// -------------------------
// test_iterator_constructor
// -------------------------
TEST (Iterator, Constructor1) {
	MyDeque<int> md (5, 5);
	for (int i = 0; i < 5; ++i)
	{
		MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri + i);
		ASSERT_TRUE (*iter == 5);	
	}
}

TEST (Iterator, Constructor2) {
	MyDeque<int> md (1, -9);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (*iter == -9);
}

TEST (Iterator, Constructor3) {
	MyDeque<int> md (10, 9);
	MyDeque<int>::iterator iter(&md, 1, 0);
	ASSERT_TRUE (*iter == 9);
}

// -------------------------
// test_iterator_dereference
// -------------------------
TEST (Iterator, Dereference1) {
	MyDeque<int> md (4, 0);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (*iter == 0);
}

TEST (Iterator, Dereference2) {
	MyDeque<int> md (10, 9);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (*iter == 9);
}

TEST (Iterator, Dereference3) {
	MyDeque<int> md (10, 9);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri - 1);
	ASSERT_TRUE (*iter != 9);
}

TEST (Iterator, Dereference4) {
	MyDeque<int> md (3, 2);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	*iter = 56;
	ASSERT_TRUE (*iter != 2);
	ASSERT_TRUE (*iter == 56);
}

// -------------------
// test_iterator_equal
// -------------------
TEST (Iterator, Equality1) {
	MyDeque<int> md (3, 2);
	MyDeque<int>::iterator iter1(&md, md.f_outeri, md.f_inneri);
	MyDeque<int>::iterator iter2(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (iter1 == iter2);
}

TEST (Iterator, Equality2) {
	MyDeque<int> md1 (3, 2);
	MyDeque<int> md2 (3, 2);
	MyDeque<int>::iterator iter1(&md1, md1.f_outeri, md1.f_inneri);
	MyDeque<int>::iterator iter2(&md2, md2.f_outeri, md2.f_inneri);
	ASSERT_TRUE (iter1 != iter2);
}

TEST (Iterator, Equality3) {
	MyDeque<int> md (3, 2);
	MyDeque<int>::iterator iter1(&md, md.f_outeri, md.f_inneri);
	MyDeque<int>::iterator iter2(&md, md.f_outeri, md.f_inneri + 1);
	ASSERT_TRUE (iter1 != iter2);
}

// ----------------
// test_iterator_++
// ----------------
TEST (Iterator, Increment1) {
	MyDeque<int> md(5, 5);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	for (int i = 0; i < 5; ++i)
	{
		ASSERT_TRUE (*iter == 5);
		++iter;
	}
}

TEST (Iterator, Increment2) {
	MyDeque<int> md(5, 0);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri + 2);
	for (int i = 0; i < 3; ++i)
	{
		ASSERT_TRUE (*iter == 0);
		++iter;
	}
}

TEST (Iterator, Increment3) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	for (int i = 0; i < 30; ++i)
	{
		ASSERT_TRUE (*iter == 5);
		++iter;
	}
}

// ----------------
// test_iterator_--
// ----------------
TEST (Iterator, Decrement1) {
	MyDeque<int> md(5, 5);
	MyDeque<int>::iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	for (int i = 0; i < 5; ++i)
	{
		ASSERT_TRUE (*iter == 5);
		--iter;
	}
}

TEST (Iterator, Decrement2) {
	MyDeque<int> md(5, 0);
	MyDeque<int>::iterator iter(&md, md.b_outeri, md.b_inneri - 3);
	for (int i = 0; i < 2; ++i)
	{
		ASSERT_TRUE (*iter == 0);
		--iter;
	}
}

TEST (Iterator, Decrement3) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	for (int i = 0; i < 30; ++i)
	{
		ASSERT_TRUE (*iter == 5);
		--iter;
	}
}

// ----------------
// test_iterator_+=
// ----------------
TEST (Iterator, PlusEquals1) {
	MyDeque<int> md(5, 5);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	iter += 4;
	ASSERT_TRUE (*iter == 5);
}

TEST (Iterator, PlusEquals2) {
	MyDeque<int> md(5, 0);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	for (int i = 0; i < 5; ++i)
	{
		iter += 1;
		ASSERT_TRUE (*iter == 0);
	}
}

TEST (Iterator, PlusEquals3) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	iter += 15;
	ASSERT_TRUE (*iter == 5);
	iter += 5;
	ASSERT_TRUE (*iter == 5);
}

TEST (Iterator, PlusEquals4) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::iterator iter(&md, md.f_outeri + 1, md.f_inneri + 4);
	iter += -10;
	ASSERT_TRUE (*iter == 5);
}

// ----------------
// test_iterator_-=
// ----------------
TEST (Iterator, MinusEquals1) {
	MyDeque<int> md(5, 5);
	MyDeque<int>::iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	iter -= 4;
	ASSERT_TRUE (*iter == 5);
}

TEST (Iterator, MinusEquals2) {
	MyDeque<int> md(5, 0);
	MyDeque<int>::iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	for (int i = 0; i < 5; ++i)
	{
		iter -= 1;
		ASSERT_TRUE (*iter == 0);
	}
}

TEST (Iterator, MinusEquals3) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	iter -= 15;
	ASSERT_TRUE (*iter == 5);
	iter -= 5;
	ASSERT_TRUE (*iter == 5);
}

TEST (Iterator, MinusEquals4) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	iter -= -10;
	ASSERT_TRUE (*iter == 5);
}

// -------------------
// test_iterator_valid
// -------------------
TEST (Iterator, valid1) {
	MyDeque<int> md;
	MyDeque<int>::iterator iter(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (iter.valid());
}

TEST (Iterator, valid2) {
	MyDeque<int> md;
	MyDeque<int>::iterator iter(&md, 0, 0); // Won't let me construct invalid ones
	ASSERT_TRUE (iter.valid());
}

TEST (Iterator, valid3) {
	MyDeque<int> md (5, 5);
	MyDeque<int>::iterator iter(&md, 0, 1);
	ASSERT_TRUE (iter.valid());
}


// --------------------
// Const Iterator Tests
// --------------------

// -------------------------------
// test_const_iterator_constructor
// -------------------------------
TEST (ConstIterator, Constructor1) {
	MyDeque<int> md (5, 5);
	for (int i = 0; i < 5; ++i)
	{
		MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri + i);
		ASSERT_TRUE (*iter == 5);	
	}
}

TEST (ConstIterator, Constructor2) {
	MyDeque<int> md (1, -9);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (*iter == -9);
}

TEST (ConstIterator, Constructor3) {
	MyDeque<int> md (10, 9);
	MyDeque<int>::const_iterator iter(&md, 1, 0);
	ASSERT_TRUE (*iter == 9);
}

// -------------------------------
// test_const_iterator_dereference
// -------------------------------
TEST (ConstIterator, Dereference1) {
	MyDeque<int> md (4, 0);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (*iter == 0);
}

TEST (ConstIterator, Dereference2) {
	MyDeque<int> md (10, 9);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (*iter == 9);
}

TEST (ConstIterator, Dereference3) {
	MyDeque<int> md (10, 9);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri - 1);
	ASSERT_TRUE (*iter != 9);
}

// -------------------------
// test_const_iterator_equal
// -------------------------
TEST (ConstIterator, Equality1) {
	MyDeque<int> md (3, 2);
	MyDeque<int>::const_iterator iter1(&md, md.f_outeri, md.f_inneri);
	MyDeque<int>::const_iterator iter2(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (iter1 == iter2);
}

TEST (ConstIterator, Equality2) {
	MyDeque<int> md1 (3, 2);
	MyDeque<int> md2 (3, 2);
	MyDeque<int>::const_iterator iter1(&md1, md1.f_outeri, md1.f_inneri);
	MyDeque<int>::const_iterator iter2(&md2, md2.f_outeri, md2.f_inneri);
	ASSERT_TRUE (iter1 != iter2);
}

TEST (ConstIterator, Equality3) {
	MyDeque<int> md (3, 2);
	MyDeque<int>::const_iterator iter1(&md, md.f_outeri, md.f_inneri);
	MyDeque<int>::const_iterator iter2(&md, md.f_outeri, md.f_inneri + 1);
	ASSERT_TRUE (iter1 != iter2);
}

// ----------------------
// test_const_iterator_++
// ----------------------
TEST (ConstIterator, Increment1) {
	MyDeque<int> md(5, 5);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	for (int i = 0; i < 5; ++i)
	{
		ASSERT_TRUE (*iter == 5);
		++iter;
	}
}

TEST (ConstIterator, Increment2) {
	MyDeque<int> md(5, 0);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri + 2);
	for (int i = 0; i < 3; ++i)
	{
		ASSERT_TRUE (*iter == 0);
		++iter;
	}
}

TEST (ConstIterator, Increment3) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	for (int i = 0; i < 30; ++i)
	{
		ASSERT_TRUE (*iter == 5);
		++iter;
	}
}

// ----------------------
// test_const_iterator_--
// ----------------------
TEST (ConstIterator, Decrement1) {
	MyDeque<int> md(5, 5);
	MyDeque<int>::const_iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	for (int i = 0; i < 5; ++i)
	{
		ASSERT_TRUE (*iter == 5);
		--iter;
	}
}

TEST (ConstIterator, Decrement2) {
	MyDeque<int> md(5, 0);
	MyDeque<int>::const_iterator iter(&md, md.b_outeri, md.b_inneri - 3);
	for (int i = 0; i < 2; ++i)
	{
		ASSERT_TRUE (*iter == 0);
		--iter;
	}
}

TEST (ConstIterator, Decrement3) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::const_iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	for (int i = 0; i < 30; ++i)
	{
		ASSERT_TRUE (*iter == 5);
		--iter;
	}
}

// ----------------------
// test_const_iterator_+=
// ----------------------
TEST (ConstIterator, PlusEquals1) {
	MyDeque<int> md(5, 5);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	iter += 4;
	ASSERT_TRUE (*iter == 5);
}

TEST (ConstIterator, PlusEquals2) {
	MyDeque<int> md(5, 0);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	for (int i = 0; i < 5; ++i)
	{
		iter += 1;
		ASSERT_TRUE (*iter == 0);
	}
}

TEST (ConstIterator, PlusEquals3) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	iter += 15;
	ASSERT_TRUE (*iter == 5);
	iter += 5;
	ASSERT_TRUE (*iter == 5);
}

TEST (ConstIterator, PlusEquals4) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri + 1, md.f_inneri + 4);
	iter += -10;
	ASSERT_TRUE (*iter == 5);
}

// ----------------------
// test_const_iterator_-=
// ----------------------
TEST (ConstIterator, MinusEquals1) {
	MyDeque<int> md(5, 5);
	MyDeque<int>::const_iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	iter -= 4;
	ASSERT_TRUE (*iter == 5);
}

TEST (ConstIterator, MinusEquals2) {
	MyDeque<int> md(5, 0);
	MyDeque<int>::const_iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	for (int i = 0; i < 5; ++i)
	{
		iter -= 1;
		ASSERT_TRUE (*iter == 0);
	}
}

TEST (ConstIterator, MinusEquals3) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::const_iterator iter(&md, md.b_outeri, md.b_inneri - 1);
	iter -= 15;
	ASSERT_TRUE (*iter == 5);
	iter -= 5;
	ASSERT_TRUE (*iter == 5);
}

TEST (ConstIterator, MinusEquals4) {
	MyDeque<int> md(30, 5);
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	iter -= -10;
	ASSERT_TRUE (*iter == 5);
}

// -------------------------
// test_const_iterator_valid
// -------------------------
TEST (ConstIterator, valid1) {
	MyDeque<int> md;
	MyDeque<int>::const_iterator iter(&md, md.f_outeri, md.f_inneri);
	ASSERT_TRUE (iter.valid());
}

TEST (ConstIterator, valid2) {
	MyDeque<int> md;
	MyDeque<int>::const_iterator iter(&md, 0, 0); // Won't let me construct invalid ones
	ASSERT_TRUE (iter.valid());
}

TEST (ConstIterator, valid3) {
	MyDeque<int> md (5, 5);
	MyDeque<int>::const_iterator iter(&md, 0, 1);
	ASSERT_TRUE (iter.valid());
}

