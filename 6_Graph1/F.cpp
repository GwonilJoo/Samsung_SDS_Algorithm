// 1516 게임 개발

/*
강사님 방법
위상절렬 -> 최소시간 찾기

위상정렬 방법
1. 들어오는 간선이 없는 노드들을 큐에 넣기
2. 작업 수행 후 나가는 간선 없애주기
3. 이로인해 들어오는 간선이 없어진 노드들에 대하여 1~2 수행하기
4. 큐가 empty일때까지 계속하기

build_time[510], answer[510], indegree[510], before_max[510]; 역할별로 분류 잘하기!
*/

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N, build_time[510], answer[510], indegree[510], before_max[510];
vector<int> adj[510]; // 먼저 건물 --> 나중 건물
queue<int> q;


int main(){
  scanf("%d", &N);
  for(int i=1;i<=N;i++){
    scanf("%d", &build_time[i]);
    while(true){
      int a;
      scanf("%d", &a);
      if(a == -1) break;
      
      // a--> i
      adj[a].push_back(i);
      indegree[i]++;
    }
  }
  
  // 위상정렬을 통해서, 시작점 = 들어오는 간선이 없는 것들
  for(int i=1;i<=N;i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  
  // 각각의 건물이 지어지는 최소시간 구하기...
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    
    // 지금은 cur를 처리함...이미 before_max는 어떤 값이 잘 들어있다고 생각할 수 있음.
    answer[cur] = before_max[cur] + build_time[cur];
    
    // 다음 건물을 처리해줌...간선을 하나 빼주고 && 그 건물이 지어지기 전에 가장 큰 값(before_max) 세팅
    for(int i=0;i<adj[cur].size();i++){
      int next = adj[cur][i];
      indegree[next]--; // 간선을 하나 빼줌
      if(before_max[next] < answer[cur]){
        before_max[next] = answer[cur];
      }
      if(indegree[next] == 0){
        q.push(next);
      }
    }
  }
  
  // 출력
  for(int i=1;i<=N;i++){
    printf("%d\n", answer[i]);
  }
}
