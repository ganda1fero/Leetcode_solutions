#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int now_index{ 0 };
        const int str_len = s.length();

        int palind_start{ 0 }, palind_len{ 1 };

        int tmp_owset, tmp_left_index, tmp_right_index;
        while (now_index < str_len - 1) { // перебираем по строке (середину)
            // проверем (центр = эл.)
            tmp_owset = 0;
            tmp_left_index = now_index - (tmp_owset + 1);
            tmp_right_index = now_index + (tmp_owset + 1);
            while (tmp_left_index >= 0 && tmp_right_index < str_len && s[tmp_left_index] == s[tmp_right_index]) {
                tmp_owset++;
                tmp_left_index = now_index - (tmp_owset + 1);
                tmp_right_index = now_index + (tmp_owset + 1);
            }

            if (palind_len < tmp_owset * 2 + 1) {
                palind_start = now_index - tmp_owset;
                palind_len = tmp_owset * 2 + 1;
            }

            // провер€ем (центр = мнимый после эл.)
            tmp_owset = 0;
            tmp_left_index = now_index - tmp_owset;
            tmp_right_index = now_index + (tmp_owset + 1);
            while (tmp_left_index >= 0 && tmp_right_index < str_len && s[tmp_left_index] == s[tmp_right_index]) {
                tmp_owset++;
                tmp_left_index = now_index - tmp_owset;
                tmp_right_index = now_index + (tmp_owset + 1);
            }

            if (s[now_index - (tmp_owset - 1)] == s[now_index + tmp_owset] && palind_len < (tmp_owset - 1) * 2 + 2) {
                palind_start = now_index - (tmp_owset - 1);
                palind_len = (tmp_owset - 1) * 2 + 2;
            }

            now_index++;
        }

        return s.substr(palind_start, palind_len);
    }
};

int main() {// дл€ провреки 
    Solution solution;

    std::string s1{ "babad" };
    std::string s2{ "cbbd" };
    std::string s3{ "aaa" };

    //std::cout << solution.longestPalindrome(s1) << std::endl;
    //std::cout << solution.longestPalindrome(s2) << std::endl;
    std::cout << solution.longestPalindrome(s3);
}