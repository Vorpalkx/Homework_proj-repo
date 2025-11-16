#include <stdbool.h>

#include "../List/list.h"
#include "functional_menu.h"

int main()
{
    void* list = createList();
    selection_menu(list);
    return 0;
}


