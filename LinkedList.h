#ifndef LinkedList_H
#define LinkedList_H
class LinkedList
{
private:
   // Declare the node structure
  struct ListNode
{
    double value;
    struct ListNode *next;
};
    ListNode *head;

   // Declare the head pointer

public:
   // Constructor
   LinkedList();

   // Destructor
   ~LinkedList();

   // Linked list operations
   void appendNode(double);
   void deleteNode(double);
   void insertNode(double);
   void displayList() const;
    int length() const;
   int findOrder(double) const;
    void insertAt(double,int);
    void removeAt(int);
};
#endif // LINKEDLIST_H_INCLUDED

