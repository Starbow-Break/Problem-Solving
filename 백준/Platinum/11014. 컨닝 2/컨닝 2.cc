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

int numV = 0; //정점의 갯수
char arr[80][81];
vector<int> edge[6400];
int conn[6400];
bool visited[6400];

void init() {
    numV = 0;
    for(int i = 0; i < 6400; i++) {
        edge[i].clear();
        conn[i] = -1;
    }
}

//DFS
bool dfs(int cur) {
    for(auto &next: edge[cur]) {
        if(visited[next]) continue;
        
        visited[next] = true;
        if(conn[next] == -1 || dfs(conn[next])) {
            conn[next] = cur;
            return true;
        }
    }
    
    return false;
}

//이분 매칭
int binaryMatching(int N, int M) {
    int ret = 0;
    
    for(int i = 0; i < N*M; i++) {
        fill(visited, visited+N*M, false);
        ret += dfs(i);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        init();
        
        int N, M; cin >> N >> M;
        for(int i = 0; i < N; i++) cin >> arr[i];
        
        //교실 상황에 맞는 이분 그래프 생성
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(arr[i][j] != '.') continue;
                
                numV++;
                
                if(!(j%2)) {
                    if(j < M-1) {
                        if(i > 0 && arr[i-1][j+1] == '.') edge[i*M+j].push_back((i-1)*M+j+1);
                        if(arr[i][j+1] == '.') edge[i*M+j].push_back(i*M+j+1);
                        if(i < N-1 && arr[i+1][j+1] == '.') edge[i*M+j].push_back((i+1)*M+j+1);
                    }
                    if(j > 0) {
                        if(i > 0 && arr[i-1][j-1] == '.') edge[i*M+j].push_back((i-1)*M+j-1);
                        if(arr[i][j-1] == '.') edge[i*M+j].push_back(i*M+j-1);
                        if(i < N-1 && arr[i+1][j-1] == '.') edge[i*M+j].push_back((i+1)*M+j-1);
                    }
                }
            }
        }
        
        //최대 매칭 수 구하기
        int maxMatch = binaryMatching(N, M);
        
        //최대 독립 집합 크기 = (정점 수)-(최대 매칭 수)
        cout << numV-maxMatch << '\n';
    }
    

    return 0;
}