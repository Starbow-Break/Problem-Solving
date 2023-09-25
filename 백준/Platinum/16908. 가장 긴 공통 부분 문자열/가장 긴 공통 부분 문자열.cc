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

const ll MOD = 1'379'342'557'847'047;

ll modPow(int a, int e) {
    int128 ret = 1, w = a;
    while(e > 0) {
        if(e&1) {
            ret *= w;
            ret %= MOD;
        }
        w *= w; w %= MOD;
        e /= 2;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<string> words;
    for(int i = 1; i <= N; i++) {
        string word; cin >> word;
        words.pb(word);
    }
    
    int i = 1, j = 100000;
    while(i <= j) {
        int mid = i+j >> 1;
        bool check = true;
        for(auto &w: words) {
            if(mid > w.length()) {
                check = false;
                break;
            }
        }
        
        set<ll> s;
        if(check) {
            ll cur = 0;
            ll w = modPow(29, mid-1);
            for(int i = 0; i < words[0].length(); i++) {
                if(i <= mid-1) {
                    cur = (cur*29+words[0][i]-'a'+1)%MOD;
                }
                else {
                    cur = (cur+(words[0][i-mid]-'a'+1)*(MOD-w))%MOD;
                    cur = (cur*29+words[0][i]-'a'+1)%MOD;
                }
                
                if(i >= mid-1) {
                    s.insert(cur);
                }
            }
            
            for(int k = 1; k < N; k++) {
                set<ll> temp;
                cur = 0;
                for(int i = 0; i < words[k].length(); i++) {
                    if(i <= mid-1) {
                        cur = (cur*29+words[k][i]-'a'+1)%MOD;
                    }
                    else {
                        cur = (cur+(words[k][i-mid]-'a'+1)*(MOD-w))%MOD;
                        cur = (cur*29+words[k][i]-'a'+1)%MOD;
                    }
                    
                    if(s.find(cur) != s.end()) temp.insert(cur);
                }
                
                s = temp;
            }
            
            if(!s.empty()) i = mid+1;
            else j = mid-1;
        }
        else {
            j = mid-1;
        }
    }
    
    cout << j;
    
    return 0;
}
