#ifndef NXOpen_FEATURES_SHIPDESIGN_TRACELINESBUILDER_HXX_INCLUDED
#define NXOpen_FEATURES_SHIPDESIGN_TRACELINESBUILDER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Features_ShipDesign_TraceLinesBuilder.ja
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
#include <NXOpen/Expression.hxx>
#include <NXOpen/Features_FeatureBuilder.hxx>
#include <NXOpen/Features_ShipDesign_TraceLinesBuilder.hxx>
#include <NXOpen/ScCollector.hxx>
#include <NXOpen/Section.hxx>
#include <NXOpen/SelectObjectList.hxx>
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
        namespace ShipDesign
        {
            class TraceLinesBuilder;
        }
    }
    class Expression;
    namespace Features
    {
        class FeatureBuilder;
    }
    class ScCollector;
    class Section;
    class SelectDisplayableObjectList;
    namespace Features
    {
        namespace ShipDesign
        {
            class _TraceLinesBuilderBuilder;
            class TraceLinesBuilderImpl;
            /**
                    Represents a @link Features::ShipDesign::TraceLines Features::ShipDesign::TraceLines@endlink  builder
                     <br> To create a new instance of this class, use @link Features::ShipCollection::CreateTraceLinesBuilder Features::ShipCollection::CreateTraceLinesBuilder@endlink  <br> 
            Default values.
            <table border="1"> 
             
            <tr><th> 
            Property</th>  <th> 
            Value</th> </tr>
            <tr><td> 
             
            Associative </td> <td> 
             
            1 </td> </tr> 

            <tr><td> 
             
            CurveCount </td> <td> 
             
            1 </td> </tr> 

            <tr><td> 
             
            Offset.Value </td> <td> 
             
            0 (millimeters part), 0 (inches part) </td> </tr> 

            <tr><td> 
             
            OffsetCurveCount </td> <td> 
             
            1 </td> </tr> 

            <tr><td> 
             
            OffsetType </td> <td> 
             
            EqualSpacing </td> </tr> 

            </table>  

             <br>  Created in NX7.5.0.  <br>  
            */
            class NXOPENCPP_FEATURESEXPORT  TraceLinesBuilder : public Features::FeatureBuilder
            {
                /** Define the traceline creation method */
                public: enum TraceLineType
                {
                    TraceLineTypeEqualSpacing/** equal spacing */ ,
                    TraceLineTypeOffset/** offset */ 
                };

                private: TraceLinesBuilderImpl * m_tracelinesbuilder_impl;
                private: friend class  _TraceLinesBuilderBuilder;
                protected: TraceLinesBuilder();
                public: ~TraceLinesBuilder();
                /**Returns  the offset type 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Features::ShipDesign::TraceLinesBuilder::TraceLineType OffsetType
                (
                );
                /**Sets  the offset type 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : nx_ship_concept ("Ship Concept") OR nx_ship_basic ("Ship Basic Design") OR nx_ship_detail ("Ship Detail Design") */
                public: void SetOffsetType
                (
                    NXOpen::Features::ShipDesign::TraceLinesBuilder::TraceLineType offsetType /** offsettype */ 
                );
                /**Returns  the placement face 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::ScCollector * PlacementFace
                (
                );
                /**Returns  the reference curve 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Section * ReferenceCurve
                (
                );
                /**Returns  the direction
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: bool Direction
                (
                );
                /**Sets  the direction
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : nx_ship_concept ("Ship Concept") OR nx_ship_basic ("Ship Basic Design") OR nx_ship_detail ("Ship Detail Design") */
                public: void SetDirection
                (
                    bool direction /** direction */ 
                );
                /**Returns  the start curve 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Section * StartCurve
                (
                );
                /**Returns  the end curve 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Section * EndCurve
                (
                );
                /**Returns  the datum planes 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::SelectDisplayableObjectList * DatumPlanes
                (
                );
                /**Returns  the curve count 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: int CurveCount
                (
                );
                /**Sets  the curve count 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : nx_ship_concept ("Ship Concept") OR nx_ship_basic ("Ship Basic Design") OR nx_ship_detail ("Ship Detail Design") */
                public: void SetCurveCount
                (
                    int curveCount /** curvecount */ 
                );
                /**Returns  the offset curve count 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: int OffsetCurveCount
                (
                );
                /**Sets  the offset curve count 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : nx_ship_concept ("Ship Concept") OR nx_ship_basic ("Ship Basic Design") OR nx_ship_detail ("Ship Detail Design") */
                public: void SetOffsetCurveCount
                (
                    int offsetCurveCount /** offsetcurvecount */ 
                );
                /**Returns  the offset 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Expression * Offset
                (
                );
                /**Returns  the associative 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : None */
                public: bool Associative
                (
                );
                /**Sets  the associative 
                 <br>  Created in NX7.5.0.  <br>  
                 <br> License requirements : nx_ship_concept ("Ship Concept") OR nx_ship_basic ("Ship Basic Design") OR nx_ship_detail ("Ship Detail Design") */
                public: void SetAssociative
                (
                    bool associative /** associative */ 
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