#ifndef NXOpen_ROUTING_IAXISPORT_HXX_INCLUDED
#define NXOpen_ROUTING_IAXISPORT_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Routing_IAxisPort.ja
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
#include <NXOpen/Routing_IRoutePosition.hxx>
#include <NXOpen/ugmath.hxx>
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
        class IAxisPort;
    }
    class Axis;
    class DisplayableObject;
    class Expression;
    namespace Routing
    {
        class IRoutePosition;
    }
    namespace Routing
    {
        /** Interface class for all routing objects that specify a direction 
         <br>  Created in NX4.0.0.  <br>  
        */
        class NXOPENCPP_ROUTINGEXPORT  IAxisPort : public virtual Routing::IRoutePosition
        {
            public: virtual ~IAxisPort() {}
            /** Sets the align vector of Port 
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetAlignVector
            (
                const NXOpen::Vector3d & vector /** Vector direction in absolute co-ordinate system */
            ) = 0;
            /** Sets the rotation vector of Port 
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetRotationVector
            (
                const NXOpen::Vector3d & vector /** Vector direction in absolute co-ordinate system */
            ) = 0;
            /** Sets the object used to derive the rotation vector of Port 
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetRotationObject
            (
                NXOpen::DisplayableObject * rotationObject /** Object used to derive the rotation vector */
            ) = 0;
            /** Sets the forward extension value of a port, i.e. the minimum length that
                        a segment must remain straight coming out of a @link Port Port@endlink 
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetForwardExtension
            (
                double forwardExtension /** Port extension */
            ) = 0;
            /**Returns  the forward extension object of a port, i.e. an expression representing the minimum
                        length that a segment must remain straight coming out of a @link Port Port@endlink 
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual NXOpen::Expression * ForwardExtensionObject
            (
            ) = 0;
            /**Sets  the forward extension object of a port, i.e. an expression representing the minimum
                        length that a segment must remain straight coming out of a @link Port Port@endlink 
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetForwardExtensionObject
            (
                NXOpen::Expression * forwardExtension /** Forward Extension Expression */
            ) = 0;
            /** The engagment distance of a @link IAxisPort IAxisPort@endlink , i.e. the distance 
                        behind the port that another fitting or stock may engage
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetEngagement
            (
                double engagement /** Engagement distance */
            ) = 0;
            /**Returns  the engagement object of a port, i.e. an expression representing the
                        distance behind the port that another fitting or stock may engage
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual NXOpen::Expression * EngagementObject
            (
            ) = 0;
            /**Sets  the engagement object of a port, i.e. an expression representing the
                        distance behind the port that another fitting or stock may engage
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetEngagementObject
            (
                NXOpen::Expression * engagement /** Engagement Expression */
            ) = 0;
            /** Sets the cutback length of a port, i.e. the length along the wire from
                        the port where individual wires leave a bundle to attach to pins
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetCutbackLength
            (
                double cutbackLength /** Cutback Length */
            ) = 0;
            /**Returns  the cutback length object of a port, i.e. an expression representing the length
                        along the wire from the port where individual wires leave a bundle to attach to pins
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual NXOpen::Expression * CutbackLengthObject
            (
            ) = 0;
            /**Sets  the cutback length object of a port, i.e. an expression representing the length
                        along the wire from the port where individual wires leave a bundle to attach to pins
                      
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetCutbackLengthObject
            (
                NXOpen::Expression * cutbackLength /** Cutback Length Expression */
            ) = 0;
            /**Returns   the axis that defines the port
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual NXOpen::Axis * Axis
            (
            ) = 0;
            /**Sets   the axis that defines the port
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: virtual void SetAxis
            (
                NXOpen::Axis * axis /** axis */ 
            ) = 0;
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