#ifndef wali_wfa_WEIGHT_MAKER_GUARD
#define wali_wfa_WEIGHT_MAKER_GUARD 1

/*!
 * @author Nick Kidd
 */

#include "wali/Common.hpp"
#include "wali/SemElem.hpp"
#include "wali/wpds/ewpds/MergeFunction.hpp"

namespace wali
{

    namespace wfa
    {
        /*!
         * @class WeightMaker
         *
         * This class defines the interface for joining the weights
         * on WFA transitions during WFA intersection.
         *
         * @see wali::sem_elem_t
         * @see wali::wfa::WFA
         */
        class WeightMaker
        {
            public:
                virtual ~WeightMaker() {}
                virtual sem_elem_t make_weight( sem_elem_t lhs, sem_elem_t rhs ) = 0;
                virtual sem_elem_t make_weight( sem_elem_t lhsBeforeCall, 
                                                sem_elem_t lhsAfterCall, 
                                                wali::wpds::ewpds::merge_fn_t lhsmf, 
                                                sem_elem_t rhs);
        }; // WeightMaker

        /*!
         * @class KeepLeft
         *
         * This class joins the weights by ignoring the second parameter
         * (rhs).
         *
         * @see wali::wfa::WeightMaker
         * @see wali::sem_elem_t
         */
        class KeepLeft : public WeightMaker
        {
            public:
                KeepLeft() {}
                virtual ~KeepLeft() {}
                virtual sem_elem_t make_weight( sem_elem_t lhs, sem_elem_t rhs );

        }; // KeepLeft

        /*!
         * @class KeepRight
         *
         * This class joins the weights by ignoring the second parameter
         * (rhs).
         *
         * @see wali::wfa::WeightMaker
         * @see wali::sem_elem_t
         */
        class KeepRight : public WeightMaker
        {
            public:
                KeepRight() {}
                virtual ~KeepRight() {}
                virtual sem_elem_t make_weight( sem_elem_t lhs, sem_elem_t rhs );

        }; // KeepRight

        /*!
         * @class KeepBoth
         *
         * This class joins the weights by pairing them.
         *
         * @see wali::wfa::WeightMaker
         * @see wali::sem_elem_t
         * @see wali::SemElemPair
         */
        class KeepBoth : public WeightMaker
        {
            public:
                KeepBoth() {}
                virtual ~KeepBoth() {}
                virtual sem_elem_t make_weight( sem_elem_t lhs, sem_elem_t rhs );

        }; // KeepBoth

    } // namespace wfa

} // namespace wfa

#endif  // wali_wfa_WEIGHT_MAKER_GUARD

/* Yo, Emacs!
   ;;; Local Variables: ***
   ;;; tab-width: 4 ***
   ;;; End: ***
 */
