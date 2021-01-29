//
// Created by jianyuelin on 1/29/2021.
//

#ifndef MINOS_INVERTED_ITEM_H
#define MINOS_INVERTED_ITEM_H

#include <vector>

class inverted_item {
public:
    explicit inverted_item(const std::string &id) : document_id{id} {
        positions{new std::vector<int>{}};
    }

    inverted_item(const inverted_item &rhs) = delete;

    inverted_item(const inverted_item &&rhs) : document_id{std::move(rhs.document_id)},
                                               positions{std::move(rhs.positions)} {
    }

    inverted_item &operator=(inverted_item &&other) noexcept {
        if (this != other) {
            delete positions;
            document_id = other.document_id;
            positions = std::move(other);
            delete other.positions;
        }
        return *this;
    }

    ~inverted_item() {
        delete positions;
    }

    void add_position(int p) {
        this->positions.emplace_back(p);
    }

    const std::string &get_document_id() {
        return this->document_id;
    }

    const std::vector<int> &get_positions() {
        return this->positions;
    }

private:
    std::string document_id;
    const std::vector<int> *positions;
};

#endif //MINOS_INVERTED_ITEM_H
