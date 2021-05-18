#include <iostream>
#include "exptree.hpp"

void print_vars(ExpTree::Variable *vars, int amount_vars){
    for (int i = 0; i < amount_vars; i++){
        std::cout << vars[i].getName() << ": " << (vars[i]) << std::endl;
    }
}


int main(){

    ExpTree::Variable vars[]{"x", "y"};
    print_vars(vars, 2);

    
    ExpTree::Variable var("variable_name");
    var = 3;
    std::string var_name = var.getName();
    double var_value = var.getValue();
    double var_value_alternative = double(var);
    std::cout << var_name << ": " << var_value << "|" << var_value_alternative << std::endl;


    return 0;
}