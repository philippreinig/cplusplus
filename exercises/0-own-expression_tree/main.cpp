#include <iostream>


class Variable{
    public:
        Variable(){}
        Variable(const std::string name_, const double value_) : name(name_), value(value_){
        }

        Variable& operator=(double value_){
            this->value = value_;
            return *this;
        }

        operator double(){
            return this->value;
        }

    private:
        std::string name;
        double value;

};


class VariableNode{

    public:
        VariableNode(){}
        VariableNode(Variable var_) : var(var_){
        }

        Variable getVariable() const {
            return this->var;
        }



    private:
        Variable var;
};

class SumNode{

    public:
        SumNode(VariableNode left_, VariableNode right_) : left(left_), right(right_){}

        double getValue() const{
            return double(left.getVariable()) + double(right.getVariable());
        }

        VariableNode getLeft ()const {
            return this->left;
        }

        VariableNode getRight () const{
            return this->right;
        }

    private:
        VariableNode left;
        VariableNode right;
};

class MultNode{

    public:
        MultNode(VariableNode left_, VariableNode right_) : left(left_), right(right_){}

        double getValue() const
        {
            return double(left.getVariable()) * double(right.getVariable());
        }

        VariableNode getLeft() const {
            return this->left;
        }

        VariableNode getRight() const{
            return this->right;
        }

    private:
        const VariableNode left;
        const VariableNode right;
};

template<typename T>
void printNode(const T& node) {
    std::cout << "debug: Node: left " << double(node.getLeft().getVariable()) << ", right: " << double(node.getRight().getVariable()) << ", result: " << node.getValue() << std::endl;
}


void printSumNode(SumNode sn){
    std::cout << "debug: SumNode: left " << double(sn.getLeft().getVariable()) << ", right: " << double(sn.getRight().getVariable()) << ", sum: " << sn.getValue() << std::endl;
}
void printMultNode(MultNode mult_node){
    std::cout << "debug: MultNode: left " << double(mult_node.getLeft().getVariable()) << ", right: " << double(mult_node.getRight().getVariable()) << ", sum: " << mult_node.getValue() << std::endl;
}
// void printDivideNode(DivideNode division_node){
//     std::cout << "debug: DivideNode: left " << double(division_node.getLeft().getVariable()) << ", right: " << double(division_node.getRight().getVariable()) << ", sum: " << division_node.getValue() << std::endl;
// }
// void printMinusNode(MinusNode minus_node){
//     std::cout << "debug: MinusNode: left " << double(minus_node.getLeft().getVariable()) << ", right: " << double(minus_node.getRight().getVariable()) << ", sum: " << minus_node.getValue() << std::endl;
// }



int main(){
    const Variable var1("var1", 3.0);
    const Variable var2("var2", -7.0);
    
    const VariableNode var_node_1(var1);
    const VariableNode var_node_2(var2);

    const SumNode sum_node_1(var_node_1, var_node_2);
    const SumNode sum_node_2(var_node_2, var_node_1);

    // const MinusNode minus_node_2(var_node_1, var_node_2);
    // const MinusNode minus_node_1(var_node_2, var_node_1);

    const MultNode mult_node_1(var_node_1, var_node_2);
    const MultNode mult_node_2(var_node_2, var_node_1);

    // const DivideNode divide_node_1(var_node_1, var_node_2);
    // const DivideNode divide_node_2(var_node_2, var_node_1);

    printNode(sum_node_1);
    printNode(mult_node_1);

    // printSumNode(sum_node_1);
    // printSumNode(sum_node_2);

    // printMinusNode(minus_node_1);
    // printMinusNode(minus_node_2);

    // printMultNode(mult_node_1);
    // printMultNode(mult_node_2);

    // printDivideNode(divide_node_1);
    // printDivideNode(divide_node_2);


    return 0;
}