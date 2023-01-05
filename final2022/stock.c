// not finish yet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MARKET_SIZE 50

typedef enum { BUY, SELL } action_type;

typedef struct _order {
	char stock_id[5];
	action_type action;
	float price;
	int amount;
	struct _order *next;
} order;

typedef struct {
	char stock_id[5];
	int trading_volumn;
	float opening_price;
	float closing_price;
	float highest_price;
	float lowest_price;
	order *buy_orders;
	order *sell_orders;
} subject;

subject market[MARKET_SIZE];

void make_order(order *new_order);

int cmp(const void *a, const void *b) {
	subject *subjectA = (subject *)a;
	subject *subjectB = (subject *)b;

	return (subjectB->trading_volumn - subjectA->trading_volumn);
}

void print_price(float price) {
	if (price < 50)
		printf("  %6.2f", price);
	else if (price < 500)
		printf("  %6.1f", price);
	else
		printf("  %6.0f", price);
}

int main() {
	char buffer[30], target[5], action[5];
	float price;
	int amount;

	while (fgets(buffer, 30, stdin) != NULL) {
		if (buffer[0] == '\n') break;
		sscanf(buffer, "%s %s %f %d\n", target, action, &price, &amount);

		order *new_order = (order *)malloc(sizeof(order));

		strcpy(new_order->stock_id, target);
		new_order->action = strcmp(action, "BUY") ? SELL : BUY;
		new_order->price = price;
		new_order->amount = amount;
		new_order->next = NULL;

		make_order(new_order);
	}

	qsort(market, MARKET_SIZE, sizeof(subject), cmp);

	printf("stock_id  volumn    open   close    high     low\n");
	for (int i = 0; i < MARKET_SIZE && market[i].stock_id[0] != '\0'; ++i) {
		printf("%s      %6d", market[i].stock_id, market[i].trading_volumn);
		print_price(market[i].opening_price);
		print_price(market[i].closing_price);
		print_price(market[i].highest_price);
		print_price(market[i].lowest_price);
		printf("\n");
	}

	return 0;
}

int marketIndex = 0;
int stockIdtoIndex(char *id) {
	for (int i = 0; i < marketIndex; i++) {
		if (strcmp(id, market[i].stock_id) == 0) {
			return i;
		}
	}

	// init market

	strcpy(market[marketIndex++].stock_id, id);
	market[marketIndex - 1].lowest_price = -1;
	market[marketIndex - 1].highest_price = 0;
	market[marketIndex - 1].opening_price = -1;
	return marketIndex - 1;
}

void updateMarket(int id, float price, int amount) {
	printf("> %d %f %d\n", id, price, amount);
	if(price == 0 || amount == 0) return;
	if (market[id].lowest_price > price || market[id].lowest_price == -1)
		market[id].lowest_price = price;
	if (market[id].highest_price < price) market[id].highest_price = price;
	if (market[id].opening_price == -1) market[id].opening_price = price;
	market[id].closing_price = price;
	market[id].trading_volumn += amount;
}

void make_order(order *new_order) {
	int id = stockIdtoIndex(new_order->stock_id);
	if (new_order->action == BUY) {
		int finish = 0;
		for (order *curr = market[id].sell_orders; curr; curr++) {
			if (curr->price > new_order->price) break;
			if (curr->amount < new_order->amount) {
				market[id].sell_orders = curr->next;
				new_order->amount -= curr->amount;
				updateMarket(id, curr->price, curr->amount);
			} else if (curr->amount == new_order->amount) {
				market[id].sell_orders = curr->next;
				updateMarket(id, curr->price, curr->amount);
				finish = 1;
				break;
			} else {
				curr->amount -= new_order->amount;
				updateMarket(id, curr->price, new_order->amount);
				finish = 1;
				break;
			}
		}
		if (!finish) {
			if (market[id].buy_orders == NULL) {
				market[id].buy_orders = new_order;
			} else if (market[id].buy_orders->price < new_order->price) {
				new_order->next = market[id].buy_orders;
				market[id].buy_orders = new_order;
			} else {
				for (order *curr = market[id].buy_orders; curr; curr++) {
					if(curr->next == NULL){
						curr->next = new_order;
					}else if (curr->next->price < new_order->price) {
						new_order->next = curr->next;
						curr->next = new_order;
						break;
					}
				}
			}
		}
	} else {
		// sell
		int finish = 0;
		for (order *curr = market[id].buy_orders; curr; curr++) {
			if (curr->price < new_order->price) break;
			if (curr->amount < new_order->amount) {
				market[id].buy_orders = curr->next;
				new_order->amount -= curr->amount;
				updateMarket(id, curr->price, curr->amount);
			} else if (curr->amount == new_order->amount) {
				market[id].buy_orders = curr->next;
				updateMarket(id, curr->price, curr->amount);
				finish = 1;
				break;
			} else {
				curr->amount -= new_order->amount;
				updateMarket(id, curr->price, new_order->amount);
				finish = 1;
				break;
			}
		}
		if (!finish) {
			if(market[id].sell_orders == NULL){
				market[id].sell_orders = new_order;
			}else if(market[id].sell_orders->price > new_order->price){
				new_order->next = market[id].sell_orders;
				market[id].sell_orders = new_order;
			}else{
				for (order *curr = market[id].sell_orders; curr; curr++) {
					if(curr->next == NULL){
						curr->next = new_order;
					}else if (curr->next->price < new_order->price) {
						new_order->next = curr->next;
						curr->next = new_order;
						break;
					}
				}
			}
		}
	}
}
