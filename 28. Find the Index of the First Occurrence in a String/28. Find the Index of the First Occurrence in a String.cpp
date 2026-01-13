#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int haystack_len = haystack.length();
        const int needle_len = needle.length();
        int needle_count{ 0 };
        
        for (int i{ 0 }; i < haystack_len; i += 1) {
            while (haystack[i + needle_count] == needle[needle_count]) {
                needle_count += 1;
                if (needle_count == needle_len) {
                    return i;
                }
            }
            needle_count = 0;
        }

        return -1;  // if not found
    }
};

int main() {	// для провреки
	setlocale(LC_ALL, "");
    Solution solution;

    string haystack{ "mississippi" }, needle{ "issip" };
    std::cout << solution.strStr(haystack, needle);
}