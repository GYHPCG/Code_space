#include <stdio.h>
#include "privateStru.h"
#include <string.h>
#include <stdlib.h>

struct Obj {
    int id;
    char *name;
};

Obj1* create_obj(int id,const char* name)
{
    Obj1* ret = NULL;
    ret = (Obj1*)malloc(sizeof(Obj1));
    if(ret)
    {
        int len = 0;
        ret->id = id;
        len = strlen(name);
        ret->name = malloc(len + 1);
        if(ret->name)
        {
            memset(ret->name,0,len + 1);
            memcpy(ret->name,name,len);
        }
    }
    return ret;
}

void release_obj(Obj1* o)
{
    if(!o) return ;
    if(o->name)
    {
        free(o->name);
        o->name = NULL;
    }
    free(o);
    o = NULL;
}

int get_obj_id(const Obj1* o)
{
    int ret = 0;
    if(o)
    {
        ret = o->id;
    }
    return ret;
}

