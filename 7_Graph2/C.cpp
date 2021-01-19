// 11657 타임머신

/*
다익스트라, 플로이드는 모두 가중치 양수일때를 전제로 한 것
음수이면??

벨만 - 포드 알고리즘 사용
*/

#include<cstdio>
#include<vector>
using namespace std;

#define INF 5000001

struct Info{
  int b, c;
};

int N, M;
long long cost[501];
vector<Info> adj[501];
bool check = false;

void bell(){
  cost[1] = 0; // 시작점을 초기화
  for(int i=0;i<N-1;i++){ // 최대 방문할 수 있는 간선의 개수만큼 돌림 : n-1번
    for(int j=1;j<=N;j++){ // j점 주변에 있는 점들을 업데이트할 수 있는지 확인함
      for(int k=0;k<adj[j].size();k++){
        Info next = adj[j][k]; // next.b: j점 주변의 점, next.c: 그 점까지 이동하는데 걸리는 비용
        long long new_cost = cost[j] + next.c;
        
        if(cost[j] != INF && cost[next.b] > new_cost)
          cost[next.b] = new_cost; // j->next 더 적은 비용으로 이동 가능하면 업데이트
      }
    }
  }
  
  // 전제: n-1번 수행했기 때문에, 가장 먼 경로더라도 충분히 도달했을 것임
  // 그리고 그 경로가 최단경로엿을것이다.
  // 왜냐면 더 추가해서 방문을 했으면 경로의 값이 커질테니까
  // 하지만 중간에 감소하는 구간이 있었다면??
  // 뭔가 해야 함
  // 한번 더 해봄
  for(int j=1;j<=N;j++){
    for(int k=0;k<adj[j].size();k++){
      Info next = adj[j][k];
      long long new_cost = cost[j] + next.c;
    
      if(cost[j] != INF && cost[next.b] > new_cost){ // 이런 일이 벌어질 수 있을까??
        check = true; return;
      }  
    }
  }
}

int main(){
  // 입력
  scanf("%d%d", &N, &M);
  
  for(int i=2;i<=N;i++){
    cost[i] = INF;
  }
  
  for(int i=0;i<M;i++){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({b,c});
  }
  
  // 최소 시간 구하기
  bell();
  
  // 출력
  // 예외 먼저 처리
  // 시간이 무한히 되돌아가면 -1
  // 어떤 도시까지 가는 경로 없으면 -1
  // 각 지점까지 출력
  if(check){
    printf("-1\n");
  }
  else{
    for(int i=2;i<=N;i++){
      if(cost[i] == INF) printf("-1\n");
      else printf("%lld\n", cost[i]);
    }
  }
}
