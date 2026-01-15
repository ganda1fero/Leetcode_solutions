#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> ANSI_s1(26, 0); // эталонный массив
        for (const char& symbol : s1) {
            ++ANSI_s1[symbol - 'a'];
        }

        vector<int> ANSI_buffer(26, 0); // массив для првоерки

        const int s2_len = s2.length();
        int left_p{ 0 }, right_p{ 0 };

        while (right_p != s2_len) {
            ++ANSI_buffer[s2[right_p] - 'a'];

            if (ANSI_buffer[s2[right_p] - 'a'] > ANSI_s1[s2[right_p] - 'a']) {  // перебрали
                // удаляем до нашего символа
                while (s2[left_p] != s2[right_p]) {
                    --ANSI_buffer[s2[left_p] - 'a'];
                    ++left_p;
                }
                --ANSI_buffer[s2[left_p] - 'a'];
                ++left_p;
            }
            else if (ANSI_buffer == ANSI_s1) {
                return true;
            }

            ++right_p;
        }

        return false;
    }
};

int main() {    // для проверки
    Solution solution;

    string s1 = "adc", s2 = "dcda";

    std::cout << std::boolalpha << solution.checkInclusion(s1, s2) << std::endl;
}