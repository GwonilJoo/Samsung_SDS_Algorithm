// 2342 Dance Dance Revolution

/*
강사님 방법
*/

#include<cstdio>

#define INF 8000000

int n, step[100005], power[5][5];
int dp[100001][5][5]; //[DDR의 단계][왼발의 위치][오른발의 위치] 일때까지 소모한 최소의 힘

int main(){
  // 중앙에서 이동
  for(int i=1;i<=4;i++){
    power[0][i] = 2;
  }
  
  // 중앙이 아닌 곳에서 근처 이동
  power[1][2] = power[1][4] = 3;
  power[2][1] = power[2][3] = 3;
  power[3][2] = power[3][4] = 3;
  power[4][1] = power[4][3] = 3;
  
  // 반대편
  power[1][3] = power[2][4] = power[3][1] = power[4][2] = 4;
  
  // 같은 곳
  for(int i=1;i<=4;i++){
    power[i][i] = 1;
  }
  
  
  // 입력
  while(true){
    scanf("%d", &step[n+1]);
    if(step[n+1] == 0) break;
    n++;
  }   
  
  // 입력 확인
  /*
  for(int i=1;i<=n;i++) printf("%d ", step[i]);
  printf("\n");
  */
  
  // 초기화
  for(int i=0;i<100001;i++){
    for(int l=0;l<=4;l++){
      for(int r=0;r<=4;r++){
        dp[i][l][r] = INF;
      }
    }
  }
  dp[0][0][0] = 0;
  
  
  // 단계를 진행해보자
  for(int i=0;i<n;i++){
    // 할일은 <i>단계의 결과는 잘 끝냈고, <i+1>단계로 가고 싶음.
    // 내가 밟아야할 DDR의 번호는 i+1을 예정임.
    for(int l=0;l<=4;l++){
      for(int r=0;r<=4;r++){
        int ddr = step[i+1], used_power;
        // dp[i][l][r]: i단계일때 왼발 l, 오른발 r일때 소모한 힘
        
        // 처리할 것들.... 같은 위치는 안됨!
        // ddr == r, l == ddr
        // 가장 작은 힘일때만 넣고 싶음
        
        // 왼발을 움직여봄 -> dp[i+1][step[i+1]][r]
        used_power = dp[i][l][r] + power[l][ddr];
        if(r != ddr && used_power < dp[i+1][ddr][r]){
          dp[i+1][ddr][r] = used_power;
        }
        
        // 오른발을 움직여봄 -> dp[i+1][l][ddr]
        used_power = dp[i][l][r] + power[r][ddr];
        if(l != ddr && used_power < dp[i+1][l][ddr]){
          dp[i+1][l][ddr] = used_power;
        }

      }
    }
  }
  
  // 출력... n단계까지 왔을 때 많은 발의 상태가 있을텐데, 그 중 가장 작은값
  int ans = INF;
  for(int l=0;l<=4;l++){
    for(int r=0;r<=4;r++){
      if(dp[n][l][r] < ans){
        ans = dp[n][l][r];
      }
    }
  }
  printf("%d\n", ans);
}
