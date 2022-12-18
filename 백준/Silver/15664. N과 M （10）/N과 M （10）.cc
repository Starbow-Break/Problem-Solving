#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <list>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int A[8];
vector<vector<int>> ans;

vector<int> temp;
void solve(int N, int M, int start = 0, int step = 0) {
    if(step == M) {
        ans.push_back(temp);
        return;
    }
    
    for(int i = start; i < N; i++) {
        if(i != start && A[i-1] == A[i]) continue;
        
        temp.push_back(A[i]);
        solve(N, M, i+1, step+1);
        temp.erase(temp.end()-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) { cin >> A[i]; }
    sort(A, A+N);
    solve(N, M);
    for(auto &a: ans) {
        for(auto &v: a) {
            cout << v << " "; 
        }
        cout << '\n';
    }

    return 0;
}