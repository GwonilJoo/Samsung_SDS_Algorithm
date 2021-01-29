// 5626 제단

/*
강사님 방법
*/

#include<cstdio>
#include<cstring>

#define MOD 1000000007
#define INVALID -1

int n, h[10001];
int dp[10001][5001]; // [i][j] i번째 제단까지 진행을 했을 때 높이가 j인 경우의 수
//int dp[2][5001], prev = 0, cur = 1; // 메모리 줄이는 방법

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &h[i]);
  }
  
  // 양쪽 끝 비교 0 아니면 -> 0
  if(h[1] > 0 || h[n] > 0){
    printf("0\n"); return 0;
  }
  
//  /*
  // 방법1
  // 가장 높은 높이 비교-->실패 
  // 초기화
  memset(dp, 0x00, sizeof(dp));
  dp[1][0] = 1;
  
  // i번째 제단에서 가능한 높이 경우의 수를 넣는다.
  for(int i=2;i<=n;i++){
    // i번째 제단이 j의 높이를 갖는 경우의 수
    if(h[i] != -1){
      int j = h[i];
      if(j-1>=0){
        dp[i][j] += dp[i-1][j-1], dp[i][j] %= MOD;
      }
      
      dp[i][j] += dp[i-1][j], dp[i][j] %= MOD; 
      
      if(j+1 <= 5000){
        dp[i][j] += dp[i-1][j+1], dp[i][j] %= MOD;
      }
    }
    else{
      for(int j=0;j<=n/2;j++){
        // j-->이전의 높이가 j+1, j ,j-1 합쳐지는 경우의 수
        if(j-1 >=0){
          dp[i][j] += dp[i-1][j-1], dp[i][j] %= MOD;
        }
        
        dp[i][j] += dp[i-1][j], dp[i][j] %= MOD; 
        
        if(j+1 <= 5000){
          dp[i][j] += dp[i-1][j+1], dp[i][j] %= MOD;
        }
      }
    } 
  } 
  
  printf("%d\n", dp[n][0]);
//  */
  /*
  // 방법2. 메모리 줄이는 방법
  memset(dp, 0x00, sizeof(dp));
  dp[prev][0] = 1;
  
  // i번째 제단에서 가능한 높이 경우의 수를 넣는다.
  for(int i=2;i<=n;i++){
    // dp[cur][xxxx]
    int st= 0, ed = n/2;
    
    // cur 메모리 초기화
    for(int j=0;j<=5000;j++){
      dp[cur][j] = 0;
    }
    
    if(h[i] != -1){
      st = h[i], ed = h[i];
    }
    
    for(int j=st;j<=ed;j++){
      if(j-1>=0){
        dp[cur][j] += dp[prev][j-1];
        dp[cur][j] %= MOD;
      }
      
      dp[cur][j] += dp[prev][j];
      dp[cur][j] %= MOD;
      
      if(j+1 <= 5000){
        dp[cur][j] += dp[prev][j+1];
        dp[cur][j] %= MOD;
      }
    }
    
    // prev와 cur 바꿔줌
    prev = (prev==1) ? 0 : 1; 
    cur = (cur==1) ? 0 : 1;
  } 
  
  printf("%d\n", dp[prev][0]);
  */
}
