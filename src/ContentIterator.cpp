//
// Created by kennetsu on 2/1/21.
//

#include "ContentIterator.h"

std::ifstream &ContentIterator::go_to_line(size_t num) const {
    stream.seekg(std::ios::beg);
    for (int i = 0; i < num + 1; ++i) {
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return stream;
}

// Dereferencable.
ContentIterator::reference ContentIterator::operator*() const {
    std::ifstream &s = this->go_to_line(current);
    std::getline(s, this->current_line);
    return current_line;
}

// Pre-incrementable: ++it.
ContentIterator &ContentIterator::operator++() {
    ++current;
    return *this;
}

// Post-incrementable: it++.
ContentIterator ContentIterator::operator++(int) {
    ContentIterator tmp = *this;
    ++current;
    return tmp;
}

// Pre-decrementable: --it.
ContentIterator &ContentIterator::operator--() {
    --current;
    return *this;
}

// Post-decrementable: it--.
ContentIterator ContentIterator::operator--(int) {
    ContentIterator tmp = *this;
    --current;
    return tmp;
}

bool ContentIterator::operator==(const ContentIterator &rhs) {
    std::ifstream &s = this->go_to_line(current);
    std::string left{};
    std::getline(s, left);

    auto &rs = rhs.go_to_line(rhs.current);
    std::string right{};
    std::getline(rs, right);
    return left == right;
}


bool ContentIterator::operator!=(const ContentIterator &rhs) {
    return !(*this == rhs);
}