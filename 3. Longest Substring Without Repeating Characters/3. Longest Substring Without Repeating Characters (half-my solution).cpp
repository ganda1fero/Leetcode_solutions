#include <iostream>
#include <unordered_map>
using namespace std;

//сам решение
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start_substr_index{ 0 }, now_index{ 0 }, max_len{ 0 };
        const int str_len = s.length();
        bool used_ANSI[128] = { false };

        while (now_index < str_len) {
            max_len = max(max_len, now_index - start_substr_index);

            while (used_ANSI[s[now_index]]) {
                used_ANSI[s[start_substr_index]] = false;
                start_substr_index++;
            }

            used_ANSI[s[now_index]] = true;

            now_index++;    // увеличиваем счетчик
        }

        max_len = max(max_len, now_index - start_substr_index);

        return max_len;
    }
};


// для отладки -------
int main() {
    std::setlocale(LC_ALL, "");

    Solution solution;

    string s1 = "abcabcbb";
    string s2 = "pwwkew";
    string s3 = "";
    string s4 = " ";

    cout << '(' << s1 << ')' << " | " << solution.lengthOfLongestSubstring(s1) << std::endl;
    cout << '(' << s2 << ')' << " | " << solution.lengthOfLongestSubstring(s2) << std::endl;
    cout << '(' << s3 << ')' << " | " << solution.lengthOfLongestSubstring(s3) << std::endl;
    cout << '(' << s4 << ')' << " | " << solution.lengthOfLongestSubstring(s4) << std::endl;
}