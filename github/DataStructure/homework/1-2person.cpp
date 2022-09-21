#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person 
{
    /* data */
    char* name;
    int age;
    double Weight;
};

int main()
{
    
    //struct Person *p = (struct Person*)malloc(sizeof(struct Person));
    struct Person p;
    
    p.name = (char*)malloc(sizeof(char));
    //fp->name = NULL;
    gets(p.name);
    //scanf("%s",p->name);
    scanf("%d%lf",&p.age,&p.Weight);
    printf("%s %d %f\n",p.name,p.age,p.Weight);
    return 0;

}
