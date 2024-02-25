#include<iostream>
#include<map>

using namespace std;
const int cols = 9;
const int rows= 9;
const int N = 9;

//TODO: Solve the suduko board using the solve board method
//	Create or find the ML model that can read the numbers from img
//	Use the paint tool in said application to display solution


// Params: Board - suduko board, current row, current col, n - number to check
// Output: true the number can exist, false if it cannot
bool isSafe(int board[N][N], int row, int col, int n)
{
	// Check to see if the number is equal to n in row
	// return false if true
	for (int i = 0; i < N; i++)
		if (board[row][i] == n)
			return false;

	//Check to see if the number is equal to n in col
	//return false if true
	for (int i = 0; i < N; i++)
		if (board[i][col] == n)
			return false;

	
	//variable for stare of 3 x 3 matrix
	int rowStart = row - row % 3;
	int colStart = col - col % 3; 
	
	//Check to see if n exists in the matrix 
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[i + rowStart][j + colStart] == n)
				return false;
		}
	}

	return true;
}	

bool solveBoard(int board[N][N], int row, int col){
	if (row == N - 1 && col == N)
		return true;

	if (col == N){
		row ++;
		col = 0;
	}

	if (board[row][col] > 0)
		return solveBoard(board, row, col + 1);

	for (int num = 1; num <= N; num++){
		if(isSafe(board, row, col, num)){
			board[row][col] = num;
			if (solveBoard (board, row, col + 1))
				return true;
		}
		board[row][col] = 0;
	}
	return false;
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

	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };	
	//if(argc != 1 + rows * cols) {
	//	cout << "Invalid number of elements. Usage:  "
	//		<< argv[0] << " <elem1> <elem2> ..." << endl;
	//	return -1;					
	//}

	

//	cout << "The current sudoku board is as follows\n";
	//for(int i = 0; i < rows; i++){
	//	for(int j = 0; j < cols; j++){
	//		int index = 1 + i * cols + j;
	//		board[i][j] = stoi(argv[index]);
			
	//	}
	//}

	
	if (solveBoard(grid, 0, 0))
		printBoard(grid);
	else {
		cout << "No solution for this board exists" << endl;
	}

	return 0;
}
