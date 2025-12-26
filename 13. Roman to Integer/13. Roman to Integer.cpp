#include <iostream>
#include <unordered_map>

using namespace std;

/*
Основные значения:
	I - 1
	V - 5
	X - 10
	L - 50
	C - 100
	D - 500
	M - 1000
Также стоит учитывать:

*/

class Solution {
public:
	int romanToInt(string s) {
		const int str_len = s.length();
		int answer{ 0 }, now, next;

		unordered_map<char, int> romans = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

		for (int i{ 0 }; i < str_len; i++) {
			now = romans[s[i]];
			next = romans[s[i + 1]];

			if (now < next) {
				answer -= now;
			}
			else {
				answer += now;
			}
		}
		
		return answer;
	}
};

int main() {	// для проверки 
	Solution solution;

	string s1 = "LVIII";	// 58
	string s2 = "MCMXCIV";	// 1994

	std::cout << s1 << " = " << solution.romanToInt(s1) << std::endl;
	std::cout << s2 << " = " << solution.romanToInt(s2) << std::endl;
}