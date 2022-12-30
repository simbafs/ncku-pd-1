#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDER_ID_LEN 8
#define MAX_VILLAGE_NAME_LEN 15

typedef struct order_s {
	struct order_s *next;
	char order_id[ORDER_ID_LEN + 1];
	char consumer[MAX_VILLAGE_NAME_LEN + 1]; enum {
		INGRED_A = 1,
		INGRED_B,
		INGRED_C,
	} ingredient_id;
	union {
		char ing_a[8];
		long ing_b;
		double ing_c;
	} amount;
} order_t;

typedef struct village_s {
	char name[MAX_VILLAGE_NAME_LEN + 1];
	unsigned long total_cost;
	order_t *order_list;
} village_t;

static const long unit_costs[] = {
	[INGRED_A] = 256,
	[INGRED_B] = 512,
	[INGRED_C] = 1024,
};

static village_t *init_village_array(int v_cnt);
static order_t *init_order_list(int o_cnt);
static void unify_orders(village_t *vills, int v_cnt, order_t *orders);
static void print_result(village_t *vills, int v_cnt);

int main() {
	int village_cnt, order_cnt;
	scanf("%d%d", &village_cnt, &order_cnt);
	village_t *villages = init_village_array(village_cnt);
	if (!villages) {
		goto init_village_failed;
	}
	order_t *orders = init_order_list(order_cnt);
	if (!orders) {
		goto init_order_failed;
	}
	unify_orders(villages, village_cnt, orders);
	print_result(villages, village_cnt);
	free(orders);

init_order_failed:
	free(villages);

init_village_failed:
	return 0;
}

static village_t *init_village_array(int v_cnt) {
	village_t *villages = malloc(sizeof(village_t) * v_cnt);
	if (!villages) {  // Ran out of memory
		return NULL;
	}
	for (int i = 0; i < v_cnt; i++) {
		scanf("%s", villages[i].name);
	}
	return villages;
}

static order_t *init_order_list(int o_cnt) {
	order_t *orders = malloc(sizeof(order_t) * o_cnt);
	if (!orders) {	// Ran out of memory
		return NULL;
	}
	for (int i = 0; i < o_cnt; i++) {
		// Read the content of order
		// the term %[^c] will use 'c' as delimiter while scanning the input
		scanf(" %[^:]:%u/%[^-]-%s", orders[i].order_id,
			  &orders[i].ingredient_id, orders[i].amount.ing_a,
			  orders[i].consumer);

		switch (orders[i].ingredient_id) {
			case INGRED_B:
				orders[i].amount.ing_b = atol(orders[i].amount.ing_a);
				break;
			case INGRED_C:
				orders[i].amount.ing_c = atof(orders[i].amount.ing_a);
				break;
			default:
				break;
		}
		// Construct orders into linked-list
		if (i) {
			orders[i - 1].next = orders + i;
		}
	}
	// End the linked-list
	orders[o_cnt - 1].next = NULL;
	return orders;
}

static void print_result(village_t *vills, int v_cnt) {
	for (int i = 0; i < v_cnt; i++) {
		printf("%s %ld\n  ->", vills[i].name, vills[i].total_cost);
		for (order_t *optr = vills[i].order_list; optr; optr = optr->next) {
			printf(" %s", optr->order_id);
		}
		printf("\n");
	}
}

int cmp(const void *a, const void *b){
	return strcmp((const char*)a, (const char *)b);
}

static void unify_orders(village_t *vills, int v_cnt, order_t *orders) {
	order_t *currentOrder = orders;

	while (currentOrder != NULL) {
		order_t *next = currentOrder->next;

		// find consumer
		village_t *consumer;
		for (int i = 0; i < v_cnt; i++) {
			if (strcmp(currentOrder->consumer, vills[i].name) == 0) {
				consumer = vills + i;
				break;
			}
		}
		//  printf("id: %s, consumer: %s\n", currentOrder->order_id, consumer->name);

		// insert order
		if (consumer->order_list == NULL) {
			//  printf("initialize order_list\n");
			consumer->order_list = currentOrder;
			currentOrder->next = NULL;
		} else if (strcmp(consumer->order_list->order_id,
						  currentOrder->order_id) > 0) {
			//  printf("replace head\n");
			currentOrder->next = consumer->order_list;
			consumer->order_list = currentOrder;
		} else {
			//  printf("insert\n");
			order_t *nowOrder = consumer->order_list;
			while (1) {
				if (nowOrder->next == NULL) {
					//  printf("add to tail\n");
					nowOrder->next = currentOrder;
					currentOrder->next = NULL;
					break;
				} else if (strcmp(nowOrder->next->order_id,
								  currentOrder->order_id) > 0) {
					//  printf("insert after %s\n", nowOrder->order_id);
					currentOrder->next = nowOrder->next;
					nowOrder->next = currentOrder;
					break;
				}
				nowOrder = nowOrder->next;
			}
		}

		// calcuate cost
		int cost = 0;
		switch (currentOrder->ingredient_id) {
			case INGRED_A:
				cost = unit_costs[currentOrder->ingredient_id] *
					   atol(currentOrder->amount.ing_a);
				//  printf("ingredient_id: %d, amount: %s\n", currentOrder->ingredient_id, currentOrder->amount.ing_a);
				break;
			case INGRED_B:
				cost = unit_costs[currentOrder->ingredient_id] *
					   currentOrder->amount.ing_b;
				//  printf("ingredient_id: %d, amount: %ld\n", currentOrder->ingredient_id, currentOrder->amount.ing_b);
				break;
			case INGRED_C:
				cost = unit_costs[currentOrder->ingredient_id] *
					   currentOrder->amount.ing_c;
				//  printf("ingredient_id: %d, amount: %f\n", currentOrder->ingredient_id, currentOrder->amount.ing_c);
				break;
		}
		//  unit_costs[currentOrder->ingredient_id] *
		//  currentOrder->amount.ing_b;
		//  printf("cost: %d\n", cost);
		consumer->total_cost += cost;

		//  printf("next order: %s\n", next->order_id);
		currentOrder = next;
		//  printf("\n");
	}
	//  printf("--------\n");
	qsort(vills, v_cnt, sizeof(vills[0]), cmp);
}
