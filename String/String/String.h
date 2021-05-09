//
// Created by 晚风吹行舟 on 2021/5/5.
//

#ifndef DATASTRUCTURE_STRING_H
#define DATASTRUCTURE_STRING_H

#include <cstring>  // strcpy
#include <istream>
#include <ostream>
#include <iostream>

using std::istream;
using std::ostream;

/**
 * 参考STL中std::string简单实现了字符串类的部分函数
 */
class String {
private:
    // std::string中capacity初始化为15B，每次递增16B，此处简化为以15B为一个块来线性增长
    static const size_t _block = 15;
    // 字符串指针
    char *p_str;
    // 字符串的长度
    size_t _size;
    // 已动态分配内存的大小（B）
    size_t _capacity;

private:
    /**
     * 字符串拼接操作
     * @param str 要拼接的字符串
     */
    void append(const char *str);

public:

    /**
     * 构造函数 explicit 禁止隐式的转换
     * @param str 初始化String对象
     */
    explicit String(const char *str = "") {
        _size = strlen(str);
        _capacity = (_size / _block + 1) * _block;
        p_str = new char[_capacity];
        strcpy(p_str, str);
    }

    /**
     * 拷贝构造函数 深拷贝
     * @param str
     */
    String(const String &str){
        _size = str.size();
        _capacity = str.capacity();
        p_str = new char[_capacity];
        strcpy(p_str, str.c_str());
        std::cout << "copy constructor is called" << std::endl;
    }

    ~String() {
        delete[] p_str;
        p_str = nullptr;
        _size = _capacity = 0;
    }

    static size_t block() {
        return _block;
    }

    inline size_t capacity() const {
        return _capacity;
    }

    inline size_t size() const {
        return _size;
    }

//    String substr(size_t pos, size_t len);

    inline char &operator[](size_t i) const;

    inline const char *c_str() const;

    String &operator+=(const char *str);

    String &operator+=(const String &str);

    inline bool operator==(const String &str) const;

    friend String operator+(const String &s1, const String &s2);

    friend String operator+(const String &s1, const char *s2);


    /*
     * 此处str使用const限定
     * 对于 str1 = str2 + str3;
     * 右侧表达式计算后返回一个临时变量，临时变量很快就会被销毁
     * C++标准规定非常量引用不能指向临时对象
     * 而且《C++ primer》中也提到：临时变量被const引用绑定后，生命期就将自动延长到与这个引用同长。
     */
    String& operator=(const String &str);

    friend istream &operator>>(istream &is, String &str);

    friend ostream &operator<<(ostream &os, String &str);

};


#endif //DATASTRUCTURE_STRING_H
