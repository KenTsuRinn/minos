//
// Created by kennetsu on 2/1/21.
//

#ifndef MINOS_CONTENT_ITERATOR_H
#define MINOS_CONTENT_ITERATOR_H

#include <iterator>
#include <vector>
#include <fstream>


class content_iterator {
public:
    using value_type = std::string;
    using difference_type = std::ptrdiff_t;
    using pointer = std::string *;
    using reference = std::string &;
    using iterator_category = std::bidirectional_iterator_tag;

    content_iterator();

    explicit content_iterator(std::vector<std::string> nodes);

    // Dereferencable.
    reference operator*() const;

    // Pre- and post-incrementable.
    content_iterator &operator++();

    content_iterator operator++(int);

    // Pre- and post-decrementable.
    content_iterator &operator--();

    content_iterator operator--(int);

    // Equality / inequality.
    bool operator==(const content_iterator &rhs);

    bool operator!=(const content_iterator &rhs);

    static std::string TERMINAL;

    static content_iterator get_terminal_iterator();
private:
    using Nodes = std::vector<std::string>;
    Nodes nodes{};
    Nodes::size_type current{0};
    Nodes::size_type size{0};
};



#endif //MINOS_CONTENT_ITERATOR_H
