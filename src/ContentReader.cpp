//
// Created by kennetsu on 2/2/21.
//

#include <ContentReader.h>


ContentReader::iterator ContentReader::begin() const {
    return ContentIterator{lines};
}

ContentReader::iterator ContentReader::end() const {
    return ContentIterator{};
}

void ContentReader::register_processor(std::initializer_list<std::function<void(std::string &)>> functions) {
    for (auto f : functions) {
        this->pipes.push_back(f);
    }
}