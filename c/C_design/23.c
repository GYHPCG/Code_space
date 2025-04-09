#include<stdio.h>

int main(){

                int i,m=0,n=0,k=0;

               for(i=9; i<=11;i++)

                      switch(i%10){

                                case 0:     printf("%d\n",m);

m++; n++; break;

                              case 1:    printf("%d\n",n);

n++; break;

                              default:  k++; n++;

                        }

                printf("%d %d %d\n",m,n,k); 

             return 0;

}

