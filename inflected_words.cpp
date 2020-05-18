#include <bits/stdc++.h>

int main(){
    int n, m;
    std::cin >> n >> m;
    if (n != m){
        std::cout << "false" << std::endl;
        return 0;
    }
    std::string s1, s2;
    std::vector<int> count1(130, 0), count2(130, 0);
    std::cin >> s1 >> s2;
    for (auto i = 0; i < n; ++i){
        count1[int(s1[i])] ++;
    }
    for (auto i = 0; i < m; ++i){
        count2[int(s2[i])] ++;
    }
    int ans = 0;
    for (auto i = 0; i < 130; ++i){
        if (count1[i] != count2[i]){
            std::cout << "false" << std::endl;
            return 0;
        }
    }
    std::cout << "true" << std::endl;
    return 0;
}