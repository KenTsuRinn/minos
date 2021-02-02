//
// Created by kennetsu on 2/1/21.
//

#include "content_iterator.h"

content_iterator::content_iterator() {
    this->nodes.push_back(this->TERMINAL);
    this->size = this->nodes.size();
}

content_iterator::content_iterator(std::vector<std::string> nodes) {
    this->nodes = std::move(nodes);
    this->nodes.push_back(this->TERMINAL);
    this->size = this->nodes.size();
}

// Dereferencable.
content_iterator::reference content_iterator::operator*() const {
    return const_cast<std::string &>(nodes[current]);
}

// Pre-incrementable: ++it.
content_iterator &content_iterator::operator++() {
    ++current;
    return *this;
}

// Post-incrementable: it++.
content_iterator content_iterator::operator++(int) {
    content_iterator tmp = *this;
    ++current;
    return tmp;
}

// Pre-decrementable: --it.
content_iterator &content_iterator::operator--() {
    --current;
    return *this;
}

// Post-decrementable: it--.
content_iterator content_iterator::operator--(int) {
    content_iterator tmp = *this;
    --current;
    return tmp;
}

bool content_iterator::operator==(const content_iterator &rhs) {
    return nodes[current] == rhs.nodes[rhs.current];
}


bool content_iterator::operator!=(const content_iterator &rhs) {
    return !((*this).nodes[current] == rhs.nodes[rhs.current]);
}


std::string content_iterator::TERMINAL = "ITERATOR_ENDING";

content_iterator content_iterator::get_terminal_iterator() {
    std::vector<std::string> ending{};
    ending.push_back(content_iterator::TERMINAL);
    return content_iterator{ending};

}