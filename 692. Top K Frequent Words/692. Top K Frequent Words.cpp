#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) { // like O(2n * log(n))
        unordered_map<string, int> un_map;  // <word : count>
        un_map.rehash(500); // to save iterators connections (buckets cant be more than 500) 
        unordered_map<string, int>::iterator map_it;

        vector<unordered_map<string, int>::iterator> vect;
        
        for (const string& word : words) {  // O(n)
            if ((map_it = un_map.find(word)) == un_map.end()) {
                vect.push_back(un_map.emplace(word, 1).first);  // add a new word (count = 1) and push iterator to vector
            }
            else {
                map_it->second += 1;
            }
        }

        std::sort(vect.begin(), vect.end(),
            [](const auto& l_it, const auto& r_it) {
                if (l_it->second == r_it->second) {
                    return l_it->first < r_it->first;
                }
                return l_it->second > r_it->second;
            }); // O(n * (log(n)))

        vector<string> answer;
        answer.reserve(k);
        for (int i{ 0 }; i < k; ++i) {
            answer.push_back(vect[i]->first);
        }
        return answer;
    }
};

int main() {    // for tests
    Solution solution;

    vector<string> words = { "the","day","is","sunny","the","the","the","sunny","is","is" };
    int k = 4;

    for (const string& word : solution.topKFrequent(words, k)) {
        cout << word << ' ';
    }

    return 0;
}