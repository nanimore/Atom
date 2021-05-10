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

int main() { return 0; }

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
  int t = 2314;
}
