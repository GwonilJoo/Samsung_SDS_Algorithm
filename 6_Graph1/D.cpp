// 11438 LCA2

/*
강사님 힌트
1. 1 2 4 8... 번째 조상이 누군지 파악하기

2. 두 쌍의 루트로부터의 깊이 같게 만들기
3. 1 2 4 8 번째 조상이 달라지는 시점 파악하기 -> 어떤 시점의 두 노드가 같은 부모노드를 가질때까지 반복
4. 결국 찾은 두 노드의 부모노드가 LCA가 된다

*/ 

#include<cstdio>
#include<vector>
using namespace std;

int N, M, depth[100010], an[100010][18]; // 18 = 0.....17 = 2^17 > 100000 /  2^0, 2^1, ....2^17번째 조상을 담음
vector<int> adj[100010];
bool visited[100010];

// root = 1

void dfs(int parent, int cur, int param_depth){
  if(visited[cur]) return;
  visited[cur] = true;
  depth[cur] = param_depth;
  an[cur][0] = parent;    // 2^0 조상
  for(int i=0;i<adj[cur].size();i++){
    dfs(cur, adj[cur][i], param_depth+1);
  }
}

int lca(int a, int b){
  // to do
  // a의 깊이가 b보다 더 깊게 만들어서 쉽게 처리하려고...
  if(depth[a] < depth[b]){
    int tmp = a;
    a = b;
    b = tmp;
  }
  
  // 만약에 깊이가 서로 다르면 맞춰춘다...
  if(depth[a] != depth[b]){
    // a-->b 까지 깊이를 맞춰준다.
    int diff = depth[a] - depth[b];
    
    
    for(int i=0;i<=17;i++){
      //if(diff & j)
      if(diff & (1<<i)){
        a = an[a][i];
      }
    }
    
  }
  
  // depth[a] == depth[b]인 상태
  if(a==b) return a;
  
  for(int i=17;i>=0;i--){
    if(an[a][i] != an[b][i]){
      a = an[a][i];
      b = an[b][i];
    }
  }
  
  // LCA의 바로 아래까지 옴  
  return an[a][0];
}

int main(){
  scanf("%d", &N);
  for(int i=0;i<N-1;i++){
    int a,b;
    scanf("%d%d", &a, &b);
    
    // 일단 양방향으로 연결
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  // LCA를 위한 자료 수집: 깊이, 1/2/4/....조상
  dfs(1,1,1);
  
  // 2^1, 2^2, 2^3.....조상
  for(int i=1;i<=17;i++){  // 2^i 번째 조상
    for(int j=1;j<=N;j++){  // 1번 노드, 2번 노드, ... , n번 노드
      int tmp = an[j][i-1];
      an[j][i] = an[tmp][i-1];
    }
  }
  
  scanf("%d", &M);
  for(int i=0;i<M;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", lca(a,b));
  }
}
