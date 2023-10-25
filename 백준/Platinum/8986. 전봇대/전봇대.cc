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

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.fi > b.fi;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    if(N == 1) {
        cout << 0;
        return 0;
    }
    
    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    priority_queue<pii, vector<pii>, cmp> pq;
    
    for(int i = 1; i < N; i++) {
        pq.push({arr[i]/i+(arr[i]%i > 0), i});
    }
    
    int slope = -(N-1)*N/2;
    int x = 0;
    
    while(slope < 0) {
        pii cur = pq.top(); pq.pop();
        x = cur.fi;
        slope += 2*cur.se;
    }
    
    ll case1 = 0; // 0, x, 2x, ....
    ll case2 = 0; // 0, x-1, 2(x-1), .... 
    
    for(int i = 1; i < N; i++) {
        case1 += abs(arr[i]-1LL*i*x);
        case2 += abs(arr[i]-1LL*i*(x-1));
    }
    
    cout << min(case1, case2);
    
    return 0;
}