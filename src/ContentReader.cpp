//
// Created by kennetsu on 2/2/21.
//

#include <ContentReader.h>


ContentReader::iterator ContentReader::begin() const {
    return ContentIterator{lines};
}

ContentReader::iterator ContentReader::end() const {
    return ContentIterator::get_terminal_iterator();
}