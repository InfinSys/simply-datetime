
#include "dev_utils.hpp"

/* /// \\\ /// \\\ /// | TO-DO | \\\ /// \\\ /// \\\ *\
*
* ~ CLI Debug Executable Notes / TO-DO List ~
*
* -> [] Need a general place for stuff like
*       'YEAR_MIN/MAX', 'Invalid' string, etc.
*
\* /// \\\ /// \\\ ///  | END |  \\\ /// \\\ /// \\\ */


// ~ Possible Method to Shrink Date to 16-bits ~ //
//
//                    (STEPS):
// 1. Encode Gregorian date into integer per usual.
// 2. Deduct necessary amount to make last steps
//    value cleanly divisible by 10.
//    -> (RETAIN THE DEDUCTED AMOUNT!)
// 3. Using a loop, compose a divisor that increases
//    in decimal magnitude (x10) with each iteration
//    until it is an appropriate amount to compress
//    the given encoded date integer.
//    -> (RETAIN THE NUMBER OF LOOP ITERATIONS!)
//    -> (The amount used to divide the date cannot
//        be too excessive or light.)
//    -> (Idealy the computed value should be 4-5
//        significant figures.)
// 4. Divide the encoded date by the value computed
//    from the previous step. The divisor cannot be
//    too excessive because the two retained values
//    from steps 2 and 3 will now be encoded into
//    the tail-end of this steps computed value.
//    -> (Neither of the two retained values will
//        exceed 1 significant figure.)
// 5. This is your uint16_t Gregorian date than can
//    be completely reversed with no information
//    loss.
//=================================================


#include "simplydt/coord_universal_time/utc_time.hpp"
#include "simplydt/dap/driver/duration/abstract_driver.hpp"
#include "simplydt/gregorian_calendar/gregorian_date.hpp"


// SAMPLE BELOW:

/*! @brief Example duration implementation. */
class FakeDuration final : public simplydt::dap::AbstractDurationDriver<double> {

public:
    static constexpr Underlying_T DEFAULT_VALUE = 0.0;

    FakeDuration() noexcept
        : AbstractDurationDriver{},
        duration{ DEFAULT_VALUE }
    {
        //
    }

    ~FakeDuration() = default;

    /*! @brief Determine if duration value is default. */
    [[nodiscard]] bool isDefault() const noexcept
    {
        return isDefaultValue<IsDefaultValue_Impl>(this->duration);
    }

    /*! @brief Determine if duration represents negative elapsed time. */
    [[nodiscard]] bool isNegative() const noexcept
    {
        return isNegativeValue<IsNegativeValue_Impl>(this->duration);
    }

    [[nodiscard]] const Underlying_T& underlying() const noexcept
    {
        return this->duration;
    }

    /*! @brief Determine if duration value is default. */
    struct IsDefaultValue_Impl : simplydt::dap::Overload<const Underlying_T&> {
        using ReturnType = bool;

        static ReturnType call(const Underlying_T& selfImpl) noexcept { return selfImpl == DEFAULT_VALUE; }
    };

    /*! @brief Determine if duration represents negative elapsed time. */
    struct IsNegativeValue_Impl : simplydt::dap::Overload<const Underlying_T&> {
        using ReturnType = bool;

        static ReturnType call(const Underlying_T& selfImpl) noexcept { return selfImpl < 0.0; }
    };

private:
    Underlying_T duration;

};

// SAMPLE ABOVE:


int main(int argc, char* argv[])
{
    ProjectInfoOut();

    //\\//
    using namespace simplydt;

    FakeDuration demo{};

    std::cout << "\nIs default? -> " << std::boolalpha << demo.isDefault() << std::endl;

    // 1. Create concepts::useable_underlying_type<T>
    // 2. Create concepts::valid_dap_duration<T>
    //    -> Requires type traits
    // 3. Create dap::AbstractDatetimeDriver<...>
    // 4. Implement JDN algorithms
    // 5. Implement DOW algorithm
    // 6. Implement SDT datetime configuration
    // 7. Create contract::dap_duration_compliant
    // 8. Create contract::dap_datetime_compliant
    // 9. Implement STL datetime configuration

    // template <concepts::valid_dap_duration DurationImpl, concepts::useable_underlying_type Datetime_T>
    // class AbstractDatetimeDriver;
    
    // template <contract::dap_datetime_compliant Datetime_Impl>
    // using StandardDatetimeAPI = Datetime_Impl;

    return 0;
}
