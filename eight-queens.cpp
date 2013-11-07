#define __DEBUG__
#include <iostream>
#include "include/chessboard.h"
int main(int argc, char const *argv[]) {
	Chessboard chessboard;
	for (int i = 1; i <= 8; i++) {
		chessboard = Chessboard(i);
		std::cout << "size: " << i << ", count: " << chessboard.amountOfQueens() << std::endl;
	}
	return 0;
}
