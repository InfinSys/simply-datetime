
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
#include "simplydt/time/units/time_units.hpp"

namespace simplydt::utc
{

struct UTCTime final : public TimeSystem<UTCTime, Time_t> {
    /*! @brief One complete day. */
    static constexpr Time_t FULL_DAY = SECONDS_IN_DAY;

    /*!
     * @brief
     * Intercepts invalid serial seconds values and returns
     * midnight (00:00:00 AM).
     *
     * @return
     * Midnight if invalid, provided time-in-day value otherwise
     */
    [[nodiscard]] static constexpr Time_t useDefaultIfInvalid(const Time_t& time_in_day
    ) noexcept
    {
        return time_in_day >= SECONDS_IN_DAY ? MIDNIGHT : time_in_day;
    }

    /*!
     * @brief
     * Construct UTC time using hour, minute, and second
     * values.
     */
    constexpr UTCTime(const uint8_t hour, const uint8_t minute, const uint8_t second) noexcept
        : TimeSystem<UTCTime, Time_t>{},
        timeInDay{Base::toSerialSeconds(hour, minute, second)}
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
        timeInDay{Base::toSerialSeconds(hour, minute, 0)}
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
        timeInDay{Base::toSerialSeconds(hour, 0, 0)}
    {
        //
    }

    constexpr UTCTime(const Seconds secs_in_day) noexcept
        : TimeSystem<UTCTime, Time_t>{},
        timeInDay{useDefaultIfInvalid(secs_in_day.count())}
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
        return Base::hourFromSerialSecs(this->timeInDay);
    }

    [[nodiscard]] constexpr uint8_t minute() const noexcept
    {
        return Base::minuteFromSerialSecs(this->timeInDay);
    }

    [[nodiscard]] constexpr uint8_t second() const noexcept
    {
        return Base::secondFromSerialSecs(this->timeInDay);
    }

  private:
    Time_t timeInDay; ///< Time of day
};

} // namespace simplydt::utc

#endif // SIMPLYDT_LIB_COORDINATED_UNIVERSAL_TIME_STRUCT_H_
