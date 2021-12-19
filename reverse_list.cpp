#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Elem {
	struct Elem* next;
	int s;
};

struct Elem* add_char(int s, struct Elem* list)
{
	if (list == NULL)
	{
		list = (struct Elem*)malloc(sizeof(struct Elem));
		list->s = s;
		list->next = NULL;
	}
	else
		list->next = add_char(s, list->next);
	return list;
}

struct Elem* add_begin(int s, struct Elem* list)
{
	struct Elem *tmp = (struct Elem*)malloc(sizeof(struct Elem));
	tmp->s = s;
	tmp->next = list;
	return tmp;
}

struct Elem* Reverse(struct Elem* list)
{
	struct Elem* tmp = NULL;
	if (!list->next)
		return add_char(list->s, tmp);
	else
	{
		tmp = Reverse(list->next);
		tmp->next = add_char(list->s, tmp->next);
	}
	return tmp;
}


void print_elem(struct Elem* list)
{
	if (list != NULL)
	{
		cout << list->s << "\t";
		print_elem(list->next);
	}
}

void free_elem(struct Elem* list)
{
	if (list)
		free_elem(list->next);
	free(list);
}

int main() {
	
  int n = 2;
  for (n; n < 2003; n+=100)
  {
    struct Elem* tmp = NULL;
    struct Elem* tmp2 = NULL;
    for (int i = 0; i < n; i++)
      tmp = add_char(i, tmp);
    print_elem(tmp);
    cout << endl;
    unsigned int start_time = clock();
    tmp2 = Reverse(tmp);
    unsigned int end_time = clock();
    print_elem(tmp2);
    cout << endl;
    cout << "Time for n = " << n << " : " << (end_time - start_time) << "mc" << endl;
    free_elem(tmp);
    free_elem(tmp2);
  }
  return 0;
}
