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

string s; int N; 

bool check(string &ring) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < s.length(); j++) {
            if(s[j] != ring[(i+j)%10]) break;
            
            if(j == s.length()-1) return true;
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s >> N;
    
    int ans = 0;
    while(N--) {
        string ring; cin >> ring;
        ans += check(ring);
    }
    
    cout << ans;

    return 0;
}