#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input";
        return 0;
    }

    int *marks = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks: ";
        cin >> marks[i];
    }

    for (int i = 0; i < n; i++)
    {
        int *ptr = &marks[i];
        cout << "Marks: " << *ptr << endl;
    }

    int &ref = marks[0];
    ref += 5;

    cout << "Marks after bonus: " << ref << endl;

    delete[] marks;

    cout << "Memory released successfully" << endl;

    return 0;
}