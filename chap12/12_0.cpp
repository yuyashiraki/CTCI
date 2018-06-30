#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <iterator>

#define ll long long

using namespace std;

// Class and Inheritance
#define NAME_SIZE 50
class Person
{
    int id;
    char name[NAME_SIZE];
public:
/*    Person(int a) : id(a)
    {
        // id = a;   <-- this cannot be used if id is constant
        cout << "constructor" << endl;
    }*/
    // make sure ~Student() is called
    virtual ~Person()
    {
        cout << "destructor" << endl;
    }
    // virtual make sure Student's implmentation of aboutMe is called
    virtual void aboutMe()
    {
        cout << "I am a person.";
    }
    virtual bool addCourse(string s) = 0;
};
class Student : public Person
{
public:
    ~Student()
    {
        cout << "Deleting a student." << endl;
    }
    void aboutMe()
    {
        cout << "I am a student.";
    }
    bool addCourse(string s)
    {
        cout << "Added course " << s << "to student." << endl;
        return true;
    }
};

// Default values for parameters
int func(int a, int b = 3)
{
    int x = a;
    int y = b;
    return a + b;
}


// Operator Overloading
/* BookShelf BookShelf::operator+(BookShelf &other)
{
    // overload the + operator
} */


// Templates use the code to apply the same class to diffrent data types`
template <class T>
class ShiftedList
{
    T* array;
    int offset, size;
public:
    ShiftedList(int sz) : offset(0), size(sz)
    {
        array = new T[size];
    }
    ~ShiftedList()
    {
        delete [] array;
    }
    void shiftBy(int n)
    {
        offset = (offset + n) % size;
    }
    T getAt(int i)
    {
        return array[convertIndex(i)];
    }
    void setAt(T item, int i)
    {
        array[convertIndex(i)] = item;
    }
private:
    int convertIndex(int i)
    {
        int index = (i - offset) % size;
        while (index < 0) index += size;
        return size;
    }
};

int main()
{
    Person *p = new Student();
    p->aboutMe();
    p->addCourse("History");
    delete p;

    // pointer
    int *pp = new int;
    *pp = 7;
    int *q = pp;
    *pp = 8;
    cout << *q;

    // reference
    int a = 5;
    int &b = a;
    b = 7;
    cout << a;
    // allocates memory to store 12 and make b a reference to this
    const int &c = 12;

    // pointer arithmetic
    int *ppp = new int[2];
    ppp[0] = 0;
    ppp[1] = 1;
    ppp++;
    cout << *ppp;
    return 0;
}
