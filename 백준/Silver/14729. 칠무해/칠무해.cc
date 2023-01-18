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
    
    int cnt[100001] = {0, };
    
    int N; cin >> N;
    
    for(int i = 0; i < N; i++) {
        string v; cin >> v;
        int arr[2] = {0, }; int t = 0;
        for(int i = 0; i < v.length(); i++) {
            if(v[i] == '.') t++;
            else {
                arr[t] *= 10; arr[t] += v[i]-'0';
            }
        }
        
        cnt[arr[0]*1000+arr[1]]++;
    }
    
    int _cnt = 0; int idx = 0;
    cout << fixed; cout.precision(3);
    while(_cnt < 7) {
        if(cnt[idx] != 0) {
            cout << (double)idx/1000 << '\n';
            cnt[idx]--; _cnt++;
        }
        else { idx++; }
    }
    
    return 0;
}