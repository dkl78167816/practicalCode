#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<long long> a;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        long long temp;
        scanf("%lld", &temp);
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    
    long long now = a[0];
    long long cost = 0;
    int reserve = 0;
    for (int i = 1; i < n; ++i){
        if (a[i] == now)
            reserve ++;
        if (a[i] != now && reserve != 0){
            int tempCount = a[i] - now - 1;
            if (tempCount >= reserve){
                cost += ((1 + reserve) * reserve) / 2;
                reserve = 0;
            }
            else {
                cost += ((1 + tempCount) * tempCount) / 2;
                reserve -= tempCount;
                cost += (tempCount + 1) * reserve;
            }
        }
        now = a[i];
    }
    cout << cost << endl;
    return 0;
}