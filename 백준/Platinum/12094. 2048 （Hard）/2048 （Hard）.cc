#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int N;
int arr[20][20];
int pow2[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

queue<int> q;
int left(int maxValue) {
    int ret = 0;
    for(int i = 0; i < N; i++) {
        int cursor = 0; 
        for(int j = 0; j < N; j++) {
            if(arr[i][j] != 0) {
                q.push(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            
            if(arr[i][cursor] == 0) {
                arr[i][cursor] = cur;
            }
            else if(arr[i][cursor] == cur) {
                if(cur == maxValue) ret = max(ret, 2);
                else ret = max(ret, 1);
                
                arr[i][cursor] *= 2;
                cursor++;
            }
            else {
                cursor++;
                arr[i][cursor] = cur;
            }
        }
    }
    
    return ret;
}
int right(int maxValue) {
    int ret = 0;
    for(int i = 0; i < N; i++) {
        int cursor = N-1;
        for(int j = N-1; j >= 0; j--) {
            if(arr[i][j] != 0) {
                q.push(arr[i][j]);
                arr[i][j] = 0;
            }
        }
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            
            if(arr[i][cursor] == 0) {
                arr[i][cursor] = cur;
            }
            else if(arr[i][cursor] == cur) {
                if(cur == maxValue) ret = max(ret, 2);
                else ret = max(ret, 1);
                
                arr[i][cursor] *= 2;
                cursor--;
            }
            else {
                cursor--;
                arr[i][cursor] = cur;
            }
        }
    }
    
    return ret;
}
int up(int maxValue) {
    int ret = 0;
    for(int i = 0; i < N; i++) {
        int cursor = 0;
        for(int j = 0; j < N; j++) {
            if(arr[j][i] != 0) {
                q.push(arr[j][i]);
                arr[j][i] = 0;
            }
        }
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            
            if(arr[cursor][i] == 0) {
                arr[cursor][i] = cur;
            }
            else if(arr[cursor][i] == cur) {
                if(cur == maxValue) ret = max(ret, 2);
                else ret = max(ret, 1);
                
                arr[cursor][i] *= 2;
                cursor++;
            }
            else {
                cursor++;
                arr[cursor][i] = cur;
            }
        }
    }
    
    return ret;
}
int down(int maxValue) {
    int ret = 0;
    for(int i = 0; i < N; i++) {
        int cursor = N-1;
        for(int j = N-1; j >= 0; j--) {
            if(arr[j][i] != 0) {
                q.push(arr[j][i]);
                arr[j][i] = 0;
            }
        }
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            
            if(arr[cursor][i] == 0) {
                arr[cursor][i] = cur;
            }
            else if(arr[cursor][i] == cur) {
                if(cur == maxValue) ret = max(ret, 2);
                else ret = max(ret, 1);
                
                arr[cursor][i] *= 2;
                cursor--;
            }
            else {
                cursor--;
                arr[cursor][i] = cur;
            }
        }
    }
    
    return ret;
}

int ans = 0;

void solve(int step, int flag, int maxValue) {
    ans = max(maxValue, ans);
    if(maxValue*pow2[10-step] <= ans) return;
    
    int temp[20][20];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            temp[i][j] = arr[i][j];
        }
    }
    
    for(int i = 0; i < 4; i++) {
        if(flag & 1<<i) continue;

        int newFlag = 0;
        int check;
        switch(i) {
            case 0:
                check = left(maxValue);
                break;
            case 1:
                check = up(maxValue);
                break;
            case 2:
                check = right(maxValue);
                break;
            case 3:
                check = down(maxValue);
        }
        
        if(!check) {
            if(i == 0 || i == 2) {
                newFlag |= 1 << 2;
                newFlag |= 1 << 0;
            }
            if(i == 1 || i == 3) {
                newFlag |= 1 << 3;
                newFlag |= 1 << 1;
            }
        }
        
        bool _check = false;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(temp[i][j] != arr[i][j]) {
                    _check = true;
                    break;
                }
            }
        }
        
        if(_check) {
            solve(step+1, newFlag, maxValue*max(check, 1));
            for(int a = 0; a < N; a++) {
                for(int b = 0; b < N; b++) {
                    arr[a][b] = temp[a][b];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int maxV = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            maxV = max(arr[i][j], maxV);
        }
    }
    
    solve(0, 0, maxV);
    cout << ans;
    
    return 0;
}
