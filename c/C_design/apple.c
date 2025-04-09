#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct apple_s {
	int type;
	int weight;
	float price;
	char* name;
};

struct apple_s* new_apple(int type, int weight, float price, char* name, int len) {
	struct apple_s* p = (struct apple_s*)malloc(sizeof(struct apple_s));
	p->type = 0;
	p->weight = 0;
	p->price = 0;
	p->name = (char*)malloc(16);
	strncpy(p->name, name, 16);

	return p;
}

void free_apple(struct apple_s* p) {
	free(p->name);
	free(p);
}

int set_apple_type(struct apple_s* p, int type) {
	p->type = type;
	return 0;
}

int get_apple_type(struct apple_s* p) {
	return p->type;
}

int set_apple_weight(struct apple_s* p, int weight) {
	p->weight = weight;
	return 0;
}

int get_apple_weight(struct apple_s* p) {
	return p->weight;
}

