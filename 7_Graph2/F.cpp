// 할로윈
/*
강사님 힌트
*/

#include<cstdio>
#include<vector>
using namespace std;

#define INF 9000001

struct Info{
  int y2, x2, t;
};

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int W, H, G, E, no_path_cnt;
long long cost[30][30];
bool no_path[30][30], IsNever;
vector<Info> adj[30][30];

void bell(){
  cost[0][0] = 0; // 시작점 초기화
  for(int i=0;i<W*H-no_path_cnt-1;i++){
    for(int row=0;row<H;row++){
      for(int col=0;col<W;col++){
        
        if(row == H-1 && col == W-1) continue; // 문제에서 도착지이면 수행 x
        if(no_path[row][col]) continue; // 묘지이므로 수행 x
      
        if(adj[row][col].size() == 0){ // 그냥 길
          for(int j=0;j<4;j++){
            int ny = dy[j] + row;
            int nx = dx[j] + col;
            
            if(ny < 0 || ny >= H || nx < 0 || nx >= W || no_path[ny][nx]) continue;
            
            int new_cost = cost[row][col] + 1;
            if(cost[row][col] != INF && cost[ny][nx] > new_cost)
              cost[ny][nx] = new_cost;
          }
        }
        else{ // 구멍
          for(int j=0;j<adj[row][col].size();j++){
            int ny = adj[row][col][j].y2;
            int nx = adj[row][col][j].x2;
            int nt = adj[row][col][j].t;
            
            if(ny < 0 || ny >= H || nx < 0 || nx >= W || no_path[ny][nx]) continue;
            
            int new_cost = cost[row][col] + nt;
            if(cost[row][col] != INF && cost[ny][nx] > new_cost)
              cost[ny][nx] = new_cost;
          }
        }
      }
    }
  }
  
  //Never check
  for(int row=0;row<H;row++){
    for(int col=0;col<W;col++){
    
      if(row == H-1 && col == W-1) continue;
    
      if(adj[row][col].size() == 0){
        for(int j=0;j<4;j++){
          int ny = dy[j] + row;
          int nx = dx[j] + col;
            
          if(ny < 0 || ny >= H || nx < 0 || nx >= W || no_path[ny][nx]) continue;
            
          int new_cost = cost[row][col] + 1;
          if(cost[row][col] != INF && cost[ny][nx] > new_cost){
            IsNever = true; return;
          }
        }
      }
      else{
        for(int j=0;j<adj[row][col].size();j++){
          int ny = adj[row][col][j].y2;
          int nx = adj[row][col][j].x2;
          int nt = adj[row][col][j].t;
          
          if(ny < 0 || ny >= H || nx < 0 || nx >= W || no_path[ny][nx]) continue;
          
          int new_cost = cost[row][col] + nt;
          if(cost[row][col] != INF && cost[ny][nx] > new_cost){
            IsNever = true; return;
          }
        }
      }
    }
  }
}

int main(){
  while(true){
    
    scanf("%d%d", &W, &H);
    
    if(W == 0 && H == 0) break;
    
    // 초기화
    for(int i=0;i<H;i++)
      for(int j=0;j<W;j++){
        cost[i][j] = INF;
        adj[i][j].clear();
        no_path_cnt = 0;
        no_path[i][j] = false;
        IsNever = false;
      }
    
    // 입력
    scanf("%d", &G);
    for(int i=0;i<G;i++){
      int x, y;
      scanf("%d%d", &x, &y);
      
      no_path[y][x] = true;
      no_path_cnt++;
    }
    
    scanf("%d", &E);
    for(int i=0;i<E;i++){
      int x1,y1,x2,y2,t;
      scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &t);
      
      adj[y1][x1].push_back({y2, x2, t});
    }
    
    // 최소 시간 구하기
    bell();
    
    // 출력
    if(IsNever) printf("Never\n");
    else if(cost[H-1][W-1] == INF) printf("Impossible\n");
    else printf("%lld\n", cost[H-1][W-1]);
  }
}
