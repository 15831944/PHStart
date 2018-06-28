#ifndef NXOpen_CAE_RESPONSESIMULATION_SENSOR_HXX_INCLUDED
#define NXOpen_CAE_RESPONSESIMULATION_SENSOR_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     CAE_ResponseSimulation_Sensor.ja
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
#include <NXOpen/CAE_ResponseSimulation_RSDisplayObject.hxx>
#include <NXOpen/DisplayableObject.hxx>
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
        namespace ResponseSimulation
        {
            class Sensor;
        }
    }
    namespace CAE
    {
        namespace ResponseSimulation
        {
            class RSDisplayObject;
        }
    }
    class DisplayableObject;
    namespace CAE
    {
        namespace ResponseSimulation
        {
            class _SensorBuilder;
            class SensorImpl;
            /** Represents a @link CAE::ResponseSimulation::Sensor CAE::ResponseSimulation::Sensor@endlink 
                  <br> To create or edit an instance of this class, use @link CAE::ResponseSimulation::SensorBuilder CAE::ResponseSimulation::SensorBuilder@endlink  <br> 
             <br>  Created in NX5.0.0.  <br>  
            */
            class NXOPENCPP_CAEEXPORT  Sensor : public DisplayableObject
            {
                private: SensorImpl * m_sensor_impl;
                private: friend class  _SensorBuilder;
                protected: Sensor();
                public: ~Sensor();
                /** Get display attribute of sensor  @return   
                 <br>  Created in NX6.0.0.  <br>  
                 <br> License requirements : nx_response_anlys ("NX Response Analysis") */
                public: NXOpen::CAE::ResponseSimulation::RSDisplayObject * GetDisplayAttribute
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