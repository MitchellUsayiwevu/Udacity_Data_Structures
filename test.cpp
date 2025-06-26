//
// Created by diso on 6/9/25.
//

#include <vector>
#include <cmath>
#include <iostream>


int summingSquares(int n, std::vector<int> perfect_squares){
  // base case at zero
  if(n==0){
    return 0;
  }

  int min_num = 0;
  //for(int i=1; i<=sqrt(n); i++){
  for(int num: perfect_squares){
	if (num>n){
		break;
	}
    //int squares = 1 + summingSquares((n-(i*i)), perfect_squares);
    int squares = 1 + summingSquares((n-num), perfect_squares);
    if(min_num == 0 || squares<min_num){
      min_num = squares;
    }
  }

  return min_num;

}

int summingSquares(int n) {
  // todo

  std::vector<int>perfect_squares;

  for(int i=1; i<=sqrt(n); i++){
    perfect_squares.push_back(i*i);
  }

  return summingSquares(n, perfect_squares);

}


int main() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it


std::cout << summingSquares(8) << std::endl;
return 0;
}
