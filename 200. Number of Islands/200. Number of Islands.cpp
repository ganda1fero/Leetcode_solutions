#include <iostream>
#include <vector>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        DSU dsu(n * m);
        int answer{ 0 };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++answer;
                    int cur = getDSU_ID(i, j, n);

                    if (i > 0 && grid[i - 1][j] == '1') {
                        if (dsu.unite(cur, getDSU_ID(i - 1, j, n))) {
                            --answer;
                        }
                    }

                    if (j > 0 && grid[i][j - 1] == '1') {
                        if (dsu.unite(cur, getDSU_ID(i, j - 1, n))) {
                            --answer;
                        }
                    }
                }
            }
        }
        return answer;
    }
private:
    class DSU {
    public:
        DSU(int n) : parent(n) {
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            parent[y] = x;
            return true;
        }
    private:
        vector<int> parent;
    };

    int getDSU_ID(int i, int j, const int& n) {
        return i * n + j;
    }
};

int main() {    // for tests 
    /*
    std::ifstream ifile("C:\\Users\\makk2\\OneDrive\\Desktop\\test.txt", std::ios::in);
    std::ofstream ofile("C:\\Users\\makk2\\OneDrive\\Desktop\\test_new.txt", std::ios::out | std::ios::trunc);

    while (!ifile.eof()) {
        switch (char tmp_symbol = ifile.get())
        {
        case '[':
            ofile.put('{');
            break;
        case ']':
            ofile.put('}');
            break;
        case '\"':
            ofile.put('\'');
            break;
        default:
            ofile.put(tmp_symbol);
            break;
        }
        cout << "put\n";
    }
    ifile.close();
    ofile.close();
    */

    Solution solution;

    vector<vector<char>> grid = { {'1','1','1','1','1','0','1','1','1','1'},{'0','1','1','0','1','1','1','0','1','1'},{'1','0','1','0','1','1','0','1','0','1'},{'1','0','1','1','0','1','1','1','1','1'},{'1','1','0','0','1','1','1','1','1','1'},{'1','1','0','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','0','1'},{'0','1','1','0','1','1','1','1','1','0'},{'1','1','0','1','1','0','1','1','1','1'},{'0','1','1','1','1','1','0','1','1','1'} };

    for (const vector<char>& line : grid) {
        for (const char num : line) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    cout << "answer = " << solution.numIslands(grid) << endl;
}