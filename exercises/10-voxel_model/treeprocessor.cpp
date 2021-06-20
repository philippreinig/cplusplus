#include "treeprocessor.hpp"
// #include <unordered_map>
// #include <vector>
#include <algorithm>

// GRUPPENEINREICHUNG MIT DANNY SCHMIDT

void DrawProcessor::processLeaf(const Voxel& voxel)
{
    renderer.draw(voxel.position, voxel.isSolid ? '#' : '|');
}

// todo: implement
void FlattenProcessor::processLeaf(const Voxel& voxel)
{
    // std::cout << "FlattenProcessor::processLeaf called" << std::endl;
    this->voxel_map.insert(std::make_pair(voxel.position, voxel));
}

FlattenProcessor::FlattenProcessor(VoxelMap& voxel_map_) : voxel_map{voxel_map_} {}

using namespace std;
using namespace Math;

bool voxel_contained_in_vector(Voxel voxel, std::vector<Voxel>* vector){
    for(Voxel element : *vector){
        if (element.position == voxel.position) return true;
    }
    return false;
}

void get_all_voxels_in_component(Voxel voxel, VoxelMap& map, std::vector<Voxel>* vector){
    // std::cout << "get_all_voxels_in_component of voxel at: " << voxel.position[0] << ", " << voxel.position[1] << std::endl;
    IVec2 voxel_position = voxel.position;
    IVec2 top(voxel_position[0], voxel_position[1] + 1);
    IVec2 right(voxel_position[0] + 1, voxel_position[1]);
    IVec2 bottom(voxel_position[0], voxel_position[1] - 1);
    IVec2 left(voxel_position[0] - 1, voxel_position[1]);
    
    // std::cout << "top, right, bottom, left created" << std::endl;

    vector->push_back(map[voxel_position]);

    if (map.find(top) != map.end() && !voxel_contained_in_vector(map[top], vector)){
        vector->push_back(map[top]);
        get_all_voxels_in_component(map[top], map, vector);
    }
    if (map.find(right) != map.end() && !voxel_contained_in_vector(map[right], vector)){
        vector->push_back(map[right]);
        get_all_voxels_in_component(map[right], map, vector);
        map.erase(right);
    }
    if (map.find(bottom) != map.end() && !voxel_contained_in_vector(map[bottom], vector)){
        vector->push_back(map[bottom]);
        get_all_voxels_in_component(map[bottom], map, vector);
        map.erase(bottom);
    }
    if (map.find(left) != map.end() && !voxel_contained_in_vector(map[left], vector)){
        vector->push_back(map[left]);
        get_all_voxels_in_component(map[left], map, vector);
        map.erase(left);
    }
}
// Extracts a single connected model from the map and puts it into the target tree.
// Returns false when the map is already empty, true otherwise.
// todo: implement
bool extract(VoxelMap& map, QuadTree<Voxel>& target)
{
    // std::cout << "extract: " << (map.empty() ? "true" : "false") << std::endl;
    if (map.empty()) return false;
    auto map_iterator = map.begin();
    Voxel voxel = (*map_iterator).second;
    
    // std::cout << "Voxel voxel = (*map_iterator).second;" << std::endl;

    std::vector<Voxel>* vector = new std::vector<Voxel>;

    // std::cout << "std::vector<Voxel>* vector = new std::vector<Voxel>;" << std::endl;

    get_all_voxels_in_component(voxel, map, vector);

    // std::cout << "get_all_voxels_in_component(voxel, map, vector);" << std::endl;

    for (Voxel element : *vector){
        target.insert(element.position[0], element.position[1], element);
        map.erase(element.position);
    }
    delete vector;
    return true;


}

// Extracts all coherent models from the tree and puts them into new trees.
// todo: implement
void extractSubModels(QuadTree<Voxel>& tree, vector<unique_ptr<QuadTree<Voxel>>>& subTrees)
{
    std::unordered_map<IVec2, Voxel> map;
    FlattenProcessor flatten_processor(map);
    tree.traverse(flatten_processor);

    VoxelMap filled_map = flatten_processor.get_map();
    // std::cout << "after traversing with FlattenProcessor size of map is: " << map.size() << std::endl;
    // std::cout << "size of map of flatten processor is: " << flatten_processor.get_map().size() << std::endl;

    QuadTree<Voxel>* voxel_quad_tree;


    int counter = 0; 
    while(extract(filled_map, *(voxel_quad_tree = new QuadTree<Voxel>))){
        // std::cout << "extracting subtree " << counter << std::endl;
        ++counter;
        subTrees.push_back(unique_ptr<QuadTree<Voxel>>(voxel_quad_tree));
    }

    delete voxel_quad_tree;



}
