
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file utc_time.hpp
 *
 * @brief
 * Coordinated Universal Time (UTC) declaration.
 */


#ifndef SIMPLYDT_LIB_COORDINATED_UNIVERSAL_TIME_STRUCT_H_
#define SIMPLYDT_LIB_COORDINATED_UNIVERSAL_TIME_STRUCT_H_

#include "simplydt/time/abstract_time.hpp"
#include "simplydt/time/concepts/time_api_contract.hpp"
#include "simplydt/time/utc/utc_defs.hpp"

namespace simplydt::utc
{

struct UTCTime final : public TimeSystem<UTCTime, Time_t> {
    /*! @brief One complete day. */
    static constexpr Time_t FULL_DAY = SECONDS_IN_DAY;

    /*!
     * @brief
     * Construct UTC time using hour, minute, and second
     * values.
     */
    constexpr UTCTime(const uint8_t hour, const uint8_t minute, const uint8_t second) noexcept
        : TimeSystem<UTCTime, Time_t>{},
        timeInDay{useDefaultIfInvalid(TimeCalc::timeToSerialSecs(hour, minute, second))}
    {
        //
    }

    /*!
     * @brief
     * Construct UTC time using hour and minute values;
     * assume second = 0.
     */
    constexpr UTCTime(const uint8_t hour, const uint8_t minute) noexcept
        : TimeSystem<UTCTime, Time_t>{},
        timeInDay{useDefaultIfInvalid(TimeCalc::timeToSerialSecs(hour, minute, 0))}
    {
        //
    }

    /*!
     * @brief
     * Construct UTC time using an hour value; assume
     * minute and second = 0.
     */
    explicit constexpr UTCTime(const uint8_t hour) noexcept
        : TimeSystem<UTCTime, Time_t>{},
        timeInDay{useDefaultIfInvalid(TimeCalc::timeToSerialSecs(hour, 0, 0))}
    {
        //
    }

    /*!
     * @brief
     * Construct default UTC time (midnight).
     */
    constexpr UTCTime() noexcept : TimeSystem<UTCTime, Time_t>{}, timeInDay{MIDNIGHT}
    {
        //
    }

    ~UTCTime() = default;

    friend inline std::ostream& operator<<(std::ostream& os, const UTCTime time) noexcept
    {
        // TODO: INCOMPLETE!!!
        return os;
    }

    [[nodiscard]] constexpr uint8_t hour() const noexcept
    {
        return TimeCalc::hourFromSerialSecs(this->timeInDay);
    }

    [[nodiscard]] constexpr uint8_t minute() const noexcept
    {
        return TimeCalc::minuteFromSerialSecs(this->timeInDay);
    }

    [[nodiscard]] constexpr uint8_t second() const noexcept
    {
        return TimeCalc::secondFromSerialSecs(this->timeInDay);
    }

  private:
    Time_t timeInDay; ///< Time of day
};

} // namespace simplydt::utc

#endif // SIMPLYDT_LIB_COORDINATED_UNIVERSAL_TIME_STRUCT_H_
