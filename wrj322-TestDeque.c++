// ----------------------------
// projects/deque/TestDeque.cincrement
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
    % gincrement -pedantic -std=cincrement0x -Wall Deque.cincrement TestDeque.cincrement -o TestDeque -lcppunit -ldl
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

#include "Deque.h"
#include <iostream>
#include "gtest/gtest.h"

using namespace std;


/* 
    Setting test fixture up for typed tests.
*/
typedef testing::Types< deque<int> > implementationsToTest;

template <typename C>
class DequeTest : public testing::Test {

};
TYPED_TEST_CASE(DequeTest, implementationsToTest);


/* 
==============
    Tests.
==============
*/

/* 
--------
iterator
--------
*/

TYPED_TEST(DequeTest, iterator_operator_equal_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, iterator_valid_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, iterator_default_constructor_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, iterator_operator_deference_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, iterator_operator_increment_prefix_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, iterator_operator_decrement_prefix_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, iterator_operator_plus_equal_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, iterator_operator_minus_equal_01) {
	ASSERT_TRUE(false);
}

/*  
--------------
const_iterator
--------------
*/

TYPED_TEST(DequeTest, const_iterator_operator_equal_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, const_iterator_valid_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, const_iterator_default_constructor_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, const_iterator_operator_deference_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, const_iterator_operator_increment_prefix_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, const_iterator_operator_decrement_prefix_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, const_iterator_operator_plus_equal_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, const_iterator_operator_minus_equal_01) {
	ASSERT_TRUE(false);
}

/*
-------
MyDeque
-------
*/

TYPED_TEST(DequeTest, deque_operator_equal_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_operator_less_than_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_valid_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_constructor_allocator_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_constructor_size_value_allocator_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_constructor_deque_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_destructor_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_operator_assignment_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_operator_index_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_at_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_back_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_begin_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_begin_const_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_clear_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_end_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_end_const_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_erase_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_front_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, deque_insert_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, pop_back_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, pop_front_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, push_back_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, push_front_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, resize_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, size_01) {
	ASSERT_TRUE(false);
}

TYPED_TEST(DequeTest, swap_01) {
	ASSERT_TRUE(false);
}



