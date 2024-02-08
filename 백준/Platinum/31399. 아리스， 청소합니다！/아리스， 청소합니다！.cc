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

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int H, W; //  방의 크기
int parent[1024*1024*4];
int sz[1024*1024*4];
int A[1024][1024], B[1024][1024];
bool clean[1024][1024]; // 방 청소 여부
int r, c, d; // 아리스의 현재 위치

void init() {
    for(int i = 0; i < H*W*4; i++) {
        parent[i] = i; sz[i] = 1;
    }
}

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    
    if(ra == rb) return;
    
    parent[rb] = ra;
    sz[ra] += sz[rb];
}

ll solve() {
    init();
    
    ll ret = 0; int temp = 0;
    while(true) {
        // 방을 벗어나면 작동 중지
        if(r < 0 || r >= H) return ret;
        if(c < 0 || c >= W) return ret;
        
        if(clean[r][c]) {
            int start = (r*W+c)*4+d; // 시작점
            
            stack<int> s; s.push(start);
            bool flag = false;
            while(0 <= r && r < H && 0 <= c && c < W && clean[r][c]) {
                int cur = (r*W+c)*4+d;
                if(flag && cur == start) return ret; // 순환이 감지되면 종료
                int root = findRoot(cur);
                
                // 이전 정보를 활용하여 순간이동
                if(root != cur) {
                    int nr = root/(4*W);
                    int nc = root/4%W;
                    int nd = root%4;
                    r = nr; c = nc; d = nd;
                    temp += sz[root]-1;
                    flag = true;
                    s.push(root);
                }
                else { // 정보가 없으면 한 칸 이동
                    d = (d+B[r][c])%4;
                    r += dr[d], c += dc[d];
                    temp += 1;
                    flag = true;
                    s.push((r*W+c)*4+d);
                }
            }
            
            // 방을 넘어가면 작동 중지
            if(r < 0 || r >= H) return ret;
            if(c < 0 || c >= W) return ret;
            
            while(true) {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                merge(a, b);
                if(s.empty()) break;
                s.push(b);
            }
        }
        else {
            clean[r][c] = true;
            d = (d+A[r][c])%4;
            r += dr[d], c += dc[d];
            ret += temp+1;
            temp = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> H >> W >> r >> c >> d;
    for(int row = 0; row < H; row++) {
        string s; cin >> s;
        for(int col = 0; col < W; col++) {
            A[row][col] = s[col] - '0';
        }
    }
    for(int row = 0; row < H; row++) {
        string s; cin >> s;
        for(int col = 0; col < W; col++) {
            B[row][col] = s[col] - '0';
        }
    }
    
    cout << solve();
    
    return 0;
}