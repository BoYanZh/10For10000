//
// Created by liu on 18-10-27.
//

#include "InputParser.h"

InputParser::Data InputParser::parse(std::ifstream &is) {
    Data data;
    is >> data.rowNum >> data.colNum >> data.steps >> data.targetScore;
    data.board.reserve(data.rowNum);
    for (size_t i = 0; i < data.rowNum; i++) {
        std::vector<char> row;
        row.reserve(data.colNum);
        for (size_t j = 0; j < data.colNum; j++) {
            int temp = 0;
            // Set default angle as 0
            if (!is.eof()) {
                is >> temp;
            }
            row.emplace_back((char) temp);
        }
        data.board.emplace_back(std::move(row));
    }
    return data;
}
