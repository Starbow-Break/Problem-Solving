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

const int MOD =- 9'999'991;

//---------------------BST---------------------
int root; // BST의 루트 노드
int leftChild[21], rightChild[21]; // 왼쪽 자식, 오른쪽 자식
//---------------------BST---------------------

ll dp[21], C[21][21];
int sz[21];

void buildCombi() {
    for(int n = 0; n <= 20; n++) {
        for(int m = 0; m <= n; m++) {
            if(m == 0 || n == m) {
                C[n][m] = 1;
            }
            else {
                C[n][m] = (C[n-1][m]+C[n-1][m-1]) % MOD;
            }
        }
    }
}

// 초기화
void init() {
    // BST 초기화
    int root = -1;
    for(int i = 0; i <= 20; i++) {
        leftChild[i] = rightChild[i] = -1;
    }
    
    // dp, sz 배열 초기화
    fill(dp, dp+21, 0); fill(sz, sz+21, 0);
}

// DFS 돌면서 Tree DP
void dfs(int cur) {
    sz[cur] = 1; dp[cur] = 1;
    
    if(leftChild[cur] != -1) {
        dfs(leftChild[cur]);
        sz[cur] += sz[leftChild[cur]];
        dp[cur] *= dp[leftChild[cur]];
        dp[cur] %= MOD;
    }
    
    if(rightChild[cur] != -1) {
        dfs(rightChild[cur]);
        sz[cur] += sz[rightChild[cur]];
        dp[cur] *= dp[rightChild[cur]];
        dp[cur] %= MOD;
    }
    
    if(leftChild[cur] != -1) {
        dp[cur] *= C[sz[cur]-1][sz[leftChild[cur]]];
    }
    dp[cur] %= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    buildCombi();
    
    int T; cin >> T;
    while(T--) {
        // 초기화
        init();
        
        // 수열 입력
        int N; cin >> N;
        vector<int> data(N);
        for(int i = 0; i < N; i++) cin >> data[i];
        
        // BST 구축
        for(auto &v: data) {
            if(root == -1) root = v;
            else {
                int cur = root;
                while(true) {
                    if(v < cur) {
                        if(leftChild[cur] == -1) {
                            leftChild[cur] = v;
                            break;
                        }
                        else {
                            cur = leftChild[cur];
                        }
                    }
                    else {
                        if(rightChild[cur] == -1) {
                            rightChild[cur] = v;
                            break;
                        }
                        else {
                            cur = rightChild[cur];
                        }
                    }
                }
            }
        }
        
        // Tree DP
        dfs(root);
        
        cout << dp[root] << '\n';
    }
    
    return 0;
}