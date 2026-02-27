// SPDX - License - Identifier : MIT
#pragma once
#include "ocf/platform//platform.h"
#include <stdint.h>

namespace ocf {

class OCF_API Object {
public:
    Object() = default;
    Object(uint32_t id)
        : m_id(id)
    {
    }

    virtual ~Object() = default;

private:
    uint32_t m_id;
};

} // namespace ocf
