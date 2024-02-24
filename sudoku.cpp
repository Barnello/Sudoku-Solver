#include<iostream>

using namespace std;
const int cols = 9;
const int rows= 9;

//TODO: Solve the suduko board using the solve board method
//	Create or find the ML model that can read the numbers from img
//	Use the paint tool in said application to display solution

void solveBoard(int board[rows][cols]){
	
}

void printBoard(int board[rows][cols])
{
	int count = 0;
	cout << "[ | ";
	for(int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			cout << board[i][j] << " | ";
			count++;
			if(count % 9 == 0 && count != 81){
				cout << "]\n[ | ";
			}
			else if(count %9 ==0 && count ==81){
				cout << "]\n";}
		}
	}

}

int main(int argc, char* argv[]){
	const int cols = 9;
	const int rows = 9;

	int board[rows][cols];
	
	if(argc != 1 + rows * cols) {
		cout << "Invalid number of elements. Usage:  "
			<< argv[0] << " <elem1> <elem2> ..." << endl;
		return -1;					
	}

	cout << "The current sudoku board is as follows\n";
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int index = 1 + i * cols + j;
			board[i][j] = stoi(argv[index]);
			
		}
	}

	printBoard(board);

	return 0;
}
