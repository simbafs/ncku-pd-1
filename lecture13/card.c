#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *pre;
	struct node *next;
};

int main() {
	struct node *head = NULL;
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		struct node *tmp = malloc(sizeof(struct node));
		tmp->val = i;
		if (head == NULL) {
			tmp->next = tmp->pre = tmp;
			head = tmp;
		} else {
			tmp->next = head->next;
			head->next->pre = tmp;

			head->next = tmp;
			tmp->pre = head;
			head = tmp;
		}
	}
	head = head->next;

	for(int i = 0; i < m; i++){
		struct node *cur = head;
		printf("%d ", head->val);
		head->next->pre = head->pre;
		head->pre->next = head->next;
		head = head->next->next;
		free(cur);
	}

	return 0;
}
