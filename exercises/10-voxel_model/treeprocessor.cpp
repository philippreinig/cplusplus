#include "treeprocessor.hpp"

void DrawProcessor::processLeaf(const Voxel& voxel)
{
    renderer.draw(voxel.position, voxel.isSolid ? '#' : '|');
}

// todo: implement
void FlattenProcessor::processLeaf(const Voxel& voxel)
{
}

using namespace std;
using namespace Math;

// Extracts a single connected model from the map and puts it into the target tree.
// Returns false when the map is already empty, true otherwise.
// todo: implement
bool extract(VoxelMap& map, QuadTree<Voxel>& target)
{
}

// Extracts all coherent models from the tree and puts them into new trees.
// todo: implement
void extractSubModels(QuadTree<Voxel>& tree, vector<unique_ptr<QuadTree<Voxel>>>& subTrees)
{
}