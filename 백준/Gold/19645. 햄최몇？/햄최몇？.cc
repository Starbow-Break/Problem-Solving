#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) all(vec); vec.unique(erase(al(v)), vec.end());
#define repeat(cnt) for(int i = 0; i < cnt; i++)

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

struct node {
    int x, y, idx;
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.idx > b.idx;
    }
};

vector<int> burger;
int sum = 0;
int dp[5001][5001];

void solve(int N) {
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({0, 0, 0});
    dp[0][0] = 0;
    
    while(!pq.empty()) {
        int x = pq.top().x, y = pq.top().y, idx = pq.top().idx; pq.pop();
        if(dp[x][y] < idx || idx >= N) continue;
        for(int i = idx; i < N; i++) {
            if(dp[x+burger[i]][y] > i+1) {
                dp[x+burger[i]][y] = i+1;
                pq.push({x+burger[i], y, i+1});
            }
            if(dp[x][y+burger[i]] > i+1) {
                dp[x][y+burger[i]] = i+1;
                pq.push({x, y+burger[i], i+1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    repeat(N) {
        int v; cin >> v;
        sum += v;
        burger.push_back(v);
    }
    
    for(int i = 0; i <= 5000; i++)
        fill(dp[i], dp[i]+5001, 51);
    
    solve(N);
    
    int ans = 0;
    for(int x = 0; x <= sum; x++) {
        for(int y = 0; y <= sum-x; y++) {
            if(dp[x][y] <= N && sum-x-y <= x && sum-x-y <= y) {
                ans = max(ans, sum-x-y);
            }
        }
    }
    
    cout << ans;

    return 0;
}