#include <iostream>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return rec_maxDepth(root, 1);
    }
private:
    int rec_maxDepth(TreeNode* root, int level) {
        return std::max(root->left != nullptr ? rec_maxDepth(root->left, level + 1) : level, root->right != nullptr ? rec_maxDepth(root->right, level + 1) : level);
    }
};

int main() {    // Для проверки
    Solution solution;

    TreeNode tree(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    std::cout << solution.maxDepth(&tree);
}