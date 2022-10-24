#include <stdio.h>

int main() {
	int bingoTable[8][8] = {{}};
	int bingo[8][8] = {{}};
	int hostN = 0;
	int N = 0;
	int flag = 1;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%d", &bingoTable[i][j]);
		}
	}

	for (int k = 0; k < 64; k++) {
		scanf("%d", &hostN);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (bingoTable[i][j] == hostN) {
					bingo[i][j] = 1;
				}
			}
		}
	}

	// horizen
	for(int i = 0; i < 8; i++){
		flag = 1;
		for(int j = 0; j < 8; j++){
			if(bingo[i][j] == 0){
				flag = 0;
				break;
			}
		}
		N += flag;
	}

	// vertical
	for(int i = 0; i < 8; i++){
		flag = 1;
		for(int j = 0; j < 8; j++){
			if(bingo[j][i] == 0){
				flag = 0;
				break;
			}
		}
		N += flag;
	}

	// diagonal
	flag = 1;
	for(int i = 0; i < 8; i++){
		if(bingo[i][i] == 0) {
			flag = 0;
			break;
		}
	}
	N += flag;
	
	flag = 1;
	for(int i = 0; i < 8; i++){
		if(bingo[i][8-i] == 0) {
			flag = 0;
			break;
		}
	}
	N += flag;
	
	printf("%d\n", N);

	return 0;
}
