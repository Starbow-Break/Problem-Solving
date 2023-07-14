#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int parent[4001], offset = 2000;

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
    
    int N, M; cin >> N >> M;
    for(int i = 1; i <= 4001; i++) parent[i] = i;
    
    while(M--) {
        int a, b; cin >> a >> b;
        int ra = findRoot(offset+a), rb = findRoot(offset+b);
        merge(ra, offset-(rb-offset)); merge(rb, offset-(ra-offset));
    }
    
    for(int i = 1; i <= N; i++) {
        if(findRoot(offset+i) == findRoot(offset-i)) {
            cout << 0; return 0;
        }
    }
    
    cout << 1;
    return 0;
}