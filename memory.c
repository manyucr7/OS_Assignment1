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

struct node *head1  = NULL;
struct node *endnode1  = NULL;
struct node *head2  = NULL;
struct node *endnode2  = NULL;
struct node *head3  = NULL;
struct node *endnode3  = NULL;
struct node *head4  = NULL;
struct node *endnode4  = NULL;
struct node *head5  = NULL;
struct node *endnode5  = NULL;
struct node *head6  = NULL;
struct node *endnode6  = NULL;
struct node *head7  = NULL;
struct node *endnode7  = NULL;
struct node *head8  = NULL;
struct node *endnode8  = NULL;
struct node *head9  = NULL;
struct node *endnode9  = NULL;

void display(struct node** h)
 {
   struct node* head = *h;

   struct node *n = head;

   while(n!=NULL)
   {
    printf("%d\n",n->val);
    n = n->next;
   }
 }


void inserting_node(int *i,struct node** h, struct node** e)
{
    printf("adding\n");
    if(*h!=NULL)
    {
        struct node *n = (struct node*)malloc(sizeof(struct node));
        n->next  = NULL;
        n->val = i;

        (*e)->next = n;
        *e = n;
    }
    else
    {
        printf("heading\n");
        *h  = (struct node*)malloc(sizeof(struct node));
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

void *mymalloc(size_t size)
{
    if(size<=16){
        inserting_node(alloc_from_ram(size),&head1,&endnode1);
    }
    else if(size>16 && size<=32){
        inserting_node(alloc_from_ram(size),&head2,&endnode2);
    }
    else if(size>32 && size<=64){
        inserting_node(alloc_from_ram(size),&head3,&endnode3);
    }
    else if(size>64 && size<=128){
        inserting_node(alloc_from_ram(size),&head4,&endnode4);
    }
    else if(size>128 && size<=256){
        inserting_node(alloc_from_ram(size),&head5,&endnode5);
    }
    else if(size>256 && size<=512){
        inserting_node(alloc_from_ram(size),&head6,&endnode6);
    }
    else if(size>512 && size<=1024){
        inserting_node(alloc_from_ram(size),&head7,&endnode7);
    }
    else if(size>1024 && size<=2048){
        inserting_node(alloc_from_ram(size),&head8,&endnode8);
    }
    else if(size>2048 && size<=4080){
        inserting_node(alloc_from_ram(size),&head9,&endnode9);
    }
    else{
        printf("Wrong input");
    }
    printf("done inserting_node");
	return NULL;
}



int main()
{
    size_t a;
    scanf(a);
    printf(a);
    mymalloc(a);
    printf("done");

    return 0;
}
