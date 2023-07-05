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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<int> A, B;
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        A.push_back(v);
    }
    for(int i = 1; i <= M; i++) {
        int v; cin >> v;
        B.push_back(v);
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    stack<int> s;
    
    for(int i = N-1; i >= 0; i--) {
        if(s.size() == M) break;
        if(A[i] > B[s.size()]) s.push(A[i]);
        else break;
    }
    
    int i = 0; ll ans = 0;
    while(!s.empty()) {
        ans += s.top()-B[i];
        s.pop(); i++;
    }
    cout << ans;

    return 0;
}