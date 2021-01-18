// 2252 줄 세우기

/*
강사님 방법
위상정렬 사용하기!

자신의 앞에 없다 -> 자기한테 들어오는 간선이 없다(차수 indegree == 0)
-> list에 추가하고 자기로부터 나가는 간선을 지운다(outdegree)
-> 이로 인해 indegree가 0이 된 간선을 계속 추가하고 outdegree를 지우는 것을 반복한다.

*/

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int n,m, indegree[32010];
vector<int> adj[32010]; // 인접리스트. 인덱스 i칸에는 i노드의 outdegree를 넣어준다.
queue<int> q;


int main(){
  scanf("%d%d", &n, &m);
  
  for(int i=0;i<m;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    
    //a->b
    adj[a].push_back(b);
    indegree[b]++;
  }
  // indegree가 0인 것을 찾는다.
  // 어딘가 모아놓는다.
  for(int i=1;i<=n;i++){
    // queue에 넣는다.
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  
  // 모아놓은것을 하나씩 queue에서 뽑으면서 출력하고, 연결된 것들의 간선을 하나씩 줄여준다.
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    printf("%d ", cur);
    // 연결된 간선을 하나씩 줄인다.
    for(int i=0; i<adj[cur].size(); i++){
      int next = adj[cur][i];
      indegree[next]--;
      if(indegree[next] == 0){
        q.push(next);
      }
    }
  }
  
  printf("\n");
  return 0;
}
