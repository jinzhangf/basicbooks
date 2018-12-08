#include "base.h"


bool isExistedSub(vector<vector<int>> matrix, int target, 
	int start_row, int end_row, 
	int start_col, int end_col)
{
	if (start_row < end_row || start_col < end_col) {
		return false;
	}

	int mid_row = (start_row + end_row) / 2;
	int mid_col = (start_col + end_col) / 2;
	int a = matrix[mid_row][start_col];
	int b = matrix[mid_row][end_col];
	int c = matrix[mid_row][mid_col];

	if (target == a || target == b || target == c) {
		return true;
	}
	else if (target < a) {
		return isExistedSub(matrix, target, mid_row + 1, end_row, start_col, end_col);
	}
	else if (target > b) {
		return isExistedSub(matrix, target, start_row, mid_row - 1, start_col, end_col);
	}
	else if (target < c) {
		return isExistedSub(matrix, target, start_row, mid_row, start_col, mid_col - 1)
			|| isExistedSub(matrix, target, mid_row, end_row, start_col + 1, mid_col)
			|| isExistedSub(matrix, target, mid_row + 1, end_row, mid_col, end_col - 1);
	}
	else if (target > c) {
		return isExistedSub(matrix, target, start_row, mid_row + 1, start_col, end_col)
			|| isExistedSub(matrix, target, start_row, mid_row, mid_col, end_col - 1)
			|| isExistedSub(matrix, target, mid_row, end_row, mid_col + 1, end_col);
	}

	// 不会走到这里
	return false;
}

bool isExisted(vector<vector<int>> matrix, int target)
{
	if (matrix.empty() || matrix[0].empty())
		return false;

	int row = matrix.size();
	int col = matrix[0].size();
	return isExistedSub(matrix, target, 0, row - 1, 0, col - 1);
}

int main()
{
	return 0;
}