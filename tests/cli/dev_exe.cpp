
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

int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    // Sample Gregorian date implementation
    struct GregorianDate : public simplydt::CalendarDate<GregorianDate, uint16_t> {
        using Repr_Type = uint32_t;

        GregorianDate() noexcept
            : simplydt::CalendarDate<GregorianDate, uint16_t>{ }, date{ 19700101 }
        {
            //
        }

        ~GregorianDate() = default;

        // Start...

    private:
        Repr_Type date;
    };

    //GregorianDate::Date;
    //GregorianDate::YearInt_t;
    //

    return 0;
}
