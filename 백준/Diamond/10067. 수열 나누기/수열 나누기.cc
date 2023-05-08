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
#define MAX_N 100'000
#define MAX_K 200

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

struct node {
    int pos, num;
};

//dp[i][k] = k번째 항까지 총 i번 잘랐을 때 최대 점수
//토글링을 사용해서 관리
ll dp[MAX_N+1] = {0, };

//cut[k][n] = n번째 항까지 k번 잘랐을 때 최대 점수를 얻기 위한 컷에서
//제일 오른쪽에 위치한 컷의 번호
//역추적을 위해 사용하는 배열
int cut[MAX_K+1][MAX_N+1] = {0, };

//sum[i] = A[1]+A[2]+...+A[i], sum[0] = 0
int sum[MAX_N+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    
    //sum 초기화
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> sum[i]; sum[i] += sum[i-1];
    }
    
    //Convex Hull Trick
    vector<node> vec; int back = -1, t = 0;
    ll temp[MAX_N+1];
    for(int i = 1; i <= k; i++) {
        vec.clear(); back = -1;
        vec.push_back({0, i}); back++;
        t = 0;
        
        for(int j = i+1; j <= n; j++) {
            while(t != back && sum[j] >= vec[t+1].pos) t++;
            
            int idx = vec[t].num;
            temp[j] = dp[idx]-1LL*sum[idx]*sum[idx]+1LL*sum[idx]*sum[j];
            cut[i][j] = idx;
            
            ll a = sum[j];
            ll b = dp[j]-1LL*sum[j]*sum[j];
            
            while(0 <= back) {
                int pos = vec[back].pos;
                int num = vec[back].num;
                
                ll c = sum[num];
                ll d = dp[num]-1LL*sum[num]*sum[num];
                
                if(a == c) {
                    if(b <= d) break;
                }
                else {
                    int x = (b-d)/(c-a) + (abs(b-d)%abs(c-a) > 0);
                    
                    if(x > pos) {
                        back++;
                        if(back == vec.size()) vec.push_back({x, j});
                        else vec[back] = {x, j};
                        break;
                    }
                }
                
                back--;
                if(back < t) t--;
            }
            
            if(back < 0) {
                back = 0; t = 0;
                vec[back] = {0, j};
            }
        }
        
        for(int j = i+1; j <= n; j++) dp[j] = temp[j];
    }
    
    cout << dp[n] << '\n';
    
    vector<int> ans;
    for(int i = k, j = cut[k][n]; i >= 1; i--) {
        ans.push_back(j);
        j = cut[i-1][j];
    }
    
    reverse(ans.begin(), ans.end());
    for(auto &v: ans) cout << v << ' ';

    return 0;
}
