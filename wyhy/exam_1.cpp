#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long maxi_p = -9999999999, mini_p = 9999999999;
    long long maxi_w = -9999999999, mini_w = 9999999999;

    int k = 0;
    for (int i = 0; i < n; ++i){
        scanf("%d", &k);
        if (k > maxi_p)
            maxi_p = k;
        if (k < mini_p)
            mini_p = k;
    }
    for (int i = 0; i < n; ++i){
        scanf("%d", &k);
        if (k > maxi_w)
            maxi_w = k;
        if (k < mini_w)
            mini_w = k;
    }
    long long m, ans;
    cin >> m;
    if (maxi_p < mini_w){
        ans = 0;
    }else
    if (mini_p > maxi_w){
        ans = 1;
        for (int i = 2; i <= n; ++i){
            ans *= i;
            ans %= m;
        }
    }else
        ans = 1;
    cout << ans % m << endl;
    return 0;
}