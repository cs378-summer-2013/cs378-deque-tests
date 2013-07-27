// --------------------------------
// cs378 Summer 2013
// Project 4 - Deque
// Oscar Ivan Andres Chavarria
// eid: oic59
//
// Daniel Floyd
// eid: floyddj


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

    % g++ -pedantic -std=c++0x -Wall Deque.c++ TestDeque.c++ -o TestDeque -lgtest -lpthread -lgtest_main

    % valgrind TestDeque > TestDeque.out
*/

// --------
// includes
// --------
#define private public

#include <iostream>  // cout, endl
#include <sstream>   // istringtstream, ostringstream
#include <algorithm> // equals
#include <string>
#include <deque>

#include "gtest/gtest.h"

#include "Deque.h"

// ---------
// TestDeque
// ---------

//------------------------------------ Default Constructor Tests ------------------------------------//

class DequeDefaultConstructorTest : public testing::Test {
protected:
    MyDeque<int>    new_deq;
    std::deque<int> stl_deq;

    virtual void SetUp() {}
    virtual void TearDown() {}
};
TEST_F(DequeDefaultConstructorTest, init) {
    EXPECT_FALSE(new_deq._b);
    EXPECT_FALSE(new_deq._e);
    EXPECT_FALSE(new_deq._r);
    EXPECT_FALSE(new_deq._l);
    EXPECT_EQ(0, new_deq._lb);
    EXPECT_EQ(0, new_deq._er);
    EXPECT_EQ(0, new_deq._isz);
    EXPECT_EQ(0, new_deq.size());
    EXPECT_EQ(0, new_deq.capacity());
    ASSERT_TRUE(new_deq.valid());
}
TEST_F(DequeDefaultConstructorTest, test01) {
    EXPECT_EQ(0, new_deq.size());
    EXPECT_EQ(0, stl_deq.size());
    ASSERT_EQ(stl_deq.size(), new_deq.size());
}

//------------------------------------------- Equals Tests -------------------------------------------//

class DequeEqualsTest : public testing::Test {
protected:
    MyDeque<int>    new_deq_lhs;
    MyDeque<int>    new_deq_rhs;

    virtual void SetUp() {
        new_deq_lhs.resize(10, 1);
        new_deq_rhs.resize(10, 1);
    }
    virtual void TearDown() {}
};
TEST_F(DequeEqualsTest, resize10_1) {
    ASSERT_EQ(new_deq_lhs, new_deq_rhs);
}

//------------------------------------------- Less Tests -------------------------------------------//

class DequeLessTest : public testing::Test {
protected:
    MyDeque<int>    lhs;
    MyDeque<int>    rhs;
    MyDeque<std::string> aaa;
    MyDeque<std::string> bbb;


    virtual void SetUp() {
        lhs.push_back(1);
        lhs.push_back(2);
        lhs.push_back(3);

        rhs.push_back(1);
        rhs.push_back(2);
    }
    virtual void TearDown() {}
};
TEST_F(DequeLessTest, less_01) {
    ASSERT_TRUE(rhs < lhs);
    ASSERT_FALSE(lhs < rhs);
}

//------------------------------------------- Insert Tests -------------------------------------------//

class DequeInsertTest : public testing::Test {
protected:
    MyDeque<int>    new_deq;
    std::deque<int> stl_deq;


    virtual void SetUp() {
        new_deq.push_back(0);
        new_deq.push_back(1);
        new_deq.push_back(3);
        new_deq.push_back(4);
    }
    virtual void TearDown() {}
};
TEST_F(DequeInsertTest, insert_01) {

    MyDeque<int>::iterator it = new_deq.begin();
    it++;
    it++;

    new_deq.insert(it, 2);
    EXPECT_EQ(0, new_deq[0]);
    EXPECT_EQ(1, new_deq[1]);
    EXPECT_EQ(3, new_deq[3]);
    ASSERT_EQ(2, new_deq[2]);
}
TEST_F(DequeInsertTest, insert_02) {

    MyDeque<int>::iterator it = new_deq.begin();
    it+=2;

    new_deq.push_back(5);
    new_deq.push_back(6);
    new_deq.push_back(7);
    new_deq.push_back(8);
    new_deq.push_back(9);
    new_deq.push_back(10);
    new_deq.push_back(11);
    new_deq.push_back(12);

    new_deq.insert(it, 2);

    ASSERT_EQ(0, new_deq[0]);
    ASSERT_EQ(1, new_deq[1]);
    ASSERT_EQ(2, new_deq[2]);
    ASSERT_EQ(3, new_deq[3]);
    ASSERT_EQ(4, new_deq[4]);
    ASSERT_EQ(5, new_deq[5]);
    ASSERT_EQ(6, new_deq[6]);
    ASSERT_EQ(7, new_deq[7]);
}

TEST_F(DequeInsertTest, insert_03) {

    MyDeque<int>::iterator it = new_deq.begin();
    it+=12;

    new_deq.push_back(5);
    new_deq.push_back(6);
    new_deq.push_back(7);
    new_deq.push_back(8);
    new_deq.push_back(9);
    new_deq.push_back(10);
    new_deq.push_back(11);
    new_deq.push_back(12);
    new_deq.push_back(13);
    new_deq.push_back(14);

    new_deq.insert(it, 20);

    ASSERT_EQ(0, new_deq[0]);
    ASSERT_EQ(1, new_deq[1]);
    ASSERT_EQ(3, new_deq[2]);
    ASSERT_EQ(4, new_deq[3]);
    ASSERT_EQ(5, new_deq[4]);
    ASSERT_EQ(6, new_deq[5]);
    ASSERT_EQ(7, new_deq[6]);
    ASSERT_EQ(8, new_deq[7]);
    ASSERT_EQ(20, new_deq[12]);
    ASSERT_EQ(13, new_deq[13]);
    ASSERT_EQ(14, new_deq[14]);
}

TEST_F(DequeInsertTest, insert_04) {

    MyDeque<int>::iterator it = new_deq.begin();
    it+=3;

    new_deq.insert(it, 5);
    EXPECT_EQ(0, new_deq[0]);
    EXPECT_EQ(1, new_deq[1]);
    EXPECT_EQ(5, new_deq[3]);
    ASSERT_EQ(3, new_deq[2]);
}

TEST_F(DequeInsertTest, insert_05) {

    MyDeque<int>::iterator it = new_deq.begin();
    it+=4;

    new_deq.insert(it, 5);
    EXPECT_EQ(0, new_deq[0]);
    EXPECT_EQ(1, new_deq[1]);
    EXPECT_EQ(4, new_deq[3]);
    ASSERT_EQ(5, new_deq[4]);
    ASSERT_EQ(5, new_deq.size());
}

TEST_F(DequeInsertTest, insert_06) {

    MyDeque<int>::iterator it = new_deq.begin();

    new_deq.insert(it, 11);
    EXPECT_EQ(11, new_deq[0]);
    EXPECT_EQ(0, new_deq[1]);
    EXPECT_EQ(1, new_deq[2]);
    EXPECT_EQ(3, new_deq[3]);
    EXPECT_EQ(4, new_deq[4]);
    ASSERT_EQ(5, new_deq.size());
}


TEST_F(DequeInsertTest, insert_07) {

    MyDeque<int>::iterator it = new_deq.begin();
    new_deq.resize(20, 20);
    it += 15;

    new_deq.insert(it, 30);
    EXPECT_EQ(0, new_deq[0]);
    EXPECT_EQ(1, new_deq[1]);
    EXPECT_EQ(4, new_deq[3]);
    EXPECT_EQ(30, new_deq[15]);
    ASSERT_EQ(21, new_deq.size());
}

//------------------------------------------- Size Tests -------------------------------------------//

class DequeIntTest : public testing::Test {
protected:
    std::deque<int> stl_deq;
    MyDeque<int>    new_deq;

    virtual void SetUp() {
        MyDeque<int> s1(1, 1);
        new_deq = s1;
        std::deque<int> s2(1, 1);
        stl_deq = s2;
    }

    virtual void TearDown() {
    }

};

// put expected(stl) value first, MyDeque value second
TEST_F(DequeIntTest, test_size) {
    EXPECT_EQ(1, stl_deq.size());
    EXPECT_EQ(1, new_deq.size());
    ASSERT_EQ(stl_deq.size(), new_deq.size());
}

TEST_F(DequeIntTest, resize01) {
    ASSERT_EQ(1, new_deq.size());
}

TEST_F(DequeIntTest, resize02) {
    new_deq.resize(1);
    ASSERT_EQ(1, new_deq.size());
}

TEST_F(DequeIntTest, resize03) {
    new_deq.resize(2, 1);
    ASSERT_EQ(2, new_deq.size());
}

TEST_F(DequeIntTest, resize04) {
    new_deq.resize(10, 1);
    new_deq.resize(20, 2);
    new_deq.resize(15, 5);
    ASSERT_EQ(15, new_deq.size());
}

//----------------------------------------- Push_back Tests -----------------------------------------//

class DequePushBackTest : public testing::Test {
protected:
    MyDeque<int>    lhs;

    virtual void SetUp() {
        lhs.push_back(1);
        lhs.push_back(2);
        lhs.push_back(3);
        lhs.push_back(4);
        lhs.push_back(5);
    }
    virtual void TearDown() {}
};

TEST_F(DequePushBackTest, push_back_01) {
    ASSERT_EQ(1, lhs.front());
    ASSERT_EQ(5, lhs.back());
}

TEST_F(DequePushBackTest, push_back_02) {
    lhs.push_back(0);
    lhs.resize(2);
    lhs.push_back(11);
    ASSERT_EQ(1, lhs.front());
    ASSERT_EQ(11, lhs.back());
}

TEST_F(DequePushBackTest, push_back_03) {
    lhs.clear();
    lhs.push_back(6);
    ASSERT_EQ(6, lhs.front());
    ASSERT_EQ(6, lhs.back());
}

//----------------------------------------- Push_front Tests -----------------------------------------//

class DequePushFrontTest : public testing::Test {
protected:
    MyDeque<int>    lhs;

    virtual void SetUp() {
        lhs.push_front(1);
        lhs.push_front(2);
        lhs.push_front(3);
        lhs.push_front(4);
        lhs.push_front(5);
    }
    virtual void TearDown() {}
};

TEST_F(DequePushFrontTest, push_front_01) {
    ASSERT_EQ(5, lhs.front());
    ASSERT_EQ(1, lhs.back());
}

TEST_F(DequePushFrontTest, push_front_02) {
    lhs.push_front(0);
    lhs.resize(2);
    lhs.push_front(11);
    ASSERT_EQ(11, lhs.front());
    ASSERT_EQ(5, lhs.back());
}

TEST_F(DequePushFrontTest, push_front_03) {
    lhs.clear();
    lhs.push_back(6);
    lhs.push_front(11);
    ASSERT_EQ(11, lhs.front());
    ASSERT_EQ(6, lhs.back());
}

//----------------------------------------- Pop_back Tests -----------------------------------------//

class DequePopBackTest : public testing::Test {
protected:
    MyDeque<int>    lhs;

    virtual void SetUp() {
        lhs.push_back(1);
        lhs.push_back(2);
        lhs.push_back(3);
        lhs.push_back(4);
        lhs.push_back(5);
    }
    virtual void TearDown() {}
};

TEST_F(DequePopBackTest, pop_back_01) {
    lhs.pop_back();
    lhs.pop_back();
    lhs.pop_back();
    lhs.pop_back();
    ASSERT_EQ(1, lhs.front());
    ASSERT_EQ(1, lhs.back());
    ASSERT_EQ(1, lhs.size());
}

TEST_F(DequePopBackTest, pop_back_02) {
    lhs.pop_back();
    ASSERT_EQ(1, lhs.front());
    ASSERT_EQ(4, lhs.back());
    ASSERT_EQ(4, lhs.size());
}

TEST_F(DequePopBackTest, pop_back_03) {
    lhs.pop_back();
    lhs.pop_back();
    lhs.resize(100, 6);
    lhs.pop_back();
    lhs.pop_back();
    ASSERT_EQ(1, lhs.front());
    ASSERT_EQ(6, lhs.back());
    ASSERT_EQ(98, lhs.size());
}

//----------------------------------------- Pop_front Tests -----------------------------------------//

class DequePopFrontTest : public testing::Test {
protected:
    MyDeque<int>    lhs;

    virtual void SetUp() {
        lhs.push_back(1);
        lhs.push_back(2);
        lhs.push_back(3);
        lhs.push_back(4);
        lhs.push_back(5);
    }
    virtual void TearDown() {}
};

TEST_F(DequePopFrontTest, pop_front_01) {
    lhs.pop_front();
    lhs.pop_front();
    lhs.pop_front();
    lhs.pop_front();
    ASSERT_EQ(5, lhs.front());
    ASSERT_EQ(5, lhs.back());
    ASSERT_EQ(1, lhs.size());
}

TEST_F(DequePopFrontTest, pop_front_02) {
    lhs.pop_front();
    ASSERT_EQ(2, lhs.front());
    ASSERT_EQ(5, lhs.back());
    ASSERT_EQ(4, lhs.size());
}

TEST_F(DequePopFrontTest, pop_front_03) {
    lhs.pop_front();
    lhs.pop_front();
    lhs.resize(100, 6);
    lhs.pop_front();
    lhs.pop_front();
    ASSERT_EQ(5, lhs.front());
    ASSERT_EQ(6, lhs.back());
    ASSERT_EQ(98, lhs.size());
}

//----------------------------------------- Resize Tests -----------------------------------------//

class DequeResizeTest : public testing::Test {
protected:
    MyDeque<int>    lhs;

    virtual void SetUp() {
        lhs.push_back(2);
        lhs.push_back(2);
    }
    virtual void TearDown() {}
};

TEST_F(DequeResizeTest, resize_01) {
    lhs.resize(4);
    ASSERT_EQ(2, lhs.front());
    ASSERT_EQ(0, lhs.back());
    ASSERT_EQ(4, lhs.size());
}

TEST_F(DequeResizeTest, resize_02) {
    lhs.push_back(1);
    lhs.push_back(1);
    lhs.push_back(1);
    lhs.push_back(1);
    lhs.push_back(1);
    lhs.push_back(1);
    lhs.push_back(1);
    lhs.push_back(1);
    lhs.resize(10, 2);
    lhs.resize(20, 3);
    lhs.resize(15);
    ASSERT_EQ(2, lhs.front());
    ASSERT_EQ(3, lhs.back());
    ASSERT_EQ(15, lhs.size());
}

TEST_F(DequeResizeTest, resize_03) {
    lhs.push_back(2);
    lhs.push_back(2);
    lhs.push_back(2);
    lhs.resize(2);
    ASSERT_EQ(2, lhs.front());
    ASSERT_EQ(2, lhs.back());
    ASSERT_EQ(2, lhs.size());
}

//----------------------------------------- Resize Tests -----------------------------------------//

class DequeIteratorTest : public testing::Test {
protected:
    MyDeque<int>    lhs;
    MyDeque<int>    rhs;

    virtual void SetUp() {
        lhs.push_back(1);
        lhs.push_back(2);
        lhs.push_back(3);
        lhs.push_back(4);
        lhs.push_back(5);

        rhs.push_back(1);
        rhs.push_back(2);
        rhs.push_back(3);
        rhs.push_back(4);
        rhs.push_back(5);
    }
    virtual void TearDown() {}
};

TEST_F(DequeIteratorTest,  iterator_01) {
    typename MyDeque<int>::iterator a = lhs.begin();
    typename MyDeque<int>::iterator b = rhs.begin();
    ASSERT_EQ(*a, *b);
}

TEST_F(DequeIteratorTest,  iterator_02) {
    typename MyDeque<int>::iterator a = lhs.begin();
    typename MyDeque<int>::iterator b = rhs.begin();
    ASSERT_EQ(*(--a), *(--b));
}

TEST_F(DequeIteratorTest,  iterator_03) {
    typename MyDeque<int>::iterator a = lhs.begin();
    typename MyDeque<int>::iterator b = rhs.begin();
    std::cout << *a << std::endl;
    std::cout << *b << std::endl;
    ASSERT_EQ(*(++a), *(++b));
}




typedef testing::Types<MyDeque<int>, std::deque<int> > MyTypes;
template <typename T>
class TypeTest : public testing::Test {
    protected:
        T x;
        T y;
};

TYPED_TEST_CASE(TypeTest, MyTypes);
TYPED_TEST(TypeTest, TemplateTypeEquals) {
    ASSERT_EQ(0, this->x.size());
}

template <typename T>
class CopyConstructorTest : public testing::Test {
    protected:
        T x;
    virtual void SetUp () {
        T x(5);
    }
};

TYPED_TEST_CASE(CopyConstructorTest, MyTypes);
TYPED_TEST(CopyConstructorTest, Size5_Block10) {
    ASSERT_EQ(0, this->x.size());
}



// TEST(Deque, dummy_test) {
//     std::cout << "here" << std::endl;
//     ASSERT_TRUE(true);
// }

