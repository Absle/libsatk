#ifndef SATK_COMMON_HPP
#define SATK_COMMON_HPP

#include "Config.hpp"

#include <bitset>
#include <cassert>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace Satk
{
    using mask = std::bitset<MAX_NCOMPS_REG>;
    template<class A, class B> using dictionary = std::unordered_map<A, B>;
    using uid = std::size_t;

    namespace internal
    {
        template<class T>
        uid generate_uid(T& obj)
        {
            uid id = reinterpret_cast<uid>(&obj);
            return id;
        }
    }
}

#endif