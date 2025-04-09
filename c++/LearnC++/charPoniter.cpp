
#include <iostream>

using namespace std;
struct Person 
{
    /* data */
    char* name;
    int age;
    double Weight;
};
int main()
{
    Person* p = new Person;
    p->name = new char[20];
    cin >> p->name >> p->age >> p->Weight;
    cout << p->name <<" "<< p->age <<" "<< p->Weight;
    delete [] p->name;
    delete p;
    return 0;

}

