#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "StudentTestScores.h"
using namespace std;
int maxsize = 20;
struct Student
{
  string firstName;
  string lastName;
  float gpa;
  int hours;
  string status;
  string studentID;
  string StuEmail;
};
class FloatList // Declares a class that contains an array of                                // floating point numbers
{
private:
  int length;                    //    Holds the number of elements in the array
  vector<Student> studentVector; //    The array of values

public:
  FloatList(); // constructor that sets length to 0.
  void getList(ifstream &);
  // Member function that gets data from a file
  void printList() const;
  void MenuManip(); // file to the screen.
};

int main()
{
  ifstream infile; // Defines a data file
  FloatList list;
  // Fill in the code to define an object called list of the class FloatList

  cout << fixed << showpoint;

  cout << setprecision(2);

  infile.open("Student_Data.txt");
  list.getList(infile);
  // Fill in the code that calls the getList function.
  list.printList();
  // Fill in the code that calls the printList function.
  list.MenuManip();
  // Student mary;
  // string substr;

  // //do this for every value in a struct
  // getline(stuFile,substr, ',');
  // mary.firstName = substr;
  // cout << mary.firstName;
  // //
  // stuFile.close();
  return 0;
}

FloatList::FloatList()
{
  length = 0;
  // Fill in the code to complete this constructor that
  // sets the private data member length to 0
}
void FloatList::getList(ifstream &stuFile)
{
  string test;
  for (int i = 0; i < maxsize; i++)
  {
    Student temp;
    std::getline(stuFile, temp.firstName, ',');
    std::getline(stuFile, temp.lastName, ',');
    stuFile >> temp.gpa;
    stuFile.ignore(); // Ignore the comma
    stuFile >> temp.hours;
    stuFile.ignore();
    std::getline(stuFile, temp.status, ',');
    std::getline(stuFile, temp.studentID, ',');
    std::getline(stuFile, temp.StuEmail);

    if (!(temp.StuEmail == test))
    {
      studentVector.push_back(temp);
      length++;
    }
  }
  // read line by line
}

void FloatList::MenuManip()
{
  bool a = true;
  int index = 0;
  char choice;
  string Status;
  double GPA = 0.0;

  while (a)
  {
    cout << "Which function would you want to Use" << endl;
    cout << "Choose an operation: \n (c) Full-time Students \n (d)Part time Students \n (w)Exceptional \n (b)Passing\n (a)Display all Emails";
    cout << "\n (z)DisplayStudentInfo \n (x)exit.          " << endl;

    cin >> choice;

    while (!(choice == 'c' || choice == 'd' || choice == 'w' || choice == 'b' || choice == 'a' || choice == 'z' || choice == 'x'))
    {
      cout << "Please re-enter a valid choice" << endl;
      cin >> choice;
    }

    switch (choice)
    {

    case 'c':
      cout << "Here are the Full Time Students " << endl;

      for (int i = 0; i < length; i++)
      {
        if (studentVector[i].status == "Full-time")
        {
          cout << studentVector[i].firstName
               << " " << studentVector[i].lastName << " Is their Name" << endl
               << "GPA: " << studentVector[i].gpa << endl
               << "Hours: " << studentVector[i].hours << endl
               << "Status: " << studentVector[i].status << endl
               << "Student ID: " << studentVector[i].studentID << endl
               << "Email: " << studentVector[i].StuEmail << endl;
        }
      }

      break; // optional
    case 'd':
      for (int i = 0; i < length; i++)
      {
        if (studentVector[i].status == "Part-time" || studentVector[i].gpa > 2.00)
        {
          cout << studentVector[i].firstName
               << " " << studentVector[i].lastName << " Is their Name" << endl
               << "GPA: " << studentVector[i].gpa << endl
               << "Hours: " << studentVector[i].hours << endl
               << "Status: " << studentVector[i].status << endl
               << "Student ID: " << studentVector[i].studentID << endl
               << "Email: " << studentVector[i].StuEmail << endl;
        }
      }

      break; // optional
    case 'w':
      for (int i = 0; i < length; i++)
      {
        if (studentVector[i].gpa > 3.95)
        {
          cout << studentVector[i].firstName
               << " " << studentVector[i].lastName << " Is their Name" << endl
               << "GPA: " << studentVector[i].gpa << endl
               << "Hours: " << studentVector[i].hours << endl
               << "Status: " << studentVector[i].status << endl
               << "Student ID: " << studentVector[i].studentID << endl
               << "Email: " << studentVector[i].StuEmail << endl;
        }
      }

      break;
    case 'b':
      for (int i = 0; i < length; i++)
      {
        if (studentVector[i].gpa > 2.5)
        {
          cout << studentVector[i].firstName
               << " " << studentVector[i].lastName << " Is their Name" << endl
               << "GPA: " << studentVector[i].gpa << endl
               << "Hours: " << studentVector[i].hours << endl
               << "Status: " << studentVector[i].status << endl
               << "Student ID: " << studentVector[i].studentID << endl
               << "Email: " << studentVector[i].StuEmail << endl;
        }
      }

      break;
    case 'a':
      for (int i = 0; i < length; i++)
      {
        cout << studentVector[i].firstName
             << " " << studentVector[i].lastName << " Is their Name" << endl
             << "GPA: " << studentVector[i].gpa << endl
             << "Hours: " << studentVector[i].hours << endl
             << "Status: " << studentVector[i].status << endl
             << "Student ID: " << studentVector[i].studentID << endl
             << "Email: " << studentVector[i].StuEmail << endl;
      }

      break;
    case 'z':
      printList();

      break;

    case 'x':
      a = false;
      break;
    }
  }
}

void FloatList::printList() const
{
  for (int i = 0; i < length; i++)
  {
    cout << studentVector[i].firstName
         << " " << studentVector[i].lastName << " Is their Name" << endl
         << "GPA: " << studentVector[i].gpa << endl
         << "Hours: " << studentVector[i].hours << endl
         << "Status: " << studentVector[i].status << endl
         << "Student ID: " << studentVector[i].studentID << endl
         << "Email: " << studentVector[i].StuEmail << endl;
  }
}
