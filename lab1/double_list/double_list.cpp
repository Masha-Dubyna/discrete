#include <stdexcept>
using namespace std;
#include "double_list.h"

Double_list::Double_list():
  first(nullptr),
  last(nullptr),
  size(0)
{};

Double_list::~Double_list()
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

void Double_list::push(int data)
{
  Node *element = new Node;
  element->data = data;
  element->next = nullptr;

  if (first == nullptr)
  {
    first = element;
    element->prev = nullptr;
    last = element;
    size++;
    return;
  }  

  element->prev = last;
  last->next = element;
  last = element;
  size++;
}

void Double_list::pop()
{
  if (first == nullptr)
  {
    throw invalid_argument("The list is empty");
  }

  Node *now = last;
  Node *temp = last->prev;
  temp->next = nullptr;
  last = temp;
  delete now;
  size--;
}

void Double_list::insert(int data, int point)
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
    element->prev = nullptr;
    first = element;
    size++;
    return;
  }

  if (point == size)
  {
    push(data);
    return;
  }

  Node *element = new Node;
  element->data = data;
  element->next = nullptr;
  element->prev = nullptr;
  Node *now = first;
  for (int count = 0; count < (point - 1); count++) 
  {
    now = now->next; 
  }
  element->next = now->next;
  now->next->prev = element;
  now->next = element;
  element->prev = now;
  size++;
}

void Double_list::remove(int point)
{
 
  if (point < 0 || point > size) 
  {
    throw invalid_argument("Invalid position");
  }

  if (point == 0)
  {
    Node *temp = first;
    first->next->prev = nullptr;
    first = first->next;
    delete temp;
    size--;
    return;
  }

  if (point == (size -1))
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
  temp->next->prev = now;
  delete temp;
  size--;
}

void Double_list::delete_second()
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

string Double_list::turn_list_into_string()
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

int Double_list::get_first()
{
  if (first == nullptr)
  {
    throw invalid_argument("A list is empty");
  }
  
  return first->data;
}

int Double_list::get_last()
{
  if (first == nullptr)
  {
    throw invalid_argument("A list is empty");
  }
  
  return last->data;
}
