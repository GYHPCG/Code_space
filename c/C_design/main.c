#include <stdio.h>
#include <stdlib.h>
#include "apple.h"

int main(int argc, char** argv)
{
	int type = 1;
	struct apple_s* apple = new_apple(0, 1, 1.0, "apple", 5);

	// apple->type = type;//此处编译时会报错

	set_apple_type(apple, type);
	printf("apple type:%d\n", get_apple_type(apple));
	printf("hello,world\n");
	free(apple);

	return 0;
}

