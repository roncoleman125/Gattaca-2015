#include <stdio.h>


void test00(void);

int main(int argc, char** argv) {
	void(*tests[])(void) = {
		test00
	};

	int n = sizeof(tests) / sizeof(void*);

	printf("running tests: %d\n", n);
	for (int k = 0; k < n; k++) {
		printf("test %02x: \n", k);
		(*tests[k])();
		printf(" PASSED!\n");
	}
}