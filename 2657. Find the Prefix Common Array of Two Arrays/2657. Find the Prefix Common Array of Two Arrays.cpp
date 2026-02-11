#include <vector>
#include <initializer_list>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<bool> memory(A.size(), false);
        int counter{};
        vector<int> common_arr(A.size(), 0);

        for (int i{}; i < A.size(); ++i) {
            if (memory[A[i] - 1]) {
                ++counter;
            }
            memory[A[i] - 1] = true;

            if (memory[B[i] - 1]) {
                ++counter;
            }
            memory[B[i] - 1] = true;

            common_arr[i] = counter;
        }

        return common_arr;
    }
};