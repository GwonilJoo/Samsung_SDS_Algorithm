// 3055 탈출

#include<iostream>
#include<queue>
using namespace std;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

struct pos{
  int y; int x; char type;
};

int R, C;
char map[50][50];
int dp[50][50];
bool visited[50][50];
queue<pos> q;

void init(){
  cin >> R >> C;
  
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++){
      cin >> map[i][j];
      if(map[i][j] == '*'){
        q.push({i,j, '*'});
      }
    }
    
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++){
      if(map[i][j] == 'S'){
        q.push({i,j, 'S'});
        return;
      }
    }
}

void show(){
  cout << "------------------------" << endl;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout << map[i][j];
    }
    cout << endl;
  }
  cout << endl;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout << dp[i][j];
    }
    cout << endl;
  }
  cout << "------------------------" << endl;
  cout << endl;
}

bool bfs(){
  while(!q.empty()){
    // 1. 큐에서 꺼내오기
    pos cur = q.front();
    q.pop();
    
    //show();
    
    
    // 2. 목적지인가?
    if(map[cur.y][cur.x] == 'D'){
      cout << dp[cur.y][cur.x] << endl;
      return true;
    }
    // 3. 갈 수 있는 곳을 순회
    for(int i=0;i<4;i++){
      int next_y = cur.y + dy[i];
      int next_x = cur.x + dx[i];
      
      // 4. 갈 수 있는가?
      if(next_y < 0 || next_y >= R || next_x < 0 || next_x >= C || map[next_y][next_x] == 'X' || map[next_y][next_x] == '*')
        continue;
      
      if(cur.type == '*' && map[next_y][next_x] != 'D'){ // 물
        // 5. 체크인
        map[next_y][next_x] = '*';
        // 6. 큐에 넣음
        q.push({next_y, next_x, '*'});
      }
      else if(cur.type == 'S' && dp[next_y][next_x] == 0){ // 고슴도치
        // 5. 체크인
        dp[next_y][next_x] = dp[cur.y][cur.x]+1;
        // 6. 큐에 넣음
        q.push({next_y, next_x, 'S'});
      }
    } 
  }
  
  return false;
}

int main(){
  init();
  if(!bfs()) cout << "KAKTUS\n";
}
