#include "LZesp.h"
#include<iostream>

int main ()
{
  using namespace std;

  const LZesp first (1, 11);
  const LZesp second (2, 22);
	
  cout<<first<<"\t"<<second<<"\n";
  
  LZesp sum = first + second, product (1 + (LZesp::i*2));
  cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\n";

  const LZesp& productRef = product = sum = first*second;
  cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tproductRef: "<<productRef<<"\n";

  product *= 3;
  cout<<"After product times 3\n";
  cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tproductRef: "<<productRef<<"\n";

  LZesp result (2 - LZesp::i + first*second - (product++) + (++sum) );
  cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tresult: "<<result<<"\n";

  result[(first > result) ? LZesp::IMAGINARY : LZesp::REAL] += 3;

  cout<<"After result real plus 3\n";
  cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tresult: "<<result<<"\n";

  result[(result > first) ? LZesp::IMAGINARY : LZesp::REAL] += 3;
  cout<<"After result imaginary plus 3\n";
  cout<<"Sum: "<<sum<<"\tproduct: "<<product<<"\tresult: "<<result<<"\n";

  return 0;
}

/*
// OUTPUT: ./Lab12
1 + 11i	2 + 22i
Sum: 3 + 33i	product: 1 + 2i
Sum: -240 + 44i	product: -240 + 44i	productRef: -240 + 44i
After product times 3
Sum: -240 + 44i	product: -720 + 132i	productRef: -720 + 132i
Sum: -239 + 44i	product: -719 + 132i	result: 243 + -45i
After result real plus 3
Sum: -239 + 44i	product: -719 + 132i	result: 246 + -45i
After result imaginary plus 3
Sum: -239 + 44i	product: -719 + 132i	result: 246 + -42i
*/