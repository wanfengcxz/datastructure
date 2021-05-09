//
// Created by 晚风吹行舟 on 2021/5/5.
//

#include "String.h"


inline char &String::operator[](size_t i) const {
    assert(i < _size);
    return p_str[i];
}

String &String::operator+=(const char *str) {
    append(str);
    return *this;
}

String &String::operator+=(const String &str) {
    append(str.c_str());
    return *this;
}

inline const char *String::c_str() const {
    return p_str;
}

inline bool String::operator==(const String &str) const {
    if (_size != str.size()) {
        return false;
    } else {
        return strcmp(p_str, str.c_str()) == 0;
    }
}

istream &operator>>(istream &is, String &str) {
    is >> str.p_str;
    return is;
}

ostream &operator<<(ostream &os, String &str) {
    os << str.p_str;
    return os;
}

String &String::operator=(const String &str) {
    std::cout << "= function is called" << std::endl;
    _size = str.size();
    _capacity = str.capacity();
    if (p_str != nullptr) {
        delete[]p_str;
    }
    p_str = new char[_capacity];
    strcpy(p_str, str.c_str());
    return *this;
}

void String::append(const char *str) {
    size_t size_str = strlen(str);
    // 如果当前分配的内存空间不够放入str
    if (size_str + _size >= _capacity) {
        // 重新计算需要动态分配内存空间的大小（以_block的整数倍来分配）
        _capacity = ((size_str + _size) / _block + 1) * _block;
        // 重新动态分配内存
        char *temp = new char[_capacity];
        // 拷贝
        strcpy(temp, p_str);
        strcpy(temp + _size, str);
        _size = size_str + _size;
    } else {
        // 直接拷贝
        strcpy(p_str + _size, str);
        _size += size_str;
    }
}

String operator+(const String &s1, const String &s2) {
    String temp(s1);
    temp += s2;
    return temp;
}

String operator+(const String &s1, const char *s2) {
    String temp(s1);
    temp += s2;
    return temp;
}

