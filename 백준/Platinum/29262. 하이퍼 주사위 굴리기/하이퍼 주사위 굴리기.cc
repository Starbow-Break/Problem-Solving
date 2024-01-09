#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int OFFSET = 500'001;
int number[1'000'003]; // 각 축에 대응되는 주사위 번호
int axis[1'000'003]; // 각 주사위 번호에 대응되는 축 

int main()
{
    int N, M; cin >> N >> M;
    
    vector<int> query(M);
    for(int i = 0; i < M; i++) cin >> query[i];
    
    // 차원 압축
    // M이 최대 50만이므로 최대 (50만+1)차원만 확인하면 된다.
    vector<int> temp; int axisNum;
    temp.push_back(1);
    for(auto &q: query) {
        if(q > N) temp.push_back(2*N+1-q);
        else temp.push_back(q);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    axisNum = temp.size();
    
    for(int i = 1; i <= axisNum; i++) {
        number[OFFSET+i] = 2*axisNum+1-i;
        number[OFFSET-i] = i;
        axis[2*axisNum+1-i] = i;
        axis[i] = -i;
    }
    
    for(int i = 0; i < query.size(); i++) {
        if(query[i] > N) {
            int twin = lower_bound(temp.begin(), temp.end(), 2*N+1-query[i])-temp.begin()+1;
            query[i] = 2*axisNum+1-twin;
        }
        else query[i] = lower_bound(temp.begin(), temp.end(), query[i])-temp.begin()+1;
    }
    
    int move[500'002] = {0, };
    for(auto &q: query) {
        //cout << q << ' ' << axis[q] << '\n';
        
        int ax = axis[q];
        int a = number[OFFSET+ax];
        int b = number[OFFSET-1];
        int c = number[OFFSET-ax];
        int d = number[OFFSET+1];
        
        //cout << a << b << c << d << '\n';
        
        move[abs(ax)] += ax/abs(ax);
        
        number[OFFSET-1] = a;
        number[OFFSET-ax] = b;
        number[OFFSET+1] = c;
        number[OFFSET+ax] = d;
        axis[a] = -1, axis[b] = -ax, axis[c] = 1, axis[d] = ax;
    }
    
    long long ans = 0;
    for(int i = 1; i <= axisNum; i++) {
        ans += 1LL*move[i]*move[i];
        //cout << move[i] << ' ';
    }
    
    cout << ans;

    return 0;
}