
// Copyright (C) 2023-2025 by Jamon T. Bailey and Infinity Systems, LLC. All rights reserved.
// Released under the terms of the GNU Affero General Public License version 3.

// [ISJTB-CXX-XL20230401-000001]

#include "simplydt/coord_universal_time/utc_time.hpp"

//	simplydt::utc::Time : CONSTRUCTOR

simplydt::utc::Time::Time(
    const uint8_t hour, const uint8_t minute, const uint8_t second
) noexcept
    : time{ DEFAULT_TIME }
{
    Time::encodeUTCTimeIntoInteger(&this->time, hour, minute, second);
}

simplydt::utc::Time::Time(const uint8_t hour, const uint8_t minute) noexcept
    : time{ DEFAULT_TIME }
{
    Time::encodeUTCTimeIntoInteger(&this->time, hour, minute, 0);
}

simplydt::utc::Time::Time(const Time& time) noexcept : time{ time.time }
{
    //
}

simplydt::utc::Time::Time() noexcept : time{ DEFAULT_TIME }
{
    //
}

//	simplydt::utc::Time : CONSTRUCTOR END!


//	simplydt::utc::Time : STATIC

bool simplydt::utc::Time::encodeUTCTimeIntoInteger(
    Underlying_T* integer, const uint8_t& hour, const uint8_t& minute, const uint8_t& second
) noexcept
{
    if (integer == nullptr)
        return false;

    if ((hour > MAX_HOURS_IN_DAY) || (minute > MAX_MINUTES_IN_HOUR) ||
        (second > MAX_SECONDS_IN_MINUTE))
        return false; // Invalid UTC time params

    *integer = ((hour * HOUR_FACTOR) + (minute * MINUTE_FACTOR) + second);

    return true;
}

//	simplydt::utc::Time : STATIC END!


//	simplydt::utc::Time : OPERATOR

bool simplydt::utc::Time::operator==(const Time time) const noexcept
{
    return this->time == time.time;
}

bool simplydt::utc::Time::operator<(const Time time) const noexcept
{
    return this->time < time.time;
}

bool simplydt::utc::Time::operator>(const Time time) const noexcept
{
    return this->time > time.time;
}

bool simplydt::utc::Time::operator<=(const Time time) const noexcept
{
    return this->time <= time.time;
}

bool simplydt::utc::Time::operator>=(const Time time) const noexcept
{
    return this->time >= time.time;
}

uint16_t simplydt::utc::Time::operator[](const CalendarComponent component) const noexcept
{
    return this->getComponent(component);
}

//	simplydt::utc::Time : OPERATOR END!


//	simplydt::utc::Time : PUBLIC

uint8_t simplydt::utc::Time::hour() const noexcept
{
    return static_cast<uint8_t>(this->time / HOUR_FACTOR);
}

std::string simplydt::utc::Time::hourPhaseLiteral() const noexcept
{
    if ((this->time / HOUR_FACTOR) < 12)
        return MeridiemPhases[AM];

    return MeridiemPhases[PM];
}

uint8_t simplydt::utc::Time::minute() const noexcept
{
    return static_cast<uint8_t>((this->time % HOUR_FACTOR) / MINUTE_FACTOR);
}

uint8_t simplydt::utc::Time::second() const noexcept
{
    return static_cast<uint8_t>((this->time % HOUR_FACTOR) % MINUTE_FACTOR);
}

uint16_t simplydt::utc::Time::getComponent(const CalendarComponent component) const noexcept
{
    switch (component) {
    case CalendarComponent::HOUR:
        return static_cast<uint8_t>(this->hour());

    case CalendarComponent::MINUTE:
        return static_cast<uint8_t>(this->minute());

    case CalendarComponent::SECOND:
        return static_cast<uint8_t>(this->second());

    default:
        return 0; // Invalid component
    }
}

std::string simplydt::utc::Time::toStr() const noexcept
{
    const char delimiter = ':';

    std::string timeStr;
    timeStr.reserve(12);

    timeStr += (std::to_string(this->hour()) + delimiter);
    timeStr += (toDoubleDigitStr(this->minute()) + delimiter);
    timeStr += (toDoubleDigitStr(this->second()) + ' ');
    timeStr += this->hourPhaseLiteral();

    return timeStr;
}

simplydt::utc::Time::Underlying_T simplydt::utc::Time::underlying() const noexcept
{
    return this->time;
}

//	simplydt::utc::Time : PUBLIC END!


//	simplydt::utc::Time : PROTECTED
//	simplydt::utc::Time : PROTECTED END!


//	simplydt::utc::Time : PRIVATE
//	simplydt::utc::Time : PRIVATE END!
