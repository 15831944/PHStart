#ifndef NXOpen_PDM_LOGICALOBJECT_HXX_INCLUDED
#define NXOpen_PDM_LOGICALOBJECT_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     PDM_LogicalObject.ja
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
#include <NXOpen/NXObject.hxx>
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
        class LogicalObject;
    }
    class NXObject;
    namespace PDM
    {
        class _LogicalObjectBuilder;
        class LogicalObjectImpl;
        /**
                Represents the class that contains database business logic or pre-creation information for the objects.
             <br> Instances of this class can be accessed through various application specific builders <br> 
         <br>  Created in NX8.5.0.  <br>  
        */
        class NXOPENCPP_PDMEXPORT  LogicalObject : public NXObject
        {
            private: LogicalObjectImpl * m_logicalobject_impl;
            private: friend class  _LogicalObjectBuilder;
            protected: LogicalObject();
            public: ~LogicalObject();
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