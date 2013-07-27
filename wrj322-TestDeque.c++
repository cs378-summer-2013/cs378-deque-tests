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
#include <exception>

#include <iostream>
#include "gtest/gtest.h"

/* Enable testing of private data members. */
#define private public
#define protected public

#include "Deque.h"

using namespace std;


/* 
    Test struct.
*/
struct A {

    // ~A() {
    //     cout << "~A()" << endl;
    // }

    // A() {
    //     cout << "A()" << endl;
    // }

    // A(const A&) {
    //     cout << "A(A)" << endl;
    // }
};

ostream& operator<<(ostream &output, const A) {
    return output << "A";
}

/* 
    Setting test fixture up for typed tests.
*/
typedef testing::Types< deque<int>, MyDeque<int> > implementationsToTest;

template <typename C>
class DequeTest : public testing::Test {
	protected:
		typedef typename C::value_type T;
        typedef C container_type;
        typedef typename C::iterator iterator;
        typedef typename C::const_iterator const_iterator;
		container_type x, y;
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

// TYPED_TEST(DequeTest, iterator_operator_equal_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, iterator_valid_01) {
// 	ASSERT_TRUE(false);
// }

TYPED_TEST(DequeTest, iterator_default_constructor_01) {	
    MyDeque<int> a(101, 3);
    deque<int> b(101, 3);
    MyDeque<int>::iterator itr = a.begin();
    deque<int>::iterator d_itr = b.begin();

    for (int i = 0; i < 101; ++i) {
        ASSERT_EQ(*itr, 3);
        ASSERT_EQ(*d_itr, 3);
        ++itr;
        ++d_itr;
    }
}

// TYPED_TEST(DequeTest, iterator_operator_deference_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, iterator_operator_increment_prefix_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, iterator_operator_decrement_prefix_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, iterator_operator_plus_equal_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, iterator_operator_minus_equal_01) {
// 	ASSERT_TRUE(false);
// }

/*  
--------------
const_iterator
--------------
*/

// TYPED_TEST(DequeTest, const_iterator_operator_equal_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, const_iterator_valid_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, const_iterator_default_constructor_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, const_iterator_operator_deference_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, const_iterator_operator_increment_prefix_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, const_iterator_operator_decrement_prefix_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, const_iterator_operator_plus_equal_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, const_iterator_operator_minus_equal_01) {
// 	ASSERT_TRUE(false);
// }

/*
----------------
MyDeque Specific
----------------
*/

TEST(MyDequeTest, capacity_01) {
    MyDeque<int> d;
    ASSERT_TRUE(d.capacity() == 30);
}

TEST(MyDequeTest, back_capacity_01) {
    MyDeque<int> d;
    ASSERT_TRUE(d.back_capacity() == 30);
}

TEST(MyDequeTest, constructor_fill_01) {
    
    MyDeque<int> a(101, 3);
    cout << "a.back_capacity(): " << a.back_capacity() << endl;
    ASSERT_EQ(a.size(), 101);
    ASSERT_TRUE(a.back_capacity() == 9);

    MyDeque<int> b(99, -14);
    cout << "b.back_capacity(): " << b.back_capacity() << endl;
    ASSERT_EQ(b.size(), 99);
    ASSERT_TRUE(b.back_capacity() == 1);
}

TEST(MyDequeTest, num_elements_back_block_01) {
    MyDeque<int> a;
    ASSERT_EQ(a.num_elements_back_block(), 0);
}

TEST(MyDequeTest, num_elements_back_block_02) {
    MyDeque<int> a (104, 3);
    ASSERT_EQ(a.num_elements_back_block(), 4);
}

TEST(MyDequeTest, constructor_copy_01) {
    
    MyDeque<int> a (104, 3);
    MyDeque<int> b(a);

    ASSERT_EQ(a.size(), b.size());
    ASSERT_EQ(a._size, b._size);
    ASSERT_EQ(a._block_allocator, b._block_allocator);
    ASSERT_EQ(a._outer_allocator, b._outer_allocator);
    ASSERT_EQ(a._pushed_front_yet, b._pushed_front_yet);
    ASSERT_EQ(a._pushed_back_yet, b. _pushed_back_yet);

    ASSERT_NE(a._beginning_block, b._beginning_block);
    ASSERT_NE(a._end_block, b._end_block);
    ASSERT_NE(a._deque_front_block, b._deque_front_block);
    ASSERT_NE(a._deque_back_block, b._deque_back_block);
    ASSERT_NE(a._deque_front, b._deque_front);
    ASSERT_NE(a._deque_back, b._deque_back);

    ASSERT_EQ(a._end_block-a._beginning_block, b._end_block-b._beginning_block);
    ASSERT_EQ(a._deque_back_block-a._deque_front_block, b._deque_back_block-b._deque_front_block);
    ASSERT_EQ(a._deque_front-*a._deque_front_block, b._deque_front-*b._deque_front_block);
    ASSERT_EQ(a._deque_back-*a._deque_back_block, b._deque_back-*b._deque_back_block);
  

}

TEST(MyDequeTest, deque_operator_index_01) {
    MyDeque<int> a(9, 7);
    ASSERT_EQ(a[0], 7);
    ASSERT_EQ(a[1], 7);
    ASSERT_EQ(a[2], 7);
    ASSERT_EQ(a[3], 7);
    ASSERT_EQ(a[4], 7);
    ASSERT_EQ(a[5], 7);
    ASSERT_EQ(a[6], 7);
    ASSERT_EQ(a[7], 7);
    ASSERT_EQ(a[8], 7);
    ASSERT_EQ(a[9], 0);
}

TEST(MyDequeTest, deque_operator_at_01) {
    MyDeque<int> a(9, 7);
    ASSERT_EQ(a.at(0), 7);
    ASSERT_EQ(a.at(1), 7);
    ASSERT_EQ(a.at(2), 7);
    ASSERT_EQ(a.at(3), 7);
    ASSERT_EQ(a.at(4), 7);
    ASSERT_EQ(a.at(5), 7);
    ASSERT_EQ(a.at(6), 7);
    ASSERT_EQ(a.at(7), 7);
    ASSERT_EQ(a.at(8), 7);
    try {
        ASSERT_EQ(a.at(9), 0);
        ASSERT_TRUE(false);
    }
    catch (out_of_range &e) {

    }
}


// TEST(MyDequeTest, resize_01) {

//     MyDeque<int> a(91, 7);
//     a.resize(57);
//     ASSERT_EQ(a.size(), 57);
//     ASSERT_EQ(a.back_capacity(), 43);
// }

// TEST(MyDequeTest, resize_02) {

//     MyDeque<A> a(91);
//     a.resize(57);
//     ASSERT_EQ(a.size(), 57);
//     ASSERT_EQ(a.back_capacity(), 43);
// }

// TEST(MyDequeTest, resize_03) {

//     MyDeque<int> a(91, 7);
//     a.resize(96);
//     ASSERT_EQ(a.size(), 96);
//     ASSERT_EQ(a.back_capacity(), 4);
// }

// TEST(MyDequeTest, resize_04) {

//     MyDeque<A> a(91);
//     a.resize(96);
//     ASSERT_EQ(a.size(), 96);
//     ASSERT_EQ(a.back_capacity(), 4);
// }

TEST(MyDequeTest, resize_05) {

    MyDeque<int> a(91, 7);
    a.resize(120, 8);
    ASSERT_EQ(a.size(), 120);
    ASSERT_EQ(a.back_capacity(), 0);
}

// TEST(MyDequeTest, resize_06) {

//     MyDeque<A> a(89);
//     a.resize(177);
//     ASSERT_EQ(a.size(), 177);
//     ASSERT_EQ(a.back_capacity(), 3);
// }

TEST(MyDequeTest, reserve_05) {
    MyDeque<int> a;
    typedef MyDeque<int>::value_type value_type;

    value_type **old_beg = a._beginning_block;
    value_type **old_end = a._end_block;
    value_type **old_deque_front_block = a._deque_front_block;
    value_type **old_deque_back_block = a._deque_back_block;
    value_type *old_deque_front = a._deque_front;
    value_type *old_deque_back = a._deque_back;

    a.reserve(167);

    ASSERT_NE(a._beginning_block, old_beg);
    ASSERT_NE(a._end_block, old_end);
    ASSERT_NE(a._deque_front_block, old_deque_front_block);
    ASSERT_NE(a._deque_back_block, old_deque_back_block);
    ASSERT_EQ(a._deque_front, old_deque_front);
    ASSERT_EQ(a._deque_back, old_deque_back);

    ASSERT_EQ(a.capacity(), 170);
}



/*
--------------------
MyDeque versus Deque
--------------------
*/

// TYPED_TEST(DequeTest, deque_operator_equal_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_operator_less_than_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_valid_01) {
// 	ASSERT_TRUE(false);
// }

TYPED_TEST(DequeTest, deque_constructor_allocator_01) {
    cout << "this->x.size(): " << this->x.size() << endl;
    cout << "this->y.size(): " << this->y.size() << endl;
	ASSERT_EQ(this->x.size(), 0);
	ASSERT_EQ(this->y.size(), 0);
}

// TYPED_TEST(DequeTest, deque_constructor_copy_01) {
	// this->container_type g = this->x;
 //    this->container_type h = this->y;

 //    ASSERT_TRUE(equal<T*, T*> (this->x._back_block, this->x._back_block, g._back_block));
        
// }

// TYPED_TEST(DequeTest, deque_destructor_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_operator_assignment_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_at_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_back_01) {
// 	ASSERT_TRUE(false);
// }

TYPED_TEST(DequeTest, deque_begin_01) {
	MyDeque<int> a(101, 3);
    deque<int> b(101, 3);

    MyDeque<int>::iterator md_b = a.begin();
    deque<int>::iterator    d_b = b.begin();

    MyDeque<int>::iterator md_e = a.end();
    // deque<int>::iterator    d_e = b.end();

    // int i = 1;
    while (md_b != md_e) {
        // cout << "i: " << i << endl;
        ASSERT_EQ(*md_b, 3);
        ASSERT_EQ(*d_b, 3);
        ++md_b;
         ++d_b;
         // ++i;
    }
}

// TYPED_TEST(DequeTest, deque_begin_02) {
//     MyDeque<int> a(101, 3);
//     deque<int> b(101, 3);

//     MyDeque<int>::const_iterator md_b = a.begin();
//     deque<int>::const_iterator    d_b = b.begin();

//     MyDeque<int>::const_iterator md_e = a.end();
//     // deque<int>::const_iterator    d_e = b.end();

//     // int i = 1;
//     while (md_b != md_e) {
//         // cout << "i: " << i << endl;
//         ASSERT_EQ(*md_b, 3);
//         ASSERT_EQ(*d_b, 3);
//         ++md_b;
//          ++d_b;
//          // ++i;
//     }
// }

// TYPED_TEST(DequeTest, deque_begin_const_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_clear_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_end_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_end_const_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_erase_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_front_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, deque_insert_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, pop_back_01) {
// 	ASSERT_TRUE(false);
// }

// TYPED_TEST(DequeTest, pop_front_01) {
// 	int limit = 1000;
// 	for (int i = 0; i <= limit; ++i) {
// 		this->x.push_front(i);
// 	}

// 	ASSERT_EQ(limit, this->x.front());
// 	ASSERT_EQ(0, this->x.back());

// 	for (int i = limit; i >= 0; --i) {
// 		ASSERT_EQ(i, this->x.front());
// 		ASSERT_EQ(0, this->x.back());
// 		this->x.pop_front();
// 	}
// 	ASSERT_TRUE(this->x.empty());
// }

TYPED_TEST(DequeTest, push_back_01) {
	this->x.push_back(1);
	ASSERT_EQ(1, this->x.back());
	ASSERT_EQ(1, this->x.front());

	this->x.push_back(2);
	ASSERT_EQ(2, this->x.back());
	ASSERT_EQ(1, this->x.front());

	this->x.push_back(3);
	ASSERT_EQ(3, this->x.back());
	ASSERT_EQ(1, this->x.front());

	this->x.push_back(4);
	ASSERT_EQ(4, this->x.back());
	ASSERT_EQ(1, this->x.front());
}
TYPED_TEST(DequeTest, push_back_02) {

	this->x.push_back(-2147483647);
	ASSERT_EQ(-2147483647, this->x.back());
	ASSERT_EQ(-2147483647, this->x.front());

	this->x.push_back(2147483647);
	ASSERT_EQ(2147483647, this->x.back());
	ASSERT_EQ(-2147483647, this->x.front());

}
TYPED_TEST(DequeTest, push_back_03) {
	int limit = 1000;

	for (int i = 0; i < limit; i++) {
		this->x.push_back(i);
		ASSERT_EQ(i, this->x.back());
		ASSERT_EQ(0, this->x.front());
	}
}


TYPED_TEST(DequeTest, push_front_01) {
	this->x.push_front(1);
	ASSERT_EQ(1, this->x.front());
	ASSERT_EQ(1, this->x.back());

	this->x.push_front(2);
	ASSERT_EQ(2, this->x.front());
	ASSERT_EQ(1, this->x.back());

	this->x.push_front(3);
	ASSERT_EQ(3, this->x.front());
	ASSERT_EQ(1, this->x.back());

	this->x.push_front(4);
	ASSERT_EQ(4, this->x.front());
	ASSERT_EQ(1, this->x.back());
}
TYPED_TEST(DequeTest, push_front_02) {

	this->x.push_front(-2147483647);
	ASSERT_EQ(-2147483647, this->x.front());
	ASSERT_EQ(-2147483647, this->x.back());

	this->x.push_front(2147483647);
	ASSERT_EQ(2147483647, this->x.front());
	ASSERT_EQ(-2147483647, this->x.back());

}
TYPED_TEST(DequeTest, push_front_03) {
	int limit = 1000;

	for (int i = 0; i < limit; i++) {
		this->x.push_front(i);
		ASSERT_EQ(i, this->x.front());
		ASSERT_EQ(0, this->x.back());
	}
}

// TYPED_TEST(DequeTest, resize_01) {
// 	ASSERT_TRUE(false);
// }

TYPED_TEST(DequeTest, size_01) {
	ASSERT_TRUE(this->x.size() == 0);
	ASSERT_TRUE(this->x.size() == 0);
}

// TYPED_TEST(DequeTest, swap_01) {
// 	ASSERT_TRUE(false);
// }



