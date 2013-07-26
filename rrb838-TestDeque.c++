// For Rayne Beridon and Spencer Mosley
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

// ---------
// TestDeque
// ---------

template <typename C>
struct TestDeque : CppUnit::TestFixture {
    // ----
    // size
    // ----

    void test_size_empty () {
        const C x;
        CPPUNIT_ASSERT(x.size() == 0);}
    void test_size_one () {
        C x;
        x.push_back(1);
        CPPUNIT_ASSERT(x.size() == 1);}
    void test_size_backtoempty() {
        C x;
        x.push_back(1);
        CPPUNIT_ASSERT(x.size() == 1);
        x.pop_back();
        CPPUNIT_ASSERT(x.size() == 0);}

    void test_access_array_1() {
        C x(3,1);
        //x.push_front(13);
        //CPPUNIT_ASSERT(x[0] == 13);}
    x.push_front(0);
        CPPUNIT_ASSERT(x[0] == 0);}
    void test_access_array_2() {
        C x;
        x.push_back(13);
        x.push_back(13);
        x.push_back(99999);
        x.push_back(13);
        x.push_back(13);
        CPPUNIT_ASSERT(x[2] == 99999);}
    void test_access_array_3() {
        C x;
        x.push_back(13);
        x.pop_back();
        x.push_back(19);
        x.push_back(23);
        x.push_back(34);
        x.push_back(399);
        x.pop_back();
        CPPUNIT_ASSERT(x[2] == 34);}

    void test_access_atmethod_1() {
        C x;
        x.push_back(14);
        CPPUNIT_ASSERT(x.at(0) == 14);}
    void test_access_atmethod_2() {
        C x;
        x.push_back(999);
        x.push_back(999);
        x.push_back(13);
        x.push_back(999);
        x.push_back(999);
        CPPUNIT_ASSERT(x.at(2) == 13);}
    void test_access_atmethod_3() {
        C x;
        x.push_back(0);
        x.pop_back();
        x.push_back(14);
        x.push_back(999);
        x.push_back(345);
        CPPUNIT_ASSERT(x.at(2) == 345);}

    void test_access_front_1() {
        C x;
        x.push_back(13);
        x.push_back(14);
        CPPUNIT_ASSERT(x.front() == 13);}
    void test_access_front_2() {
        C x;
        x.push_back(0);
        x.push_back(2000);
        x.pop_back();
        CPPUNIT_ASSERT(x.front() == 0);}
    void test_access_front_3() {
        C x;
        x.push_back(-19);
        x.pop_back();
        x.push_back(14);
        x.push_back(0);
        CPPUNIT_ASSERT(x.front() == 14);}

    void test_empty_1() {
        C x;
        x.push_back(13);
        x.push_back(14);
        x.pop_back();
        x.pop_back();
        CPPUNIT_ASSERT(x.empty());}
    void test_empty_2() {
        C x;
        x.push_back(0);
        x.push_back(2000);
        x.erase(x.begin());
        x.erase(x.begin());
        CPPUNIT_ASSERT(x.empty());}
    void test_empty_3() {
        C x;
        x.push_back(-19);
        x.pop_back();
        x.push_back(14);
        x.push_back(0);
        x.clear();
        CPPUNIT_ASSERT(x.empty());}

    void test_operatoreqeq_1() {
        C x;
        x.push_back(13);
        x.push_back(14);
        C y;
        y.push_back(13);
        y.push_back(14);
        CPPUNIT_ASSERT(x == y);}
    void test_operatoreqeq_2() {
        C x;
        x.push_back(99);
        x.push_back(0);
        x.push_back(54);
        C y;
        y.push_back(99);
        y.push_back(0);
        y.push_back(54);
        CPPUNIT_ASSERT(x == y);}
    void test_operatoreqeq_3() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        x.push_back(0);
        C y;
        y.push_back(123);
        y.push_back(456);
        y.push_back(789);
        y.push_back(0);
        CPPUNIT_ASSERT(x == y);}

    void test_back_1() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        CPPUNIT_ASSERT(x.back() == 789);}
    void test_back_2() {
        C x;
        x.push_back(123);
        x.push_front(0);
        x.push_back(789);
        CPPUNIT_ASSERT(x.back() == 789);}
    void test_back_3() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        x.pop_back();
        CPPUNIT_ASSERT(x.back() == 456);}

    void test_front_1() {
        C x;
        x.push_front(123);
        x.push_front(456);
        x.push_front(789);
        CPPUNIT_ASSERT(x.front() == 789);}
    void test_front_2() {
        C x;
        x.push_front(123);
        x.push_back(0);
        x.push_front(789);
        CPPUNIT_ASSERT(x.front() == 789);}
    void test_front_3() {
        C x;
        x.push_front(123);
        x.push_front(456);
        x.push_front(789);
        x.pop_front();
        CPPUNIT_ASSERT(x.front() == 456);}

    void test_arrow_1() {
        C x;
        C* y = &x;
        assert(y->empty());
    }

    void test_iterator_1() {
        C x;
        x.push_front(123);
        x.push_front(456);
        x.push_front(789);
        typename C::iterator y = x.begin();
        CPPUNIT_ASSERT(*y == 789);
    }
    void test_iterator_2() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::iterator y = x.begin();
        CPPUNIT_ASSERT(*y == 123);
    }
    void test_iterator_3() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::iterator y = x.end();
        --y;
        CPPUNIT_ASSERT(*y == 789);
    }
    void test_iterator_4() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::iterator a = x.begin();
        typename C::iterator y = x.end();
        int i = 0;
        while (a != y) { 
            CPPUNIT_ASSERT(*a++ == x[i++]);
        }
        CPPUNIT_ASSERT(a == y);
    }
    void test_iterator_5() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::iterator a = x.begin();
        typename C::iterator y = x.end();
        int i = x.size() - 1;
        --y;
        while (a != y) { 
            CPPUNIT_ASSERT(*y-- == x[i--]);
        }
        CPPUNIT_ASSERT(a == y);
    }
    void test_iterator_6() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::iterator a = x.begin();
        typename C::iterator y = x.end();
        a += (x.size());
        CPPUNIT_ASSERT(a == y);
    }
    void test_iterator_7() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::iterator a = x.begin();
        typename C::iterator y = x.end();
        y -= (x.size());
        CPPUNIT_ASSERT(a == y);
    }
    void test_iterator_8() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::iterator a = x.begin();
        typename C::iterator y = x.end();
        a += 2;
        y--;
        CPPUNIT_ASSERT(a == y);
    }
    void test_iterator_9() {
        C x;
        for (int i = 1; i <= 8; ++i) {
            x.push_back(i);
        }
        typename C::iterator y = x.end();
        y--;
        y -= 4;
        CPPUNIT_ASSERT(*y == 4);
    }
    void test_const_iterator_1() {
        C x;
        x.push_front(123);
        x.push_front(456);
        x.push_front(789);
        typename C::const_iterator y = x.begin();
        CPPUNIT_ASSERT(*y == 789);
    }
    void test_const_iterator_2() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::const_iterator y = x.begin();
        CPPUNIT_ASSERT(*y == 123);
    }
    void test_const_iterator_3() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::const_iterator y = x.end();
        --y;
        CPPUNIT_ASSERT(*y == 789);
    }
    void test_const_iterator_4() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::const_iterator a = x.begin();
        typename C::const_iterator y = x.end();
        int i = 0;
        while (a != y) { 
            CPPUNIT_ASSERT(*a++ == x[i++]);
        }
        CPPUNIT_ASSERT(a == y);
    }
    void test_const_iterator_5() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::const_iterator a = x.begin();
        typename C::const_iterator y = x.end();
        int i = x.size() - 1;
        --y;
        while (a != y) { 
            CPPUNIT_ASSERT(*y-- == x[i--]);
        }
        CPPUNIT_ASSERT(a == y);
    }
    void test_const_iterator_6() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::const_iterator a = x.begin();
        typename C::const_iterator y = x.end();
        a += (x.size());
        CPPUNIT_ASSERT(a == y);
    }
    void test_const_iterator_7() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::const_iterator a = x.begin();
        typename C::const_iterator y = x.end();
        y -= (x.size());
        CPPUNIT_ASSERT(a == y);
    }
    void test_const_iterator_8() {
        C x;
        x.push_back(123);
        x.push_back(456);
        x.push_back(789);
        typename C::const_iterator a = x.begin();
        typename C::const_iterator y = x.end();
        a += 2;
        y--;
        CPPUNIT_ASSERT(a == y);
    }
    void test_const_iterator_9() {
        C x;
        for (int i = 1; i <= 8; ++i) {
            x.push_back(i);
        }
        typename C::const_iterator y = x.end();
        y--;
        y -= 4;
        CPPUNIT_ASSERT(*y == 4);
    }

    



    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
    CPPUNIT_TEST(test_size_empty);
    CPPUNIT_TEST(test_size_one);
    CPPUNIT_TEST(test_size_backtoempty);
    CPPUNIT_TEST(test_access_array_1);
    CPPUNIT_TEST(test_access_array_2);
    CPPUNIT_TEST(test_access_array_3);
    CPPUNIT_TEST(test_access_atmethod_1);
    CPPUNIT_TEST(test_access_atmethod_2);
    CPPUNIT_TEST(test_access_atmethod_3);
    CPPUNIT_TEST(test_access_front_1);
    CPPUNIT_TEST(test_access_front_2);
    CPPUNIT_TEST(test_access_front_3);
    CPPUNIT_TEST(test_empty_1);
    CPPUNIT_TEST(test_empty_2);
    CPPUNIT_TEST(test_empty_3);
    CPPUNIT_TEST(test_operatoreqeq_1);
    CPPUNIT_TEST(test_operatoreqeq_2);
    CPPUNIT_TEST(test_operatoreqeq_3);
    CPPUNIT_TEST(test_back_1);
    CPPUNIT_TEST(test_back_2);
    CPPUNIT_TEST(test_back_3);
    CPPUNIT_TEST(test_front_1);
    CPPUNIT_TEST(test_front_2);
    CPPUNIT_TEST(test_front_3);
    CPPUNIT_TEST(test_arrow_1);
    CPPUNIT_TEST(test_arrow_1);
    CPPUNIT_TEST(test_iterator_1);
    CPPUNIT_TEST(test_iterator_2);
    CPPUNIT_TEST(test_iterator_3);
    CPPUNIT_TEST(test_iterator_4);
    CPPUNIT_TEST(test_iterator_5);
    CPPUNIT_TEST(test_iterator_6);
    CPPUNIT_TEST(test_iterator_7);
    CPPUNIT_TEST(test_iterator_8);
    CPPUNIT_TEST(test_iterator_9);
    CPPUNIT_TEST(test_const_iterator_1);
    CPPUNIT_TEST(test_const_iterator_2);
    CPPUNIT_TEST(test_const_iterator_3);
    CPPUNIT_TEST(test_const_iterator_4);
    CPPUNIT_TEST(test_const_iterator_5);
    CPPUNIT_TEST(test_const_iterator_6);
    CPPUNIT_TEST(test_const_iterator_7);
    CPPUNIT_TEST(test_const_iterator_8);
    CPPUNIT_TEST(test_const_iterator_9);
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
    //tr.addTest(TestDeque<   deque<int> >::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
