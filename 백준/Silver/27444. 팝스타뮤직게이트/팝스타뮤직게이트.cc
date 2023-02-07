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
#define MAX_N 288'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int TICK = 6;

int B, X, N;
int screen[MAX_N][9];

int getScore(int line) {
    int ret = 0;
    
    int idx = N-1;
    while(idx >= 0) {
        if(screen[idx][line] == 0) break;
        idx--;
    }
    
    if(idx < N-1) {
        if(screen[idx+1][line] == 1) {
            if(screen[N-1][line] == 2)
                ret += 80+(N-1-idx)*X/TICK;
            else
                ret += 100*(N-1-idx);
        }
        else
            ret += (N-1-idx)*X/TICK+((screen[N-1][line] == 2 && idx+1 < N-1) ? 80 : 0);
    }
    
    bool isLong = false; int len = 0;
    while(idx >= 0) {
        if(screen[idx][line] == 1) {
            if(isLong) len += X;
            else ret += 100;
        }
        
        if(screen[idx][line] == 2) {
            if(isLong) {
                len += X;
                ret += len/TICK;
                len = 0; isLong = false;
            }
            else {
                ret += 80;
                isLong = true; len += X;
            }
        }
        
        idx--;
    }
    
    if(isLong) ret += len/TICK;
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> B >> X >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 9; j++) cin >> screen[i][j];
    }
    
    int ans = 0;
    for(int l = 0; l < 9; l++) {
        ans += getScore(l);
    }
    
    cout << ans;

    return 0;
}