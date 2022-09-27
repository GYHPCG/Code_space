#include <iostream>
#include <string>
#include <set>
using namespace std;
#define Maxsize 20//假设最多有20个供应商

//本题所要求按照意思建立一个邻接表
struct Goods {
    char goodType;
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
void addGoods(Supplier& Ls, char type) {
   Goods* obj = (Goods*)malloc(sizeof(Goods));
   Supplier& lsh = Ls;
   obj->goodType = type;
   obj->Next = nullptr;
   //如果还是空表的话
   if (lsh.good == nullptr) {
    lsh.good = obj;
   }
   //找到结尾
   else {
     while(lsh.good->Next!= nullptr) {
        lsh.good = lsh.good->Next;
     }
   lsh.good->Next = obj;
   }
    
}
bool addSupplier(Thing& Lt, string name) {
    //添加供应商时，名字不同才添加
    int i = 0;
    for (i = 0; i < Lt.length; ++i) {
        if (Lt.supplier[i].Name == name) {
            return false;
        }
    }
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
    int i = 0;
    cout << "第i个供应商: " ;
    //可选择添加供应商，并赋予每个供应商名字
    bool res1 = addSupplier(p,"zhangsan");//true
    bool rs2 = addSupplier(p,"lisi");//true
    bool rs3 = addSupplier(p,"lisi");//false
    //在第0个和第一个供应商上添加商品a b,b. 只要供应商人数在20个内，商品可以无限添加
    addGoods(p.supplier[0],'a');
    addGoods(p.supplier[0],'b');
    addGoods(p.supplier[1],'b');
    //打出添加进去的所有商品，不是商品种类，商品种类用set去重一下就行
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
