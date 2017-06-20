#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

struct node {
    string data;
    struct node *next, *prev;
};

struct node *split(struct node *head);

struct node *merge(struct node *first, struct node *second)
{

    if (!first)
        return second;

    if (!second)
        return first;

    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

struct node *mergeSort(struct node *head)
{
	
    if (!head || !head->next)
        return head;
    struct node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    
    return merge(head, second);
}

void insert(struct node **head, string data)
{
    struct node *temp =  new node();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct node *head)
{
    struct node *temp = head;
    while (head)
    {
        cout << head->data << endl;
        temp = head;
        head = head->next;
    }
}

struct node *split(struct node *head)
{
    struct node *fast = head, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct node *temp = slow->next;
    slow->next = NULL;
    return temp;
}


int main()
{
    string buf;
    ifstream input("input.txt");

    getline(input, buf);

    struct node *head = NULL;

    string word;

    buf.erase(remove_if(buf.begin(), buf.end(), iswpunct), buf.end());

    for (int i = 0; i < buf.size(); i++)
    {
        if (buf[i] != ' ')
        {
            word += buf[i];
        } else
        {
            insert(&head, word);
            word.clear();
        }
    }

    head = mergeSort(head);

    print(head);

    return 0;
}
