//********************************************************************
//Name:Christian Medrano
//Class: COSC 1436 Spring 22
//Instructor: Marwa Hassan
//Assignment 7 Problem 1
//Date:4/18/22
//Program description: This program receives an amount of exam scores for a specific student and stores them in their respective class pointers, which are dynamically allocated in the constructors or the student assignment with =
//The program overloads the = and > operators in order to compare the average scores of the Averages of two class objects, it does this using a *this which holds the properties of the
//Object which is being called, it is like a predefined object usable in the scope of the class object's function which is called. This also has a get average function to calculate the averages of the student test scores
//The program is also made to have the proper constructors to allocate space, space with names, and also a default constructor. This program also uses input validation in order to ensure all inputs are valid test scores.
//*********************************************************************
#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H
#include <string>
#include <iostream>
using namespace std;

class StudentTestScores
{
private:
   string studentName;  // The student's name
   double *testScores;  // Points to array of test scores
   int numTestScores;   // Number of test scores

public:
    // Constructor

    void highest();
    void lowest();
    bool operator > (StudentTestScores &);
    StudentTestScores operator = (const StudentTestScores & );
    double getAvgscore();
  //Student Test Scores constructors used dynamically to allocate memory of int num for the testScore pointer and sets names for the students, the default constructor sets all string to " " and all values to 0 or 0.0
   StudentTestScores()
   :StudentTestScores(" ",0)
   {}
    StudentTestScores (int num) :StudentTestScores(" ",num)
    {}

   StudentTestScores(string name, int numScores)
   { studentName = name;
     numTestScores = numScores;
     testScores = new double[numScores];
     for (int i = 0; i < numTestScores; i++)
           testScores[i] = 0;
    }
//*************************************************
// StudentTestScores class member function for Initializing =
//This function uses an algorithm to set a declared StudentTestScores object equal to another, and allocates memory for it separately.
//    Return
// ------------
// void
//
// Parameters
// ------------
// StudentTestScores &obj This is used to be the value in which all private members of the newly declared StudentTestScores object are set equal to.
//
//*************************************************
StudentTestScores(StudentTestScores &obj)
{
              numTestScores = obj.numTestScores;
           studentName = obj.studentName;
           testScores = new double[numTestScores];
            for (int i=0; i<numTestScores; i++)
            testScores[i] = obj.testScores[i];
}


//*************************************************
// void class member function updateScore
// This function is used to update a specific score in an already defined StudentClassObject, this is done by reassigning a value to another, input validation is done if needed
//    Return
// ------------
// void
//
// Parameters
// ------------
// int index the index of the score to be updated
// double score the new score which will be input
//*************************************************
void updateScore(int index,double score){
    if (score<=100&&score>=0)
    testScores[index] = score;

    else
    cout<<"Enter a valid test score"<<endl;
}
    // The setTestScore function sets a specific
    // test score's value.
      //*************************************************
// void class member function setTestScore
// This function is used to input a specific score in an already defined StudentClassObject, this is done by assinging a value to another
//    Return
// ------------
// void
//
// Parameters
// ------------
// int index the index of the score to be assigned
// double score the new score which will be input
//*************************************************
   void setTestScore(double score, int index)
   { testScores[index] = score; }

    // Set the student's name.
   void setStudentName(string name)
   { studentName = name; }

    // Get the student's name.
   string getStudentName() const
   { return studentName; }

   // Get the number of test scores.
   int getNumTestScores()
   { return numTestScores; }


    // Get a specific test score.
   double getTestScore(int index) const
   { return testScores[index]; }

    //Class Destructor
     ~StudentTestScores()
   { delete [] testScores; }

};
#endif

