#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

void enqueue(prio_queue_t *const queue, int value, int weight);
node_t *dequeue(prio_queue_t *const queue);
void print_nodes(const prio_queue_t *const queue);

int main() {
	int N;
	scanf("%d", &N);
	prio_queue_t queue = {
		.head = NULL,
	};
	for (int i = 0; i < N; i++) {
		char op[8];
		scanf("%s", op);
		if (!strcmp(op, "ENQUEUE")) {
			int v, w;
			scanf("%d%d", &v, &w);
			enqueue(&queue, v, w);
		} else if (!strcmp(op, "DEQUEUE")) {
			free(dequeue(&queue));
		}
		print_nodes(&queue);
	}
	return 0;
}

void print_nodes(const prio_queue_t *const queue) {
	if (!queue->head) {
		printf("EMPTY\n");
		return;
	}
	for (node_t *node = queue->head; node; node = node->next) {
		printf(" -> %d(%d)", node->value, node->weight);
	}
	printf("\n");
	return;
}

node_t *newNode(int value, int weight) {
	node_t *node = malloc(sizeof(node_t));
	node->value = value;
	node->weight = weight;
	return node;
}

void enqueue(prio_queue_t *const queue, int value, int weight) {
	if (queue->head == NULL) {
		queue->head = newNode(value, weight);
		return;
	}
	for (node_t *cur = queue->head; cur != NULL; cur = cur->next) {
		node_t *tmp = newNode(value, weight);
		if (cur->weight > weight) {
			tmp->next = cur;
			queue->head = tmp;
			break;
		}
		if (cur->next == NULL) {
			cur->next = newNode(value, weight);
			break;
		}
		if (cur->next->weight > weight) {
			node_t *tmp = newNode(value, weight);
			tmp->next = cur->next;
			cur->next = tmp;
			break;
		}
	}
}

node_t *dequeue(prio_queue_t *const queue) {
	node_t *head = queue->head;
	if (head == NULL) return NULL;
	queue->head = head->next;
	return head;
}
