#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
#define MAX 200000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
vector<int> vec;

int solve() {
    for(int ansIdx = N-1; ansIdx >= 3; ansIdx--) {
        for(int j = ansIdx-1; j >= 0; j--) {
            if(vec[j]+vec[j]+vec[ansIdx-1] < vec[ansIdx]) break;
            
            int i = j; int k = j;
            while(i >= 0 && k < ansIdx) {
                if(vec[i]+vec[j]+vec[k] < vec[ansIdx]) k++;
                else if(vec[i]+vec[j]+vec[k] > vec[ansIdx]) i--;
                else return vec[ansIdx];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    sort(vec.begin(), vec.end());
    
    cout << solve();
    
    return 0;
}