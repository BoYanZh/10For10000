//
// Created by yhh on 18-10-27.
//

#include "../input_parser/InputParser.h"

#include <algorithm>
#include <array>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<array<int, 4> >> adjacentMap;

void initAdjacentMap(const InputParser::Data &data) {
    vector<pair<int, int>> directions = {
            {-1, 0},
            {0,  1},
            {1,  0},
            {0,  -1}
    };
    adjacentMap.clear();
    adjacentMap.reserve(data.rowNum);
    for (int i = 0; i < data.rowNum; i++) {
        vector<array<int, 4> > row(data.colNum);
        for (int j = 0; j < data.colNum; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + directions[k].first;
                int y = j + directions[k].second;
                int index = -1;
                if (x >= 0 && x < data.rowNum && y >= 0 && y < data.colNum) {
                    index = x * (int) data.colNum + y;
                }
                row[j][k] = index;
            }
        }
        adjacentMap.emplace_back(move(row));
    }
}


int main() {
    std::ifstream fin("testcases/case1.txt");
    auto data = InputParser::parse(fin);
    fin.close();

    initAdjacentMap(data);

    return 0;
}