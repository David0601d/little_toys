#include <iostream>
#include <string>
#include <random>
using namespace std;
                //ABCDEFGHJKUVXYWZIO
string SYMBOLS = "ABCDEFGHJKLMNPQRSTUVXYWZIO";
int letter_value, count = 1, sum;
string input ;


//將字串處理(取得該字母並對應到該數字)
 string dealInput ()
 {
  //若開頭是F 從SYMBOLS裡找F，發現他在索引值5
  letter_value = SYMBOLS.find(input.substr(0,1),0) + 10;
  input.erase(0,1); //移除字母
  input.insert(0, to_string(letter_value));//將數字插入
  return input;  //input = 15123456789
 }

//11碼數字加總
int operation()
{
  //input = 15123456789
  for(int i = 9; i >= 1; i--)
  {
    //從第2位(索引值1)、長度為1開始乘
    sum += stoi(input.substr(count,1)) * i;
    count++;
  }       //第一位數字            +     最後一位數字
  sum += stoi(input.substr(0,1)) + stoi(input.substr(10,1));
  return sum ;
}


int main()
{
    //使用者輸入
    cout << "Please input your ID number" << endl;
    cin >> input;//F123456789(一開始的身分證)
    input = dealInput();// 15123456789(處理後的身分證)
    sum = operation(); //數字乘積和

    if (sum % 10 ==0)
     cout << "True" << endl;
    else
      cout << "False" << endl;

  return 0;
}
