//Name:Christian Medrano
//Class: COSC 1436 SP22
//Instructor: Marwa Hassan
//Assignment 2 Problem 1
//Date:2/3/21
//Program description:This code will infile 365 integers which represent the 12 months in sales, following this, the averages are calculated for each month
// and then stored in monthAV, following this monthAV is sent to the dualsort function where it is placed into a for loop, which will sort the months using the function
//findMin, it will simultaneously swap monthAv with the new sorted value using the swap function for each iteration in the for loop. This idea will be replicated by the
// other swap function, and following the dualsort function's sorting, median will be used to find the median value of the month sales.
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void dualSort(double monthAv [], string names[],int Size );
void swap(double monthAv [], int i, int unsortedmin);
void swap(string names[], int i, int unsortedmin);
int findMin(double monthAv[],int size,int i);
double median(double monthAv[],int size);
int main()
{
    int counter=0;
    const int Size=12;
    char index;
    const int DAYS[12] = {31,28,31,30,31, 30, 31, 31, 30, 31, 30, 31};
    double Average=0;
    string names[12] = {"January", "February", "March", "April", "May",
"June", "July", "August", "September", "October", "November", "December"};
double monthAv[Size];

 ifstream inFile;
	inFile.open("seasonal_rainfall_data.txt");
for(int i=0; i<12; i++)
   {
       Average=0;
       for (int j=0; j<DAYS[i]; j++){
        //open file;
	inFile>>monthAv[i];
	Average+=monthAv[i];

}
    Average=(Average/DAYS[i]);
    monthAv[i]=Average;



   }
    cout<<"The sorted values in the Array are "<<endl;
   dualSort(monthAv, names, Size );
     for (int i=0; i<12; i++)

   {
       cout<<setprecision(2);
       cout<<fixed;
       cout<<names[i]<<",Has an Average of "<<monthAv[i]<<" Sales"<<endl;

   }
   cout<<"The Median value of the array is "<<median( monthAv,Size)<<endl;

        return 0;
    }
//*************************************************
// dualSort function
// This function sorts the array monthAv, then sorts the array names in accordance to monthAv using a dual sort algorithm
//
// void function
// ------------
//
//
// Parameters
// ------------
// double monthAv               array with the month Averages from the sales
//int size                      the size of the array
// string names                 the array for the names of the months
//*************************************************
void dualSort(double monthAv[], string names[],int Size ){
    int unsortedmin=0;
for (int i=0; i<Size; i++)    {
        unsortedmin=findMin(monthAv,Size,i);
        swap(monthAv,i,unsortedmin);
        swap(names,i,unsortedmin);
        }
}

    //*************************************************
// swap function
// This function will swap the arrays value of i with the sorted value found via the findmin function which is held by unsortedmin
// void function
// ------------
//
//
// Parameters
// ------------
// double a[]               array with the month Averages from the sales
//int size                  the size of the array
// int j                    j is unsortedmin, the sorted value from the findmin function
//*************************************************
 void swap(double a[], int i, int j)
{

int temp = a[i];
a[i] = a[j];
a[j] = temp;
}
  //*************************************************
// swap function
// This function will swap the arrays value of i with the sorted value found via the findmin function which is held by unsortedmin
// This is following the same swapping algorithm as the other swap function, and this allows both to be sorted through dualsorting
//void function
// ------------
//
//
// Parameters
// ------------
// string a[]               array with the month names
//int size                  the size of the array
// int j                    j is unsortedmin, the sorted value from the findmin function
//*************************************************
 void swap(string a[], int i, int j)
{
string temp = a[i];
a[i] = a[j];
a[j] = temp;
}
//*************************************************
// findMin function
// this function finds the minimum value of the array in accordance to the I value passed from the dualsort function
// int function
// ------------
//
//
// Parameters
// ------------
// double monthAv               array with the month Averages from the sales
//int size                      the size of the array
// int i                        Value which represents the placement(iteration) of the monthAv array
//*************************************************
int findMin(double monthAv[],int size,int i)
{
    int smallestAt=i;
    for (int j=i;j<size; j++)
    {
        if (monthAv[j]<monthAv[smallestAt])
         smallestAt=j;


    }
    return smallestAt;

}
//*************************************************
// median function
// This function will calculate a mean using the sorted array
// double function
// ------------
//
//
// Parameters
// ------------
// double monthAv               array with the month Averages from the sales
//int size                      the size of the array
//*************************************************
double median(double monthAv[],int size)
{
    double Average;
    int middle=(size/2);
    int middle2=middle-1;
    Average=(monthAv[middle]+monthAv[middle2])/2;
    return Average;
}


