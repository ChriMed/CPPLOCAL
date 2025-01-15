// Implementation file for the FeetInches class
#include <iostream>
#include <cstdlib>       // Needed for abs()
#include "FeetInches.h"

//************************************************************
// Definition of member function simplify. This function     *
// checks for values in the inches member greater than       *
// twelve or less than zero. If such a value is found,       *
// the numbers in feet and inches are adjusted to conform    *
// to a standard feet & inches expression. For example,      *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
// 5 feet -2 inches would be adjusted to 4 feet 10 inches.   *
//************************************************************

void FeetInches::simplify()
{
   if (inches >= 12)
   {
      feet += (inches / 12);
      inches = inches % 12;
   }
   else if (inches < 0)
   {
      feet -= ((abs(inches) / 12) + 1);
      inches = 12 - (abs(inches) % 12);
   }
}
//**********************************************
// Overloaded binary + operator.               *
//**********************************************

FeetInches FeetInches::operator + (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches + right.inches;
   temp.feet = feet + right.feet;
   temp.simplify();
   return temp;
}
//**********************************************
// Overloaded binary + operator.               *
//**********************************************

FeetInches FeetInches::operator * (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches * right.inches;
   temp.feet = feet * right.feet;
   temp.simplify();
   return temp;
}
//**********************************************
// Overloaded binary - operator.               *
//**********************************************

FeetInches FeetInches::operator - (const FeetInches &right)
{
   FeetInches temp;

   temp.inches = inches - right.inches;
   temp.feet = feet - right.feet;
   temp.simplify();
   return temp;
}
//**********************************************
// Overloaded binary += operator.               *
//**********************************************
FeetInches FeetInches::operator += (const FeetInches &right)
{
   FeetInches temp;

   temp.inches += inches;
   temp.feet += feet;
   temp.simplify();
   return temp;
}
//**********************************************
// Overloaded binary == operator.               *
//**********************************************
bool FeetInches::operator == (const FeetInches &right)
{
if(right.inches == inches){
    return true;
  if (right.feet == feet)
    return true;
}
else return false;
}
//**********************************************
// Overloaded binary != operator.               *
//**********************************************
bool FeetInches::operator != (const FeetInches &right)
{
if(right.inches != inches){
    return true;
  if (right.feet != feet)
    return true;
}
else return false;
}
//**********************************************
// Overloaded binary >= operator.               *
//**********************************************
bool FeetInches::operator >= (const FeetInches &right)
{
if(right.inches >= inches){
    return true;
  if (right.feet >= feet)
    return true;
}
else return false;
}
//**********************************************
// Overloaded binary > operator.               *
//**********************************************
bool FeetInches::operator > (const FeetInches &right)
{
if(right.inches > inches){
    return true;
  if (right.feet > feet)
    return true;
}
else return false;
}
//**********************************************
// Overloaded binary < operator.               *
//**********************************************
bool FeetInches::operator < (const FeetInches &right)
{
if(right.inches < inches){
    return true;
  if (right.feet < feet)
    return true;
}
else return false;
}
//**********************************************
// Overloaded binary <= operator.               *
//**********************************************
bool FeetInches::operator <= (const FeetInches &right)
{
if(right.inches <= inches){
    return true;
  if (right.feet <= feet)
    return true;
}
else return false;
}

//**********************************************
// Overloaded binary -- operator.               *
//**********************************************
FeetInches FeetInches::operator--()
{
--inches;
simplify();
return *this;
}
//**********************************************
// Overloaded binary ++ operator.               *
//**********************************************
FeetInches FeetInches::operator++()
{
++inches;
simplify();
return *this;
}
istream &operator >> (istream &strm, FeetInches &obj)
{
// Prompt the user for the feet.
cout << "Feet: ";
strm >> obj.feet;
// Prompt the user for the inches.
cout << "Inches: ";
strm >> obj.inches;
// Normalize the values.
obj.simplify();
return strm;
}
ostream &operator << (ostream &strm, const FeetInches &obj)
{
strm << obj.feet << " feet, " << obj.inches << " inches";
return strm;
}
