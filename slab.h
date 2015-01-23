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
#include <math.h>

#ifndef DEBUG
#define DEBUG 1
#endif

#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

typdef struct usmem_cache{
	struct list_head 	slab_free;
	struct list_head 	slab_partial;
	struct list_head	slab_full
	unsigned int 		num_obj_per_slab;
	spinlock_t			slock; 	
}usmem_cache_t

typedef struct usmem_slab
{
    struct list_head	first_free_obj;
    void				*first_obj_loc;
    unsigned int 		num_used_objs;
    struct usmem_objctl	first_free_obj;
} usmem_slab_t

typedef struct usmem_objctl{
	usmem_slab_t	*obj_slabp;
}usmem_bufctl_t

static void init()
{
}

#endif