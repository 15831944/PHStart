#ifndef NXOpen_CAE_MODELCHECK_REVERSESHELLELEMENTNORMALBUILDER_HXX_INCLUDED
#define NXOpen_CAE_MODELCHECK_REVERSESHELLELEMENTNORMALBUILDER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     CAE_ModelCheck_ReverseShellElementNormalBuilder.ja
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
#include <NXOpen/Builder.hxx>
#include <NXOpen/CAE_FEElement.hxx>
#include <NXOpen/CAE_ModelCheck_ReverseShellElementNormalBuilder.hxx>
#include <NXOpen/SelectObjectList.hxx>
#include <NXOpen/libnxopencpp_cae_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace CAE
    {
        namespace ModelCheck
        {
            class ReverseShellElementNormalBuilder;
        }
    }
    class Builder;
    namespace CAE
    {
        class FEElement;
    }
    class SelectTaggedObjectList;
    namespace CAE
    {
        namespace ModelCheck
        {
            class _ReverseShellElementNormalBuilderBuilder;
            class ReverseShellElementNormalBuilderImpl;
            /**
                    Represents a @link CAE::ModelCheck::ReverseShellElementNormalBuilder CAE::ModelCheck::ReverseShellElementNormalBuilder@endlink  used to reverse normals
                    for specified shell elements. You can reverse shell element normals by using either @link Builder::Commit Builder::Commit@endlink 
                    or @link CAE::ModelCheck::ReverseShellElementNormalBuilder::ReverseNormals CAE::ModelCheck::ReverseShellElementNormalBuilder::ReverseNormals@endlink .
                    The difference between these two methods is @link Builder::Commit Builder::Commit@endlink  reverses the normals
                    and updates normal display, but it does not return the shell elements which were reversed
                    successfully. @link CAE::ModelCheck::ReverseShellElementNormalBuilder::ReverseNormals CAE::ModelCheck::ReverseShellElementNormalBuilder::ReverseNormals@endlink  
                    reverses normals and returns the shell elements which were reversed successfully.
                    Both of the methods are only available in fem context.
                     <br> There is no KF for this <br> 
             <br>  Created in NX8.5.0.  <br>  
            */
            class NXOPENCPP_CAEEXPORT  ReverseShellElementNormalBuilder : public Builder
            {
                private: ReverseShellElementNormalBuilderImpl * m_reverseshellelementnormalbuilder_impl;
                private: friend class  _ReverseShellElementNormalBuilderBuilder;
                protected: ReverseShellElementNormalBuilder();
                public: ~ReverseShellElementNormalBuilder();
                /**Returns  the selected objects to be checked. The objects must be @link CAE::Mesh CAE::Mesh@endlink  or
                            @link CAE::FEElement CAE::FEElement@endlink  
                 <br>  Created in NX8.5.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::SelectTaggedObjectList * SelectionList
                (
                );
                /** Display normals of @link CAE::ModelCheck::ReverseShellElementNormalBuilder::SelectionList CAE::ModelCheck::ReverseShellElementNormalBuilder::SelectionList@endlink  
                 <br>  Created in NX8.5.0.  <br>  
                 <br> License requirements : nx_masterfem ("Finite Element Modeling") OR nx_design_sim ("NX Design Simulation") */
                public: void DisplayNormals
                (
                );
                /** Reverses normals specified in @link CAE::ModelCheck::ReverseShellElementNormalBuilder::SelectionList CAE::ModelCheck::ReverseShellElementNormalBuilder::SelectionList@endlink 
                                and returns those elements whose normals were reversed successfully. This method will only reverse
                                the normals for shell elements in the current work fem part.
                             @return  
                 <br>  Created in NX8.5.0.  <br>  
                 <br> License requirements : nx_masterfem ("Finite Element Modeling") OR nx_design_sim ("NX Design Simulation") */
                public: std::vector<NXOpen::CAE::FEElement *> ReverseNormals
                (
                );
            };
        }
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