// 1072 게임

/*
이진탐색
lower bound: 원하는 k값 이상이 처음 나오는 위치		-> O(lgN)
upper bound: 원하는 k값을 초과한 값이 처음 나오는 위치	-> O(lgN)

upper bound - lower bound = k값의 빈도수. k값의 개수를 알 수 있다.	-> 2*O(lgN)

이 문제는 upper bound를 구하는 문제!
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long X, Y, Z;

long long calc(long long n){
  return ((Y+n)*100)/(X+n);
}

long long upper_bound(){
  if(Z == 99 || Z == 100)
    return -1;
    
  long long left = 1, right = X, mid;
  
  // 전형적인 upper bound 알고리즘 형태
  while(left < right){
    mid = (left+right)/2;
    long long res = calc(mid);
    
    if(res <= Z){
      left = mid+1;
    }
    else{
      right = mid; // mid값 살려야 한다.
    }
  }
  
  return right;
}

int main(){
  cin >> X >> Y;
  Z = calc(0);
  
  cout << upper_bound() << endl;
}
