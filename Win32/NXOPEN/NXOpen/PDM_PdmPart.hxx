#ifndef NXOpen_PDM_PDMPART_HXX_INCLUDED
#define NXOpen_PDM_PDMPART_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     PDM_PdmPart.ja
//
//  Generated by:
//     apiwrap
//
//  WARNING:
//    This file is automatically generated - do not edit by hand
//
#ifdef _MSC_VER
#pragma once
#endif

#include <NXOpen/NXDeprecation.hxx>
#include <vector>
#include <NXOpen/NXString.hxx>
#include <NXOpen/Callback.hxx>
#include <NXOpen/PDM_AlternateIdManager.hxx>
#include <NXOpen/PDM_DatabaseAttributeManager.hxx>
#include <NXOpen/PDM_OperationErrors.hxx>
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/libnxopencpp_pdm_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace PDM
    {
        class PdmPart;
    }
    class BasePart;
    namespace PDM
    {
        class AlternateIdManager;
    }
    namespace PDM
    {
        class DatabaseAttributeManager;
    }
    namespace PDM
    {
        class OperationErrors;
    }
    namespace PDM
    {
        class PdmPartImpl;
        /** This class serves as a gateway to part-specific tools for NX Manager mode.
             <br> To obtain an instance of this class, refer to @link BasePart BasePart@endlink  <br> 
         <br>  Created in NX4.0.0.  <br>  
        */
        class NXOPENCPP_PDMEXPORT  PdmPart
        {
             /** Reservation check-out input struct */
            public:
            struct  CheckoutInput
            {
                public: /** inputcomment */ NXString InputComment;
                public: /** inputchangeid */ NXString InputChangeId;
                public: /** True to allow remote check out, false otherwise */bool AllowRemote;
                public: /** True to perform explicit check out, false otherwise */bool ExplicitCheckOut;
                public: /** True to check out secondary dataset, false otherwise */bool IncludeSecondary;
                public: CheckoutInput() :
                    InputComment(),
                    InputChangeId(),
                    AllowRemote(),
                    ExplicitCheckOut(),
                    IncludeSecondary()
                {
                }
                /** Constructor for the CheckoutInput struct. */ 
                public: CheckoutInput(const NXString &inputCommentInitial /** inputcomment */ , 
                        const NXString &inputChangeIdInitial /** inputchangeid */ , 
                        bool allowRemoteInitial /** True to allow remote check out, false otherwise */, 
                        bool explicitCheckOutInitial /** True to perform explicit check out, false otherwise */, 
                        bool includeSecondaryInitial /** True to check out secondary dataset, false otherwise */) :
                    InputComment(inputCommentInitial),
                    InputChangeId(inputChangeIdInitial),
                    AllowRemote(allowRemoteInitial),
                    ExplicitCheckOut(explicitCheckOutInitial),
                    IncludeSecondary(includeSecondaryInitial)
                {
                }
            };

             
            public:
            struct  CheckinInput
            {
                public: /** True to allow remote check in, false otherwise */bool AllowRemote;
                public: /** True to perform explicit check in, false otherwise */bool ExplicitCheckIn;
                public: /** True to check out secondary dataset, false otherwise */bool IncludeSecondary;
                public: CheckinInput() :
                    AllowRemote(),
                    ExplicitCheckIn(),
                    IncludeSecondary()
                {
                }
                /** Constructor for the CheckinInput struct. */ 
                public: CheckinInput(bool allowRemoteInitial /** True to allow remote check in, false otherwise */, 
                        bool explicitCheckInInitial /** True to perform explicit check in, false otherwise */, 
                        bool includeSecondaryInitial /** True to check out secondary dataset, false otherwise */) :
                    AllowRemote(allowRemoteInitial),
                    ExplicitCheckIn(explicitCheckInInitial),
                    IncludeSecondary(includeSecondaryInitial)
                {
                }
            };

            private: PdmPartImpl * m_pdmpart_impl;
            private: NXOpen::BasePart* m_owner;
            /// \cond NX_NO_DOC 
            public: explicit PdmPart(NXOpen::BasePart *owner);


            /// \endcond 
            public: 
            /**Returns the tag of this object.  */
            tag_t Tag() const; 
            public: ~PdmPart();
            /** Create an instance of a @link PDM::AlternateIdManager PDM::AlternateIdManager@endlink 
                    class that will be used to create alternate ID information on the part.  @return  the new @link PDM::AlternateIdManager PDM::AlternateIdManager@endlink  instance 
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::PDM::AlternateIdManager * NewAlternateIdManager
            (
            );
            /** Create an instance of a @link PDM::DatabaseAttributeManager PDM::DatabaseAttributeManager@endlink 
                    class that will be used to modify database attributes of the part.  @return  the new @link PDM::DatabaseAttributeManager PDM::DatabaseAttributeManager@endlink  instance 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::PDM::DatabaseAttributeManager * NewDatabaseAttributeManager
            (
            );
            /** Checkout the part 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: void Checkout
            (
            );
            /** Assign a permanent name to the temporary part 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: void AssignPermanentName
            (
                const NXString & newFileName /** name of new part file to create   <br>  NOTE: The full Unicode character set is not supported for this parameter.  <br> */
            );
            /** Assign a permanent name to the temporary part 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            void AssignPermanentName
            (
                const char * newFileName /** name of new part file to create   <br>  NOTE: The full Unicode character set is not supported for this parameter.  <br> */
            );
            /** Set default folder for the part in which it is to be saved 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: void SetDefaultFolderForPart
            (
            );
            /** Given an array of parts, check out the parts.  @return  Errors encountered during the checkout 
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::PDM::OperationErrors * CheckoutParts
            (
                const std::vector<NXOpen::BasePart *> & partsToCheckOut /** Array of parts to check out  */,
                const NXOpen::PDM::PdmPart::CheckoutInput & checkOutInput /** Input which control the check out behavior */
            );
            /** Given an array of parts, check in the parts.  @return  Errors encountered during the checkin 
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::PDM::OperationErrors * CheckinParts
            (
                const std::vector<NXOpen::BasePart *> & partsToCheckIn /** Array of parts to check in  */,
                const NXOpen::PDM::PdmPart::CheckinInput & checkInInput /** Input which control the check in behavior */
            );
        }; //lint !e1712 default constructor not defined for class  

    }
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif
#ifdef __GNUC__
#ifndef NX_NO_GCC_DEPRECATION_WARNINGS
#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#endif
#endif

#undef EXPORTLIBRARY
#endif