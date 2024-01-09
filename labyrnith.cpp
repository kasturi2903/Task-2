#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void dfs(vector<string> &labyrinth, int x, int y, int &count) {
    if (x < 0 || x >= labyrinth.size() || y < 0 || y >= labyrinth[0].size() || labyrinth[x][y] != '.') {
        return;
    }

    labyrinth[x][y] = '0' + count++;

    for (int i = 0; i < 8; ++i) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        dfs(labyrinth, newX, newY, count);
    }
}

int findLongestPath(vector<string> &labyrinth) {
    int a=labyrinth.size()-1;
    if(labyrinth[a]=="#######"){
        return 0;
    }
    int maxCount = 0;

    for (int i = 0; i < labyrinth[0].size(); ++i) {
        if (labyrinth[0][i] == '.') {
            int count = 0;
            dfs(labyrinth, 0, i, count);
            maxCount = max(maxCount, count);
        }
    }

    return maxCount;
}

int main() {
    vector<string> labyrinth;
    ifstream ifs("input.txt");

    if (!ifs.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string line;
    while (getline(ifs, line)) {
        labyrinth.push_back(line);
    }

    int longestPath = findLongestPath(labyrinth);

    if (longestPath > 0) {
        cout << longestPath << endl;
        for (const auto &line : labyrinth) {
            cout << line << endl;
        }
    } else {
        cout << -1 << endl;
        for (const auto &line : labyrinth) {
            cout << line << endl;
        }
    }

    return 0;
}
