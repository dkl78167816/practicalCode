#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;

void ensure(char a[][10], int b){

}

int main(){
    int n, m;
    cin >> n >> m;
    char players[n][m];
    char temp;
    scanf("%c", &temp);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j)
            scanf("%c", &players[i][j]);
        scanf("%c", &temp);
    }
    int origin_i, origin_j, target_i, target_j;
    char kind;
    cin >> origin_i >> origin_j >> kind >> target_i >> target_j;
    while (!(origin_i == 0 && origin_j == 0 && target_i == 0 && target_j == 0 && kind == 'N')){
        cin >> origin_i >> origin_j >> kind >> target_i >> target_j;  
    }
    char ans[m][n];
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j)
            ans[i][j] = players[j][i];
    }

    for (int j = 0; j < n; ++j)
        ensure(ans, j)
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}