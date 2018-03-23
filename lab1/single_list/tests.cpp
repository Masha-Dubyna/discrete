#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "single_list.h"
using namespace std;

Single_list list1;
Single_list list2;
Single_list list3;
Single_list list4;
Single_list list5;
Single_list list6;
Single_list list7;
Single_list list8;
Single_list list9;
Single_list list10;
Single_list list11;

TEST_CASE("Attributes of an empty list")
{
  CHECK(list1.get_size() == 0);
  CHECK_THROWS(list1.get_first());
  CHECK_THROWS(list1.get_last());
}

TEST_CASE("Pushing")
{ 
  CHECK_NOTHROW(list2.push(0));
  CHECK(list2.get_first() == 0);
  CHECK(list2.get_last() == 0);

  CHECK_NOTHROW(list2.push(1));
  CHECK(list2.get_first() == 0);
  CHECK(list2.get_last() == 1);
}

TEST_CASE("Posittion of inserting less then 0 or more then size")
{
  list3.push(1);
  list3.push(2);
  CHECK_THROWS(list3.insert(2, -4));
  CHECK_THROWS(list3.insert(10, 5));//5 > 2
}

TEST_CASE("Inserting in the beginning and end")
{
  list4.push(10);
  list4.push(15);//list [10, 15]
  CHECK_NOTHROW(list4.insert(1, 0));//list [1, 10, 15]
  CHECK(list4.get_first() == 1);

  CHECK_NOTHROW(list4.insert(4, 3));//list [1, 10, 15, 4]
  CHECK(list4.get_last() == 4);
}

TEST_CASE("Posittion of removing less then 0 or more then (size-1)")
{
  list5.push(1);
  list5.push(2);
  CHECK_THROWS(list5.remove(-4));
  CHECK_THROWS(list5.remove(5));//5 > 1
}

TEST_CASE("Removing from the beginning and end")
{
  list6.push(1);
  list6.push(2);
  list6.push(3);
  list6.push(4);// list [1, 2, 3, 4]
  CHECK_NOTHROW(list6.remove(0));//list [2, 3, 4]
  CHECK(list6.get_first() == 2);

  CHECK_NOTHROW(list6.remove(2));//list [2, 3]
  CHECK(list6.get_last() == 3);
}

TEST_CASE("Deleting every second elements: the size is even number")
{ 
  list7.push(1);
  list7.push(2);//list [1, 2]
  CHECK_NOTHROW(list7.delete_second());//list [1]
  CHECK(list7.get_size() == 1);
}

TEST_CASE("Deleting every second elements: the size is odd number")
{
  list8.push(1);
  list8.push(2);
  list8.push(3);//list [1, 2, 3]
  CHECK_NOTHROW(list8.delete_second());//list [1, 3]
  CHECK(list8.get_size() == 2);
}

TEST_CASE("Deleting every second elements: last element")
{
  list9.push(1);
  list9.push(2);
  list9.push(3);
  list9.push(4);//list [1, 2, 3, 4]
  CHECK_NOTHROW(list9.delete_second());//list [1, 3]
  CHECK(list9.get_last() == 3);
}

TEST_CASE("Deleting every second from empty list")
{
  CHECK_THROWS(list10.delete_second());
}

TEST_CASE("Popping")
{
  list11.push(1);
  list11.push(2);//list [1, 2]
  CHECK_NOTHROW(list11.pop()); 
}
