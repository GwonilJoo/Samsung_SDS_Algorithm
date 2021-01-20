// 5719 거의 최단 경로
/*
강사님 힌트
dijk-> 최단 경로의 간선 저장 -> dfs를 통해 간선 블랙리스트 추가 -> 다시 dijk 하기
*/

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define INF 1000000

struct Info{
  int v,p;
};

struct compare{
  bool operator()(Info A, Info B){
    return A.p > B.p;
  }
};

int N, M, S, D, dist[500];
vector<Info> adj[500];
vector<int> rev[500];
bool black_list[500][500], visit[500]; // visit 안하면 시간 초과 남;;

void dijk(){
  priority_queue<Info, vector<Info>, compare> pq;
  pq.push({S, 0});
  dist[S] = 0;
  
  while(!pq.empty()){
    Info cur = pq.top();
    pq.pop();
    
    if(dist[cur.v] < cur.p) continue;
    
    for(int i=0;i<adj[cur.v].size();i++){
      Info next = adj[cur.v][i];
      
      if(black_list[cur.v][next.v]) continue;
      
      int new_dist = cur.p + next.p;
      
      if(new_dist < dist[next.v]){
        dist[next.v] = new_dist;
        pq.push({next.v, new_dist});
        
        rev[next.v].clear();
        rev[next.v].push_back(cur.v);
      }
      else if(new_dist == dist[next.v]){
        rev[next.v].push_back(cur.v);
      }
    }
  }
}

void rev_dfs(int n){
  if(visit[n]) return;
  visit[n] = true;
  
  for(int i=0;i<rev[n].size();i++){
    int next = rev[n][i];
    black_list[next][n] = true;
    
    rev_dfs(next);
  }
}

int main(){
  while(true){
    scanf("%d%d", &N, &M);
    
    if(N == 0 && M == 0) break;
    
    // 초기화
    for(int i=0;i<N;i++) {
      dist[i] = INF;
      rev[i].clear();
      adj[i].clear();
      visit[i] = false;
      for(int j=0;j<N;j++) black_list[i][j] = false;
    }
    
    
    // 입력
    scanf("%d%d", &S, &D);
    for(int i=0;i<M;i++){
      int u,v,p;
      scanf("%d%d%d", &u, &v, &p);
      adj[u].push_back({v,p});
    }
    
    // 최단 경로 찾기
    dijk();
    
    if(dist[D] == INF) {
      printf("-1\n"); continue;
    }
    // 최단 경로들 블랙리스트 처리
    rev_dfs(D);
    //black_list[S] = false;
    
    /*
    printf("black_list: \n");
    for(int i=0;i<N;i++){
      printf("%d: ", i);
      for(int j=0;j<N;j++){
        if(black_list[i][j]) printf("%d ", j);
      }
      printf("\n");
    }
    printf("\n");
    */
  
    // 거의 최단 경로 찾기
    for(int i=0;i<N;i++) dist[i] = INF;
    dijk();
    
    // 출력
    if(dist[D] == INF) {
      printf("-1\n"); 
    }
    else printf("%d\n", dist[D]);
  }

}
