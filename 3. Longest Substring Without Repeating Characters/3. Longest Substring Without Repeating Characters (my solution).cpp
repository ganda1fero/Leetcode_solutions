#include <iostream>
#include <unordered_map>
using namespace std;

//сам решение
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // переменные
        int max_len{ 0 }, substr_start_index{ 0 }, now_index{ 0 };    // начинается с 0
        const int string_len = s.length();
        vector<int> ANSI_pos(128, -1); // создали массив с позицией == -1 (начальное)

        while (now_index < string_len) {
            if (ANSI_pos[s[now_index]] >= substr_start_index) {  //  такой символ в подстроке есть!
                max_len = max(max_len, now_index - substr_start_index); // (обновили) max_len
                substr_start_index = ANSI_pos[s[now_index]] + 1;
            }

            ANSI_pos[s[now_index]] = now_index; // автоматом записываем/перезаисываем индекс символа 
            now_index++;
        }

        // считаем что получилось в конце (на всякий если не было пересечений)
        max_len = max(max_len, now_index - substr_start_index);
        return max_len;
    }
};


// для отладки -------
int main() {
    std::setlocale(LC_ALL, "");

    Solution solution;

    string s1 = "abcabcbb";
    string s2 = "pwwkew";
    string s3 = "3212";
    string s4 = "f  ";

    cout << s1 << " | " << solution.lengthOfLongestSubstring(s1) << std::endl;
    cout << s2 << " | " << solution.lengthOfLongestSubstring(s2) << std::endl;
    cout << s3 << " | " << solution.lengthOfLongestSubstring(s3) << std::endl;
    cout << s4 << " | " << solution.lengthOfLongestSubstring(s4) << std::endl;
}