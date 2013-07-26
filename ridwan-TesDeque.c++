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

// ---------
// TestDeque
// ---------

template <typename D>
class DequeTest : public testing::Test {
    protected:
        D d1;
        D d2;

        DequeTest() : d2(5, 1) {}
};

typedef testing::Types<std::deque<int>, MyDeque<int> > DequeTypes;

TYPED_TEST_CASE(DequeTest, DequeTypes);

TYPED_TEST(DequeTest, fill_constructor_1) {
    ASSERT_EQ(this->d2.size(), 5);
    ASSERT_EQ(this->d2[4], 1);
}

TYPED_TEST(DequeTest, copy_constructor_1) {
    TypeParam d3 (this->d2);
    ASSERT_EQ(d3.size(), this->d2.size());
    for (int i = 0; i < d3.size(); i++)
        ASSERT_EQ(d3[i], this->d2[i]);
}

TYPED_TEST(DequeTest, size_1) {
    ASSERT_EQ(this->d1.size(), 0);
}

TYPED_TEST(DequeTest, size_2) {
    ASSERT_EQ(this->d2.size(), 5);
}

TYPED_TEST(DequeTest, subscript_operator_1) {
    this->d2[2] = 100;
    ASSERT_EQ(this->d2[2], 100);
}

TYPED_TEST(DequeTest, front_1) {
    this->d2[0] = 100;
    ASSERT_EQ(this->d2.front(), 100);
}

TYPED_TEST(DequeTest, back_1) {
    this->d2[4] = 100;
    ASSERT_EQ(this->d2.back(), 100);
}

TYPED_TEST(DequeTest, empty_1) {
    ASSERT_EQ(this->d1.empty(), true);
    ASSERT_EQ(this->d2.empty(), false);
}

TYPED_TEST(DequeTest, push_back_1) {
    this->d2.push_back(10);
    ASSERT_EQ(this->d2.back(), 10);
}

TYPED_TEST(DequeTest, push_back_2) {
    for (int i = 5; i < 15; i++) {
        this->d2.push_back(i);
        ASSERT_EQ(this->d2.back(), i);
    }
}

TYPED_TEST(DequeTest, push_front_1) {
    this->d2.push_front(10);
    ASSERT_EQ(this->d2.front(), 10);
}

TYPED_TEST(DequeTest, push_front_2) {
    for (int i = 5; i < 15; i++) {
        this->d2.push_front(i);
        ASSERT_EQ(this->d2.front(), i);
    }
}

// TYPED_TEST(DequeTest, equal_operator_1) {
//     this->d1 = this->d2;
//     ASSERT_EQ(this->d1.size(), 5);
//     for (int i = 0 ; i < 5; i++){
//         ASSERT_EQ(this->d1[i], 1);
//     }
// }