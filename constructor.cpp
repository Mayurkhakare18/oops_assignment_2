#include <iostream>
using namespace std;

class Student
{
public:
    int marks;

    // 1. Default Constructor
    Student()
    {
        marks = 0;
    }

    // 2. Parameterized Constructor
    Student(int m)
    {
        marks = m;
    }

    // 3. Copy Constructor
    Student(const Student &obj)
    {
        marks = obj.marks;
    }

    // Member Function 1
    void display()
    {
        cout << "Marks = " << marks << endl;
    }

    // Member Function 2
    void setMarks(int m)
    {
        marks = m;
    }
};

int main()
{
    Student s1;        // Default constructor
    Student s2(80);    // Parameterized constructor
    Student s3(s2);    // Copy constructor

    s1.setMarks(70);   // Calling new member function

    s1.display();
    s2.display();
    s3.display();

    return 0;
}