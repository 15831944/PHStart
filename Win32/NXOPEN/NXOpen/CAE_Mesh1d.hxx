#ifndef NXOpen_CAE_MESH1D_HXX_INCLUDED
#define NXOpen_CAE_MESH1D_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     CAE_Mesh1d.ja
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
#include <NXOpen/CAE_Mesh.hxx>
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
        class Mesh1d;
    }
    namespace CAE
    {
        class Mesh;
    }
    namespace CAE
    {
        class _Mesh1dBuilder;
        class Mesh1dImpl;
        /** Represents 1d Mesh  <br> To create or edit an instance of this class, use @link CAE::Mesh1dBuilder CAE::Mesh1dBuilder@endlink  <br> 
         <br>  Created in NX6.0.0.  <br>  
        */
        class NXOPENCPP_CAEEXPORT  Mesh1d : public CAE::Mesh
        {
            private: Mesh1dImpl * m_mesh1d_impl;
            private: friend class  _Mesh1dBuilder;
            protected: Mesh1d();
            public: ~Mesh1d();
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