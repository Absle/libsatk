#ifndef SATK_COMPONENT_MANAGER_HPP
#define SATK_COMPONENT_MANAGER_HPP

#include <common/Config.hpp>
#include <common/Map_Vector.hpp>

#include <cassert>
#include <cxxabi.h>
#include <iostream>
#include <string>
#include <typeinfo>

namespace Satk
{
    namespace internal
    {
        using remove_f = void (*)(uid);

        class Component_Manager
        {
            public:
            template<class Comp_T>
            class Component
            {
                public:
                static Map_Vector<Comp_T> store;
                static std::string name;
                static int get_reg_id(){ return reg_id; }

                static void remove_comp(uid id)
                {
                    store.swap_pop(id);
                }

                private:
                static int reg_id;
            };

            static int get_component_count() { return ncomps_reg; }

            // remove a component using it's reg_id
            static void remove_comp_by_reg_id(int reg_id, uid id)
            {
                remove_fs[reg_id](id);
            }

            private:
            // running count of the number of components registered
            static int ncomps_reg;
            // set of remove functions mapped to their component's reg_id's
            static std::vector<remove_f> remove_fs;

            template<class Comp_T>
            static int register_component(remove_f remove)
            {
                assert(ncomps_reg < MAX_NCOMPS_REG && "Too many components registered");

                // obtaining new reg_id
                int reg_id = ncomps_reg;
                ++ncomps_reg;

                Component<Comp_T>::store.reserve(COMP_SOFT_CAP); // prepping comp store

                // obtaining and storing name of registered class
                int status;
                char *realname = abi::__cxa_demangle(typeid(Comp_T).name(), 0, 0, &status);
                Component<Comp_T>::name = realname;
                free(realname);

                // mapping remove remove function so that it can be referenced by reg_id
                remove_fs.push_back(remove);

                std::clog << "Registered component \"" << Component<Comp_T>::name << "\" as id #" << reg_id << '\n';
                return reg_id;
            }
        };
        //int Component_Manager::ncomps_reg = 0;
        //std::vector<remove_f> Component_Manager::remove_fs(MAX_NCOMPS_REG);

        template<class Comp_T> int Component_Manager::Component<Comp_T>::reg_id = 
            Component_Manager::register_component<Comp_T>(Component_Manager::Component<Comp_T>::remove_comp);
        template<class Comp_T> Map_Vector<Comp_T> Component_Manager::Component<Comp_T>::store;
        template<class Comp_T> std::string Component_Manager::Component<Comp_T>::name;
    }
}

#endif