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
#define MAX_L 500'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;

int t = 1;
int sfx[MAX_L]; //접미사 배열
int inv[MAX_L]; //접미사 배열의 역함수
int lcp[MAX_L]; //LCP 배열
int group[MAX_L+1]; //그룹
int temp[MAX_L];

bool cmp(int a, int b) {
    if(group[a] == group[b]) return group[a+t] < group[b+t];
    
    return group[a] < group[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    int lenS = s.length();
    
    //---------------------------Suffix Array---------------------------
    for(int i = 0; i < lenS; i++) sfx[i] = i;
    
    //그룹 초기화
    for(int i = 0; i < lenS; i++) { group[i] = s[i] - 'a'; }
    group[lenS] = -INF;
    
    while(t <= lenS) {
        //그룹에 따라 정렬
        sort(sfx, sfx+lenS, cmp);
        
        //그룹을 다시 부여
        temp[sfx[0]] = 1;
        for(int i = 1; i < lenS; i++) {
            if(cmp(sfx[i-1], sfx[i])) temp[sfx[i]] = temp[sfx[i-1]]+1;
            else temp[sfx[i]] = temp[sfx[i-1]];
        }
        
        for(int i = 0; i < lenS; i++) group[i] = temp[i];
        
        t <<= 1;
    }
    //---------------------------Suffix Array---------------------------
    
    for(int i = 0; i < lenS; i++) cout << sfx[i] << '\n';
    
    return 0;
}