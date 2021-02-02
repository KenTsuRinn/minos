//
// Created by kennetsu on 2/2/21.
//

#ifndef MINOS_CONTENT_READER_H
#define MINOS_CONTENT_READER_H

#include <fstream>
#include <functional>
#include "content_iterator.h"

extern std::function<bool(std::string &)> null_string_filter;

class content_reader {
public:
    using iterator = content_iterator;

    content_reader() = default;

    explicit content_reader(std::ifstream &ifstream) : stream{ifstream} {
        for (std::string line; getline(stream, line);) {
            for (auto &p : pipes) {
                if (p(line))
                    continue;
                lines.push_back(line);

            }
        }
    }

    static void register_processor(std::initializer_list<std::function<bool(std::string &)>> functions);

    iterator begin() const;

    iterator end() const;

private:
    static std::vector<std::function<bool(std::string &)>> pipes;
    std::ifstream &stream;
    std::vector<std::string> lines{};
};

#endif //MINOS_CONTENT_READER_H
