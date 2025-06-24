
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

#include "simplydt/common/c_datetime_utils.h"
#include "simplydt/common/stl_chrono_utils.hpp"

simplydt_UnixTimestamp simplydt_get_now_system_time_secs(void)
{
    return static_cast<simplydt_UnixTimestamp>(
        std::chrono::duration_cast<std::chrono::seconds>(
            simplydt::stl::SystemClock::now().time_since_epoch()
        ).count()
    );
}
