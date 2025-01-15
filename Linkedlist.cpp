// Implementation file for the LinkedList class
#include <iostream>
#include "LinkedList.h"
using namespace std;


//**************************************************
// constructor								       *
//**************************************************
LinkedList::LinkedList()
{
    head=nullptr;

	// initilize the head to null

}

//**************************************************
// appendNode function creates and appends
// a node with the passed value
//
//  Void return type
// Parameters: double num Is the value of the node to be appended
//**************************************************
void LinkedList::appendNode(double num)
{
ListNode *newNode; // To point to a new node
ListNode *nodePtr; // To move through the list
// Allocate a new node and store num there.
newNode = new ListNode;
newNode->value = num;
newNode->next = nullptr;
if (!head)
head = newNode;
else //If other nodes exist
{
    nodePtr = head;

    while (nodePtr->next)
    nodePtr = nodePtr->next;
    //Search for last node
    nodePtr->next = newNode; //Append newnode;

}
}
/**************************************************
// Length function Calaulates the length of the LinkedList, and returns it
//
//  Void return int
// Parameters: none
//***/

int LinkedList::length() const
{


ListNode *nodePtr; // To move through the list
int counter = 0;
if (!head)
return counter;
else //If other nodes exist
{
    nodePtr = head;
    counter = 1;
    while (nodePtr->next){
    nodePtr = nodePtr->next;
    //Search for last node
    counter++;}

     //Append newnode;
return counter;
}
}
/**************************************************
// Findorder function Calaulates the placement of a Node, and returns it
//
//
//  int return type
// Parameters: double num Is the value of the node to be appended
//*/
 int LinkedList::findOrder(double num ) const
{

ListNode *nodePtr; // To move through the list

int placement = -1;
if (!head)
return -1;
if (head->value==num)
return 0;

else //If other nodes exist
{
    nodePtr = head;
    placement = 1;
    while (nodePtr->next){
    if (nodePtr->value==num)
    return placement;

    nodePtr = nodePtr->next;
    placement++;
    //Search for last node
  }

     if (nodePtr->value==num)
    return placement;
     //Append newnode;
return -1;
}

}


/**************************************************
// insertNode function searches for a value less than a certain value x
// and inserts the value x in the previous node, and links it to the next node
//
//  void return type
// Parameters: double num Is the value of the node to be found
//*/
void LinkedList::insertNode(double num)
{
ListNode *newNode; // A new node
ListNode *nodePtr; // To traverse the list
ListNode *previousNode; // The previous node
// Allocate a new node and store num there.
newNode = new ListNode;
newNode->value = num;
//If there are no nodes, make newNode the first node
if (!head)
{
head = newNode;
newNode->next = nullptr;
}
else // Otherwise, insert newNode
{
// initialize nodePtr and previousNode
nodePtr = head;
previousNode = nullptr;
// Skip all nodes whose value is less than num.
while (nodePtr != nullptr && nodePtr->value < num)
{
previousNode = nodePtr;
nodePtr = nodePtr->next;
}
// If the new node is to be the 1st in the list,
// insert it before all other nodes.
if (previousNode == nullptr)
{
head = newNode;
newNode->next = nodePtr;
}
else // Otherwise insert after the previous node.
{
previousNode->next = newNode;
newNode->next = nodePtr;
}
}
}

//**************************************************
// deleteNode function searches for and deletes
// the node containing the passed value
//  void return type
// Parameters: double num Is the value of the node to be deleted
//*/
void LinkedList::deleteNode(double num)
{
ListNode *nodePtr; // To traverse the list
ListNode *previousNode; // To point to the previous node
// If the list is empty, do nothing.
if (!head)
return;

if (head->value == num)
{
    nodePtr = head->next;
    delete head;
    head = nodePtr;
}
else
{
// Initialize nodePtr to head of list
    nodePtr = head;
// Skip all nodes whose value is not equal to num.
    while (nodePtr != nullptr && nodePtr->value != num)
{
    previousNode = nodePtr;
    nodePtr = nodePtr->next;
}
// If nodePtr is not NULL,
// link the previous node to the node after
// nodePtr, then delete nodePtr.
if (nodePtr)
{
    previousNode->next = nodePtr->next;
    delete nodePtr;
}
}

}

//**************************************************
// displayList displays the values stored in each
// node in the list

//  void return type
// Parameters: none
//*/
void LinkedList::displayList() const
{



ListNode *nodePtr;
nodePtr = head;
while (nodePtr)//While nodePtr is not null
{
    cout << nodePtr->value << endl;
    nodePtr = nodePtr->next;


}


}
//**************************************************
// insertAt function Inserts a node at a specified location in the linked list
//  void return type
// Parameters: double num Is the value of the node to be inserted
// int Placement The placement of the linked list
//*/
void LinkedList::insertAt(double num, int Placement)
{
    int length = this->length();
ListNode *newNode; // A new node
ListNode *nodePtr; // To traverse the list
ListNode *previousNode; // The previous node
// Allocate a new node and store num there.
int Listnum = 0;
newNode = new ListNode;
newNode->value = num;
//If there are no nodes, make newNode the first node

if (!head)
{
head = newNode;
newNode->next = nullptr;
}
else // Otherwise, insert newNode
{
// initialize nodePtr and previousNode
nodePtr = head;
previousNode = nullptr;

// Skip all nodes whose value is less than num.
while (nodePtr != nullptr && Placement!=Listnum)
{
previousNode = nodePtr;
nodePtr = nodePtr->next;
Listnum++;
}

if (Placement>=length)
appendNode(num);
if (previousNode == nullptr||Placement==0)
{
previousNode = nodePtr;
nodePtr = nodePtr->next;
head = newNode;
newNode->next = nodePtr;
}
if (Placement==Listnum){
previousNode->next = newNode;
newNode->next = nodePtr;
}
}
}
//**************************************************
// removeAt function Inserts a node at a specified location in the linked list
//  void return type
// Parameters:
// int Placement The placement of the linked list to be removed
//*/
void LinkedList::removeAt(int Placement) //double num
{
int counter = 1;

ListNode *nodePtr; // To traverse the list
ListNode *previousNode; // To point to the previous node
// If the list is empty, do nothing.


if (!head||Placement>=this->length())
return;
// Determine if the first node is the one.
if (Placement==0)//head->value == num
{
nodePtr = head->next;
delete head;
head = nodePtr;
}
else
{
// Initialize nodePtr to head of list
nodePtr = head;
// Skip all nodes whose value is not equal to num.
while (nodePtr != nullptr && Placement!=counter)//nodePtr->value != num
{
previousNode = nodePtr;
nodePtr = nodePtr->next;
counter++;
}
// If nodePtr is not NULL,
// link the previous node to the node after
// nodePtr, then delete nodePtr.
if (nodePtr)
{
    if (nodePtr)
    {

        previousNode = nodePtr;
        nodePtr = nodePtr->next;
        counter++;

    }

previousNode->next = nodePtr->next;
delete nodePtr;
}
}
}


//**************************************************
// The Destructor deletes every node in the list
//**************************************************
LinkedList::~LinkedList()
{
ListNode *nodePtr; // To traverse the list
ListNode *nextNode; // To point to the next node
// Position nodePtr at the head of the list.
nodePtr = head;
// While nodePtr is not at the end of the list...
while (nodePtr != nullptr)
{
// Save a pointer to the next node.
nextNode = nodePtr->next;
// Delete the current node
//(release the memory at this address)
delete nodePtr;
// Position nodePtr at the next node.
nodePtr = nextNode;
}
}
