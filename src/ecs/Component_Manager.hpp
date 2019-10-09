#ifndef SATK_COMPONENT_MANAGER_HPP
#define SATK_COMPONENT_MANAGER_HPP

#include "Common.hpp"
#include "Component_Traits.hpp"

namespace Satk
{
    namespace internal
    {
        class Component_Manager
        {
            public:
            template<class Comp_T>
            class Component
            {
                public:
                static std::vector<Comp_T> store;
                static int get_reg_id(){ return reg_id; }

                private:
                static int reg_id;
            };

            private:
            // running count of the number of components registered
            static int ncomps_reg;

            template<class Comp_T>
            static int register_component()
            {
                assert(ncomps_reg < MAX_NCOMPS_REG && "Too many components registered");
                int reg_id = ncomps_reg;
                ++ncomps_reg;
                Component<Comp_T>::store.reserve(COMP_SOFT_CAP);
                std::clog << "Registered component \"" << Component_Traits<Comp_T>::name << "\" as id #" << reg_id << '\n';
                return reg_id;
            }
        };
    }
}

#endif