#include <stdio.h>
#include <math.h>

int getRound(int start, int end);
int whowin(char left, char right, int leftID, int rightID, char indicates);
int tournament(char *shapes, char *indicates, int start, int end);

int main() {
	int N;
	char shapes[1026] = "";
	char indicates[20] = "";
	scanf("%d %s %s", &N, shapes, indicates);

	printf("%d\n", tournament(shapes, indicates, 0, N - 1) + 1);
	return 0;
}

int getRound(int start, int end){
	return log2(end-start+1)-1;
}

int whowin(char left, char right, int leftID, int rightID, char indicates) {
	if (left == 'r') {
		if (right == 'p') return rightID;
		if (right == 's') return leftID;
	}
	if (left == 'p') {
		if (right == 'r') return leftID;
		if (right == 's') return rightID;
	}
	if (left == 's') {
		if (right == 'r') return rightID;
		if (right == 'p') return leftID;
	}
	if(indicates == 's') return leftID;
	return rightID;
}

int tournament(char *shapes, char *indicates, int start, int end) {
	// only one player
	if (start == end){
		return start;
	}

	// only two player. In other words, this is first round
	if (end - start == 1) {
		return whowin(shapes[start], shapes[end], start, end, indicates[0]);
	}

	int left = tournament(shapes, indicates, start, (start+end-1)/2);
	int right = tournament(shapes, indicates, (start+end+1)/2, end);

	return whowin(shapes[left], shapes[right], left, right, indicates[getRound(start, end)] );
}
