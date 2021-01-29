// 11062 카드게임

/*
강사님 방법
*/

#include<cstdio>
#include<cstring>

int tt, n, card[1001], subsum[1001]; // subsum[i]: 1~i까지의 합
int A_dp[1001][1001], B_dp[1001][1001]; // memoization


int getsum(int s, int e){ // 카드 s부터 e까지의 합
  return subsum[e] - subsum[s-1];
}

int getmax(int a, int b){return a>b?a:b;}

int A_play(int s, int e);
int B_play(int s, int e);


int main(){
  scanf("%d", &tt);
  for(int tc=1;tc<=tt;tc++){
    memset(A_dp, 0xff, sizeof(A_dp));
    memset(B_dp, 0xff, sizeof(B_dp));
    
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
      scanf("%d", &card[i]);
      subsum[i] = subsum[i-1] + card[i];
    }

    // 출력
    printf("%d\n", A_play(1,n));
  }
}


int A_play(int s, int e){
  if(s==e) return card[s];
  
  if(A_dp[s][e] != -1){
    return A_dp[s][e];
  }
  
  int left = 0, right = 0;
  // 가장 왼쪽을 가져가거나
  // A가 카드로 얻는값: card[s]
  // B가 최선을 다해서 얻는 점수: B_play(s+1,e)
  // A가 나머지 플레이에서 얻는 점수: [s+1~e]까지의 합 - B가 최선을 다해서 얻는 점수
  left = card[s] + getsum(s+1,e) - B_play(s+1,e);
  
  // 가장 오른쪽으로 가져가거나
  // 위와 마찬가지로 해줌
  right = card[e] + getsum(s,e-1) - B_play(s,e-1);
  
  //최종 A는 left, right 중에서 큰 것을 하면 됨
  A_dp[s][e] = getmax(left, right);
  return A_dp[s][e];
}

int B_play(int s, int e){
  if(s==e) return card[s];
  
  if(B_dp[s][e] != -1){
    return B_dp[s][e];
  }
  
  int left = 0, right = 0;
  left = card[s] + getsum(s+1,e) - A_play(s+1,e);
  right = card[e] + getsum(s,e-1) - A_play(s,e-1);
  
  B_dp[s][e] = getmax(left, right);
  return B_dp[s][e];
}
