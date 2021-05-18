#include "exptree.hpp"

namespace ExpTree{
    //Variable
    Variable::Variable(const char* name_) : name(name_){}

    Variable& Variable::operator= (double const& value_){
        this->value = value_;
        return *this;
    }

    Variable::operator double() const{
        return this->value;
    }

    std::string Variable::get_name() const{
        return this->name;
    }
    
    //SumNode
    SumNode::SumNode(Node* left_, Node* right_) : BinOpNode(left_, right_){}

    double SumNode::evaluate(const Variable* vars, int numVars) const
    {
        return this->left->evaluate(vars, numVars)  + this->right->evaluate(vars, numVars);
    }

    //MulNode
    MulNode::MulNode(Node* left_, Node* right_) : BinOpNode(left_, right_){}
    double MulNode::evaluate(const Variable* vars, int numVars) const
    {
        return this->left->evaluate(vars, numVars) * this->right->evaluate(vars, numVars);
    }

    //BinOpNode
    BinOpNode::BinOpNode(Node* left_, Node* right_){
        this->left = left_;
        this->right = right_;
    }
    BinOpNode::~BinOpNode(){
        delete this->left;
        delete this->right;
    }

    //VarNode
    VarNode::VarNode(const char* name_){
        this->var = new Variable(name_);
    }

    double VarNode::evaluate(const Variable* vars, int numVars) const
    {
        for(int i = 0; i < numVars; i++){
            if (this->var->get_name() == vars[i].get_name()){
                return double(vars[i]);
            }
        }
        return 0;
    }

    VarNode::~VarNode(){
        delete var;
    }
}
