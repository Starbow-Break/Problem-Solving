#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int parent[101];
int cnt[101][26] = {0, };

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a), rb = findRoot(b);
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) parent[i] = i;
    
    for(int i = 1; i <= N; i++) {
        string s; cin >> s;
        for(auto &c: s) {
            cnt[i][c-'a']++;
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            int ri = findRoot(i);
            int rj = findRoot(j);
            
            if(ri == rj) continue;
            
            bool check = true;
            for(int k = 0; k < 26 && check; k++) {
                if(cnt[ri][k] != cnt[rj][k]) check = false;
            }
            
            if(check) merge(i, j);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += findRoot(i) == i;
    }
    
    cout << ans;

    return 0;
}