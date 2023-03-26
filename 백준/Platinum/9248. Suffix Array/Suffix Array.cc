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
#define MAX_S 500'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;

int t = 1;
int sfx[MAX_S]; //접미사 배열
int inv[MAX_S]; //접미사 배열의 역함수
int lcp[MAX_S]; //LCP 배열
int group[MAX_S+1]; //그룹
int temp[MAX_S];

bool cmp(int a, int b) {
    if(group[a] == group[b]) return group[a+t] < group[b+t];
    
    return group[a] < group[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    
    
    //---------------------------Suffix Array---------------------------
    for(int i = 0; i < s.length(); i++) sfx[i] = i;
    
    //그룹 초기화
    for(int i = 0; i < s.length(); i++) { group[i] = s[i] - 'a'; }
    group[s.length()] = -INF;
    
    while(t <= s.length()) {
        //그룹에 따라 정렬
        sort(sfx, sfx+s.length(), cmp);
        
        //그룹을 다시 부여
        temp[sfx[0]] = 1;
        for(int i = 1; i < s.length(); i++) {
            if(cmp(sfx[i-1], sfx[i])) temp[sfx[i]] = temp[sfx[i-1]]+1;
            else temp[sfx[i]] = temp[sfx[i-1]];
        }
        
        for(int i = 0; i < s.length(); i++) group[i] = temp[i];
        
        t <<= 1;
    }
    
    for(int i = 0; i < s.length(); i++) cout << sfx[i]+1 << ' ';
    //---------------------------Suffix Array---------------------------
    
    //-----------------------------LCP Array----------------------------
    for(int i = 0; i < s.length(); i++) inv[sfx[i]] = i;
    
    for(int i = 0, cur = 0; i < s.length(); i++) {
        if(inv[i] == 0) continue;
        
        int j = sfx[inv[i]-1];
        
        while(i+cur < s.length() && j+cur < s.length() && s[i+cur] == s[j+cur]) {
            cur++;
        }
        
        lcp[inv[i]] = cur;
        
        if(cur > 0) cur--;
    }
    
    cout << '\n' << "x ";
    for(int i = 1; i < s.length(); i++) cout << lcp[i] << ' ';
    //-----------------------------LCP Array----------------------------
    
    return 0;
}