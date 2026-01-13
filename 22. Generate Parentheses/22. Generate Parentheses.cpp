#include <iostream>
#include <vector>
using namespace std;

// само решение

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> answer;
		
		rec(answer, 1, 0, "(", n);

		return answer;
	}
private:
	void rec(vector<string>& main_vect, int opened, int closed, string now_str, const int& n) {
		if (opened < n) {	// открываем еще 1
			rec(main_vect, opened + 1, closed, now_str + '(', n);
		}
		if (closed < opened) {	// закрываем 1 
			rec(main_vect, opened, closed + 1, now_str + ')', n);
		}

		if (closed == n) {	// для выхода
			main_vect.push_back(now_str);
		}
	}
};

int main() {	// для проверки
	std::setlocale(LC_ALL, "");

	Solution solution;
	vector<string> tmp;
	for (int i{ 1 }; i < 4; ++i) {
		tmp = solution.generateParenthesis(i);
		std::cout << i << " скобок | " << tmp.size() << " вариантов:\n";
		for (string& str : tmp) {
			std::cout << str << ' ';
		}
		std::cout << std::endl;
	}
}