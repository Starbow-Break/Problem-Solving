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

int N, M;
int arr[1000][1000];
bool visited[1000][1000] = {false, };

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.fi < b.fi;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cin >> arr[r][c];
    }
    
    priority_queue<pii, vector<pii>, cmp> pq;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(r == 0 || r == N-1 || c == 0 || c == M-1) {
                pq.push({arr[r][c], r*M+c});
                visited[r][c] = true;
            }
        }
    }
    
    int K; cin >> K;
    while(K--) {
        int pos = pq.top().se;
        pq.pop();
        cout << pos/M+1 << ' ' << pos%M+1 << '\n';
        for(int i = 0; i < 4; i++) {
            int nr = pos/M+dr[i];
            int nc = pos%M+dc[i];
            
            if(0 <= nr && nr < N && 0 <= nc && nc < M) {
                if(!visited[nr][nc]) {
                    pq.push({arr[nr][nc], nr*M+nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
    
    return 0;
}
