
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_time.hpp
 *
 * @brief
 * Abstract time system declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_TEMPORAL_TIME_H_
#define SIMPLYDT_LIB_BASE_TEMPORAL_TIME_H_

#include "simplydt/common/time_defs.hpp"

namespace simplydt
{

/*!
 * @brief
 * TODO: INCOMPLETE COMMENT!!!
 */
template <typename Time_Impl, typename Repr_T>
struct TimeSystem {
    /*! @brief Time system implementation. */
    using Time = Time_Impl;
    /*! @brief Time system base class. */
    using Base = TimeSystem<Time_Impl, Repr_T>;
    /*! @brief Underlying time representation type. */
    using Repr_Type = Repr_T;

    /*!
     * @brief
     * Converts an hour, minute, and second combination to
     * a serial count of seconds since start of day.
     *
     * @return
     * Seconds since start of day
     */
    [[nodiscard]] static constexpr Time_t toSerialSeconds(
        const uint8_t hr, const uint8_t min, const uint8_t sec
    ) noexcept
    {
        if ((hr >= HOURS_IN_DAY) || (min >= MINUTES_IN_HOUR) || (sec >= SECONDS_IN_MINUTE))
            return MIDNIGHT; // Invalid time parameters

        const uint32_t secsSinceMidnight =
            (hr * SECONDS_IN_HOUR) + (min * SECONDS_IN_MINUTE) + sec;
        return static_cast<Time_t>(secsSinceMidnight);
    }

    /*!
     * @brief
     * Calculates hour of time from serial count of
     * seconds since start of day.
     *
     * @return
     * Time hour component
     */
    [[nodiscard]] static constexpr uint8_t hourFromSerialSecs(const Time_t secs_in_day
    ) noexcept
    {
        if (secs_in_day >= SECONDS_IN_DAY)
            return 0; // Invalid serial seconds count

        return static_cast<uint8_t>(secs_in_day / SECONDS_IN_HOUR);
    }

    /*!
     * @brief
     * Calculates minute of time from serial count of
     * seconds since start of day.
     *
     * @return
     * Time minute component
     */
    [[nodiscard]] static constexpr uint8_t minuteFromSerialSecs(const Time_t secs_in_day
    ) noexcept
    {
        if (secs_in_day >= SECONDS_IN_DAY)
            return 0; // Invalid serial seconds count

        return static_cast<uint8_t>((secs_in_day % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE);
    }

    /*!
     * @brief
     * Calculates second of time from serial count of
     * seconds since start of day.
     *
     * @return
     * Time second component
     */
    [[nodiscard]] static constexpr uint8_t secondFromSerialSecs(const Time_t secs_in_day
    ) noexcept
    {
        if (secs_in_day >= SECONDS_IN_DAY)
            return 0; // Invalid serial seconds count

        return static_cast<uint8_t>(secs_in_day % SECONDS_IN_MINUTE);
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
