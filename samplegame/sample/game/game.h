#pragma once
#include"..\\initialize\\init.h"

typedef struct __Graph{
	int handle;
	int x;
	int y;
	int width;
	int height;
}Graphs;

void game(Scene *scene);
void init(Graphs graph[15]);
void init_graph(Graphs graph[15]);