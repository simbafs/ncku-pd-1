#include <math.h>
#include <stdio.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]);
void print_M(unsigned int mask[][MAX_SIZE]);
void print_Y(unsigned int mask[][MAX_SIZE]);
void print_K(unsigned int mask[][MAX_SIZE]);
void CMYK_to_RGB();

int main() {
	// Get the dimension of the image.
	scanf("%u %u", &W, &H);

	// Declare the mask for single ink color.
	unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

	// For each layer, do the following:
	for (int layer = 0; layer < 4; ++layer) {
		// Get color mask.
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				scanf("%u", &mask[i][j]);
			}
		}

		// Print a layer of that color to the paper.
		switch (layers[layer]) {
			case 'C':
				print_C(mask);
				break;
			case 'M':
				print_M(mask);
				break;
			case 'Y':
				print_Y(mask);
				break;
			case 'K':
				print_K(mask);
				break;
		}
	}

	// Convert CMYK color to RGB color.
	CMYK_to_RGB();

	// Show the final result.
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			printf("#%06x ", image[i][j]);
		}
		printf("\n");
	}

	return 0;
}

double RGB[3][MAX_SIZE][MAX_SIZE] = {{{}}};

void print_C(unsigned int mask[][MAX_SIZE]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			RGB[0][i][j] = 255 * (100 - mask[i][j]) / 100.0;
		}
	}
}

void print_M(unsigned int mask[][MAX_SIZE]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			RGB[1][i][j] = 255 * (100 - mask[i][j]) / 100.0;
		}
	}
}

void print_Y(unsigned int mask[][MAX_SIZE]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			RGB[2][i][j] = 255 * (100 - mask[i][j]) / 100.0;
		}
	}
}

void print_K(unsigned int mask[][MAX_SIZE]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < 3; k++) {
				RGB[k][i][j] *= (100 - mask[i][j]) / 100.0;
			}
		}
	}
}

void CMYK_to_RGB() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < 3; k++) {
				image[i][j] |= lround(RGB[k][i][j]) << 8 * (2 - k);
			}
		}
	}
}
