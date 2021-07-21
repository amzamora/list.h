/* if this is defined, then the vector will double in capacity each
 * time it runs out of space. if it is not defined, then the vector will
 * be conservative, and will have a capcity no larger than necessary.
 * having this defined will minimize how often realloc gets called.
 */
#define CVECTOR_LOGARITHMIC_GROWTH

#include "list.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	List(int) list = NULL;

	push_back(list, 10);
	push_back(list, 20);
	push_back(list, 30);

	pop_back(list);

	printf("pointer : %p\n", list);
	printf("capacity: %lu\n", list_capacity(list));
	printf("size    : %lu\n", list_size(list));

	if (list) {
		size_t i;
		for (i = 0; i < list_size(list); ++i) {
			printf("v[%lu] = %d\n", i, list[i]);
		}
	}

	delete_list(list);

	return 0;
}
