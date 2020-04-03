#include <bits/stdc++.h>
using namespace std;

int output_direction(int input_direction, int grid_type){
    if (input_direction == 1){
        if (grid_type == 2)
            return 2;
        else if (grid_type == 3)
            return 3;        
        else if (grid_type == 4)
            return 4;
    }else if (input_direction == 2){
        if (grid_type == 2)
            return 1;
        else if (grid_type == 5)
            return 3;        
        else if (grid_type == 6)
            return 4;
    }else if (input_direction == 3){
        if (grid_type == 1)
            return 4;
        else if (grid_type == 3)
            return 1;        
        else if (grid_type == 5)
            return 2;
    }else{
        if (grid_type == 1)
            return 3;
        else if (grid_type == 4)
            return 1;        
        else if (grid_type == 6)
            return 2;
    }
    return 0;
}

bool hasValidPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    bool visited[m][n];
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j)
            visited[i][j] = false;
    }

    //direction  south = 1, north = 2, west = 3, east = 4;
    int now_m = 0, now_n = 0, out_direct;
    bool has_road = false;
    if (m == 1 && n == 1)
        return true;
    if (grid[0][0] == 5)
        return false;
    if (grid[0][0] == 1 || grid[0][0] == 4 || grid[0][0] == 6)
        out_direct = 4;
    else out_direct = 1;

    while (now_m != m - 1 || now_n != n - 1){
        cout << "m:" << now_m << " n:" << now_n << " dir:" << out_direct << endl;
        has_road = false;
        if (visited[now_m][now_n] == true)
            return false;
        visited[now_m][now_n] = true;
        if (out_direct == 1){
            if (now_m + 1 < m){
                int temp[3] = {2, 5, 6};
                for (auto i:temp)
                if (grid[now_m + 1][now_n] == i){
                    now_m += 1;
                    out_direct = output_direction(2, i);
                    has_road = true;
                    break;
                }
            } 
        }else if (out_direct == 2){
            if (now_m >= 1){
                int temp[3] = {2, 3, 4};
                for (auto i:temp)
                if (grid[now_m - 1][now_n] == i){
                    now_m -= 1;
                    out_direct = output_direction(1, i);
                    has_road = true;
                    break;
                }
            } 
        }else if (out_direct == 3){
            if (now_n >= 1){
                int temp[3] = {1, 4, 6};
                for (auto i:temp)
                if (grid[now_m][now_n - 1] == i){
                    now_n -= 1;
                    out_direct = output_direction(4, i);
                    has_road = true;
                    break;
                }
            } 
        }else if (out_direct == 4){
            if (now_n + 1 < n){
                int temp[3] = {1, 3, 5};
                for (auto i:temp)
                if (grid[now_m][now_n + 1] == i){
                    now_n += 1;
                    out_direct = output_direction(3, i);
                    has_road = true;
                    break;
                }
            } 
        }
        cout << "road:" << has_road << endl;
        if (has_road == false){
            if (grid[0][0] == 4){
                break;
            }else {
                return false;
            }
        }
    }
    if (now_m == m - 1 && now_n == n - 1)
        return true;
    else if (grid[0][0] == 4){
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
                visited[i][j] = false;
            }
        int now_m = 0, now_n = 0, out_direct = 1;
        bool has_road = false;

        while (now_m != m - 1 || now_n != n - 1){
            cout << "m:" << now_m << " n:" << now_n << " dir:" << out_direct << endl;
            has_road = false;
            if (visited[now_m][now_n] == true)
                return false;
            visited[now_m][now_n] = true;
            if (out_direct == 1){
                if (now_m + 1 < m){
                    int temp[3] = {2, 5, 6};
                    for (auto i:temp)
                    if (grid[now_m + 1][now_n] == i){
                        now_m += 1;
                        out_direct = output_direction(2, i);
                        has_road = true;
                        break;
                    }
                } 
            }else if (out_direct == 2){
                if (now_m >= 1){
                    int temp[3] = {2, 3, 4};
                    for (auto i:temp)
                    if (grid[now_m - 1][now_n] == i){
                        now_m -= 1;
                        out_direct = output_direction(1, i);
                        has_road = true;
                        break;
                    }
                } 
            }else if (out_direct == 3){
                if (now_n >= 1){
                    int temp[3] = {1, 4, 6};
                    for (auto i:temp)
                    if (grid[now_m][now_n - 1] == i){
                        now_n -= 1;
                        out_direct = output_direction(4, i);
                        has_road = true;
                        break;
                    }
                } 
            }else if (out_direct == 4){
                if (now_n + 1 < n){
                    int temp[3] = {1, 3, 5};
                    for (auto i:temp)
                    if (grid[now_m][now_n + 1] == i){
                        now_n += 1;
                        out_direct = output_direction(3, i);
                        has_road = true;
                        break;
                    }
                } 
            }
            cout << "road:" << has_road << endl;
            if (has_road == false)
                return false;
        }
    }
    return true;
}

int main(){
    int temp[2][3] = {{4, 1}, {6, 1}};
    std::vector<vector<int>> a(2);
    for (int i = 0; i < a.size(); i++){
        a[i].resize(2);
    }

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[0].size(); j++){
            a[i][j] = temp[i][j];
        }
    }
    cout << hasValidPath(a);    
    return 0;
}