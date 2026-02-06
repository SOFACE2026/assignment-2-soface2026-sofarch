#include "ShoeShop_Org.h"
#include <stdlib.h>

ShoeShop* ShoeShop_create(int size) {
	ShoeShop* shop = (ShoeShop*) malloc(sizeof(ShoeShop));
	shop->shelf = (int*)calloc(size, sizeof(int));
	shop->size = size;
	return shop;
}

void ShoeShop_destroy(ShoeShop* shop) {
	if (shop != NULL) {
		free(shop->shelf);
		free(shop);
	}
}

void ShoeShop_add_items(ShoeShop* shop, int row, int num) {
	shop->shelf[row] += num;
}

int ShoeShop_in_stock(ShoeShop* shop, int row) {
	return shop->shelf[row] > 0;
}

int ShoeShop_count_items(ShoeShop* shop) {
	int tot = 0;
	for (int k = 0; k < shop->size; k++) {
		tot += shop->shelf[k];
	}
	return tot;
}

bool ShoeShop_clear(ShoeShop* shop, int row) {
	bool rem = shop->shelf[row] > 0;
	shop->shelf[row] = 0;
	return rem;
}
