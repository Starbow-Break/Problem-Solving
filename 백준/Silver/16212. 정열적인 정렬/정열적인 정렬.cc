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
    
    int N; cin >> N; 
    vector<int> ans;
    
    for(int i = 0; i < N; i++) { int v; cin >> v; ans.push_back(v); }
    sort(ans.begin(), ans.end());
    
    for(auto &item: ans) { cout << item << " "; }

    return 0;
}