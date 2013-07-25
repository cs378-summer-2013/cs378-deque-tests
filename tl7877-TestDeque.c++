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
#include <cstring> // strcmp
#include <deque> // deque
#include <sstream> // ostringstream
#include <stdexcept> // invalid_argument
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TestRunner

#include "Deque.h"

// ---------
// TestDeque
// ---------

template <typename C>
struct TestDeque : CppUnit::TestFixture {
    // ----
    // size
    // ----

    void test_size () {
        const C x;
        CPPUNIT_ASSERT(x.size() == 0);}

    void test_size_2 () {
        C x(2);
        x.push_front(1);
        CPPUNIT_ASSERT(x.size() == 3);}

    void test_size_3 () {
        C x(2);
        x.push_back(1);
        CPPUNIT_ASSERT(x.size() == 3);}

    void test_size_4 () {
        C x;
        x.push_back(1);
        CPPUNIT_ASSERT(x.back() == 1);
        CPPUNIT_ASSERT(x.front() == 1);}

    void test_push_front () {
        C x(1);
        int i = 2;
        x.push_front(i);
        x.push_front(3);
        x.push_front(4);
        x.push_front(5);
        x.push_front(6);
        x.push_front(7);
        x.push_front(8);
        x.push_front(9);
        CPPUNIT_ASSERT(x.size() == 9);
        CPPUNIT_ASSERT(true);}

    void test_push_front_2 () {
        C x;
        x.push_front(7);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(true);}

    void test_push_front_3 () {
        C x(10);
        int i = 2;
        x.push_front(i);
        CPPUNIT_ASSERT(x.size() == 11);
        CPPUNIT_ASSERT(true);}

    void test_push_back () {
        C x(1);
        int i = 2;
        x.push_back(i);
        x.push_back(3);
        x.push_back(4);
        x.push_back(5);
        x.push_back(6);
        x.push_back(7);
        x.push_back(8);
        x.push_back(9);
        CPPUNIT_ASSERT(x.size() == 9);
        CPPUNIT_ASSERT(true);}

    void test_push_back_2 () {
        C x;
        x.push_back(7);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(true);}

    void test_push_back_3 () {
        C x(10);
        int i = 2;
        x.push_back(i);
        CPPUNIT_ASSERT(x.size() == 11);
        CPPUNIT_ASSERT(true);}

    void test_constructor () {
        C x(2);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(true);}

    void test_constructor_2 () {
        C x(4);
        CPPUNIT_ASSERT(x.size() == 4);
        CPPUNIT_ASSERT(true);}

    void test_constructor_3 () {
        C x(45);
        CPPUNIT_ASSERT(x.size() == 45);
        CPPUNIT_ASSERT(true);}

    void test_equals() {
        C x(1);
        C y(2);
        CPPUNIT_ASSERT((x == y) == false);
        CPPUNIT_ASSERT(true);}
 
    void test_equals_2() {
        C x(1);
        C y(1);
        CPPUNIT_ASSERT((x == y) == true);
        CPPUNIT_ASSERT(true);}

    void test_equals_3() {
        C x;
        C y;
        CPPUNIT_ASSERT((x == y) == true);
        CPPUNIT_ASSERT(true);}

    void test_equals_4() {
        C x;
        x.push_back(1);
        x.push_back(1);
        C y;
        y.push_back(1);
        y.push_back(1);
        CPPUNIT_ASSERT((x == y) == true);
        CPPUNIT_ASSERT(true);}

    void test_indexing() {
        C x(2);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x[0] == 0);
        CPPUNIT_ASSERT(true);}

    void test_indexing_2() {
        const C x(2);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x[0] == 0);
        CPPUNIT_ASSERT(true);}

    void test_indexing_3() {
        C x(2);
        x.push_front(2);
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(x[0] == 2);
        CPPUNIT_ASSERT(true);}

    void test_indexing_4() {
        C x(2);
        x.push_back(2);
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(x[2] == 2);
        CPPUNIT_ASSERT(true);}

    void test_at() {
        try {
            const C x(2);
            CPPUNIT_ASSERT(x.size() == 2);
            CPPUNIT_ASSERT(x.at(0) == 0);
        } catch (std::out_of_range& e) {
            CPPUNIT_ASSERT(false);
        }}

    void test_at_2() {
        const C x(2);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x.at(0) == 0);
        CPPUNIT_ASSERT(true);}

    void test_at_3() {
        try {
            C x(2);
            x.push_front(2);
            CPPUNIT_ASSERT(x.size() == 3);
            CPPUNIT_ASSERT(x.at(5) == 2);
        } catch (std::out_of_range& e) {
            CPPUNIT_ASSERT(true);
        }}

    void test_at_4() {
        C x(2);
        x.push_back(2);
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(x.at(2) == 2);
        CPPUNIT_ASSERT(true);}

    void test_back() {
        C x(2);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x.back() == 0);
        CPPUNIT_ASSERT(true);}

    void test_back_2() {
        C x(2);
        x.push_front(4);
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(x.back() == 0);
        CPPUNIT_ASSERT(true);}

    void test_back_3() {
        C x(2);
        x.push_back(4);
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(x.back() == 4);
        CPPUNIT_ASSERT(true);}

    void test_clear() {
        C x(2);
        x.clear();
        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(true);}

    void test_clear_2() {
        C x(50);
        x.push_front(10);
        x.clear();
        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(true);}

    void test_clear_3() {
        C x(2);
        x.push_front(10);
        x.clear();
        x.push_front(9);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(true);}

    void test_empty() {
        C x(2);
        x.push_front(10);
        x.clear();
        x.push_front(9);
        CPPUNIT_ASSERT(!x.empty());
        CPPUNIT_ASSERT(true);}

    void test_empty_2() {
        C x(2);
        x.push_front(10);
        x.clear();
        CPPUNIT_ASSERT(x.empty());
        CPPUNIT_ASSERT(true);}

    void test_front() {
        C x(1);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(x.front() == 0);
        CPPUNIT_ASSERT(true);}

    void test_front_2() {
        C x(2);
        x.push_front(4);
        x.push_back(10);
        x.push_front(3);
        CPPUNIT_ASSERT(x.size() == 5);
        CPPUNIT_ASSERT(x.front() == 3);
        CPPUNIT_ASSERT(true);}

    void test_front_3() {
        C x(2);
        x.push_back(4);
        
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(x.front() == 0);
        CPPUNIT_ASSERT(true);}

    void test_pop_back() {
        C x(2);
        x.push_back(4);
        x.push_back(5);
        x.pop_back();
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(x.back() == 4);
        CPPUNIT_ASSERT(true);}

    void test_pop_back_2() {
        C x(2);
        x.push_back(4);
        x.push_back(5);
        x.pop_back();
        x.push_back(6);
        CPPUNIT_ASSERT(x.size() == 4);
        CPPUNIT_ASSERT(x.back() == 6);
        CPPUNIT_ASSERT(true);}

    void test_pop_back_3() {
        C x(2);
        x.push_back(4);
        x.push_back(5);
        x.pop_back();
        x.push_front(6);
        CPPUNIT_ASSERT(x.size() == 4);
        CPPUNIT_ASSERT(x.back() == 4);
        CPPUNIT_ASSERT(true);}

    void test_pop_front() {
        C x(1);
        x.push_back(4);
        x.push_back(5);
        x.pop_front();
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x.front() == 4);
        CPPUNIT_ASSERT(true);}

    void test_pop_front_2() {
        C x(1);
        x.push_back(4);
        x.push_back(5);
        x.pop_back();
        x.pop_front();
        x.pop_front();
        CPPUNIT_ASSERT(x.size() == 0);
        CPPUNIT_ASSERT(true);}

    void test_pop_front_3() {
        C x;
        x.push_back(4);
        x.push_back(5);
        x.pop_front();
        x.push_front(6);
        
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x.back() == 5);
        CPPUNIT_ASSERT(x.front() == 6);
        CPPUNIT_ASSERT(true);}

    void test_assign() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(4);
        x = y;
        CPPUNIT_ASSERT(x.size() == 4);
        CPPUNIT_ASSERT(true);}

    void test_assign_2() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(4);
        x = y;
        x.push_front(3);
        CPPUNIT_ASSERT(x.size() == 5);
        CPPUNIT_ASSERT(x.front() == 3);
        CPPUNIT_ASSERT(true);}

    void test_assign_3() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(4);
        x = y;
        x.push_front(3);
        x.push_back(6);
        CPPUNIT_ASSERT(x.size() == 6);
        CPPUNIT_ASSERT(x.front() == 3);
        CPPUNIT_ASSERT(x.back() == 6);
        CPPUNIT_ASSERT(x.at(0) == 3);
        CPPUNIT_ASSERT(true);}

    void test_copy() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(x);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(y.at(0) == 4);
        CPPUNIT_ASSERT(true);}

    void test_copy_2() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(x);
        y.push_front(7);
        y.push_front(10);
        CPPUNIT_ASSERT(y.size() == 4);
        CPPUNIT_ASSERT(y.at(0) == 10);
        CPPUNIT_ASSERT(true);}

    void test_copy_3() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(x);
        y.push_front(7);
        y.push_front(10);
        y.pop_back();
        CPPUNIT_ASSERT(y.size() == 3);
        CPPUNIT_ASSERT(y.at(0) == 10);
        CPPUNIT_ASSERT(y.back() == 4);
        CPPUNIT_ASSERT(true);}

    void test_compare() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(x);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(x == y);
        CPPUNIT_ASSERT(true);}

    void test_compare_2() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(x);
        x.push_back(6);
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(!(x == y));
        CPPUNIT_ASSERT(true);}

    void test_less() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(x);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(!(x < y));
        CPPUNIT_ASSERT(true);}

    void test_less_2() {
        C x;
        x.push_back(4);
        x.push_back(5);
        C y(x);
        x.push_back(6);
        CPPUNIT_ASSERT(x.size() == 3);
        CPPUNIT_ASSERT(y.size() == 2);
        CPPUNIT_ASSERT(y < x);
        CPPUNIT_ASSERT(true);}

    void test_iterator() {
        C x;
        x.push_back(2);
        x.push_back(3);
        typename C::iterator b = x.begin();
        CPPUNIT_ASSERT(*b == 2);
        ++b;
        CPPUNIT_ASSERT(*b == 3);
        *b = 4;
        CPPUNIT_ASSERT(*b == 4);}

    void test_iterator_2() {
        C x;
        x.push_back(2);
        x.push_back(3);
        C y(x);
        typename C::iterator b = x.begin();
        typename C::iterator a = y.begin();
        CPPUNIT_ASSERT(*b == *a);
        ++b;
        CPPUNIT_ASSERT(*b == 3);
        *a = 4;
        *b = 4;
        CPPUNIT_ASSERT(*b == *a);}

    void test_iterator_3() {
        C x;
        x.push_back(2);
        x.push_back(3);
        C y(x);
        typename C::iterator b = x.begin();
        typename C::iterator a = y.begin();
        CPPUNIT_ASSERT(*b == *a);
        ++b;
        CPPUNIT_ASSERT(*b == 3);
        *a = *b;
        *b = 4;
        CPPUNIT_ASSERT(*b != *a);}

    void test_erase() {
        C x;
        x.push_back(2);
        x.push_back(3);
        typename C::iterator b = x.begin();
        CPPUNIT_ASSERT(*b == 2);
        ++b;
        CPPUNIT_ASSERT(*b == 3);
        x.erase(b);
        CPPUNIT_ASSERT(*b == 3);}

    void test_erase_2() {
        C x;
        x.push_back(2);
        x.push_back(3);
        typename C::iterator b = x.begin();
        CPPUNIT_ASSERT(*b == 2);
        ++b;
        CPPUNIT_ASSERT(*b == 3);
        x.erase(b);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(*b == 3);
        x.push_back(4);
        CPPUNIT_ASSERT(x.back() == 4);}

    void test_erase_3() {
        C x;
        x.push_back(2);
        x.push_back(3);
        typename C::iterator b = x.begin();
        CPPUNIT_ASSERT(*b == 2);
        ++b;
        CPPUNIT_ASSERT(*b == 3);
        x.erase(b);
        CPPUNIT_ASSERT(x.size() == 1);
        CPPUNIT_ASSERT(*b == 3);
        x.push_back(4);
        x.push_back(5);
        x.push_front(5);
        x.push_front(7);
        //++b;
        x.erase(b);
        CPPUNIT_ASSERT(x.back() == 5);}

    void test_insert() {
        C x;
        x.push_back(2);
        x.push_back(3);
        typename C::iterator b = x.begin();
        CPPUNIT_ASSERT(*b == 2);
        b++;
        CPPUNIT_ASSERT(*b == 3);
        x.insert(b, 9);
        CPPUNIT_ASSERT(*b == 9);
        CPPUNIT_ASSERT(x.front() == 2);
        CPPUNIT_ASSERT(x.back() == 3);}


    void test_insert_2() {
        C x(8);
        x.push_back(2);
        x.push_back(3);
        typename C::iterator b = x.begin();
        CPPUNIT_ASSERT(*b == 0);
        b += 8;
        CPPUNIT_ASSERT(*b == 2);
        x.insert(b, 9);
        CPPUNIT_ASSERT(*b == 9);
        b++;
        CPPUNIT_ASSERT(*b == 2);
        CPPUNIT_ASSERT(x.back() == 3);}

    void test_insert_3() {
        C x(2);
        typename C::iterator b = x.begin();
        CPPUNIT_ASSERT(*b == 0);
        b++;
        x.erase(b);
        x.insert(b, 9);
        CPPUNIT_ASSERT(*b == 9);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(x.back() == 9);
        CPPUNIT_ASSERT(x.front() == 0);}

    void test_resize() {
        C x;
        for(int i = 1; i < 10; i++)
            x.push_back(i);
        x.resize(5);
        CPPUNIT_ASSERT(x.size() == 5);}

    void test_resize_2() {
        C x;
        for(int i = 1; i < 10; i++)
            x.push_back(i);
        x.resize(5);
        x.push_back(0);
        x.push_back(10);
        CPPUNIT_ASSERT(x.size() == 7);
        CPPUNIT_ASSERT(x.back() == 10);
        CPPUNIT_ASSERT(x.front() == 1);}

    void test_swap() {
        C x;
        for(int i = 1; i < 10; i++)
            x.push_back(i);
        x.resize(5);

        C y(2);
        x.swap(y);
        CPPUNIT_ASSERT(x.size() == 2);
        CPPUNIT_ASSERT(y.size() == 5);
        CPPUNIT_ASSERT(x.front() == 0);
        CPPUNIT_ASSERT(y.front() == 1);}





    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
    CPPUNIT_TEST(test_size);
    CPPUNIT_TEST(test_size_2);
    CPPUNIT_TEST(test_size_3);
    CPPUNIT_TEST(test_size_4);
    CPPUNIT_TEST(test_push_front);
    CPPUNIT_TEST(test_push_front_2);
    CPPUNIT_TEST(test_push_front_3);
    CPPUNIT_TEST(test_push_back);
    CPPUNIT_TEST(test_push_back_2);
    CPPUNIT_TEST(test_push_back_3);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_equals_4);
    CPPUNIT_TEST(test_indexing);
    CPPUNIT_TEST(test_indexing_2);
    CPPUNIT_TEST(test_indexing_3);
    CPPUNIT_TEST(test_indexing_4);
    CPPUNIT_TEST(test_at);
    CPPUNIT_TEST(test_at_2);
    CPPUNIT_TEST(test_at_3);
    CPPUNIT_TEST(test_at_4);
    CPPUNIT_TEST(test_back);
    CPPUNIT_TEST(test_back_2);
    CPPUNIT_TEST(test_back_3);

    CPPUNIT_TEST(test_clear);
    CPPUNIT_TEST(test_clear_2);
    CPPUNIT_TEST(test_clear_3);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_empty_2);
    CPPUNIT_TEST(test_front);
    CPPUNIT_TEST(test_front_2);
    CPPUNIT_TEST(test_front_3);
    CPPUNIT_TEST(test_pop_back);
    CPPUNIT_TEST(test_pop_back_2);
    CPPUNIT_TEST(test_pop_back_3);
    CPPUNIT_TEST(test_pop_front);
    CPPUNIT_TEST(test_pop_front_2);
    CPPUNIT_TEST(test_pop_front_3);

    CPPUNIT_TEST(test_assign);
    CPPUNIT_TEST(test_assign_2);
    CPPUNIT_TEST(test_assign_3);
    CPPUNIT_TEST(test_copy);
    CPPUNIT_TEST(test_copy_2);
    CPPUNIT_TEST(test_copy_3);
    CPPUNIT_TEST(test_compare);
    CPPUNIT_TEST(test_compare_2);
    CPPUNIT_TEST(test_less);
    CPPUNIT_TEST(test_less_2);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_iterator_2);
    CPPUNIT_TEST(test_iterator_3);
    CPPUNIT_TEST(test_erase);
    CPPUNIT_TEST(test_erase_2);
    CPPUNIT_TEST(test_erase_3);
    CPPUNIT_TEST(test_insert);
    CPPUNIT_TEST(test_insert_2);
    CPPUNIT_TEST(test_insert_3);
    CPPUNIT_TEST(test_resize);
    CPPUNIT_TEST(test_resize_2);
    CPPUNIT_TEST(test_swap);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestDeque.c++" << endl << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDeque< MyDeque<int> >::suite());
    tr.addTest(TestDeque< deque<int> >::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}


