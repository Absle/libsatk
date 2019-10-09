#ifndef SATK_COMPONENT_TRAITS_HPP
#define SATK_COMPONENT_TRAITS_HPP

#include "Common.hpp"

namespace Satk
{
    template<class Comp_T>
    struct Component_Traits
    {
        constexpr static char const * name = DEF_COMP_NAME;
    };
}

#endif