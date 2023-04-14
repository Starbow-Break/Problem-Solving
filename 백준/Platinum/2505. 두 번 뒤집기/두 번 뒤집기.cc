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
    
    int N; cin >> N;
    int orig[N+1], arr[N+1];
    for(int i = 1; i <= N; i++) cin >> orig[i];
    
    vector<pii> ans;
    int a = 1;
    for(int i = 1; i <= N; i++) arr[i] = orig[i];
    while(a <= N) {
        if(arr[a] == a) a++;
        else {
            int b = a;
            while(arr[b] != a) b++;
            
            ans.push_back({a, b});
            if(ans.size() > 3) {
                ans.clear(); break;
            }
            
            int i = a, j = b;
            while(i <= j) {
                swap(arr[i], arr[j]);
                i++; j--;
            }
        }
    }
    
    if(a <= N) {
        a = N;
        for(int i = 1; i <= N; i++) arr[i] = orig[i];
        while(a >= 1) {
            if(arr[a] == a) a--;
            else {
                int b = a;
                while(arr[b] != a) b--;
                
                ans.push_back({b, a});
                
                int i = b, j = a;
                while(i <= j) {
                    swap(arr[i], arr[j]);
                    i++; j--;
                }
            }
        }
    }
    
    while(ans.size() < 2) ans.push_back({1, 1});
    
    for(auto &a: ans) {
        cout << a.first << ' ' << a.second << '\n';
    }

    return 0;
}