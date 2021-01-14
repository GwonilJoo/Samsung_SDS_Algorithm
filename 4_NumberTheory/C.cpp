// 3955 캔디 분배

#include<iostream>
using namespace std;

// ax+by=c -> as+bt=r 을 만족하는 s,t,r 조합 찾기(r이 gcd(a,b)일때)

void eGcd(int a, int b){
  int s0 = 1, t0 = 0, r0 = a;
  int s1 = 0, t1 = 1, r1 = b;
  
  int temp;
  while(r1 != 0){
    int q = r0 / r1;
    
    temp = r0 - q * r1; // 새로운 r
    r0 = r1;
    r1 = temp;
    
    temp = s0 - q * s1;
    s0 = s1;
    s1 = temp;
    
    temp = t0 - q * t1;
    t0 = t1;
    t1 = temp;
  }
  
  cout << s0 << " " << t0 << " " << r0 << endl;
}

int main(){
  eGcd(71,240);
  
  // x: 인당 나눠줄 사람의 수
  // y: 사탕 봉지의 수
  // A * x + 1 = B * y
  // -> A*(-x) + B*y = 1
  
  // A, B 입력
  
  // D = gcd(A,B)
  // C = D*K --> C%D == 0 이어야만 해를 가질 수 있다 : 배주 항등식
  
  // 확장유클리드 호제법을 이용하여 s,t, r(=D)을 찾아냄
  
  // x0 = s * C/D
  // y0 = t * C/D
  
  // 일반 해 공식
  // 주의 위의 k와 다름
  // x = x0 + B/D * k
  // y = y0 - A/D * k
  
  // x < 0 (위에서 방정식을 세울 때 x를 음수로 치환했기 때문)
  // x0 + B/D * k < 0
  // k < -x0 / B*D
  
  // 0 < y <= 1e9
  // 0 < y0 - A/D * k <= 1e9
  
  // (y0-1e9)/A*D <= k < y0/A*D
  //                k < -x0 / B*D
  
  // k의 max를 구한 후 그 k를 이용해서 y값을 구한다. -> k가 커지면 y가 작아지므로
  // 그렇게 구한 y는 가장 작은 y값.
  // 구한 y값이 1e9보다 작거나 같으면 가능한 답. 아니면 불가능한 답
  
}
