#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Lnode {
  int data;
  struct Lnode *next;
} Lnode, *LinkList;

bool initList(LinkList &L);
bool listInsert(LinkList &L, int i, int data);
Lnode *getElem(LinkList &L, int i);
void printList(LinkList &L);

int main() {
  LinkList L;
  initList(L);
  printf("%c\n", 'h');
  printf("%s\n", L->next);
  listInsert(L, 1, 6);
  for (int i = 1; i <= 5; i++) {
    bool r = listInsert(L, i, i);
    cout << boolalpha << r << endl;
  }
  printf("%d\n", L->next);
  printf("%d\n", L->data);
  printf("%d\n", L->next->data);
  printList(L);
  system("pause");
  return 0;
}

bool initList(LinkList &L) {
  L = (Lnode *)malloc(sizeof(Lnode));
  if (L == NULL)
    return false;
  L->next = NULL;
  return true;
}
bool listInsert(LinkList &L, int i, int data) {
  if (i < 1)
    return false;
  Lnode *p = L;
  int j = 0;
  while (p != NULL && j < i - 1) {
    p = p->next;
    j++;
  }
  if (p == NULL)
    return false;
  Lnode *t = (Lnode *)malloc(sizeof(Lnode));
  t->data = data;
  t->next = p->next;
  p->next = t;
  return true;
}
Lnode *getElem(LinkList &L, int i) {
  Lnode *p = L->next;
  int j = 1;
  if (i == 0)
    return L;
  if (i < 0)
    return NULL;
  while (p && j < i) {
    p = p->next;
    j++;
  }
  return p;
}
void printList(LinkList &L) {
  Lnode *p = L->next;
  while (p != NULL) {
    printf("%d\n", p->data);
    p = p->next;
  }
}

// void printList(LinkList &L) {
//   Lnode *p = L;
//   int i = 0;
//   while (p) {
//     Lnode *t;
//     t = getElem(L, i);
//     printf("%d\n", t->data);
//     i++;
//     p = p->next;
//   }
// }
