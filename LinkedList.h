#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

using namespace std;

template <class Thing> class LinkedList
{
 public:
  LinkedList();
  LinkedList(Thing newThing);
  bool add(Thing newThing);
  bool remove(Thing oldThing);
  Thing* find(Thing item);
  ~LinkedList();
  
 private:
  struct node{
    Thing item;
    node* next;
    node* previous;
  };
  node *root;
  
};

#endif
