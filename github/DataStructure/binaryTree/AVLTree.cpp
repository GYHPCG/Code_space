/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-15 16:15:54
 * @LastEditors: CGPan
 * @LastEditTime: 2022-11-25 17:18:48
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <string.h>
#include <algorithm>
#include <queue>
#include <random>
using namespace std;

using eLementType = int;

const int num = (int)(1.1e+7);

const int maxSize =(int)(1.1e+7);

int hashArr[maxSize];

struct AVLNode {
    eLementType Data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
};
struct TreeNode {
    int Data;
    TreeNode* left;
    TreeNode* right;
}*BinaryTree;

int getHeight(AVLNode* root) {
    if (root == nullptr) return 0;
    return root->height;
}
//左单旋转
AVLNode* singleLeftRo(AVLNode* T) {
    AVLNode* T1 = T->left;
    T->left = T1->right;
    T1->right = T;
    T1->height = max(getHeight(T1->left),getHeight(T1->right)) + 1;
    T->height = max(getHeight(T->left),getHeight(T->right)) + 1;
    return T1;
}
//右单旋转
AVLNode* singRightRo(AVLNode* T) {
    AVLNode* T1 = T->right;
    T->right = T1->left;
    T1->left = T;
    T1->height = max(getHeight(T1->left),getHeight(T1->right)) + 1;
    T->height = max (getHeight(T->left),getHeight(T->right)) + 1;
    return T1;
}
//左双旋，先右后左
AVLNode* doubleLeftRo(AVLNode* T) {
    T->left = singRightRo(T->left);
    return singleLeftRo(T);
}
//右双旋转
AVLNode* doubleRightRo(AVLNode* T) {
    T->right = singleLeftRo(T->right);
    return singRightRo(T);
}
AVLNode* insertAVLTree(AVLNode* T, eLementType x) {
    if (T == nullptr) {
        T = new AVLNode();
        T->Data = x;
        T->height = 1;
        T->left = T->right = nullptr;
    } else if (x < T->Data) {
        T->left = insertAVLTree(T->left,x);
        if (getHeight(T->left) - getHeight(T->right) == 2) {
            
            if (x < T->left->Data) {
                T = singleLeftRo(T);
            } else {
                T = doubleLeftRo(T);
            }
           
        } 
    } else if (x > T->Data){
        T->right = insertAVLTree(T->right,x);
        if (getHeight(T->right) - getHeight(T->left) == 2) {
           if (x > T->right->Data) {
             T = singRightRo(T);
           } else {
             T = doubleRightRo(T);
           }
        } 
    }
    T->height = max(getHeight(T->left),getHeight(T->right)) + 1;
    return T;
}
//二叉排序树
void InsertBST(TreeNode* &root,int e) {
    if (root == nullptr) {
        root = new TreeNode();
        root->Data = e;
        root->left = root->right = nullptr;
    }
    else {
        if (root->Data > e) {
            InsertBST(root->left,e);
        } else {
            InsertBST(root->right,e);
        }
    }
}
template<typename T>
void preTravel(T* root) {
    if (root == nullptr) {
        cout << "#";
        return;
    }
    cout << root->Data;
    preTravel(root->left);
    preTravel(root->right);
}
template<typename T>
void Inorder(T* root) {
    if (root == nullptr) {
        cout << "#";
        return;
    }
    Inorder(root->left);
    cout << root->Data;
    Inorder(root->right);
}
template<typename T>
void PostOrder(T* root) {
    if (root == nullptr) {
        cout << "#";
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->Data;
}
AVLNode* inistAVLtree(AVLNode* root) {
    int x;
    for (int i = 0; i < 6; ++i) {
        cin >> x;
        root = insertAVLTree(root,x);
    }
    return root;
}
void inistBSTree(TreeNode* &root) {
    int x;
    for (int i = 0; i < 4; ++i) {
        cin >> x;
        InsertBST(root,x);
    }
}
//随机产生多个数
AVLNode* inistAVLtree(AVLNode* root, int n,int hashArr[]) {
     int x1;
     srand((int)time(nullptr));
     //伪随机数产生器，用于产生高性能的随机数，范围 0~2^19937-1。
    //  mt19937 rng(time(0));
    //  shuffle(hashArr,hashArr+maxSize,rng);
    for (int i = 0; i < maxSize; ++i) {
         x1 = ((rand()<<8) | rand());//x1 在大约在0~八百三十多万范围内
        //x2 = ((rand()<<8) | rand());
        swap(hashArr[x1],hashArr[i]);
         //root = insertAVLTree(root,hashArr[i]);
    }
    for (int i = 0; i < n; ++i) {
        root = insertAVLTree(root,hashArr[i]);
    }
    return root;
}
void inistBSTree(TreeNode* &root, int n,int hashArr[]) {
    int x1;
    srand((int)time(nullptr));
    //random_shuffle(hashArr,hashArr+maxSize);
    for (int i = 0; i < maxSize; ++i) {
        x1 = ((rand()<<8) | rand());//x1 在大约在0~八百三十多万范围内
        //x2 = ((rand()<<8) | rand());
        swap(hashArr[x1],hashArr[i]);
    }  
    for (int i = 0; i < n; ++i) {
        InsertBST(root,hashArr[i]);
    }  
}
//获取结点总数
template<typename T>
int getCount(T* root) {
    if (root == nullptr) return 0;
    return 1 + getCount(root->left) + getCount(root->right);
}
//获取层次之和
//层序遍历获取
template<typename T>
int levelOrderCount(T* root) 
{
        queue<T*> que;
        if (root != NULL) que.push(root);
        int result = 0;//总层序之和
        int height = 1;//第一次为1开始
        while (!que.empty()) {
            int size = que.size();
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i = 0; i < size; i++) {
                T* node = que.front();
                que.pop();
                result += height;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            //到下一层，height + 1;
            ++height;
        }
        return result;
}
//递归获取
template<typename T>
int DLcount(T* root) {
    if (root == nullptr) return 0;
    return DLcount(root->left) + DLcount(root->right) + getCount(root);
}
template<typename T>
void deleteTree(T* &root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main()
{

    for (int i = 0; i < maxSize; ++i) {
        hashArr[i] = i;
    }
    //AVLNode* root1 = nullptr;
    //TreeNode* root2 = nullptr;
    // root1 = inistAVLtree(root1);
    // cout << "先序输出平衡树：" << endl;
    // preTravel(root1);
    // cout << endl;
    // cout << "中序输出平衡树：" << endl;
    // Inorder(root1);
    // cout << endl;
    // inistBSTree(root2);
    // cout << "先序输出BST: " << endl;
    // preTravel(root2);
    // cout << endl;
    // cout << DLcount(root2) << endl;
    // cout << levelOrderCount(root2) << endl;
    int N = 5000000;
    cout << "输入"<< N << "个不同数：" << endl;
    TreeNode* root3 = nullptr;
    inistBSTree(root3,N,hashArr);
    //cout << "先序输出" << N << "个的BST" << endl;
    //preTravel(root3); 
    float ASL1 = DLcount(root3)*1.0 / getCount(root3);
    //float ASL11 = levelOrderCount(root3)*1.0 / getCount(root3);
    cout << "BSTree的结点数: " << getCount(root3) << endl;
    cout << "BSTree的层次之和: " << DLcount(root3) << endl;
    cout <<"BSTree的ASL:" << ASL1 << endl;
    //cout <<"BSTree的ASL:" << ASL11 << endl;
    AVLNode* root4 = nullptr;
    root4 = inistAVLtree(root4,N,hashArr);
    //cout << "先序输出" << N << "个的AVLTree" << endl;
    //preTravel(root4);
    float ASL2 = DLcount(root4)*1.0 / getCount(root4);
    cout << "AVLTree的结点数: " << getCount(root4) << endl;
    cout << "AVLTree的层次之和: " << DLcount(root4) << endl;
    cout << "AVLTree的ASL: " << ASL2 << endl;
    // std::mt19937 rng(time(0));
    return 0;

}
