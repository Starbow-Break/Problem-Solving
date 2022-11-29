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

int N;
bool isExist[400001] = {false, };
vector<int> A;

int solve() {
    int ret = 0;
    
    for(int i = 1; i < A.size(); i++) {
        for(int j = 0; j < i; j++) {
            isExist[A[i-1]+A[j]+200000] = true;
        }
        
        for(int j = 0; j < i; j++) {
            if(isExist[A[i]-A[j]+200000]) {
                ret++; break;
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    while(N--) {
        int v; cin >> v; A.push_back(v);
    }

    cout << solve();

    return 0;
}