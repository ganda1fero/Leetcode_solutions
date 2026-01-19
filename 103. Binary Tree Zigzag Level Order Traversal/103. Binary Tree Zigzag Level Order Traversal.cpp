#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> tree_levels;
        queue<tmp_root> q;

        q.push(tmp_root(root, 0));
        tree_levels.push_back({ root->val });

        vector<int> tmp_level;
        tmp_root now_node;
        int last_level{ 0 };
        while (!q.empty()) {
            now_node = q.front();    // взяли node
            q.pop();
            if (now_node.level != last_level) {
                if (now_node.level % 2 == 1) {
                    std::reverse(tmp_level.begin(), tmp_level.end());
                }
                tree_levels.push_back(tmp_level);
                tmp_level.clear();
                last_level = now_node.level;
            }

            if (now_node.ptr->left != nullptr) {
                tmp_level.push_back(now_node.ptr->left->val);
                q.push(tmp_root(now_node.ptr->left, now_node.level + 1));
            }
            if (now_node.ptr->right != nullptr) {
                tmp_level.push_back(now_node.ptr->right->val);
                q.push(tmp_root(now_node.ptr->right, now_node.level + 1));
            }
        }

        return tree_levels;
    }
private:
    struct tmp_root {
        TreeNode* ptr;
        int level;
        tmp_root(TreeNode* ptr, int level) : level(level), ptr(ptr) {}
        tmp_root() : ptr(nullptr), level(0) {}
    };
};

int main() {    // для проверки
    Solution solution;

    TreeNode tree(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    for (const vector<int>& arr : solution.zigzagLevelOrder(&tree)) {
        cout << '[';
        for (const int& num : arr) {
            cout << num << ',';
        }
        cout << "\b],";
    }
    cout << "\b ";
}