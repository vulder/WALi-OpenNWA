#ifndef wali_VISITABLE_GUARD
#define wali_VISITABLE_GUARD 1

/*!
 * @author Nick Kidd
 */

#include "wali/Common.hpp"

namespace wali
{
    namespace witness
    {
        class Visitor;

        class Visitable
        {
            public:
                virtual ~Visitable() {}

                virtual void accept( Visitor& v ) = 0;
        };

    } // namespace witness

} // namespace wali

#endif  // wali_VISITABLE_GUARD

/* Yo, Emacs!
   ;;; Local Variables: ***
   ;;; tab-width: 4 ***
   ;;; End: ***
 */
