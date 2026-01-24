#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int matrix_size = mat.size();
        int answer{ 0 };

        for (int i{ 0 }; i < matrix_size; ++i) {
            answer += mat[i][i] + ((i != matrix_size - i - 1) ? mat[i][matrix_size - i - 1] : 0);
        }

        return answer;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };

    cout << solution.diagonalSum(matrix);
}