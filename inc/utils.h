//
// Created by jianyuelin on 2/3/2021.
//

#ifndef MINOS_UTILS_H
#define MINOS_UTILS_H

#include <string.h>
#include <iostream>
#include <inverted_item.h>
#include <experimental/type_traits>

template<typename T>
using std_to_string_expression = decltype(std::to_string(std::declval<T>()));

template<typename T>
constexpr bool has_std_to_string = std::experimental::fundamentals_v2::is_detected<std_to_string_expression, T>{};

template<typename T>
using to_string_expression = decltype(to_string(std::declval<T>()));

template<typename T>
constexpr bool has_to_string = std::experimental::fundamentals_v2::is_detected<to_string_expression, T>{};

template<typename T>
using ostringstream_expression = decltype(std::declval<std::ostringstream &>() << std::declval<T>());

template<typename T>
constexpr bool has_ostringstream = std::experimental::fundamentals_v2::is_detected<ostringstream_expression, T>{};

template<typename T, typename std::enable_if<has_std_to_string<T>, int>::type = 0>
std::string toString(T const &t) {
    return std::to_string(t);
}

template<typename T, typename std::enable_if<!has_std_to_string<T> && has_to_string<T>, int>::type = 0>
std::string toString(T const &t) {
    return to_string(t);
}

template<typename T, typename std::enable_if<
        !has_std_to_string<T> && !has_to_string<T> && has_ostringstream<T>, int>::type = 0>
std::string toString(T const &t) {
    std::ostringstream oss;
    oss << t;
    return oss.str();
}


struct None {
};

template<typename First, typename Second>
struct Pair {
    First first;
    Second second;
};

template<typename List>
struct LogData {
    List list;
};

template<typename Begin, typename Value>
LogData<Pair<Begin, const Value &>>
operator<<(LogData<Begin> begin, const Value &value) {
    return {{begin.list, value}};
}

template<typename Begin, size_t n>
LogData<Pair<Begin, const char *>>
operator<<(LogData<Begin> begin, const char (&value)[n]) {
    return {{begin.list, value}};
}

inline void printList(std::ostream &os, None) {
}


template<typename Begin, typename Last>
void printList(std::ostream &os, const Pair<Begin, Last> &data) {
    printList(os, data.first);
    os << data.second;
}

template<typename List>
void log(const char *file, int line, const LogData<List> &data) {
    std::cout << file << " (" << line << "): ";
    printList(std::cout, data.list);
    std::cout << "\n";
}

#define LOG(x) (log(__FILE__,__LINE__,LogData<None>() << x))


template<typename T>
std::string vec_string_join(const std::vector<T> &v);

template<>
std::string vec_string_join<inverted_item>(const std::vector<inverted_item> &v) {
    std::stringstream ss;
    for (auto &iter: v) {
        ss << iter.get_document_id();
    }
    return ss.str();
}

#endif //MINOS_UTILS_H
