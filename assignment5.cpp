#include <iostream>
using namespace std;

class Student {
private:
    int RollNO;
    string Name;
    int marks;
    static int count;

public:
    Student(int RollNO, string Name, int marks) {
        this->RollNO = RollNO;
        this->Name = Name;
        this->marks = marks;
        count++;
    }

    inline void display() {
        cout << "RollNO: " << RollNO << endl;
        cout << "Name: " << Name << endl;
        cout << "marks: " << marks << endl;
    }

    static void showCount() {
        cout << "Total Students: " << count << endl;
    }

    friend class Result;
};

int Student::count = 0;

class Result {
public:
    void showResult(Student obj) {
        cout << "Result Information" << endl;
        if (obj.marks >= 40) {
            cout << obj.Name << " has passed." << endl;
        } else {
            cout << obj.Name << " has Failed" << endl;
        }
    }
};

int main() {
    Student a1(101, "Aman", 80);
    Student a2(102, "Suraj", 90);

    cout << "Student a1." << endl;
    a1.display();

    cout << "student a2." << endl;
    a2.display();

    Student::showCount();

    Result r;
    r.showResult(a1);
    r.showResult(a2);

    return 0;
}