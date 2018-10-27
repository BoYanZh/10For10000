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

    static Data parse(std::ifstream &is);
};


#endif //PROJECT_INPUTPARSER_H
