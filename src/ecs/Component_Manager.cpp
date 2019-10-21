#include <ecs/Component_Manager.hpp>

namespace Satk
{
    namespace internal
    {
        int Component_Manager::ncomps_reg = 0;
        std::vector<remove_f> Component_Manager::remove_fs;
    }
}
