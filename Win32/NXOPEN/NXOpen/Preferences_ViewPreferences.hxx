#ifndef NXOpen_PREFERENCES_VIEWPREFERENCES_HXX_INCLUDED
#define NXOpen_PREFERENCES_VIEWPREFERENCES_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Preferences_ViewPreferences.ja
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
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/libnxopencpp_preferences_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Preferences
    {
        class ViewPreferences;
    }
    class Part;
    namespace Preferences
    {
        class BaseViewPreferences;
    }
    namespace Preferences
    {
        class DetailViewPreferences;
    }
    namespace Preferences
    {
        class FlatPatternViewPreferences;
    }
    namespace Preferences
    {
        class GeneralViewPreferences;
    }
    namespace Preferences
    {
        class HiddenLinesViewPreferences;
    }
    namespace Preferences
    {
        class InheritPmiPreferences;
    }
    namespace Preferences
    {
        class ProjectedViewPreferences;
    }
    namespace Preferences
    {
        class SectionViewPreferences;
    }
    namespace Preferences
    {
        class ShadingViewPreferences;
    }
    namespace Preferences
    {
        class ShipbuildingLinesViewPreferences;
    }
    namespace Preferences
    {
        class SmoothEdgesViewPreferences;
    }
    namespace Preferences
    {
        class ThreadsViewPreferences;
    }
    namespace Preferences
    {
        class TraceLinesViewPreferences;
    }
    namespace Preferences
    {
        class VirtualIntersectionsViewPreferences;
    }
    namespace Preferences
    {
        class VisibleLinesViewPreferences;
    }
    namespace Preferences
    {
        class ViewPreferencesImpl;
        /** Represents set of style applicable to drafting views.  <br> To obtain an instance of this class, refer to @link Part Part@endlink  <br> 
         <br>  Created in NX5.0.0.  <br>  
        */
        class NXOPENCPP_PREFERENCESEXPORT  ViewPreferences
        {
            private: ViewPreferencesImpl * m_viewpreferences_impl;
            private: NXOpen::Part* m_owner;
            /// \cond NX_NO_DOC 
            public: explicit ViewPreferences(NXOpen::Part *owner);


            /// \endcond 
            public: 
            /**Returns the tag of this object.  */
            tag_t Tag() const; 
            public: ~ViewPreferences();


            /** Returns object for doing View style settings applicable to General 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::GeneralViewPreferences *General();
            /** Returns object for doing View style settings applicable to BaseView 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::BaseViewPreferences *BaseView();
            /** Returns object for doing View Preferences settings applicable to Projected 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::ProjectedViewPreferences *Projected();
            /** Returns object for doing View Preferences settings applicable to Inherit Pmi 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::InheritPmiPreferences *InheritPmi();
            /** Returns object for doing View Preferences settings applicable to Detail 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::DetailViewPreferences *Detail();
            /** Returns object for doing View Preferences settings applicable to Section 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::SectionViewPreferences *Section();
            /** Returns object for doing View Preferences settings applicable to VirtualIntersections 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::VirtualIntersectionsViewPreferences *VirtualIntersections();
            /** Returns object for doing View Preferences settings applicable to SmoothEdges 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::SmoothEdgesViewPreferences *SmoothEdges();
            /** Returns object for doing View Preferences settings applicable to VisibleLines 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::VisibleLinesViewPreferences *VisibleLines();
            /** Returns object for doing View Preferences settings applicable to Threads 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::ThreadsViewPreferences *Threads();
            /** Returns object for doing View Preferences settings applicable to TraceLines 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::TraceLinesViewPreferences *TraceLines();
            /** Returns object for doing View Preferences settings applicable to HiddenLines 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::HiddenLinesViewPreferences *HiddenLines();
            /** Returns object for doing View Preferences settings applicable to Shading 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::ShadingViewPreferences *Shading();
            /** Returns object for doing View Preferences settings applicable to Flat Patterns 
             <br>  Created in NX3.0.0.  <br>  
            */
            public: NXOpen::Preferences::FlatPatternViewPreferences *FlatPattern();
            /** Returns object for doing View Preferences settings applicable to Shipbuilding Lines 
             <br>  Created in NX8.0.0.  <br>  
            */
            public: NXOpen::Preferences::ShipbuildingLinesViewPreferences *ShipbuildingLines();
        }; //lint !e1712 default constructor not defined for class  

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