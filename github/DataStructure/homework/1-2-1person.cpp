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
    Person* p = new Person();
    //p->name = (char*)malloc(sizeof(char));
    //gets(p->name);
    //p->name = new char[20];
    //p->name = nullptr;
    //cin >> p->name;
    char* name = new char[20];
    cin >> name;
    scanf("%s",name);
    cin >> p->age >> p->Weight;
    cout << name << endl;
    cout << p->age << p->Weight;
    return 0;

}
