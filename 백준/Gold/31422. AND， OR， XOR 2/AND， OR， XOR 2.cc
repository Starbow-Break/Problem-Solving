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

const int MOD = 998'244'353;
int weight[30];

int calcAnd(vector<int> &A) {
    int ret = 0;
    int sz = A.size();
    for(int b = 0; b < 30; b++) {
        vector<bool> bit(sz);
        int total = 0;
        for(int i = 0; i < sz; i++) {
            bit[i] = A[i] & (1 << b);
        }
        
        int cnt = 0;
        for(int i = 0; i < sz; i++) {
            if(bit[i]) {
                cnt++;
            }
            else {
                total += 1LL*cnt*(cnt+1)/2%MOD;
                total %= MOD;
                cnt = 0;
            }
        }
        
        total += 1LL*cnt*(cnt+1)/2%MOD;
        total %= MOD;
        
        ret += 1LL*weight[b]*total%MOD;
        ret %= MOD;
    }
    
    return ret;
}

int calcOr(vector<int> &A) {
    int ret = 0;
    int sz = A.size();
    for(int b = 0; b < 30; b++) {
        vector<bool> bit(sz);
        ll total = 1LL*sz*(sz+1)/2;
        for(int i = 0; i < sz; i++) {
            bit[i] = A[i] & (1 << b);
        }
        
        int cnt = 0;
        for(int i = 0; i < sz; i++) {
            if(bit[i]) {
                total -= 1LL*cnt*(cnt+1)/2;
                cnt = 0;
            }
            else {
                cnt++;
            }
        }
        
        total -= 1LL*cnt*(cnt+1)/2;
        total %= MOD;
        
        ret += 1LL*weight[b]*total%MOD;
        ret %= MOD;
    }
    
    return ret;
}

int calcXor(vector<int> &A) {
    int ret = 0;
    int sz = A.size();
    for(int b = 0; b < 30; b++) {
        vector<bool> bit(sz);
        for(int i = 0; i < sz; i++) {
            bit[i] = A[i] & (1 << b);
        }
        
        int cnt[2] = {0, };
        
        int temp = 0;
        for(int i = 0; i < sz; i++) {
            temp += bit[i];
            cnt[temp%2]++;
        }
        
        int total = cnt[1];
        for(int i = 1; i < sz; i++) {
            if(bit[i-1]) {
                cnt[1]--;
                swap(cnt[0], cnt[1]);
            }
            else {
                cnt[0]--;
            }
            
            total += cnt[1];
            total %= MOD;
        }
        
        ret += 1LL*total*weight[b]%MOD;
        ret %= MOD;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    weight[0] = 1;
    for(int i = 1; i < 30; i++) {
        weight[i] = weight[i-1] * 2;
        weight[i] %= MOD;
    }
    
    int N; cin >> N;
    vector<int> A(N);
    
    for(int i = 0; i < N; i++) cin >> A[i];
    
    cout << calcAnd(A) << ' ' << calcOr(A) << ' ' << calcXor(A);
    
    return 0;
}
