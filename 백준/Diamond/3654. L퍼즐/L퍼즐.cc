#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

int N, M; 

vector<ii> graph;
int maxIndex[1000001] = {0, };
bool visited[1000001] = {0, };
stack<int> s;

vector<ii> reverseGraph;
int maxIndexR[1000001] = {0, };
bool visitedR[1000001] = {0, };

int SCC[1000001] = {0, };
vector<ii> SCCgraph;
int SCCIndegree[1000001] = {0, };
int maxIndexSCC[1000001] = {0, };

queue<int> q;
vector<int> orderedSCC;
int SCCnum = 0;

void init() {
    for(int i = 0; i <= 1000000; i++) {
        maxIndex[i] = 0; visited[i] = 0;
        maxIndexR[i] = 0; visitedR[i] = 0;
        SCC[i] = 0; SCCIndegree[i] = 0; maxIndexSCC[i] = 0;
    }
    
    graph.erase(graph.begin(), graph.end());
    reverseGraph.erase(reverseGraph.begin(), reverseGraph.end());
    SCCgraph.erase(SCCgraph.begin(), SCCgraph.end());
    orderedSCC.erase(orderedSCC.begin(), orderedSCC.end());
    SCCnum = 0;
}

void DFS(int cur) {
    visited[cur] = true;
    
    for(int i = (cur == 0) ? 0 : maxIndex[cur-1]; i < maxIndex[cur]; i++) {
        int next = graph[i].second+500000;
        if(!visited[next]) {
            DFS(next);
        }
    }
    
    s.push(cur);
}

void DFS_R(int cur) {
    visitedR[cur] = true;
    SCC[cur] = SCCnum;
    
    for(int i = (cur == 0) ? 0 : maxIndexR[cur-1]; i < maxIndexR[cur]; i++) {
        int next = reverseGraph[i].second+500000;
        if(!visitedR[next]) {
            DFS_R(next);
        }
        else {
            if(SCCnum != SCC[next]) {
                SCCgraph.push_back({SCC[next], SCCnum});
                SCCIndegree[SCCnum]++;
                maxIndexSCC[SCC[next]]++;
            }
        }
    }
}

void addEdge(int i, int j) {
    graph.push_back({-i, j}); graph.push_back({-j, i});
    maxIndex[500000-i]++; maxIndex[500000-j]++;
    reverseGraph.push_back({j, -i}); reverseGraph.push_back({i, -j});
    maxIndexR[500000+i]++; maxIndexR[500000+j]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        init();
        
        cin >> N >> M;
        
        char board[N][501];
        for(int i = 0; i < N; i++) {cin >> board[i];}
        
        int black = 0; int white = 0; bool isPos = true;
        for(int i = 0; i < N && isPos; i++) {
            for(int j = 0; j < M && isPos; j++) {
                if(board[i][j] == 'B') {
                    black++;
                    
                    bool uw = (i > 0 && board[i-1][j] == 'W');
                    bool dw = (i < N-1 && board[i+1][j] == 'W');
                    bool lw = (j > 0 && board[i][j-1] == 'W');
                    bool rw = (j < M-1 && board[i][j+1] == 'W');
                    
                    if(uw && dw) {
                        int u = M*(2*i-1)+j+1;
                        int d = M*(2*i+1)+j+1;
                        addEdge(u, d); addEdge(-u, -d);
                    }
                    else if(uw) {
                        int u = M*(2*i-1)+j+1;
                        addEdge(u, u);
                    }
                    else if(dw) {
                        int d = M*(2*i+1)+j+1;
                        addEdge(d, d);
                    }
                    else {
                        isPos = false;
                    }
                    
                    if(lw && rw) {
                        int l = M*2*i+j;
                        int r = M*2*i+j+1;
                        addEdge(l, r); addEdge(-l, -r);
                    }
                    else if(lw) {
                        int l = M*2*i+j;
                        addEdge(l, l);
                    }
                    else if(rw) {
                        int r = M*2*i+j+1;
                        addEdge(r, r);
                    }
                    else {
                        isPos = false;
                    }
                }
                if(board[i][j] == 'W') {
                    white++;
                    
                    int v[4] = {M*(2*i-1)+j+1, M*(2*i+1)+j+1, M*2*i+j, M*2*i+j+1};
                    for(int a = 0; a < 4; a++) {
                        for(int b = a+1; b < 4; b++) {
                            bool ba, bb; ba = bb = false;
                            if(a == 0 && i > 0 && board[i-1][j] == 'B') ba = true;
                            if(a == 1 && i < N-1 && board[i+1][j] == 'B') ba = true;
                            if(a == 2 && j > 0 && board[i][j-1] == 'B') ba = true;
                            if(a == 3 && j < M-1 && board[i][j+1] == 'B') ba = true;
                            
                            if(b == 0 && i > 0 && board[i-1][j] == 'B') bb = true;
                            if(b == 1 && i < N-1 && board[i+1][j] == 'B') bb = true;
                            if(b == 2 && j > 0 && board[i][j-1] == 'B') bb = true;
                            if(b == 3 && j < M-1 && board[i][j+1] == 'B') bb = true;
                            
                            if(ba && bb) addEdge(-v[a], -v[b]);
                        }
                    }
                }
            }
        }
            
        sort(graph.begin(), graph.end());
        sort(reverseGraph.begin(), reverseGraph.end());
        
        for(int i = 500000-2*N*M; i <= 500000+2*N*M; i++) {
            if(i == 0)
                continue;
                
            maxIndex[i] += maxIndex[i-1];
            maxIndexR[i] += maxIndexR[i-1];
        }
            
        for(int i = 500000-2*N*M; i <= 500000+2*N*M; i++) {
            if(i == 500000)
                continue;
                
            if(!visited[i]) {
                DFS(i);
            }
        }
        
        while(!s.empty()) {
            int v = s.top(); s.pop();
            if(!visitedR[v]) {
                SCCnum++;
                DFS_R(v);
            }
        }
        
        for(int i = 1; i <= SCCnum; i++) {
            if(SCCIndegree[i] == 0) {
                q.push(i);
            }
        }
        
        for(int i = 1; i <= SCCnum; i++) {
            maxIndexSCC[i] += maxIndexSCC[i-1];
        }
        
        sort(SCCgraph.begin(), SCCgraph.end());
        
        while(!q.empty()) {
            int curSCC = q.front(); q.pop();
            orderedSCC.push_back(curSCC);
            for(int i = maxIndexSCC[curSCC-1]; i < maxIndexSCC[curSCC]; i++) {
                int next = SCCgraph[i].second;
                SCCIndegree[next]--;
                
                if(SCCIndegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        int SCCorder[1000001];
        for(int i = 1; i <= SCCnum; i++) {
            SCCorder[orderedSCC[i-1]] = i;
        }
        
        for(int i = 500000-2*N*M; i <= 500000+2*N*M; i++) {
            SCC[i] = SCCorder[SCC[i]];
        }
        
        
        for(int i = 1; i <= 2*N*M && isPos; i++) {
            int SCCpos = SCC[500000+i];
            int SCCneg = SCC[500000-i];
                
            if(SCCpos == SCCneg) {
                isPos = false;
                break;
            }
        }
        
        cout << ((isPos && black*2 == white) ? "YES" : "NO") << '\n';
    }

    return 0;
}