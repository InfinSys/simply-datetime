
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
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

#include <concepts>
#include "simplydt/calendar/type_traits/date_traits.hpp"

/*!
* @namespace simplydt::concepts
* 
* @brief
* Simply Datetime library concepts.
*/
namespace simplydt::concepts { }

/*!
* @namespace simplydt::concepts::date
*
* @brief
* Calendar date concepts.
*/
namespace simplydt::concepts::date
{

// TODO: INCOMPLETE!!!
// nested_date_types : Check for the expected nested types of a date???
// concepts::date::has_contextual_nested_types

    template <typename Date_Impl, typename Year_T>
    concept has_date_component_methods = requires(Date_Impl& d) {
        //{ d.year() } -> std::same_as<Year_T>;
        //{ d.month() } -> std::same_as<uint8_t>;
        { d.day() } -> std::convertible_to<uint8_t>;
    };

    template <typename Date_Impl>
    concept has_basic_state_methods = requires(Date_Impl& d) {
        { d.isDefault() } -> std::same_as<bool>;
    };

}

#endif // SIMPLYDT_LIB_CALENDAR_DATE_CONCEPTS_H_
