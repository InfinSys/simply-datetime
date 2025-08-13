
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
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
#include "simplydt/calendar/type_traits/calendar_traits.hpp"
#include "simplydt/common/calendar_defs.hpp"
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
};

template <typename Calendar_Impl>
concept has_characteristic_query_members = requires {
    { Calendar_Impl::calendar } -> std::same_as<const CalendarSystem&>;
    { Calendar_Impl::isSolarCalendar } -> std::same_as<const bool&>;
    { Calendar_Impl::isLunarCalendar } -> std::same_as<const bool&>;
    { Calendar_Impl::isLunisolarCalendar } -> std::same_as<const bool&>;
};

template <typename Calendar_Impl>
concept has_date_validation_methods = requires {
    {
        Calendar_Impl::isValidYear(std::declval<const typename Calendar_Impl::YearInt_t>())
    } -> std::same_as<bool>;

    { Calendar_Impl::isValidMonth(std::declval<const uint8_t>()) } -> std::same_as<bool>;
    { Calendar_Impl::isValidDay(std::declval<const uint8_t>()) } -> std::same_as<bool>;

    {
        Calendar_Impl::isValidDate(std::declval<const typename Calendar_Impl::Date>())
    } -> std::same_as<bool>;
};

} // namespace simplydt::concepts::calendar

#endif // SIMPLYDT_LIB_CALENDAR_CONCEPTS_H_
