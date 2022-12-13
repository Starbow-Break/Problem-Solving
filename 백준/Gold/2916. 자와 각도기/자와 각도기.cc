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

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

int gcd(vector<int> &values) {
    int ret = values[0];
    for(auto &v: values) {
        ret = gcd(ret, v);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    vector<int> possible;
    vector<int> mission;
    
    possible.push_back(360);
    while(N--) {
        int v; cin >> v;
        possible.push_back(v);
    }
    while(K--) {
        int v; cin >> v;
        mission.push_back(v);
    }
    
    int theta = gcd(possible);
    
    for(auto &t: mission) {
        cout << (!(t%theta) ? "YES" : "NO") << '\n';
    }

    return 0;
}