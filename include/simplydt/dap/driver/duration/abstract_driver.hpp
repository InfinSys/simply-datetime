
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file abstract_driver.hpp
 *
 * @brief
 * Abstract duration driver interface.
 */

#ifndef SIMPLYDT_LIB_ABSTRACT_DURATION_DRIVER_H_
#define SIMPLYDT_LIB_ABSTRACT_DURATION_DRIVER_H_

#include "simplydt/dap/concepts/method_call.hpp"
#include "simplydt/dap/driver/abstract_tag.hpp"
#include <cstdint>

namespace simplydt::dap
{

    /*!
     * @brief
     * Duration driver interface abstraction.
     * 
     * @details
     * This type cannot be instantiated on its own since
     * the interface it presents is abstract. It is meant
     * to be inherited by another class which will then
     * present concrete implementations of the functionality
     * outlined here. The presence of a method definition
     * in this base class alone does not automatically
     * enforce a requirement on the derivatives; that is
     * achieved by using concepts. The API extended by this
     * class is protected and only accessible by derived
     * entities. The protected API uses static methods that
     * follow the "pointer-to-self" convention. On the
     * contrary, the API extended by a derivative is expected
     * to be public and typically with use of member methods.
     */
    template <typename Duration_T>
    class AbstractDurationDriver : public AbstractDAPDriver {

      public:
        /*!
         * @brief
         * Underlying duration representation type.
         */
        using Underlying_T = Duration_T;

        /*!
         * @brief
         * Type alias of base duration abstraction.
         */
        using Driver = AbstractDurationDriver<Duration_T>;

      protected:
        AbstractDurationDriver() noexcept { }

        ~AbstractDurationDriver() noexcept = default;

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static bool isDefaultValue(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(bool, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static bool isNegativeValue(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(bool, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static int32_t getElapsedDays(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(int32_t, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static uint32_t getAbsoluteElapsedDays(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(uint32_t, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static int8_t getHoursComponent(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(int8_t, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static uint8_t getAbsoluteHours(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(uint8_t, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static int8_t getMinutesComponent(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(int8_t, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static uint8_t getAbsoluteMinutes(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(uint8_t, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static int8_t getSecondsComponent(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(int8_t, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static uint8_t getAbsoluteSeconds(const Duration_T& selfImpl)
        {
            ASSERT_RETURN_TYPES_EQ(uint8_t, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static Duration_T calculateDisplace(const Duration_T& selfImpl, const Duration_T& durationImpl)
        {
            ASSERT_RETURN_TYPES_EQ(Duration_T, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl, durationImpl);
        }

        /*! @brief Overload base functionality using provided implementation. */
        template <concepts::valid_template_overload Overload_Impl>
        static void displace(Duration_T& selfImpl, const Duration_T& durationImpl)
        {
            ASSERT_RETURN_TYPES_EQ(void, typename Overload_Impl::ReturnType);
            return Overload_Impl::call(selfImpl, durationImpl);
        }
    };

} // namespace simplydt::dap

#endif // SIMPLYDT_LIB_ABSTRACT_DURATION_DRIVER_H_
