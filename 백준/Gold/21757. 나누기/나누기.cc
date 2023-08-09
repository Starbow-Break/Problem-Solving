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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int sumA[100001];
    for(int i = 1; i <= N; i++) {
        cin >> sumA[i];
        sumA[i] += sumA[i-1];
    }
    
    if(sumA[N]%4) { cout << 0; return 0; }
    
    vector<int> A1, A2, A3;
    for(int i = 1; i <= N-1; i++) {
        if(sumA[i] == sumA[N]/4) A1.pb(i);
        if(sumA[i] == sumA[N]/2) A2.pb(i);
        if(sumA[i] == sumA[N]*3/4) A3.pb(i);
    }
    
    vector<ll> t; t.pb(0);
    int j = 0;
    for(int i = 0; i < A2.size(); i++) {
        while(j < A3.size() && A2[i] >= A3[j]) j++;
        t.pb(A3.size()-j);
    }
    for(int i = 1; i < t.size(); i++) {
        t[i] += t[i-1];
    }
    
    j = 0; ll ans = 0;
    for(int i = 0; i < A1.size(); i++) {
        while(j < A2.size() && A1[i] >= A2[j]) j++;
        ans += t[t.size()-1]-t[j];
    }
    
    cout << ans;
    
    return 0;
}