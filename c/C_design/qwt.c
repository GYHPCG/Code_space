#include <stdio.h>

int main(){

        int array[10]={1,2,3,4,5,6,7,8,9,10};

        int *p=&array[2];

        printf("%d\n",*p);

        p=p+5;

        printf("%d\n",*p);

        p++;

        printf("%d\n",*p);

        p=p-2;

    printf("%d\n",*p);

        if(*p<array[5])

                printf("%d\n",100);

        else

                printf("%d\n",200);

 

        return 0;

}
