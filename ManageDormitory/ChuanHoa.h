#pragma once
#include <string>
#include <iostream>
using namespace std;
bool checkKiTu(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < 65 or (s[i] > 90 and s[i] < 97) or (s[i] > 122))
            return false;
    }
    return true;
}
bool checkSo(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]<48 or s[i]>57)
            return false;
    }
    return true;
}
string chuanHoa(string s)
{
    int length(s.length());
    // xoa khoang trang dau chuoi
    while (s[0] == ' ') {
        for (int i = 0; i < length; i++) {
            s[i] = s[i + 1];
        }
    }
    // xoa khoang trang cuoi chuoi
    while (length > 0 && s[length - 1] == ' ') {
        s[--length] = '\0';
    }
    // Xoa khoang trang thaa giua cac tu
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            for (int j = i; s[j] != '\0'; ++j) {
                s[j] = s[j + 1];
            }
            --i;
        }
    }
    // in hoa tu
    for (int i = 0; i < length; i++)
    {
        if (i == 0 or (s[i - 1] == ' '))
        {
            s[i] = s[i] - 32;
        }
    }
    return s;
}