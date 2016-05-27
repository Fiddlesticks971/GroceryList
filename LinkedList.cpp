#include "LinkedList.h"

template <class Thing> LinkedList<Thing>::LinkedList()
{
  root = nullptr;
}

template <class Thing> LinkedList<Thing>::LinkedList(Thing newThing)
{
  root = new node;
  root->item = newThing;
  root->previous = nullptr;
  root->next = nullptr;
}

template <class Thing> bool LinkedList<Thing>::add(Thing newThing)
{
  
  node *runner;
  runner = root;
  
  while( runner->next != nullptr ) 
    runner = runner->next;
  
  runner->next = new node;
  runner->next->item = newThing;
  runner->next->previous = runner;
  runner->next->next = nullptr;

  delete runner;
  
  return 0;
}

template <class Thing> bool LinkedList<Thing>::remove(Thing oldThing)
{
  node *runner;
  runner = root;

  while(runner != nullptr && runner->item != oldThing)
    runner=runner->next;

  if (runner == nullptr)
    return 1;
  return 0;
}

template <class Thing> Thing* LinkedList<Thing>::find(Thing item)
{
  return &item;
}

template <class Thing> LinkedList<Thing>::~LinkedList()
{
  delete root;
}
