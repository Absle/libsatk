#ifndef SATK_CONFIG_HPP
#define SATK_CONFIG_HPP

namespace Satk
{
    const static int MAX_NCOMPS_REG = 64; // max number of types that can be used as components
    const static int COMP_SOFT_CAP = 512; // number of reserved spaces in each component storage vector
    constexpr static char const * DEF_COMP_NAME = "NONAME";
}


#endif