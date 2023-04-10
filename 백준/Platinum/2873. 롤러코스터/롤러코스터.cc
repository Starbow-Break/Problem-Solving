#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int arr[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int R, C; cin >> R >> C;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) cin >> arr[r][c];
    }
    
    string ans = "";
    if(R%2) {
        int r = 0, c = 0;
        while(r != R-1 || c != C-1) {
            if(r%2) {
                if(c == 0) { ans += 'D'; r++; }
                else { ans += 'L'; c--; }
            }
            else {
                if(c == C-1) { ans += 'D'; r++; }
                else { ans += 'R'; c++; }
            }
        }
    }
    else if(C%2) {
        int r = 0, c = 0;
        while(r != R-1 || c != C-1) {
            if(c%2) {
                if(r == 0) { ans += 'R'; c++; }
                else { ans += 'U'; r--; }
            }
            else {
                if(r == R-1) { ans += 'R'; c++; }
                else { ans += 'D'; r++; }
            }
        }
    }
    else {
        pii p = {0, 1};
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
                if(r%2 ^ c%2) {
                    if(arr[r][c] < arr[p.first][p.second]) {
                        p = {r, c};
                    }
                }
            }
        }
        
        int r = 0, c = 0;
        while(r != R-1 || c != C-1) {
            if(r/2 == p.first/2) {
                if(r == p.first/2*2+1 && c == C-1) {
                    if(r != R-1) { ans += 'D'; r++; }
                    continue;
                }
                
                if(c%2) {
                    if(c == p.second) { ans += 'R'; c++; }
                    else {
                        if(c < p.second) {
                            if(r == p.first/2*2) { ans += 'R'; c++; }
                            else { ans += 'U'; r--; }
                        }
                        else {
                            if(r == p.first/2*2+1) { ans += 'R'; c++; }
                            else { ans += 'D'; r++; }
                        }
                    }
                }
                else {
                    if(c == p.second) { ans += 'R'; c++; }
                    else {
                        if(c < p.second) {
                            if(r == p.first/2*2+1) { ans += 'R'; c++; }
                            else { ans += 'D'; r++; }
                        }
                        else {
                            if(r == p.first/2*2) { ans += 'R'; c++; }
                            else { ans += 'U'; r--; }
                        }
                    }
                }
            }
            else {
                if(r/2 < p.first/2) {
                    if(r%2) {
                        if(c == 0) { ans += 'D'; r++; }
                        else { ans += 'L'; c--; }
                    }
                    else {
                        if(c == C-1) { ans += 'D'; r++; }
                        else { ans += 'R'; c++; }
                    }
                }
                else {
                    if(!(r%2)) {
                        if(c == 0) { ans += 'D'; r++; }
                        else { ans += 'L'; c--; }
                    }
                    else {
                        if(c == C-1) { ans += 'D'; r++; }
                        else { ans += 'R'; c++; }
                    }
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}