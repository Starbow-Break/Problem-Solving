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

struct cmp {
    bool operator()(string &a, string &b) {
        return a+b > b+a;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    stack<string> st[20];
    priority_queue<string, vector<string>, cmp> pq;
    
    repeat(N) {
        string s; cin >> s;
        pq.push(s);
    }
    
    string ans = "";
    while(!pq.empty()) {
        string cur = pq.top(); pq.pop();
        ans += cur[0];
        string t = "";
        for(int i = 1; i < cur.length(); i++) t += cur[i];
        if(t != "") {
            pq.push(t);
        }
    }
    
    cout << ans;
    
    return 0;
}