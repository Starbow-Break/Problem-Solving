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

int dp[3'000'001];
vector<int> fibonacci;

void getFibonacci() {
    fibonacci.push_back(1); fibonacci.push_back(2);
    
    int i = 0, j = 1;
    while(1) {
        fibonacci.push_back(fibonacci[i]+fibonacci[j]);
        
        if(fibonacci.back() >= 3'000'000) break;
        i++; j++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getFibonacci();
    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3;
    
    int check[100] = {0, }; int idx;
    for(int i = 4; i <= 3'000'000; i++) {
        idx = 0;
        for(auto &f: fibonacci) {
            if(f > i) break;
            check[dp[i-f]] = i;
            
            while(check[idx] == i) idx++;
        }
        
        dp[i] = idx;
    }
    
    int N; cin >> N; int grundy = 0;
    while(N--) {
        int v; cin >> v;
        grundy ^= dp[v];
    }
    
    cout << (grundy ? "koosaga" : "cubelover");

    return 0;
}