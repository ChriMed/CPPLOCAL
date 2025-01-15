//Name:Christian Medrano
//Class: COSC 1436 SP22
//Instructor: Marwa Hassan
//Assignment 2 Problem 2
//Date:2/3/21
//Program description:This program creates 50 random integers between 100-900 then sorts them in an array,
//following that It searcher for a user input value and shows the iterations for both Binary and Linear searches that are done
#include <iostream>
#include <cstdlib>
using namespace std;
void dualSort(int array[],int size, int &iterationDualSort);
void swap(int a[], int i, int j);
int findMin(int array[],int size,int i, int &iterationDualSort);
int binarysearch(int array[], int size, int value, int &iterationBinary);
void selectionsort(int array[],int size, int &iterationsSelection);
int Linearsearch(int array[], int size, int value, int &iterationLinear);
int main()
{

int iterationBinary = 0;
int iterationLinear = 0;
int iterationDualSort = 0;
int iterationsSelection = 0;
    int target=0;
    int test=0;
    int test2=0;
    const int size =50;
    int array[size];
      cout<<"The sorted array is "<<endl;
             unsigned seed = time(0);
             srand(seed);
    for (int i=0;i<size; i++)
    {
        array[i]= (rand()%900 + 100);

    }
    cout<<endl;


    selectionsort( array, size, iterationsSelection);
    dualSort( array, size, iterationDualSort);
  for (int i=0;i<size-1; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter a number you would like to search for "<<endl;
    cin>>target;
    test=binarysearch( array, size, target,iterationBinary);
    test2=Linearsearch(array, size, target,iterationLinear);

    if (array[test]==target)
        cout<<"Binary target is found at index "<<test<<", With "<<iterationBinary<<" iterations"<<endl;
    else
    cout<<"Binary target was not found"<<endl;
 if (array[test2]==target)
        cout<<"Linear target is found at index "<<test<<", With "<<iterationLinear<<" iterations"<<endl;
    else
    cout<<"Linear target was not found"<<endl;

    cout<<"Selectionsort sorts in "<<iterationsSelection<< " iterations"<<endl;

    cout<<"Dualsorts sorts in "<<iterationDualSort<< " iterations"<<endl;

     return 0;

}





//*************************************************
// selectionsort function
// This function searches through an array for a the lowest number, using a linear search and then saves the number in the array
//
// Return Value
// ------------
// Sorts the array and then returns temp value which is not used, the main objective if the sorting of the array
//
// Parameters
// ------------
// int array               array with 50 numbers
//int size                 50, the size of the array
//*************************************************
    void selectionsort(int array[],int size, int &iterationsSelection){
        int minIndex=0;
        int temp=0;
        for(int i=0;i<size; i++)
        {
            minIndex=i;
            for (int j=i+1; j<size; j++)
            {
                if (array[j]<array[minIndex])
                minIndex=j;
                iterationsSelection++;
            }

        temp=array[i];
        array[i]=array[minIndex];
        array[minIndex]=temp;
        }
    }


 //*************************************************
// binarysearch function
// This function searches through an array for a number, using binary search
//
// Return Value
// ------------
// int index of the value in the array if found, else -1
//
// Parameters
// ------------
// int array               array with 50 numbers
//int size                 50, the size of the array
//int value                the value being searched for
//int &iterationBinary     reference search iteration counter
//*************************************************
 int binarysearch(int array[], int size, int value, int &iterationBinary){
        int position=-1;
        int last=size;
        int first=0;
        int mid=0;
        while (last>=first&&position==-1)
        {
            mid=((first+last)/2);
            if(array[mid]==value){
            position=mid;
            iterationBinary++;

            }
            else if(array[mid]>value){
            last=mid-1;
        iterationBinary++;

            }

            else {
            first=mid+1;
            iterationBinary++;
            }

            }
        return position;
 }
 //*************************************************
// Linearsearch function
// This function searches through an array for a number, using linear search
//
// Return Value
// ------------
// int index of the value in the array if found, else -1
//
// Parameters
// ------------
// int array               array with 50 numbers
//int size                 50, the size of the array
//int value                the value being searched for
//int &iterationLinear     reference search iteration counter
//*************************************************
 int Linearsearch(int array[], int size, int value, int &iterationLinear)
    {
       for(int i=0; i<size; i++)
        {
            iterationLinear++;
            if (array[i]==value)
            return i;
        }
        return -1;
    }

void dualSort(int array[],int size, int &iterationDualSort)
{
     int unsortedmin=0;
    for (int i=0; i<size; i++)    {
    unsortedmin=findMin(array,size,i, iterationDualSort);
    swap(array,i,unsortedmin);
    }
}
 void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int findMin(int array[],int size,int i, int &iterationDualSort)
{
    int smallestAt=i;
    for (int j=i; j<size; j++)
    {
        iterationDualSort++;
        if (array[j]<array[smallestAt])
         {
             smallestAt=j;
         }   
    }
    return smallestAt;
}

    
    
    
