#include <stdio.h>
#include <stdlib.h>


typedef struct list_s{
    char string[8];
    int next;
} list;

int main(){
    int tests;
    scanf("%d", &tests);
    
    for (int i = 0; i < tests; ++i){
        int count_node, cur_idx, op;
        scanf("%d %d %d", &count_node, &cur_idx, &op);
        
        list* nodes = (list*)malloc(sizeof(list)*count_node);
        
        for (int j = 0; j < count_node; ++j){
            scanf("%s %d", nodes[j].string, &nodes[j].next);
        }
        int type, idx;

        for (int k = 0; k < op; ++k){
            scanf("%d %d", &type, &idx);
            if (type == 0){
                count_node ++;
                nodes = realloc(nodes, sizeof(list) * count_node);
                scanf(" %s", nodes[count_node-1].string);
                if (idx == -1){
                    nodes[count_node-1].next = cur_idx;
                    cur_idx = count_node-1;
                } else {
                    int tmp_next = nodes[idx].next;
                    nodes[idx].next = count_node-1;
                    nodes[count_node-1].next = tmp_next;
                }
                printf("%d\n", count_node-1);
            } else if (type == 1){
                int old_idx;
                if (idx == -1){
                    old_idx = cur_idx;
                    cur_idx = nodes[cur_idx].next;
                    printf("%s\n", nodes[old_idx].string);
                } else{
                    old_idx = nodes[idx].next;
                    nodes[idx].next = nodes[nodes[idx].next].next;
                    printf("%s\n", nodes[old_idx].string);
                }

            }
        }
        
        printf("===\n");
        while (cur_idx != -1){
            printf("%s\n", nodes[cur_idx].string);
            cur_idx = nodes[cur_idx].next;
        } 
        printf("===\n");
        
        free(nodes);
    }    
    
}


