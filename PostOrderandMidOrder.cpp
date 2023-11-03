//由后序和中序来恢复二叉树
#include <iostream>
#include <vector>
using namespace std;
// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 辅助函数：根据中序遍历和后序遍历数组构建二叉搜索树
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }
    // 后序遍历的最后一个元素是当前子树的根节点
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);
    // 在中序遍历中找到根节点的索引
    int rootIndex;
    for (rootIndex = inStart; rootIndex <= inEnd; rootIndex++) {
        if (inorder[rootIndex] == rootVal) {
            break;
        }
    }
    // 递归构建左子树和右子树
    root->left = buildTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + (rootIndex - inStart) - 1);
    root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd, postStart + (rootIndex - inStart), postEnd - 1);
    return root;
}
// 主函数：根据中序遍历和后序遍历数组构建二叉搜索树
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int inLength = inorder.size();
    int postLength = postorder.size();
    return buildTree(inorder, postorder, 0, inLength - 1, 0, postLength - 1);
}
// 辅助函数：中序遍历二叉树，用于验证结果
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = buildTree(inorder, postorder);
    cout << "中序遍历结果: ";
    inOrderTraversal(root);
    return 0;
}
