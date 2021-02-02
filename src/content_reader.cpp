//
// Created by kennetsu on 2/2/21.
//

#include <content_reader.h>


content_reader::iterator content_reader::begin() const {
    return content_iterator{lines};
}

content_reader::iterator content_reader::end() const {
    return content_iterator{};
}

void content_reader::register_processor(std::initializer_list<std::function<void(std::string &)>> functions) {
    for (auto f : functions) {
        this->pipes.push_back(f);
    }
}