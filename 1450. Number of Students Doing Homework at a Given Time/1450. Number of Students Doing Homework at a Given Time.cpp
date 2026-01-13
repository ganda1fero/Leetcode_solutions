#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        const int arr_len = startTime.size();
        int answer{ 0 };
        
        for (int i{ 0 }; i < arr_len; i += 1) { // перебор всех студентов
            if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
                answer += 1;
            }
        }

        return answer;
    }
};

int main() {	// для проверки
    Solution solution;
    vector<int> startTime = { 1,2,3 };
    vector<int> endTime = { 3, 2, 7 };

    std::cout << solution.busyStudent(startTime, endTime, 4);
}