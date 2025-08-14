
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
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
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr const char* getMonthName(const Date date) noexcept
    {
        return date.monthLiteral();
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static std::string getMonthAbbrev(const Date date) noexcept
    {
        return date.monthAbbreviation();
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
     */
    [[nodiscard]] static constexpr Month getMonthEnumRepr(const Date date) noexcept
    {
        return static_cast<Month>(date.month() - 1);
    }

    /*!
     * @brief
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
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
     * TODO: INCOMPLETE COMMENT!!!
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
