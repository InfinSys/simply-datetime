
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_calendar.hpp
 *
 * @brief
 * Base calendar system interface declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_CALENDAR_INTERFACE_H_
#define SIMPLYDT_LIB_BASE_CALENDAR_INTERFACE_H_

#include "simplydt/common/simplydt_defs.hpp"
#include <cstdint>
#include <limits>
#include <string_view>

namespace simplydt
{

/*!
 * @brief
 * Base calendar interface.
 *
 * @details
 * This serves as the foundational interface for calendar
 * systems in Simply Datetime. It is designed to be agnostic
 * of any specific calendar implementation, allowing derived
 * calendars to define their own characteristics. Note that
 * the assumption is made that the calendar model in question
 * utilizes year, month, and day values to describe a date in
 * time. An implementation of this type focuses on conducting
 * calendar operations on dates of type `Date_Impl` while
 * obeying defined systemic calendar rules. Similar to other
 * class hierarchies in Simply Datetime, this family uses the
 * CRTP design pattern which allows this base to reference the
 * derivative. Consequently, the convenience methods defined
 * in this base structure depend on the concrete calendars
 * public API for them to be well-formed. A derivative is
 * expected to present the appropriate static attributes and
 * methods, which can be verified by invoking the contract
 * enforcement macro (`SIMPLYDT_ENFORCE_CALENDAR_CONTRACT`)
 * just after the body of the implementation. Failing to have
 * a compliant API can result in substitution errors or
 * undefined behavior. Similarly, the provided date
 * implementation must also satisfy its API requirements to
 * avoid substitution errors or undefined behavior. This type
 * is meant to present a stateless API and should not be
 * constructable. It must be inherited by a concrete
 * implementation that presents the expected (public) static
 * API.
 */
template <typename Calendar_Impl, typename Date_Impl, typename Month_Enum, typename DOW_Enum>
struct CalendricalSystem {
    /*! @brief Calendar system base class. */
    using Base = CalendricalSystem<Calendar_Impl, Date_Impl, Month_Enum, DOW_Enum>;
    /*! @brief Calendar date. */
    using Date = Date_Impl;
    /*! @brief Calendar year integer type. */
    using YearInt_t = typename Date::YearInt_t;
    /*! @brief Enumeration of calendar months. */
    using Month = Month_Enum;
    /*! @brief Enumeration of calendar days of week. */
    using DayOfWeek = DOW_Enum;

    /*!
     * @brief
     * Returns name of calendar month by its numeric value.
     *
     * @details
     * Expects a 1-based month number (1 = January ... 12 =
     * December). If the month value is invalid for the
     * current calendar implementation, the function returns
     * a predefined invalid string literal. Month names are
     * sourced from the derived calendar's `MONTH_NAMES` array.
     *
     * @return
     * Calendar month name
     */
    [[nodiscard]] static constexpr const char* getMonthName(const uint8_t month) noexcept
    {
        if (month == 0 || !Calendar_Impl::isValidMonth(month))
            return INVALID_LITERAL;

        const uint8_t monthIndex = month - 1;
        return Calendar_Impl::MONTH_NAMES[monthIndex];
    }

    /*!
     * @brief
     * Returns name of calendar month from its enumeration
     * representation.
     *
     * @details
     * Accepts a month enumeration constant defined by the
     * derived calendar implementation. The enumeration is
     * expected to use zero-based indexing (0 = January ...
     * 11 = December). If the month value is invalid for the
     * current calendar, the function returns a predefined
     * invalid string literal. Month names are sourced from
     * the derived calendar's `MONTH_NAMES` array.
     *
     * @return
     * Calendar month name
     */
    [[nodiscard]] static constexpr const char* getMonthName(const Month month_repr) noexcept
    {
        if (month_repr < 0 || month_repr > std::numeric_limits<uint8_t>::max())
            return INVALID_LITERAL;

        const uint8_t monthIndex = static_cast<uint8_t>(month_repr);

        if (!Calendar_Impl::isValidMonth(monthIndex + 1))
            return INVALID_LITERAL;

        return Calendar_Impl::MONTH_NAMES[monthIndex];
    }

    /*!
     * @brief
     * Returns month name of calendar date.
     *
     * @details
     * Extracts month from calendar defined date implementation
     * and returns its corresponding month name using the derived
     * calendar's `MONTH_NAMES` array.
     *
     * @return
     * Calendar month name
     */
    [[nodiscard]] static constexpr const char* getMonthName(const Date date) noexcept
    {
        return getMonthName(date.month());
    }

    /*!
     * @brief
     * Returns abbreviated name of a calendar month by its numeric
     * value.
     *
     * @details
     * Expects a 1-based month number (1 = January ... 12 = December).
     * If the month value is invalid for the current calendar
     * implementation, the function returns a predefined invalid
     * string literal. Month abbreviations are sourced from the
     * derived calendar's `MONTH_ABBREVS` array.
     *
     * @return
     * Abbreviated calendar month name
     */
    [[nodiscard]] static constexpr std::string_view getMonthAbbrev(const uint8_t month
    ) noexcept
    {
        if (month == 0 || !Calendar_Impl::isValidMonth(month))
            return std::string_view{INVALID_LITERAL};

        const uint8_t monthIndex = month - 1;
        return Calendar_Impl::MONTH_ABBREVS[monthIndex];
    }

    /*!
     * @brief
     * Returns abbreviated name of a calendar month from its
     * enumeration representation.
     *
     * @details
     * Accepts a month enumeration constant defined by the derived
     * calendar implementation. The enumeration is expected to use
     * zero-based indexing (0 = January ... 11 = December). If the
     * month value is invalid for the current calendar, the function
     * returns a predefined invalid string literal. Month abbreviations
     * are sourced from the derived calendar's `MONTH_ABBREVS` array.
     *
     * @return
     * Abbreviated calendar month name
     */
    [[nodiscard]] static constexpr std::string_view getMonthAbbrev(const Month month_repr
    ) noexcept
    {
        if (month_repr < 0 || month_repr > std::numeric_limits<uint8_t>::max())
            return std::string_view{INVALID_LITERAL};

        const uint8_t monthIndex = static_cast<uint8_t>(month_repr);

        if (!Calendar_Impl::isValidMonth(monthIndex + 1))
            return std::string_view{INVALID_LITERAL};

        return Calendar_Impl::MONTH_ABBREVS[monthIndex];
    }

    /*!
     * @brief
     * Returns abbreviated month name of calendar date.
     *
     * @details
     * Extracts month from calendar defined date implementation
     * and returns its corresponding abbreviated month name using
     * the derived calendar's `MONTH_ABBREVS` array.
     *
     * @return
     * Abbreviated calendar month name
     */
    [[nodiscard]] static constexpr std::string_view getMonthAbbrev(const Date date) noexcept
    {
        return getMonthAbbrev(date.month());
    }

    /*!
     * @brief
     * Converts a numeric month value to its corresponding
     * enumeration representation.
     *
     * @details
     * Expects a 1-based month number (1 = January ... 12 =
     * December). If the value is invalid for the current
     * calendar implementation, the function returns a fallback
     * enumeration value (0). The returned value uses zero-based
     * indexing of the derived calendar's `Month` enumeration.
     *
     * @return
     * Calendar month enum representation
     */
    [[nodiscard]] static constexpr Month getMonthEnumRepr(const uint8_t month) noexcept
    {
        if (!Calendar_Impl::isValidMonth(month))
            return static_cast<Month>(0); // TODO: Fallback value not acceptable here...

        const uint8_t monthIndex = month - 1;
        return static_cast<Month>(monthIndex);
    }

    /*!
     * @brief
     * Converts a calendar date month to its corresponding
     * enumeration representation.
     *
     * @details
     * Extracts month from calendar defined date implementation and
     * converts it to the corresponding zero-based `Month`
     * enumeration defined by the derived calendar implementation.
     *
     * @return
     * Calendar month enum representation
     */
    [[nodiscard]] static constexpr Month getMonthEnumRepr(const Date date) noexcept
    {
        return getMonthEnumRepr(date.month());
    }

    /*!
     * @brief
     * Returns name of calendar day-of-week from its enumeration
     * representation.
     *
     * @details
     * Accepts a day-of-week enumeration constant defined by
     * the derived calendar implementation. The enumeration
     * is expected to use zero-based indexing (0 = Sunday ...
     * 6 = Saturday). If the day-of-week value is invalid for
     * the current calendar, the function returns a predefined
     * invalid string literal. Calendar day-of-week names are
     * sourced from the derived calendar's `DAY_OF_WEEK_NAMES`
     * array.
     *
     * @return
     * Calendar day-of-week name
     */
    [[nodiscard]] static constexpr const char* getDayOfWeekName(const DayOfWeek dow_repr
    ) noexcept
    {
        if (dow_repr < 0 || dow_repr > std::numeric_limits<uint8_t>::max())
            return INVALID_LITERAL;

        const uint8_t dowIndex = static_cast<uint8_t>(dow_repr);

        if (!Calendar_Impl::isValidDOWIndex(dowIndex))
            return INVALID_LITERAL;

        return Calendar_Impl::DAY_OF_WEEK_NAMES[dowIndex];
    }

    /*!
     * @brief
     * Returns calendar date day-of-week name.
     *
     * @details
     * Determines day-of-week index of the provided calendar
     * date by calling the derived calendar implementation
     * `getDayOfWeekIndex()` method. Returns the corresponding
     * name from the calendar defined `DAY_OF_WEEK_NAMES`
     * array, or a predefined invalid string literal if the
     * date is not valid.
     *
     * @return
     * Calendar day-of-week name
     */
    [[nodiscard]] static constexpr const char* getDayOfWeekName(const Date date) noexcept
    {
        if (!Calendar_Impl::isValidDate(date))
            return INVALID_LITERAL;

        const uint8_t dowIndex = Calendar_Impl::getDayOfWeekIndex(date);
        return Calendar_Impl::DAY_OF_WEEK_NAMES[dowIndex];
    }

    /*!
     * @brief
     * Returns abbreviated name of calendar day-of-week from its
     * enumeration representation.
     *
     * @details
     * Accepts a day-of-week enumeration constant defined by
     * the derived calendar implementation. The enumeration is
     * expected to use zero-based indexing (0 = Sunday ... 6 =
     * Saturday). If the day-of-week value is invalid for the
     * current calendar, the function returns a predefined
     * invalid string literal. Day-of-week abbreviations are
     * sourced from the derived calendar's `DAY_OF_WEEK_ABBREVS`
     * array.
     *
     * @return
     * Abbreviated calendar day-of-week name
     */
    [[nodiscard]] static constexpr std::string_view getDayOfWeekAbbrev(const DayOfWeek dow_repr
    ) noexcept
    {
        if (dow_repr < 0 || dow_repr > std::numeric_limits<uint8_t>::max())
            return std::string_view{INVALID_LITERAL};

        const uint8_t dowIndex = static_cast<uint8_t>(dow_repr);

        if (!Calendar_Impl::isValidDOWIndex(dowIndex))
            return std::string_view{INVALID_LITERAL};

        return Calendar_Impl::DAY_OF_WEEK_ABBREVS[dowIndex];
    }

    /*!
     * @brief
     * Returns abbreviated name of calendar day-of-week from its
     * enumeration representation.
     *
     * @details
     * Determines day-of-week index of the provided calendar
     * date by calling the derived calendar implementation
     * `getDayOfWeekIndex()` method. Returns the corresponding
     * name from the calendar defined `DAY_OF_WEEK_ABBREVS`
     * array, or a predefined invalid string literal if the
     * date is not valid.
     *
     * @return
     * Abbreviated calendar day-of-week name
     */
    [[nodiscard]] static constexpr std::string_view getDayOfWeekAbbrev(const Date date
    ) noexcept
    {
        if (!Calendar_Impl::isValidDate(date))
            return std::string_view{INVALID_LITERAL};

        const uint8_t dowIndex = Calendar_Impl::getDayOfWeekIndex(date);
        return Calendar_Impl::DAY_OF_WEEK_ABBREVS[dowIndex];
    }

    /*!
     * @brief
     * Converts a calendar date to its corresponding day-of-week
     * enumeration representation.
     *
     * @details
     * Validates the given `Date` instance and determines its
     * day-of-week index using the derived calendar's
     * `getDayOfWeekIndex()` method. Returns the corresponding
     * day-of-week enumeration representation using the
     * `DayOfWeek` enumeration defined by the derived calendar.
     *
     * @return
     * Calendar day-of-week enum representation
     */
    [[nodiscard]] static constexpr DayOfWeek getDayOfWeekEnumRepr(const Date date) noexcept
    {
        if (!Calendar_Impl::isValidDate(date))
            return static_cast<DayOfWeek>(0); // TODO: Fallback value not acceptable here...

        const uint8_t dowIndex = Calendar_Impl::getDayOfWeekIndex(date);
        return static_cast<DayOfWeek>(dowIndex);
    }

    // Continue...

  private:
    CalendricalSystem()  = delete;
    ~CalendricalSystem() = delete;
    friend Calendar_Impl;
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_CALENDAR_INTERFACE_H_
