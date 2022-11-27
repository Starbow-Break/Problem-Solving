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
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> vec;
    
    int N; string s;
    cin >> N >> s;
    
    char cur = s[0]; int cnt = 1;
    for(int i = 1; i < N; i++) {
        if(cur == s[i]) cnt++;
        else {
            vec.push_back(cnt);
            cnt = 1; cur = s[i];
        }
    }
    vec.push_back(cnt);
    
    int ans = 0;
    if(vec.size() >= 2) {
        for(int i = 0; i < vec.size()-1; i++) {
            ans = max(ans, min(vec[i], vec[i+1])*2);
        }
    }
    
    cout << ans;

    return 0;
}
