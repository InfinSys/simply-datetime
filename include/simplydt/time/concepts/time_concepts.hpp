
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file time_concepts.hpp
 *
 * @brief
 * Agnostic temporal time concepts.
 */


#ifndef SIMPLYDT_LIB_TEMPORAL_TIME_CONCEPTS_H_
#define SIMPLYDT_LIB_TEMPORAL_TIME_CONCEPTS_H_

#include <concepts>
#include <ostream>
#include <string>

/*!
 * @namespace simplydt::concepts::time
 *
 * @brief
 * Time concepts.
 */
namespace simplydt::concepts::time
{

template <typename Time_Impl>
concept has_contextual_nested_types = requires {
    typename Time_Impl::Repr_Type;
    typename Time_Impl::Unit_Resolution;
};

template <typename Time_Impl>
concept has_standard_time_component_methods = requires(const Time_Impl& t) {
    { t.hour() } -> std::same_as<uint8_t>;
    { t.minute() } -> std::same_as<uint8_t>;
    { t.second() } -> std::same_as<uint8_t>;
};

template <typename Time_Impl>
concept has_logical_operators = requires(const Time_Impl& t) {
    { t == t } -> std::same_as<bool>;
    { t < t } -> std::same_as<bool>;
    { t > t } -> std::same_as<bool>;
    { t <= t } -> std::same_as<bool>;
    { t >= t } -> std::same_as<bool>;
};

template <typename Time_Impl>
concept has_arithmetic_operators =
    requires(Time_Impl& t, typename Time_Impl::Unit_Resolution units) {
        { t + units } -> std::same_as<Time_Impl>;
        { t - units } -> std::same_as<Time_Impl>;
        { t - t } -> std::same_as<typename Time_Impl::Unit_Resolution>;
        { t += units } -> std::same_as<Time_Impl&>;
        { t -= units } -> std::same_as<Time_Impl&>;
        { ++t } -> std::same_as<Time_Impl&>;
        { t++ } -> std::same_as<Time_Impl>;
        { --t } -> std::same_as<Time_Impl&>;
        { t-- } -> std::same_as<Time_Impl>;
    };

template <typename Time_Impl>
concept has_basic_state_methods = requires(const Time_Impl& t) {
    { t.isZero() } -> std::same_as<bool>;
    { t.units() } -> std::same_as<typename Time_Impl::Unit_Resolution>;
    { t.underlying() } -> std::same_as<const typename Time_Impl::Repr_Type&>;
};

template <typename Time_Impl>
concept is_stream_out_compatible = requires(std::ostream& os, const Time_Impl& t) {
    { os << t } -> std::convertible_to<std::ostream&>;
};

template <typename Time_Impl>
concept has_sequential_evaluation_methods = requires(const Time_Impl& t) {
    { t.isBefore(t) } -> std::same_as<bool>;
    { t.isAfter(t) } -> std::same_as<bool>;
    { t.isBetween(t, t) } -> std::same_as<bool>;
};

template <typename Time_Impl>
concept has_time_string_methods = requires(const Time_Impl& t) {
    { t.toStr() } -> std::same_as<std::string>;
    { t.hourPhaseStr() } -> std::same_as<const char*>;
};

} // namespace simplydt::concepts::time

#endif // SIMPLYDT_LIB_TEMPORAL_TIME_CONCEPTS_H_
