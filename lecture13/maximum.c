#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void MoveToTail();

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		struct node *tmp = malloc(sizeof(struct node));
		scanf("%d", &tmp->val);
		tmp->next = NULL;
		if (i == 1)
			head = tmp;
		else
			tail->next = tmp;
		tail = tmp;
	}
	MoveToTail();
	for (struct node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d ", cur->val);
	}
	return 0;
}

void MoveToTail() {
	struct node *max = head;
	struct node *tnbMax = NULL;	 // the node before max

	for (struct node *cur = head, *pre = NULL; cur != NULL; pre = cur, cur = cur->next) {
		if (cur->val > max->val) {
			max = cur;
			if (pre != NULL) {
				tnbMax = pre;
			}
		}
	}

	if (max != tail) {
		if (max == head) {
			// max is head
			head = max->next;
		} else {
			tnbMax->next = max->next;
		}

		tail->next = max;
		max->next = NULL;
		tail = max;
	}
}
