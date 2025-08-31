
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_date.hpp
 *
 * @brief
 * Base serial calendar date interface declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_SERIAL_CALENDAR_DATE_INTERFACE_H_
#define SIMPLYDT_LIB_BASE_SERIAL_CALENDAR_DATE_INTERFACE_H_

#include "simplydt/time/units/time_units.hpp"
#include <limits>
#include <ostream>

namespace simplydt
{

/*!
 * @brief
 * Base calendar date interface.
 *
 * @details
 * TODO: INCOMPLETE COMMENT!!!
 */
template <typename Date_Impl, typename Validation_Policy, typename Repr_T, typename Year_T>
struct SerialCalendarDate {
    /*! @brief Calendar date base class. */
    using Base = SerialCalendarDate<Date_Impl, Validation_Policy, Repr_T, Year_T>;
    /*! @brief Calendar date validation policy. */
    using ValidationPolicy = Validation_Policy;
    /*! @brief Underlying serial date type. */
    using Repr_Type = Repr_T;
    /*! @brief Year integer type. */
    using YearInt_t = Year_T;

    /*! @brief Puts human-readable date string in output stream. */
    friend inline std::ostream& operator<<(std::ostream& os, const Base& serial_date) noexcept
    {
        os << serial_date.derivedImpl().toStr();
        return os;
    }

    /*! @brief Evaluates equivalence of calendar dates. */
    [[nodiscard]] constexpr bool operator==(const Date_Impl date) const noexcept
    {
        return this->serialDays == date.serialDays;
    }

    /*! @brief Determines if left-hand side is sequentially before right-hand side. */
    [[nodiscard]] constexpr bool operator<(const Date_Impl date) const noexcept
    {
        return this->serialDays < date.serialDays;
    }

    /*! @brief Determines if left-hand side is sequentially after right-hand side. */
    [[nodiscard]] constexpr bool operator>(const Date_Impl date) const noexcept
    {
        return this->serialDays > date.serialDays;
    }

    [[nodiscard]] constexpr bool operator<=(const Date_Impl date) const noexcept
    {
        return this->serialDays <= date.serialDays;
    }

    [[nodiscard]] constexpr bool operator>=(const Date_Impl date) const noexcept
    {
        return this->serialDays >= date.serialDays;
    }

    /*! @brief Returns this calendar date with provided amount of days added. */
    [[nodiscard]] constexpr Date_Impl operator+(const Days days) const noexcept
    {
        Date_Impl displacedDate{this->derivedImpl()};
        displacedDate.serialDays += days.count();
        return displacedDate;
        // TODO: This method is not safe nor complete...
        // ('days' can underflow or overflow 'serialDays')
    }

    /*! @brief Returns this calendar date with provided amount of days subtracted. */
    [[nodiscard]] constexpr Date_Impl operator-(const Days days) const noexcept
    {
        Date_Impl displacedDate{this->derivedImpl()};
        displacedDate.serialDays -= days.count();
        return displacedDate;
        // TODO: This method is not safe nor complete...
        // ('days' can underflow or overflow 'serialDays')
    }

    /*! @brief Calculates number of days between calendar dates. */
    [[nodiscard]] constexpr Days operator-(const Date_Impl date) const noexcept
    {
        return Days{this->serialDays - date.serialDays};
        // TODO: This method is not safe nor complete...
        // (the math was looking at me funny)
        // (no but srsly, the math could overflow)
    }

    /*!
     * @brief
     * Increments calendar date one day.
     *
     * @return
     * Reference to self
     */
    Date_Impl& operator++() noexcept
    {
        this->serialDays += 1;
        return *this;
        // TODO: This method is not safe nor complete...
        // ('this->serialDays' can overflow)
    }

    /*!
     * @brief
     * Increments calendar date one day.
     *
     * @return
     * Copy of previous calendar date
     */
    [[nodiscard]] Date_Impl operator++(int) noexcept
    {
        Date_Impl previousDate{this->derivedImpl()};
        this->serialDays += 1;
        return previousDate;
        // TODO: This method is not safe nor complete...
        // ('this->serialDays' can overflow)
    }

    /*! @brief Adds provided amount of days to calendar date. */
    Date_Impl& operator+=(const Days days) noexcept
    {
        this->serialDays += days.count();
        return *this;
        // TODO: This method is not safe nor complete...
        // ('days' can underflow or overflow 'this->serialDays')
    }

    /*!
     * @brief
     * Decrements calendar date one day.
     *
     * @return
     * Reference to self
     */
    Date_Impl& operator--() noexcept
    {
        this->serialDays -= 1;
        return *this;
        // TODO: This method is not safe nor complete...
        // ('this->serialDays' can underflow)
    }

    /*!
     * @brief
     * Decrements calendar date one day.
     *
     * @return
     * Copy of previous calendar date
     */
    [[nodiscard]] Date_Impl operator--(int) noexcept
    {
        Date_Impl previousDate{this->derivedImpl()};
        this->serialDays -= 1;
        return previousDate;
        // TODO: This method is not safe nor complete...
        // ('this->serialDays' can underflow)
    }

    /*! @brief Subtracts provided amount of days from calendar date. */
    Date_Impl& operator-=(const Days days) noexcept
    {
        this->serialDays -= days.count();
        return *this;
        // TODO: This method is not safe nor complete...
        // ('days' can underflow or overflow 'this->serialDays')
    }

    // Continue...

  private:
    Repr_Type serialDays;

    constexpr SerialCalendarDate(const Repr_Type serialDayCount) noexcept
        : serialDays{serialDayCount}
    { }

    ~SerialCalendarDate() = default;
    friend Date_Impl;

    [[nodiscard]] constexpr Date_Impl& derivedImpl() const noexcept
    {
        return static_cast<const Date_Impl&>(*this);
    }
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_SERIAL_CALENDAR_DATE_INTERFACE_H_
