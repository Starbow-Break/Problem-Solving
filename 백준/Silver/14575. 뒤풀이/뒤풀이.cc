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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int L[1000], R[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, T; cin >> N >> T;
    for(int i = 0; i < N; i++) cin >> L[i] >> R[i];
    
    int s = 0;
    for(int i = 0; i < N; i++) s += L[i];
    if(s > T) { cout << -1; return 0; }
    s = 0;
    for(int i = 0; i < N; i++) s += R[i];
    if(s < T) { cout << -1; return 0; }
    
    
    int i = 1, j = 1'000'000'000;
    while(i <= j) {
        int mid = (i+j)>>1;
        int cnt = 0; bool flag = true;
        for(int k = 0; k < N && flag; k++) {
            if(mid < L[k]) flag = false;
            cnt += min(R[k], mid);
        }
        
        if(cnt >= T && flag) j = mid-1;
        else i = mid+1;
    }
    
    cout << i;

    return 0;
}