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
  if(visit[cur]) return;
  visit[cur] = true;
  depth[cur] = param_depth;
  an[cur][0] = parent;    // 2^0 조상
  for(int i=0;i<adj[cur].size();i++){
    dfs(cur, adj[cur][i], param_depth+1);
  }
}

int lca(int a, int b){
  if(depth[a] < depth[b]){
    
  }
}

int main(){
  scanf("%d%d", &N);
  for(int i=0;i<M;i++){
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
    for(int j=1;j<=n;j++){  // 1번 노드, 2번 노드, ... , n번 노드
      int tmp = an[j][i-1];
      an[j][i] = an[tmp][i-1];
    }
  }
  
  scanf("%d", &M);
  for(int i=0;i<M;i++){
    int a, b;
    scanf("%d %d", &a, &b);
  }
}
