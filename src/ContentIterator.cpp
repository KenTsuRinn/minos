//
// Created by kennetsu on 2/1/21.
//

#include "ContentIterator.h"

ContentIterator::ContentIterator(std::vector<std::string> nodes) {
    this->nodes = std::move(nodes);
//    nodes.push_back(nullptr);
}

// Dereferencable.
ContentIterator::reference ContentIterator::operator*() const {
    return const_cast<std::string &>(nodes[current]);
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
    if (rhs.nodes.size() == 0)
        return false;
    return nodes[current] == rhs.nodes[rhs.current];
}


bool ContentIterator::operator!=(const ContentIterator &rhs) {
    return !(*this == rhs);
}