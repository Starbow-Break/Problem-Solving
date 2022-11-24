#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<int> ans;
bool check() {
    int len = ans.size();
    
    for(int d = 2; d <= len/2; d++) {
        int j = len-1; int i = j-d;
        
        while(j >= len-d-1) {
            if(j == len-d-1) return false;
            
            if(ans[i] != ans[j]) break;
            
            i--; j--;
        }
    }
    
    return true;
}

bool solve(int N, int step) {
    if(N == step) return true;
    
    for(int i = 1; i <= 3; i++) {
        if(step > 0 && ans[step-1] == i) continue;
        
        ans.push_back(i);
        if(check()) {
            if(solve(N, step+1)) return true;
        }
        ans.erase(ans.end()-1);
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    solve(N, 0);
    for(auto &a: ans) {cout << a;}

    return 0;
}
