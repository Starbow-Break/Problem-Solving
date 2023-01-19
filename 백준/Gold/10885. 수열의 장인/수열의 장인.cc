#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<int> arr;

ll modpow(int a, int e) {
    if(e < 0) return 0;
    
    ll ret = 1; ll w = a;
    while(e > 0) {
        if(e%2) {
            ret *= w;
            ret %= MOD;
        }
        
        w *= w; w %= MOD;
        e /= 2;
    }
    
    return ret;
}

ll solve() {
    int maxCnt = 0; int cnt = 0;
    int brr[2] = {0, }; int idx = 0; int _cnt = 0; int mCnt = 0;
    int __cnt = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(abs(arr[i]) == 2) {
            cnt++; _cnt++; 
            if(arr[i] > 0) __cnt++;
        }
        
        if(arr[i] < 0) {
            mCnt++;
            if(idx == 0) {brr[0] = _cnt; idx = 1;}
            maxCnt = max(maxCnt, __cnt);
            _cnt = (arr[i] == -2); __cnt = 0;
        }
        else if(arr[i] == 0) {
            brr[1] = _cnt;
            
            if(mCnt%2) {
                maxCnt = max(maxCnt, cnt-brr[0]);
                maxCnt = max(maxCnt, cnt-brr[1]);
            }
            else {
                maxCnt = max(maxCnt, cnt);
            }
            
            idx = 0; cnt = 0; _cnt = 0; __cnt = 0; mCnt = 0;
        }
    }
    
    return modpow(2, maxCnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        arr.clear();
        
        int N; cin >> N;
        for(int i = 0; i < N; i++) {
            int v; cin >> v;
            arr.push_back(v);
        }
        arr.push_back(0);
        
        bool check = false; int t = -2; int cnt = 0;
        for(int i = 0; i < N && !check; i++) {
            t = max(t, arr[i]);
            
            if(arr[i] > 0) check = true;
            else if(arr[i] < 0) {
                cnt++;
                if(cnt >= 2) check = true;
            }
            else {
                cnt = 0;
            }
        }
        
        if(check) cout << solve() << '\n';
        else cout << t << '\n';
    }
    
    return 0;
}