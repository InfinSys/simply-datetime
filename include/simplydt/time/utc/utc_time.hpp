
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file utc_time.hpp
 *
 * @brief
 * Coordinated Universal Time (UTC) declaration.
 */


#ifndef SIMPLYDT_LIB_COORDINATED_UNIVERSAL_TIME_STANDARD_H_
#define SIMPLYDT_LIB_COORDINATED_UNIVERSAL_TIME_STANDARD_H_

#include "simplydt/time/abstract_time.hpp"
#include "simplydt/time/concepts/time_api_contract.hpp"
#include "simplydt/time/utc/utc_defs.hpp"

namespace simplydt::utc
{

/*!
 * @brief
 * Coordinated Universal Time.
 *
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 */
struct UTCTime : public SerialTimeStandard<UTCTime, Seconds, Time_t> {
    /*!
     * @brief
     * Identifies the time system represented by this
     * implementation.
     */
    static constexpr TimeStandard standard = TimeStandard::UTC;

    /*!
     * @brief
     * Indicates the resolution this time system is based
     * on.
     */
    static constexpr TimeComponent resolution = TimeComponent::SECOND;

    /*!
     * @brief
     * Indicates whether the time system is based on
     * celestial motion.
     *
     * @details
     * Specifies that UTC is a celestial time system.
     * While its rate is derived from atomic clocks, it is
     * fundamentally tied to the Earth's rotation (a
     * celestial phenomenon) through the mechanism of leap
     * seconds.
     */
    static constexpr bool isCelestialTimeSystem = true;

    /*!
     * @brief
     * Indicates whether the time system is a pure atomic
     * time scale.
     *
     * @details
     * Specifies that UTC is not a pure atomic time system
     * which is a continuous time scale based solely on
     * atomic clocks.
     */
    static constexpr bool isPureAtomicTimeSystem = false;

    /*!
     * @brief
     * Indicates whether the time system is derived from an
     * atomic time scale.
     */
    static constexpr bool isAtomicDerivedTimeSystem = true;

    /*!
     * @brief
     * Construct UTC time with hour, minute, and second
     * values.
     */
    constexpr UTCTime(const uint8_t hour, const uint8_t minute, const uint8_t second) noexcept
        : SerialTimeStandard<UTCTime, Seconds, Time_t>{
              Base::toSerialSeconds(hour, minute, second)
          }
    { }

    /*! @brief Construct default UTC time (00:00:00 AM) */
    constexpr UTCTime() noexcept : SerialTimeStandard<UTCTime, Seconds, Time_t>{MIDNIGHT}
    { }

    ~UTCTime() = default;

    /*!
     * @brief
     * Time hour component (24-hour).
     *
     * @return
     * Hour of UTC time
     */
    [[nodiscard]] constexpr uint8_t hour() const noexcept
    {
        return Base::hourFromSerialSecs(this->serialUnits);
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
        const uint8_t hour24 = Base::hourFromSerialSecs(this->serialUnits);
        return (hour24 % 12) + ((hour24 == 12 || hour24 == 0) * 12);
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
        if (Base::hourFromSerialSecs(this->serialUnits) >= 12)
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
        if (Base::hourFromSerialSecs(this->serialUnits) >= 12)
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
        return Base::minuteFromSerialSecs(this->serialUnits);
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
        return Base::secondFromSerialSecs(this->serialUnits);
    }

    /*!
     * @brief
     * Compose string representation of UTC time.
     *
     * @return
     * UTC time as string
     */
    [[nodiscard]] std::string toStr() const noexcept
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
};

SIMPLYDT_ENFORCE_TIME_CONTRACT(UTCTime);

} // namespace simplydt::utc

#endif // SIMPLYDT_LIB_COORDINATED_UNIVERSAL_TIME_STANDARD_H_
