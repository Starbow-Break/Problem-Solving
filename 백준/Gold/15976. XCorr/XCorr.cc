#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M;
vector<ii> A, B;

int find(int idx) {
    int i = 0; int j = M-1;
    
    while(i <= j) {
        int mid = (i+j)>>1;
        if(B[mid].first > idx) {
            j = mid-1;
        }
        else if(B[mid].first < idx) {
            i = mid+1;
        }
        else return mid;
    }
    
    return j;
}

ll solve(int a, int b) {
    ll ret = 0;
    for(auto &p: A) {
        int l = p.first+a;
        int r = p.first+b;
        
        int idxL = find(l-1);
        int idxR = find(r);
        
        int valueL = ((0 <= idxL) ? B[idxL].second : 0);
        int valueR = ((0 <= idxR) ? B[idxR].second : 0);
        
        ret += 1LL*(valueR-valueL)*p.second;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        int idx, v; cin >> idx >> v;
        A.push_back({idx, v});
    }
    
    cin >> M;
    for(int i = 0; i < M; i++) {
        int idx, v; cin >> idx >> v;
        B.push_back({idx, v});
    }
    
    sort(B.begin(), B.end());
    
    for(int i = 1; i < M; i++) {
        B[i].second += B[i-1].second;
    }
    
    int a, b; cin >> a >> b;
    cout << solve(a, b);

    return 0;
}