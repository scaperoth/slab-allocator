/**
 * @description: example of how the linked list is used...
 * this is to be used as a reference and not compiled
 */

main() 
{
    LIST_HEAD(fooHead);
    
    add_node(10, &fooHead);
    add_node(20, &fooHead);
    add_node(25, &fooHead);
    add_node(30, &fooHead);
    
    display(&fooHead);
    find_first_and_delete(20, &fooHead);
    display(&fooHead);
    delete_all(&fooHead);
    display(&fooHead);
}