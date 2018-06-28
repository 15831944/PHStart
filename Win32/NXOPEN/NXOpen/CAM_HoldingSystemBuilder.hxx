#ifndef NXOpen_CAM_HOLDINGSYSTEMBUILDER_HXX_INCLUDED
#define NXOpen_CAM_HOLDINGSYSTEMBUILDER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     CAM_HoldingSystemBuilder.ja
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
#include <NXOpen/CAM_HoldingSystemBuilder.hxx>
#include <NXOpen/libnxopencpp_cam_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace CAM
    {
        class HoldingSystemBuilder;
    }
    class Builder;
    namespace CAM
    {
        class _HoldingSystemBuilderBuilder;
        class HoldingSystemBuilderImpl;
        /**
            Represents a @link CAM::HoldingSystemBuilder CAM::HoldingSystemBuilder@endlink 
             <br> This is an abstract class, and cannot be instantiated. <br> 
         <br>  Created in NX6.0.0.  <br>  
        */
        class NXOPENCPP_CAMEXPORT  HoldingSystemBuilder : public Builder
        {
            private: HoldingSystemBuilderImpl * m_holdingsystembuilder_impl;
            private: friend class  _HoldingSystemBuilderBuilder;
            protected: HoldingSystemBuilder();
            public: ~HoldingSystemBuilder();
            /**Returns  the holding system name 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXString Name
            (
            );
            /**Sets  the holding system name 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetName
            (
                const NXString & name /** name */ 
            );
            /**Sets  the holding system name 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            void SetName
            (
                const char * name /** name */ 
            );
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