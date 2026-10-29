
#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout << "Base class show()" << endl;
    }

    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Derived class show()" << endl;
    }

    void derivedOnly()
    {
        cout << "Derived-only function called" << endl;
    }
};

int main()
{
    // ================ 1. static_cast =================

    cout << "===== 1. static_cast =====" << endl;

    int a = 7, b = 2;

    cout << "Without cast: 7 / 2 = " << (a / b) << endl;
    cout << "With cast   : 7 / 2 = "
         << static_cast<double>(a) / b << endl;

    double d = 9.99;
    int i = static_cast<int>(d);

    cout << "double 9.99 to int : " << i << endl;

    char ch = 'A';

    cout << "char 'A' to int : "
         << static_cast<int>(ch) << endl;

    int n = 97;

    cout << "int 97 to char : "
         << static_cast<char>(n) << endl;

    Derived dObj;
    Base *basePtr = &dObj;

    Derived *dPtr = static_cast<Derived*>(basePtr);
    // Downcast in the same hierarchy

    dPtr->derivedOnly();

    // ================ 2. dynamic_cast =================

    cout << endl << "===== 2. dynamic_cast =====" << endl;

    Base *b1 = new Derived();
    // Base pointer holding a Derived object

    Base *b2 = new Base();
    // Base pointer holding a Base object

    Derived *d1 = dynamic_cast<Derived*>(b1);

    if (d1 != NULL)
    {
        cout << "Cast of b1 succeeded: ";
        d1->derivedOnly();
    }
    else
    {
        cout << "Cast of b1 failed" << endl;
    }

    Derived *d2 = dynamic_cast<Derived*>(b2);

    if (d2 != NULL)
    {
        cout << "Cast of b2 succeeded" << endl;
    }
    else
    {
        cout << "Cast of b2 failed: dynamic_cast returned NULL"
             << endl;
    }

    try
    {
        Derived &ref = dynamic_cast<Derived&>(*b2);
        ref.derivedOnly();
    }
    catch (bad_cast &)
    {
        cout << "Reference cast of *b2 failed: bad_cast exception caught"
             << endl;
    }

    delete b1;
    delete b2;

    // ================ 3. const_cast =================

    cout << endl << "===== 3. const_cast =====" << endl;

    int val = 50;

    const int *cPtr = &val;
    // Pointer to const int

    cout << "Before const_cast : val = " << val << endl;

    int *ncPtr = const_cast<int*>(cPtr);
    // Remove constness from the pointer type

    *ncPtr = 100;

    cout << "After const_cast : val = " << val << endl;

    // ================ 4. reinterpret_cast =================

    cout << endl << "===== 4. reinterpret_cast =====" << endl;

    int num = 65;

    int *iPtr = &num;

    char *cp = reinterpret_cast<char*>(iPtr);
    // View the int's memory through a char pointer

    cout << "Value of int       : " << num << endl;

    cout << "First byte as char : " << *cp
         << " (ASCII " << static_cast<int>(*cp) << ")"
         << endl;

    return 0;
}
