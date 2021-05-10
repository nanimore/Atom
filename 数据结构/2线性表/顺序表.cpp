#include <cstdlib>
#include <iostream>

// int text(int &x){
//    x = 2;
//}
// int main() {
//    int x = 1;
//    printf("before: %d\n",x);
//    text(x);
//    printf("after: %d\n",x);
//    printf("&: %d\n",&x);
//    int *p = &x;
//    printf("*p: %d\n",*p);
//    printf("p: %d\n",p);
//    return 0;
//}

#define MAX_SIZE 10
typedef struct {
  int *data;
  int maxSize;
  int longth;
} seqList;
void initList(seqList &L) {
  L.data = (int *)malloc(10 * sizeof(int));
  L.longth = 0;
  L.maxSize = MAX_SIZE;
}
void add(seqList &L, int data) {
  if (L.longth < L.maxSize) {
    L.data[L.longth] = data;
  }
  L.longth += 1;
}

void increaseList(seqList &L, int len) {
  int *p = L.data;
  L.data = (int *)malloc((L.maxSize + len) * sizeof(int));
  for (int i = 0; i < L.longth; i++) {
    L.data[i] = p[i];
  }
  L.maxSize = L.maxSize + len;
  free(p);
}
void printList(seqList &L) {
  for (int i = 0; i < L.longth; i++) {
    printf("%d\n", L.data[i]);
  }
}

int main() {
  seqList L;
  initList(L);
  printf("%d\n", L.maxSize);

  for (int i = 1; i <= 5; i++) {
    add(L, i);
  }
  increaseList(L, 5);
  printf("%d\n", L.maxSize);

  printList(L);
  printf("%d", sizeof(int *));
}
