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

//트라이
class Trie {
    Trie* child[2];
    
    public:
        //value를 트라이에 추가
        void add(int value, int bit) {
            if(bit < 0) return;
            
            if(value & (1 << bit)) {
                if(child[1] == NULL) child[1] = new Trie();
                child[1]->add(value, bit-1);
            }
            else {
                if(child[0] == NULL) child[0] = new Trie();
                child[0]->add(value, bit-1);
            }
        }
        
        //트라이 비우기
        void clear(int bit = 29) {
            if(child[0] != NULL)
                child[0]->clear(bit-1);
            
            if(child[1] != NULL)
                child[1]->clear(bit-1);
            
            free(child[0]); child[0] = NULL;
            free(child[1]); child[1] = NULL; 
        }
        
        //트라이에 저장된 값과 value를 xor 했을 때 최솟값
        int query(int value, int bit) {
            if(bit < 0) return 0;
            
            bool b = ((value & (1 << bit)) > 0);
            
            if(child[b] != NULL) return child[b]->query(value, bit-1);
            else return (1<<bit)+child[!b]->query(value, bit-1);
        }
};

ll solve(vector<int> &vec, int bit = 29) {
    if(bit < 0 || vec.size() <= 1) return 0;
    if(vec.size() == 2) return vec[0]^vec[1];
    
    vector<int> subVec[2];
    
    for(auto &val: vec) subVec[((val&(1<<bit))>0)].push_back(val);
    
    if(subVec[0].size() == 0) return solve(subVec[1], bit-1);
    else if(subVec[1].size() == 0) return solve(subVec[0], bit-1);
    else {
        int minV = 1 << 30; Trie* tr = new Trie();
        for(auto &val: subVec[0]) tr->add(val, bit);
        for(auto &val: subVec[1]) minV = min(minV, tr->query(val, bit));
        tr->clear();
        
        return 0LL+minV+solve(subVec[0], bit-1)+solve(subVec[1], bit-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    cout << solve(vec);

    return 0;
}