#ifndef NXOpen_CAM_TURNCUTPARAMETERS_HXX_INCLUDED
#define NXOpen_CAM_TURNCUTPARAMETERS_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     CAM_TurnCutParameters.ja
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
#include <NXOpen/CAM_CutParameters.hxx>
#include <NXOpen/CAM_CutParametersEnum.hxx>
#include <NXOpen/CAM_TurnCutParameters.hxx>
#include <NXOpen/libnxopencpp_cam_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace CAM
    {
        class TurnCutParameters;
    }
    namespace CAM
    {
        class ChipControl;
    }
    namespace CAM
    {
        class ContourAngle;
    }
    namespace CAM
    {
        class CutDwell;
    }
    namespace CAM
    {
        class CutParameters;
    }
    namespace CAM
    {
        class FacesSequence;
    }
    namespace CAM
    {
        class FinishDwell;
    }
    namespace CAM
    {
        class InitialProfilePlunge;
    }
    namespace CAM
    {
        class MinCutDepth;
    }
    namespace CAM
    {
        class MinCutLength;
    }
    namespace CAM
    {
        class MultiRamp;
    }
    namespace CAM
    {
        class ProfileStrategy;
    }
    namespace CAM
    {
        class RampingMode;
    }
    namespace CAM
    {
        class ReliefCut;
    }
    namespace CAM
    {
        class ReliefPlunge;
    }
    namespace CAM
    {
        class SpringPasses;
    }
    namespace CAM
    {
        class StepoverBuilder;
    }
    namespace CAM
    {
        class StopPosition;
    }
    namespace CAM
    {
        class TurnConcaveCornerControl;
    }
    namespace CAM
    {
        class TurnCornerControl;
    }
    namespace CAM
    {
        class TurnCutterClearance;
    }
    namespace CAM
    {
        class TurnDirection;
    }
    namespace CAM
    {
        class TurnOverlap;
    }
    namespace CAM
    {
        class TurnRoughFinishTestCut;
    }
    namespace CAM
    {
        class TurnStock;
    }
    namespace CAM
    {
        class _TurnCutParametersBuilder;
        class TurnCutParametersImpl;
        /**
            Represents a @link CAM::TurnCutParameters CAM::TurnCutParameters@endlink 
            
         <br>  Created in NX6.0.0.  <br>  
        */
        class NXOPENCPP_CAMEXPORT  TurnCutParameters : public CAM::CutParameters
        {
            private: TurnCutParametersImpl * m_turncutparameters_impl;
            private: friend class  _TurnCutParametersBuilder;
            protected: TurnCutParameters();
            public: ~TurnCutParameters();
            /**Returns  the Relief Plunge 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::ReliefPlunge * ReliefPlunge
            (
            );
            /**Returns  the Cut Dwell 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::CutDwell * CutDwell
            (
            );
            /**Returns  the undercut 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: bool AllowUndercut
            (
            );
            /**Sets  the undercut 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetAllowUndercut
            (
                bool undercut /** the undercut */
            );
            /**Returns  the cut connection 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::CutParametersCutConnectionTypes CutConnection
            (
            );
            /**Sets  the cut connection 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetCutConnection
            (
                NXOpen::CAM::CutParametersCutConnectionTypes cutConnectionValue /** the cut connection mode */
            );
            /**Returns  the cleanup control 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::CutParametersCleanupControlTypes CleanupControl
            (
            );
            /**Sets  the cleanup control 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetCleanupControl
            (
                NXOpen::CAM::CutParametersCleanupControlTypes cleanupControlValue /** the cleanup control mode */
            );
            /**Returns  the min cut depth 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::MinCutDepth * MinCutDepth
            (
            );
            /**Returns  the min cut length 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::MinCutLength * MinCutLength
            (
            );
            /**Returns  the chip control 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::ChipControl * ChipControl
            (
            );
            /**Returns  the part stock 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::TurnStock * TurnPartStock
            (
            );
            /**Returns  the profile stock 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::TurnStock * TurnProfileStock
            (
            );
            /**Returns  the blank stock 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::TurnStock * TurnBlankStock
            (
            );
            /**Returns  the normal corners 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: NXOpen::CAM::TurnCornerControl * NormalCorner
            (
            );
            /**Returns  the corner shallow 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: NXOpen::CAM::TurnCornerControl * ShallowCorner
            (
            );
            /**Returns  the corner concave 
             <br>  Created in NX6.0.2.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: NXOpen::CAM::TurnConcaveCornerControl * ConcaveCornerControl
            (
            );
            /**Returns  the contour face angle 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::ContourAngle * ContourFaceAngle
            (
            );
            /**Returns  the contour diameter angle 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::ContourAngle * ContourDiameterAngle
            (
            );
            /**Returns  the contour steep angle 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::ContourAngle * ContourSteepAngle
            (
            );
            /**Returns  the contour level angle 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::ContourAngle * ContourLevelAngle
            (
            );
            /**Returns  the ramping mode 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::RampingMode * RampingMode
            (
            );
            /**Returns  the multi ramp 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::MultiRamp * MultiRamp
            (
            );
            /**Returns  the omit last pass 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: bool OmitLastPass
            (
            );
            /**Sets  the omit last pass 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetOmitLastPass
            (
                bool omitLastPass /** the omit last pass */
            );
            /**Returns  the additional profiling 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: bool AdditionalProfiling
            (
            );
            /**Sets  the additional profiling 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetAdditionalProfiling
            (
                bool profilingValue /** the additional profiling */
            );
            /**Returns  the profile cut regions 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::CutParametersProfileCutRegionsTypes ProfileCutRegions
            (
            );
            /**Sets  the profile cut regions 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetProfileCutRegions
            (
                NXOpen::CAM::CutParametersProfileCutRegionsTypes profileCutRegionsMode /** the profile cut regions mode */
            );
            /**Returns  the cut strategy 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::ProfileStrategy * ProfileStrategy
            (
            );
            /**Returns  the direction 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::TurnDirection * ProfileDirection
            (
            );
            /**Returns  the fillets mode 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::CutParametersFilletsTypes CutFillets
            (
            );
            /**Sets  the fillets mode 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetCutFillets
            (
                NXOpen::CAM::CutParametersFilletsTypes filletsMode /** the fillets mode */
            );
            /**Returns  the stop position 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::StopPosition * StopPosition
            (
            );
            /**Returns  the multi passes 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::StepoverBuilder * MultiPasses
            (
            );
            /**Returns  the finish passes 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::CutParametersFinishPassesTypes FinishPasses
            (
            );
            /**Sets  the finish passes 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetFinishPasses
            (
                NXOpen::CAM::CutParametersFinishPassesTypes finishPasses /** the finish passes */
            );
            /**Returns  the spring passes 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::SpringPasses * SpringPasses
            (
            );
            /**Returns  the overlap 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::TurnOverlap * TurnOverlap
            (
            );
            /**Returns  the finish dwell 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::FinishDwell * FinishDwell
            (
            );
            /**Returns  the Faces Sequence 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::FacesSequence * FacesSequence
            (
            );
            /**Returns  the cutter clearance angles 
             <br>  Created in NX6.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::TurnCutterClearance * TurnCutterClearance
            (
            );
            /**Returns  the relief cut 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::ReliefCut * ReliefCut
            (
            );
            /**Returns  the initial profile plunge 
             <br>  Created in NX7.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::InitialProfilePlunge * InitialProfilePlunge
            (
            );
            /**Returns  the Test Cut 
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::TurnRoughFinishTestCut * TestCut
            (
            );
            /**Returns  the Secondary Test Cut 
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::TurnRoughFinishTestCut * SecondaryTestCut
            (
            );
            /**Returns  the Corner Start Extension 
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::CAM::CutParametersExtendAtStartMode ExtendAtStart
            (
            );
            /**Sets  the Corner Start Extension 
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : cam_base ("CAM BASE") */
            public: void SetExtendAtStart
            (
                NXOpen::CAM::CutParametersExtendAtStartMode mode /** the extend at start mode*/
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