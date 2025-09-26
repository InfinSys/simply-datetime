
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file date_concepts.hpp
 *
 * @brief
 * Agnostic calendar date concepts.
 */


#ifndef SIMPLYDT_LIB_CALENDAR_DATE_CONCEPTS_H_
#define SIMPLYDT_LIB_CALENDAR_DATE_CONCEPTS_H_

#include "simplydt/time/units/time_units.hpp"
#include <concepts>
#include <ostream>
#include <string>

/*!
 * @namespace simplydt::concepts
 *
 * @brief
 * Simply Datetime library concepts.
 */
namespace simplydt::concepts
{ }

/*!
 * @namespace simplydt::concepts::date
 *
 * @brief
 * Calendar date concepts.
 */
namespace simplydt::concepts::date
{

template <typename Date_Impl>
concept has_date_component_methods = requires(const Date_Impl& d) {
    { d.year() } -> std::same_as<typename Date_Impl::YearInt_t>;
    { d.month() } -> std::same_as<uint8_t>;
    { d.day() } -> std::same_as<uint8_t>;
};

template <typename Date_Impl>
concept has_logical_operators = requires(const Date_Impl& d) {
    { d == d } -> std::same_as<bool>;
    { d < d } -> std::same_as<bool>;
    { d > d } -> std::same_as<bool>;
    { d <= d } -> std::same_as<bool>;
    { d >= d } -> std::same_as<bool>;
};

template <typename Date_Impl>
concept has_arithmetic_operators = requires(Date_Impl& d, simplydt::Days days) {
    { d + days } -> std::same_as<Date_Impl>;
    { d - days } -> std::same_as<Date_Impl>;
    { d - d } -> std::same_as<simplydt::Days>;
    { d += days } -> std::same_as<Date_Impl&>;
    { d -= days } -> std::same_as<Date_Impl&>;
    { ++d } -> std::same_as<Date_Impl&>;
    { d++ } -> std::same_as<Date_Impl>;
    { --d } -> std::same_as<Date_Impl&>;
    { d-- } -> std::same_as<Date_Impl>;
};

template <typename Date_Impl>
concept has_basic_state_methods = requires(const Date_Impl& d) {
    { d.isZero() } -> std::same_as<bool>;
    { d.underlying() } -> std::same_as<const typename Date_Impl::Repr_Type&>;
    { d.units() } -> std::same_as<simplydt::Days>;
};

template <typename Date_Impl>
concept is_stream_out_compatible = requires(std::ostream& os, const Date_Impl& d) {
    { os << d } -> std::convertible_to<std::ostream&>;
};

template <typename Date_Impl>
concept has_sequential_evaluation_methods = requires(const Date_Impl& d) {
    { d.isBefore(d) } -> std::same_as<bool>;
    { d.isAfter(d) } -> std::same_as<bool>;
    { d.isBetween(d, d) } -> std::same_as<bool>;
    { d.daysUntil(d) } -> std::same_as<simplydt::Days>;
};

template <typename Date_Impl>
concept has_date_string_methods = requires(const Date_Impl& d) {
    //_// { d.monthStr() } -> std::same_as<const char*>;
    //_// { d.monthAbbrev() } -> std::same_as<std::string_view>;
    { d.toStr() } -> std::same_as<std::string>;
};

template <typename Date_Impl>
concept has_contextual_nested_types = requires {
    typename Date_Impl::Repr_Type;
    typename Date_Impl::YearInt_t;
    typename Date_Impl::ValidationPolicy;
};

} // namespace simplydt::concepts::date

#endif // SIMPLYDT_LIB_CALENDAR_DATE_CONCEPTS_H_
