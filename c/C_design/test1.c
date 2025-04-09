#include "privateStru.h"
//#include "privateStru.c"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	Obj1* k = creat_obj(1,"test 1");
	//printf("id:%d\n",k->id);
	printf("id:%d\n",get_obj_id(k));
	release_obj(k);
	 return 0;
}
