
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] N/a
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */

// Includes...
#include "simplydt/calendar/abstract_calendar.hpp"
#include "simplydt/calendar/date/abstract_date.hpp"

// Sample Gregorian date implementation
struct GregorianDate : public simplydt::CalendarDate<GregorianDate, uint16_t> {
    using Repr_Type = uint32_t;

    GregorianDate() noexcept
        : simplydt::CalendarDate<GregorianDate, uint16_t>{ }, date{ 19700101 }
    {
        //
    }

    ~GregorianDate() = default;

    uint16_t year() const noexcept { return 2025; }
    uint8_t month() const noexcept { return 8; }
    uint8_t day() noexcept { return 5; }

private:
    Repr_Type date;
};


int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    //

    return 0;
}
