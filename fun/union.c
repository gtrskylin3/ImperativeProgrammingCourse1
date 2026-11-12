#include <stdio.h>


typedef enum{
    union_var_none, union_var_ch, union_var_i, union_var_d
} TYPE_VAR;

union tag_var
{
    char var_ch;
    int  var_i;
    double var_d;
};

void show_var(union tag_var v, TYPE_VAR type){
    switch (type){
    case union_var_ch:
        printf("var_ch = %c\n", v.var_ch);
        break;
    
    case union_var_i:
        printf("var_i = %d\n", v.var_i);
        break;
    
    case union_var_d:
        printf("var_d = %.2f\n", v.var_d);
        break;
    
    case union_var_none:
        puts("Undefined type var");
        break;
    }

}

int main(){
    union tag_var var;
    var.var_ch = 'C';
    // var.var_i = 45;

    show_var(var, union_var_ch);

}