//
// Created by kennetsu on 2/2/21.
//

#include <ContentReader.h>

ContentReader::iterator ContentReader::begin() const {
    stream.seekg(std::ios::beg);
    return ContentIterator{stream};
}

ContentReader::iterator ContentReader::end() const {
    stream.seekg(std::ios::end);
    return ContentIterator{stream};
}