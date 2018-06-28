#ifndef NXOpen_TOOLING_SPLITSOLIDBUILDER_HXX_INCLUDED
#define NXOpen_TOOLING_SPLITSOLIDBUILDER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Tooling_SplitSolidBuilder.ja
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
#include <NXOpen/GeometricUtilities_SurfaceRangeBuilder.hxx>
#include <NXOpen/SelectObject.hxx>
#include <NXOpen/Tooling_SplitSolidBuilder.hxx>
#include <NXOpen/libnxopencpp_tooling_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Tooling
    {
        class SplitSolidBuilder;
    }
    class Builder;
    namespace GeometricUtilities
    {
        class SurfaceRangeBuilder;
    }
    class Plane;
    class SelectBody;
    class SelectNXObject;
    namespace Tooling
    {
        class _SplitSolidBuilderBuilder;
        class SplitSolidBuilderImpl;
        /** Represents a builder to be used to split a solid with geometry tools.  <br> To create a new instance of this class, use @link Tooling::SplitSolidCollection::CreateSplitSolidBuilder Tooling::SplitSolidCollection::CreateSplitSolidBuilder@endlink  <br> 
        Default values.
        <table border="1"> 
         
        <tr><th> 
        Property</th>  <th> 
        Value</th> </tr>
        <tr><td> 
         
        IsEnlarge </td> <td> 
         
        0 </td> </tr> 

        <tr><td> 
         
        SurfaceRange.AnchorPosition </td> <td> 
         
        Vertex1 </td> </tr> 

        <tr><td> 
         
        ToolOption </td> <td> 
         
        ExistingObject </td> </tr> 

        </table>  

         <br>  Created in NX7.5.0.  <br>  
        */
        class NXOPENCPP_TOOLINGEXPORT  SplitSolidBuilder : public Builder
        {
            /** the split operation type: split, trim. */
            public: enum OperationType
            {
                OperationTypeSplit/** split option */,
                OperationTypeTrim/** trim option */
            };

            /** the split tool selection type: Existing Object, New Plane. */
            public: enum ToolObjectOption
            {
                ToolObjectOptionExistingObject/** Existing Object option */,
                ToolObjectOptionNewPlane/** New Plane option */
            };

            private: SplitSolidBuilderImpl * m_splitsolidbuilder_impl;
            private: friend class  _SplitSolidBuilderBuilder;
            protected: SplitSolidBuilder();
            public: ~SplitSolidBuilder();
            /**Returns  the tool object selection option 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Tooling::SplitSolidBuilder::ToolObjectOption ToolOption
            (
            );
            /**Sets  the tool object selection option 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: void SetToolOption
            (
                NXOpen::Tooling::SplitSolidBuilder::ToolObjectOption toolOption /** tooloption */ 
            );
            /**Returns  the target body to be split. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::SelectBody * SplitTarget
            (
            );
            /**Returns  the tool object to split the target body. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::SelectNXObject * SplitObject
            (
            );
            /**Returns  the plane to be a split tool. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Plane * SplitPlane
            (
            );
            /**Sets  the plane to be a split tool. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: void SetSplitPlane
            (
                NXOpen::Plane * splitPlane /** splitplane */ 
            );
            /**Returns  the option to enlarge a split tool or not, the tool should be a face. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: bool IsEnlarge
            (
            );
            /**Sets  the option to enlarge a split tool or not, the tool should be a face. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: void SetEnlarge
            (
                bool isEnlarge /** isenlarge */ 
            );
            /**Returns  the option to reverse the trim direction or not. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: bool ReverseTrimDirection
            (
            );
            /**Sets  the option to reverse the trim direction or not. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: void SetReverseTrimDirection
            (
                bool reverseTrimDirection /** reversetrimdirection */ 
            );
            /**Returns  the utility to get enlarged parameters. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::GeometricUtilities::SurfaceRangeBuilder * SurfaceRange
            (
            );
            /**Returns  the operation type to do split body or trim body. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Tooling::SplitSolidBuilder::OperationType Type
            (
            );
            /**Sets  the operation type to do split body or trim body. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: void SetType
            (
                NXOpen::Tooling::SplitSolidBuilder::OperationType splitOrTrim /** splitortrim */ 
            );
            /** Keep enlarged surface data to create enlarged surface. Four values passed in represent enlarged parameters 
                        in U+, U-, V+ and V-. 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: void SetEnlargedSurfaceData
            (
                const std::vector<double> & enlargedSurfaceData /** array of u and v range values */
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