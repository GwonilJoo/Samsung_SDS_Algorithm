#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct index{
  int n, c;
};

bool visited[1000000][11];
queue<index> q;

int swap_num(int n, int i, int j){
  string num = to_string(n);
  if (i == 0 && num[j] == '0') return -1;
  
  char tmp = num[i];
  num[i] = num[j];
  num[j] = tmp;
  
  return stoi(num);
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    visited[N][0] = true;
    q.push({N, 0});
 
    int len = to_string(N).length();
 
    while (!q.empty()) {
        // 1. 큐에서 꺼내옴
        index cur = q.front();
        if (cur.c == K) break;
        q.pop();
        
        // 3. 연결된 곳을 순회
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                int new_n= swap_num(cur.n, i, j);
                
                // 4. 갈 수 있는가?
                if (new_n != -1 && !visited[new_n][cur.c+1]) { 
                    // 5. 체크인 & 큐에 넣음
                    visited[new_n][cur.c+1] = true;
                    q.push({new_n, cur.c+1});
                }
                
            }
        }
    }
    
    int Max = -1;
    while (!q.empty()) {
        index cur = q.front();
        if (Max < cur.n) {
            Max = cur.n;
        }
        q.pop();
    }
    
    cout << Max << endl;
}
