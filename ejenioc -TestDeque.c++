// A unit test source that makes use of gtest
#include <iostream>         // ostream
#include <vector>           // vector
#include <algorithm>        // equal
#include <deque>			//deque

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
#include "gtest/gtest.h"
#include "Deque.h"




// TEST(Deque, Default_Constructor)
// {
// 	MyDeque<int> x;

// 	ASSERT_TRUE(x.empty());
// 	std::deque<int> y;
// 	ASSERT_TRUE(x.empty());
// }


TEST(DequeConstructor, Constructor_one_arg_1)
{
	MyDeque<int> x(5);

	ASSERT_TRUE(x.size() == 5);
	ASSERT_EQ(x[0], 0);
	ASSERT_EQ(x[1], 0);
	ASSERT_EQ(x[2], 0);
	ASSERT_EQ(x[3], 0);
	ASSERT_EQ(x[4], 0);

	std::deque<int> y(1);
	ASSERT_EQ(y[0] , 0);
	ASSERT_TRUE(!y.empty());
}


TEST(DequeConstructor, Constructor_one_arg_2)
{
	MyDeque<int> x(11);

	ASSERT_TRUE(x.size() == 11);
	ASSERT_EQ(x[0], 0);
	ASSERT_EQ(x[0], 0);
	ASSERT_EQ(x[0], 0);
	ASSERT_EQ(x[10], 0);

	std::deque<int> y(1);
	ASSERT_EQ(y[0] , 0);
	ASSERT_TRUE(!y.empty());
}


TEST(DequeConstructor, Constructor_one_arg_3)
{
	MyDeque<int> x(199);

	ASSERT_TRUE(x.size() == 199);
	ASSERT_EQ(x[0], 0);
	ASSERT_EQ(x[4], 0);
	ASSERT_EQ(x[14], 0);
	ASSERT_EQ(x[10], 0);
	ASSERT_EQ(x[198], 0);


	std::deque<int> y(199);
	ASSERT_EQ(y[0] , 0);
	ASSERT_EQ(y[198] , 0);

}


TEST(DequeConstructor, Constructor_two_arg_1)
{
	MyDeque<int> x(1,1);

	ASSERT_TRUE(x.size() == 1);
	ASSERT_EQ(x[0], 1);

	std::deque<int> y(1,1);
	ASSERT_EQ(y[0] , 1);

}


TEST(DequeConstructor, Constructor_two_arg_2)
{
	MyDeque<int> x(56,1445);

	ASSERT_TRUE(x.size() == 56);
	ASSERT_EQ(x[0], 1445);
	ASSERT_EQ(x[55] , 1445);

	std::deque<int> y(56, 1445);
	ASSERT_EQ(y[0] , 1445);
	ASSERT_EQ(y[55] , 1445);

	ASSERT_EQ(y[55] , x[55]);

	ASSERT_TRUE(!x.empty() && !y.empty());
}


TEST(DequeConstructor, Constructor_two_arg_3)
{
	MyDeque<int> x(155,-53);

	ASSERT_TRUE(x.size() == 155);
	ASSERT_EQ(x[0], -53);
	ASSERT_EQ(x[100] , -53);

	std::deque<int> y(155, -53);
	ASSERT_EQ(y[0] , -53);
	ASSERT_EQ(y[55] , -53);

	ASSERT_EQ(y[55] , x[55]);

	ASSERT_TRUE(!x.empty() && !y.empty());
}





TEST(DequeOps, access_operator_1)
{
	MyDeque<int> x(155,-53);

	ASSERT_TRUE(x.size() == 155);

	ASSERT_EQ(x[0], -53);


	std::deque<int> y(155, -53);

	x[55] = 4;
	ASSERT_EQ(x[55], 4);

	ASSERT_EQ(x[0], -53);

	ASSERT_EQ(y[0], -53);
	y[4] = 5;
	ASSERT_EQ(y[4], 5);


	ASSERT_TRUE(!x.empty() && !y.empty());
}


TEST(DequeReferences, access_operator_2)
{
	MyDeque<int> x(124,903);

	ASSERT_TRUE(x.size() == 124);

	ASSERT_EQ(x[0], 903);



	std::deque<int> y(155, -123);

	x[55] = 4;
	ASSERT_EQ(x[55], 4);

	ASSERT_EQ(x[0], 903);

	ASSERT_EQ(y[0], -123);


	ASSERT_TRUE(!x.empty() && !y.empty());
}

TEST(DequeReferences, access_operator_3)
{
	MyDeque<char> x(4,'a');

	ASSERT_TRUE(x.size() == 4);

	ASSERT_EQ(x[0], 'a');



	std::deque<char> y(4, 'a');

	x[2] = 'b';
	ASSERT_EQ(x[2], 'b');

	ASSERT_EQ(x[0], 'a');

	ASSERT_EQ(y[0], 'a');


	ASSERT_TRUE(!x.empty() && !y.empty());
}

TEST(DequeReferences, at_operator_1)
{
	MyDeque<char> x(4,'a');

	ASSERT_TRUE(x.size() == 4);

	ASSERT_EQ(x.at(0), 'a');



	std::deque<char> y(4, 'a');

	x.at(2) = 'b';
	ASSERT_EQ(x.at(2), 'b');

	ASSERT_EQ(x.at(0), 'a');

	ASSERT_EQ(y.at(0), 'a');

	ASSERT_EQ(y.at(0), x.at(0));


	ASSERT_TRUE(!x.empty() && !y.empty());
}


TEST(DequeReferences, at_operator_2)
{
	MyDeque<int> x(4,55);

	ASSERT_TRUE(x.size() == 4);

	ASSERT_EQ(x.at(0), 55);



	std::deque<int> y(4, 55);

	x.at(2) = 54;
	ASSERT_EQ(x.at(2), 54);

	ASSERT_EQ(x.at(0), 55);

	ASSERT_EQ(y.at(0), 55);

	ASSERT_EQ(y.at(0), x.at(0));

	ASSERT_EQ(x.at(3), x[3]);


	ASSERT_TRUE(!x.empty() && !y.empty());
}

TEST(DequeReferences, at_operator_3)
{
	MyDeque<double> x(10,12.54);

	ASSERT_TRUE(x.size() == 10);

	ASSERT_EQ(x.at(0), 12.54);



	std::deque<double> y(10, 12.54);

	x.at(2) = 12.543;
	ASSERT_EQ(x.at(2), 12.543);

	ASSERT_EQ(x.at(0), 12.54);

	ASSERT_EQ(y.at(0), 12.54);

	ASSERT_EQ(y.at(0), x.at(0));

	ASSERT_EQ(x.at(3), x[3]);


	ASSERT_TRUE(!x.empty() && !y.empty());
}

TEST(DequeReferences, back_1)
{
	MyDeque<int> x (4, 1513);
	ASSERT_EQ(x.back(), 1513);

	std::deque<int> y (4, 1513);
	ASSERT_EQ(y.back(), 1513);

	ASSERT_EQ(y.back(), x.back());

}


TEST(DequeReferences, back_2)
{
	MyDeque<char> x (4, 'f');
	ASSERT_EQ(x.back(), 'f');

	std::deque<int> y (4, 'f');
	ASSERT_EQ(y.back(), 'f');

	ASSERT_EQ(y.back(), x.back());

}

TEST(DequeReferences, back_3)
{
	MyDeque<char> x (4, 'f');
	ASSERT_EQ(x.back(), 'f');

	x.push_back('r');
	ASSERT_EQ(x.back(), 'r');


	std::deque<int> y (4, 'f');
	ASSERT_EQ(y.back(), 'f');

	y.push_back('r');
	ASSERT_EQ(y.back(), 'r');

	ASSERT_EQ(y.back(), x.back());

}

TEST(DequeReferences, front_1)
{
	MyDeque<char> x (4, 'f');
	ASSERT_EQ(x.front(), 'f');

	std::deque<int> y (4, 'f');
	ASSERT_EQ(y.front(), 'f');

	ASSERT_EQ(y.front(), x.front());

}

TEST(DequeReferences, front_2)
{
	MyDeque<int> x (5, 7);
	ASSERT_EQ(x.front(), 7);

	x.push_front(4);
	ASSERT_EQ(x.front(), 4);


	std::deque<int> y (5, 7);
	ASSERT_EQ(y.front(), 7);

	y.push_front(4);
	ASSERT_EQ(y.front(), 4);

	ASSERT_EQ(y.front(), x.front());
}


TEST(DequeReferences, front_3)
{
	MyDeque<double> x (20, 4.4);
	ASSERT_EQ(x.front(), 4.4);

	x.push_front(1.1);
	ASSERT_EQ(x.front(), 1.1);


	std::deque<double> y (20, 4.4);
	ASSERT_EQ(y.front(), 4.4);

	y.push_front(1.1);
	ASSERT_EQ(y.front(), 1.1);

	ASSERT_EQ(y.front(), x.front());
}

TEST(DequeIndex, get_last_index_1)
{
	MyDeque<int> x (5, 6);
	ASSERT_EQ(x.get_last_index(), 4);
}

TEST(DequeIndex, get_last_index_2)
{
	MyDeque<int> x (5, 6);
	ASSERT_EQ(x.get_last_index(), 4);
	x.push_back(55);
	ASSERT_EQ(x.get_last_index(), 5);

}

TEST(DequeIndex, get_last_index_3)
{
	MyDeque<double> x (166, 14.2);
	ASSERT_EQ(x.get_last_index(), 165);
	x.push_back(55);
	ASSERT_EQ(x.get_last_index(), 166);
	x.push_front(0.2);
	ASSERT_EQ(x.get_last_index(), 167);

}

TEST(DequeIndex, get_pointer_from_index_1)
{
	MyDeque<int> x (5, 6);
	ASSERT_EQ(*x.get_pointer_from_index(0), 6);
}

TEST(DequeIndex, get_pointer_from_index_2)
{
	MyDeque<int> x (5, 6);
	ASSERT_EQ(x.back(), *x.get_pointer_from_index(4));
	x.push_back(55);
	ASSERT_EQ(x.back(), *x.get_pointer_from_index(5));


}

TEST(DequeIndex, get_pointer_from_index_3)
{
	MyDeque<int> x (53, 4);
	ASSERT_EQ(x.back(), *x.get_pointer_from_index(52));
	x.push_back(542);
	ASSERT_EQ(x.back(), *x.get_pointer_from_index(53));
}

TEST(DequeIndex, get_index_1)
{
	MyDeque<int> x (53, 4);
	ASSERT_EQ(x.get_index(1,1), 11);
}

TEST(DequeIndex, get_index_2)
{
	MyDeque<int> x (53, 4);
	x.push_front(14);

	ASSERT_EQ(x.get_index(1,1), 2);
}

TEST(DequeIndex, get_index_3)
{
	MyDeque<int> x (53, 4);

	x.push_back(14);

	ASSERT_EQ(x.get_index(1,1), 11);
}

TEST(DequeSizing, capacity_1)
{
	MyDeque<int> x(55, 5);

	ASSERT_EQ(x.capacity(), 60);
}

TEST(DequeSizing, capacity_2)
{
	MyDeque<int> x(55, 5);

	x.push_front(424);

	ASSERT_EQ(x.capacity(), 70);
}

TEST(DequeSizing, capacity_3)
{
	MyDeque<int> x(55, 5);

	x.push_front(424);
	for(int i = 0; i < 10; i++)
	{
		x.push_front(i*4);
		x.push_back(i*43);
	}
	ASSERT_EQ(x.capacity(), 90);
}

TEST(DequeSizing, size_1)
{
	MyDeque<int> x(55, 5);

	ASSERT_EQ(x.size(), 55);

	std::deque<int> y(55, 5);

	ASSERT_EQ(y.size(), 55);

	ASSERT_EQ(x.size() , y.size());
}

TEST(DequeSizing, size_2)
{
	MyDeque<int> x(1, 5);

	ASSERT_EQ(x.size(), 1);

	std::deque<int> y(1, 5);

	ASSERT_EQ(y.size(), 1);

	ASSERT_EQ(x.size() , y.size());
}

TEST(DequeSizing, size_3)
{
	MyDeque<int> x(55, 5);

	x.push_front(424);
	for(int i = 0; i < 10; i++)
	{
		x.push_front(i*4);
		x.push_back(i*43);
	}
	ASSERT_EQ(x.size(), 76);
}

TEST(DequePushPop, push_back_1)
{
	MyDeque<int> x(14, 9);
	std::deque<int> y (14, 9);
	ASSERT_EQ(x.size(), 14);
	ASSERT_EQ(y.size(), 14);
	x.push_back(4);
	y.push_back(4);
	ASSERT_EQ(x.size(), 15);
	ASSERT_EQ(y.size(), 15);

}

TEST(DequePushPop, push_back_2)
{
	MyDeque<int> x(14, 9);
	std::deque<int> y (14, 9);
	ASSERT_EQ(x.size(), 14);
	ASSERT_EQ(y.size(), 14);
	x.push_back(4);
	y.push_back(4);
	ASSERT_EQ(x.size(), 15);
	ASSERT_EQ(y.size(), 15);

	for(int i = 0; i < 15; i++)
	{
		x.push_back(i);
		y.push_back(i);
	}

	ASSERT_EQ(x.back(), 14);
	ASSERT_EQ(y.back(), 14);
	ASSERT_EQ(x.size(), y.size());
}

TEST(DequePushPop, push_back_3)
{
	MyDeque<int> x(14, 9);
	std::deque<int> y (14, 9);
	ASSERT_EQ(x.size(), 14);
	ASSERT_EQ(y.size(), 14);
	x.push_back(4);
	y.push_back(4);
	ASSERT_EQ(x.size(), 15);
	ASSERT_EQ(y.size(), 15);
// 
	// int i = 0;
	for(int i = 0; i < 21; i++)
	{
		x.push_back(i);
		y.push_back(i);
	}

	ASSERT_EQ(x.back(), 20);
	ASSERT_EQ(y.back(), 20);
	ASSERT_EQ(x.size(), y.size());
}

// TEST(DequePushPop, push_front_1)
// {
// 	MyDeque<int> x(14, 9);
// 	std::deque<int> y (14, 9);
// 	ASSERT_EQ(x.size(), 14);
// 	ASSERT_EQ(y.size(), 14);
// 	x.push_back(4);
// 	y.push_back(4);
// 	ASSERT_EQ(x.size(), 15);
// 	ASSERT_EQ(y.size(), 15);
// // 
// 	// int i = 0;
// 	for(int i = 0; i < 21; i++)
// 	{
// 		x.push_front(i);
// 		y.push_front(i);
// 	}

// 	ASSERT_EQ(x.back(), 4);
// 	ASSERT_EQ(y.back(), 4);
// 	ASSERT_EQ(x.front(), 20);
// 	ASSERT_EQ(y.front(), 20);
// 	ASSERT_EQ(x.size(), y.size());
// }



TEST(DequePushPop, push_front_2)
{
	MyDeque<char> x(1, 'a');
	std::deque<char> y (1, 'a');
	x.push_front('z');
	y.push_front('z');
	ASSERT_EQ(x.front(), 'z');
	ASSERT_EQ(y.front(), 'z');
}

TEST(DequePushPop, push_front_3)
{
	MyDeque<char> x(1, 'a');
	std::deque<char> y (1, 'a');
	x.push_front('z');
	y.push_front('z');


	ASSERT_EQ(x.front(), 'z');
	ASSERT_EQ(y.front(), 'z');
}

TEST(DequePushPop, pop_front_1)
{
	MyDeque<char> x(4, 'a');
	std::deque<char> y (4, 'a');
	x.pop_front();
	y.pop_front();


	ASSERT_EQ(x.size(), 3);
	ASSERT_EQ(y.size(), 3);
}

TEST(DequePushPop, pop_front_2)
{
	MyDeque<char> x(1, 'a');
	std::deque<char> y (1, 'a');


	x.push_back('4');
	y.push_back('4');

	x.pop_front();
	y.pop_front();

	ASSERT_EQ(x.front(), '4');
	ASSERT_EQ(y.front(), '4');
}

TEST(DequePushPop, pop_front_3)
{
	MyDeque<char> x(15, 'a');
	std::deque<char> y (15, 'a');


	x.push_front('4');
	y.push_front('4');
	x.push_front('5');
	y.push_front('5');

	x.pop_front();
	y.pop_front();

	ASSERT_EQ(x.front(), '4');
	ASSERT_EQ(y.front(), '4');
}





TEST(DequeResize, resize_less_1)
{
	MyDeque<int> x(642, 8);
	x.resize(5);
	ASSERT_EQ(x.size(), 5);
	ASSERT_EQ(x.capacity(), 10);

}


TEST(DequeResize, resize_less_2)
{
	MyDeque<int> x(61, 8);
	x.resize(50);
	ASSERT_EQ(x.size(), 50);
	ASSERT_EQ(x.capacity(), 50);

}

TEST(DequeResize, resize_less_3)
{
	MyDeque<int> x(39, 8);
	x.resize(22);
	ASSERT_EQ(x.size(), 22);
	ASSERT_EQ(x.capacity(), 30);

}

TEST(DequeResize, resize_greater_1)
{
	MyDeque<int> x(24, 8);
	x.resize(33);
	ASSERT_EQ(x.size(), 33);
	ASSERT_EQ(x.capacity(), 40);

}

TEST(DequeResize, resize_greater_2)
{
	MyDeque<int> x(25, 8);
	x.resize(56);
	ASSERT_EQ(x.size(), 56);
	ASSERT_EQ(x.capacity(), 60);

}

TEST(DequeResize, resize_greater_3)
{
	MyDeque<int> x(15, 8);
	x.resize(14);
	ASSERT_EQ(x.size(), 14);
	ASSERT_EQ(x.capacity(), 20);

}


TEST(DequeResize, resize_same_1)
{
	MyDeque<int> x(642, 8);
	x.resize(642);
	ASSERT_EQ(x.size(), 642);
	ASSERT_EQ(x.capacity(), 650);

}

TEST(DequeResize, resize_same_2)
{
	MyDeque<int> x(1, 8);
	x.resize(1);
	ASSERT_EQ(x.size(), 1);
	ASSERT_EQ(x.capacity(), 10);

}

TEST(DequeResize, resize_same_3)
{
	MyDeque<int> x(644, 8);
	x.push_back(42);
	x.resize(645);
	ASSERT_EQ(x.size(), 645);
	ASSERT_EQ(x.capacity(), 650);

}


TEST(Iterators, begin_iterator_1)
{
	MyDeque<int> x(8, 5);
	// while()
	auto y = x.begin();
	int count = 0;
	while(y != x.end())
	{
		y++;
		count++;
	}
	ASSERT_EQ(count, 8);
}


TEST(Iterators, begin_iterator_2)
{
	MyDeque<int> x(145, 5);
	// while()
	auto y = x.begin();
	int count = 0;
	while(y != x.end())
	{
		y++;
		count++;
	}
	ASSERT_EQ(count, 145);
}


TEST(Iterators, begin_iterator_3)
{
	MyDeque<int> x(55, 5);
	// while()
	auto y = x.begin();
	int count = 0;
	while(y != x.end())
	{
		y++;
		count++;
	}
	ASSERT_EQ(count, 55);
}

TEST(Iterators, iterator_1)
{
	MyDeque<int> x(55, 5);
	// while()
	x.push_front(44);

	auto y = x.begin();
	ASSERT_EQ(*y, 44);
}

TEST(Iterators, iterator_2)
{
	MyDeque<int> x(55, 5);
	// while()
	x.push_front(44);

	auto y = x.begin();
	ASSERT_EQ(*y, 44);
	auto z = x.begin();
	ASSERT_EQ(y, z);
}

TEST(Iterators, iterator_3)
{
	MyDeque<int> x(55, 5);
	// while()
	x.push_front(44);

	auto y = x.begin();
	ASSERT_EQ(*y, 44);
	auto z = x.begin();
	ASSERT_EQ(*y, *z);
}

TEST(Iterators, iterator_equality_1)
{
	MyDeque<int> x(55, 5);
	// while()
	x.push_front(44);

	auto y = x.begin();
	y++;
	ASSERT_EQ(*y, 5);
	auto z = x.begin();
	ASSERT_TRUE(y != z);
}

TEST(Iterators, iterator_equality_2)
{
	MyDeque<int> x(24, 2);
	// while()
	auto z =x.begin();
	z++;
	z++;
	ASSERT_EQ(*z, 2);
}

TEST(Iterators, iterator_equality_3)
{
	MyDeque<int> x(24, 2);
	// while()
	auto z =x.begin();
	z++;
	z++;
	x.push_front(24);
	auto r = x.begin();

	ASSERT_EQ(*r, 24);
	ASSERT_EQ(*z, 2);

}

TEST(Iterators, iterator_reverse_1)
{
	MyDeque<int> x(24, 2);
	// while()
	auto z =x.begin();
	z++;
	z--;
	x.push_front(24);
	auto r = x.begin();

	ASSERT_EQ(*r, 24);
	ASSERT_EQ(*z, 24);

}

TEST(Iterators, iterator_reverse_2)
{
	MyDeque<int> x(24, 2);
	// while()
	auto z =x.begin();
	z++;
	z--;
	z++;
	z--;
	x.push_front(24);
	auto r = x.begin();

	ASSERT_EQ(*r, 24);
	ASSERT_EQ(*z, 24);

}

TEST(Iterators, iterator_reverse_3)
{
	MyDeque<int> x(24, 2);
	// while()
	auto z =x.begin();
	while(z != x.end())
	{
		z++;
	}
	z--;
	x.push_front(24);
	auto r = x.begin();

	ASSERT_EQ(*r, 24);
	ASSERT_EQ(*z, 2);

}



TEST(ComboTests, lots_of_push_backs)
{
	MyDeque<int> y(1,1);
	for(int i = 0; i < 143; i++)
	{
		y.push_back(i);
	}
	ASSERT_EQ(y.size(), 144);
}

TEST(ComboTests, lots_of_push_fronts)
{
	MyDeque<int> y(1,1);
	for(int i = 0; i < 143; i++)
	{
		y.push_front(i);
	}
	ASSERT_EQ(y.size(), 144);
}

TEST(ComboTests, interleaved_front_back)
{
	MyDeque<int> y(1,1);
	for(int i = 0; i < 143; i++)
	{
		y.push_back(i);
		y.push_front(-i);
	}
	ASSERT_EQ(y.size(), 287);
}

TEST(ComboTests, push_big_then_pop)
{
	MyDeque<int> a(1,0);
	for(int i = 0; i < 142; i++)
	{
		a.push_back(i);
	}
	for(int i = 0; i < 25; i++)
	{
		a.pop_front();
	}	

	ASSERT_EQ(a.size(), 118);
	ASSERT_EQ(a.front(), 24);
	ASSERT_EQ(a.back(), 141);
}

TEST(ComboTests, yo_yo)
{
	MyDeque<int> a(1,0);
	for(int i = 0; i < 142; i++)
	{
		a.push_back(i);
		a.push_front(-i);
	}
	a.pop_back();

	ASSERT_EQ(a.size(), 284);
	ASSERT_EQ(a.front(), -141);
	ASSERT_EQ(a.back(), 140);
}

TEST(ComboTests, push_pop_alternate)
{
	MyDeque<int> a(4,6);
	for(int i = 0; i < 1000; i++)
	{
		a.push_back(1);
		a.pop_back();
	}
	ASSERT_EQ(a.size(), 4);
}


TEST(ComboTests, alphabet_1)
{
	MyDeque<char> a(1,'a');
	
		char c = 'a';
		for(int i = 0; i < 25; i++)
		{
			a.push_back(++c);
		}
		ASSERT_EQ(a.size(), 26);
		ASSERT_EQ(a.back(), 'z');
	
}


TEST(ComboTests, alphabet_2)
{
	MyDeque<char> a(1,'a');
	
		char c = 'a';
		for(int i = 0; i < 25; i++)
		{
			a.push_front(++c);
		}
		ASSERT_EQ(a.size(), 26);
		ASSERT_EQ(a.front(), 'z');
	
}
