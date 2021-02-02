//
// Created by kennetsu on 2/1/21.
//

#ifndef MINOS_CONTENTITERATOR_H
#define MINOS_CONTENTITERATOR_H

#include <iterator>
#include <vector>
#include <fstream>

class ContentIterator {
public:
    using value_type = std::string;
    using difference_type = std::ptrdiff_t;
    using pointer = std::string *;
    using reference = std::string &;
    using iterator_category = std::bidirectional_iterator_tag;

    ContentIterator() = default;

    explicit ContentIterator(std::vector<std::string> nodes);

    // Dereferencable.
    reference operator*() const;

    // Pre- and post-incrementable.
    ContentIterator &operator++();

    ContentIterator operator++(int);

    // Pre- and post-decrementable.
    ContentIterator &operator--();

    ContentIterator operator--(int);

    // Equality / inequality.
    bool operator==(const ContentIterator &rhs);

    bool operator!=(const ContentIterator &rhs);

private:
    using Nodes = std::vector<std::string>;
    Nodes nodes;
    Nodes::size_type current{0};
};


#endif //MINOS_CONTENTITERATOR_H
