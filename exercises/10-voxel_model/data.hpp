#pragma once

#include <array>
#include "vector.hpp"

// A single voxel from which models can be formed.
struct Voxel
{
    Voxel() = default;

    Voxel(int _x, int _y, bool _isSolid)
        : isSolid(_isSolid),
        position(_x, _y)
    {
    }

    bool isSolid;
    Math::IVec2 position;
};


/*
                #
               ###  
            |  ###  |
            #########
        |    #######    |
        ##    #####    ##
        ##     # ###   ##
       ###  ##      #  ###
       ########    #######
        ##  ##### ###  ##
            ###   ###
            ###   ###

*/
const std::array<Voxel, 92> DATA = {
    Voxel{ 16, 0, true },
    Voxel{ 15, 1, true },
    Voxel{ 16, 1, true },
    Voxel{ 17, 1, true },
    Voxel{ 12, 2, false },
    Voxel{ 15, 2, true },
    Voxel{ 16, 2, true },
    Voxel{ 17, 2, true },
    Voxel{ 20, 2, false },
    Voxel{ 12, 3, true },
    Voxel{ 13, 3, true },
    Voxel{ 14, 3, true },
    Voxel{ 15, 3, true },
    Voxel{ 16, 3, true },
    Voxel{ 17, 3, true },
    Voxel{ 18, 3, true },
    Voxel{ 19, 3, true },
    Voxel{ 20, 3, true },
    Voxel{ 8, 4, false },
    Voxel{ 13, 4, true },
    Voxel{ 14, 4, true },
    Voxel{ 15, 4, true },
    Voxel{ 16, 4, true },
    Voxel{ 17, 4, true },
    Voxel{ 18, 4, true },
    Voxel{ 19, 4, true },
    Voxel{ 24, 4, false },
    Voxel{ 8, 5, true },
    Voxel{ 9, 5, true },
    Voxel{ 14, 5, true },
    Voxel{ 15, 5, true },
    Voxel{ 16, 5, true },
    Voxel{ 17, 5, true },
    Voxel{ 18, 5, true },
    Voxel{ 23, 5, true },
    Voxel{ 24, 5, true },
    Voxel{ 8, 6, true },
    Voxel{ 9, 6, true },
    Voxel{ 15, 6, true },
    Voxel{ 17, 6, true },
    Voxel{ 18, 6, true },
    Voxel{ 19, 6, true },
    Voxel{ 23, 6, true },
    Voxel{ 24, 6, true },
    Voxel{ 7, 7, true },
    Voxel{ 8, 7, true },
    Voxel{ 9, 7, true },
    Voxel{ 12, 7, true },
    Voxel{ 13, 7, true },
    Voxel{ 20, 7, true },
    Voxel{ 23, 7, true },
    Voxel{ 24, 7, true },
    Voxel{ 25, 7, true },
    Voxel{ 7, 8, true },
    Voxel{ 8, 8, true },
    Voxel{ 9, 8, true },
    Voxel{ 10, 8, true },
    Voxel{ 11, 8, true },
    Voxel{ 12, 8, true },
    Voxel{ 13, 8, true },
    Voxel{ 14, 8, true },
    Voxel{ 19, 8, true },
    Voxel{ 20, 8, true },
    Voxel{ 21, 8, true },
    Voxel{ 22, 8, true },
    Voxel{ 23, 8, true },
    Voxel{ 24, 8, true },
    Voxel{ 25, 8, true },
    Voxel{ 8, 9, true },
    Voxel{ 9, 9, true },
    Voxel{ 12, 9, true },
    Voxel{ 13, 9, true },
    Voxel{ 14, 9, true },
    Voxel{ 15, 9, true },
    Voxel{ 16, 9, true },
    Voxel{ 18, 9, true },
    Voxel{ 19, 9, true },
    Voxel{ 20, 9, true },
    Voxel{ 23, 9, true },
    Voxel{ 24, 9, true },
    Voxel{ 12, 10, true },
    Voxel{ 13, 10, true },
    Voxel{ 14, 10, true },
    Voxel{ 18, 10, true },
    Voxel{ 19, 10, true },
    Voxel{ 20, 10, true },
    Voxel{ 12, 11, true },
    Voxel{ 13, 11, true },
    Voxel{ 14, 11, true },
    Voxel{ 18, 11, true },
    Voxel{ 19, 11, true },
    Voxel{ 20, 11, true }
};