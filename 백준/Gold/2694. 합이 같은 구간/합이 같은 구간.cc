#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    int arr[10'000]; vector<int> vec;
    while(T--) {
        vec.clear();
        
        int N; cin >> N;
        for(int i = 0; i < N; i++) { cin >> arr[i]; }
        
        int i = 0, j = N-1, sumI = arr[0], sumJ = arr[N-1];
        while(i < N && j >= 0) {
            if(sumI > sumJ) { j--; sumJ += arr[j]; }
            else if(sumI < sumJ) { i++; sumI += arr[i]; }
            else {
                vec.push_back(sumI);
                i++; j--; sumI += arr[i]; sumJ += arr[j];
            }
        }
        
        int sum = vec.back(); int ans = 0;
        for(int i = 0; i < vec.size() && ans == 0; i++) {
            if(sum%vec[i] == 0) {
                int cur = vec[i];
                for(int j = i; j < vec.size(); j++) {
                    if(vec[j] == cur) cur += vec[i];
                    if(vec[j] > cur) break;
                }
                
                if(cur > sum) ans = vec[i];
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}