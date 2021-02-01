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

    explicit ContentReader(std::ifstream &ifstream) : stream{ifstream} {}

    iterator begin() const;

    iterator end() const;

private:
    std::ifstream &stream;
};

#endif //MINOS_CONTENTREADER_H
