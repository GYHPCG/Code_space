#include <stdio.h>

int func1(int a,int b){

        return a+b;

}

 

int func2(int a,int b){

        return a-b;

}

 

int func3(int a,int b){

        return a*b;

}

 

int main(){

        int a,b;

        scanf("%d%d",&a,&b);

        switch(a+b){

                case 10:

                        printf("%d\n",func1(a,b));

                        printf("%d\n",func2(a,b));

                        printf("%d\n",func3(a+1,b+1));

                case 11:

                        printf("%d\n",func2(a,b));

                        printf("%d\n",func1(a,b));

                        break;

                case 12:

                        printf("%d\n",func3(a+1,b+1));

                        printf("%d\n",func1(a,b));

                        printf("%d\n",func2(a,b));

        }

        return 0;

}

