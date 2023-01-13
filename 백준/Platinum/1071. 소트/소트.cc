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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int ans[50];
vector<int> A; bool visited[50] = {false, };
int remain[1001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        A.push_back(v);
        remain[v]++;
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    
    int idx = 0; int idx1 = 1; int idx2 = 2;
    while(idx < A.size()) {
        if(idx1 >= A.size()) {
            while(remain[A[idx]]--) cout << A[idx] << " ";
        }
        else {
            if(A[idx1] != A[idx]+1) {
                while(remain[A[idx]]--) cout << A[idx] << " ";
            }
            else {
                if(idx2 < A.size()) {
                    while(remain[A[idx]]--) cout << A[idx] << " ";
                    cout << A[idx2] << " "; remain[A[idx2]]--;
                }
                else {
                    while(remain[A[idx1]]--) cout << A[idx1] << " ";
                }
            }
        }
        
        while(idx < A.size() && remain[A[idx]] <= 0) { idx++; }
        while(idx >= idx1 || (idx1 < A.size() && remain[A[idx1]] <= 0)) { idx1++; }
        while(idx1 >= idx2 || (idx2 < A.size() && remain[A[idx2]] <= 0)) { idx2++; }
    }

    return 0;
}