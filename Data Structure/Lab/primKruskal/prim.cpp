#include<stdio.h>

int main() {

  int V = 5;
  int graph[V][V] = {
  { 0, 2, 0, 6, 0 },
      { 2, 0, 3, 8, 5 },
      { 0, 3, 0, 0, 7 },
      { 6, 8, 0, 0, 9 },
      { 0, 5, 7, 9, 0 }
  };
  bool visited[V] = {};

  //	int V = 9;
  //	int graph[V][V] = {
  //		{0,  4, 0,  0,  0,  0, 0,  8, 0},
  //		{4,  0, 8,  0,  0,  0, 0, 11, 0},
  //		{0,  8, 0,  7,  0,  4, 0,  0, 2},
  //		{0,  0, 7,  0,  9, 14, 0,  0, 0},
  //		{0,  0, 0,  9,  0, 10, 0,  0, 0},
  //		{0,  0, 4, 14, 10,  0, 2,  0, 0},
  //		{0,  0, 0,  0,  0,  2, 0,  1, 6},
  //		{8, 11, 0,  0,  0,  0, 1,  0, 7},
  //		{0,  0, 2,  0,  0,  0, 6,  7, 0},
  //	};

  return 0;
}