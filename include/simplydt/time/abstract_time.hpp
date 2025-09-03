
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_time.hpp
 *
 * @brief
 * Base serial time standard declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_SERIAL_TIME_SYSTEM_H_
#define SIMPLYDT_LIB_BASE_SERIAL_TIME_SYSTEM_H_

#include "simplydt/common/time_defs.hpp"
#include "simplydt/time/units/time_units.hpp"

namespace simplydt
{

/*!
 * @brief
 * Base time standard interface.
 *
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 */
template <typename Standard_Impl, typename Resolution_T, typename Repr_T>
struct SerialTimeStandard {
    /*! @brief Time standard base class. */
    using Base = SerialTimeStandard<Standard_Impl, Resolution_T, Repr_T>;
    /*! @brief Time resolution unit type. */
    using Unit_Resolution = Resolution_T;
    /*! @brief Underlying serial time type. */
    using Repr_Type = Repr_T;

    /*!
     * @brief
     * Converts hour, minute, and second values to a
     * count of seconds since start of day.
     *
     * @return
     * Seconds since midnight (00:00:00 AM)
     */
    [[nodiscard]] static constexpr uint32_t toSerialSeconds(
        const uint8_t hr, const uint8_t min, const uint8_t sec
    ) noexcept
    {
        if ((hr >= HOURS_IN_DAY) || (min >= MINUTES_IN_HOUR) || (sec >= SECONDS_IN_MINUTE))
            return MIDNIGHT; // Invalid time parameters

        const uint32_t secsSinceMidnight =
            (hr * SECONDS_IN_HOUR) + (min * SECONDS_IN_MINUTE) + sec;
        return secsSinceMidnight;
    }

    /*!
     * @brief
     * Calculates hour of time from serial count of
     * seconds since start of day.
     *
     * @return
     * Time hour component
     */
    [[nodiscard]] static constexpr uint8_t hourFromSerialSecs(const uint32_t serial_secs
    ) noexcept
    {
        if (serial_secs >= SECONDS_IN_DAY)
            return 0; // Invalid serial seconds count

        return static_cast<uint8_t>(serial_secs / SECONDS_IN_HOUR);
    }

    /*!
     * @brief
     * Calculates minute of time from serial count of
     * seconds since start of day.
     *
     * @return
     * Time minute component
     */
    [[nodiscard]] static constexpr uint8_t minuteFromSerialSecs(const uint32_t serial_secs
    ) noexcept
    {
        if (serial_secs >= SECONDS_IN_DAY)
            return 0; // Invalid serial seconds count

        return static_cast<uint8_t>((serial_secs % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE);
    }

    /*!
     * @brief
     * Calculates second of time from serial count of
     * seconds since start of day.
     *
     * @return
     * Time second component
     */
    [[nodiscard]] static constexpr uint8_t secondFromSerialSecs(const uint32_t serial_secs
    ) noexcept
    {
        if (serial_secs >= SECONDS_IN_DAY)
            return 0; // Invalid serial seconds count

        return static_cast<uint8_t>(serial_secs % SECONDS_IN_MINUTE);
    }

    /*! @brief Puts human-readable time string in output stream. */
    friend inline std::ostream& operator<<(std::ostream& os, const Base& serial_time) noexcept
    {
        os << serial_time.derivedImpl().toStr();
        return os;
    }

    /*! @brief Evaluates equivalence of times. */
    [[nodiscard]] constexpr bool operator==(const Base& serial_time) const noexcept
    {
        return this->serialUnits == serial_time.serialUnits;
    }

    /*! @brief Determines if left-hand side is sequentially before right-hand side. */
    [[nodiscard]] constexpr bool operator<(const Base& serial_time) const noexcept
    {
        return this->serialUnits < serial_time.serialUnits;
    }

    /*! @brief Determines if left-hand side is sequentially after right-hand side. */
    [[nodiscard]] constexpr bool operator>(const Base& serial_time) const noexcept
    {
        return this->serialUnits > serial_time.serialUnits;
    }

    [[nodiscard]] constexpr bool operator<=(const Base& serial_time) const noexcept
    {
        return this->serialUnits <= serial_time.serialUnits;
    }

    [[nodiscard]] constexpr bool operator>=(const Base& serial_time) const noexcept
    {
        return this->serialUnits >= serial_time.serialUnits;
    }

    /*! @brief Returns this time with provided amount of time units added. */
    [[nodiscard]] constexpr Standard_Impl operator+(const Unit_Resolution units) const noexcept
    {
        Standard_Impl displacedTime{this->derivedImpl()};
        displacedTime.serialUnits += units.count();
        return displacedTime;
    }

    /*! @brief Returns this time with provided amount of time units subtracted. */
    [[nodiscard]] constexpr Standard_Impl operator-(const Unit_Resolution units) const noexcept
    {
        Standard_Impl displacedTime{this->derivedImpl()};
        displacedTime.serialUnits -= units.count();
        return displacedTime;
    }

    /*! @brief Calculates number of precision time units between times. */
    [[nodiscard]] constexpr Unit_Resolution operator-(const Standard_Impl time) const noexcept
    {
        return this->units() - time.units();
    }

    /*!
     * @brief
     * Increments time one unit of precision.
     *
     * @return
     * Reference to self
     */
    Standard_Impl& operator++() noexcept
    {
        this->serialUnits += 1;
        return static_cast<Standard_Impl&>(*this);
    }

    /*!
     * @brief
     * Increments time one unit of precision.
     *
     * @return
     * Copy of previous time
     */
    [[nodiscard]] Standard_Impl operator++(int) noexcept
    {
        Standard_Impl previousTime{this->derivedImpl()};
        this->serialUnits += 1;
        return previousTime;
    }

    /*! @brief Adds provided amount of units to time. */
    Standard_Impl& operator+=(const Unit_Resolution units) noexcept
    {
        this->serialUnits += units.count();
        return static_cast<Standard_Impl&>(*this);
    }

    /*!
     * @brief
     * Decrements time one unit of precision.
     *
     * @return
     * Reference to self
     */
    Standard_Impl& operator--() noexcept
    {
        this->serialUnits -= 1;
        return static_cast<Standard_Impl&>(*this);
    }

    /*!
     * @brief
     * Decrements time one unit of precision.
     *
     * @return
     * Copy of previous time
     */
    [[nodiscard]] Standard_Impl operator--(int) noexcept
    {
        Standard_Impl previousTime{this->derivedImpl()};
        this->serialUnits -= 1;
        return previousTime;
    }

    /*! @brief Subtracts provided amount of units from time. */
    Standard_Impl& operator-=(const Unit_Resolution units) noexcept
    {
        this->serialUnits -= units.count();
        return static_cast<Standard_Impl&>(*this);
    }

    /*!
     * @brief
     * Determines if time is midnight.
     *
     * @return
     * True if serial time count is zero
     */
    [[nodiscard]] constexpr bool isZero() const noexcept
    {
        return this->serialUnits == 0;
    }

    /*!
     * @brief
     * Determines if time is sequentially before provided
     * time.
     *
     * @return
     * True if this time occurs before provided
     */
    [[nodiscard]] constexpr bool isBefore(const Standard_Impl time) const noexcept
    {
        return this->serialUnits < time.serialUnits;
    }

    /*!
     * @brief
     * Determines if time is sequentially after provided
     * time.
     *
     * @return
     * True if this time occurs after provided
     */
    [[nodiscard]] constexpr bool isAfter(const Standard_Impl time) const noexcept
    {
        return this->serialUnits > time.serialUnits;
    }

    /*!
     * @brief
     * Determines if time is sequentially between two
     * times.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * True if this time occurs between provided times
     */
    [[nodiscard]] constexpr bool isBetween(
        const Standard_Impl start_time, const Standard_Impl end_time
    ) const noexcept
    {
        return start_time.serialUnits <= this->serialUnits &&
               this->serialUnits <= end_time.serialUnits;
    }

    /*!
     * @brief
     * Returns serial time count as explicit units
     * of precision.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * Serial time count
     */
    [[nodiscard]] constexpr Unit_Resolution units() const noexcept
    {
        return Unit_Resolution{this->serialUnits};
    }

    /*!
     * @brief
     * Returns constant reference to underlying serial
     * time count.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * Serial time count
     */
    [[nodiscard]] constexpr const Repr_Type& underlying() const noexcept
    {
        return this->serialUnits;
    }

  private:
    Repr_Type serialUnits; ///< Serial time of day

    /*!
     * @brief
     * Intercepts negative units and returns absolute
     * units.
     *
     * @return
     * Absolute unit count
     */
    [[nodiscard]] static constexpr Repr_Type absoluteCount(const Unit_Resolution serial_count
    ) noexcept
    {
        return static_cast<Repr_Type>(
            (serial_count.count() < 0) ? serial_count.count() * -1 : serial_count.count()
        );
    }

    /*! @brief Construct time of day with serial time units. */
    constexpr SerialTimeStandard(const Repr_Type serial_units) noexcept
        : serialUnits{serial_units}
    { }

    /*! @brief Construct time of day with serial time units. */
    constexpr SerialTimeStandard(const Unit_Resolution serial_units) noexcept
        : serialUnits{absoluteCount(serial_units)}
    { }

    ~SerialTimeStandard() = default;
    friend Standard_Impl;

    /*!
     * @brief
     * Returns constant reference to this concrete derivative.
     *
     * @note
     * Do not call this from the derived class, YOU are the
     * `derivedImpl()` (a.k.a `this`)
     */
    [[nodiscard]] constexpr const Standard_Impl& derivedImpl() const noexcept
    {
        return static_cast<const Standard_Impl&>(*this);
    }
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_SERIAL_TIME_SYSTEM_H_
