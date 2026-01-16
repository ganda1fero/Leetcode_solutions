#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<vector<int>>::iterator it = std::lower_bound(matrix.begin(), matrix.end(), target,
            [](const vector<int>& elem, const int& target) {
                return elem.back() < target;
            }); // it указывает на нужный массив
        if (it == matrix.end()) {
            return false;
        }
        
        vector<int>::iterator it2 = std::lower_bound(it->begin(), it->end(), target,
            [](const int& elem, const int& target) {
                return elem < target;
            });

        return *it2 == target;
    }
};

int main() {	// для проверок
    Solution solution;

    vector<vector<int>> arr1 = { {1,3,5,7}, {10,11,16,20}, {23,30,34,60} };

    cout << std::boolalpha << solution.searchMatrix(arr1, 3);
}