
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file gregorian_date.hpp
 *
 * @brief
 * Gregorian calendar date declaration.
 */


#ifndef SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_
#define SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_

#include "simplydt/calendar/concepts/date_contract.hpp"
#include "simplydt/calendar/date/abstract_date.hpp"
#include "simplydt/calendar/gregorian/gregorian_defs.hpp"
#include "simplydt/common/string_utils.hpp"
#include <ostream>

namespace simplydt::gregorian
{

/*!
 * @brief
 * Gregorian calendar date.
 *
 * @details
 * This type serves as a broken-down form of
 * Gregorian calendar dates and has no calendar
 * knowledge. This type does not validate the
 * date values provided to the constructor beyond
 * disregarding nonsensical values. Such values
 * are the kind that could obviously never be a
 * date (i.e, 2023-04-32, 2023-15-11, etc).
 * Consequently, a well-constructed `GregorianDate`
 * does not automatically imply that date exists on
 * the real-world calendar. The calendar can verify
 * the validity of the date held by this type.
 */
struct GregorianDate final : public CalendarDate<GregorianDate, Year_Type> {
    /*! @brief Underlying date representation type. */
    using Repr_Type = uint32_t;

    /*! @brief Factor used to store and retrieve year values. */
    static constexpr Repr_Type YEAR_FACTOR = 10'000;

    /*! @brief Factor used to store and retrieve month values. */
    static constexpr Repr_Type MONTH_FACTOR = 100;

    /*! @brief Default Gregorian calendar date. */
    static constexpr Repr_Type DEFAULT_DATE = ((1'970 * YEAR_FACTOR) + 101);

    /*!
     * @brief
     * Encoded Gregorian calendar date to integer.
     *
     * @return
     * Gregorian calendar date as integer
     */
    static constexpr Repr_Type encodeGregorianDateToInteger(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
    {
        if ((year < YEAR_MINIMUM) || (year > YEAR_MAXIMUM) || (month < MIN_MONTH_OF_YEAR) ||
            (month > MAX_MONTH_OF_YEAR) || (day < MIN_DAY_OF_MONTH) ||
            (day > MAX_DAY_OF_MONTH))
            return 0; // Invalid date params

        return ((year * YEAR_FACTOR) + (month * MONTH_FACTOR) + day);
    }

    /*!
     * @brief
     * Intercept invalid signal from date encoding and return
     * default date.
     *
     * @details
     * This is a compile-time helper for the `GregorianDate`
     * constructors. Non-zero values pass through this method
     * while zeros are intercepted and yeild the default date.
     *
     * @return
     * Valid encoded date, default date otherwise
     */
    static constexpr Repr_Type useDefaultIfInvalid(const Repr_Type& encoded_date) noexcept
    {
        return (encoded_date == 0) ? DEFAULT_DATE : encoded_date;
    }

    /*!
     * @brief
     * Retrieve year component from encoded Gregorian
     * date integer.
     *
     * @return
     * Gregorian date year component
     */
    static constexpr YearInt_t extractEncodedYear(const Repr_Type& encoded_date) noexcept
    {
        return static_cast<YearInt_t>(encoded_date / YEAR_FACTOR);
    }

    /*!
     * @brief
     * Retrieve month component from encoded Gregorian
     * date integer.
     *
     * @return
     * Gregorian date month component
     */
    static constexpr uint8_t extractEncodedMonth(const Repr_Type& encoded_date) noexcept
    {
        return static_cast<uint8_t>((encoded_date % YEAR_FACTOR) / MONTH_FACTOR);
    }

    /*!
     * @brief
     * Retrieve day component from encoded Gregorian
     * date integer.
     *
     * @return
     * Gregorian date day component
     */
    static constexpr uint8_t extractEncodedDay(const Repr_Type& encoded_date) noexcept
    {
        return static_cast<uint8_t>((encoded_date % YEAR_FACTOR) % MONTH_FACTOR);
    }

    /*!
     * @brief
     * Construct Gregorian calendar date using year,
     * month, and day values.
     */
    constexpr GregorianDate(
        const YearInt_t year, const uint8_t month, const uint8_t day
    ) noexcept
        : CalendarDate<GregorianDate, Year_Type>{},
          date{useDefaultIfInvalid(encodeGregorianDateToInteger(year, month, day))}
    {
        //
    }

    /*!
     * @brief
     * Construct Gregorian calendar date using year
     * and month values; assume first of month.
     */
    constexpr GregorianDate(const YearInt_t year, const uint8_t month) noexcept
        : CalendarDate<GregorianDate, Year_Type>{},
          date{useDefaultIfInvalid(encodeGregorianDateToInteger(year, month, 1))}
    {
        //
    }

    /*!
     * @brief
     * Construct default Gregorian calendar date.
     */
    constexpr GregorianDate() noexcept
        : CalendarDate<GregorianDate, Year_Type>{}, date{DEFAULT_DATE}
    {
        //
    }

    ~GregorianDate() = default;

    friend inline std::ostream& operator<<(std::ostream& os, const GregorianDate date) noexcept
    {
        os << date.toStr();
        return os;
    }

    /*! @brief Evaluate equivalence of Gregorian dates. */
    [[nodiscard]] constexpr bool operator==(const GregorianDate date) const noexcept
    {
        return this->date == date.date;
    }

    /*! @brief Determine if left-hand side is sequentially before right-hand side. */
    [[nodiscard]] constexpr bool operator<(const GregorianDate date) const noexcept
    {
        return this->date < date.date;
    }

    /*! @brief Determine if left-hand side is sequentially after right-hand side. */
    [[nodiscard]] constexpr bool operator>(const GregorianDate date) const noexcept
    {
        return this->date > date.date;
    }

    [[nodiscard]] constexpr bool operator<=(const GregorianDate date) const noexcept
    {
        return this->date <= date.date;
    }

    [[nodiscard]] constexpr bool operator>=(const GregorianDate date) const noexcept
    {
        return this->date >= date.date;
    }

    /*! @brief Index Gregorian calendar date components. */
    [[nodiscard]] std::optional<YearInt_t> operator[](const CalendarComponent component
    ) const noexcept
    {
        return this->getComponent(component);
    }

    /*!
     * @brief
     * Evaluate if date is epoch.
     *
     * @return
     * True if date is epoch date
     */
    [[nodiscard]] constexpr bool isDefault() const noexcept
    {
        return this->date == DEFAULT_DATE;
    }

    /*!
     * @brief
     * Date year component.
     *
     * @return
     * Year of Gregorian calendar date
     */
    [[nodiscard]] constexpr YearInt_t year() const noexcept
    {
        return extractEncodedYear(this->date);
    }

    /*!
     * @brief
     * Date month component.
     *
     * @return
     * Month of Gregorian calendar date
     */
    [[nodiscard]] constexpr uint8_t month() const noexcept
    {
        return extractEncodedMonth(this->date);
    }

    /*!
     * @brief
     * Month name.
     *
     * @return
     * Month literal
     */
    [[nodiscard]] constexpr const char* monthStr() const noexcept
    {
        const uint8_t monthIndex = extractEncodedMonth(this->date) - 1;
        return Months[monthIndex];
    }

    /*!
     * @brief
     * Abbreviated month name.
     *
     * @return
     * Abbreviated month literal
     */
    [[nodiscard]] constexpr std::string monthAbbreviation() const noexcept
    {
        const uint8_t monthIndex = extractEncodedMonth(this->date) - 1;
        return std::string{MonthAbbrevs[monthIndex]};
    }

    /*!
     * @brief
     * Date day component.
     *
     * @return
     * Day of Gregorian calendar date
     */
    [[nodiscard]] constexpr uint8_t day() const noexcept
    {
        return extractEncodedDay(this->date);
    }

    /*!
     * @brief
     * Compose string representation of Gregorian
     * calendar date.
     *
     * @return
     * Gregorian calendar date as string
     */
    [[nodiscard]] std::string toStr() const noexcept
    {
        const char delimiter = '-';

        std::string dateStr;
        dateStr.reserve(12);
        dateStr += (std::to_string(this->year()) + delimiter);
        dateStr += (toDoubleDigitStr(this->month()) + delimiter);
        dateStr += toDoubleDigitStr(this->day());
        return dateStr;
    }

    /*!
     * @brief
     * Returns underlying representation of Gregorian
     * calendar date.
     *
     * @return
     * Gregorian calendar date as integer
     */
    [[nodiscard]] constexpr Repr_Type underlying() const noexcept
    {
        return this->date;
    }

  private:
    Repr_Type date; ///< Calendar date
};

SIMPLYDT_ENFORCE_DATE_CONTRACT(GregorianDate);

} // namespace simplydt::gregorian

#endif // SIMPLYDT_LIB_GREGORIAN_DATE_STRUCT_H_
