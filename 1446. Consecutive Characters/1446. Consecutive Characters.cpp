#include <iostream>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        const int str_len = s.length();
        int substr_start_index{ 0 };
        int max_len{ 1 }, tmp_len;
        
        for (int i{ 1 }; i < str_len; i++) {
            if (s[i] != s[substr_start_index]) {    // считаем длину
                tmp_len = i - substr_start_index;
                substr_start_index = i;
                if (max_len < tmp_len) {
                    max_len = tmp_len;
                }
            }
        }

        if (s[str_len - 1] == s[substr_start_index]) {  // могли пропустить (т.к тригер стоит на изменение) 
            tmp_len = str_len - substr_start_index;
            if (max_len < tmp_len) {
                max_len = tmp_len;
            }
        }

        return max_len;
    }
};

int main() {	// Для проверки
    Solution solution;

    string s1{ "leetcode" };
    string s2{ "abbcccddddeeeeedcba" };

    std::cout << solution.maxPower(s1) << std::endl;
    std::cout << solution.maxPower(s2) << std::endl;
}