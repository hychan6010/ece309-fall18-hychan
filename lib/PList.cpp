namespace ece309{

#include "PList.h"

PList::PList()
{

  head = NULL;
  tail = NULL;
}

void PList::append(Object *o)
{
  ListNode *node = new ListNode(o);
  if (head == NULL)
    
      head = node;
      tail = node;
    }
  else
    {
      tail->setNext(node);
      tail = node;
    }
}

bool PList::remove(Object*& copy)
{
  if (!empty())
    {
      copy = head->getObject(); 
      ListNode *tmp = head->getNext();
      delete head; 
      head = tmp; 
      if (tmp==NULL) 
	tail = NULL;
      return true;
    }
  return false; 
}

bool PList::empty()
{
  return head==NULL;
}

void PList::removeAfter(PList::iterator it) 
{
   if (it.node==NULL) 
     {
       ListNode *remove = head;
       head = head->getNext(); 
       if (head==NULL) tail = NULL; 
       delete remove; 
     }
   else 
     {
       ListNode *tmp = it.node;
       ListNode *remove = tmp->getNext(); 
       tmp->setNext(remove->getNext());  
       if (tail==remove) tail = tmp;    
       delete remove; 
     }
}

void PList::insertAfter(PList::iterator it, Object *o) 
{
    if (it.node==NULL)
      { 

	ListNode *node = new ListNode(o,head);
	if (head==NULL) { 
	  tail = node; 
	  head = node;
	} else {
	  head = node; 
	}
      }
    else 
    {
	     ListNode *node = new ListNode(o,it.node->getNext());
	     it.node->setNext(node);
	     if (tail==it.node) tail = node;
    }
}

}
