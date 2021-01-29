#include <iostream>
#include <fstream>
#include <utf.h>
#include <map>
#include <inverted_index.h>

int main() {
    std::map<std::string, inverted_index> indexer{};
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
            std::cout << token << std::endl;

            if (indexer.contains(token)) {
                inverted_index i = indexer[token];
                inverted_item s{document_id};
                s.add_position(position);
                i.add_item(s);
            } else {
                auto id = static_cast<unsigned int>(std::hash<std::string>{}(token));
                inverted_index i{id};
                inverted_item s{document_id};
                s.add_position(position);
                i.add_item(s);
                indexer[token] = i;
            }
        }
    }
    return 0;
}
