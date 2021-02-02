#include <iostream>
#include <fstream>
#include <utf.h>
#include <map>
#include <inverted_item.h>
#include <sstream>
#include <filesystem>
#include <ContentReader.h>

int main() {
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
    for (const auto &dirEntry : recursive_directory_iterator("./data")) {
        std::cout << dirEntry.path() << std::endl;
        std::map<std::string, inverted_item> indexer{};
        std::ifstream input(dirEntry.path());
        const std::string document_id{dirEntry.path()};
        int position{};

        ContentReader reader{input};
        using ContentIt = ContentReader::iterator;
        ContentIt it = reader.begin();
        ContentIt it_end = reader.end();

        for (const auto &line : reader) {
            if (line.empty())
                continue;
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
                    if (it != indexer.end()) {
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
            if (key == "一盤") {
                std::cout << &val << std::endl;
                std::cout << val.get_positions() << std::endl;

            }
            if (val.get_positions() > 1)
                std::cout << key        // string (key)
                          << ':'
                          << std::endl;
        }
    }

    return 0;
}
