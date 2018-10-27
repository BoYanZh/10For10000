//
// Created by yhh on 18-10-27.
//

#include "../input_parser/InputParser.h"

#include <fstream>

int main() {
    std::ifstream fin("testcases/case1.txt");
    auto data = InputParser::parse(fin);
    fin.close();

    return 0;
}