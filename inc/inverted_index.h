//
// Created by jianyuelin on 1/29/2021.
//

#ifndef MINOS_INVERTED_INDEX_H
#define MINOS_INVERTED_INDEX_H

#include <vector>
#include "inverted_item.h"

class inverted_index {
public:
    explicit inverted_index(int id) : token_id{id}, document_count{0}, position_count{0} {
        postings{new std::vector<inverted_item>};
    }

    void add_item(const inverted_item &item) {
        postings.emplace_back(std::move(item));
    }

    const int &get_token_id() {
        return this.token_id;
    }

    const int &get_document_count() {
        return this.document_count;
    };

    const int &get_position_count() {
        return this->position_count;
    };

    const std::vector<inverted_item> get_postings() const {
        return this->postings;
    }

    bool operator<(const inverted_index &rhs) const {
        return this->token_id < rhs.token_id;
    }

private:
    int token_id;
    const std::vector<inverted_item> &postings;
    int document_count;
    int position_count;
};

#endif //MINOS_INVERTED_INDEX_H
