
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
#include "simplydt/common/stl_chrono_defs.hpp"
#include "simplydt/common/stl_chrono_utils.hpp"
#include "simplydt/time/units/time_units.hpp"
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
    /*! @brief Calendar date validation policy. */
    using DatePolicy = typename Date::ValidationPolicy;
    /*! @brief Enumeration of calendar months. */
    using Month = Month_Enum;
    /*! @brief Enumeration of calendar days of week. */
    using DayOfWeek = DOW_Enum;

    /*! @brief TODO: INCOMPLETE COMMENT!!! */
    struct NonLocal { };

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
        const uint8_t monthIndex = date.month() - 1;
        return Calendar_Impl::MONTH_NAMES[monthIndex];
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
        const uint8_t monthIndex = date.month() - 1;
        return Calendar_Impl::MONTH_ABBREVS[monthIndex];
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
        const uint8_t monthIndex = date.month() - 1;
        return static_cast<Month>(monthIndex);
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
        const uint8_t dowIndex = Calendar_Impl::getDayOfWeekIndex(date);
        return static_cast<DayOfWeek>(dowIndex);
    }

    /*!
     * @brief
     * Create calendar date using a year, month, and day value.
     *
     * @brief
     * Constructs a calendar defined date implementation using
     * the provided date values. Checks validity of date values
     * beforehand using the derived calendars `isValidDate()`
     * method. The method returns a default constructed calendar
     * date if the provided date values were invalid for the
     * current calendar.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] static constexpr Date getDate(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        if (!Calendar_Impl::isValidDate(year, month, day))
            return Date{};

        return Date{year, month, day};
    }

    /*!
     * @brief
     * Create calendar date using a year, month, and day value.
     *
     * @brief
     * Constructs a calendar defined date implementation using
     * the provided date values. Checks validity of date values
     * beforehand using the derived calendars `isValidDate()`
     * method. The method returns a default constructed calendar
     * date if the provided date values were invalid for the
     * current calendar. The month enumeration value is converted
     * to a 1-based numerical month value for calculations.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] static constexpr Date getDate(
        const YearInt_t year, const Month month, const uint8_t day
    ) noexcept
    {
        if (month < 0 || month >= std::numeric_limits<uint8_t>::max())
            return Date{};

        const uint8_t numericMonth = static_cast<uint8_t>(month) + 1;
        return Date{year, numericMonth, day};
    }

    /*!
     * @brief
     * Create calendar date using local system clock.
     *
     * @details
     * Interprets the given `stl::SystemTimePoint` as local time
     * by converting it to a Unix timestamp and then populating
     * a `std::tm` structure using the C++ standard library backed
     * `stl::deriveLocalDateTimeFromTimestamp()` method. The
     * resulting year, month, and day fields are used to construct
     * and return the calendar defined date implementation. If the
     * local date conversion fails a default constructed calendar
     * date is returned.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] static Date getDate(const stl::SystemTimePoint time_point) noexcept
    {
        const stl::UnixTimestamp secsSinceEpoch = stl::SystemClock::to_time_t(time_point);
        stl::CalendarDateTime dateBuffer{};

        if (!stl::deriveLocalDateTimeFromTimestamp(&secsSinceEpoch, &dateBuffer))
            return Date{}; // Failed to interpret local date

        return Date{
            static_cast<YearInt_t>(
                dateBuffer.tm_year + 1'900
            ), // tm_year measures years since 1900
            static_cast<uint8_t>(
                dateBuffer.tm_mon + 1
            ), // tm_mon measures months since January
            static_cast<uint8_t>(dateBuffer.tm_mday)
        };
    }

    /*!
     * @brief
     * Create calendar date using system clock.
     *
     * @details
     * When the `NonLocal` tag struct is supplied, the provided
     * timepoint is interpreted without the assistance of the
     * host OS (no time-zone applied). The OS has access to the
     * necessary system settings that influence local time
     * interpretation and must be consulted to get the systems
     * true date (time-zone applied).
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] static Date getDate(
        const stl::SystemTimePoint time_point, const NonLocal
    ) noexcept
    {
        const stl::UnixTimestamp secsSinceEpoch = stl::SystemClock::to_time_t(time_point);
        return Calendar_Impl::fromUnixTimestamp(secsSinceEpoch);
    }

    /*!
     * @brief
     * Returns next calendar date.
     *
     * @details
     * Increments the provided date by 1 day.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] inline static constexpr Date getNextDate(const Date from_date) noexcept
    {
        return from_date + Days{1};
    }

    /*!
     * @brief
     * Finds next calendar date on specified day-of-week.
     *
     * @details
     * This function determines the first calendar date that
     * falls on the specified day of the week strictly after
     * the provided `from_date`. The calculation uses the
     * day-of-week index supplied by the derived calendar
     * implementation and advances by at least one full week.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] static constexpr Date getNextDate(
        const Date from_date, const DayOfWeek dow_repr
    ) noexcept
    {
        constexpr uint8_t daysInWeek =
            static_cast<uint8_t>(Calendar_Impl::DAY_OF_WEEK_NAMES.size());
        const int8_t fromDate_dow =
            static_cast<int8_t>(Calendar_Impl::getDayOfWeekIndex(from_date));
        const int8_t dowOffset = static_cast<int8_t>(dow_repr) - fromDate_dow;
        return from_date + Days{dowOffset + daysInWeek};
    }

    /*!
     * @brief
     * Finds next calendar date within specified month.
     *
     * @details
     * This function calculates the next date in the given
     * `month_repr` relative to the provided `from_date`. If
     * the target month has not yet occurred in the current
     * year, the result is the first day of that month within
     * the same year. If the target month has already passed,
     * the result is the first day of that month in the
     * following year. If the `from_date` is already within
     * the target month, the function advances to the very
     * next day, unless the date is the last day of the month,
     * in which case it rolls over to the first day of the
     * same month in the next year.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] static constexpr Date getNextDate(
        const Date from_date, const Month month_repr
    ) noexcept
    {
        const uint8_t fromNumericMonth = from_date.month();
        const uint8_t toNumericMonth   = static_cast<uint8_t>(month_repr) + 1;

        if (fromNumericMonth != toNumericMonth) {
            if (fromNumericMonth > toNumericMonth) {
                const YearInt_t nextYear = from_date.year() + 1;
                return Date{nextYear, toNumericMonth, 1};
            }
            else { // fromNumericMonth < toNumericMonth
                return Date{from_date.year(), toNumericMonth, 1};
            }
        }

        const uint8_t daysInMonth =
            Calendar_Impl::getDaysInMonth(from_date.year(), fromNumericMonth);

        if (from_date.day() != daysInMonth)
            return from_date + Days{1};
        
        const YearInt_t nextYear = from_date.year() + 1;
        return Date{nextYear, fromNumericMonth, 1};
        // NOTE: Check validity of above date values first before return?
        // (wrap around to valid?)
    }

    /*!
     * @brief
     * Returns last calendar date.
     *
     * @details
     * Decrements the provided date by 1 day.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] inline static constexpr Date getLastDate(const Date from_date) noexcept
    {
        return from_date - Days{1};
    }

    /*!
     * @brief
     * Finds last calendar date on provided day-of-week.
     *
     * @details
     * This function determines the first calendar date that
     * falls on the specified day of the week strictly before
     * the provided `from_date`. The calculation uses the
     * day-of-week index supplied by the derived calendar
     * implementation and decreases by at least one full week.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] static constexpr Date getLastDate(
        const Date from_date, const DayOfWeek dow_repr
    ) noexcept
    {
        constexpr uint8_t daysInWeek =
            static_cast<uint8_t>(Calendar_Impl::DAY_OF_WEEK_NAMES.size());
        const int8_t fromDate_dow =
            static_cast<int8_t>(Calendar_Impl::getDayOfWeekIndex(from_date));
        const int8_t dowOffset = fromDate_dow - static_cast<int8_t>(dow_repr);
        return from_date - Days{dowOffset + daysInWeek};
    }

    /*!
     * @brief
     * Finds last calendar date within specified month.
     *
     * @details
     * This function calculates the last date in the given
     * `month_repr` relative to the provided `from_date`. If
     * the target month has not yet occurred in the current
     * year, the result will be the last day of that month
     * in the previous year. If the target month has already
     * passed, the result is the last day of that month in
     * the same year. If `from_date` is already within the
     * target month, the function returns the day
     * immediately preceding it, unless `from_date` is the
     * first day of the month, in which case it rolls back
     * to the last day of the same month in the previous year.
     *
     * @return
     * Calendar date
     */
    [[nodiscard]] static constexpr Date getLastDate(
        const Date from_date, const Month month_repr
    ) noexcept
    {
        const uint8_t fromNumericMonth = from_date.month();
        const uint8_t toNumericMonth   = static_cast<uint8_t>(month_repr) + 1;
        uint8_t daysInMonth = Calendar_Impl::getDaysInMonth(from_date.year(), toNumericMonth);

        if (fromNumericMonth != toNumericMonth) {
            if (fromNumericMonth > toNumericMonth) {
                return Date{from_date.year(), toNumericMonth, daysInMonth};
            } else { // fromNumericMonth < toNumericMonth
                const YearInt_t previousYear = from_date.year() - 1;
                daysInMonth = Calendar_Impl::getDaysInMonth(previousYear, toNumericMonth);
                return Date{previousYear, toNumericMonth, daysInMonth};
            }
        }

        if (from_date.day() != 1)
            return from_date - Days{1};

        const YearInt_t previousYear = from_date.year() - 1;
        daysInMonth = Calendar_Impl::getDaysInMonth(previousYear, toNumericMonth);
        return Date{previousYear, toNumericMonth, daysInMonth};
        // NOTE: Check validity of above date values first before return?
        // (wrap around to valid?)
    }

  private:
    CalendricalSystem()  = delete;
    ~CalendricalSystem() = delete;
    friend Calendar_Impl;
};

} // namespace simplydt

#endif // SIMPLYDT_LIB_BASE_CALENDAR_INTERFACE_H_
