//
// Created by jianyuelin on 1/29/2021.
//

#ifndef MINOS_INVERTED_ITEM_H
#define MINOS_INVERTED_ITEM_H

#include <vector>

class inverted_item {
public:
    inverted_item() = default;

    inverted_item(const std::string &doc_id, const std::size_t &token_id) : document_id{doc_id}, token_id{token_id} {
    }

    void add_position(int p) {
        this->positions.push_back(p);
    }

    const std::size_t get_token_id() {
        return this->token_id;
    }

    const std::string &get_document_id() {
        return this->document_id;
    }

    const std::vector<int>::size_type get_positions() const{
        return this->positions.size();
    }

private:
    std::size_t token_id;
    std::string document_id;
    std::vector<int> positions;
};

#endif //MINOS_INVERTED_ITEM_H
