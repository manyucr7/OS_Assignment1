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
    int *data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int *n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void display() {
        struct node* ptr;
        ptr = head;
        while (ptr != NULL) {
            cout<< ptr->data <<" ";
            ptr = ptr->next;
      }
    }
};

linked_list one;
linked_list second;
linked_list third;
linked_list fourth;
linked_list fifth;
linked_list sixth;
linked_list seventh;
linked_list eighth;
linked_list ninth;

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
        one.add_node(alloc_from_ram(size));
    }
    else if(size>16 && size<=32){
        second.add_node(alloc_from_ram(size));
    }
    else if(size>32 && size<=64){
        third.add_node(alloc_from_ram(size));
    }
    else if(size>64 && size<=128){
        fourth.add_node(alloc_from_ram(size));
    }
    else if(size>128 && size<=256){
        fifth.add_node(alloc_from_ram(size));
    }
    else if(size>256 && size<=512){
        sixth.add_node(alloc_from_ram(size));
    }
    else if(size>512 && size<=1024){
        seventh.add_node(alloc_from_ram(size));
    }
    else if(size>1024 && size<=2048){
        eighth.add_node(alloc_from_ram(size));
    }
    else if(size>2048 && size<=4080){
        ninth.add_node(alloc_from_ram(size));
    }
    else{
        printf("Wrong input");
    }
	return NULL;
}



int main()
{
    cout << "Hello world!" << endl;
    size_t a;
    cin>>a;
    cout<<a;
    mymalloc(a);
    printf("done");

    return 0;
}
