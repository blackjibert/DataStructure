//二叉树层序遍历

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
// 辅助函数：递归层序遍历
void recursiveLevelOrder(TreeNode* root, int level, vector<vector<int>>& result) {
    if (root == nullptr) {
        return;
    }
    // 确保结果向量足够大以容纳当前层的元素
    if (result.size() <= level) {
        result.push_back(vector<int>());
    }
    // 将当前节点的值添加到当前层的结果
    result[level].push_back(root->val);
    // 递归遍历左子树和右子树
    recursiveLevelOrder(root->left, level + 1, result);
    recursiveLevelOrder(root->right, level + 1, result);
}
// 主函数：二叉树的递归层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    recursiveLevelOrder(root, 0, result);
    return result;
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> result = levelOrder(root);
    cout << "递归层序遍历结果:" << endl;
    for (const vector<int>& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
