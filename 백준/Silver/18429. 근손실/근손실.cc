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

int weight[9];
vector<vector<int>> per;

vector<int> temp;
bool isUsed[9] = {false, };
void getPermutation(int N, int step = 0) {
    if(step == N) per.push_back(temp);
    
    for(int i = 1; i <= N; i++) {
        if(isUsed[i]) continue;
        
        temp.push_back(i);
        isUsed[i] = true;
        getPermutation(N, step+1);
        isUsed[i] = false;
        temp.erase(temp.end()-1);
    }
}

bool check(vector<int> &vec, int K) {
    int cur = 500;
    for(auto &num: vec) {
        cur += (weight[num]-K);
        if(cur < 500) return false;
    }
    
    return true;
}

int solve(int N, int K) {
    int ret = 0;
    
    getPermutation(N);
    
    for(auto &p: per) {
        ret += check(p, K);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> weight[i];
    
    cout << solve(N, K);

    return 0;
}