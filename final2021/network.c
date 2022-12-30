#include <stdio.h>
#include <stdlib.h>

struct node {
	int id;
	struct node *next;
};

struct node *read_data(int *size);	// TODO: implement this function

void print_data(struct node *adj, int size) {
	if (!adj) {
		return;
	}
	for (int i = 0; i < size; ++i) {
		printf("%d -> ", adj[i].id);
		for (struct node *ptr = adj[i].next; ptr != NULL; ptr = ptr->next) {
			printf("%d ", ptr->id);
		}
		putchar('\n');
	}
	return;
}

void free_data(struct node *adj, int size) {
	if (!adj) {
		return;
	}
	for (int i = 0; i < size; ++i) {
		struct node *ptr = adj[i].next;
		while (ptr) {
			adj[i].next = ptr->next;
			free(ptr);
			ptr = adj[i].next;
		}
	}
	free(adj);
	return;
}

int main() {
	int size;
	struct node *adj = read_data(&size);
	if (!adj) {
		fprintf(stderr, "Error allocating memory.");
		exit(1);
	}
	print_data(adj, size);
	free_data(adj, size);
	return 0;
}

int nodeCmp(const void *a, const void *b) {
	struct node *A = (struct node *)a;
	struct node *B = (struct node *)b;
	return A->id - B->id;
}

struct node *read_data(int *size) {
	// initialize
	struct node *root = malloc(sizeof(struct node) * 1000);
	*size = 0;

	struct node *current = root;
	int val;

	while (scanf("%d ->", &val) != EOF) {
		(*size)++;
		current->id = val;
		struct node *tail = current;
		scanf("%d", &val);
		while (val != 0) {
			tail->next = malloc(sizeof(struct node));
			tail->next->id = val;
			tail = tail->next;
			scanf("%d", &val);
		}
		current++;
	}

	qsort(root, *size, sizeof(*root), nodeCmp);

	return root;
}
