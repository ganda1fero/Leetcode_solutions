#include <iostream>
#include <algorithm>
#include <iomanip>
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        bool is_balanced{ true };
        if (std::abs(rec_isBalanced(root->left, 1, is_balanced) - rec_isBalanced(root->right, 1, is_balanced)) > 1) {
            is_balanced = false;
        }

        return is_balanced;
    }
private:
    int rec_isBalanced(TreeNode* root, int level, bool& is_balanced) {
        if (root == nullptr) {
            return level;
        }
        
        int left = rec_isBalanced(root->left, level + 1, is_balanced);
        int right = rec_isBalanced(root->right, level + 1, is_balanced);

        if (std::abs(left - right) > 1) {
            is_balanced = false;
        }

        return std::max(left, right);
    }
};

int main() {
    Solution solution;

    TreeNode tree(1, new TreeNode(2, new TreeNode(3), new TreeNode(3)), new TreeNode(2));

    cout << std::boolalpha << solution.isBalanced(&tree);
}