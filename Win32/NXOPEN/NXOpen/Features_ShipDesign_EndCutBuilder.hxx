#ifndef NXOpen_FEATURES_SHIPDESIGN_ENDCUTBUILDER_HXX_INCLUDED
#define NXOpen_FEATURES_SHIPDESIGN_ENDCUTBUILDER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Features_ShipDesign_EndCutBuilder.ja
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
#include <NXOpen/Features_ShipDesign_EndCutBuilder.hxx>
#include <NXOpen/Features_ShipDesign_SteelFeatureSpreadsheetBuilder.hxx>
#include <NXOpen/SelectObject.hxx>
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
            class EndCutBuilder;
        }
    }
    class Expression;
    class Face;
    namespace Features
    {
        class FeatureBuilder;
    }
    namespace Features
    {
        namespace ShipDesign
        {
            class SteelFeatureSpreadsheetBuilder;
        }
    }
    class Plane;
    class SelectDisplayableObject;
    class SelectEdge;
    class SelectFaceList;
    namespace Features
    {
        namespace ShipDesign
        {
            class _EndCutBuilderBuilder;
            class EndCutBuilderImpl;
            /**
                Represents a @link Features::ShipDesign::EndCut Features::ShipDesign::EndCut@endlink  builder. 
                 <br> To create a new instance of this class, use @link Features::ShipCollection::CreateEndCutBuilder Features::ShipCollection::CreateEndCutBuilder@endlink  <br> 
            Default values.
            <table border="1"> 
             
            <tr><th> 
            Property</th>  <th> 
            Value</th> </tr>
            <tr><td> 
             
            DraftAngle.Value </td> <td> 
             
            0 </td> </tr> 

            <tr><td> 
             
            DraftOffset.Value </td> <td> 
             
            0 (millimeters part), 0 (inches part) </td> </tr> 

            <tr><td> 
             
            DraftType </td> <td> 
             
            Trim </td> </tr> 

            <tr><td> 
             
            LimitType </td> <td> 
             
            Value </td> </tr> 

            <tr><td> 
             
            Offset.Value </td> <td> 
             
            0 (millimeters part), 0 (inches part) </td> </tr> 

            <tr><td> 
             
            SelectionType </td> <td> 
             
            FacesWithAttributes </td> </tr> 

            <tr><td> 
             
            ShearAngle.Value </td> <td> 
             
            0 </td> </tr> 

            <tr><td> 
             
            TiltAngle.Value </td> <td> 
             
            0 </td> </tr> 

            </table>  

             <br>  Created in NX8.0.0.  <br>  
            */
            class NXOPENCPP_FEATURESEXPORT  EndCutBuilder : public Features::FeatureBuilder
            {
                /** This enum defines the Placement Face and Placement Edge Selection Type. */
                public: enum SelectionTypes
                {
                    SelectionTypesFacesWithAttributes/** If this Selection Type is set, just faces need to be specifed and placement edges will be inferred automatically. 
                                                                                           <br> 
                                                                                              All faces specified as placement faces must have valid attributes that identify it as a valid face for Endcuts.
                                                                                           <br>  */,
                    SelectionTypesFaceAndEdge/** If this Selection Type is set, then a single pair of a Face (Placement Face) and an edge(Placement Edge) needs to be specified. */
                };

                /** This enum defines the different ways users can trim the ends of a profile or a plate. */
                public: enum LimitTypes
                {
                    LimitTypesValue/** If this Limit Type is set, the values of Tilt Angle and Shear Angle expressions will be used.*/,
                    LimitTypesPlane/** If this Limit Type is set, a Plane needs to be specified and the Tilt and Shear angles will be inferred from the intersection of Datum Plane with the body on which EndCut will be applied. */,
                    LimitTypesNeatTrim/** If this Limit Type is set, a datum plane feature, a face or a profile/plate body needs to be selected and the endcut will be trimmed to the selected geometry. */
                };

                /** This enum defines the types of draft to be applied. */
                public: enum DraftTypes
                {
                    DraftTypesTrim/** If this Draft Type is set, the EndCut face will split and the left side face will be tapered.*/,
                    DraftTypesExtend/** If this Draft Type is set, the EndCut face will split and the right side face will be tapered.*/
                };

                private: EndCutBuilderImpl * m_endcutbuilder_impl;
                private: friend class  _EndCutBuilderBuilder;
                protected: EndCutBuilder();
                public: ~EndCutBuilder();
                /**Returns  the selection type. Users can provide a set of faces where the edge can be inferred automatically or specify a single pair of a Face and an edge(Placement Edge).
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Features::ShipDesign::EndCutBuilder::SelectionTypes SelectionType
                (
                );
                /**Sets  the selection type. Users can provide a set of faces where the edge can be inferred automatically or specify a single pair of a Face and an edge(Placement Edge).
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : nx_ship_detail ("Ship Detail Design") */
                public: void SetSelectionType
                (
                    NXOpen::Features::ShipDesign::EndCutBuilder::SelectionTypes selectionType /** selectiontype */ 
                );
                /**Returns  the select placement faces.
                             <br> 
                             If the Selection Type is @link Features::ShipDesign::EndCutBuilder::SelectionTypesFacesWithAttributes Features::ShipDesign::EndCutBuilder::SelectionTypesFacesWithAttributes@endlink  this list can contain multiple faces
                             and each face must be a valid endcut face, i.e. faces with SAW_SIZE and SAW_SIZE2 attributes whose value 
                             is same as the Perpendicular EndCut Name defined in the customer defaults. 
                             If the Selection Type is @link Features::ShipDesign::EndCutBuilder::SelectionTypesFaceAndEdge Features::ShipDesign::EndCutBuilder::SelectionTypesFaceAndEdge@endlink , this list must contain a single face.
                             Each face will result in a separate EndCut feature. If an existing EndCut feature is queried, it will
                             contain a single face in this list. 
                             <br> 
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::SelectFaceList * PlacementFaces
                (
                );
                /**Returns  the select placement edges.
                             <br> 
                            This input is only required when the Selection Type is @link Features::ShipDesign::EndCutBuilder::SelectionTypesFaceAndEdge Features::ShipDesign::EndCutBuilder::SelectionTypesFaceAndEdge@endlink . This edge must belong to the face
                            specified as Placement Face.
                             <br> 
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::SelectEdge * PlacementEdge
                (
                );
                /** Copy the parameters from the endcut face to this endcut. The input face must belong to an endcut feature
                            and should have all the attributes. All the builder parameters will be replaced with copies of parameters
                            from the input face. If any change is made after this call, the copied parameter value will be overwritten.
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : nx_ship_detail ("Ship Detail Design") */
                public: void InheritParametersFromEndcutFace
                (
                    NXOpen::Face * endcutFace /** endcutface */ 
                );
                /**Returns  the limit type. The Tilt and Shear angles can be supplied as expressions or can be inferred from a Plane. Users can also limit the ends using a face or a body.
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Features::ShipDesign::EndCutBuilder::LimitTypes LimitType
                (
                );
                /**Sets  the limit type. The Tilt and Shear angles can be supplied as expressions or can be inferred from a Plane. Users can also limit the ends using a face or a body.
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : nx_ship_detail ("Ship Detail Design") */
                public: void SetLimitType
                (
                    NXOpen::Features::ShipDesign::EndCutBuilder::LimitTypes limitType /** limittype */ 
                );
                /**Returns  the plane. If the Limit Type is @link Features::ShipDesign::EndCutBuilder::LimitTypesPlane Features::ShipDesign::EndCutBuilder::LimitTypesPlane@endlink , the Tilt and Shear angle will be inferred automatically from this plane. 
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Plane * Plane
                (
                );
                /**Sets  the plane. If the Limit Type is @link Features::ShipDesign::EndCutBuilder::LimitTypesPlane Features::ShipDesign::EndCutBuilder::LimitTypesPlane@endlink , the Tilt and Shear angle will be inferred automatically from this plane. 
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : nx_ship_detail ("Ship Detail Design") */
                public: void SetPlane
                (
                    NXOpen::Plane * plane /** plane */ 
                );
                /**Returns  the tilt angle 
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Expression * TiltAngle
                (
                );
                /**Returns  the shear angle. The Shear Angle is always applied after the Tilt Angle. 
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Expression * ShearAngle
                (
                );
                /**Returns  the offset. The Offset is always applied after the Tilt and Shear Angles. 
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Expression * Offset
                (
                );
                /**Returns  the web sketch data. 
                             <br> 
                            Users can specify the EndCut using either a single or two sketches. The sketch type and its parameters
                            are controlled by the @link Features::ShipDesign::SteelFeatureSpreadsheetBuilder Features::ShipDesign::SteelFeatureSpreadsheetBuilder@endlink .
                             <br> 
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Features::ShipDesign::SteelFeatureSpreadsheetBuilder * WebSketchData
                (
                );
                /**Returns  the toe sketch data.
                             <br> 
                            Users can specify the EndCut using either a single or two sketches. The sketch type and its parameters
                            are controlled by the @link Features::ShipDesign::SteelFeatureSpreadsheetBuilder Features::ShipDesign::SteelFeatureSpreadsheetBuilder@endlink .
                             <br> 
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Features::ShipDesign::SteelFeatureSpreadsheetBuilder * ToeSketchData
                (
                );
                /**Returns  the draft type. A partial taper can be applied to the end face of a Stiffener. The end face will be split and the
                            Draft Type defines which split face is tapered. 
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Features::ShipDesign::EndCutBuilder::DraftTypes DraftType
                (
                );
                /**Sets  the draft type. A partial taper can be applied to the end face of a Stiffener. The end face will be split and the
                            Draft Type defines which split face is tapered. 
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : nx_ship_detail ("Ship Detail Design") */
                public: void SetDraftType
                (
                    NXOpen::Features::ShipDesign::EndCutBuilder::DraftTypes draftType /** drafttype */ 
                );
                /**Returns  the draft angle 
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Expression * DraftAngle
                (
                );
                /**Returns  the draft offset. This is the distance from the end of the Placement Edge where the
                            Stiffener end face will be split.
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::Expression * DraftOffset
                (
                );
                /**Returns  the limit geometry. 
                                 <br> 
                                    This input is required when the Limit Type is @link Features::ShipDesign::EndCutBuilder::LimitTypesNeatTrim Features::ShipDesign::EndCutBuilder::LimitTypesNeatTrim@endlink .
                                    Valid types are Plane, Face or a Body. If a Body is specified, it must have at least one face with MK_TYPE=MOLDINGLINE and one face with MK_TYPE=OPPOSINGMOLDINGLINE attributes.
                                 <br> 
                        
                 <br>  Created in NX8.0.0.  <br>  
                 <br> License requirements : None */
                public: NXOpen::SelectDisplayableObject * LimitGeometry
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