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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int _maxHeap[1 << 17], sz; //최대힙 (정확히는 아님)

vector<int> edges[100'001]; //i -> j => A[i] < A[j]
vector<int> sorted;

void topologySort(int N) {
    int inorder[100'001] = {0, };
    for(int i = 1; i <= N; i++) {
        for(auto &v: edges[i]) inorder[v]++;
    }
    
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(!inorder[i]) q.push(i);
    }
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        sorted.push_back(cur);
        for(auto &next: edges[cur]) {
            inorder[next]--;
            if(!inorder[next]) q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    sz = N;
    for(int i = 1; i <= N; i++) _maxHeap[i] = i;
    
    //최대힙이므로 첫번째 요소는 제일 커야 함
    for(int i = 2; i <= N; i++) edges[i].push_back(1);
    //교환 횟수를 최대로 하기 위해 마지막 요소가 항상 가장 작도록 해야 함
    for(int i = 1; i < N; i++) edges[N].push_back(i);
    
    while(sz > 1) {
        _maxHeap[1] = _maxHeap[sz]; //마지막 요소를 맨 앞으로 옮김
        _maxHeap[sz] = 0; sz--; //사이즈 1 감소
        
        int t = 17;
        while(!(sz&(1<<t))) t--;
        t--;
        
        int idx = 1; //맨 마지막 요소의 현재 위치
        while(t >= 0) {
            if(sz&(1<<t)) { //오른쪽 자식이랑 교환 해야 함 
                edges[_maxHeap[idx<<1]].push_back(_maxHeap[idx<<1|1]); //즉, left < right
                swap(_maxHeap[idx], _maxHeap[idx<<1|1]); //교환
                idx = idx<<1|1; //idx 업데이트
            }
            else { //왼쪽 자식이랑 교환 해야 함 
                edges[_maxHeap[idx<<1|1]].push_back(_maxHeap[idx<<1]); //즉, left > right
                swap(_maxHeap[idx], _maxHeap[idx<<1]); //교환
                idx = idx<<1; //idx 업데이트
            }
            t--;
        }
    }
    
    //위상 정렬
    topologySort(N);
    
    //답 출력
    int ans[100'001];
    for(int i = 0; i < N; i++) ans[sorted[i]] = i+1;
    for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
    
    return 0;
}