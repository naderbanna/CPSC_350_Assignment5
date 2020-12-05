#include <iostream>
#include "listNode.h"
using namespace std;

template <class temp>
class NaiveList{
  private:
    ListNode<temp> *front;
    ListNode<temp> *back;
    unsigned int size;
  public:
    NaiveList();
    ~NaiveList();

    void insertFront(temp d);
    void insertBack(temp d);
    temp removeFront();
    void printList();
    temp printFront();


    temp find(temp value);
    void deleteItem(temp id);

};

template <class temp>
NaiveList<temp>::NaiveList(){
  front = NULL;
  back = NULL;
  size = 0;
}
template <class temp>
NaiveList<temp>::~NaiveList(){
}

template <class temp>
void NaiveList<temp>::insertFront(temp d){
  ListNode<temp> *node = new ListNode<temp>(d);
  //we need to update pointer back aswell
  if(size == 0){
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

template <class temp>
void NaiveList<temp>::insertBack(temp d){
  ListNode<temp> *node = new ListNode<temp>(d);

  if (front == NULL){
    front = back;
  }
  else{
    back->next = node;
    node->prev = back;
  }

  back = node;
  ++size;
}

template <class temp>
temp NaiveList<temp>::removeFront(){
  ListNode<temp> *node = front;
  if(front->next == NULL){
    back = NULL;
  }
  else{
    front->next->prev = 0;
  }

  front = front->next;
  --size;
  node->next = 0;
  temp t = node->data;

  delete node;
  return t;
}

//remove front and remove back functions
template <class temp>
void NaiveList<temp>::printList(){
  ListNode<temp> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class temp>
temp NaiveList<temp>::printFront(){
  return front->data;
}

template <class temp>
temp NaiveList<temp>::find(temp value){
  int pos = -1;
  ListNode<temp> *curr = front;

  while(curr != NULL){
    ++pos;
    if(curr->data == value)
      break;

    curr = curr->next;
  }
  //did not find value
  if(curr == NULL)
    pos = -1;

  return curr->data;
}

template <class temp>
void NaiveList<temp>::deleteItem(temp id){
  int pos = -1;
  ListNode<temp> *curr = front;

  while(curr != NULL){
    ++pos;
    if(curr->data == id)
      break;

    curr = curr->next;
  }
  //did not find value
  if(curr == NULL)
    pos = -1;

  delete curr;
};

// template <class temp>
// void NaiveList<temp>::deletePos(int id){
//   int p = 0;
//   ListNode<temp> *curr = front;
//   ListNode<temp> *prev = front;
//   //iternate to the position
//   while(curr->data != id){
//     //iterate and update my pointers
//     prev = curr;
//     curr = curr->next;
//     p++;
//   }
//   //we found our target, all pointers should be in the correct location
//   prev->next = curr->next;
//   curr->next = NULL;
//   int t = curr->data;
//   size--;
//
//   delete curr;
//   //return t;
//
//   //try drawing this
// };
