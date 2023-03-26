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
#define MAX_N 200'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int t = 1;
int sfx[MAX_N]; //접미사 배열
int inv[MAX_N]; //접미사 배열의 역함수
int lcp[MAX_N]; //LCP 배열
int group[MAX_N+1]; //그룹
int temp[MAX_N];

bool cmp(int a, int b) {
    if(group[a] == group[b]) return group[a+t] < group[b+t];
    
    return group[a] < group[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string s; cin >> s;
    
    //---------------------------Suffix Array---------------------------
    for(int i = 0; i < N; i++) sfx[i] = i;
    
    //그룹 초기화
    for(int i = 0; i < N; i++) { group[i] = s[i] - 'a'; }
    group[N] = -1;
    
    while(t <= N) {
        //그룹에 따라 정렬
        sort(sfx, sfx+N, cmp);
        
        //그룹을 다시 부여
        temp[sfx[0]] = 1;
        for(int i = 1; i < N; i++) {
            if(cmp(sfx[i-1], sfx[i])) temp[sfx[i]] = temp[sfx[i-1]]+1;
            else temp[sfx[i]] = temp[sfx[i-1]];
        }
        
        for(int i = 0; i < N; i++) group[i] = temp[i];
        
        t <<= 1;
    }
    //---------------------------Suffix Array---------------------------
    
    //-----------------------------LCP Array----------------------------
    for(int i = 0; i < N; i++) inv[sfx[i]] = i;
    
    for(int i = 0, cur = 0; i < N; i++) {
        if(inv[i] == 0) continue;
        
        int j = sfx[inv[i]-1];
        
        while(i+cur < N && j+cur < N && s[i+cur] == s[j+cur]) {
            cur++;
        }
        
        lcp[inv[i]] = cur;
        
        if(cur > 0) cur--;
    }
    //-----------------------------LCP Array----------------------------
    
    int ans = 0;
    for(int i = 1; i < s.length(); i++) ans = max(ans, lcp[i]);
    
    cout << ans;
    
    return 0;
}