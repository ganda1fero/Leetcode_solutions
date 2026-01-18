#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tree_levels;



    }
private:
    void tmp(TreeNode* root) {
        
    }
};

int main() {    // для проверки
    Solution solution;

    TreeNode tree(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    for (const vector<int>& arr : solution.levelOrder(&tree)) {
        cout << '[';
        for (const int& num : arr) {
            cout << num << ',';
        }
        cout << "\b],";
    }
}