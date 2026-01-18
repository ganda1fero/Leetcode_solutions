#include <iostream>
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
    bool isSymmetric(TreeNode* root) {
        return rec_isSymetric(root->left, root->right);
    }
private:
    bool rec_isSymetric(TreeNode* l_root, TreeNode* r_root) {
        if ((l_root == nullptr) != (r_root == nullptr)) {
            return false;
        }
        else if (l_root == nullptr) {
            return true;
        }
        else if (l_root->val != r_root->val) {
            return false;
        }

        return rec_isSymetric(l_root->left, r_root->right) && rec_isSymetric(l_root->right, r_root->left);
    }
};