// 2579 계단 오르기

/*
강사님 방법
*/

#include<cstdio>

int n, step[301], max_point_1[301], max_point_2[301]; 

int getmax(int a, int b){return a>b?a:b;}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &step[i]);
  }
  
  max_point_1[1] = step[1];
  
  for(int i=2;i<=n;i++){
    // i-2에 있는 계단과 관련이 있음
    max_point_1[i] = getmax(max_point_1[i-2], max_point_2[i-2]) + step[i]; // 잘 채웠음
    
    // 관련이 있는데 i-1에 있는 계단과 관련이 있음
    max_point_2[i] = max_point_1[i-1] + step[i];
  }
  
  // 출력
  printf("%d\n", getmax(max_point_1[n], max_point_2[n]));
}


