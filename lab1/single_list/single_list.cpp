#include <stdexcept>
using namespace std;
#include "single_list.h"

Single_list::Single_list():
  first(nullptr),
  last(nullptr),
  size(0)
{};

Single_list::~Single_list()
{
  Node *temp1 = nullptr;
  Node *temp2 = first;
  while(temp2 != nullptr)
  {
    temp1 = temp2->next;
    delete temp2;
    temp2 = temp1;  
  }
  first = nullptr;
  last = nullptr;
  size = 0;
}

void Single_list::push(int data)
{
  Node *element = new Node;
  element->data = data;
  element->next = nullptr;

  if (first == nullptr)
  {
    first = element;
    last = element;
    size++;
    return;
  }

  last->next = element;
  last = element;
  size++;
}

void Single_list::pop()
{
  if (first == nullptr)
  {
    throw invalid_argument("The list is empty");
  }

  Node *temp = last;
  Node *now = first;

  for (int count = 0; count < (size - 2); count++) 
  {
    now = now->next; 
  }
  now->next = nullptr;
  last = now;
  delete temp;
  size--;
}

void Single_list::insert(int data, int point)
{
  if (point < 0 || point > size) 
  {
    throw invalid_argument("Invalid position");
  }

  if (point == 0)
  {
    Node *element = new Node;
    element->data = data;
    element->next = first;
    first = element;
    size++;
    return;
  }

  if (point == size)
  {
    push(data);
  }

  Node *element = new Node;
  element->data = data;
  element->next = nullptr;
  Node *now = first;
  for (int count = 0; count < (point - 1); count++) 
  {
    now = now->next; 
  }
  element->next = now->next;
  now->next = element;
  size++;
}

void Single_list::remove(int point)
{
  if (point < 0 || point > size) 
  {
    throw invalid_argument("Invalid position");
  }

  if (point == 0)
  {
    Node *temp = first;
    first = temp->next;
    delete temp;
    size--;
    return;
  }

  if (point == (size - 1))
  {
    pop();
    return;
  }

  Node *now = first;
  for (int count = 0; count < (point - 1); count++) 
  {
    now = now->next; 
  }
  Node *temp = now->next;
  now->next = temp->next;
  delete temp;
  size--;
}

void Single_list::delete_second()
{
  Node *now = first;

  if (now == nullptr) 
  {
    throw invalid_argument("The list is empty");
  }

  for (int count = 1; count < size; count++)
  { 
     remove(count);
  }    
}

string Single_list::turn_list_into_string()
{
  string word = "";
  Node *now = first;
  for (int count = 0; count < size; count++)
  {
    word = word + std::to_string(now->data) + " ";
    now = now->next;     
  }
  return word;
}

int Single_list::get_first()
{
  if (first == nullptr)
  {
    throw invalid_argument("The list is empty");
  }
  
  return first->data;
}

int Single_list::get_last()
{
  if (first == nullptr)
  {
    throw invalid_argument("The list is empty");
  }
  
  return last->data;
}
