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

vector<int> getFail(vector<int> &arr) {
    vector<int> fail(arr.size());
    
    fail[0] = 0;
    
    for(int i = 1; i < arr.size(); i++) {
        int j = fail[i-1];
        while(j > 0 && arr[j] != arr[i]) j = fail[j-1];
        
        if(arr[j] == arr[i]) j++;
        fail[i] = j;
    }
    
    return fail;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    vector<int> arr;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        arr.push_back(v);
    }
    reverse(arr.begin(), arr.end());
    
    vector<int> fail = getFail(arr);
    
    pii ans = {N-1, 1};
    for(int i = 1; i <= N; i++) {
        int p = i-fail[i-1];
        int k = N-i;
            
        if(ans.first+ans.second > k+p ||
            (ans.first+ans.second == k+p && ans.second > p)) ans = {k, p};
    }
    
    cout << ans.first << ' ' << ans.second;

    return 0;
}