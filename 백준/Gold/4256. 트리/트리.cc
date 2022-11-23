#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int preOrder[1001], inOrder[1001];
vector<int> ans;

void solve(int l, int r) {
    if(l > r) return;
    
    int root = preOrder[l];
    
    int t = l+1;
    while(t <= r && inOrder[preOrder[t]] < inOrder[root]) { t++; }
    solve(l+1, t-1);
    solve(t, r);
    ans.push_back(root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        ans.clear();
        
        int N; cin >> N;
        int v;
        for(int i = 1; i <= N; i++) { cin >> v; preOrder[i] = v; }
        for(int i = 1; i <= N; i++) { cin >> v; inOrder[v] = i; }
        
        solve(1, N);
        
        for(auto &a: ans) { cout << a << " "; }
        cout << '\n';
    }

    return 0;
}