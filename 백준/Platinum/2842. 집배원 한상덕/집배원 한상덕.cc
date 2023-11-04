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

int N;
char arr[50][51];
int height[50][50];
bool check[50][50];
vector<pii> vec;
vector<int> post;

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int parent[2500];

void init(int sz) {
    for(int i = 0; i < sz*sz; i++) parent[i] = i;
    for(int r = 0; r < sz; r++) {
        for(int c = 0; c < sz; c++) {
            check[r][c] = false;
        }
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
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int r = 0; r < N; r++) cin >> arr[r];
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(arr[r][c] == 'P' || arr[r][c] == 'K') {
                post.pb(r*N+c);
            }
            
            cin >> height[r][c];
            vec.pb({height[r][c], r*N+c});
        }
    }
    sort(all(vec));
    
    int ans = 1'000'000;
    for(int i = 0; i < N*N; i++) {
        int j = i, l = 1;
        
        init(N);
        
        while(j < N*N) {
            int curH = vec[j].fi;
            while(j < N*N && vec[j].fi == curH) {
                int r = vec[j].se/N;
                int c = vec[j].se%N;
                check[r][c] = true;
                for(int k = 0; k < 8; k++) {
                    int nr = r+dr[k];
                    int nc = c+dc[k];
                    if(0 <= nr && nr < N && 0 <= nc && nc < N && check[nr][nc]) {
                        merge(r*N+c, nr*N+nc);
                    }
                }
                
                j++;
            }
            
            while(l < post.size()) {
                if(findRoot(post[0]) == findRoot(post[l])) l++;
                else break;
            }
            
            if(l == post.size()) {
                ans = min(ans, curH-vec[i].fi);
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
