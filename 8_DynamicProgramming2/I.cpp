// 1102 발전소

/*
강사님 방법

비트 마스킹
*/

#include<cstdio>

#define INF 10000

int n, cost[16][16], p;
int dp[(1<<16)]; // 상태를 만들기 위한 최소비용
bool onoff[16];
char buf[20];

int bitcount(int x){
  int count = 0;
  while(x){
    if(x&1) count++;
    x/=2;
  }
  return count;
}

int bit_check(int b, int pos){
  return b & (1<<pos);
}

int bit_set(int b, int pos){
  return b | (1<<pos);
}

int main(){
  //printf("%d\n", bitcount(8));
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      // i를 이용해서 j를 켤때의 값
      scanf("%d", &cost[i][j]);
    }
  }
  scanf("%s", buf);
  for(int i=0;buf[i];i++){
    if(buf[i] == 'Y') onoff[i] = true;
  }
  scanf("%d", &p);
  for(int i=0;i<(1<<16);i++) dp[i] = INF;
  
  // 최초 시작은 어떻게 진행해야 할까?
  // 힌트는 최초에 켜져있는 발전소를 아니까, 상태를 만들어서, 그 상태의 dp[] = 0으로....
  int first_state = 0;
  for(int i=0;i<n;i++){
    if(onoff[i]){
      first_state = bit_set(first_state, i);
    }
  }
  dp[first_state] = 0;
  
  // 시작 (핵심 코드)
  for(int state = 0; state<(1<<n); state++){
    for(int i=0;i<n;i++){
      // state인 상태에서 i 발전소를 켤 수 있을까??
      // 켜게되면 비용은 어떻게 될까?
      // 그때 state는 어떤 모양일까?: next_state
      // next_state에는 어떤 값이 있었을까??
      int next_state, next_cost;
      if(bit_check(state, i)){ // state: 발전소가 켜져있는것, i가 있다는 것은 이미 켜져있는것
        continue;
      }
      next_state = bit_set(state, i);
      for(int j=0;j<n;j++){
        if(bit_check(state, j)){
          next_cost = dp[state] + cost[j][i];
          if(next_cost < dp[next_state]){
            dp[next_state] = next_cost;
          }
        }
      }
    }
  }
  
  // 답을 출력할때는 p를 고려해서 p보다 큰가를 본다
  int ans = INF;
  for(int i=0;i<(1<<n);i++){
    if(bitcount(i) >= p){
      if(dp[i] < ans) ans = dp[i];
    }
  }
  
  if(ans == INF) printf("-1\n");
  else printf("%d\n", ans);
}
