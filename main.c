#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

struct node {string data;
struct node *next, *prev;
};

struct node *split(struct node *head);

struct node *split(struct node *head)
{struct node *fast = head, *slow = head;
while (fast->next && fast->next->next)
{fast = fast->next->next;
slow = slow->next;}
struct node *temp = slow->next;
slow->next = NULL;
return temp;
}
