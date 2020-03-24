#include <bits/stdc++.h>

//also can be done by merge sort
std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
    std::vector<int> ans;
    int k = 0;
    for (int i = 0; i < nums.size(); i++){
        ans.insert(ans.begin() + index[i], nums[i]);
    }
    return ans;
}

int main(){
    int tempa[5] = {4, 2, 4, 3, 2};
    int tempb[5] = {0, 0, 1, 3, 1};

    std::vector<int> a(5), b(5);
    for (int i = 0; i < 5; i++){
        a[i] = tempa[i];
        b[i] = tempb[i];
    }

    std::vector<int> result = createTargetArray(a, b);
    for (auto i:result)
        std::cout << i << ' ';
        
    return 0;
}