/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-29 11:02:47
 * @LastEditors: CGPan
 * @LastEditTime: 2022-11-29 12:00:30
 */
#include <iostream>
#include <vector>
using namespace std;
//存放中序遍历结果
vector<int>result;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};
void creatBiTree(TreeNode* &root) {
    
    int c;
    cin >> c;
    // -1表示空
    if (c == -1) {
        root = nullptr;
        return;
    } else {
        root = new TreeNode();
        root->data = c;
        creatBiTree(root->left);
        creatBiTree(root->right);
    }
}
//二叉排序树的中序遍历是从小到大有序的
void Inorder(TreeNode* root) {
    if (root == nullptr) {
        //cout << "#";
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    result.push_back(root->data);
    Inorder(root->right);
}
void isBSTree() {
    for (int i = 0; i < (int)result.size() - 1; ++i) {
        if (result[i] > result[i+1]){
            cout << "不是二叉排序树\n";
            return;
        }
    }
    cout << "是二叉排序树\n";
}
int main()
{
    TreeNode* root = nullptr;
    cout << "-1表示空:\n";
    creatBiTree(root);
    result.clear();
    Inorder(root);
    cout << endl;
    isBSTree();
    return 0;

}
