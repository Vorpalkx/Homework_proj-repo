#include <string.h>

#include "../List/list.h"
#include "functional_menu.h"
#include "test_functional_menu.h"

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "--tests") == 0) {
        runAllTests();
        return 0;
    }
    void* list = createList();
    selection_menu(list);
    return 0;
}
