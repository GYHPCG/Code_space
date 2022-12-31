/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-23 09:58:10
 * @LastEditors: CGPan
 * @LastEditTime: 2022-12-03 12:37:34
 */
#include <iostream>
#include <time.h>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;
// 0, 1, 2;
enum EntryType {Legitimate, Empty, Deleted};
int aslCount;
struct HashEntry {
    int Data;
    enum EntryType Info;
};
struct HashTable {
    int TableSize;
    struct HashEntry * Cells; /* 存放条目的数组 */
};
bool isPrime(int x) {
    if (x <= 3) {
        return x > 1;
    }
    for (int m = 2; m < sqrt(x); m++) {

        if (x % m == 0)
            return false;  
    }
    return true;
}
int nextPrime(int n) {
    for (int i = n; ; ++i) {
        if (isPrime(i)) return i;   
    }
    //return 53;
}
HashTable* creatHashTable(int N) {
    HashTable* hashTa = new HashTable();
    int i = 0;
    hashTa->TableSize = nextPrime(N);
    //cout << "prime:" << hashTa->TableSize << endl;
    hashTa->Cells = new HashEntry[hashTa->TableSize];
    for (i = 0; i < hashTa->TableSize; ++i) {
        hashTa->Cells[i].Info = Empty;
        hashTa->Cells[i].Data = -1;

    }
    return hashTa;
}
int Hash(int x, int hashSize) {
    int m = x % hashSize;
    return m;
}
int Find(HashTable* ha, int x) {
    int pos = 0, newPos = 0;
    int count = 1;
    //线性探测法
    newPos = pos = Hash(x,ha->TableSize);
    while(ha->Cells[newPos].Data != x && ha->Cells[newPos].Info != Empty) {
        ++count;
        ++newPos;
        newPos = (newPos) % ha->TableSize;
    }
    aslCount += count;
    return newPos;
}
void insertNum(int x,HashTable* ha) {

    int pos = Find(ha,x);
    if (ha->Cells[pos].Info == Empty || ha->Cells[pos].Info == Deleted) {
        ha->Cells[pos].Data = x;
        ha->Cells[pos].Info = Legitimate;
    }
}

//查找
void FindNNum(HashTable* ha, int x) {
    int pos = 0, newPos = 0;
    int count = 0;
    //线性探测法
    newPos = pos = Hash(x,ha->TableSize);
    while(ha->Cells[newPos].Data != x ) {
        ++count;
        ++newPos;
        newPos = (newPos) % ha->TableSize;
        if (ha->Cells[newPos].Info == Empty) {
            cout << "not found" << endl;
            return;
        }
    }

    cout << newPos << endl;;
}
void travel(HashTable* h) {
    int n = 0;
    for (int i = 0; i < h->TableSize; ++i) {
        //if (h->Cells[i].Data != -1)
        cout << h->Cells[i].Data << " ";
        ++n;
        if (n == 6) {
            cout << endl;
            n = 0;
        }
    }
}
int ASL() {
    return aslCount;
}
int main()
{
    int N = 11;
    HashTable* hash = creatHashTable(N);
    //srand((int)time(0));
    int t = 0;
    for (int i = 0; i < 9; ++i) {
        
        //int x = rand() % (1000 - 0 + 1);
        cin >> t;
        insertNum(t,hash);
    }
    cout << "-1表示为空:\n";
    travel(hash);
    cout << endl;
    cout << "输入需要查找的数：" << endl;
    int x;
    cin >> x;
    FindNNum(hash,x);
    cout << "ASL: " << ASL() / 8.0 << endl;
    return 0;

}
