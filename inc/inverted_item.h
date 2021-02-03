//
// Created by jianyuelin on 1/29/2021.
//

#ifndef MINOS_INVERTED_ITEM_H
#define MINOS_INVERTED_ITEM_H

#include <vector>
#include <sstream>


class inverted_item {
public:
    inverted_item() = default;

    inverted_item(const std::string &doc_id, const std::size_t &token_id) : document_id{doc_id}, token_id{token_id} {
    }

    void add_position(int p) {
        this->positions.push_back(p);
    }

    const std::size_t get_token_id() const {
        return this->token_id;
    }

    const std::string &get_document_id() const {
        return this->document_id;
    }

    const std::vector<int>::size_type get_position_count() const {
        return this->positions.size();
    }

    const std::string get_all_positions() const {
        std::stringstream ss;
        for (auto &p:this->positions) {
            ss << " ";
            ss << p;
            ss << " ";
        }
        return ss.str();
    }

private:
    std::size_t token_id;
    std::string document_id;
    std::vector<int> positions;
};

std::string to_string(const inverted_item &i) {
    std::stringstream ss;
    ss << " key: ";
    ss << i.get_token_id();
    ss << " document_id: ";
    ss << i.get_document_id();
    ss << " positions: ";
    ss << i.get_all_positions();
    return ss.str();
}

#endif //MINOS_INVERTED_ITEM_H
