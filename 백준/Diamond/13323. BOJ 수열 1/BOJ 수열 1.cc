#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

ll A[1'000'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    priority_queue<ll, vector<ll>, less<ll>> pq; //그래프의 기울기를 관리하기 위한 최대 힙
    ll ans = 0, t = 0; //답, 평행이동 정도
    
    t++; pq.push(A[1]);
    for(int i = 2; i <= N; i++) {
        ll r = pq.top()+t;
        if(A[i] >= r) pq.push(A[i]-t);
        else {
            pq.pop();
            pq.push(A[i]-t);
            pq.push(A[i]-t);
            ans += r-A[i];
        }
        
        t++;
    }
    
    cout << ans;

    return 0;
}