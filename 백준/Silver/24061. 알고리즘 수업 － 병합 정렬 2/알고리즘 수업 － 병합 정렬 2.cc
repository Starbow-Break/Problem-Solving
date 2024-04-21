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

int A[500'001];
int remain, sz;

void merge(int l, int mid, int r) {
    int i = l, j = mid+1;
    int temp[r-l+1], idx = 0;
    while(i <= mid && j <= r) {
        if(A[i] <= A[j]) {
            temp[idx++] = A[i++];
        }
        else {
            temp[idx++] = A[j++];
        }
    }
    
    while(i <= mid) {
        temp[idx++] = A[i++];
    }
    
    while(j <= r) {
        temp[idx++] = A[j++];
    }
    
    for(int k = 0; k < r-l+1; k++) {
        remain--;
        A[l+k] = temp[k];
        
        if(remain == 0) {
            for(int i = 1; i <= sz; i++) {
                cout << A[i] << ' ';
            }
        }
    }
}

void mergeSort(int l, int r) {
    if(l == r) {
        return;
    }
    
    int mid = (l+r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    merge(l, mid, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    sz = N; remain = K;
    
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    mergeSort(1, N);
    
    if(remain > 0) cout << -1;
    
    return 0;
}