#include <bits/stdc++.h>
#include <climits>
#include <list>
using namespace std;

class MyStack{
public:
    MyStack(){
        num_head = new _Node_;
        min_head = new _Node_;
        min_head->v = INT_MAX;
        num_head->root = true;
        min_head->root = true;
    }

    void push(int num){
        _Node_* temp = new _Node_;
        temp->next = num_head;
        temp->v = num;
        num_head = temp;
        if (num <= min_head->v){
            _Node_* temp1 = new _Node_;
            temp1->next = min_head;
            temp1->v = num;
            min_head = temp1;
        }
    }

    void pop(){
        if (num_head->root)
            return;
        int v = num_head->v;
        _Node_* temp = num_head->next;
        delete num_head;
        num_head = temp;
        if (v <= min_head->v){
            temp = min_head->next;
            delete min_head;
            min_head = temp;
        }
    }

    int getMin(){
        return min_head->v;
    }

private:
    struct _Node_{
        _Node_* next = nullptr;
        int v = 0;
        bool root = false;
    };
    _Node_* num_head, * min_head;
};

int main(){
    int n;  
    cin >> n;
    string s;
    MyStack stack;
    while (n--){
        cin >> s;
        if (s == "push"){
            int num;
            cin >> num;
            stack.push(num);
        }else if (s == "pop"){
            stack.pop();
        }else if (s == "getMin"){
            cout << stack.getMin() << endl;
        }
    } 
    return 0;
}