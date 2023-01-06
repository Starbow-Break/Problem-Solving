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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
int A[100001];
int idx[100001];
bool visited[100001] = {false, };

void compress() {
    vector<int> temp;
    for(int i = 1; i <= N; i++) { temp.push_back(A[i]); }
    
    sort(temp.begin(), temp.end());
    
    for(int i = 1; i <= N; i++) {
        A[i] = lower_bound(temp.begin(), temp.end(), A[i])-temp.begin()+1;
    }
}

int solve() {
    int ret = 0;
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            int cur = A[i];
            int pos = i;
            
            while(pos != cur) {
                visited[pos] = true; ret++;
                pos = idx[pos];
            }
            
            visited[cur] = true;
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) { cin >> A[i]; }
    compress();
    for(int i = 1; i <= N; i++) { idx[A[i]] = i; }
    
    cout << solve();

    return 0;
}