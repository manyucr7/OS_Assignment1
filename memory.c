#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include "memory.h"

#define PAGE_SIZE 4096

struct node
{
  struct node *next;
  int *val;
};

void delete_node(int *i,struct node** h,struct node** e)
  {
    node* head = *h;
    node* endnode = *e;
    node *temp;
    node *n = head;
    while(n!=NULL)
    {
     if(n->val == i)
     {
        if(n==head)
        {
            head = head->next;
        }
        else if(n==endnode)
        {
            temp->next = NULL;
            endnode = temp;
        }
        else
        {
            temp->next = n->next;
        }
        free(n);
        break;
    }
    else
    {
        temp = n;
        n = n->next;
    }
  }
}

void display(struct node** h)
 {
   node* head = *h;

   node *n = head;

   while(n!=NULL)
   {
    printf("%d\n",n->val);
    n = n->next;
   }
 }


void add_node(int *i,struct node** h, struct node** e)
{
    printf("adding\n");
    if(*h!=NULL)
    {
        node *n = (struct node*)malloc(sizeof(node));
        n->next  = NULL;
        n->val = i;

        (*e)->next = n;
        *e = n;
    }
    else
    {
        printf("heading\n");
        *h  = (struct node*)malloc(sizeof(node));
        (*h)->next = NULL;
        (*h)->val = i;
        *e = *h;
    }

}


static void *alloc_from_ram(size_t size)
{
	assert((size % PAGE_SIZE) == 0 && "size must be multiples of 4096");
	void* base = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);
	if (base == MAP_FAILED)
	{
		printf("Unable to allocate RAM space\n");
		exit(0);
	}
	return base;
}

static void free_ram(void *addr, size_t size)
{
	munmap(addr, size);
}

void myfree(void *ptr)
{
	printf("myfree is not implemented\n");
	abort();
}

void *mymalloc(size_t size, struct node** head, struct node** endnode)
{
    if(size<=16){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else if(size>16 && size<=32){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else if(size>32 && size<=64){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else if(size>64 && size<=128){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else if(size>128 && size<=256){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else if(size>256 && size<=512){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else if(size>512 && size<=1024){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else if(size>1024 && size<=2048){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else if(size>2048 && size<=4080){
        add_node(alloc_from_ram(size),head,endnode);
    }
    else{
        printf("Wrong input");
    }
    printf("done add_node");
	return NULL;
}



int main()
{
    cout << "Hello world!" << endl;
    size_t a;
    scanf(a);
    printf(a);
    struct node *head  = NULL;
    struct node *endnode  = NULL;
    mymalloc(a, head, endnode);
    printf("done");

    return 0;
}
