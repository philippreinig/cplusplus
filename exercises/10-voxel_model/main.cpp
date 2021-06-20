#include "quadtree.hpp"
#include "data.hpp"
#include "treeprocessor.hpp"

#include <vector>
#include <memory>
#include <fstream>

using namespace std;
using namespace Math;

/* A Quadtree is a data structure that can be helpful in processing meshes or images.
 * In this example it is used to store a model of a spaceship that consists of small pieces
 * of the same size, named voxels.
 * The given model is damaged an thus breaks into pieces.
 * These new models need to be found and put into there own trees so that they can be processed independently.
 * A model is considered coherent if all voxels are connected.
 * example: one model       two models
 *              ##           #
 *              #           #
 * Since the given Quadtree has no easy way to access direct neighbours the voxels should be 
 * transfered into a different data structure first.
 * A 2-dimensional array could work well for this, but especially considering the more common 3d case
 * it would grow to an unfavorable size while beeing mostly empty. (e.g. spacestation with long arms)
 * Thus we want to use a hashmap using a voxel's position as key. Th
 * is allows for constant access time
 * based on the position and a size requierement that is not significantly higher than that of the actual voxels.
 *      todo:   * add hash specialisation to make unordered_map work. Math::hashFunc() can be used as hash function
 *              * implement FlattenProcessor
 *              * implement extractSubModels()
 *              * implement extract()
 */


Graphic::Renderer renderer;

int main()
{
    DrawProcessor drawProcessor(renderer);
    renderer.clear();

    // put all data in a QuadTree
    QuadTree<Voxel> tree;
    for(auto& voxel : DATA)
        tree.insert(voxel.position[0], voxel.position[1], voxel);

    // display the voxel model
    tree.traverse(drawProcessor);
    renderer.swap();

    vector<unique_ptr<QuadTree<Voxel>>> subTrees;
    extractSubModels(tree, subTrees);

    // display extracted submodels
    std::cout << std::endl;
    // std::cout << "found " << subTrees.size() << " subtress" << std::endl;
    for(auto& t : subTrees)
    {
        // std::cout << "subtree " << counter << std::endl;
        renderer.clear();
        t->traverse(drawProcessor);
        renderer.swap();
    }

    return 1;
}