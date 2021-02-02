//
// Created by kennetsu on 2/2/21.
//

#include <content_reader.h>

std::function<bool(std::string &)> null_string_filter = [](std::string &l) {
    if (l.empty())
        return true;
    else
        return false;
};

content_reader::iterator content_reader::begin() const {
    return content_iterator{lines};
}

content_reader::iterator content_reader::end() const {
    return content_iterator{};
}

void content_reader::register_processor(std::initializer_list<std::function<bool(std::string &)>> functions) {
    for (auto f : functions) {
        content_reader::pipes.push_back(f);
    }
}

std::vector<std::function<bool(std::string &)>> content_reader::pipes{};
