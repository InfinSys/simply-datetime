
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file calendar_concepts.hpp
 *
 * @brief
 * Agnostic calendar concepts.
 */


#ifndef SIMPLYDT_LIB_CALENDAR_CONCEPTS_H_
#define SIMPLYDT_LIB_CALENDAR_CONCEPTS_H_

#include "simplydt/calendar/concepts/date_concepts.hpp"
#include "simplydt/common/calendar_defs.hpp"
#include "simplydt/common/stl_chrono_defs.hpp"
#include <concepts>

/*!
 * @namespace simplydt::concepts::calendar
 *
 * @brief
 * Calendar concepts.
 */
namespace simplydt::concepts::calendar
{

template <typename Calendar_Impl>
concept has_contextual_nested_types = requires {
    typename Calendar_Impl::YearInt_t;
    typename Calendar_Impl::Date;
    typename Calendar_Impl::Month;
    typename Calendar_Impl::DayOfWeek;
    typename Calendar_Impl::DatePolicy;
    typename Calendar_Impl::NonLocal;
};

template <typename Calendar_Impl>
concept has_characteristic_members = requires {
    { Calendar_Impl::calendar } -> std::same_as<const CalendarSystem&>;
    { Calendar_Impl::isSolarCalendar } -> std::same_as<const bool&>;
    { Calendar_Impl::isLunarCalendar } -> std::same_as<const bool&>;
    { Calendar_Impl::isLunisolarCalendar } -> std::same_as<const bool&>;
};

template <typename Calendar_Impl>
concept has_calendar_name_arrays = requires {
    {
        Calendar_Impl::MONTH_NAMES
    } -> std::same_as<const std::array<
        const char*,
        std::tuple_size_v<std::remove_cvref_t<decltype(Calendar_Impl::MONTH_NAMES)>>>&>;

    {
        Calendar_Impl::MONTH_ABBREVS
    } -> std::same_as<const std::array<
        std::string_view,
        std::tuple_size_v<std::remove_cvref_t<decltype(Calendar_Impl::MONTH_ABBREVS)>>>&>;

    {
        Calendar_Impl::DAY_OF_WEEK_NAMES
    } -> std::same_as<const std::array<
        const char*,
        std::tuple_size_v<std::remove_cvref_t<decltype(Calendar_Impl::DAY_OF_WEEK_NAMES)>>>&>;

    {
        Calendar_Impl::DAY_OF_WEEK_ABBREVS
    } -> std::same_as<const std::array<
        std::string_view,
        std::tuple_size_v<std::remove_cvref_t<decltype(Calendar_Impl::DAY_OF_WEEK_ABBREVS)>>>&>;
};

template <typename Calendar_Impl>
concept has_structure_validation_methods = requires {
    {
        Calendar_Impl::isValidYear(std::declval<const typename Calendar_Impl::YearInt_t>())
    } -> std::same_as<bool>;

    { Calendar_Impl::isValidMonth(std::declval<const uint8_t>()) } -> std::same_as<bool>;
    { Calendar_Impl::isValidDay(std::declval<const uint8_t>()) } -> std::same_as<bool>;
    { Calendar_Impl::isValidDOWIndex(std::declval<const uint8_t>()) } -> std::same_as<bool>;
    { Calendar_Impl::isValidWeekIndex(std::declval<const uint8_t>()) } -> std::same_as<bool>;

    {
        Calendar_Impl::isValidDate(
            std::declval<const typename Calendar_Impl::YearInt_t>(),
            std::declval<const uint8_t>(),
            std::declval<const uint8_t>()
        )
    } -> std::same_as<bool>;
};

template <typename Calendar_Impl>
concept has_structure_query_methods = requires {
    {
        Calendar_Impl::getDaysInYear(std::declval<typename Calendar_Impl::YearInt_t>())
    } -> std::same_as<uint16_t>;

    {
        Calendar_Impl::getDaysInMonth(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<uint8_t>;

    {
        Calendar_Impl::getWeeksInMonth(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<uint8_t>;

    {
        Calendar_Impl::getWeeksMonthSpans(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<uint8_t>;

    {
        Calendar_Impl::getWeekIndex(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<uint8_t>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<uint8_t>;

    {
        Calendar_Impl::getDayOfWeekIndex(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<uint8_t>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<uint8_t>;

    {
        Calendar_Impl::getMonthEnumRepr(std::declval<uint8_t>())
    } -> std::same_as<typename Calendar_Impl::Month>;

    {
        Calendar_Impl::getMonthEnumRepr(std::declval<typename Calendar_Impl::Date>())
    } -> std::same_as<typename Calendar_Impl::Month>;

    {
        Calendar_Impl::getDayOfWeekEnumRepr(std::declval<typename Calendar_Impl::Date>())
    } -> std::same_as<typename Calendar_Impl::DayOfWeek>;
};

template <typename Calendar_Impl>
concept has_date_query_methods = requires {
    {
        Calendar_Impl::getDate(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<uint8_t>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getDate(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<typename Calendar_Impl::Month>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getDate(std::declval<stl::SystemTimePoint>())
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getDate(
            std::declval<stl::SystemTimePoint>(),
            typename Calendar_Impl::NonLocal{}
        )
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getNextDate(std::declval<typename Calendar_Impl::Date>())
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getNextDate(
            std::declval<typename Calendar_Impl::Date>(),
            std::declval<typename Calendar_Impl::DayOfWeek>()
        )
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getNextDate(
            std::declval<typename Calendar_Impl::Date>(),
            std::declval<typename Calendar_Impl::Month>()
        )
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getLastDate(std::declval<typename Calendar_Impl::Date>())
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getLastDate(
            std::declval<typename Calendar_Impl::Date>(),
            std::declval<typename Calendar_Impl::DayOfWeek>()
        )
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::getLastDate(
            std::declval<typename Calendar_Impl::Date>(),
            std::declval<typename Calendar_Impl::Month>()
        )
    } -> std::same_as<typename Calendar_Impl::Date>;

    // TODO: Add `Calendar_Impl::getWeek()` at some point...
    // (Requires generic `WeekDates` container alias)
};

template <typename Calendar_Impl>
concept has_standard_date_conversion_methods = requires {
    {
        Calendar_Impl::toDaysSinceEpoch(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<uint8_t>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<Days>;

    {
        Calendar_Impl::fromDaysSinceEpoch(std::declval<Days>())
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::toUnixTimestamp(
            std::declval<typename Calendar_Impl::YearInt_t>(),
            std::declval<uint8_t>(),
            std::declval<uint8_t>()
        )
    } -> std::same_as<stl::UnixTimestamp>;

    {
        Calendar_Impl::fromUnixTimestamp(std::declval<stl::UnixTimestamp>())
    } -> std::same_as<typename Calendar_Impl::Date>;

    {
        Calendar_Impl::fromUnixTimestamp(std::declval<Seconds>())
    } -> std::same_as<typename Calendar_Impl::Date>;
};

template <typename Calendar_Impl>
concept has_name_methods = requires {
    {
        Calendar_Impl::getMonthName(std::declval<uint8_t>())
    } -> std::same_as<const char*>;

    {
        Calendar_Impl::getMonthName(std::declval<typename Calendar_Impl::Month>())
    } -> std::same_as<const char*>;

    {
        Calendar_Impl::getMonthName(std::declval<typename Calendar_Impl::Date>())
    } -> std::same_as<const char*>;

    {
        Calendar_Impl::getMonthAbbrev(std::declval<uint8_t>())
    } -> std::same_as<std::string_view>;

    {
        Calendar_Impl::getMonthAbbrev(std::declval<typename Calendar_Impl::Month>())
    } -> std::same_as<std::string_view>;

    {
        Calendar_Impl::getMonthAbbrev(std::declval<typename Calendar_Impl::Date>())
    } -> std::same_as<std::string_view>;

    {
        Calendar_Impl::getDayOfWeekName(std::declval<typename Calendar_Impl::DayOfWeek>())
    } -> std::same_as<const char*>;

    {
        Calendar_Impl::getDayOfWeekName(std::declval<typename Calendar_Impl::Date>())
    } -> std::same_as<const char*>;

    {
        Calendar_Impl::getDayOfWeekAbbrev(std::declval<typename Calendar_Impl::DayOfWeek>())
    } -> std::same_as<std::string_view>;

    {
        Calendar_Impl::getDayOfWeekAbbrev(std::declval<typename Calendar_Impl::Date>())
    } -> std::same_as<std::string_view>;
};

} // namespace simplydt::concepts::calendar

#endif // SIMPLYDT_LIB_CALENDAR_CONCEPTS_H_
