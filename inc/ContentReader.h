//
// Created by kennetsu on 2/2/21.
//

#ifndef MINOS_CONTENTREADER_H
#define MINOS_CONTENTREADER_H

#include <fstream>
#include "ContentIterator.h"

class ContentReader {
public:
    using iterator = ContentIterator;

    ContentReader() = default;

    explicit ContentReader(std::ifstream &ifstream) : stream{ifstream} {
        for (std::string line; getline(stream, line);) {
            if (line.empty())
                continue;
            lines.push_back(line);
        }
    }

    iterator begin() const;

    iterator end() const;

private:
    std::ifstream &stream;
    std::vector<std::string> lines{};
};

#endif //MINOS_CONTENTREADER_H
