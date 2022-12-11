#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int A[9];
vector<vector<int>> permutation;

vector<int> temp;
bool isUsed[9] = {false, };
void getPermutation(int N, int step = 0) {
    if(N == step) { permutation.push_back(temp); return; }
    
    for(int i = 1; i <= N; i++) {
        if(!isUsed[i]) {
            isUsed[i] = true;
            temp.push_back(i);
            getPermutation(N, step+1);
            temp.erase(temp.end()-1);
            isUsed[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { cin >> A[i]; }
    getPermutation(N);
    
    int ans = 0;
    for(auto &p: permutation) {
        int cur = 0;
        for(int i = 1; i < N; i++) {
            cur += abs(A[p[i]]-A[p[i-1]]);
        }
        
        ans = max(ans, cur);
    }
    
    cout << ans;

    return 0;
}