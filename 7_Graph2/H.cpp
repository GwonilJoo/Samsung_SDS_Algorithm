// K번째 최단 경로 찾기

/*
강사님 힌트
max heap 사용
최단 경로만이 아닌 k개의 경로를 max heap에 저장
size는 최대 k
*/


#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

struct Info{
  int b,c; // b: 노드, c: 시간
  Info(int bb, int cc){ b = bb; c = cc;}
};

struct compare{
  bool operator()(Info A, Info B){
    return A.c > B.c;
  }
};

int n,m,k;
vector<Info> adj[1001];
priority_queue<int> keep_path[1001];

void dijk(){
  priority_queue<Info, vector<Info>, compare> pq;
  pq.push(Info(1,0));
  keep_path[1].push(0);
  
  while(!pq.empty()){
    Info cur = pq.top();
    pq.pop();
    
    for(int i=0;i<adj[cur.b].size();i++){
      Info next = adj[cur.b][i];
      
      int new_dist = cur.c + next.c;
         
      if(keep_path[next.b].size() == k){
        if(keep_path[next.b].top() > new_dist){
          keep_path[next.b].pop();
          keep_path[next.b].push(new_dist);
        }
        else{
          continue;
        }
      }
      else{
        keep_path[next.b].push(new_dist);
      }
      pq.push(Info(next.b, new_dist)); // 위의 continue 덕분에 무한루프를 돌지 않는다!!
    }
  }
}

void show(int i){
  printf("i: ");
  while(!keep_path[i].empty()){
    printf("%d ", keep_path[i].top());
    keep_path[i].pop();
  }
  printf("\n");
}

int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c); // a->b c 시간 걸림
    adj[a].push_back(Info(b,c));
  }
  
  // 경로 구하기
  dijk();
    
  // 출력
  for(int i=1;i<=n;i++){
    if(keep_path[i].size() != k) printf("-1\n");
    else printf("%d\n", keep_path[i].top());
    //else show(i);
  }
}
