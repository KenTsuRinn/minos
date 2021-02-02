//
// Created by jianyuelin on 1/29/2021.
//

#ifndef MINOS_UTF_H
#define MINOS_UTF_H
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include <string>
#include <locale>
#include <codecvt>

class encoding {

public:
    static bool is_ignored_char(char32_t const &c);

    static std::string to_utf8(std::string const &s);

    static std::string to_utf8(std::u32string const &s);

    static std::string to_utf8(std::wstring const &s);

    static std::wstring to_wstring(std::wstring const &s);

    static std::wstring to_wstring(std::string const &s);

    static std::wstring to_wstring(std::u32string const &s);

    static std::u16string to_utf16(std::string const &s);

    static std::u16string to_utf16(std::u16string const &s);

    static std::u32string to_utf32(std::u32string const &s);

    static std::u32string to_utf32(std::string const &s);

    static std::u32string to_utf32(std::wstring const &s);

    static std::u32string read_with_bom(std::istream &&src);

    static inline std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> char16_t_conv{};
    static inline std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> char32_t_conv{};
    static inline std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> wchar_conv{};

};

#endif //MINOS_UTF_H
