#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, M;
char arr[1000][1001];

bool subCheck(int i, int j) {
    char cur = arr[i][j]; int len = 0;
    
    int idx = j;
    while(idx < M) {
        idx++; len++;
        if(idx >= M || arr[i][idx] != cur) break;
    }
    
    int r = i;
    while(r < N) {
        bool flag = (arr[r][j] == cur);
        for(int c = j; c < j+len; c++) {
            if(flag != (arr[r][c] == cur)) return false;
            
            if(flag) arr[r][c] = '.';
        }
        
        if(flag) {
            if(j-1 >= 0 && arr[r][j-1] == cur) return false;
            if(j+len < M && arr[r][j+len] == cur) return false;
        }
        else { break; }
        
        r++;
    }
    
    return true;
}

bool check() {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            if(arr[i][j] != '.') {
                if(!subCheck(i, j)) return false;
            }
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) { cin >> arr[i]; }
    
    cout << (check() ? "dd" : "BaboBabo");

    return 0;
}