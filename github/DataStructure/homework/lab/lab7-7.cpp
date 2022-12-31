/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-29 11:52:21
 * @LastEditors: CGPan
 * @LastEditTime: 2022-11-29 12:19:18
 */
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int weight;
    TreeNode* left;
    TreeNode* right;
}*BinaryTree;

void creatBiTree(TreeNode* &root) {
    
    int c;
    cin >> c;
    // -1表示空
    if (c == -1) {
        root = nullptr;
        return;
    } else {
        root = new TreeNode();
        root->weight = c;
        creatBiTree(root->left);
        creatBiTree(root->right);
    }
}
int getWPL(TreeNode* root) 
{
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result  = 0;//存放WPL
        int deapth = 0;//计算深度
        while (!que.empty()) {
            int size = que.size();
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            //一个循环遍历一层
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                //叶子节点计算WPL;
                if (node->left == nullptr && node->right == nullptr) {
                     result += node->weight * deapth;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ++deapth;//深度加1
        }
        return result;
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
    cout << "-1表示空\n";
    creatBiTree(root);
    cout << "WPL: " << getWPL(root) << endl; 
    destoryTree(root);
    return 0;

}
