#include <stdio.h>
#include "StrList.h"
#include <stdlib.h>
#define false 0
#define true 1
int main() {
    StrList *list = StrList_alloc();
    int num = 0;
    scanf("%d", &num);
    
    while (num != 0) {
        if (num == 1) {
            int temp = 0;
            scanf("%d", &temp);
            for (int i = 0; i < temp; i++) {  
                char* data = (char*)malloc(sizeof(char) * 100);
                scanf("%s", data);
                StrList_insertLast(list, data);
                free(data);
            }
        }

        else if (num == 2) {
            int temp = 0;
            scanf("%d", &temp);
            char* data = (char *)malloc(sizeof(char) * 100);
            scanf("%s", data);
            StrList_insertAt(list, data, temp); 
            free(data);   
        }
        else if (num == 3) {
            StrList_print(list);
        } 
        else if (num == 4) {
           printf("%d\n", (int)StrList_size(list));
        } 
        else if (num == 5) {
            int index = 0;
            scanf("%d", &index);
            StrList_printAt(list, index);
        } 
        else if (num == 6) {
            int i = StrList_printLen(list);
            printf("%d\n", i);
        } 
        else if (num == 7) {
            char* data = (char *)malloc(sizeof(char) * 100);
            scanf("%s", data);
            int y = StrList_count(list, data);
            printf("%d\n",y);
            free(data);
        } 
        else if (num == 8) {
            char* data = (char*)malloc(sizeof(char) * 100);
            scanf("%s", data);
            StrList_remove(list, data);
            free(data);
        } 
        else if (num == 9) {
            int index = 0;
            scanf("%d", &index);
            StrList_removeAt(list, index);
        }
         else if (num == 10) {
            StrList_reverse(list);
        }
         else if (num == 11) {
            StrList_free11(list);
        }
         else if (num == 12) {
            StrList_sort(list);
        }
         else if (num == 13) {
            if (StrList_isSorted(list)) {
                printf("true \n");
            } 
            else {
                printf("false \n");
            }
        }
        scanf("%d", &num); // Read next number for the next iteration
    }
    
    StrList_free(list);
    
    return 0;
}