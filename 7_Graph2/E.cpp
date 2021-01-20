// 11400 단절선

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
  int a, b;
};

bool compare(edge x, edge y){
  if(x.a == y.a) return x.b < y.b;
  else return x.a < y.a;
}

int V, E, cnt, num = 1;
int order[100001];
vector<int> adj[100001];
vector<edge> edge_list;

int dfs(int parent, int cur){
  if(order[cur] != 0) return order[cur];
  order[cur] = num++;
  int min_node_num = order[cur];
  
  for(int i=0;i<adj[cur].size();i++){
    int next = adj[cur][i];
    
    if(next == parent) continue;
    
    if(order[next] != 0){
      min_node_num = min(min_node_num, order[next]);
    }
    else{
      int tmp;
      tmp = dfs(cur, next);
      if(tmp > order[cur]){ // 같으면 안된다! 단절점과 다른점. 
        edge_list.push_back({min(next,cur), max(next,cur)});
      }
      
      min_node_num = min(min_node_num, tmp);
    }
  }
  
 // if(IsRoot && child_num >= 2) ans[cur] = true;
  
  return min_node_num;
}

int main(){
  scanf("%d%d", &V, &E);
  for(int i=0;i<E;i++){
    int a,b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  // 단절선 구하기
  for(int i=1;i<=V;i++){
    if(order[i] == 0)
      dfs(0, i);
  }
  
  // 출력
  sort(edge_list.begin(), edge_list.end(), compare);
  
  printf("%d\n", (int)edge_list.size());
  for(int i=0;i<edge_list.size();i++){
    printf("%d %d\n", edge_list[i].a, edge_list[i].b);
  }
}
