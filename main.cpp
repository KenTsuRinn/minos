#include <iostream>
#include <fstream>
#include <utf.h>
#include <map>
#include <inverted_item.h>
#include <sstream>

int main() {
    std::map<std::string, inverted_item> indexer{};
    std::ifstream input("jin_ping_mei_15.txt");
    const std::string document_id{"jin_ping_mei_15.txt"};
    int position{};
    for (std::string line; getline(input, line);) {
        std::u32string u32line = to_utf32(line);

        for (std::u32string::const_iterator it = u32line.begin(); it != u32line.end(); ++it) {
            if (is_ignored_char(*it))
                continue;

            ++position;
            std::u32string ngram_token{*it, *(it + 1)};
            std::string token = to_utf8(ngram_token);

            std::size_t token_hash = std::hash<std::string>{}(token);
            std::ostringstream stringStream;
            stringStream << document_id;
            stringStream << ":";
            stringStream << token;
            std::string copyOfStr = stringStream.str();

            if (indexer.contains(token)) {
                std::map<std::string, inverted_item>::iterator it = indexer.find(token);
                if (it != indexer.end()){
                    if (token == "一盤") {
                        std::cout << &(it->second) << std::endl;

                    }
                    it->second.add_position(position);

                }


            } else {
                inverted_item s{document_id, token_hash};
                s.add_position(position);
                indexer[token] = s;
            }
        }
    }
    for (auto const&[key, val] : indexer) {
        if (key == "一盤"){
            std::cout << &val<<std::endl;
            std::cout << val.get_positions() << std::endl;

        }
        if (val.get_positions() > 1)
            std::cout << key        // string (key)
                      << ':'
                      << std::endl;
    }

    return 0;
}
