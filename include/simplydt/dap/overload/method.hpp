
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file method.hpp
 *
 * @brief
 * Method overload entity declaration.
 */

#ifndef SIMPLYDT_LIB_METHOD_OVERLOAD_STRUCT_H_
#define SIMPLYDT_LIB_METHOD_OVERLOAD_STRUCT_H_

#include "simplydt/dap/overload/arguments.hpp"

namespace simplydt::dap
{

    /*!
     * @brief
     * Method overload implementation struct.
     *
     * @details
     * This type is meant to be inherited by other
     * structs which will represent the overloaded
     * implementation of some template method. The
     * template methods invoke the implementation
     * detailed by a derivative of this type through
     * an implicit contract between the two.
     * Typically the methods implemented by this
     * type are static, but in most cases there is
     * no performance difference if they are member
     * methods.
     */
    template <typename... ArgTypes>
    struct Overload {
        /*! @brief Overload method argument types. */
        using MethodArgs = Arguments<ArgTypes...>;
    };

} // namespace simplydt::dap

#endif // SIMPLYDT_LIB_METHOD_OVERLOAD_STRUCT_H_
