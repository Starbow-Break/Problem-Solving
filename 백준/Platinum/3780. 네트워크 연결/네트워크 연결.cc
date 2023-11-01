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

int parent[20001];
int length[20001];

void init(int N) {
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        length[i] = 0;
    }
}

pii findCenter(int v) {
    if(v == parent[v]) return {v, 0};
    pii ret = findCenter(parent[v]);
    parent[v] = ret.fi;
    length[v] += ret.se;
    return {parent[v], length[v]};
}

// 센터와 i 까지의 거리
int getDistance(int i) {
    int center = findCenter(i).fi;
    return length[i];
}

//센터 c를 기업 i에 연결
void connect(int c, int i) {
    int _c = findCenter(i).fi; //기업 i가 속한 클러스터의 센터
    parent[c] = _c;
    length[c] = abs(c-i)%1000+length[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        init(N);
        
        while(true) {
            char c; cin >> c;
            if(c == 'O') break;
            
            if(c == 'E') {
                int i; cin >> i;
                cout << getDistance(i) << '\n';
            }
            else {
                int i, j; cin >> i >> j;
                connect(i, j);
            }
            
            // for(int i = 1; i <= N; i++) cout << parent[i] << ' ';
            // cout << '\n';
            // for(int i = 1; i <= N; i++) cout << length[i] << ' ';
            // cout << '\n';
        }
    }
    
    return 0;
}
