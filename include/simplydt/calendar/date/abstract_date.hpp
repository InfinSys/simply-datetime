
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
 * This is the foundational interface for serial calendar
 * dates in Simply Datetime. It is agnostic of any specific
 * calendar and allows derivatives to define their own
 * implementation. Note that the assumption is made that
 * the calendar model in question utilizes year, month,
 * and day values to describe a date in time. This type
 * is not meant to have calendar knowledge, its purpose
 * is to point to a valid date on the calendar it is
 * designed for. Simply Datetime relies on the object
 * invariant that any constructed instance of this type
 * represents a valid calendar date. Each implementation is
 * responsible for enforcing this invariant to prevent bugs
 * and undefined behavior. This structure timekeeps dates
 * using a serial count of days relative to some epoch date.
 * The provided underlying serial date representation type
 * `Repr_T` is initialized in this base class but can also
 * be accessed by the derived calendar date implementation.
 * The class hierarchy implements the CRTP design pattern
 * which allows this base to reference the derivative.
 * Consequently, the convenience methods defined in this
 * base structure depend on the concrete calendar dates
 * public API for them to be well-formed. A derivative is
 * expected to present the appropriate attributes and
 * methods, which can be verified by invoking the contract
 * enforcement macro (`SIMPLYDT_ENFORCE_DATE_CONTRACT`)
 * just after the body of the implementation. Failing to
 * have a compliant API can result in substitution errors
 * or undefined behavior. This is not a self-constructable
 * type, it must be inherited by a concrete implementation
 * that presents the expected (public) API.
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
    [[nodiscard]] constexpr bool operator==(const Base& serial_date) const noexcept
    {
        return this->serialDays == serial_date.serialDays;
    }

    /*! @brief Determines if left-hand side is sequentially before right-hand side. */
    [[nodiscard]] constexpr bool operator<(const Base& serial_date) const noexcept
    {
        return this->serialDays < serial_date.serialDays;
    }

    /*! @brief Determines if left-hand side is sequentially after right-hand side. */
    [[nodiscard]] constexpr bool operator>(const Base& serial_date) const noexcept
    {
        return this->serialDays > serial_date.serialDays;
    }

    [[nodiscard]] constexpr bool operator<=(const Base& serial_date) const noexcept
    {
        return this->serialDays <= serial_date.serialDays;
    }

    [[nodiscard]] constexpr bool operator>=(const Base& serial_date) const noexcept
    {
        return this->serialDays >= serial_date.serialDays;
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
        return static_cast<Date_Impl&>(*this);
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
        return static_cast<Date_Impl&>(*this);
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
        return static_cast<Date_Impl&>(*this);
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
        return static_cast<Date_Impl&>(*this);
        // TODO: This method is not safe nor complete...
        // ('days' can underflow or overflow 'this->serialDays')
    }

    /*!
     * @brief
     * Determines if calendar date is epoch date.
     *
     * @return
     * True if serial day count is zero
     */
    [[nodiscard]] constexpr bool isZero() const noexcept
    {
        return this->serialDays == 0;
    }

    /*!
     * @brief
     * Determines if date is sequentially before provided
     * date.
     *
     * @return
     * True if this date occurs before provided
     */
    [[nodiscard]] constexpr bool isBefore(const Date_Impl date) const noexcept
    {
        return this->serialDays < date.serialDays;
    }

    /*!
     * @brief
     * Determines if date is sequentially after provided
     * date.
     *
     * @return
     * True if this date occurs after provided
     */
    [[nodiscard]] constexpr bool isAfter(const Date_Impl date) const noexcept
    {
        return this->serialDays > date.serialDays;
    }

    /*!
     * @brief
     * Determines if date is sequentially between two
     * dates.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * True if this date occurs between provided dates
     */
    [[nodiscard]] constexpr bool isBetween(
        const Date_Impl start_date, const Date_Impl end_date
    ) const noexcept
    {
        return start_date.serialDays <= this->serialDays &&
               this->serialDays <= end_date.serialDays;
    }

    /*!
     * @brief
     * Calculates number of days between dates.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * Days from this date to provided
     */
    [[nodiscard]] constexpr Days daysUntil(const Date_Impl date) const noexcept
    {
        return Days{date.serialDays - this->serialDays};
    }

    /*!
     * @brief
     * Returns serial day count as explicit units
     * of precision.
     *
     * @details
     * TODO: INCOMPLETE COMMENT!!!
     *
     * @return
     * Serial day count
     */
    [[nodiscard]] constexpr Days units() const noexcept
    {
        return Days{this->serialDays};
    }

    /*!
     * @brief
     * Returns constant reference to underlying serial
     * day count.
     *
     * @return
     * Constant reference to serial day count
     */
    [[nodiscard]] constexpr const Repr_Type& underlying() const noexcept
    {
        return this->serialDays;
    }

  private:
    Repr_Type serialDays; ///< Serial day count

    /*! @brief Construct calendar date with serial day count. */
    constexpr SerialCalendarDate(const Repr_Type serialDayCount) noexcept
        : serialDays{serialDayCount}
    { }

    ~SerialCalendarDate() = default;
    friend Date_Impl;

    /*!
     * @brief
     * Returns constant reference to this concrete derivative.
     *
     * @note
     * Do not call this from the derived class, YOU are the
     * `derivedImpl()` (a.k.a `this`)
     */
    [[nodiscard]] constexpr const Date_Impl& derivedImpl() const noexcept
    {
        return static_cast<const Date_Impl&>(*this);
    }
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_SERIAL_CALENDAR_DATE_INTERFACE_H_
