#include<cstdio>
#include<vector>
using namespace std;

int parent[18][100001];
vector<int> adj[100001];
int n, m;

int main(){
  scanf("%d", &n);
  for(int i=0;i<n-1;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(a);
    adj[b].push_back(b);
  }
  
  scanf("%d", &m);
  for(int i=0;i<m;i++){
    int a, b;
    
  }
}
