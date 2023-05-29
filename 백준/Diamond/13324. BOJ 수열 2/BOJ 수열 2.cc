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

ll A[1'000'001], B[1'000'001], arr[1'000'001];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    priority_queue<ll, vector<ll>, less<ll>> pq; //그래프의 기울기를 관리하기 위한 최대 힙
    ll ans = 0, t = 0; //답, 평행이동 정도
    
    pq.push(A[1]); arr[1] = pq.top()+t;
    t++; 
    for(int i = 2; i <= N; i++) {
        ll r = pq.top()+t;
        pq.push(A[i]-t); arr[i] = pq.top()+t;
        if(A[i] < r) {
            pq.pop();
            pq.push(A[i]-t);
            ans += r-A[i];
        }
        
        t++;
    }
    
    B[N] = arr[N];
    for(int i = N-1; i >= 1; i--) {
        B[i] = min(arr[i], B[i+1]-1);
        t--;
    }
    
    for(int i = 1; i <= N; i++) cout << B[i] << '\n';

    return 0;
}