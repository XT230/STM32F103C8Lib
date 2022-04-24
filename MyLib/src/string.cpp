#include "string.h"

/**
 * @brief Construct a new String:: String object
 * 
 * @param str 填入的字符串, 默认为空
 */
String::String(const char *str)
{
    lens = 0;
    if(str != nullptr)
    {
        this->lens = strlens(str);
        this->str = new char[lens + 1];
        strcpy(this->str, str, lens);
    }
    else 
    {
        this->str = nullptr;
    }
}

/**
 * @brief 拷贝构造函数
 * 
 * @param str 
 */
String::String(const String &str)
{
    lens = str.lens;
    this->str = new char[lens + 1];
    strcpy(this->str, str.str, lens);
}

/**
 * @brief 类型转换
 * 
 * @param c 
 */
String::String(const char c)
{
    lens = 1;
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
}

/**
 * @brief Destroy the String:: String object
 * 
 */
String::~String()
{
    delete[] str;
}

/**
 * @brief 返回字符串的长度
 * 
 * @return size_t 
 */
size_t String::length() const
{
    return lens;
}

/**
 * @brief 清空字符串
 * 
 */
void String::clear()
{
    delete[] str;
    str = nullptr;
    lens = 0;
}

/**
 * @brief 判断是否以某一字符串开头
 * 
 * @param prefix 需要进行比对的字符串
 * @return bool  
 */
bool String::startsWith(const char *prefix) const
{
    size_t len = strlens(prefix);
    if(len > lens)return false;
    if(strcmp(str, prefix, len) == 0)return true;
    else return false;
}

/**
 * @brief 判断是否以某一字符串结尾
 * 
 * @param suffix 需要进行比对的字符串
 * @return bool  
 */
bool String::endsWith(const char *suffix) const
{
    size_t len = strlens(suffix);
    if(len > lens)return false;
    if(strcmp(&str[lens - len], suffix, len) == 0)return true;
    else return false;
}

/**
 * @brief 索引
 * 
 * @param index 
 * @return char& 
 */
char& String::operator[](const size_t index)
{
    if(index >= lens)return str[lens - 1];
    else return str[index];
}

/**
 * @brief 
 * 
 * @param s 
 * @return String& 
 */
String& String::operator=(const String &s)
{
    lens = s.lens;
    str = new char[lens + 1];
    strcpy(str, s.str, lens);
    return *this;
}

/**
 * @brief 拼接字符串
 * 
 * @param s 需要拼接的字符串
 * @return String& 拼接后字符串的引用
 */
String& String::operator+=(const String &s)
{
    char *buf;
    buf = new char[lens + s.lens + 1];
    if(lens > 0)strcpy(buf, str, lens);
    strcpy(&buf[lens], s.str, s.lens);
    str = buf;
    lens += s.lens;
    return *this;
}

/**
 * @brief 拼接字符串
 * 
 * @param s1 
 * @param s2 
 * @return String 拼接后的字符串
 */
String operator+(const String s1, const String s2)
{
    String s(s1);
    s += s2;
    // std::cout<<s.c_str();
    return s;
}

/**
 * @brief 测量字符串长度
 * 
 * @param str 
 * @return size_t 字符串长度
 */
size_t strlens(const char *str)
{
    size_t lens = 0;
    while(*str != '\0')
    {
        lens++;
        str++;
    }
    return lens;
}

/**
 * @brief 字符串复制
 * 
 * @param str 目的字符串
 * @param source 源字符串
 */
void strcpy(char *str, const char *source, size_t lens)
{
    if(lens == 0)lens = strlens(source);
    for(int i = 0; i < lens; i++)
    {
        str[i] = source[i];
    }
    str[lens] = '\0';
}

/**
 * @brief 字符串拼接
 * 
 * @param str1 
 * @param str2 
 */
void strcat(char *str1, const char *str2, size_t lens)
{
    size_t lens1 = strlens(str1);
    strcpy(&str1[lens1], str2, lens);
}

int8_t strcmp(const char *s1, const char *s2, size_t lens)
{
    size_t len1 = 0, len2 = 0;
    if(lens == 0)
    {
        len1 = strlens(s1);
        len2 = strlens(s2);
        lens = len1 < len2 ? len1 : len2;
    }
    for(int i = 0; i < lens; i++)
    {
        if(s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
    }
    return len1 - len2;
}