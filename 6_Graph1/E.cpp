// 2458 키 순서

/*
강사님 방법
나보다 키가 큰 노드 + 나보다 키가 작은 노드 + 자기 자신 = 노드 개수 -> 나의 키가 몇번째인지 정확히 알 수 있다!
*/

#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int N, M, answer, visited_cnt, visited_rev_cnt;
bool visited[510], visited_rev[510];
vector<int> adj[510], rev[510];

void dfs(int cur){
  if(visited[cur]) return;
  visited[cur] = true;
  visited_cnt++;
  
  for(int i=0;i<adj[cur].size();i++){
    dfs(adj[cur][i]);
  }
}

void dfs_rev(int cur){
  if(visited_rev[cur]) return;
  visited_rev[cur] = true;
  visited_rev_cnt++;
  
  for(int i=0;i<rev[cur].size();i++){
    dfs_rev(rev[cur][i]);
  }
}


int main(){
  scanf("%d%d", &N, &M);
  
  for(int i=0;i<M;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    // a가 b보다 작음
    adj[a].push_back(b); // a-->b
    rev[b].push_back(a); // b-->a
  }
  
  for(int i=1;i<=N;i++){
    // 나보다 큰 수를 셈 ---> visited_cnt 
    visited_cnt = 0; // 나 + 나보다 큰 학생
    memset(visited, 0x00, sizeof(visited));
    dfs(i);
    
    // 나보다 작은 수를 셈
    visited_rev_cnt = 0; // 나 + 나보다 작은 학생
    memset(visited_rev, 0x00, sizeof(visited_rev));
    dfs_rev(i);
    
    // i번째 학생의 순서를 알 수 있는지 없는지 판단
    // 나보다 큰 학생수 + 나보다 작은 학생수 + 1 == N
    if(visited_cnt + visited_rev_cnt == N+1){
      answer++;
    }
  }
  
  printf("%d\n", answer);  
}
