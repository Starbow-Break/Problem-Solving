#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <list>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> box;
    
    while(N--) {
        int size; cin >> size;
        box.push_back(size);
    }
    
    vector<int> ans;
    for(auto &b: box) {
        if(ans.size() == 0) { ans.push_back(b); }
        else {
            if(ans.back() < b) { ans.push_back(b); }
            else {
                for(int j = ans.size()-1; j >= -1; j--) {
                    if(j == -1) ans[0] = b;
                    else {
                        if(ans[j] < b) {
                            ans[j+1] = b;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    cout << ans.size();

    return 0;
}