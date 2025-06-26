
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file gregorian_date.hpp
 *
 * @brief
 * Standalone Gregorian calendar date declaration.
 */

#ifndef SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_
#define SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_

#include "simplydt/common/string_utils.hpp"
#include "simplydt/gregorian_calendar/gregorian_defs.hpp"
#include <ostream>

namespace simplydt::gregorian
{

    /*!
     * @brief
     * Broken-down Gregorian calendar date.
     *
     * @details
     * This type is meant to serve as a broken-down
     * form of Gregorian calendar dates and only
     * serves this purpose. This type does not
     * validate the Gregorian dates it is constructed
     * with, it is only a vehicle for Gregorian Date
     * values.
     */
    class Date {

      public:
        /*!
         * @brief
         * Underlying type used to represent Gregorian
         * calendar dates.
         */
        using Underlying_T = uint32_t;

        /*!
         * @brief
         * Factor used to store and retrieve year values.
         */
        static constexpr Underlying_T YEAR_FACTOR = 10'000;

        /*!
         * @brief
         * Factor used to store and retrieve month values.
         */
        static constexpr Underlying_T MONTH_FACTOR = 100;

        /*!
         * @brief
         * Default Gregorian calendar date.
         */
        static constexpr Underlying_T DEFAULT_DATE = ((1'970 * YEAR_FACTOR) + 101);

        /*!
         * @brief
         * Construct Gregorian date using year, month,
         * and day values.
         */
        Date(const YearInt_T year, const uint8_t month, const uint8_t day) noexcept;

        /*!
         * @brief
         * Construct Gregorian date using year and month
         * values; assume first of month.
         */
        Date(const YearInt_T year, const uint8_t month) noexcept;

        /*!
         * @brief
         * Construct Gregorian date from another.
         */
        Date(const Date& date) noexcept;

        /*!
         * @brief
         * Construct default Gregorian date.
         */
        Date() noexcept;

        ~Date() noexcept = default;

        friend inline std::ostream& operator<<(std::ostream& os, const Date date) noexcept
        {
            os << date.toStr();
            return os;
        }

        /*! @brief Evaluate equivalence of Gregorian dates. */
        [[nodiscard]] bool operator==(const Date date) const noexcept;

        /*! @brief Determine if left-hand side is sequentially before right-hand side. */
        [[nodiscard]] bool operator<(const Date date) const noexcept;

        /*! @brief Determine if left-hand side is sequentially after right-hand side. */
        [[nodiscard]] bool operator>(const Date date) const noexcept;

        [[nodiscard]] bool operator<=(const Date date) const noexcept;

        [[nodiscard]] bool operator>=(const Date date) const noexcept;

        /*!
         * @brief
         * Returns requested date component.
         *
         * @return
         * Individual date component value
         */
        [[nodiscard]] uint16_t operator[](const CalendarComponent component) const noexcept;

        /*!
         * @brief
         * Date year component.
         *
         * @return
         * Year of Gregorian calendar date
         */
        [[nodiscard]] YearInt_T year() const noexcept;

        /*!
         * @brief
         * Date month component.
         *
         * @return
         * Month of Gregorian calendar date
         */
        [[nodiscard]] uint8_t month() const noexcept;

        /*!
         * @brief
         * Month name.
         *
         * @return
         * Month literal
         */
        [[nodiscard]] const char* monthLiteral() const noexcept;

        /*!
         * @brief
         * Abbreviated month name.
         *
         * @return
         * Abbreviated month literal
         */
        [[nodiscard]] std::string_view monthAbbreviation() const noexcept;

        /*!
         * @brief
         * Date day component.
         *
         * @return
         * Day of Gregorian calendar date
         */
        [[nodiscard]] uint8_t day() const noexcept;

        /*!
         * @brief
         * Returns requested Gregorian date component.
         *
         * @details
         * If the requested calendar component is not a
         * date component the method returns 0.
         *
         * @return
         * Individual date component value
         */
        [[nodiscard]] uint16_t getComponent(const CalendarComponent component) const noexcept;

        /*!
         * @brief
         * Compose string representation of Gregorian
         * calendar date.
         *
         * @return
         * Gregorian calendar date as string
         */
        [[nodiscard]] std::string toStr() const noexcept;

      private:
        Underlying_T date; ///< Calendar date

        /*! @brief Store Gregorian date in underlying variable. */
        void assumeGregorianDate(
            const YearInt_T& year, const uint8_t& month, const uint8_t& day
        ) noexcept;
    };

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_
