#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int line_len = matrix[0].size();
        
        for (int i{ 0 }, columns = matrix.size() / 2; i < columns; i += 1) {    // проходим по столбцам
            for (int j{ i }; j < line_len - 1 - i; j += 1) {
                spiralSwap(matrix, line_len, i, j);
            }
        }
    }
private:
    void spiralSwap(vector<vector<int>>& matrix, const int line_len ,int i, int j) {
        int buffer;
        queue<int> tmp_queue;
        tmp_queue.push(matrix[i][j]);
        
        buffer = i;
        i = j;
        j = line_len - 1 - buffer;

        for (int counter{ 0 }; counter < 4; counter += 1) {
            tmp_queue.push(matrix[i][j]);
            matrix[i][j] = tmp_queue.front();
            tmp_queue.pop();

            buffer = i;
            i = j;
            j = line_len - 1 - buffer;
        }
    }
};

// [0, 0] -> [0, (line_len - 1) - 0] +
// [0, 1] -> [1, (line_len - 1) - 0] +
// [0, 2] -> [2, (line_len - 1) - 0] +

// добавляем в очередь [i, j]; i = new_i; j = new_j;
// 
// добавляем в очередь [i, j]
// [i, j] = pop_front()
//  i = new_i
//  j = new_j


// для проверок

void printArr(vector<vector<int>>& arr) {
    for (vector<int> line : arr) {
        for (int num : line) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    Solution solution;
   
    vector<vector<int>> arr = { {1,2,3}, {4,5,6}, {7,8,9} };

    printArr(arr);
    std::cout << std::endl;
    solution.rotate(arr);
    printArr(arr);
    std::cout << std::endl;
    
    vector<vector<int>> arr2 = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };

    printArr(arr2);
    std::cout << std::endl;
    solution.rotate(arr2);
    printArr(arr2);
}