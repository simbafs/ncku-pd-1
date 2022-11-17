#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void) {
	int grid[NUM][NUM];	 // sudoku puzzle
	for (int i = 0; i < NUM; ++i) {
		for (int j = 0; j < NUM; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}
	check_sudoku(grid);
	return 0;
}

int resultRrid[9][9] = {{0}};

int checkCache[9] = {};
void resetCheck() {
	for (int i = 0; i < 9; i++) {
		checkCache[i] = 0;
	}
}

// WARNING: this function has side effects
// return how many times does the number appear
int checkrow(int row, int column, int (*grid_p)[NUM]) {
	int n = grid_p[row][column];
	if (checkCache[n - 1]) {
		//  printf("[%d %d](%d) -> %d\n", row, column, n, checkCache[n]);
		return checkCache[n - 1];
	} else {
		checkCache[n - 1]++;
		return 0;
	}
}

void check_sudoku(int (*grid_p)[NUM]) {
	// row
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
			// if first find some number duplicated, mark all
			if (checkrow(i, j, grid_p) == 1) {
				//  printf("[%d, %d] = %d\n", i, j, grid_p[i][j]);
				for (int k = 0; k < 9; k++) {
					if (grid_p[i][k] == grid_p[i][j]) {
						resultRrid[i][k] = 1;
					}
				}
			}
		}
		resetCheck();
	}
	//  for (int i = 0; i < NUM; i++) {
	//      for (int j = 0; j < NUM; j++) {
	//          printf("%d ", resultRrid[i][j]);
	//      }
	//      printf("\n");
	//  }
	//  printf("\n");

	// column
	for (int j = 0; j < NUM; j++) {
		for (int i = 0; i < NUM; i++) {
			// if first find some number duplicated, mark all
			if (checkrow(i, j, grid_p) == 1) {
				for (int k = 0; k < 9; k++) {
					if (grid_p[k][j] == grid_p[i][j]) {
						resultRrid[k][j] = 1;
					}
				}
			}
		}
		resetCheck();
	}
	//  for (int i = 0; i < NUM; i++) {
	//      for (int j = 0; j < NUM; j++) {
	//          printf("%d ", resultRrid[i][j]);
	//      }
	//      printf("\n");
	//  }
	//  printf("\n");

	// block
	for (int b = 0; b < 9; b++) {
		//  printf("> %d %d\n", (b % 3) * 3, (b / 3) * 3);
		for (int i = (b % 3) * 3; i < (b % 3) * 3 + 3; i++) {
			for (int j = (b / 3) * 3; j < (b / 3) * 3 + 3; j++) {
				//  printf("%d %d\n", i, j);
				//  if first find some number duplicated, mark all
				if (checkrow(i, j, grid_p) == 1) {
					for (int l = (b % 3) * 3; l < (b % 3) * 3 + 3; l++) {
						for (int m = (b / 3) * 3; m < (b / 3) * 3 + 3; m++) {
							//  printf("[%d %d](%d) == [%d %d](%d)\n", i, j,
							//  grid_p[i][j], l, m, grid_p[l][m]);
							if (grid_p[l][m] == grid_p[i][j]) {
								resultRrid[l][m] = 1;
							}
						}
					}
				}
			}
		}
		resetCheck();
	}

	//  for (int i = 0; i < NUM; i++) {
	//      for (int j = 0; j < NUM; j++) {
	//          printf("%d ", resultRrid[i][j]);
	//      }
	//      printf("\n");
	//  }
	//  printf("\n");
	
	for (int i = 0; i < NUM; i++) {
		for (int j = 0; j < NUM; j++) {
			if(resultRrid[i][j]){
				printf("(%d,%d)\n", i, j);
			}
		}
	}
}
