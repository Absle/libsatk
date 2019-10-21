#include "ecs/Ecs.hpp"

namespace Satk
{
    uid Ecs::create()
    {
        return entities.push_back(mask());
    }


    void Ecs::destroy(uid id)
    {
        remove_all(id);
        entities.swap_pop(id);
    }
}