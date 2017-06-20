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

int main()
{string buf;
ifstream input("input.txt");
getline(input, buf);
struct node *head = NULL;
string word;
buf.erase(remove_if(buf.begin(), buf.end(), iswpunct), buf.end());
struct node *head = NULL;
string word;
for (int i = 0; i < buf.size(); i++){
if (buf[i] != ' '){
word += buf[i];} 
else{
insert(&head, word);
word.clear();}}
print(head);
return 0;
}
