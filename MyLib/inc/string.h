#ifndef _STRING_H_
#define _STRING_H_

#include "stdint.h"

typedef unsigned int size_t;

size_t strlens(const char *str);
void strcpy(char *str, const char *source, size_t lens = 0);
void strcat(char *str1, const char *str2, size_t lens = 0);
int8_t strcmp(const char *s1, const char *s2, size_t lens = 0);

class String
{
private:
    size_t lens;
    char *str;
    
public:
    String(const char *str = nullptr);
    String(const String &str);
    String(const char c);
    ~String();
    size_t length() const;
    char *c_str(){return str;}
    void clear();
    bool startsWith(const char *prefix) const;
    bool endsWith(const char *suffix) const;
    String& operator+=(const String &s);
    friend String operator+(const String s1, const String s2);
    String& operator=(const String &s);
    char& operator[](const size_t index);
};

#endif