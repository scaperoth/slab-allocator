/**
 * @description: user space slab allocator written
 * in C.
 *
 * for license see LICENSE.txt
 *
 * 1. create slabs as linked list
 * 2. create cache
 * 3. usmem_slabo to point to slab list
 * 4. create object list based on slab size
 * 5. usmem_obj to point to obj list on each slab
 */

#ifndef SLAB_H
#define SLAB_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>
#include "list.h"

#ifndef DEBUG
#define DEBUG
#endif

#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

static void init();
static void new_empty_slab();
static void display(struct list_head *head);

typedef struct usmem_cache
{
    struct list_head    slabs_free;
    struct list_head    slabs_partial;
    struct list_head    slabs_full;
} usmem_cache_t;

typedef struct usmem_slab
{
    struct list_head    list;
    unsigned int        inuse;
    char                end_slabp[0];
    //struct usmem_bufctl first_free_obj;
} usmem_slab_t;

typedef struct usmem_bufctl
{
    struct list_head    free_objs;
    struct usmem_slab   *obj_slabp;
    int                 info;
} usmem_bufctl_t;

usmem_cache_t *cachep;

static void init()
{
    cachep = (usmem_cache_t *)malloc(sizeof(usmem_cache_t));
    assert(cachep != NULL);
    INIT_LIST_HEAD(&cachep->slabs_full);
    INIT_LIST_HEAD(&cachep->slabs_partial);
    INIT_LIST_HEAD(&cachep->slabs_free);
    newslab();

}

static void new_empty_slab()
{
    int error;

    usmem_slab_t *slabp;

#ifdef DEBUG
    printf("the size of slab is %u \n", sizeof(slabp));
#endif

    //allocate memory to slab pointer aligned to page size and size of pagesize
    error = posix_memalign((void **)&slabp, PAGESIZE,  PAGESIZE - (sizeof(slabp)));

    assert(error == 0 && slabp != NULL);

    list_add_tail(&slabp->list, &cachep->slabs_free);

#ifdef DEBUG
    printf("the size of allocation is %u \n", malloc_usable_size(slabp));
#endif

    usmem_bufctl_t *bufp = (void *)slabp->end_slabp;
    bufp->info = 1;
    assert(bufp != NULL);

}



#endif