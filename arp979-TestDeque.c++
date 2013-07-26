// ----------------------------
// projects/deque/TestDeque.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

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

    % g++ -pedantic -std=c++0x -Wall Deque.h TestDeque_gtest.c++ -o TestDeque -lgtest -lpthread -lgtest_main

    % valgrind TestDeque_gtest.c++ > TestDeque_gtest.c++.out
*/

// --------
// includes
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
% g++ -pedantic -std=c++0x -Wall Deque.h TestDeque.c++ -o TestDeque -lgtest -lpthread -lgtest_main
% valgrind TestDeque > TestDeque.out
*/

// --------
// includes
// --------

#include <algorithm> // equal
#include <cstring> // strcmp
#include <deque> // deque
#include <sstream> // ostringstream
#include <stdexcept> // invalid_argument
#include <string> // ==
#include <gtest/gtest.h>
#include "Deque.h"

// ---------
// TestDeque
// ---------

template <class C>
class DequeTest : public testing::Test {
protected:
    DequeTest() : mydequeX(C()) ,mydequeY(C()), mydequeD(C(3,3)) {}


    C mydequeX,mydequeY,mydequeD;
    typename C::iterator iterator;
    typename C::iterator iterator2;
    typename C::const_iterator const_iterator;
    typename C::const_iterator const_iterator2;
    typename C::difference_type diff_type;
    typename C::size_type size_type;
};

using testing::Types;
typedef Types<std::deque<int>, MyDeque<int>, std::deque<short>, MyDeque<short>, std::deque<long>, MyDeque<long>, std::deque<unsigned>, MyDeque<unsigned> > Implementations;
TYPED_TEST_CASE(DequeTest, Implementations);

TYPED_TEST(DequeTest, test_constructor_1){
    ASSERT_EQ(this->mydequeD[0],3);
    ASSERT_EQ(this->mydequeD.size(),3);
}

TYPED_TEST(DequeTest, test_constructor_2){
    ASSERT_EQ(this->mydequeD[1],3);
    ASSERT_EQ(this->mydequeD.size(),3);
}

TYPED_TEST(DequeTest, test_constructor_3){
    ASSERT_EQ(this->mydequeD[2],3);
    ASSERT_EQ(this->mydequeD.size(),3);
}

TYPED_TEST(DequeTest, test_push_back_0) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(4);
    this->mydequeX.push_back(5);
    this->mydequeX.push_back(6);
    this->mydequeX.push_back(7);
    this->mydequeX.push_back(8);
    this->mydequeX.push_back(9);
    this->mydequeX.push_back(10);
    this->mydequeX.push_back(11);
    this->mydequeX.push_back(12);
    this->mydequeX.push_back(13);
    this->mydequeX.push_back(14);
    this->mydequeX.push_back(15);
    this->mydequeX.push_back(16);
    this->mydequeX.push_back(17);
    this->mydequeX.push_back(18);
    this->mydequeX.push_back(19);
    this->mydequeX.push_back(20);
    this->mydequeX.push_back(21);
    
    ASSERT_EQ(this->mydequeX[0], 1);
    ASSERT_EQ(this->mydequeX[1], 2);
    ASSERT_EQ(this->mydequeX[20], 21);
    this->mydequeX.clear();
}

TYPED_TEST(DequeTest, test_push_back_1) {
    this->mydequeX.push_front(99);
    this->mydequeX.push_back(11);
    this->mydequeX.push_back(22);
    this->mydequeX.push_back(33);
    this->mydequeX.push_back(13);
    ASSERT_EQ(this->mydequeX[1], 11);
    ASSERT_EQ(this->mydequeX[3], 33);
    ASSERT_EQ(this->mydequeX[4], 13);
    this->mydequeX.clear();
}

TYPED_TEST(DequeTest, test_push_back_2) {
    this->mydequeX.push_front(1);
    this->mydequeX.push_front(1);
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(4);
    this->mydequeX.push_back(5);
    ASSERT_EQ(this->mydequeX[2], 1);
    ASSERT_EQ(this->mydequeX[5], 5);
    this->mydequeX.clear();
}

TYPED_TEST(DequeTest, test_loop_70_push_back) {
    for (int i = 0; i < 70; i++) {
        this->mydequeX.push_back(70);
    }
    for (int i = 0; i < 70; i++) {
        ASSERT_EQ(this->mydequeX[i], 70);
    }
}

TYPED_TEST(DequeTest, test_loop_90_push_back_nums) {
    for (int i = 0; i < 90; i++) {
        this->mydequeX.push_back(i);
    }
    for (int i = 0; i < 90; i++) {
        ASSERT_EQ(this->mydequeX[i], i);
    }
}

TYPED_TEST(DequeTest, test_push_front) {
    this->mydequeX.push_front(1);
    this->mydequeX.push_front(2);
    this->mydequeX.push_front(3);
    this->mydequeX.push_front(4);
    this->mydequeX.push_front(5);
    this->mydequeX.push_front(6);
    this->mydequeX.push_front(7);
    this->mydequeX.push_front(8);
    this->mydequeX.push_front(9);
    this->mydequeX.push_front(10);
    this->mydequeX.push_front(11);
    this->mydequeX.push_front(12);
    this->mydequeX.push_front(13);
    this->mydequeX.push_front(14);
    this->mydequeX.push_front(15);
    this->mydequeX.push_front(16);
    this->mydequeX.push_front(17);
    this->mydequeX.push_front(18);
    this->mydequeX.push_front(19);
    this->mydequeX.push_front(20);
    this->mydequeX.push_front(21);
    ASSERT_EQ(this->mydequeX[0], 21);
    ASSERT_EQ(this->mydequeX[1], 20);
    ASSERT_EQ(this->mydequeX[20], 1);
}

TYPED_TEST(DequeTest, test_loop_50_push_front) {
    for (int i = 0; i < 50; i++) {
        this->mydequeX.push_front(i);
    }
    for (int i = 0; i < 50; i++) {
        ASSERT_EQ(this->mydequeX[i], 49-i);
    }
}

TYPED_TEST(DequeTest, test_size_w_pushfront_and_pushback) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_front(99);
    ASSERT_EQ(this->mydequeX.size(),3);
}

TYPED_TEST(DequeTest, test_empty) {
    ASSERT_EQ(this->mydequeX.size(), 0);
}


TYPED_TEST(DequeTest, test_clear) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_front(2);
    this->mydequeX.push_back(3);
    ASSERT_EQ(this->mydequeX.size(), 3);
    this->mydequeX.clear();
    ASSERT_EQ(this->mydequeX.size(), 0);
}

TYPED_TEST(DequeTest, test_iterator_begin) {
    this->mydequeX.push_back(1);
    this->iterator = this->mydequeX.begin();
    ASSERT_EQ(*(this->iterator), 1);
}

TYPED_TEST(DequeTest, test_iterator_begin_2) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_front(22);
    this->iterator = this->mydequeX.begin();
    ASSERT_EQ(*(this->iterator), 22);
}

TYPED_TEST(DequeTest, test_iterator_end) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_front(22);
    this->iterator = this->mydequeX.end()-1;
    ASSERT_EQ(*(this->iterator), 3);
}

TYPED_TEST(DequeTest, test_iterator_end_2) {
    this->mydequeX.push_back(13);
    this->mydequeX.push_front(26);
    this->mydequeX.push_front(39);
    this->iterator = this->mydequeX.end()-1;
    ASSERT_EQ(*(this->iterator), 13);
}

TYPED_TEST(DequeTest, test_equality) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);

    this->mydequeY.push_back(1);
    this->mydequeY.push_back(2);

    ASSERT_EQ(this->mydequeX, this->mydequeY);
}

TYPED_TEST(DequeTest, test_iterator_equals) {
    this->mydequeX.push_back(13);
    this->iterator = this->mydequeX.begin();
    this->iterator2 = this->mydequeX.begin();
    EXPECT_TRUE(this->iterator == this->iterator2);
}

TYPED_TEST(DequeTest, test_iterator_plus_equals) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(4);
    this->mydequeX.push_back(5);
    this->mydequeX.push_back(6);
    this->mydequeX.push_back(7);
    this->mydequeX.push_back(8);
    this->mydequeX.push_back(9);
    this->mydequeX.push_back(10);
    this->iterator = this->mydequeX.begin();
    this->iterator += 7;
    EXPECT_TRUE(*(this->iterator) == 8);
}

TYPED_TEST(DequeTest, test_iterator_minus_equals) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(4);
    this->mydequeX.push_back(5);
    this->mydequeX.push_back(6);
    this->mydequeX.push_back(7);
    this->mydequeX.push_back(8);
    this->mydequeX.push_back(9);
    this->mydequeX.push_back(10);
    this->iterator = this->mydequeX.end();
    this->iterator -= 7;
    EXPECT_TRUE(*(this->iterator) == 4);
}

TYPED_TEST(DequeTest, test_assignment) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeY = this->mydequeX;
    EXPECT_TRUE(&this->mydequeX != &this->mydequeY);
    EXPECT_TRUE(this->mydequeX == this->mydequeY);
}

TYPED_TEST(DequeTest, test_check_default_equal) {
    EXPECT_TRUE(&this->mydequeX != &this->mydequeY);
    EXPECT_TRUE(this->mydequeX == this->mydequeY);
}

TYPED_TEST(DequeTest, test_index_1) {
    this->mydequeY.push_back(1);
    this->mydequeY.push_back(2);
    this->mydequeY.push_back(3);
    this->size_type = 2;
    EXPECT_TRUE((this->mydequeY)[this->size_type] == 3);
}

TYPED_TEST(DequeTest, test_index_2) {
    this->mydequeY.push_back(4);
    this->mydequeY.push_back(9);
    this->mydequeY.push_front(32);
    this->size_type = 2;
    ASSERT_EQ((this->mydequeY)[this->size_type], 9);
}

TYPED_TEST(DequeTest, test_out_of_range_exception) {
    this->mydequeY.push_back(1);
    this->mydequeY.push_back(2);
    this->mydequeY.push_front(3);
    try {
        this->size_type = 4;
        this->mydequeY.at(this->size_type);
        EXPECT_TRUE(false);
    } catch (std::out_of_range &e) {

    }
}

TYPED_TEST(DequeTest, test_out_of_range_exception_2) {
    this->mydequeY.push_back(1);
    this->mydequeY.push_back(2);
    this->mydequeY.push_front(3);
    try {
	  this->size_type = -1;
	  this->mydequeY.at(this->size_type);
	  EXPECT_TRUE(false);
        } 
    catch (std::out_of_range &e) {}
}

TYPED_TEST(DequeTest, test_back) {
    this->mydequeX.push_front(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(4);
    this->mydequeX.push_back(5);
    this->mydequeX.push_back(8);
    this->mydequeX.push_back(9);
    this->mydequeX.push_back(10);
    EXPECT_TRUE((this->mydequeX).back() == 10);
}

TYPED_TEST(DequeTest, test_end_1) {
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(7);
    this->iterator = this->mydequeX.end()-1;
    EXPECT_TRUE(*(this->iterator) == 7);
}

TYPED_TEST(DequeTest, test_end_2) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->iterator = this->mydequeX.end()-1;
    EXPECT_TRUE(*(this->iterator) == 3);
}

TYPED_TEST(DequeTest, test_erase) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->iterator = this->mydequeX.begin();
    this->iterator = (this->mydequeX).erase(this->iterator);
    EXPECT_TRUE(*(this->iterator) == 2);
}

TYPED_TEST(DequeTest, test_front_1) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    EXPECT_TRUE((this->mydequeX).front()==1);
}

TYPED_TEST(DequeTest, test_front_2) {
    this->mydequeX.push_front(1);
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(7);
    this->mydequeX.push_back(14);
    this->mydequeX.push_back(21);
    this->mydequeX.push_back(28);
    EXPECT_TRUE((this->mydequeX).front()==1);
}

TYPED_TEST(DequeTest, test_insert) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->iterator = this->mydequeX.begin();
    this->iterator = this->mydequeX.insert(this->iterator,5);
    EXPECT_TRUE(*(this->iterator)==5);
    EXPECT_TRUE((this->mydequeX)[0]==5);
}

TYPED_TEST(DequeTest, test_pop_back) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.pop_back();
    EXPECT_TRUE((this->mydequeX).size()==2);
    EXPECT_TRUE((this->mydequeX)[1]==2);
}

TYPED_TEST(DequeTest, test_pop_front) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.pop_front();
    EXPECT_TRUE((this->mydequeX).size()==2);
    EXPECT_TRUE((this->mydequeX)[0]==2);
}

TYPED_TEST(DequeTest, test_resize) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->size_type = 1;
    (this->mydequeX).resize(this->size_type);
    EXPECT_TRUE((this->mydequeX).size()==1);
    EXPECT_TRUE((this->mydequeX)[0]==1);
}

TYPED_TEST(DequeTest, test_resize_2) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    ASSERT_EQ((this->mydequeX).size(), 9);
    this->mydequeX.resize(4);
    ASSERT_EQ((this->mydequeX).size(), 4);
    this->mydequeX.push_back(2);
    ASSERT_EQ((this->mydequeX).size(), 5);
}

TYPED_TEST(DequeTest, swap) {
    this->mydequeX.push_back(1);
    this->mydequeX.push_back(2);
    this->mydequeX.push_back(3);
    
    this->mydequeY.push_back(3);
    this->mydequeY.push_back(2);
    this->mydequeY.push_back(1);
    this->mydequeY.push_back(4);

    (this->mydequeX).swap(this->mydequeY);
    EXPECT_TRUE((this->mydequeX).size()==4);
    EXPECT_TRUE((this->mydequeY).size()==3);
  
}
