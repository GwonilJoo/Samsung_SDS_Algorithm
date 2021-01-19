// 11266 단절점

/*
강사님 풀이
1. 임의의 점 루트로 잡고 시작
2. 
*/

#include<cstdio>
#include<vector>
using namespace std;

int v, e, cnt, visit_order[10010], num = 1;
bool ans[10010]; // 단절점이면 true
vector<int> adj[10010];

// 예외: 루트일 경우
// 나의 방문순서와 자식들이 만나는 방문순서중 가장 작은 값을 비교
int dfs(int parent, int cur, bool isRoot){
  int min_visit_order = 20000; // 내 자식들이 만날 수 있는 점 중에서 가장 작은 점
  int chlcnt = 0; // 자식들의 수
  visit_order[cur] = num; // 나(cur) 의 순서, 번호
  min_visit_order = visit_order[cur]; // 자기 자신으로 초기화
  num++;
  
  for(int i=0;i<adj[cur].size();i++){
    int next = adj[cur][i];
    //if (next == parent) continue; 
    if(visit_order[next]){
      min_visit_order = min(min_visit_order, visit_order[next]);
    }
    else{ // 새롭게 방문하는 경우
      int tmp = dfs(cur, next, false);
      min_visit_order = min(min_visit_order, tmp);
      if(!isRoot && tmp >= visit_order[cur]){
        ans[cur] = true;
      }
      chlcnt++;
    }
  }
  
  // 위에 min_visit_order 초기화, parent 예외처리를  하지 않은 경우,
  // 만약에 리프노드면, 단절점처리를 해주지 않음
  /*
  if(adj[cur].size() == 1){
    return visit_order[cur];
  }
  */
  
  if(isRoot){
    // 자식이 두개 이상이면 단절점
    if(chlcnt >= 2){
      ans[cur] = true;
    }
  }
  
  return min_visit_order; // 내가(cur) 만난 점 중에서 방문순서가 가장 낮은 점을 반환
}

int main(){
  scanf("%d%d", &v, &e);
  
  for(int i=0;i<e;i++){
    int a,b;
    scanf("%d%d", &a, &b);
    
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  // 단절점 찾기
  for(int i=1; i<=v;i++){
    if(visit_order[i] == 0){
      dfs(0, i, true);
    }
  }
  
  // 출력
  for(int i=1;i<=v;i++){
    if(ans[i]) cnt++;
  }
  printf("%d\n", cnt);
  for(int i=1;i<=v;i++){
    if(ans[i]){
      printf("%d ", i);
    }
  }
  printf("\n");
}
