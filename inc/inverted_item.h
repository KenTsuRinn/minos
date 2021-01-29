//
// Created by jianyuelin on 1/29/2021.
//

#ifndef MINOS_INVERTED_ITEM_H
#define MINOS_INVERTED_ITEM_H

#include <vector>

class inverted_item {
public:
    inverted_item() : document_id{} {

    }

    explicit inverted_item(const std::string &id) : document_id{id} {
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
    std::string document_id{};
    std::vector<int> positions{};
};

#endif //MINOS_INVERTED_ITEM_H
