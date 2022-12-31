/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-29 11:37:09
 * @LastEditors: CGPan
 * @LastEditTime: 2022-11-29 11:50:45
 */
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
}*BinaryTree;

void creatBiTree(TreeNode* &root) {
    
    char c;
    cin >> c;
    // -1表示空
    if (c == '#') {
        root = nullptr;
        return;
    } else {
        root = new TreeNode();
        root->data = c;
        creatBiTree(root->left);
        creatBiTree(root->right);
    }
}
void levelOrder(TreeNode* root) 
{
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            //一个循环遍历一层
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                cout << node->data << " ";
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            cout << "\n";
        }
}
void destoryTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    destoryTree(root->left);
    destoryTree(root->right);
    delete root;
}
int main()
{
    TreeNode* root = nullptr;
    creatBiTree(root);
    cout << "输出层序遍历结果：\n";
    levelOrder(root);
    destoryTree(root);
    return 0;

}
