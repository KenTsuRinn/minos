//
// Created by kennetsu on 2/2/21.
//

#ifndef MINOS_CONTENTREADER_H
#define MINOS_CONTENTREADER_H

#include <fstream>
#include <functional>
#include "ContentIterator.h"

class ContentReader {
public:
    using iterator = ContentIterator;

    ContentReader() = default;

    explicit ContentReader(std::ifstream &ifstream) : stream{ifstream} {
        for (std::string line; getline(stream, line);) {
            for (auto &p : this->pipes) {
                p(line);
            }
            lines.push_back(line);
        }
    }

    void register_processor(std::initializer_list<std::function<void(std::string &)>> functions);

    iterator begin() const;

    iterator end() const;

private:
    std::vector<std::function<void(std::string &)>> pipes;
    std::ifstream &stream;
    std::vector<std::string> lines{};
};

#endif //MINOS_CONTENTREADER_H
