#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return rec_isValidBST(root, INT_MIN, INT_MAX);
    }
private:
    bool rec_isValidBST(TreeNode* root, int min, int max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val >= max || root->val <= min) {
            return false;
        }

        return rec_isValidBST(root->left, min, root->val) && rec_isValidBST(root->right, root->val, max);
    }
};