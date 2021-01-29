//
// Created by jianyuelin on 1/29/2021.
//

#ifndef MINOS_INVERTED_INDEX_H
#define MINOS_INVERTED_INDEX_H

#include <vector>
#include "inverted_item.h"

class inverted_index {
public:
    inverted_index() {

    }

    explicit inverted_index(unsigned int id) : token_id{id} {
    }

    void add_item(const inverted_item &item) {
        postings.emplace_back(std::move(item));
    }

    const unsigned int &get_token_id() {
        return this->token_id;
    }

    const unsigned int &get_document_count() {
        return this->document_count;
    };

    const unsigned int &get_position_count() {
        return this->position_count;
    };

    const std::vector<inverted_item> get_postings() const {
        return this->postings;
    }

    bool operator<(const inverted_index &rhs) const {
        return this->token_id < rhs.token_id;
    }

private:
    unsigned int token_id{};
    std::vector<inverted_item> postings{};
    unsigned int document_count{};
    unsigned int position_count{};
};

#endif //MINOS_INVERTED_INDEX_H
