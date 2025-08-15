
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_calendar.hpp
 *
 * @brief
 * Base CRTP calendar declaration.
 */


#ifndef SIMPLYDT_LIB_BASE_CALENDAR_H_
#define SIMPLYDT_LIB_BASE_CALENDAR_H_

#include "simplydt/calendar/concepts/calendar_contract.hpp"

namespace simplydt
{

/*!
 * @brief
 * Base calendar agnostic system.
 *
 * @details
 * This class serves as a foundational interface for calendar
 * systems, providing a generic and extensible structure for
 * calendar operations. It is designed to be agnostic of any
 * specific calendar implementation, allowing derived calendars
 * to define their own month and day-of-week enumerations, date
 * representations, and naming conventions. This type is not
 * self-constructable and must be inherited by a concrete
 * implementation that presents a valid public API. Implementations
 * should seek confirmation their API is compliant by invoking the
 * calendar contract enforcement macro just after the body of the
 * implementation. Failing to be compliant can result in substitution
 * errors or undefined behavior.
 */
template <typename Calendar_Impl, typename Date_T, typename Month_Enum, typename DOW_Enum>
struct CalendricalSystem {
    /*! @brief Calendar system implementation. */
    using Calendar = Calendar_Impl;
    /*! @brief Calendar implementation base class. */
    using Base = CalendricalSystem<Calendar_Impl, Date_T, Month_Enum, DOW_Enum>;
    /*! @brief Calendar date. */
    using Date = Date_T;
    /*! @brief Year integer type. */
    using YearInt_t = typename Date::YearInt_t;
    /*! @brief Enumeration of calendar months. */
    using Month = Month_Enum;
    /*! @brief Enumeration of calendar days of week. */
    using DayOfWeek = DOW_Enum;

    /*!
     * @brief
     * Returns name of a calendar month by its numeric value.
     *
     * @details
     * Expects a 1-based month number (1 = January ... 12 = December).
     * If the month value is invalid for the current calendar
     * implementation, the function returns a predefined invalid
     * string literal. Month names are provided by the derived
     * calendar's `MONTH_NAMES` array.
     *
     * @return
     * Month name
     */
    [[nodiscard]] static constexpr const char* getMonthName(const uint8_t month) noexcept
    {
        if (!Calendar::isValidMonth(month))
            return INVALID_LITERAL;

        const uint8_t monthIndex = month - 1;
        return Calendar::MONTH_NAMES[monthIndex];
    }

    /*!
     * @brief
     * Returns name of a calendar month from its enumeration
     * representation.
     *
     * @details
     * Accepts a month enumeration constant defined by the derived
     * calendar implementation. The enumeration is expected to use
     * zero-based indexing (0 = January ... 11 = December). If the
     * month value is invalid for the current calendar, the function
     * returns a predefined invalid string literal. Month names are
     * sourced from the derived calendar's `MONTH_NAMES` array.
     *
     * @return
     * Month name
     */
    [[nodiscard]] static constexpr const char* getMonthName(const Month month) noexcept
    {
        const uint8_t monthIndex = static_cast<uint8_t>(month);

        if (!Calendar::isValidMonth(monthIndex + 1))
            return INVALID_LITERAL;

        return Calendar::MONTH_NAMES[monthIndex];
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
     * Month name
     */
    [[nodiscard]] static constexpr const char* getMonthName(const Date date) noexcept
    {
        return date.monthLiteral();
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
     * string literal. Month abbreviations are provided by the
     * derived calendar's `MONTH_ABBREVS` array.
     *
     * @return
     * Abbreviated month name
     */
    [[nodiscard]] static std::string getMonthAbbrev(const uint8_t month) noexcept
    {
        if (!Calendar::isValidMonth(month))
            return INVALID_LITERAL;

        const uint8_t monthIndex = month - 1;
        const std::string abbreviation{Calendar::MONTH_ABBREVS[monthIndex]};
        return abbreviation;
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
     * returns a predefined invalid string literal. Month
     * abbreviations are sourced from the derived calendar's
     * `MONTH_ABBREVS` array.
     *
     * @return
     * Abbreviated month name
     */
    [[nodiscard]] static std::string getMonthAbbrev(const Month month) noexcept
    {
        const uint8_t monthIndex = static_cast<uint8_t>(month);

        if (!Calendar::isValidMonth(monthIndex + 1))
            return INVALID_LITERAL;

        const std::string abbreviation{Calendar::MONTH_ABBREVS[monthIndex]};
        return abbreviation;
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
     * Abbreviated month name
     */
    [[nodiscard]] static std::string getMonthAbbrev(const Date date) noexcept
    {
        return date.monthAbbreviation();
    }

    /*!
     * @brief
     * Converts a numeric month value to its corresponding
     * enumeration representation.
     *
     * @details
     * Expects a 1-based month number (1 = January ... 12 = December).
     * If the value is invalid for the current calendar implementation,
     * the function returns a fallback enumeration value (0). The
     * returned value uses zero-based indexing of the derived
     * calendar's `Month` enumeration.
     *
     * @return
     * Calendar month enum value
     */
    [[nodiscard]] static constexpr Month getMonthEnumRepr(const uint8_t month) noexcept
    {
        if (!Calendar::isValidMonth(month))
            return static_cast<Month>(0); // TODO: Crap...

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
     * converts it to the zero-based `Month` enumeration defined by
     * the derived calendar implementation.
     *
     * @return
     * Calendar month enum value
     */
    [[nodiscard]] static constexpr Month getMonthEnumRepr(const Date date) noexcept
    {
        return static_cast<Month>(date.month() - 1);
    }

    /*!
     * @brief
     * Returns day-of-week name of calendar date.
     *
     * @details
     * Validates the given `Date` instance and determines its
     * day-of-week index using the derived calendar's
     * `getDayOfWeekIndex()` method. Returns the corresponding name
     * from the `DAY_OF_WEEK_NAMES` array, or a predefined invalid
     * string literal if the date is not valid.
     *
     * @return
     * Day-of-week name
     */
    [[nodiscard]] static constexpr const char* getDayOfWeekName(const Date date) noexcept
    {
        if (!Calendar::isValidDate(date))
            return INVALID_LITERAL;

        const uint8_t dowIndex = Calendar::getDayOfWeekIndex(date);
        return Calendar::DAY_OF_WEEK_NAMES[dowIndex];
    }

    /*!
     * @brief
     * Returns name of a calendar day-of-week from its enumeration
     * representation.
     *
     * @details
     * Accepts a day-of-week enumeration constant defined by the
     * derived calendar implementation. The enumeration is expected
     * to use zero-based indexing (0 = Sunday ... 6 = Saturday). If
     * the day-of-week value is invalid for the current calendar, the
     * function returns a predefined invalid string literal.
     * day-of-week names are sourced from the derived calendar's
     * `DAY_OF_WEEK_NAMES` array.
     *
     * @return
     * Day-of-week name
     */
    [[nodiscard]] static constexpr const char* getDayOfWeekName(const DayOfWeek dow) noexcept
    {
        const uint8_t dowIndex = static_cast<uint8_t>(dow);

        if (!Calendar::isValidDOWIndex(dowIndex))
            return INVALID_LITERAL;

        return Calendar::DAY_OF_WEEK_NAMES[dowIndex];
    }

    /*!
     * @brief
     * Returns abbreviated day-of-week name of calendar date.
     *
     * @details
     * Validates the given `Date` instance and determines its
     * day-of-week index using the derived calendar's
     * `getDayOfWeekIndex()` method. Returns the corresponding
     * abbreviated name from the `DAY_OF_WEEK_ABBREVS` array, or a
     * predefined invalid string literal if the date is not valid.
     *
     * @return
     * Abbreviated day-of-week name
     */
    [[nodiscard]] static std::string getDayOfWeekAbbrev(const Date date) noexcept
    {
        if (!Calendar::isValidDate(date))
            return INVALID_LITERAL;

        const uint8_t dowIndex = Calendar::getDayOfWeekIndex(date);
        const std::string abbreviation{Calendar::DAY_OF_WEEK_ABBREVS[dowIndex]};
        return abbreviation;
    }

    /*!
     * @brief
     * Returns abbreviated name of a calendar day-of-week from its
     * enumeration representation.
     *
     * @details
     * Accepts a day-of-week enumeration constant defined by the derived
     * calendar implementation. The enumeration is expected to use
     * zero-based indexing (0 = Sunday ... 6 = Saturday). If the
     * day-of-week value is invalid for the current calendar, the
     * function returns a predefined invalid string literal. Day-of-week
     * abbreviations are sourced from the derived calendar's
     * `DAY_OF_WEEK_ABBREVS` array.
     *
     * @return
     * Abbreviated day-of-week name
     */
    [[nodiscard]] static std::string getDayOfWeekAbbrev(const DayOfWeek dow) noexcept
    {
        const uint8_t dowIndex = static_cast<uint8_t>(dow);

        if (!Calendar::isValidDOWIndex(dowIndex))
            return INVALID_LITERAL;

        const std::string abbreviation{Calendar::DAY_OF_WEEK_ABBREVS[dowIndex]};
        return abbreviation;
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
     * day-of-week enumeration representation using the `DayOfWeek`
     * enumeration defined by the derived calendar.
     *
     * @return
     * Calendar day-of-week enum value
     */
    [[nodiscard]] static constexpr DayOfWeek getDayOfWeekEnumRepr(const Date date) noexcept
    {
        if (!Calendar::isValidDate(date))
            return static_cast<DayOfWeek>(0); // TODO: Oh no.. another one...

        const uint8_t dowIndex = Calendar::getDayOfWeekIndex(date);
        return static_cast<DayOfWeek>(dowIndex);
    }

  private:
    CalendricalSystem()  = delete;
    ~CalendricalSystem() = delete;
    friend Calendar_Impl;
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_CALENDAR_H_
