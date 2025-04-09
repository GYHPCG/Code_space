#ifndef __PRIVATESTRU_H_
#define __PRIVATESTRU_H_
typedef struct Obj Obj1;
Obj1* creat_obj(int id, const char* name);
void release_obj(Obj1* o);
int get_obj_id(const Obj1* o);

#endif 
