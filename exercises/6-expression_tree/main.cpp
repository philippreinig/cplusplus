#include <iostream>
#include "exptree.hpp"

using namespace ExpTree;
using namespace std;

int main(int, char**)
{
    // If everything is correct you should see a (streched) circle as output.
    Variable vars[2] = {"x", "y"};

    const Node* root = new SumNode(
                            new MulNode(new VarNode("x"), new VarNode("x")),
                            new MulNode(new VarNode("y"), new VarNode("y"))
                        );

    for(int iy = 0; iy < 14; ++iy)
    {
        vars[1] = iy - 5.;
        for(int ix = 0; ix < 64; ++ix)
        {
            vars[0] = ix - 10.;
            double val = root->evaluate(vars, 2);
            if(val > 15. && val < 24.)
                cout << "#";
            else cout << " ";
        }
        cout << endl;
    }

    delete root;
}
