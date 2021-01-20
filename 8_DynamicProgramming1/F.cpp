// 11049 행렬 곱셈 순서

/*
강사님 방법

행렬을 크게 두 부분으로 나누면.... A x B = C 형태가 된다
최소로 하는 것이 무엇인지 찾기
A와 B 또한 각각 크게 나누어서 최소가 되는 것을 찾는다.

재귀적으로 호출!

그런데 재귀적으로 호출한다면 시간초과 발생
-> 메모이제이션으로 해결하기!

dp 하면서 메모리 초과 문제는 트릭을 사용해서 푸는 것. 필요없는 것들 저장 안한다든지 등등....
이건 아직 안가르쳐주심.
*/

#include<cstdio>

struct Info{
  int r, c;
  Info() {}
};

int N, dp[510][510];
Info mat[510];

int getmin(int a, int b){return a<b?a:b;}

// 행렬의 s부터 e까지 계산을 해서 최적의 값을 내는 함수
int calc(int s, int e){
  if(e-s == 1){
    return mat[s].r * mat[s].c * mat[e].c;
  }
  if(e == s){
    return 0;
  }
  
  // 적절한 처리를 해서 계산량 줄이기
  // calc(s,e)를 처음으로 계산한 적이 있으면, 그때 계산했던 결과를 사용
  if(dp[s][e] != 0){
    return dp[s][e];
  }
  
  // 계산한 적이 없으므로 계산
  // 부분으로 다 나눠서 괜찮은 값을 구하기
  int mn = -1;
  for(int mid = s ; mid < e ; mid++){
    if(dp[s][mid] == 0) dp[s][mid] = calc(s,mid);
    if(dp[mid+1][e] == 0) dp[mid+1][e] = calc(mid+1, e);
    
    int tmp = dp[s][mid] + dp[mid+1][e] + mat[s].r * mat[mid].c * mat[e].c; // 그림 그려보자
    if(mn == -1 || tmp < mn) mn = tmp;
  }
  
  // 처음으로 계산했기 때문에 계산 결과를 저장함.
  dp[s][e] = mn;
  
  return mn;
}

int main(){
  scanf("%d", &N);
  for(int i=1;i<=N;i++){
    scanf("%d%d", &mat[i].r, &mat[i].c);
  }
  printf("%d\n", calc(1,N));
}

