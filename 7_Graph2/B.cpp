// 1753 최단경로

/*
// 강사님 풀이
다익스트라 알고리즘 사용
우선순위큐를 사용해서 현재 가중치가 가장 작은 노드부터 경로를 따라 움직이고,
다음 노드들을 우선순위 큐에 집어넣음
*/
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define INF 300000

struct Info{
  int b,c;
  Info(int bb, int cc){ // 생성자
    b = bb;
    c = cc;
  }
};

struct Dijk_Info{
  int node_num, node_dist;
  Dijk_Info(int nn, int nd){
    node_num = nn;
    node_dist = nd;
  }
};

struct comp{ // 우선순위 큐를 위한 compare 함수 선언 방법
  bool operator()(Dijk_Info a, Dijk_Info b){
    return a.node_dist > b.node_dist; // swap 조건을 쓰는 것. a가 b보다 크다면 swap -> 최소힙 구현
  }
};

int v,e,k, dist[20010];
vector<Info> adj[20010];

void dijk(){
  priority_queue<Dijk_Info, vector<Dijk_Info>, comp> pq; // 우선순위 큐 선언 방법
  
  // 시작점 거리 세팅 + pq에 입력
  dist[k] = 0;
  pq.push(Dijk_Info(k, 0));
  
  while(!pq.empty()){
    Dijk_Info cur = pq.top();
    pq.pop();
    //printf("node_num: %d")
    
    if(dist[cur.node_num] < cur.node_dist) continue;
    
    // cur 주변 탐색
    for(int i=0;i<adj[cur.node_num].size();i++){
      Info next =  adj[cur.node_num][i];
      int tmp = cur.node_dist + next.c; // 현재점(cur) -> 다음점(next)로 이동할 때 드는 비용
      if(tmp < dist[next.b]){
        dist[next.b] = tmp;
        pq.push(Dijk_Info(next.b, tmp));  
      }
    }
  }
}

int main(){
  scanf("%d%d", &v, &e);
  scanf("%d", &k);
  for(int i=0;i<e;i++){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(Info(b,c)); // a--->b, 가중치는 c
  }
  
  for(int i=1;i<=v;i++) dist[i] = INF;
  
  // dijkstra
  dijk();
  
  // 출력
  for(int i=1;i<=v;i++){
    if(dist[i] == INF){
      printf("INF\n"); 
    }
    else printf("%d\n", dist[i]);
    
  }
}
