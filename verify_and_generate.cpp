#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;
                //ABCDEFGHJKUVXYWZIO
string SYMBOLS = "ABCDEFGHJKLMNPQRSTUVXYWZIO";
int sum;
int count = 1;
string userinput, output ;
string save; //10個元素

//將輸入的身分證通通變成數字
 string coverToInt (string userinput)
 {
  int letter_value;
  letter_value = SYMBOLS.find(userinput.substr(0,1),0) + 10;
  userinput.erase(0,1); //移除字母
  userinput.insert(0, to_string(letter_value));//將數字插入
  return userinput;  //userinput = 15123456789
 }

//通通變成數字的身分證 前10碼加起來
int operation(string userinput)
{
  for(int i = 9; i >= 1; i--)
  {
    //從第2位(索引值1)、長度為1開始乘
    sum += stoi(userinput.substr(count,1)) * i;
    count++;
  }
  sum += stoi(userinput.substr(0,1));//加上字母的十位數 (只剩最後一碼沒加)
 return sum;
}

//前十碼的值除10做判斷真偽
string judge()
{
  int check = 10 - (sum % 10); //算出檢查碼
  if(check == stoi(userinput.substr(10,1)))//若檢查碼等於最後一碼
      output = "Valid ID";//正確ID
  else
      output = "Invalid ID";//偽ID
  return output;
}


string generateID()
{
    mt19937 generator; //亂數產生器引擎。
    generator.seed(time(0));
    uniform_int_distribution<uint32_t> letter(0,25);
    uniform_int_distribution<uint32_t> gender(1,2);//性別亂數分布
    uniform_int_distribution<uint32_t> num(0,9);//編號1~7分布

    string getLetter = SYMBOLS.substr(letter(generator),1);//隨機產生字母 A~Z
    save += getLetter ;
    save += to_string(gender(generator));             //亂數產生性別碼 1~2

    for(int i = 1; i<=7; i++ )
    {
      save += to_string(num(generator));            //亂數產生 0~9。F12345678
    }
    save = coverToInt(save);                         //1512345678(字母轉成數字)
    operation(save);                                //10個數字總和
    save += to_string(10 - (sum % 10));             //算出檢查碼並存入save
    save.erase(0,2);                                //移除最前面兩數字。
    save.insert(0, getLetter);                      //將字母插入

  return save;
}


int main()
{
    cout << "Enter your ID or generate ID " << endl;
    cin >> userinput;
    //判斷要驗證還是產生ID
    if(userinput =="g" or userinput == "generate")
      cout<<generateID()<<endl;
    else
    {
      userinput = coverToInt(userinput);// 15123456789(處理後的身分證)
      operation(userinput);      //算出前10碼總和
      cout<< judge() <<endl;     //丟入該函示判斷 真or偽
    }
  system("pause");
  return 0;
}
