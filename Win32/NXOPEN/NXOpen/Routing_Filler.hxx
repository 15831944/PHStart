#ifndef NXOpen_ROUTING_FILLER_HXX_INCLUDED
#define NXOpen_ROUTING_FILLER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Routing_Filler.ja
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
#include <NXOpen/Routing_Stock.hxx>
#include <NXOpen/libnxopencpp_routing_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Routing
    {
        class Filler;
    }
    namespace Routing
    {
        class Stock;
    }
    namespace Routing
    {
        class _FillerBuilder;
        class FillerImpl;
        /** Represents a Filler 
         <br>  Created in NX4.0.0.  <br>  
        */
        class NXOPENCPP_ROUTINGEXPORT  Filler : public Routing::Stock
        {
            private: FillerImpl * m_filler_impl;
            private: friend class  _FillerBuilder;
            protected: Filler();
            public: ~Filler();
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