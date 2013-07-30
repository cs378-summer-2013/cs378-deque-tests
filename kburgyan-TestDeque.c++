// A unit test source that makes use of gtest
#include <iostream>         // ostream
#include <deque>           // deque
#include <algorithm>        // equal
#include <cstring> // strcmp
#include <sstream> // ostringstream
#include <stdexcept> // invalid_argument
#include <string> // ==
//#include <iterator> // ==
/*
 * This is the gtest header.
 * The usual installation is in /usr/include/
 *
 * It's already installed there on the CS machines,
 * but if you've installed it elsewhere on your own,
 * there's no need to change this line.
 *
 * You just need to make sure to include the folder where
 * you put the gtest folder when compiling.
 */
#include "Deque.h"
#include "gtest/gtest.h"

//g++ -pedantic -std=c++0x -Wall TestStuff.c++ -o TestStuff -lgtest -lgtest_main -pthread


class MyDequeTest: public testing::Test{
protected:

	std::deque<int> v3;
	std::deque<int> v4;
	std::deque<int> v5;
	std::deque<int> v6;
	std::deque<int> v7;
	std::deque<int> v8;
	std::deque<int> v9;
	std::deque<int> v10;
	std::deque<int> v11;
	std::deque<int> v12;
	std::deque<int> v13;
	std::deque<int> v14;
	//######################
	MyDeque<int> myV3;
	MyDeque<int> myV4;
	MyDeque<int> myV5;
	MyDeque<int> myV6;
	MyDeque<int> myV7;
	MyDeque<int> myV8;
	MyDeque<int> myV9;
	MyDeque<int> myV10;
	MyDeque<int> myV11;
	MyDeque<int> myV12;
	MyDeque<int> myV13;
	MyDeque<int> myV14;
	MyDeque<int> myV15;

	virtual void SetUp(){

		v3.push_back(1);
		v3.push_back(2);
		v3.push_back(3);
		v4.push_back(10);
		v4.push_back(20);
		v4.push_back(30);

		v5.push_back(1);
		v5.push_back(2);
		v6.push_back(10);
		v6.push_back(20);

		v7.push_back(1);
		v7.push_back(2);
		v8.push_back(10);
		v8.push_back(20);

		v9.push_back(1);
		v9.push_back(2);
		v9.push_back(3);
		v10.push_back(10);
		v10.push_back(20);
		v10.push_back(30);
		
		for (int i = 0; i < STANDARD_ROW_SIZE; ++i){
			v12.push_back(i + 1);
		}

		for (int i = 0; i < STANDARD_ROW_SIZE + 1; ++i){
			v13.push_back(i + 1);
		}

		for (int i = 0; i < STANDARD_ROW_SIZE * 3 + 1; ++i){
			v14.push_back(i + 1);
		}

		//##############################

		myV3.push_back(1);
		myV3.push_back(2);
		myV3.push_back(3);
		//MyDeque<int>::iterator myV3Begin = myV3.begin();
		//MyDeque<int>::iterator myV3End = myV3.end();

		myV4.push_back(10);
		myV4.push_back(20);
		myV4.push_back(30);

		myV5.push_back(1);
		myV5.push_back(2);
		myV6.push_back(10);
		myV6.push_back(20);

		myV7.push_back(1);
		myV7.push_back(2);
		myV8.push_back(10);
		myV8.push_back(20);

		myV9.push_back(1);
		myV9.push_back(2);
		myV9.push_back(3);
		myV10.push_back(10);
		myV10.push_back(20);
		myV10.push_back(30);

		
		for (int i = 0; i < STANDARD_ROW_SIZE; ++i){
			myV12.push_back(i + 1);
		}
		//MyDeque<int>::iterator myV12Begin = myV12.begin();
		//MyDeque<int>::iterator myV12Begin = myV12.end();

		for (int i = 0; i < STANDARD_ROW_SIZE + 1; ++i){
			myV13.push_back(i + 1);
		}
		//MyDeque<int>::iterator myV13Begin = myV13.begin();
		//MyDeque<int>::iterator myV13Begin = myV13.end();

		for (int i = 0; i < STANDARD_ROW_SIZE * 3 + 1; ++i){
			myV14.push_back(i + 1);
		}
		//MyDeque<int>::iterator myV14Begin = myV14.begin();
		//MyDeque<int>::iterator myV14Begin = myV14.end();

		for (int i = 0; i < STANDARD_ROW_SIZE * 3 + 1; ++i){
			myV15.push_back(i + 1);
		}

	}
	
	virtual void TearDown() {
	}
};

//********************************************

 TEST_F(MyDequeTest, IteratorConstructorTest1) {
	MyDeque<int>::iterator x3(&myV3, 0);
	ASSERT_EQ(1, *x3);
}

TEST_F(MyDequeTest, IteratorConstructorTest2){
	MyDeque<int>::iterator x3(&myV3, 2);
	ASSERT_EQ(3, *x3);
}

TEST_F(MyDequeTest, IteratorConstructorTest3){
	ASSERT_EQ(3, myV3.size());
	MyDeque<int>::iterator x3(&myV3, 3);
	//ASSERT_EQ(*myV3.end(), *x3); //produces rubbish: valgrind says: "Conditional jump or move depends on uninitialised value(s)"

}

//********************************************

 TEST_F(MyDequeTest, DequeEqualTest1) {
	ASSERT_EQ(myV3, myV9);
}

TEST_F(MyDequeTest, DequeEqualTest2){
	bool temp = myV14 == myV15;
	ASSERT_EQ(true, myV14 == myV15);
}

TEST_F(MyDequeTest, DequeEqualTest3){
	ASSERT_EQ(false, myV14 == myV13);

}

//********************************************

TEST_F(MyDequeTest, LessThanTest1){
	ASSERT_EQ(true, v3 < v4);
	//##############################
	ASSERT_EQ(true, myV3 < myV4);
}

TEST_F(MyDequeTest, LessThanTest2){
	ASSERT_EQ(true, v3 < v12);
	//##############################
	ASSERT_EQ(true, myV3 < myV12);
}

TEST_F(MyDequeTest, LessThanTest3){
	ASSERT_EQ(true, v12 < v4);
	//##############################
	ASSERT_EQ(true, myV12 < myV4);
}

//********************************************ITERATOR & VALID____

TEST_F(MyDequeTest, MinusEqualTest1){
	MyDeque<int>::iterator x(&myV3, myV3.size());
	ASSERT_EQ(3, *(--x));
	
}

TEST_F(MyDequeTest, MinusEqualTest2){
	MyDeque<int>::iterator x(&myV14, myV14.size());
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, *(--x));

}

TEST_F(MyDequeTest, MinusEqualTest3){
	MyDeque<int>::iterator x(&myV3, 0);
	ASSERT_EQ(1, *(x));
	++x;
	ASSERT_EQ(2, *(x));
	ASSERT_EQ(1, *(--x));

}

//^^^^^^^ITERATOR & VALID

//********************************************

TEST_F(MyDequeTest, DefaultConstructorTest1){
	MyDeque<int> myV0;
	ASSERT_EQ(0, myV0.size());
	myV0.push_back(1);
	ASSERT_EQ(1, myV0.size());
}

//********************************************

TEST_F(MyDequeTest, AllocConstructorTest1){
	std::allocator<int> q;
	MyDeque<int> myV0( q);
	ASSERT_EQ(0, myV0.size());
}

//********************************************

TEST_F(MyDequeTest, SizeAndInitAllocConstructorTest1){
	int size = 3;
	int initVal = 9;
	std::allocator<int> q;
	MyDeque<int> myV0(size, initVal, q);
	ASSERT_EQ(size, myV0.size());
	for (int i = 0; i < size; ++i){
		ASSERT_EQ(initVal, myV0[i]);
	}
}

TEST_F(MyDequeTest, SizeAndInitAllocConstructorTest2){
	int size = 0;
	int initVal = 9;
	std::allocator<int> q;
	MyDeque<int> myV0(size, initVal, q);
	ASSERT_EQ(size, myV0.size());
	for (int i = 0; i < size; ++i){
		ASSERT_EQ(initVal, myV0[i]);
	}
}

TEST_F(MyDequeTest, SizeAndInitAllocConstructorTest3){
	int size = STANDARD_ROW_SIZE * 3 + 1;
	int initVal = 9;
	std::allocator<int> q;
	MyDeque<int> myV0(size, initVal, q);
	ASSERT_EQ(size, myV0.size());
	for (int i = 0; i < size; ++i){
		ASSERT_EQ(initVal, myV0[i]);
	}
}

//********************************************

TEST_F(MyDequeTest, SizeConstructorTest1){
	int size = 3;
	MyDeque<int> myV0(size);
	ASSERT_EQ(size, myV0.size());

}

TEST_F(MyDequeTest, SizeConstructorTest2){
	int size = 0;
	MyDeque<int> myV0(size);
	ASSERT_EQ(size, myV0.size());

}

TEST_F(MyDequeTest, SizeConstructorTest3){
	int size = STANDARD_ROW_SIZE * 3 + 1;
	MyDeque<int> myV0(size);
	ASSERT_EQ(size, myV0.size());

}

//********************************************

TEST_F(MyDequeTest, CopyConstructorTest1){
	MyDeque<int> myV0(myV9);
	ASSERT_EQ(3, myV0.size());
	ASSERT_EQ(1, myV0[0]);
	ASSERT_EQ(2, myV0[1]);
	ASSERT_EQ(3, myV0[2]);
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(1, myV9[0]);
	ASSERT_EQ(2, myV9[1]);
	ASSERT_EQ(3, myV9[2]);
	++myV0[0];
	ASSERT_EQ(3, myV0.size());
	ASSERT_EQ(2, myV0[0]);
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(1, myV9[0]);
}

TEST_F(MyDequeTest, CopyConstructorTest2){
	MyDeque<int> myV0(myV14);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV0.size());
	ASSERT_EQ(1, myV13[0]);
	ASSERT_EQ(1, myV0[0]);
	ASSERT_EQ(2, myV0[1]);
	ASSERT_EQ(3, myV0[2]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(1, myV14[0]);
	ASSERT_EQ(2, myV14[1]);
	ASSERT_EQ(3, myV14[2]);
	++myV0[0];
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV0.size());
	ASSERT_EQ(2, myV0[0]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(1, myV14[0]);

}

TEST_F(MyDequeTest, CopyConstructorTest3){
	std::deque<int> v0(v11);
	ASSERT_EQ(0, v0.size());
	ASSERT_EQ(0, v11.size());
	v0.push_back(1);
	ASSERT_EQ(1, v0.size());
	ASSERT_EQ(1, v0[0]);
	ASSERT_EQ(0, v11.size());
	//################################
	MyDeque<int> myV0(myV11);
	ASSERT_EQ(0, myV0.size());
	ASSERT_EQ(0, myV11.size());
	myV0.push_back(1);
	ASSERT_EQ(1, myV0.size());
	ASSERT_EQ(1, myV0[0]);
	ASSERT_EQ(0, myV11.size());

}

//********************************************

TEST_F(MyDequeTest, CopyAssignTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(2, myV9[1]);
	MyDeque<int> temp = myV9;
	ASSERT_EQ(2, temp[1]);
	ASSERT_EQ(2, myV9[1]);
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(3, temp.size());
	++temp[1];
	ASSERT_EQ(3, temp[1]);
	ASSERT_EQ(2, myV9[1]);
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(3, temp.size());
}

TEST_F(MyDequeTest, CopyAssignTest2){
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14[STANDARD_ROW_SIZE * 3]);
	MyDeque<int> temp = myV14;
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, temp[STANDARD_ROW_SIZE * 3]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14[STANDARD_ROW_SIZE * 3]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, temp.size());
	++temp[STANDARD_ROW_SIZE * 3];
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 2, temp[STANDARD_ROW_SIZE * 3]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14[STANDARD_ROW_SIZE * 3]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, temp.size());
}

TEST_F(MyDequeTest, CopyAssignTest3){
	ASSERT_EQ(0, v11.size());
	std::deque<int> temp = v11;
	ASSERT_EQ(0, v11.size());
	ASSERT_EQ(0, temp.size());
	temp.push_back(1);
	ASSERT_EQ(1, temp[0]);
	ASSERT_EQ(0, v11.size());
	ASSERT_EQ(1, temp.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	MyDeque<int> temp2 = myV11;
	ASSERT_EQ(0, myV11.size());
	ASSERT_EQ(0, temp2.size());
	temp2.push_back(1);
	ASSERT_EQ(1, temp2[0]);
	ASSERT_EQ(0, myV11.size());
	ASSERT_EQ(1, temp.size());
}

//********************************************

TEST_F(MyDequeTest, SubscriptTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(2, myV9[1]);
	int temp = myV9.at(1);
	ASSERT_EQ(2, temp);
	ASSERT_EQ(2, myV9[1]);
	ASSERT_EQ(3, myV9.size());
}

TEST_F(MyDequeTest, SubscriptTest2){
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, myV14[STANDARD_ROW_SIZE * 3 - 1]);
	int temp = myV14.at(STANDARD_ROW_SIZE * 3 - 1);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, myV14[STANDARD_ROW_SIZE * 3 - 1]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, temp);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
}

TEST_F(MyDequeTest, SubscriptTest3){
	ASSERT_EQ(0, v11.size());
	try{
	int temp = v11.at(0);
	} catch (const std::out_of_range& ){};
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	try{
	int temp = myV11.at(0);
	} catch (const std::out_of_range){};
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, ConstSubscriptTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(2, myV9[1]);
	const int temp = myV9.at(1);
	ASSERT_EQ(2, temp);
	ASSERT_EQ(2, myV9[1]);
	ASSERT_EQ(3, myV9.size());
}

TEST_F(MyDequeTest, ConstSubscriptTest2){
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, myV14[STANDARD_ROW_SIZE * 3 - 1]);
	const int temp = myV14.at(STANDARD_ROW_SIZE * 3 - 1);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, myV14[STANDARD_ROW_SIZE * 3 - 1]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, temp);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
}

TEST_F(MyDequeTest, ConstSubscriptTest3){
	ASSERT_EQ(0, v11.size());
	try{
	int temp = v11.at(0);
	} catch (const std::out_of_range){};
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	try{
	int temp = myV11.at(0);
	} catch (const std::out_of_range){};
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, AtTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(2, myV9[1]);
	int temp = myV9.at(1);
	ASSERT_EQ(2, temp);
	ASSERT_EQ(2, myV9[1]);
	ASSERT_EQ(3, myV9.size());
}

TEST_F(MyDequeTest, AtTest2){
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, myV14[STANDARD_ROW_SIZE * 3 - 1]);
	int temp = myV14.at(STANDARD_ROW_SIZE * 3 - 1);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, myV14[STANDARD_ROW_SIZE * 3 - 1]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, temp);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
}

TEST_F(MyDequeTest, AtTest3){
	ASSERT_EQ(0, v11.size());
	try{
	int temp = v11.at(0);
	} catch (const std::out_of_range&){};
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	try{
	int temp = myV11.at(0);
	} catch (const std::out_of_range&){};
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, ConstAtTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(2, myV9[1]);
	const int temp = myV9.at(1);
	ASSERT_EQ(2, temp);
	ASSERT_EQ(2, myV9[1]);
	ASSERT_EQ(3, myV9.size());
}

TEST_F(MyDequeTest, ConstAtTest2){
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, myV14[STANDARD_ROW_SIZE * 3 - 1]);
	const int temp = myV14.at(STANDARD_ROW_SIZE * 3 - 1);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, myV14[STANDARD_ROW_SIZE * 3 - 1]);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3, temp);
	ASSERT_EQ(STANDARD_ROW_SIZE * 3 + 1, myV14.size());
}

TEST_F(MyDequeTest, ConstAtTest3){
	ASSERT_EQ(0, v11.size());
	try{
	int temp = v11.at(0);
	} catch (const std::out_of_range&){};
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	try{
	int temp = myV11.at(0);
	} catch (const std::out_of_range&){};
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, BackTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(20, myV8[1]);
	int temp = myV8.back();
	ASSERT_EQ(20, temp);
	ASSERT_EQ(20, myV8[1]);
	ASSERT_EQ(2, myV8.size());
}

TEST_F(MyDequeTest, BackTest2){
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(10, myV12[9]);
	int temp = myV12.back();
	ASSERT_EQ(10, myV12[9]);
	ASSERT_EQ(10, temp);
	ASSERT_EQ(10, myV12.size());
}
 //test fails with std::deque and MyDeque as desired
TEST_F(MyDequeTest, BackTest3){
	ASSERT_EQ(0, v11.size());
	//int temp = v11.back();//test fails with std::deque and MyDeque as desired
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	//int temp2 = myV11.back();//test fails with std::deque and MyDeque as desired
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, ConstBackTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(20, myV8[1]);
	const int temp = myV8.back();
	ASSERT_EQ(20, myV8[1]);
	ASSERT_EQ(20, temp);
	ASSERT_EQ(2, myV8.size());
}

TEST_F(MyDequeTest, ConstBackTest2){
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(10, myV12[9]);
	const int temp = myV12.back();
	ASSERT_EQ(10, myV12[9]);
	ASSERT_EQ(10, temp);
	ASSERT_EQ(10, myV12.size());
}

TEST_F(MyDequeTest, ConstBackTest3){
	ASSERT_EQ(0, v11.size());
	//const int temp = v11.back();//test fails with std::deque and MyDeque as desired
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	//const int temp2 = myV11.back();//test fails with std::deque and MyDeque as desired
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, BeginTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(1, myV9[0]);
	MyDeque<int>::iterator iter = myV9.begin();
	ASSERT_EQ(1, *(iter));
	ASSERT_EQ(1, myV9[0]);
	ASSERT_EQ(3, myV9.size());
}

TEST_F(MyDequeTest, BeginTest2){
	ASSERT_EQ(0, v11.size());
	std::deque<int>::iterator iter = v11.begin();
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	MyDeque<int>::iterator iter2 = myV11.begin();
	ASSERT_EQ(0, myV11.size());
}

TEST_F(MyDequeTest, BeginTest3){
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(1, myV12[0]);
	const MyDeque<int>::iterator iter = myV12.begin();
	ASSERT_EQ(1, *(iter));
	ASSERT_EQ(1, myV12[0]);
	ASSERT_EQ(10, myV12.size());
}

TEST_F(MyDequeTest, BeginTest4){
	ASSERT_EQ(11, myV13.size());
	ASSERT_EQ(1, myV13[0]);
	MyDeque<int>::iterator iter = myV13.begin();
	ASSERT_EQ(1, *(iter));
	ASSERT_EQ(1, myV13[0]);
	ASSERT_EQ(11, myV13.size());
}

//********************************************

TEST_F(MyDequeTest, ConstBeginTest1){ // const
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(1, myV9[0]);
	const MyDeque<int>::iterator iter = myV9.begin();
	ASSERT_EQ(1, *(iter));
	ASSERT_EQ(1, myV9[0]);
	ASSERT_EQ(3, myV9.size());
}

TEST_F(MyDequeTest, ConstBeginTest2){ // const
	ASSERT_EQ(0, v11.size());
	const std::deque<int>::iterator iter = v11.begin();
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	const MyDeque<int>::iterator iter2 = myV11.begin();
	ASSERT_EQ(0, myV11.size());
}

TEST_F(MyDequeTest, ConstBeginTest3){ // const
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(1, myV12[0]);
	const MyDeque<int>::iterator iter = myV12.begin();
	ASSERT_EQ(1, *(iter));
	ASSERT_EQ(1, myV12[0]);
	ASSERT_EQ(10, myV12.size());
}

TEST_F(MyDequeTest, ConstBeginTest4){ // const
	ASSERT_EQ(11, myV13.size());
	ASSERT_EQ(1, myV13[0]);
	const MyDeque<int>::iterator iter = myV13.begin();
	ASSERT_EQ(1, *(iter));
	ASSERT_EQ(1, myV13[0]);
	ASSERT_EQ(11, myV13.size());
}

//********************************************

TEST_F(MyDequeTest, ClearTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(1, myV9[0]);
	myV9.clear();
	ASSERT_EQ(0, myV9.size());
}

TEST_F(MyDequeTest, ClearTest2){
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(1, myV12[0]);
	myV12.clear();
	ASSERT_EQ(0, myV12.size());
}

TEST_F(MyDequeTest, ClearTest3){
	ASSERT_EQ(11, myV13.size());
	ASSERT_EQ(1, myV13[0]);
	myV13.clear();
	ASSERT_EQ(0, myV13.size());
}

TEST_F(MyDequeTest, ClearTest4){
	ASSERT_EQ(0, v11.size());
	//v11.erase(v11.clear()); // both deque and MyDeque create compile-error
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	//myV11.erase(myV11.clear());// both deque and MyDeque create compile-error
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, EndTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(3, myV9[2]);
	MyDeque<int>::iterator iter = myV9.end();
	ASSERT_EQ(3, *(iter - 1));
	ASSERT_EQ(3, myV9[2]);
	ASSERT_EQ(3, myV9.size());
}

TEST_F(MyDequeTest, EndTest2){
	ASSERT_EQ(0, v11.size());
	std::deque<int>::iterator iter = v11.end();
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	MyDeque<int>::iterator iter2 = myV11.end();
	ASSERT_EQ(0, myV11.size());
}

TEST_F(MyDequeTest, EndTest3){
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(10, myV12[9]);
	MyDeque<int>::iterator iter = myV12.end();
	ASSERT_EQ(10, *(iter - 1));
	ASSERT_EQ(10, myV12[9]);
	ASSERT_EQ(10, myV12.size());
}

TEST_F(MyDequeTest, EndTest4){
	ASSERT_EQ(11, myV13.size());
	ASSERT_EQ(11, myV13[10]);
	MyDeque<int>::iterator iter = myV13.end();
	ASSERT_EQ(11, *(iter - 1));
	ASSERT_EQ(11, myV13[10]);
	ASSERT_EQ(11, myV13.size());
}

//********************************************

TEST_F(MyDequeTest, ConstEndTest1){ // const
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(3, myV9[2]);
	const MyDeque<int>::iterator iter = myV9.end();
	ASSERT_EQ(3, *(iter - 1));
	ASSERT_EQ(3, myV9[2]);
	ASSERT_EQ(3, myV9.size());
}

TEST_F(MyDequeTest, ConstEndTest2){ // const
	ASSERT_EQ(0, v11.size());
	const std::deque<int>::iterator iter = v11.end();
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	const MyDeque<int>::iterator iter2 = myV11.end();
	ASSERT_EQ(0, myV11.size());
}

TEST_F(MyDequeTest, ConstEndTest3){ // const
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(10, myV12[9]);
	const MyDeque<int>::iterator iter = myV12.end();
	ASSERT_EQ(10, *(iter - 1));
	ASSERT_EQ(10, myV12[9]);
	ASSERT_EQ(10, myV12.size());
}

TEST_F(MyDequeTest, ConstEndTest4){ // const
	ASSERT_EQ(11, myV13.size());
	ASSERT_EQ(11, myV13[10]);
	const MyDeque<int>::iterator iter = myV13.end();
	ASSERT_EQ(11, *(iter - 1));
	ASSERT_EQ(11, myV13[10]);
	ASSERT_EQ(11, myV13.size());
}

//********************************************

TEST_F(MyDequeTest, PrePlusPlusTest1){ 
  MyDeque<int>::iterator iter = myV9.begin();
  ASSERT_EQ(2, *++iter);
  ASSERT_EQ(3, *++iter);
}

TEST_F(MyDequeTest, PrePlusPlusTest2){
  MyDeque<int>::iterator iter = myV13.begin();
  ASSERT_EQ(2, *++iter);
  ASSERT_EQ(3, *++iter);
  ASSERT_EQ(4, *++iter);
}

//********************************************

TEST_F(MyDequeTest, PostPlusPlusTest1){ 
  MyDeque<int>::iterator iter = myV9.begin();
  ASSERT_EQ(1, *iter++);
  ASSERT_EQ(2, *iter++);
  ASSERT_EQ(3, *iter);
}

TEST_F(MyDequeTest, PostPlusPlusTest2){
  MyDeque<int>::iterator iter = myV13.begin();
  ASSERT_EQ(1, *iter++);
  ASSERT_EQ(2, *iter++);
  ASSERT_EQ(3, *iter++);
  ASSERT_EQ(4, *iter);
}

//********************************************

TEST_F(MyDequeTest, EraseTest1){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(1, myV9[0]);
	MyDeque<int>::iterator iter = myV9.erase(myV9.begin());
	ASSERT_EQ(2, *iter);
	ASSERT_EQ(2, myV9[0]);
	ASSERT_EQ(2, myV9.size());
}

TEST_F(MyDequeTest, EraseTest2){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(2, myV9[1]);
	MyDeque<int>::iterator iter0 = myV9.begin();
	++iter0;
	ASSERT_EQ(2, *iter0);
	
	//ASSERT_EQ(3, 2);
	MyDeque<int>::iterator iter = myV9.erase(iter0);
	//ASSERT_EQ(3, 2);
	ASSERT_EQ(3, *iter);
	//ASSERT_EQ(myV9.end(), iter0);
	ASSERT_EQ(3, myV9[1]);
	ASSERT_EQ(2, myV9.size());
}

TEST_F(MyDequeTest, EraseTest3){
	ASSERT_EQ(0, v11.size());
	//v11.erase(v11.begin());
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	//myV11.erase(myV11.begin()); // fails just like std::deque
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, FrontTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(10, myV8[0]);
	int temp = myV8.front();
	ASSERT_EQ(10, temp);
	ASSERT_EQ(10, myV8[0]);
	ASSERT_EQ(2, myV8.size());
}

TEST_F(MyDequeTest, FrontTest2){
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(1, myV12[0]);
	int temp = myV12.front();
	ASSERT_EQ(1, myV12[0]);
	ASSERT_EQ(1, temp);
	ASSERT_EQ(10, myV12.size());
}

TEST_F(MyDequeTest, FrontTest3){
	ASSERT_EQ(0, v11.size());
	//int temp = v11.front();//return giberish b/c v11 is empty
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	//int temp2 = myV11.front();// return giberish b/c myV11 is empty
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, ConstFrontTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(10, myV8[0]);
	const int temp = myV8.front();
	ASSERT_EQ(10, myV8[0]);
	ASSERT_EQ(10, temp);
	ASSERT_EQ(2, myV8.size());
}

TEST_F(MyDequeTest, ConstFrontTest2){
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(1, myV12[0]);
	const int temp = myV12.front();
	ASSERT_EQ(1, myV12[0]);
	ASSERT_EQ(1, temp);
	ASSERT_EQ(10, myV12.size());
}

TEST_F(MyDequeTest, ConstFrontTest3){
	ASSERT_EQ(0, v11.size());
	const int temp = v11.front();
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	const int temp2 = myV11.front();
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, InsertTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(20, myV8[myV8.size() - 1]);
	myV8.insert(myV8.end(), 30);
	ASSERT_EQ(30, myV8[myV8.size() - 1]);
	ASSERT_EQ(3, myV8.size());
}

TEST_F(MyDequeTest, InsertTest2){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(1, myV9[0]);
	myV9.insert(myV9.begin(), 0);
	ASSERT_EQ(0, myV9[0]);
	ASSERT_EQ(4, myV9.size());
}

TEST_F(MyDequeTest, InsertTest3){
	ASSERT_EQ(0, v11.size());
	v11.insert(v11.end(), 1);
	ASSERT_EQ(1, v11[0]);
	ASSERT_EQ(1, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	myV11.insert(myV11.end(), 1);
	ASSERT_EQ(1, myV11[0]);
	ASSERT_EQ(1, myV11.size());
}

TEST_F(MyDequeTest, InsertTest4){
	ASSERT_EQ(0, v11.size());
	v11.insert(v11.begin(), 1);
	ASSERT_EQ(1, v11[0]);
	ASSERT_EQ(1, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	myV11.insert(myV11.begin(), 1);
	ASSERT_EQ(1, myV11[0]);
	ASSERT_EQ(1, myV11.size());
}

TEST_F(MyDequeTest, InsertTest5){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(2, myV9[1]);
	MyDeque<int>::iterator iter = myV9.begin();
	++iter;
	myV9.insert(iter, 99);
	ASSERT_EQ(99, myV9[1]);
	ASSERT_EQ(4, myV9.size());
}

TEST_F(MyDequeTest, InsertTest6){
	ASSERT_EQ(10, myV12.size());
	ASSERT_EQ(2, myV12[1]);
	MyDeque<int>::iterator iter = myV12.begin();
	++iter;
	myV12.insert(iter, 99);
	ASSERT_EQ(99, myV12[1]);
	ASSERT_EQ(11, myV12.size());
}

//********************************************

TEST_F(MyDequeTest, PopBackTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(20, myV8[myV8.size() - 1]);
	myV8.pop_back();
	ASSERT_EQ(10, myV8[myV8.size() - 1]);
	ASSERT_EQ(1, myV8.size());
}

TEST_F(MyDequeTest, PopBackTest2){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(3, myV9[myV9.size() - 1]);
	myV9.pop_back();
	ASSERT_EQ(2, myV9[myV8.size() - 1]);
	ASSERT_EQ(2, myV9.size());
}

TEST_F(MyDequeTest, PopBackTest3){
	ASSERT_EQ(0, v11.size());
	v11.pop_back();
	//ASSERT_EQ(0, v11.size()); 	// caused failure
	//###############################
	ASSERT_EQ(0, myV11.size());
	//myV11.pop_back();		// caused failure
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, PopFrontTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(10, myV8[0]);
	myV8.pop_front();
	ASSERT_EQ(20, myV8[0]);
	ASSERT_EQ(1, myV8.size());
}

TEST_F(MyDequeTest, PopFrontTest2){
	ASSERT_EQ(3, myV9.size());
	ASSERT_EQ(1, myV9[0]);
	myV9.pop_front();
	ASSERT_EQ(2, myV9[0]);
	ASSERT_EQ(2, myV9.size());
}

TEST_F(MyDequeTest, PopFrontTest3){
	ASSERT_EQ(0, v11.size());
	//v11.pop_front();		//failure
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	//myV11.pop_front(); 		//failure
	ASSERT_EQ(0, myV11.size());
}

//********************************************

TEST_F(MyDequeTest, PushBackTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(20, myV8[myV8.size() - 1]);
	myV8.push_back(8);
	ASSERT_EQ(8, myV8[myV8.size() - 1]);
	ASSERT_EQ(3, myV8.size());
}

TEST_F(MyDequeTest, PushBackTest2){
	ASSERT_EQ(0, v11.size());
	v11.push_back(11);
	ASSERT_EQ(11, v11[v11.size() - 1]);
	ASSERT_EQ(1, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	myV11.push_back(11);
	ASSERT_EQ(11, myV11[myV11.size() - 1]);
	ASSERT_EQ(1, myV11.size());
}

TEST_F(MyDequeTest, PushBackTest3){
	ASSERT_EQ(3, myV10.size());
	ASSERT_EQ(30, myV10[myV10.size() - 1]);
	myV10.push_back(40);
	ASSERT_EQ(4, myV10.size());
	ASSERT_EQ(40, myV10[myV10.size() - 1]);
}

//********************************************

TEST_F(MyDequeTest, PushFrontTest1){
	ASSERT_EQ(2, myV8.size());
	ASSERT_EQ(10, myV8[0]);
	myV8.push_front(8);
	ASSERT_EQ(8, myV8[0]);
	ASSERT_EQ(3, myV8.size());
}

TEST_F(MyDequeTest, PushFrontTest2){
	ASSERT_EQ(0, v11.size());
	v11.push_front(11);
	ASSERT_EQ(11, v11[0]);
	ASSERT_EQ(1, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	myV11.push_front(11);
	ASSERT_EQ(11, myV11[0]);
	ASSERT_EQ(1, myV11.size());
}

TEST_F(MyDequeTest, PushFrontTest3){
	ASSERT_EQ(3, myV10.size());
	ASSERT_EQ(10, myV10[0]);
	myV10.push_front(40);
	ASSERT_EQ(4, myV10.size());
	ASSERT_EQ(40, myV10[0]);
}

//********************************************

TEST_F(MyDequeTest, ResizeTest1){
	ASSERT_EQ(2, myV8.size());
	myV8.resize(8);
	ASSERT_EQ(8, myV8.size());
}

TEST_F(MyDequeTest, ResizeTest2){
	ASSERT_EQ(0, myV11.size());
	myV11.resize(11);
	ASSERT_EQ(11, myV11.size());
}

TEST_F(MyDequeTest, ResizeTest3){
	ASSERT_EQ(3, myV10.size());
	myV10.resize(0);
	ASSERT_EQ(0, myV10.size());
	myV10.resize(10);
	ASSERT_EQ(10, myV10.size());
}

//********************************************

TEST_F(MyDequeTest, SizeTest1){
	ASSERT_EQ(2, myV8.size());
}

TEST_F(MyDequeTest, SizeTest2){
	ASSERT_EQ(0, v11.size());
	//###############################
	ASSERT_EQ(0, myV11.size());
	
}

TEST_F(MyDequeTest, SizeTest3){
	ASSERT_EQ(3, myV10.size());
}

//********************************************

TEST_F(MyDequeTest, SwapTest1){
	ASSERT_EQ(v9, v3);
	ASSERT_EQ(v10, v4);
	v3.swap(v4);
	ASSERT_EQ(v10, v3);
	ASSERT_EQ(v9, v4);
	//###############################
	ASSERT_EQ(myV9, myV3);
	ASSERT_EQ(myV10, myV4);
	myV3.swap(myV4);
	ASSERT_EQ(myV9, myV4);
	ASSERT_EQ(myV10, myV3);
}

TEST_F(MyDequeTest, SwapTest2){
	ASSERT_EQ(myV9, myV3);
	ASSERT_EQ(myV7, myV5);
	myV3.swap(myV5);
	ASSERT_EQ(myV7, myV3);
	ASSERT_EQ(myV9, myV5);
	myV3.swap(myV5);
	ASSERT_EQ(myV9, myV3);
	ASSERT_EQ(myV7, myV5);
}

TEST_F(MyDequeTest, SwapTest3){
	myV3.resize(0);
	ASSERT_EQ(0, myV3.size());	

	myV3.swap(myV5);
	ASSERT_EQ(0, myV5.size());
	ASSERT_EQ(2, myV3.size());	
	ASSERT_EQ(myV7, myV3);
	ASSERT_EQ(myV11, myV5);

	myV3.swap(myV5);
	ASSERT_EQ(myV7, myV5);
	ASSERT_EQ(myV11, myV3);
}

