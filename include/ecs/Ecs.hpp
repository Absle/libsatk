#ifndef SATK_ECS_HPP
#define SATK_ECS_HPP

#include "common/Config.hpp"
#include "common/Map_Vector.hpp"
#include "ecs/Component_Manager.hpp"

#include <bitset>
#include <cassert>

// TODO: remove test
#include <iostream>

namespace Satk
{
    using mask = std::bitset<MAX_NCOMPS_REG>;

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
            int reg_id = internal::Component_Manager::Component<Comp_T>::get_reg_id();
            assert(reg_id >= 0 && "Component failed to register!");
            
            // adding proper bit to entity mask
            mask &entity = entities.at(id);
            mask comp_mask = 1 << reg_id;
            entity |= comp_mask;

            internal::Component_Manager::Component<Comp_T>::store.insert(id, (Comp_T){ms...});
        }

        // remove a component Comp_T from entity
        template<class Comp_T>
        void remove(uid id)
        {
            // removing component mask from entity
            int reg_id = internal::Component_Manager::Component<Comp_T>::get_reg_id();
            mask comp_mask = 1 << reg_id;
            mask inverted = comp_mask.flip();
            mask &entity = entities.at(id);
            entity &= inverted;
            
            internal::Component_Manager::Component<Comp_T>::store.swap_pop(id); // remove component from store
        }

        template<class... Comp_Ts>
        std::vector<uid> list()
        {

        }

        // remove all components from an entity
        void remove_all(uid id);

        private:
        internal::Map_Vector<mask> entities;
    };
}

#endif