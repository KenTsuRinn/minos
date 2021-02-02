//
// Created by kennetsu on 2/1/21.
//

#include "ContentIterator.h"

ContentIterator::ContentIterator() {
    this->nodes.push_back(this->TERMINAL);
    this->size = this->nodes.size();
}

ContentIterator::ContentIterator(std::vector<std::string> nodes) {
    this->nodes = std::move(nodes);
    this->nodes.push_back(this->TERMINAL);
    this->size = this->nodes.size();
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
    return nodes[current] == rhs.nodes[rhs.current];
}


bool ContentIterator::operator!=(const ContentIterator &rhs) {
    return !((*this).nodes[current] == rhs.nodes[rhs.current]);
}


std::string ContentIterator::TERMINAL = "ITERATOR_ENDING";

ContentIterator ContentIterator::get_terminal_iterator() {
    std::vector<std::string> ending{};
    ending.push_back(ContentIterator::TERMINAL);
    return ContentIterator{ending};

}