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

using namespace std;
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
        const C x(50);
        CPPUNIT_ASSERT(x.size() == 50);}

    void test_size_3 () {
        const C x(500);
        CPPUNIT_ASSERT(x.size() == 500);}


    void test_allocate () {
                C x;
                x.push_back(5);
                x.push_back(6);
                x.push_back(7);
                x.push_front(3);
                CPPUNIT_ASSERT(x.at(0)== 3);
                CPPUNIT_ASSERT(x.at(1)== 5);
                CPPUNIT_ASSERT(x.at(2)== 6);
                CPPUNIT_ASSERT(x.at(3)== 7);
                CPPUNIT_ASSERT(x.size() == 4);}

        void test_push_front () {
                C x;
                x.push_front(5);
                x.push_front(6);
                x.push_front(7);
                x.push_front(8);
                x.push_front(9);
                x.push_front(10);
                x.push_front(11);
                x.push_front(12);
                x.push_front(13);
                x.push_front(14);
                x.push_front(15);
                x.push_front(16);
                CPPUNIT_ASSERT(x.at(0)== 16);
                CPPUNIT_ASSERT(x.at(1)== 15);
                CPPUNIT_ASSERT(x.at(2)== 14);
                CPPUNIT_ASSERT(x.at(3)== 13);
                CPPUNIT_ASSERT(x.at(4)== 12);
                CPPUNIT_ASSERT(x.at(5)== 11);
                CPPUNIT_ASSERT(x.at(6)== 10);
                CPPUNIT_ASSERT(x.at(7)== 9);
                CPPUNIT_ASSERT(x.at(8)== 8);
                CPPUNIT_ASSERT(x.at(9)== 7);
                CPPUNIT_ASSERT(x.at(10)== 6);
                CPPUNIT_ASSERT(x.at(11)== 5);
                CPPUNIT_ASSERT(x.size() == 12);}


    void test_push_front_2 () {
                C x;
                x.push_front(10);
                x.push_back(11);
                x.push_front(9);
                x.push_back(12);
                x.push_front(8);
                x.push_back(13);
                x.push_front(7);
                x.push_back(14);
                x.push_front(6);
                x.push_back(15);
                x.push_front(5);
                x.push_back(16);
                CPPUNIT_ASSERT(x.at(0)== 5);
                CPPUNIT_ASSERT(x.at(1)== 6);
                CPPUNIT_ASSERT(x.at(2)== 7);
                CPPUNIT_ASSERT(x.at(3)== 8);
                CPPUNIT_ASSERT(x.at(4)== 9);
                CPPUNIT_ASSERT(x.at(5)== 10);
                CPPUNIT_ASSERT(x.at(6)== 11);
                CPPUNIT_ASSERT(x.at(7)== 12);
                CPPUNIT_ASSERT(x.at(8)== 13);
                CPPUNIT_ASSERT(x.at(9)== 14);
                CPPUNIT_ASSERT(x.at(10)== 15);
                CPPUNIT_ASSERT(x.at(11)== 16);
                CPPUNIT_ASSERT(x.size() == 12);}

    void test_push_front_3 () {
                C x;
                x.push_front(10);
                x.push_front(11);
                x.push_front(12);
                x.push_front(13);
                x.push_front(14);
                CPPUNIT_ASSERT(x.at(0)== 14);
                CPPUNIT_ASSERT(x.at(1)== 13);
                CPPUNIT_ASSERT(x.at(2)== 12);
                CPPUNIT_ASSERT(x.at(3)== 11);
                CPPUNIT_ASSERT(x.at(4)== 10);
                CPPUNIT_ASSERT(x.size() == 5);}

    void test_push_back () {
                C x;
                x.push_back(5);
                CPPUNIT_ASSERT(x.at(0)== 5);
                CPPUNIT_ASSERT(x.size() == 1);
        }

    void test_push_back_2 () {
                C x;
                x.push_back(5);
                x.push_back(6);
                x.push_back(7);
                x.push_back(8);
                x.push_back(9);
                CPPUNIT_ASSERT(x.at(0)== 5);
                CPPUNIT_ASSERT(x.at(1)== 6);
                CPPUNIT_ASSERT(x.at(2)== 7);
                CPPUNIT_ASSERT(x.at(3)== 8);
                CPPUNIT_ASSERT(x.at(4)== 9);
                CPPUNIT_ASSERT(x.size() == 5);
        }


        void test_push_back_3 () {
                C x;
                x.push_back(5);
                x.push_back(6);
                x.push_back(7);
                x.push_back(8);
                x.push_back(9);
                x.push_back(10);
                x.push_back(11);
                x.push_back(12);
                x.push_back(13);
                x.push_back(14);
                x.push_back(15);
                x.push_back(16);
                x.push_back(17);
                CPPUNIT_ASSERT(x.at(0)== 5);
                CPPUNIT_ASSERT(x.at(1)== 6);
                CPPUNIT_ASSERT(x.at(2)== 7);
                CPPUNIT_ASSERT(x.at(3)== 8);
                CPPUNIT_ASSERT(x.at(4)== 9);
                CPPUNIT_ASSERT(x.at(5)== 10);
                CPPUNIT_ASSERT(x.at(6)== 11);
                CPPUNIT_ASSERT(x.at(7)== 12);
                CPPUNIT_ASSERT(x.at(8)== 13);
                CPPUNIT_ASSERT(x.at(9)== 14);
                CPPUNIT_ASSERT(x.at(10)== 15);
                CPPUNIT_ASSERT(x.at(11)== 16);
                CPPUNIT_ASSERT(x.at(12)== 17);
                CPPUNIT_ASSERT(x.size() == 13);
        }

        void test_insert () {
                C x;
                x.push_back(5);
                x.push_back(6);
                x.push_back(7);
                x.push_back(8);
                x.push_back(9);
                x.insert((x.begin() + 1) , 2);
                CPPUNIT_ASSERT(x.at(0)== 5);
                CPPUNIT_ASSERT(x.at(1)== 2);
                CPPUNIT_ASSERT(x.at(2)== 6);
                CPPUNIT_ASSERT(x.at(3)== 7);
                CPPUNIT_ASSERT(x.at(4)== 8);
                CPPUNIT_ASSERT(x.at(5)== 9);
                CPPUNIT_ASSERT(x.size() == 6);
        }


        void test_insert_2 () {
                C x;
                x.push_back(5);
                x.push_back(6);
                x.push_back(7);
                x.push_back(8);
                x.push_back(9);
                x.insert((x.begin() + 1) , 5);
                x.insert((x.begin() + 1) , 4);
                x.insert((x.begin() + 1) , 3);
                x.insert((x.begin() + 1) , 2);
                CPPUNIT_ASSERT(x.at(0)== 5);
                CPPUNIT_ASSERT(x.at(1)== 2);
                CPPUNIT_ASSERT(x.at(2)== 3);
                CPPUNIT_ASSERT(x.at(3)== 4);
                CPPUNIT_ASSERT(x.at(4)== 5);
                CPPUNIT_ASSERT(x.at(5)== 6);
                CPPUNIT_ASSERT(x.size() == 9);
        }

        void test_erase () {
                C x;
                x.push_back(5);
                x.push_back(6);
                x.push_back(7);
                x.push_back(8);
                x.push_back(9);
                CPPUNIT_ASSERT(x.size() == 5);
                x.erase((x.begin() + 1));
                CPPUNIT_ASSERT(x.at(0)== 5);
                CPPUNIT_ASSERT(x.at(1)== 7);
                CPPUNIT_ASSERT(x.at(2)== 8);
                CPPUNIT_ASSERT(x.at(3)== 9);
                CPPUNIT_ASSERT(x.size() == 4);
        }


        void test_erase_2 () {
                C x;
                x.push_back(5);
                x.push_back(6);
                x.push_back(7);
                x.push_back(8);
                x.push_back(9);
                CPPUNIT_ASSERT(x.size() == 5);
                x.erase((x.begin() + 1));
                x.erase((x.begin() + 1));
                x.erase((x.begin() + 1));
                x.erase((x.begin() + 1));
                x.erase((x.begin()));
                CPPUNIT_ASSERT(x.size() == 0);
        }

        void test_fill() {
                C x(5, 3);
                CPPUNIT_ASSERT(x.size() == 5);
                CPPUNIT_ASSERT(x[0] == 3);
                CPPUNIT_ASSERT(x[1] == 3);
                CPPUNIT_ASSERT(x[2] == 3);
                CPPUNIT_ASSERT(x[4] == 3);
            }

         void test_fill_2() {
                C x(10, 30);
                CPPUNIT_ASSERT(x.size() == 10);
                CPPUNIT_ASSERT(x[0] == 30);
                CPPUNIT_ASSERT(x[1] == 30);
                CPPUNIT_ASSERT(x[2] == 30);
                CPPUNIT_ASSERT(x[4] == 30);
            }

         void test_fill_3() {
                C x(500, 1);
                CPPUNIT_ASSERT(x.size() == 500);
                CPPUNIT_ASSERT(x[0] == 1);
                CPPUNIT_ASSERT(x[1] == 1);
                CPPUNIT_ASSERT(x[2] == 1);
                CPPUNIT_ASSERT(x[4] == 1);
            }


        void test_copy() {
                C x(5, 3);
                C y(x);
                CPPUNIT_ASSERT(y.size() == 5);
                CPPUNIT_ASSERT(y[0] == 3);
                CPPUNIT_ASSERT(y[1] == 3);
                CPPUNIT_ASSERT(y[4] == 3);}

        void test_copy_2() {
                C x(10, 5);
                C y(x);
                CPPUNIT_ASSERT(y.size() == 10);
                CPPUNIT_ASSERT(y[0] == 5);
                CPPUNIT_ASSERT(y[1] == 5);
                CPPUNIT_ASSERT(y[4] == 5);}

        void test_copy_3() {
                C x(400, 300);
                C y(x);
                CPPUNIT_ASSERT(y.size() == 400);
                CPPUNIT_ASSERT(y[0] == 300);
                CPPUNIT_ASSERT(y[100] == 300);
                CPPUNIT_ASSERT(y[300] == 300);}


        void test_equal() {
                C x(6, 6);
                C y(6, 6);
                CPPUNIT_ASSERT(x == y);}


        void test_equal_2() {
                 C x(6,6);
                 C z(x);
                CPPUNIT_ASSERT(x == z);}

        void test_equal_3() {
                const C x(6,6);
                const C z(x);
                CPPUNIT_ASSERT(x == z);}

        void test_pop_back() {
                C x(5, 3);
                CPPUNIT_ASSERT(x.size() == 5);
                x.pop_back();
                CPPUNIT_ASSERT(x.size() == 4);
        }


        void test_pop_back_2() {
                C x(30, 3);
                CPPUNIT_ASSERT(x.size() == 30);
                x.pop_back();
                x.pop_back();
                x.pop_back();
                x.pop_back();
                CPPUNIT_ASSERT(x.size() == 26);
        }


        void test_assignment() {
                C x(15,5);
                C z(15);
                z = x;
                CPPUNIT_ASSERT(z[6] == 5);}

        void test_assignment_2() {
                C x(15,5);
                C z(20,2);
                z = x;
                CPPUNIT_ASSERT(z.size() == 15);
                CPPUNIT_ASSERT(z == x);}


        void test_resize() {
                C x(10, 2);
                x.resize(300);
                CPPUNIT_ASSERT(x.size() == 300);}

        void test_clear() {
                C x(50, 12);
                CPPUNIT_ASSERT(x.size() == 50);
                x.clear();
                CPPUNIT_ASSERT(x.size() == 0);}

        void test_clear_2() {
                C x(500, 12);
                CPPUNIT_ASSERT(x.size() == 500);
                x.clear();
                CPPUNIT_ASSERT(x.size() == 0);}

        void test_clear_3() {
                C x(30, 12);
                CPPUNIT_ASSERT(x.size() == 30);
                x.clear();
                CPPUNIT_ASSERT(x.size() == 0);}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDeque);
    CPPUNIT_TEST(test_size);
    CPPUNIT_TEST(test_size_2);
    CPPUNIT_TEST(test_size_3);
    CPPUNIT_TEST(test_push_back);
    CPPUNIT_TEST(test_push_back_2);
    CPPUNIT_TEST(test_push_back_3);
    CPPUNIT_TEST(test_push_front);
    CPPUNIT_TEST(test_push_front_2);
    CPPUNIT_TEST(test_push_front_3);
    CPPUNIT_TEST(test_insert);
    CPPUNIT_TEST(test_insert_2);
    CPPUNIT_TEST(test_erase);
    CPPUNIT_TEST(test_erase_2);
    CPPUNIT_TEST(test_allocate);
    CPPUNIT_TEST(test_fill);
    CPPUNIT_TEST(test_fill_2);
    CPPUNIT_TEST(test_fill_3);
    CPPUNIT_TEST(test_copy);
    CPPUNIT_TEST(test_copy_2);
    CPPUNIT_TEST(test_copy_3);
    CPPUNIT_TEST(test_equal);
    CPPUNIT_TEST(test_equal_2);
    CPPUNIT_TEST(test_equal_3);
    CPPUNIT_TEST(test_pop_back);
    CPPUNIT_TEST(test_pop_back_2);
    CPPUNIT_TEST(test_assignment);
    CPPUNIT_TEST(test_assignment_2);
    CPPUNIT_TEST(test_resize);
    CPPUNIT_TEST(test_clear);
    CPPUNIT_TEST(test_clear_2);
    CPPUNIT_TEST(test_clear_3);
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

    tr.addTest(TestDeque<   deque<int> >::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}