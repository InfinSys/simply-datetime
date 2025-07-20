
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file string_utils.hpp
 *
 * @brief
 * String utilities.
 */


#ifndef SIMPLYDT_LIB_STRING_UTILITIES_H_
#define SIMPLYDT_LIB_STRING_UTILITIES_H_

#include <string>

namespace simplydt
{

/*!
 * @brief
 * Convert integer value to a double digit string.
 *
 * @details
 * This method takes an integer value of arbitrary type
 * and converts it to a string that only consist of two
 * digits. Values less than 10 are prefixed with a '0',
 * and values greater than 99 are truncated to their
 * last two digits using modulus division.
 *
 * @return
 * Double-digit string
 */
template <typename Int_T>
requires std::is_integral_v<Int_T>
[[nodiscard]] inline std::string toDoubleDigitStr(const Int_T integer) noexcept
{
    if (integer < 10)
        return (std::string{"0"} + std::to_string(integer));
    else
        return std::to_string(integer % 100);
}

} // namespace simplydt

#endif // SIMPLYDT_LIB_STRING_UTILITIES_H_
