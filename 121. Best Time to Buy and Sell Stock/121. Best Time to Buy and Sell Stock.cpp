#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profite{ 0 };
        int buy_index{ 0 };

        for (int i{ 1 }; i < prices.size(); ++i) {
            max_profite = max(max_profite, prices[i] - prices[buy_index]);
            if (prices[i] < prices[buy_index]) {
                buy_index = i;
            }
        }

        return max_profite;
    }
};

int main() {	// Для проверки
    Solution solution;

    vector<int> price = { 7,1,5,3,6,4 };

    std::cout << solution.maxProfit(price);
}