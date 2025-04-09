/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-02 11:39:54
 * @LastEditors: CGPan
 * @LastEditTime: 2022-11-29 11:24:39
 */
#include <iostream>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
}*BinaryTree;
void creatBiTree(TreeNode* &root) {
    
    char c;
    cin >> c;
    if (c == '#') {
        root = nullptr;
        //return;
    } else {
        root = new TreeNode();
        root->data = c;
        creatBiTree(root->left);
        creatBiTree(root->right);
    }
}
// void creatBTS(TreeNode* &root) {

// }
void InsertBST(TreeNode* &root,char e) {
    if (root == nullptr) {
        root = new TreeNode();
        root->data = e;
        root->left = root->right = nullptr;
    }
    else {
        if (root->data > e) {
            InsertBST(root->left,e);
        } else {
            InsertBST(root->right,e);
        }
    }
}
void preTravel(TreeNode* root) {
    if (root == nullptr) {
        cout << "#";
        return;
    }
    cout << root->data;
    preTravel(root->left);
    preTravel(root->right);
}
void Inorder(TreeNode* root) {
    if (root == nullptr) {
        cout << "#";
        return;
    }
    Inorder(root->left);
    cout << root->data;
    Inorder(root->right);
}
void PostOrder(TreeNode* root) {
    if (root == nullptr) {
        cout << "#";
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data;

}
int TreeDeath(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } 
    return 1 + max(TreeDeath(root->left),TreeDeath(root->right));
}
TreeNode* FindMin(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    return root->left == nullptr ? root:FindMin(root->left);
}
void DeleteNode(TreeNode*& root, int x) {
    TreeNode* p = nullptr;
    if (root == nullptr) {
        return ;
    }
    else if (root->data > x) {
        DeleteNode(root->left,x);
    }
    else if (root->data < x) {
        DeleteNode(root->right,x);
    } else {
        
        //左右都不空，直接删除
        if (root->left != nullptr && root->right != nullptr) {
            p = FindMin(root->right);
            root->data = p->data;
            //因为用p->data替换，后面要删掉原来p->data的那个节点
            DeleteNode(root->right,p->data);
            //delete root;
        } else {
            p = root;
            if (root->left == nullptr) {
                root = root->right;
            } else if (root->right == nullptr) {
                root = root->left;
            }
            delete p;
        }
    }
    //return root;
}
int countLeaf(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    
    return countLeaf(root->left) + countLeaf(root->right);

}

int count(TreeNode* root) {
    if (root == nullptr) return 0;

    return 1 + count(root->left) + count(root->right);
}
void TreeCopy(TreeNode* root, TreeNode* cpoyTree) {
    //TreeNode* cpoyTree = nullptr;
    if (root == nullptr) {
        cpoyTree = nullptr;
        return;
    }
    cpoyTree = new TreeNode();
    cpoyTree->data = root->data;
    TreeCopy(root->left,cpoyTree->left);
    TreeCopy(root->right,cpoyTree->right);

}
TreeNode* getFather(TreeNode* root, TreeNode* p){
    if (p == root || root == nullptr || p == nullptr) return nullptr;

    if (root->left == p || root->right == p) return root;

    TreeNode* left = getFather(root->left,p);

    if (left) return left;

    TreeNode* right = getFather(root->right,p);

    if (right) return right;

    return nullptr;

} 
int main()
{
    TreeNode* root1 = nullptr;
    creatBiTree(root1);
    cout << "先序遍历：" << endl;
    preTravel(root1);
    cout << endl;
    cout << "中序遍历：" << endl;
    Inorder(root1);
    cout << endl;
    cout << "后序遍历：" << endl;
    PostOrder(root1);
    // cout << "二叉排序树：" << endl;
    // TreeNode* root2 = nullptr;
    // int n = 10;
    // while(n--) {
    //     int x;
    //     cin >> x;
    //     InsertBST(root2,x);
    // }
    // cout << "先序：" << endl;
    // preTravel(root2);
    // cout << endl;
    // cout << "中序：" << endl;
    // Inorder(root2);
    // cout << endl;
    // cout << "后序： "<< endl;
    // PostOrder(root2);
    // cout << endl;
    // cout << "高度："  << endl;
    // cout << TreeDeath(root2) << endl;
    // cout << "节点数：" << endl;
    // cout << count(root2) << endl;
    // cout << "最小值：" << endl;
    // TreeNode* min_node = FindMin(root2);
    // cout << min_node->data << endl;
    // int de = 5;
    // cout << "删除节点：" << de << endl;
    // DeleteNode(root2,de);
    // cout << "删除后先序：" << endl;
    // preTravel(root2);
    // cout << endl;
    // cout << "删除后中序：" << endl;
    // Inorder(root2);
    // cout << endl;
    // cout << "删除后后序：" << endl;
    // PostOrder(root2);
    return 0;

}
