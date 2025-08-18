
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_time.hpp
 *
 * @brief
 * Base CRTP time declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_TEMPORAL_TIME_H_
#define SIMPLYDT_LIB_BASE_TEMPORAL_TIME_H_

#include "simplydt/common/time_defs.hpp"
#include "simplydt/time/time_math.hpp"

namespace simplydt
{

template <typename Time_Impl, typename Integer_T>
struct TimeSystem {
    /*! @brief Time system implementation. */
    using Time = Time_Impl;
    /*! @brief Underlying time representation type. */
    using Repr_Type = Integer_T;

    /*!
     * @brief
     * Intercepts invalid time-in-day values and returns
     * midnight (00:00:00 AM).
     *
     * @return
     * Provided time-in-day value, midnight otherwise
     */
    [[nodiscard]] static constexpr Repr_Type useDefaultIfInvalid(const Repr_Type& time_in_day
    ) noexcept
    {
        return time_in_day >= Time::FULL_DAY ? MIDNIGHT : time_in_day;
    }

  private:
    TimeSystem()  = default;
    ~TimeSystem() = default;
    friend Time_Impl;

    [[nodiscard]] const Time& thisImpl() const noexcept
    {
        return static_cast<const Time&>(*this);
    }

    [[nodiscard]] Time& thisImpl() noexcept
    {
        return static_cast<Time&>(*this);
    }
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_TEMPORAL_TIME_H_
