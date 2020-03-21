#include<vector>
#include<string>
#include<iostream>

using namespace std;

vector<int> next_array;
    
void build_next(string p){
    next_array = vector<int>(p.length());
    next_array[0] = -1;
    int k = -1;
    int j = 0;
    int plen = p.length();
    while (j < plen - 1){
        if (k == -1 || p[j] == p[k]){
            k++, j++;
            if (p[j] != p[k])
                next_array[j] = k;
            else 
                next_array[j] = next_array[k];
        }else{
            k = next_array[k];
        }
    }
}

int kmp(string s, string p){
    int i = 0;
    int j = 0;
    int slen = s.length();
    int plen = p.length();
    while (i < slen && j < plen){
        if (j == -1 || s[i] == p[j]){
            i++;
            j++;
        }else{
            j = next_array[j];
        }
    }
    if (j == p.length())
        return i - j;
    return -1;
}

int strStr(string haystack, string needle) {
    build_next(needle);
    return kmp(haystack, needle);
}

void testCase(){
    if (strStr("hello", "ll") != 2)
        cout << "wrong";
    else cout << "right";
    cout << endl; 
}

int main(){
    testCase();
    // for (auto k:next_array)
    //     cout << k << endl;
    return 0;
}