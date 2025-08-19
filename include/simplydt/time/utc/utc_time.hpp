
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
#include "simplydt/time/units/time_units.hpp"
#include "simplydt/time/utc/utc_defs.hpp"

namespace simplydt::utc
{

/*!
 * @brief
 * TODO: INCOMPLETE COMMENT!!!
 */
struct UTCTime final : public TimeSystem<UTCTime, Time_t> {
    /*!
     * @brief
     * Identifies the time system represented by this
     * implementation.
     */
    static constexpr TimeStandard standard = TimeStandard::UTC;

    /*!
     * @brief
     * Indicates the resolution this time system is based on.
     */
    static constexpr TimeComponent resolution = TimeComponent::SECOND;

    /*!
     * @brief
     * Indicates whether the time system is based on celestial
     * motion.
     *
     * @details
     * Specifies that UTC is a celestial time system. While its
     * rate is derived from atomic clocks, it is fundamentally
     * tied to the Earth's rotation (a celestial phenomenon)
     * through the mechanism of leap seconds.
     */
    static constexpr bool isCelestialTimeSystem = true;

    /*!
     * @brief
     * Indicates whether the time system is a pure atomic time
     * scale.
     *
     * @details
     * Specifies that UTC is not a pure atomic time system which
     * is a continuous time scale based solely on atomic clocks.
     */
    static constexpr bool isPureAtomicTimeSystem = false;

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
     * Intercepts invalid time parameters and returns midnight
     * (00:00:00 AM).
     *
     * @return
     * Midnight if invalid, provided time-in-day value otherwise
     */
    [[nodiscard]] static constexpr Time_t useDefaultIfInvalid(
        const uint8_t& hour, const uint8_t& minute, const uint8_t& second
    ) noexcept
    {
        if ((hour >= HOURS_IN_DAY) || (minute >= MINUTES_IN_HOUR) ||
            (second >= SECONDS_IN_MINUTE))
            return MIDNIGHT; // Invalid time parameters

        return Base::toSerialSeconds(hour, minute, second);
    }

    /*!
     * @brief
     * Intercepts invalid serial seconds and returns midnight
     * (00:00:00 AM).
     *
     * @return
     * Midnight if invalid, provided time-in-day value otherwise
     */
    [[nodiscard]] static constexpr Time_t useDefaultIfInvalid(const Seconds& secs_in_day
    ) noexcept
    {
        if ((secs_in_day.count() < MIDNIGHT) || (secs_in_day.count() >= SECONDS_IN_DAY))
            return MIDNIGHT;

        return static_cast<Time_t>(secs_in_day.count());
    }

    /*!
     * @brief
     * Construct UTC time using hour, minute, and second
     * values.
     */
    constexpr UTCTime(const uint8_t hour, const uint8_t minute, const uint8_t second) noexcept
        : TimeSystem<UTCTime, Time_t>{}, timeInDay{useDefaultIfInvalid(hour, minute, second)}
    {
        //
    }

    /*!
     * @brief
     * Construct UTC time using hour and minute values;
     * assume second = 0.
     */
    constexpr UTCTime(const uint8_t hour, const uint8_t minute) noexcept
        : TimeSystem<UTCTime, Time_t>{}, timeInDay{useDefaultIfInvalid(hour, minute, 0)}
    {
        //
    }

    /*!
     * @brief
     * Construct UTC time using an hour value; assume
     * minute and second = 0.
     */
    explicit constexpr UTCTime(const uint8_t hour) noexcept
        : TimeSystem<UTCTime, Time_t>{}, timeInDay{useDefaultIfInvalid(hour, 0, 0)}
    {
        //
    }

    /*!
     * @brief
     * Construct UTC time from seconds since start of
     * day.
     */
    constexpr UTCTime(const Seconds secs_in_day) noexcept
        : TimeSystem<UTCTime, Time_t>{}, timeInDay{useDefaultIfInvalid(secs_in_day)}
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
        os << time.toStr();
        return os;
    }

    /*! @brief Evaluate equivalence of UTC times. */
    [[nodiscard]] constexpr bool operator==(const UTCTime time) const noexcept
    {
        return this->timeInDay == time.timeInDay;
    }

    /*! @brief Determine if left-hand side is sequentially before right-hand side. */
    [[nodiscard]] constexpr bool operator<(const UTCTime time) const noexcept
    {
        return this->timeInDay < time.timeInDay;
    }

    /*! @brief Determine if left-hand side is sequentially after right-hand side. */
    [[nodiscard]] constexpr bool operator>(const UTCTime time) const noexcept
    {
        return this->timeInDay > time.timeInDay;
    }

    [[nodiscard]] constexpr bool operator<=(const UTCTime time) const noexcept
    {
        return this->timeInDay <= time.timeInDay;
    }

    [[nodiscard]] constexpr bool operator>=(const UTCTime time) const noexcept
    {
        return this->timeInDay >= time.timeInDay;
    }

    /*! @brief Index UTC time components. */
    [[nodiscard]] std::optional<uint8_t> operator[](const TimeComponent component
    ) const noexcept
    {
        return this->getComponent(component);
    }

    /*!
     * @brief
     * Evaluate if time is midnight.
     *
     * @return
     * True if time is midnight
     */
    [[nodiscard]] constexpr bool isDefault() const noexcept
    {
        return this->timeInDay == MIDNIGHT;
    }

    /*!
     * @brief
     * Time hour component (24-hour).
     *
     * @return
     * Hour of UTC time
     */
    [[nodiscard]] constexpr uint8_t hour() const noexcept
    {
        return Base::hourFromSerialSecs(this->timeInDay);
    }

    /*!
     * @brief
     * Time hour component (12-hour).
     *
     * @return
     * Hour of UTC time
     */
    [[nodiscard]] constexpr uint8_t hour12() const noexcept
    {
        return Base::hourFromSerialSecs(this->timeInDay) % 12;
    }

    /*!
     * @brief
     * Time meridiem phase literal.
     *
     * @return
     * Meridiem phase abbreviation
     */
    [[nodiscard]] constexpr const char* hourPhaseStr() const noexcept
    {
        if (this->hour() >= 12)
            return MeridiemPhases[PM];

        return MeridiemPhases[AM];
    }

    /*!
     * @brief
     * Time meridiem phase indicator.
     *
     * @return
     * Meridiem phase enum representation
     */
    [[nodiscard]] constexpr MeridiemPhase hourPhaseEnumRepr() const noexcept
    {
        if (this->hour() >= 12)
            return MeridiemPhase::PM;

        return MeridiemPhase::AM;
    }

    /*!
     * @brief
     * Time minute component.
     *
     * @return
     * Minute of UTC time
     */
    [[nodiscard]] constexpr uint8_t minute() const noexcept
    {
        return Base::minuteFromSerialSecs(this->timeInDay);
    }

    /*!
     * @brief
     * Time second component.
     *
     * @return
     * Second of UTC time
     */
    [[nodiscard]] constexpr uint8_t second() const noexcept
    {
        return Base::secondFromSerialSecs(this->timeInDay);
    }

    /*!
     * @brief
     * Compose string representation of UTC time.
     *
     * @return
     * UTC time as string
     */
    [[nodiscard]] const std::string toStr() const noexcept
    {
        const char delimiter = ':';

        std::string timeStr;
        timeStr.reserve(12);
        timeStr += (toDoubleDigitStr(this->hour()) + delimiter);
        timeStr += (toDoubleDigitStr(this->minute()) + delimiter);
        timeStr += (toDoubleDigitStr(this->second()) + ' ');
        timeStr += this->hourPhaseStr();
        return timeStr;
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] std::optional<uint8_t> getComponent(const TimeComponent component
    ) const noexcept
    {
        switch (component) {
        case TimeComponent::HOUR:
            return this->hour();
        case TimeComponent::MINUTE:
            return this->minute();
        case TimeComponent::SECOND:
            return this->second();
        default: // Invalid component request
            return std::nullopt;
        };
    }

  private:
    Time_t timeInDay; ///< Time of day
};

SIMPLYDT_ENFORCE_TIME_CONTRACT(UTCTime);

} // namespace simplydt::utc

#endif // SIMPLYDT_LIB_COORDINATED_UNIVERSAL_TIME_STRUCT_H_
