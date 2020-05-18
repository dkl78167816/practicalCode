#include <iostream>
#include <vector>
using namespace std;

bool used[21];

bool search(vector<int>& a, int tot, int n){
    if (tot == n)
        return true;
    for (int i = 0; i < a.size(); ++i){
        if (!used[i] && tot + a[i] <= n){
            used[i] = true;
            return search(a, tot + a[i], n);
            used[i] = false;
        }
    }
    return false;
}
bool pd(vector<int>& a){
    int tot = 0;
    for (auto i:a)
        tot += i;
    int n = 0;
    if (tot % 4 != 0)
        return false;
    else n = tot / 4;
    for (int j = 0; j < a.size(); ++j)
        used[j] = false;
    if (!search(a, 0, n))
        return false;
    if (!search(a, 0, n))
        return false;
    if (!search(a, 0, n))
        return false;
    if (!search(a, 0, n))
        return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        vector<int> tick;
        tick.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i){
            int temp;
            cin >> temp;
            tick.push_back(temp);
        }
        if (pd(tick))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}