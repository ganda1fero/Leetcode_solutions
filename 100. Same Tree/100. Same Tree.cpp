#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return rec_isSameTreee(p, q);
    }
private:
    bool rec_isSameTreee(TreeNode* f_root, TreeNode* s_root) {
        if ((f_root == nullptr) != (s_root == nullptr)) {   // если одно закончилось
            return false;
        }
        else if (f_root == nullptr) {   // т.к оба одинаковы => достаточно проверить 1
            return true;
        }
        else if (f_root->val != s_root->val) {
            return false;
        }

        return rec_isSameTreee(f_root->left, s_root->left) && rec_isSameTreee(f_root->right, s_root->right);
    }
};

int main() {	// для проверок
    Solution solution;

    TreeNode f_tree(1, new TreeNode(2), new TreeNode(3));
    TreeNode s_tree(1, new TreeNode(2), new TreeNode(3));

    std::cout << std::boolalpha << solution.isSameTree(&f_tree, &s_tree);
}