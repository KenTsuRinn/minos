#include <iostream>
#include <utf.h>
#include <map>
#include <inverted_item.h>
#include <sstream>
#include <filesystem>
#include <content_reader.h>
#include <utils.h>

int main() {
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
    std::map<std::string, std::vector<inverted_item>> indexer{};
    content_reader::register_processor({
                                               null_string_filter
                                       });
    for (const auto &dirEntry : recursive_directory_iterator("./data")) {
        LOG(dirEntry.path());
        std::ifstream input(dirEntry.path());
        const std::string document_id{dirEntry.path()};
        int position{};
        content_reader reader{input};
        for (const auto &line : reader) {
            std::u32string u32line = encoding::to_utf32(line);

            for (std::u32string::const_iterator it = u32line.begin(); it != u32line.end(); ++it) {
                if (encoding::is_ignored_char(*it))
                    continue;
                ++position;
                std::u32string ngram_token{*it, *(it + 1)};
                std::string token = encoding::to_utf8(ngram_token);

                std::size_t token_hash = std::hash<std::string>{}(token);
                std::ostringstream stringStream;
                stringStream << document_id;
                stringStream << ":";
                stringStream << token;
                std::string copyOfStr = stringStream.str();

                inverted_item s{document_id, token_hash};
                s.add_position(position);

                if (indexer.contains(token)) {
                    auto it = indexer.find(token);
                    if (it != indexer.end()) {
                        it->second.push_back(s);
                    }
                } else {
                    std::vector<inverted_item> inverteds{};
                    inverteds.push_back(s);
                    indexer[token] = inverteds;
                }

            }
        }
    }
    for (auto const&[key, val] : indexer) {
        LOG(key);
        for (auto const &v : val) {
            LOG(toString<inverted_item>(v));
        }
        LOG("-----------------------");
    }
    return 0;

}