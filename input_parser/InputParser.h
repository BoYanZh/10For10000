//
// Created by liu on 18-10-27.
//

#ifndef PROJECT_INPUTPARSER_H
#define PROJECT_INPUTPARSER_H

#include <fstream>
#include <vector>

class InputParser {
public:
    struct Data {
        size_t rowNum = 0, colNum = 0;
        size_t steps = 0, targetScore = 0;
        std::vector<std::vector<char> > board;

        friend class InputParser;

    private:
        Data() = default;
    };

    static Data parse(std::ifstream &is) {
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
};


#endif //PROJECT_INPUTPARSER_H
