#ifndef NXOpen_CAE_CAEWELDCONNECTIONBUILDER_HXX_INCLUDED
#define NXOpen_CAE_CAEWELDCONNECTIONBUILDER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     CAE_CAEWeldConnectionBuilder.ja
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
#include <NXOpen/CAE_CAEWeldConnectionBuilder.hxx>
#include <NXOpen/CAE_ElementTypeBuilder.hxx>
#include <NXOpen/Expression.hxx>
#include <NXOpen/SelectObjectList.hxx>
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
        class CAEWeldConnectionBuilder;
    }
    class Builder;
    namespace CAE
    {
        class CAEWeldConnection;
    }
    namespace CAE
    {
        class ElementTypeBuilder;
    }
    class Expression;
    class SelectTaggedObjectList;
    namespace CAE
    {
        class _CAEWeldConnectionBuilderBuilder;
        class CAEWeldConnectionBuilderImpl;
        /**
            Builder for creating 1D Weld Connection
             <br> To create a new instance of this class, use @link CAE::CAEConnectionCollection::CreateWeldConnectionBuilder CAE::CAEConnectionCollection::CreateWeldConnectionBuilder@endlink  <br> 
         <br>  Created in NX6.0.0.  <br>  
        */
        class NXOPENCPP_CAEEXPORT  CAEWeldConnectionBuilder : public Builder
        {
            /** the type of weld connection to be created */
            public: enum WeldTypeEnum
            {
                WeldTypeEnumPointToPointDirect/** It's a point to point direct weldconnection,mesh points are created during weld connection*/,
                WeldTypeEnumPointToPointIndirect/** It's a point to point in-direct weldconnection,RBE3 elements are created during weld connection */,
                WeldTypeEnumPointToPoint3dWeld/** It's a point to point in-direct weldconnection,3D elements are created during weld connection */
            };

            /** */
            public: enum MeshDensityTypeEnum
            {
                MeshDensityTypeEnumSize/** Size of the each element on the hard object */,
                MeshDensityTypeEnumNumber/** Number of elements on the hard object */
            };

            private: CAEWeldConnectionBuilderImpl * m_caeweldconnectionbuilder_impl;
            private: friend class  _CAEWeldConnectionBuilderBuilder;
            protected: CAEWeldConnectionBuilder();
            public: ~CAEWeldConnectionBuilder();
            /**Returns  the weld connection type 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAE::CAEWeldConnectionBuilder::WeldTypeEnum WeldType
            (
            );
            /**Sets  the weld connection type 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : nx_masterfem ("Finite Element Modeling") */
            public: void SetWeldType
            (
                NXOpen::CAE::CAEWeldConnectionBuilder::WeldTypeEnum weldType /** weldtype */ 
            );
            /**Returns  the hard obj selection 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::SelectTaggedObjectList * HardObjSelection
            (
            );
            /**Returns  the top face selection(s) 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::SelectTaggedObjectList * TopFaceSelection
            (
            );
            /**Returns  the bottom face selection(s) 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::SelectTaggedObjectList * BottomFaceSelection
            (
            );
            /**Returns  the mesh density type 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAE::CAEWeldConnectionBuilder::MeshDensityTypeEnum MeshDensityType
            (
            );
            /**Sets  the mesh density type 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : nx_masterfem ("Finite Element Modeling") */
            public: void SetMeshDensityType
            (
                NXOpen::CAE::CAEWeldConnectionBuilder::MeshDensityTypeEnum meshDensityType /** meshdensitytype */ 
            );
            /**Returns  the mesh density value 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Expression * MeshDensityValue
            (
            );
            /**Returns  the merge node tol 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Expression * MergeNodeTol
            (
            );
            /**Returns  the element type to be created
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAE::ElementTypeBuilder * ElementType
            (
            );
            /** Commits the weld connection  @return  
             <br>  @deprecated Deprecated in NX7.5.1.  Use @link Builder::JA_BUILDER_commit Builder::JA_BUILDER_commit@endlink  instead. <br>  

             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : nx_masterfem ("Finite Element Modeling") */
            public:  NX_DEPRECATED("Deprecated in NX7.5.1.  Use Builder::JA_BUILDER_commit instead.") NXOpen::CAE::CAEWeldConnection * CommitWeldconnection
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