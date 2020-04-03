#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <sstream>
#include <string>
using namespace std;

class MyStack{
public:
    MyStack(){}

    void push(int num){
        if (first){
            first = true;
            num_head->v = num;
            min_head->v = num;
        }else{
            _Node_* temp = new _Node_;
            temp->next = num_head;
            temp->v = num;
            num_head = temp;
            if (num < min_head->v){
                _Node_* temp1 = new _Node_;
                temp1->next = min_head;
                temp1->v = num;
                min_head = temp1;
            }
        }
    }

    void pop(){
        int v = num_head->v;
        num_head = num_head->next;
        if (v == min_head->v){
            min_head = min_head->next;
        }
    }

    int getMin(){
        return min_head->v;
    }

private:
    struct _Node_{
        _Node_* next = NULL;
        int v = 0;
    };
    _Node_* num_head, * min_head;
    bool first = true;
};

int main(){
    int n;  
    cin >> n;
    string s;
    MyStack stack;
    while (n--){
        cin >> s;
        char c;
        int num = 0;
        while (scanf("%c", &c) && c!='\n'){
            if (c != ' '){
                num *= 10;
                num += c - '0';
            }
        }
        if (s.substr(0, 4) == "push"){
            stack.push(num);
        }else if (s.substr(0, 3) == "pop"){
            stack.pop();
        }else if (s.substr(0, 6) == "getMin"){
            cout << stack.getMin() << endl;
        }
    } 
    return 0;
}