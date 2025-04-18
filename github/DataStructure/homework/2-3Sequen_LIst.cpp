#include <iostream>
#include <string>
#include <set>
using namespace std;
#define Maxsize 20//假设最多有20个供应商

//本题所要求按照意思建立一个邻接表
struct Goods {
    char goodType;
    //goodSum同一个供应商添加同一种次数
    //unsigned int goodSum;
    struct Goods* Next;
};
/// @brief 
typedef struct Supplier
{
    string Name;
    struct Goods* good;
}SupNode,SuppArray[Maxsize];

struct Thing {
    SuppArray supplier;
    int length;
    int Capacity;
};

void InitList(Thing& L) {
    L.Capacity = Maxsize;
    L.length = 0;
}
void addGoods(Supplier* Ls, char type) {

   Supplier* lsh = Ls;
   Goods* obj = new Goods;
   
   
   //如果还是空表的话
   if (lsh->good == nullptr) {
       lsh->good = obj;
       obj->goodType = type;
    //obj->goodSum = 1;
       obj->Next = nullptr;
       return;
   }
   //找到结尾
   Goods* pg = lsh->good;
    while(pg->Next) {
        pg = pg->Next;
     }
    pg->Next = obj;
    obj->goodType = type;
   //obj->goodSum = 1;
    obj->Next = nullptr;
    return;
    
}
bool addSupplier(Thing& Lt, string name) {
    //添加供应商时，名字不同才添加
    int i = 0;
    for (i = 0; i < Lt.length; ++i) {
        if (Lt.supplier[i].Name == name) {
            return false;
        }
    }
    // Supplier* sp = new Supplier();
    // sp->Name = name;
    if ( i == Lt.length) {
        Lt.supplier[i].Name = name;
        Lt.supplier[i].good = nullptr;
        ++Lt.length;
        return true;
    } 
    return false;  
}
void print(Thing& Lt) {
    Thing L = Lt;
    Goods* g = nullptr;
    for (int i = 0; i < L.length; ++i) {
        g = L.supplier[i].good;
        while(g != nullptr) {
            cout << g->goodType << " ";
            g = g->Next;
        }
    }
    cout << endl;
}
int countAllGoods(Thing& Lt) {
    Thing L = Lt;
    int count = 0;
    //用set去重，计算出所有的种类就是set的长度
    set<char> ty;
    Goods* good1 = nullptr;
    for (int i = 0; i < L.length; ++i) {
        good1 = L.supplier[i].good;
        while(good1!= nullptr) {
            ty.insert(good1->goodType);
            //++count;
            good1 = good1->Next;
        }
    }
    count = ty.size();
    return count;
}

/// @brief 
/// @param Lt 
void destoryALllist(Thing& Lt) {
    Thing L = Lt;
    Goods* good1 = nullptr;
    int t = 0;
    for (int i = 0; i < L.length; ++i) {
        good1 = L.supplier[i].good;
        while(good1!= nullptr) {
            Goods* tmp = good1;
            good1 = good1->Next;
            cout << "free次数: " << t << endl;
            free(tmp);
            t++;
        }
    }
    good1 = nullptr;
}
int main()
{
    Thing p;
    InitList(p);
    //initList正确
    //int i = 0;
    //cout << "第i个供应商: " ;
    //可选择添加供应商，并赋予每个供应商名字
    bool res1 = addSupplier(p,"zhangsan");//true
    bool rs2 = addSupplier(p,"lisi");//true
    bool rs3 = addSupplier(p,"li");//false
    addSupplier(p,"wanger");
    //在第0个和第一个供应商上添加商品a b,b. 只要供应商人数在20个内，商品可以无限添加
    addGoods(&p.supplier[0],'f');
    addGoods(&p.supplier[0],'a');
    addGoods(&p.supplier[0],'k');
    addGoods(&p.supplier[0],'y');
    addGoods(&p.supplier[0],'y');
    addGoods(&p.supplier[2],'p');
    addGoods(&p.supplier[1],'t');
    addGoods(&p.supplier[3],'n');
    //打出添加进去的所有商品，不是商品种类，商品种类用set去重一下就行
    cout << p.length << endl;
    print(p);
    // cout << endl;
    // cout << res1 << " " << rs2 << " "<< rs3 << endl;
    //假设在10个供应商上添加
    int count = countAllGoods(p);
    cout <<"物品种类为： " << count << endl;
    //free掉所有节点
    destoryALllist(p);
    return 0;

}
