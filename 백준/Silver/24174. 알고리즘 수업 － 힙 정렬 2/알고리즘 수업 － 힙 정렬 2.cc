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
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int N, K;
vector<int> A;

void heapify(int k, int n) {
    int smaller;
    if(2*k+1 <= n) {
        if(A[2*k] < A[2*k+1]) smaller = 2*k;
        else smaller = 2*k+1;
    }
    else if(2*k <= n) smaller = 2*k;
    else return;
    
    if(A[smaller] < A[k]) {
        swap(A[k], A[smaller]); K--;
        if(K == 0) {
            for(int i = 1; i <= N; i++) cout << A[i] << ' ';
        }
        heapify(smaller, n);
    }
}

void build_min_heap() {
    for(int i = N/2; i >= 1; i--) {
        heapify(i, N);
    }
}

void heap_sort() {
    build_min_heap();
    for(int i = N; i >= 2; i--) {
        swap(A[1], A[i]); K--;
        if(K == 0) {
            for(int i = 1; i <= N; i++) cout << A[i] << ' ';
        }
        heapify(1, i-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    A.pb(0);
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        A.pb(v);
    }
    
    heap_sort();
    
    if(K > 0) cout << -1;
    
    return 0;
}
