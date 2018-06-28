#ifndef NXOpen_ROUTING_ASSIGNPATHBUILDER_HXX_INCLUDED
#define NXOpen_ROUTING_ASSIGNPATHBUILDER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Routing_AssignPathBuilder.ja
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
#include <NXOpen/Routing_AssignPathBuilder.hxx>
#include <NXOpen/Routing_RouteObjectCollector.hxx>
#include <NXOpen/Routing_RunItem.hxx>
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
        class AssignPathBuilder;
    }
    class Builder;
    class NXObject;
    namespace Routing
    {
        class RouteObjectCollector;
    }
    namespace Routing
    {
        class _AssignPathBuilderBuilder;
        class AssignPathBuilderImpl;
        /**Assigns path to a broken routing run  <br> To create a new instance of this class, use @link Routing::RouteManager::CreateAssignPathBuilder Routing::RouteManager::CreateAssignPathBuilder@endlink  <br> 
         <br>  Created in NX8.5.0.  <br>  
        */
        class NXOPENCPP_ROUTINGEXPORT  AssignPathBuilder : public Builder
        {
            private: AssignPathBuilderImpl * m_assignpathbuilder_impl;
            private: friend class  _AssignPathBuilderBuilder;
            protected: AssignPathBuilder();
            public: ~AssignPathBuilder();
            /**Returns  the route object collector 
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: NXOpen::Routing::RouteObjectCollector * RouteObjectCollector
            (
            );
            /** Add the given object to the scoped object set
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : routing_base ("Routing Basic") */
            public: void AddToScopedObjectSet
            (
                NXOpen::NXObject * object /** object */ ,
                NXOpen::Routing::RunItem::Type runItemType /** runitemtype */ 
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