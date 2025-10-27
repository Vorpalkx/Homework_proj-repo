#include <stdbool.h>

#include "../List/list.h"
#include "functional_menu.h"

int main()
{
    void* list = new_list();
    selection_menu(list);
    return 0;
}


