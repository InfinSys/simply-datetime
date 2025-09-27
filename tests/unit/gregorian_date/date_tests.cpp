
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]


//\\//\\//\\//\\//\\//\\////\\//\\//\\
//   GREGORIAN CALENDAR DATE TESTS  \\
//\\//\\//\\//\\//\\//\\////\\//\\//\\


#include<gtest/gtest.h>
#include "simplydt/calendar/gregorian/gregorian_date.hpp"

namespace simplydt::GregorianDateTests
{

/*!
 * @details
 * Tests that a default constructed Gregorian calendar
 * date represents the Unix epoch date (January 1,
 * 1970). The individual date components are queried
 * for the expected date values and the underlying
 * serial count is confirmed to be zero (0) in this
 * state.
 */
TEST(GregorianDateTests, CreatesUnixEpochOnDefaultCtor)
{
    using namespace simplydt::gregorian;

    const GregorianDate::YearInt_t unixEpochYear = 1970;
    const uint8_t unixEpochMonth = 1; // January
    const uint8_t unixEpochDay   = 1; // First of month

    // Construct default Gregorian date
    const GregorianDate epoch{};

    // Check that dates components describe January 1, 1970
    EXPECT_EQ(epoch.year(), unixEpochYear);
    EXPECT_EQ(epoch.month(), unixEpochMonth);
    EXPECT_EQ(epoch.day(), unixEpochDay);

    // Check that underlying serial count is 0
    EXPECT_EQ(epoch.underlying(), 0);
}

}
