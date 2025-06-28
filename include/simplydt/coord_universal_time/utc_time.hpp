
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file utc_time.hpp
 *
 * @brief
 * Standalone Coordinated Universal Time declaration.
 */

#ifndef SIMPLYDT_LIB_UTC_TIME_STRUCT_H_
#define SIMPLYDT_LIB_UTC_TIME_STRUCT_H_

#include "simplydt/common/general_defs.hpp"
#include "simplydt/common/string_utils.hpp"
#include "simplydt/coord_universal_time/utc_defs.hpp"
#include <ostream>

namespace simplydt::utc
{

    /*!
     * @brief
     * Broken-down UTC time.
     */
    class Time {

      public:
        /*!
         * @brief
         * Underlying type used to represent UTC time.
         */
        using Underlying_T = uint32_t;

        /*!
         * @brief
         * Factor used to store and retrieve hour values.
         */
        static constexpr Underlying_T HOUR_FACTOR = 10'000;

        /*!
         * @brief
         * Factor used to store and retrieve minute values.
         */
        static constexpr Underlying_T MINUTE_FACTOR = 100;

        /*!
         * @brief
         * Default UTC time (midnight).
         */
        static constexpr Underlying_T DEFAULT_TIME = 0;

        /*!
         * @brief
         * Store encoded UTC time at provided integer address.
         *
         * @return
         * True on success
         */
        static bool encodeUTCTimeIntoInteger(
            Underlying_T* integer,
            const uint8_t& hour,
            const uint8_t& minute,
            const uint8_t& second
        ) noexcept;

        /*!
         * @brief
         * Retrieve hour component from encoded UTC time integer.
         *
         * @return
         * UTC time hour component
         */
        static uint8_t extractEncodedHour(const Underlying_T* time) noexcept;

        /*!
         * @brief
         * Retrieve minute component from encoded UTC time integer.
         *
         * @return
         * UTC time minute component
         */
        static uint8_t extractEncodedMinute(const Underlying_T* time) noexcept;

        /*!
         * @brief
         * Retrieve second component from encoded UTC time integer.
         *
         * @return
         * UTC time second component
         */
        static uint8_t extractEncodedSecond(const Underlying_T* time) noexcept;

        /*!
         * @brief
         * Construct UTC time using hour, minute, and second
         * values.
         */
        Time(const uint8_t hour, const uint8_t minute, const uint8_t second) noexcept;

        /*!
         * @brief
         * Construct UTC time using hour and minute values;
         * assume 0 seconds.
         */
        Time(const uint8_t hour, const uint8_t minute) noexcept;

        /*!
         * @brief
         * Construct UTC time from another.
         */
        Time(const Time& time) noexcept;

        /*!
         * @brief
         * Construct default UTC time.
         */
        Time() noexcept;

        ~Time() noexcept = default;

        friend inline std::ostream& operator<<(std::ostream& os, const Time time) noexcept
        {
            os << time.toStr();
            return os;
        }

        /*! @brief Evaluate equivalence of UTC times. */
        [[nodiscard]] bool operator==(const Time time) const noexcept;

        /*! @brief Determine if left-hand side is sequentially before right-hand side. */
        [[nodiscard]] bool operator<(const Time time) const noexcept;

        /*! @brief Determine if left-hand side is sequentially after right-hand side. */
        [[nodiscard]] bool operator>(const Time time) const noexcept;

        [[nodiscard]] bool operator<=(const Time time) const noexcept;

        [[nodiscard]] bool operator>=(const Time time) const noexcept;

        /*!
         * @brief
         * Returns requested time component.
         *
         * @return
         * Individual time component value
         */
        [[nodiscard]] uint16_t operator[](const CalendarComponent component) const noexcept;

        /*!
         * @brief
         * Time hour component.
         *
         * @return
         * Hour of UTC time
         */
        [[nodiscard]] uint8_t hour() const noexcept;

        /*!
         * @brief
         * Time meridiem phase indicator literal.
         *
         * @return
         * "AM" or "PM"
         */
        [[nodiscard]] std::string hourPhaseLiteral() const noexcept;

        /*!
         * @brief
         * Time minute component.
         *
         * @return
         * Minute of UTC time
         */
        [[nodiscard]] uint8_t minute() const noexcept;

        /*!
         * @brief
         * Time second component.
         *
         * @return
         * Second of UTC time
         */
        [[nodiscard]] uint8_t second() const noexcept;

        /*!
         * @brief
         * Returns requested UTC time component.
         *
         * @details
         * If the requested calendar component is not a
         * time component the method returns 0.
         *
         * @return
         * Individual time component value
         */
        [[nodiscard]] uint16_t getComponent(const CalendarComponent component) const noexcept;

        /*!
         * @brief
         * Compose string representation of UTC time.
         *
         * @return
         * UTC time as string
         */
        [[nodiscard]] std::string toStr() const noexcept;

        /*!
         * @brief
         * Returns raw underlying representation of UTC
         * time.
         *
         * @return
         * UTC time as integer
         */
        [[nodiscard]] Underlying_T underlying() const noexcept;

      private:
        Underlying_T time; ///< UTC time
    };

} // namespace simplydt::utc

#endif // SIMPLYDT_LIB_UTC_TIME_STRUCT_H_
