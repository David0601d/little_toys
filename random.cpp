#include <iostream>
#include <random>
#include <ctime>
using namespace std; //std意思是standard
int main(){
  /* 梅森旋轉演算法 */
  mt19937 generator; //亂數產生器引擎。「計算」出一連串類似隨機的亂數
  generator.seed(time(0));
  uniform_int_distribution<uint32_t> dice(0,2);//分布
  int rnd ;

  for(int i =0; i<10; i++ )
  {
    rnd = dice(generator);
    cout << rnd << endl;
  }

  return 0;
}
