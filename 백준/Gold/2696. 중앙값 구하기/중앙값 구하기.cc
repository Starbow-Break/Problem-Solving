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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    vector<int> A, ans;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    while(T--) {
        A.clear(); ans.clear();
        while(!maxHeap.empty()) { maxHeap.pop(); }
        while(!minHeap.empty()) { minHeap.pop(); }
        
        int N; cin >> N;
        for(int i = 0; i < N; i++) { int v; cin >> v; A.push_back(v); }
        
        for(int i = 0; i < N; i++) {
            if(minHeap.empty() || minHeap.top() <= A[i]) {
                minHeap.push(A[i]);
            }
            else maxHeap.push(A[i]);
            
            if(minHeap.size() > maxHeap.size()+1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else if(maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            
            if(!(i%2)) { ans.push_back(minHeap.top()); } 
        }
        
        cout << ans.size();
        for(int i = 0; i < ans.size(); i++) {
            if(!(i%10)) cout << '\n';
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}