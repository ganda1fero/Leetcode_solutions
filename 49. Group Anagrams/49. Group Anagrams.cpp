#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<long, vector<string>> m_map;
        long tmp_long;
        int tmp_int{ 0 };

        answer.resize(strs.size());

        for (string& str : strs) {
            tmp_long = 0;
            for (const char& symbol : str) {
                tmp_long += symbol * symbol * symbol * symbol;
            }

            m_map[tmp_long].push_back(str);
        }

        // проходим по m_map
        for (auto it = m_map.begin(); it != m_map.end(); ++it) {
            answer[tmp_int].swap(it->second);
            ++tmp_int;
        }
        answer.erase(answer.begin() + tmp_int, answer.end());

        return answer;
    }
};

int main() {	// для тестов
    Solution solution;
    vector<string> vect1 = { "eat","tea","tan","ate","nat","bat" };

    vector<vector<string>> answer1 = solution.groupAnagrams(vect1);
    for (const vector<string>& arr : answer1){
        for (const string& str : arr) {
            cout << '\"' << str << "\" ";
        }
        cout << endl;
    }
}