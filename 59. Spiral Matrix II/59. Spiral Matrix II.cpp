#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int numb{ 1 }, now_i, now_j;
        for (int diag{ 0 }, half_n = n / 2 + ((n % 2 == 0) ? 0 : 1); diag < half_n; ++diag) {
            now_i = now_j = diag;
            
            // само тело
            matrix[now_i][now_j] = numb++;
            
            for (int h{ 0 }; h < n - 1 - diag * 2; ++h) {   // вправо
                matrix[now_i][++now_j] = numb++;
            }
            for (int h{ 0 }; h < n - 1 - diag * 2; ++h) {   // вниз
                matrix[++now_i][now_j] = numb++;
            }
            for (int h{ 0 }; h < n - 1 - diag * 2; ++h) {   // влево
                matrix[now_i][--now_j] = numb++;
            }
            for (int h{ 0 }; h < n - 2 - diag * 2; ++h) {   // вверх
                matrix[--now_i][now_j] = numb++;
            }
        }

        return matrix;
    }
};

int main() {	// для проверок
    Solution solution;
    
    int num = 1;

    for (const vector<int>& line : solution.generateMatrix(num)) {
        for (const int& numb : line) {
            std::cout << std::setw(2) << numb << ' ';
        }
        std::cout << std::endl;
    }
}