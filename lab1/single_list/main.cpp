#include <iostream>
#include <string>
using namespace std;
#include "single_list.h"

int main()
{
  Single_list list;
  unsigned number;

  cout << "Enter the number of elements:\n";
  cin >> number;
  cout << "Enter your elements:\n";
  int element;

  for ( int counter = 0; counter < number; counter++)
  {
    cin >> element;
    list.push(element);
  }
  
  string string1 = list.turn_list_into_string();
  cout << "Number of list elements: " << list.get_size() << endl;
  cout << "List: " << string1 << endl;
  list.delete_second();
  string string2 = list.turn_list_into_string();
  cout << "Number of list elements: " << list.get_size() << endl;
  cout << "List: " << string2 << endl;
  
  return 0;
}
