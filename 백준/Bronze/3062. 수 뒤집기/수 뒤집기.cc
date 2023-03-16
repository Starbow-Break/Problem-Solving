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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        string N; cin >> N;
        int sum = 0;
        
        for(int i = 0; i < N.length(); i++) {
            int j = N.length()-1-i;
            sum *= 10; sum += (N[i]-'0'+N[j]-'0');
        }
        
        string strSum = to_string(sum);
        
        int i = 0, j = strSum.length()-1;
        while(i <= j) {
            if(strSum[i] != strSum[j]) break;
            i++; j--;
        }
        
        cout << (i > j ? "YES" : "NO") << '\n';
    }

    return 0;
}