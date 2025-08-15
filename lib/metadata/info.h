
// Copyright (C) 2026 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

/*!
 * @file info.h
 *
 * @brief
 * Software identification document.
 *
 * @details
 * Metadata for Simply Datetime.
 */


#ifndef SIMPLYDT_SOFTWARE_IDENTITY_H_
#define SIMPLYDT_SOFTWARE_IDENTITY_H_

#include <stdint.h>

extern "C"
{
/*!
 * @brief
 * Simply Datetime publisher.
 */
const char SIMPLYDT_PUBLISHER[] = "Infinity Systems, LLC.";

/*!
 * @brief
 * Simply Datetime software type.
 */
const char SIMPLYDT_SOFTWARE_TYPE[] = "Library";

/*!
 * @brief
 * Simply Datetime interface type.
 */
const char SIMPLYDT_INTERFACE_TYPE[] = "API";

/*!
 * @brief
 * Simply Datetime universally unique identifier.
 */
const char SIMPLYDT_UUID[] = "ISJTB-CXX-XL20230401-000001";

/*!
 * @brief
 * Simply Datetime distribution license type.
 */
const char SIMPLYDT_LICENSE_TYPE[] = "AGPLv3";

/*!
 * @brief
 * Software full name.
 */
const char SIMPLYDT_FULL_NAME[] = "Simply Datetime";

/*!
 * @brief
 * Software short name.
 */
const char SIMPLYDT_SHORT_NAME[] = "Simply Datetime";

/*!
 * @brief
 * Simply Datetime main binary name.
 */
const char SIMPLYDT_MAIN_BINARY[] = "simplydt";

} // Extern "C"

#endif // SIMPLYDT_SOFTWARE_IDENTITY_H_
