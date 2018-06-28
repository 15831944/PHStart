#ifndef NXOpen_DIE_DIEBOOLEANBUILDER_HXX_INCLUDED
#define NXOpen_DIE_DIEBOOLEANBUILDER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Die_DieBooleanBuilder.ja
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
#include <NXOpen/Die_DieBooleanBuilder.hxx>
#include <NXOpen/GeometricUtilities_IComponentBuilder.hxx>
#include <NXOpen/SelectObjectList.hxx>
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/libnxopencpp_die_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Die
    {
        class DieBooleanBuilder;
    }
    namespace GeometricUtilities
    {
        class IComponentBuilder;
    }
    class SelectNXObjectList;
    namespace Die
    {
        class _DieBooleanBuilderBuilder;
        class DieBooleanBuilderImpl;
        /**
            Represents a @link Die::DieBooleanBuilder Die::DieBooleanBuilder@endlink . This class is a helper to other
            Die Design features that identify specific booleans in their dialogs, such as the Die Shoe
            feature. 
             <br> To create a new instance of this class, use @link Die::DieCollection::CreateDieBoolean Die::DieCollection::CreateDieBoolean@endlink  <br> 
         <br>  Created in NX6.0.0.  <br>  
        */
        class NXOPENCPP_DIEEXPORT  DieBooleanBuilder : public TaggedObject, public virtual GeometricUtilities::IComponentBuilder
        {
            /** boolean type to apply to the selected solids */
            public: enum BooleanType
            {
                BooleanTypeUnite/** Unite the solids to the application solid. */,
                BooleanTypeSubtract/** Subtract the solids from the application solid. */,
                BooleanTypeIntersect/** Intersect the solids with the application solid. */
            };

            private: DieBooleanBuilderImpl * m_diebooleanbuilder_impl;
            private: friend class  _DieBooleanBuilderBuilder;
            protected: DieBooleanBuilder();
            public: ~DieBooleanBuilder();
            /**Returns  the boolean option to apply to the list of selected solids 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Die::DieBooleanBuilder::BooleanType BooleanOptions
            (
            );
            /**Sets  the boolean option to apply to the list of selected solids 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : ug_die_design ("Die Design") */
            public: void SetBooleanOptions
            (
                NXOpen::Die::DieBooleanBuilder::BooleanType booleanOptions /** booleanoptions */ 
            );
            /**Returns  the bodies to be booleaned to the main feature body 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::SelectNXObjectList * SelectBodies
            (
            );
            /** Validate whether the inputs to the component are sufficient for 
                        commit to be called.  If the component is not in a state to commit
                        then an exception is thrown.  For example, if the component requires
                        you to set some property, this method will throw an exception if
                        you haven't set it.  This method throws a not-yet-implemented
                        NXException for some components.
                     @return  Was self validation successful 
             <br>  Created in NX3.0.1.  <br>  
             <br> License requirements : None */
            public: virtual bool Validate
            (
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