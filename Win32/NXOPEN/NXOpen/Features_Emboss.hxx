#ifndef NXOpen_FEATURES_EMBOSS_HXX_INCLUDED
#define NXOpen_FEATURES_EMBOSS_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Features_Emboss.ja
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
#include <NXOpen/libnxopencpp_features_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Features
    {
        class Emboss;
    }
    namespace Features
    {
        class BodyFeature;
    }
    namespace Features
    {
        class _EmbossBuilder;
        class EmbossImpl;
        /** Represents an emboss feature  <br> To create or edit an instance of this class, use @link Features::EmbossBuilder Features::EmbossBuilder@endlink  <br> 
         <br>  Created in NX4.0.0.  <br>  
        */
        class NXOPENCPP_FEATURESEXPORT  Emboss : public Features::BodyFeature
        {
            private: EmbossImpl * m_emboss_impl;
            private: friend class  _EmbossBuilder;
            protected: Emboss();
            public: ~Emboss();
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