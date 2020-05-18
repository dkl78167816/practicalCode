#include <cctype>
#include<string>
#include<iostream>
using namespace std;

// 迭代器，auto，string
int main(){
    string s("hello, the world");
    // for (auto &i:s)
    //     i = 'X';
    // for (char& i:s)
    //     i = 'X';

    // for (decltype(s.size()) i = 0; i < s.size(); i++)
    //     s[i] = 'X';
    // cout << s << endl;
    for (auto i = s.begin() + 1; i != s.end(); ++i){
        if (*(i - 1) == ' ')
            *i = toupper(*i);
    }
    cout << s << endl;
    return 0;
}