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

struct group {
    vector<int> ele;
    int cyc_start;
};

int N, K, M;
int start[100'001];
int recommend[100'001][30];

int solve(int num, int step) {
    int idx = 0;
    int ret = num;
    while(step > 0) {
        if(step & 1) {
            ret = recommend[ret][idx];
        }
        step /= 2;
        idx++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K >> M;
    for(int i = 1; i <= N; i++) cin >> start[i];
    for(int i = 1; i <= K; i++) cin >> recommend[i][0];
    
    for(int i = 1; i < 30; i++) {
        for(int k = 1; k <= K; k++) {
            recommend[k][i] = recommend[recommend[k][i-1]][i-1];
        }
    }
    
    for(int i = 1; i <= N; i++) {
        cout << solve(start[i], M-1) << ' ';
    }

    
    return 0;
}
