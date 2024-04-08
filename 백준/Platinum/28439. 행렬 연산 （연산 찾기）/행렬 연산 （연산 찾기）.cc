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

struct query {
    int com, idx, v;
};

int N, M;
int A[500'000];
int cnt[6'000'001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N*M; i++) cin >> A[i];
    
    vector<ll> row(N), col(M);
    
    for(int i = 1; i < N; i++) {
        row[i] = A[i*M] - A[0];
    }
    
    for(int j = 0; j < M; j++) {
        bool check = true;
        
        for(int i = 1; i < N && check; i++) {
            if(A[i*M+j]-row[i] != A[(i-1)*M+j]-row[i-1]) {
                check = false;
            }
        }
        
        if(!check) {
            cout << -1;
            return 0;
        }
        
        col[j] = A[j]-row[0];
    }
    
    for(int i = 0; i < N; i++) {
        cnt[3'000'000-row[i]]++;
    }
    for(int i = 0; i < M; i++) {
        cnt[3'000'000+col[i]]++;
    }
    
    int delta = 0;
    for(int i = -3'000'000; i <= 3'000'000; i++) {
        if(cnt[3'000'000+delta] < cnt[3'000'000+i]) {
            delta = i;
        }
    }
    
    vector<query> queries;
    for(int i = 0; i < N; i++) {
        if(row[i]+delta != 0) {
            queries.pb({1, i+1, row[i]+delta});
        }
    }
    
    for(int i = 0; i < M; i++) {
        if(col[i]-delta != 0) {
            queries.pb({2, i+1, col[i]-delta});
        }
    }
    
    cout << queries.size() << '\n';
    for(auto &q: queries) {
        cout << q.com << ' ' << q.idx << ' ' << q.v << '\n';
    }
    
    return 0;
}