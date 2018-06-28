#ifndef NXOpen_WELD_WELDJOINT_HXX_INCLUDED
#define NXOpen_WELD_WELDJOINT_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Weld_WeldJoint.ja
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
#include <NXOpen/Features_BodyFeature.hxx>
#include <NXOpen/libnxopencpp_weld_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Weld
    {
        class WeldJoint;
    }
    namespace Features
    {
        class BodyFeature;
    }
    namespace Weld
    {
        class _WeldJointBuilder;
        class WeldJointImpl;
        /** Represents a weld joint feature  <br> To create or edit an instance of this class, use @link Weld::WeldJointBuilder Weld::WeldJointBuilder@endlink  <br> 
         <br>  Created in NX8.0.0.  <br>  
        */
        class NXOPENCPP_WELDEXPORT  WeldJoint : public Features::BodyFeature
        {
            private: WeldJointImpl * m_weldjoint_impl;
            private: friend class  _WeldJointBuilder;
            protected: WeldJoint();
            public: ~WeldJoint();
        };
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