// ------------------------------
// cs378-deque/src/Deque.h
// Copyright (C) 2013
// CS w378 C++ STL w/ Dr. Downing
// Summer 2013
// Kevin Tran
// Shan Gupta
// ------------------------------

/*
 * TestDeque
 *
 * To compile this, use the command
 * g++ -pedantic -std=c++0x -Wall TestDeque.c++ -o TestDeque -lgtest -lgtest_main -lpthread
 *
 * Then it can run with
 * TestDeque
 *
 * It will work on any machine with gtest and the precompiled libraries installed
 */

#include <algorithm> // equal
#include <cstring>   // strcmp
#include <deque>     // deque
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

// Stuff in deque.h so they don't get compile errors when we use the defines
// to make all members of deque public
#include <cassert>
#include <iterator>
#include <memory>
#include <utility>

#include "gtest/gtest.h" // Google Test framework

#define class struct
#define protected public
#define private public
#define SIZE 500

#include "Deque.h"


// Not testing the code we didn't write
// destroy, unitialized_copy, unitialized_fill

typedef testing::Types<std::deque<int>, MyDeque<int> > MyDeques;
// --- Deque Interface tests ---
// These are tests that both deques should pass

template <typename C>
class DequeTest : public testing::Test {
    protected:
        typedef C container;
        typedef typename C::value_type T;
        typedef typename C::size_type size_type;
        std::allocator<T> a;
        container x, y;

        // This needs to be large enough that the data will span past
        // a single array
        const size_type s;

        DequeTest() :
            s(40)
        {}

        void SetSame() {
            x = container (10, 5);
            y = container (10, 5);
        }

        void SetDifferent() {
            SetSame();
            y[5] = 3;
        }

        void SetLessContent() {
            x = container (10, 4);
            y = container (10, 5);
            ASSERT_EQ(10, x.size());
            ASSERT_EQ(10, y.size());
        }

        void SetLessSize() {
            x = container (5, 5);
            y = container (10, 5);
            ASSERT_EQ(5, x.size());
            ASSERT_EQ(10, y.size());
        }

        void SetLarge() {
            x = container (s, 5);
            y = container (s, 5);
        }
};


TYPED_TEST_CASE(DequeTest, MyDeques);

TYPED_TEST(DequeTest, ResizeDown) {
    this->SetSame();
    this->x.resize(0);
    ASSERT_EQ(0, this->x.size());
}

TYPED_TEST(DequeTest, ResizeLarger) {
    this->SetSame();
    this->x.resize(20);
    ASSERT_EQ(20, this->x.size());
    ASSERT_EQ(0, this->x[14]);
}

TYPED_TEST(DequeTest, ResizeVeryLarge) {
    this->SetSame();
    this->x.resize(20000);
    ASSERT_EQ(20000, this->x.size());
    ASSERT_EQ(0, this->x[14]);
}

TYPED_TEST(DequeTest, ResizeNewValue) {
    this->SetSame();
    this->x.resize(30, 9);
    ASSERT_EQ(30, this->x.size());
    ASSERT_EQ(9, this->x[14]);
}

TYPED_TEST(DequeTest, At1) {
    this->SetSame();
    this->x.resize(30, 9);
    ASSERT_EQ(30, this->x.size());
    ASSERT_EQ(9, this->x.at(14));
}

TYPED_TEST(DequeTest, At2) {
    this->SetSame();
    ASSERT_EQ(5, this->x.at(4));
}

TYPED_TEST(DequeTest, At3) {
    this->SetSame();
    ASSERT_EQ(5, this->x.at(0));
}

TYPED_TEST(DequeTest, At4) {
    try {
        ASSERT_EQ(0, this->x.at(0));
    } catch (...) {
        ASSERT_EQ(1,1);
    }
}

TYPED_TEST(DequeTest, Front0) {
    this->SetSame();
    ASSERT_EQ(5, this->x.front());
}

TYPED_TEST(DequeTest, Front1) {
    this->SetSame();
    this->x.resize(50);
    ASSERT_EQ(5, this->x.front());
}

TYPED_TEST(DequeTest, Front2) {
    this->SetSame();
    this->x.push_front(87);
    ASSERT_EQ(87, this->x.front());
}

TYPED_TEST(DequeTest, IndexOp) {
    this->SetSame();
    this->x.push_back(7);
    this->x.pop_front();

    ASSERT_EQ(7, this->x[9]);
    ASSERT_EQ(5, this->x[0]);
}

TYPED_TEST(DequeTest, IndexOp1) {
    this->SetSame();
    this->x.push_back(7);
    this->x.pop_front();
    this->x.push_front(99);

    ASSERT_EQ(7, this->x[10]);
    ASSERT_EQ(99, this->x[0]);
}

TYPED_TEST(DequeTest, IndexOp2) {
    this->x.resize(40, 9);
    ASSERT_EQ(9, this->x[30]);
}

TYPED_TEST(DequeTest, EqualsEquals1) {
    this->SetSame();
    ASSERT_EQ(true, this->x == this->y);
}

TYPED_TEST(DequeTest, EqualsEquals2) {
    this->SetDifferent();
    ASSERT_EQ(false, this->x == this->y);
}

TYPED_TEST(DequeTest, EqualsEquals3) {
    this->SetDifferent();
    this->SetSame();
    this->x.resize(15);
    ASSERT_EQ(false, this->x == this->y);
}

TYPED_TEST(DequeTest, Swap1) {
    this->SetSame();
    this->x.swap(this->y);
    ASSERT_EQ(false, this->x != this->y);
}

TYPED_TEST(DequeTest, Swap2) {
    this->SetSame();
    this->x.swap(this->y);
    ASSERT_EQ(true, this->x == this->y);
}

TYPED_TEST(DequeTest, Swap3) {
    this->SetSame();
    this->SetDifferent();
    this->x.resize(15);
    typename TestFixture::container v(this->x);
    typename TestFixture::container w(this->y);
    this->x.swap(this->y);
    ASSERT_EQ(true, this->x == w);
    ASSERT_EQ(false, this->x == v);
    ASSERT_EQ(true, this->y == v);
    ASSERT_EQ(false, this->y == w);
}

// --- Constructors ---

TYPED_TEST(DequeTest, AllocatorConstructor) {
    EXPECT_EQ(0, this->x.size());
    EXPECT_EQ(0, this->y.size());
}

TYPED_TEST(DequeTest, SizedConstructor) {
    typename TestFixture::container v(10, 5);
    ASSERT_EQ(10, v.size());
    for (int i = 0; i < 10; ++i)
        EXPECT_EQ(5, v[i]);
}

TYPED_TEST(DequeTest, SizedConstructorLarge) {
    typename TestFixture::container v(this->s, 5);
    ASSERT_EQ(this->s, v.size());
    for (typename TestFixture::size_type i = 0; i < this->s; ++i)
        EXPECT_EQ(5, v[i]);
}

TYPED_TEST(DequeTest, CopyConstructor) {
    this->SetSame();
    typename TestFixture::container v = this->x;
    ASSERT_EQ(this->x.size(), v.size());

    for(unsigned int i = 0; i < v.size(); ++i)
        EXPECT_EQ(this->x[i], v[i]);
}

// --- Copy Assignment ---

TYPED_TEST(DequeTest, CopyAssignment) {
    this->SetDifferent();
    ASSERT_EQ(3, this->y[5]);

    this->y = this->x;

    ASSERT_EQ(this->x.size(), this->y.size());
    for (unsigned int i = 0; i < this->x.size(); ++i)
        EXPECT_EQ(this->x[i], this->y[i]);
}

// --- operator == ---

TYPED_TEST(DequeTest, ContentEqualsOnEmpty) {
    EXPECT_EQ(this->x, this->y);
}

TYPED_TEST(DequeTest, ContentEqualsSmall) {
    this->SetSame();
    EXPECT_EQ(this->x, this->y);
}

TYPED_TEST(DequeTest, ContentEqualsLarge) {
    this->SetLarge();
    EXPECT_EQ(this->x, this->y);
}

TYPED_TEST(DequeTest, ContentNotEqual) {
    this->SetDifferent();
    ASSERT_NE(this->x, this->y);
}

TYPED_TEST(DequeTest, SizeNotEqualSize) {
    this->SetSame();
    this->x.push_back(0);
    ASSERT_NE(this->x.size(), this->y.size());
}

TYPED_TEST(DequeTest, ContentAndSizeNotEqual) {
    this->SetSame();
    this->x.push_back(0);
    ASSERT_NE(this->x, this->y);
}

TYPED_TEST(DequeTest, ContentNotEqualsLarge) {
    this->SetLarge();
    this->y.at(this->s - 1) = 0;
    ASSERT_NE(this->x, this->y);
}

// --- operator < ---

TYPED_TEST(DequeTest, LessThan) {
    this->SetLessContent();
    EXPECT_LT(this->x, this->y);
}

TYPED_TEST(DequeTest, LessThanSize) {
    this->SetLessSize();
    EXPECT_LE(this->x, this->y);
}

TYPED_TEST(DequeTest, LessThanLarge) {
    this->SetLarge();
    this->x[0] = 0;
    EXPECT_LE(this->x, this->y);
}

TYPED_TEST(DequeTest, LessThanEqualEmpty) {
    EXPECT_LE(this->x, this->y);
}

TYPED_TEST(DequeTest, LessThanEqual) {
    this->SetLessContent();
    EXPECT_LE(this->x, this->y);
}

TYPED_TEST(DequeTest, LessThanEqualSelf) {
    this->SetLessContent();
    EXPECT_LE(this->x, this->x);
}

TYPED_TEST(DequeTest, LessThanEqualSize) {
    this->SetLessSize();
    EXPECT_LE(this->x, this->y);
}

TYPED_TEST(DequeTest, LessThanEqualLarge) {
    this->SetLarge();
    EXPECT_LE(this->x, this->y);
    this->x[0] = 0;
    EXPECT_LE(this->x, this->y);
}

TYPED_TEST(DequeTest, GreaterThanEqualEmpty) {
    EXPECT_GE(this->y, this->x);
}

TYPED_TEST(DequeTest, GreaterThan) {
    this->SetLessContent();
    EXPECT_GT(this->y, this->x);
}

TYPED_TEST(DequeTest, GreaterThanSize) {
    this->SetLessSize();
    EXPECT_GT(this->y, this->x);
}

TYPED_TEST(DequeTest, GreaterThanLarge) {
    this->SetLarge();
    this->x[0] = 0;
    EXPECT_GE(this->y, this->x);
}

TYPED_TEST(DequeTest, GreaterThanEqual) {
    this->SetLessContent();
    EXPECT_GE(this->y, this->x);
}

TYPED_TEST(DequeTest, GreaterThanEqualSelf) {
    this->SetLessContent();
    EXPECT_GE(this->x, this->x);
}

TYPED_TEST(DequeTest, GreaterThanEqualSize) {
    this->SetLessSize();
    EXPECT_GE(this->y, this->x);
}

TYPED_TEST(DequeTest, GreaterThanEqualLarge) {
    this->SetLarge();
    EXPECT_GE(this->y, this->x);
    this->x[0] = 0;
    EXPECT_GE(this->y, this->x);
}

// --- operator [] ---

TYPED_TEST(DequeTest, IndexZero) {
    ASSERT_EQ(0, this->x.size());
    this->x.push_back(9);
    EXPECT_EQ(9, this->x[0]);
}

TYPED_TEST(DequeTest, IndexSizeMinusOne) {
    this->SetSame();
    ASSERT_EQ(10, this->x.size());
    this->x.push_back(9);
    EXPECT_EQ(9, this->x[this->x.size() - 1]);
}

// --- at ---

TYPED_TEST(DequeTest, AtZero) {
    ASSERT_EQ(0, this->x.size());
    this->x.push_back(9);
    EXPECT_EQ(9, this->x.at(0));
}

TYPED_TEST(DequeTest, AtSizeMinusOne) {
    this->SetSame();
    ASSERT_EQ(10, this->x.size());
    this->x.push_back(9);
    EXPECT_EQ(9, this->x.at(this->x.size() - 1));
}

TYPED_TEST(DequeTest, AtSizeMinusOneWhenSizeIsLarge) {
    this->SetLarge();
    ASSERT_EQ(this->s, this->x.size());
    this->x.push_back(9);
    EXPECT_EQ(9, this->x.at(this->x.size() - 1));
}

// --- back ---

TYPED_TEST(DequeTest, BackWhenSizeIsOne) {
    ASSERT_EQ(0, this->x.size());
    this->x.push_back(9);
    EXPECT_EQ(9, this->x.back());
}

TYPED_TEST(DequeTest, BackWhenSizeIsSmall) {
    this->SetSame();
    ASSERT_EQ(10, this->x.size());
    this->x.push_back(9);
    EXPECT_EQ(9, this->x.back());
}

TYPED_TEST(DequeTest, BackWhenSizeIsLarge) {
    this->SetLarge();
    ASSERT_EQ(this->s, this->x.size());
    this->x.push_back(9);
    EXPECT_EQ(9, this->x.back());
}

// --- clear ---

TYPED_TEST(DequeTest, ClearEmpty) {
    ASSERT_EQ(0, this->x.size());
    this->x.clear();
    ASSERT_EQ(0, this->x.size());
}

TYPED_TEST(DequeTest, ClearSmall) {
    this->SetSame();
    ASSERT_EQ(10, this->x.size());
    this->x.clear();
    ASSERT_EQ(0, this->x.size());
}

TYPED_TEST(DequeTest, ClearLarge) {
    this->SetLarge();
    ASSERT_EQ(this->s, this->x.size());
    this->x.clear();
    ASSERT_EQ(0, this->x.size());
}

// --- empty ---

TYPED_TEST(DequeTest, EmptyEmpty) {
    ASSERT_TRUE(this->x.empty());
}

TYPED_TEST(DequeTest, EmptySmall) {
    this->SetSame();
    ASSERT_FALSE(this->x.empty());
}

TYPED_TEST(DequeTest, EmptyLarge) {
    this->SetLarge();
    ASSERT_FALSE(this->x.empty());
}

// --- front ---

TYPED_TEST(DequeTest, FrontWhenSizeIsOne) {
    ASSERT_EQ(0, this->x.size());
    this->x.push_front(9);
    ASSERT_EQ(9, this->x.front());
}

TYPED_TEST(DequeTest, FrontWhenSizeIsSmall) {
    this->SetSame();
    ASSERT_EQ(10, this->x.size());
    this->x.push_front(9);
    ASSERT_EQ(9, this->x.front());
}

TYPED_TEST(DequeTest, FrontWhenSizeIsLarge) {
    this->SetLarge();
    ASSERT_EQ(this->s, this->x.size());
    this->x.push_front(9);
    ASSERT_EQ(9, this->x.front());
}

// --- pop_back ---

TYPED_TEST(DequeTest, PopBackWhenSizeIsOne) {
    ASSERT_EQ(0, this->x.size());
    this->x.push_back(0);
    ASSERT_EQ(1, this->x.size());
    this->x.pop_back();
    ASSERT_EQ(0, this->x.size());
}

TYPED_TEST(DequeTest, PopBackWhenSizeIsSmall) {
    this->SetSame();
    EXPECT_EQ(10, this->x.size());
    this->x.front() = 0;
    this->x.back() = 0;

    this->x.pop_back();
    EXPECT_EQ(9, this->x.size());

    EXPECT_EQ(0, this->x.front());
    EXPECT_NE(0, this->x.back());
}

TYPED_TEST(DequeTest, PopBackWhenSizeIsLarge) {
    this->SetLarge();
    ASSERT_EQ(this->s, this->x.size());
    this->x.front() = 0;
    this->x.back() = 0;

    this->x.pop_back();
    EXPECT_EQ(this->s - 1, this->x.size());

    EXPECT_EQ(0, this->x.front());
    EXPECT_NE(0, this->x.back());
}

// --- pop_front ---

TYPED_TEST(DequeTest, PopFrontWhenSizeIsOne) {
    ASSERT_EQ(0, this->x.size());
    this->x.push_front(0);
    ASSERT_EQ(1, this->x.size());
    this->x.pop_front();
    ASSERT_EQ(0, this->x.size());
}

TYPED_TEST(DequeTest, PopFrontWhenSizeIsSmall) {
    this->SetSame();
    EXPECT_EQ(10, this->x.size());
    this->x.front() = 0;
    this->x.back() = 0;

    this->x.pop_front();
    EXPECT_EQ(9, this->x.size());

    EXPECT_NE(0, this->x.front());
    EXPECT_EQ(0, this->x.back());
}

TYPED_TEST(DequeTest, PopFrontWhenSizeIsLarge) {
    this->SetLarge();
    ASSERT_EQ(this->s, this->x.size());
    this->x.front() = 0;
    this->x.back() = 0;

    this->x.pop_front();
    EXPECT_EQ(this->s - 1, this->x.size());

    EXPECT_NE(0, this->x.front());
    EXPECT_EQ(0, this->x.back());
}


// --- push_back ---

TYPED_TEST(DequeTest, PushBackSizeIsZero) {
    this->x.push_back(1);
    EXPECT_EQ(1, this->x.back());
}

TYPED_TEST(DequeTest, PushBackSizeIsSmall) {
    this->SetSame();
    this->x.push_back(1);
    EXPECT_EQ(1, this->x.back());
}

TYPED_TEST(DequeTest, PushBackSizeIsLarge) {
    this->SetLarge();
    this->x.push_back(1);
    EXPECT_EQ(1, this->x.back());
}

TYPED_TEST(DequeTest, PushBackBunch) {
    for(typename TestFixture::size_type i = 0; i < this->s; ++i)
        this->x.push_back(1);
    EXPECT_EQ(1, this->x.back());
    EXPECT_EQ(this->s, this->x.size());
}

// --- push_front ---

TYPED_TEST(DequeTest, PushFrontSizeIsZero) {
    this->x.push_front(1);
    EXPECT_EQ(1, this->x.front());
}

TYPED_TEST(DequeTest, PushFrontSizeIsSmall) {
    this->SetSame();
    this->x.push_front(1);
    EXPECT_EQ(1, this->x.front());
}

TYPED_TEST(DequeTest, PushFrontSizeIsLarge) {
    this->SetLarge();
    this->x.push_front(1);
    EXPECT_EQ(1, this->x.front());
}

TYPED_TEST(DequeTest, PushFrontBunch) {
    for(typename TestFixture::size_type i = 0; i < this->s; ++i)
        this->x.push_front(1);
    EXPECT_EQ(1, this->x.front());
    EXPECT_EQ(this->s, this->x.size());
}

// --- resize ---

TYPED_TEST(DequeTest, ResizeGrow) {
    this->SetSame();
    ASSERT_EQ(10, this->x.size());
    ASSERT_EQ(5, this->x.back());
    this->x.resize(11, 9);
    ASSERT_EQ(11, this->x.size());
    ASSERT_EQ(9, this->x.back());
}

TYPED_TEST(DequeTest, ResizeShrink) {
    this->SetSame();
    ASSERT_EQ(10, this->x.size());
    ASSERT_EQ(5, this->x.back());
    this->x.resize(4, 9);
    ASSERT_EQ(4, this->x.size());
    ASSERT_EQ(5, this->x.back());
}

TYPED_TEST(DequeTest, ResizeGrowLarge) {
    this->SetLarge();
    typename TestFixture::size_type larger = this->s * 2;
    ASSERT_EQ(this->s, this->x.size());
    ASSERT_EQ(5, this->x.back());
    this->x.resize(larger, 9);
    EXPECT_EQ(larger, this->x.size());
    ASSERT_EQ(9, this->x.back());
}

TYPED_TEST(DequeTest, ResizeShrinkLarge) {
    this->SetLarge();
    typename TestFixture::size_type smaller = this->s / 2;
    ASSERT_EQ(this->s, this->x.size());
    ASSERT_EQ(5, this->x.back());
    this->x.resize(smaller, 9);
    EXPECT_EQ(smaller, this->x.size());
    ASSERT_EQ(5, this->x.back());
}

// --- size ---

TYPED_TEST(DequeTest, SizeIsZero) {
    ASSERT_EQ(0, this->x.size());
}

TYPED_TEST(DequeTest, SizeIsSmall) {
    this->SetSame();
    EXPECT_EQ(10, this->x.size());
}

TYPED_TEST(DequeTest, SizeIsLarge) {
    this->SetLarge();
    EXPECT_EQ(this->s, this->x.size());
}


// --- swap ---

TYPED_TEST(DequeTest, SwapEmpty) {
    EXPECT_EQ(0, this->x.size());
    EXPECT_EQ(0, this->y.size());

    this->x.swap(this->y);

    EXPECT_EQ(0, this->x.size());
    EXPECT_EQ(0, this->y.size());
}

TYPED_TEST(DequeTest, SwapSmall) {
    this->SetDifferent();
    EXPECT_EQ(10, this->x.size());
    EXPECT_EQ(10, this->y.size());
    EXPECT_EQ(5, this->x[5]);
    EXPECT_EQ(3, this->y[5]);

    this->x.swap(this->y);

    EXPECT_EQ(10, this->x.size());
    EXPECT_EQ(10, this->y.size());
    EXPECT_EQ(3, this->x[5]);
    EXPECT_EQ(5, this->y[5]);

    this->y.push_back(5);
    EXPECT_EQ(11, this->y.size());

    this->x.swap(this->y);

    EXPECT_EQ(11, this->x.size());
    EXPECT_EQ(10, this->y.size());
    EXPECT_EQ(5, this->x[5]);
    EXPECT_EQ(3, this->y[5]);
}

TYPED_TEST(DequeTest, SwapLarge) {
    this->SetLarge();
    this->y[5] = 3;

    EXPECT_EQ(this->s, this->x.size());
    EXPECT_EQ(this->s, this->y.size());
    EXPECT_EQ(5, this->x[5]);
    EXPECT_EQ(3, this->y[5]);

    this->x.swap(this->y);

    EXPECT_EQ(this->s, this->x.size());
    EXPECT_EQ(this->s, this->y.size());
    EXPECT_EQ(3, this->x[5]);
    EXPECT_EQ(5, this->y[5]);

    this->y.push_back(5);
    EXPECT_EQ(this->s + 1, this->y.size());

    this->x.swap(this->y);

    EXPECT_EQ(this->s + 1, this->x.size());
    EXPECT_EQ(this->s, this->y.size());
    EXPECT_EQ(5, this->x[5]);
    EXPECT_EQ(3, this->y[5]);
}

/// The DequeIterTest class is a Google Test Fixture created to test the iterator and const iterator inner classes.
///
class DequeIterTest : public testing::Test
{
    public:
        MyDeque<int> d;

        virtual void SetUp() 
        {
            for(int i = 0; i < SIZE; ++i)
                d.push_back(i);
        }
}; 

TEST_F(DequeIterTest, for_each_read)
{
    int count = 0;
    for(auto i : d)
    {
        ASSERT_TRUE(i == count);
        ++count;
    }    
}

TEST_F(DequeIterTest, iter_read)
{
    int count = 0;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    while(b != e)
    {
        ASSERT_TRUE(*b == count);
        ++count;
        ++b;
    } 
}

TEST_F(DequeIterTest, iter_update)
{
    int count = 0;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    while(b != e)
    {
        ASSERT_TRUE(*b == count);
        *b += 1;
        ++count;
        ++b;
    }

    count = 1;
    b = d.begin();
    e = d.end();
    while(b != e)
    {
        ASSERT_TRUE(*b == count);
        ++count;
        ++b;
    }   
}

TEST_F(DequeIterTest, reverse_iter_read)
{
    int count = SIZE;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    while(b != e)
    {
        --e;
        --count;
        ASSERT_TRUE(*e == count);
    }
}

TEST_F(DequeIterTest, reverse_iter_update)
{
    int count = SIZE;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    while(b != e)
    {
        --e;
        --count;
        ASSERT_TRUE(*e == count);
        *e += 1;
    }

    count = SIZE;
    b = d.begin();
    e = d.end();
    while(b != e)
    {
        --e;
        ASSERT_TRUE(*e == count);
        --count;
    }
}

TEST_F(DequeIterTest, const_iter_read)
{
    int count = 0;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    while(cb != ce)
    {
        ASSERT_TRUE(*cb == count);
        ++count;
        ++cb;
    } 
}

TEST_F(DequeIterTest, const_reverse_iter_read)
{
    int count = SIZE;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    while(cb != ce)
    {
        --ce;
        --count;
        ASSERT_TRUE(*ce == count);
    }
}

TEST_F(DequeIterTest, iter_read_plus_equal)
{
    int count = 0;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    while(b != e)
    {
        ASSERT_TRUE(*b == count);
        ++count;
        b += 1;
    } 
}

TEST_F(DequeIterTest, iter_update_plus_equal)
{
    int count = 0;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    while(b != e)
    {
        ASSERT_TRUE(*b == count);
        *b += 1;
        ++count;
        b += 1;
    }

    count = 1;
    b = d.begin();
    e = d.end();
    while(b != e)
    {
        ASSERT_TRUE(*b == count);
        ++count;
        b += 1;
    }   
}

TEST_F(DequeIterTest, reverse_iter_read_minus_equal)
{
    int count = SIZE;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    while(b != e)
    {
        e -= 1;
        --count;
        ASSERT_TRUE(*e == count);
    }
}

TEST_F(DequeIterTest, reverse_iter_update_minus_equal)
{
    int count = SIZE;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    while(b != e)
    {
        e -= 1;
        --count;
        ASSERT_TRUE(*e == count);
        *e += 1;
    }

    count = SIZE;
    b = d.begin();
    e = d.end();
    while(b != e)
    {
        e -= 1;
        ASSERT_TRUE(*e == count);
        --count;
    }
}

TEST_F(DequeIterTest, const_iter_read_plus_equal)
{
    int count = 0;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    while(cb != ce)
    {
        ASSERT_TRUE(*cb == count);
        ++count;
        cb += 1;
    } 
}

TEST_F(DequeIterTest, const_reverse_iter_read_minus_equal)
{
    int count = SIZE;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    while(cb != ce)
    {
        ce -= 1;
        --count;
        ASSERT_TRUE(*ce == count);
    }
}

TEST_F(DequeIterTest, iter_read_plus_equal_ten)
{
    int count = 0;
    MyDeque<int>::iterator b = d.begin();
    while((size_t) count < d.size())
    {
        ASSERT_TRUE(*b == count);
        count += 10;
        b += 10;
    } 
}

TEST_F(DequeIterTest, reverse_iter_read_plus_equal_ten)
{
    int count = SIZE;
    MyDeque<int>::iterator e = d.end();
    while(count >= 10)
    {
        e += -10;
        count += -10;
        ASSERT_TRUE(*e == count);
    }
}

TEST_F(DequeIterTest, iter_read_minus_equal_ten)
{
    int count = 0;
    MyDeque<int>::iterator b = d.begin();
    while((size_t) count < d.size())
    {
        ASSERT_TRUE(*b == count);
        count -= -10;
        b -= -10;
    } 
}

TEST_F(DequeIterTest, reverse_iter_read_minus_equal_ten)
{
    int count = SIZE;
    MyDeque<int>::iterator e = d.end();
    while(count >= 10)
    {
        e -= 10;
        count -= 10;
        ASSERT_TRUE(*e == count);
    }
}

TEST_F(DequeIterTest, const_iter_read_plus_equal_ten)
{
    int count = 0;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    while((size_t) count < d.size())
    {
        ASSERT_TRUE(*cb == count);
        count += 10;
        cb += 10;
    } 
}

TEST_F(DequeIterTest, const_reverse_iter_read_plus_equal_ten)
{
    int count = SIZE;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator ce = cd.end();
    while(count >= 10)
    {
        ce += -10;
        count += -10;
        ASSERT_TRUE(*ce == count);
    }
}

TEST_F(DequeIterTest, const_iter_read_minus_equal_ten)
{
    int count = 0;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    while((size_t) count < d.size())
    {
        ASSERT_TRUE(*cb == count);
        count -= -10;
        cb -= -10;
    } 
}

TEST_F(DequeIterTest, const_reverse_iter_read_minus_equal_ten)
{
    int count = SIZE;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator ce = cd.end();
    while(count >= 10)
    {
        ce -= 10;
        count -= 10;
        ASSERT_TRUE(*ce == count);
    }
}

TEST_F(DequeIterTest, iter_max_elem)
{
    ASSERT_TRUE(*std::max_element(d.begin(), d.end()) == ((int) d.size() - 1));
}

TEST_F(DequeIterTest, const_iter_max_elem)
{
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    ASSERT_TRUE(*std::max_element(cb, ce) == ((int) d.size() - 1));
}

TEST_F(DequeIterTest, iter_min_elem)
{
    ASSERT_TRUE(*std::min_element(d.begin(), d.end()) == 0);
}

TEST_F(DequeIterTest, const_iter_min_elem)
{
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    ASSERT_TRUE(*std::min_element(cb, ce) == 0);
}

TEST_F(DequeIterTest, iter_fill)
{
    std::fill(d.begin(), d.end(), d.size());
    for(auto i : d)
        ASSERT_TRUE(i == (int) d.size());
}

TEST_F(DequeIterTest, iter_fill_n)
{
    std::fill_n(d.begin(), 1, d.size());
    ASSERT_TRUE(d.front() == (int) d.size());

    int count = 1;
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::iterator e = d.end();
    ++b;
    while(b != e)
    {
        ASSERT_TRUE(*b == count);
        ++count;
        ++b;
    } 
}

TEST_F(DequeIterTest, iter_fill_n_max)
{
    std::fill_n(d.begin(), d.size(), d.size());
    for(auto i : d)
        ASSERT_TRUE(i == (int) d.size());
}

TEST_F(DequeIterTest, iter_plus)
{
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::iterator b = d.begin();
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    std::transform(cb, ce, b, std::bind2nd(std::plus<int>(), 1));
    ASSERT_TRUE(d.front() == 1);

    int count = 1;
    for(auto i : d)
    {
        ASSERT_TRUE(i == count);
        ++count;
    } 
}

TEST_F(DequeIterTest, iter_minus)
{
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    MyDeque<int>::iterator b = d.begin();
    std::transform(cb, ce, b, std::bind2nd(std::minus<int>(), 1));
    ASSERT_TRUE(d.front() == -1);

    int count = -1;
    for(auto i : d)
    {
        ASSERT_TRUE(i == count);
        ++count;
    } 
}

TEST_F(DequeIterTest, iter_multiply)
{
    int multiple = 2;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    MyDeque<int>::iterator b = d.begin();
    std::transform(cb, ce, b, std::bind2nd(std::multiplies<int>(), multiple));
    ASSERT_TRUE(d.front() == 0);

    int count = 0;
    for(auto i : d)
    {
        ASSERT_TRUE(i == (count * multiple));
        ++count;
    } 
}

TEST_F(DequeIterTest, iter_divide)
{
    int denominator = 2;
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    MyDeque<int>::iterator b = d.begin();
    std::transform(cb, ce, b, std::bind2nd(std::divides<int>(), denominator));
    ASSERT_TRUE(d.front() == 0);

    int count = 0;
    for(auto i : d)
    {
        ASSERT_TRUE(i == (count / denominator));
        ++count;
    } 
}

TEST_F(DequeIterTest, iter_negate)
{
    const MyDeque<int> cd = const_cast< MyDeque<int>& >(d);
    MyDeque<int>::const_iterator cb = cd.begin();
    MyDeque<int>::const_iterator ce = cd.end();
    MyDeque<int>::iterator b = d.begin();
    std::transform(cb, ce, b, std::negate<int>());
    ASSERT_TRUE(d.front() == 0);

    int count = 0;
    for(auto i : d)
    {
        ASSERT_TRUE(i == count);
        --count;
    } 
}

TEST_F(DequeIterTest, iter_replace)
{
    std::replace(d.begin(), d.end(), 0, SIZE);
    ASSERT_TRUE(d.front() == SIZE);
}