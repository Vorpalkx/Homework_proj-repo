#include <stdbool.h>

#include "../List/list.h"
#include "functional_menu.h"

int main()
{
    SingleLinkedList list;
    new_list(&list);
    selection_menu(&list);
    return 0;
}


