#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
   // Define a LinkedList object.
    LinkedList List;
   // Append some values to the list.
    List.appendNode(2.5);
    List.appendNode(7.9);
    List.appendNode(12.6);
    List.insertNode(2.9);
    List.insertNode(3.0);
    cout<<"Operations done: \n1. Append 2.5 \n2. Append 7.9 \n3. Append 12.6 \n4. Insert 2.9 \n5. Insert 3.0 \n6. Length:"; 
    cout<<List.length()<<endl;
    cout<<"7. Delete 3.0";
    List.deleteNode(3.0);
    cout<<"\n8. Length:";
    cout<<List.length()<<endl;    
    cout<<"9. Position of 12.6 is ";
    cout<<List.findOrder(12.6);
    cout<<"\n10. Insert 12.0 at 4";
    List.insertAt(12.0,4);
    cout<<"\n11. Remove 12.6 at position 3\n12. Display List"<<endl;
    List.removeAt(3);

    // Display the contents of the list.
   List.displayList();
   return 0;
}
