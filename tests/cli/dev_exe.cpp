
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

// Sample Gregorian date interface
struct GregorianDate : public simplydt::CalendarDate<GregorianDate, uint16_t> {
    /*! @brief Underlying date representation type. */
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
    Repr_Type date; ///< Calendar date
};


//========================================================\\
// :: ~ "Managing the Incomplete Type Issue w/ CRTP" ~ :: \\
//========================================================\\
//
// PROBLEM:
// -> The base CRTP CalendarDate class enforces a concept
//    called 'contract_abiding_date'.
// -> The 'contract_abiding_date' concept enforces a set
//    of sub-concepts that seek to validate aspects of
//    the derived CRTP classes interface.
// -> However, the derived classes interface has not yet
//    been parsed by the compiler. The concept is trying
//    to validate a type that is incomplete.
// -> This is because the concept is invoked while we are
//    actively in the middle of declaring the derived
//    type and its interface.
//
// SOLUTIONS:
// -> Defer interface validation to elsewhere; but where?
//      -> (This approach will cause substitution failure
//          error messages to touch the build log, not
//          something we want happening...)
// -> Remove 'contract_abiding_date' concept from CRTP base
//    and instead enforce a subset of constraints that do
//    not concern the derived interface. Then throughout the
//    library, enforce the 'contract_abiding_date' concept
//    where applicable.
//
// NOTES:
// -> Recall that you made the decision to use CRTP
//    in a customized manner where the roles of the base
//    and derived element switched. It is the derived
//    class that presents the public interface while the
//    base takes a back seat and just provides common
//    functionality.
//
//========================================================\\



int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    //

    return 0;
}
