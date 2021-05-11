#include <cstdio>
#include <cstdlib>
using namespace std;

struct DNode {
  int data;
  struct DNode *prior, *next;
};

typedef struct DNode DNode;
typedef struct DNode *DLinkList;

bool initList(DLinkList &L);
bool listInsert(DLinkList &L, int i, int data);
DNode *getElem(DLinkList &L, int i);
void printList(DLinkList &L);

int main() {
  DLinkList L;
  initList(L);
  printf("%p\n", L);
  listInsert(L, 1, 1);
  listInsert(L, 2, 2);
  listInsert(L, 3, 3);
  printf("%d\n", getElem(L, 2)->data);
  printList(L);

  return 0;
}

bool initList(DLinkList &L) {
  L = (DNode *)malloc(sizeof(DNode));
  if (L == NULL)
    return false;
  L->prior = L->next = NULL;
  return true;
}

bool listInsert(DLinkList &L, int i, int data) {
  if (i < 1)
    return false;
  DNode *p = L;
  int j = 0;
  while (p != NULL && j < i - 1) {
    p = p->next;
    j++;
  }
  if (p == NULL)
    return false;
  DNode *t = (DNode *)malloc(sizeof(DNode));
  t->next = p->next;
  t->prior = p;
  t->data = data;
  if (p->next != NULL) {
    p->next->prior = t;
  }
  p->next = t;
  return true;
}

DNode *getElem(DLinkList &L, int i) {
  DNode *p = L->next;
  int j = 1;
  if (i == 0)
    return L;
  if (i < 0)
    return NULL;
  while (j < i) {
    p = p->next;
    j++;
  }
  return p;
}

void printList(DLinkList &L) {
  DNode *p = L->next;
  while (p != NULL) {
    printf("%d\n", p->data);
    p = p->next;
  }
}
