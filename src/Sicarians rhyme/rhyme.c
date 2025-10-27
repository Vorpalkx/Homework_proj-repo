#include <stdio.h>

#include "../List/cyclic_list.h"

int main()
{
   int n;
   int m;
   printf("Enter the number of Sicarians and the order in which they are killed: ");
   scanf("%d %d", &n, &m);
   
   CyclicList* list = new_cycl_list();
   int number_sicarians = 1;
   while (number_sicarians <= n) {
       add_to_end_cycl_list(list, number_sicarians);
       number_sicarians++;
   }
   int index = 0;
   while (cycl_list_length(list) > 1) {
       index = (index + m - 1) % cycl_list_length(list);
       remove_by_index_cycl_list(list, index);
   }
   printf("The number of the remaining Sicarii: %d\n", list->head->data);
   return 0;
}
