#ifndef SATK_ECS_HPP
#define SATK_ECS_HPP

#include "Common.hpp"
#include "Component_Manager.hpp"

namespace Satk
{
    class Ecs
    {
        public:
        // create a new empty entity
        uid create();

        // destroy an existing entity
        void destroy(uid id);

        // add and (possibly) initialize a component Comp_T to entity
        template<class Comp_T, class... Mems>
        void add(uid id, Mems... ms)
        {
            assert(internal::Component_Manager::Component<Comp_T>::get_reg_id() >= 0 &&
                "Component failed to register!");
            
        }

        // remove a component Comp_T from entity
        template<class Comp_T>
        void remove(uid id);

        private:

    };
}

#endif