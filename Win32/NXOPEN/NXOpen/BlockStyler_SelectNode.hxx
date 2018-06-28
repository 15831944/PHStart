#ifndef NXOpen_BLOCKSTYLER_SELECTNODE_HXX_INCLUDED
#define NXOpen_BLOCKSTYLER_SELECTNODE_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     BlockStyler_SelectNode.ja
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
#include <NXOpen/BlockStyler_UIBlock.hxx>
#include <NXOpen/BlockStyler_SelectNode.hxx>
#include <NXOpen/libnxopenuicpp_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace BlockStyler
    {
        class SelectNode;
    }
    namespace BlockStyler
    {
        class UIBlock;
    }
    class TaggedObject;
    namespace BlockStyler
    {
        class _SelectNodeBuilder;
        class SelectNodeImpl;
        /** Represents a Select Node block
         <br>  Created in NX8.5.0.  <br>  
        */
        class NXOPENUICPPEXPORT  SelectNode : public BlockStyler::UIBlock
        {
            private: SelectNodeImpl * m_selectnode_impl;
            private: friend class  _SelectNodeBuilder;
            protected: SelectNode();
            public: ~SelectNode();
            /**Returns  the AutomaticProgression
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: bool AutomaticProgression
            (
            );
            /**Sets  the AutomaticProgression
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetAutomaticProgression
            (
                bool automaticProgression /** automaticprogression */ 
            );
            /**Returns  the Bitmap
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXString Bitmap
            (
            );
            /**Sets  the Bitmap
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetBitmap
            (
                const NXString & bitmapString /** bitmap string */ 
            );
            /**Sets  the Bitmap
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            void SetBitmap
            (
                const char * bitmapString /** bitmap string */ 
            );
            /**Returns  the Cue
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXString Cue
            (
            );
            /**Sets  the Cue
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetCue
            (
                const NXString & cue /** cue */ 
            );
            /**Sets  the Cue
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            void SetCue
            (
                const char * cue /** cue */ 
            );
            /** Gets the SelectedObjects @return Value to get from the property
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: std::vector<NXOpen::TaggedObject *> GetSelectedObjects
            (
            );
            /** Sets the SelectedObjects
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetSelectedObjects
            (
                const std::vector<NXOpen::TaggedObject *> & objectVector /**Value to set for the property*/
            );
            /**Returns  the SelectMode as string
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXString SelectModeAsString
            (
            );
            /**Sets  the SelectMode as string
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetSelectModeAsString
            (
                const NXString & enumString /** enumstring */ 
            );
            /**Sets  the SelectMode as string
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            void SetSelectModeAsString
            (
                const char * enumString /** enumstring */ 
            );
            /** Gets the SelectMode members @return Value to get from the property
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: std::vector<NXString> GetSelectModeMembers
            (
            );
            /**Returns  the StepStatus as string
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXString StepStatusAsString
            (
            );
            /**Sets  the StepStatus as string
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetStepStatusAsString
            (
                const NXString & enumString /** enumstring */ 
            );
            /**Sets  the StepStatus as string
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            void SetStepStatusAsString
            (
                const char * enumString /** enumstring */ 
            );
            /** Gets the StepStatus members @return Value to get from the property
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: std::vector<NXString> GetStepStatusMembers
            (
            );
            /**Returns  the Show Selection. If true,the graphical selection part of this block is shown.
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: bool ShowSelection
            (
            );
            /**Sets  the Show Selection. If true,the graphical selection part of this block is shown.
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetShowSelection
            (
                bool showSelection /** showselection */ 
            );
            /**Returns  the LabelString
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXString LabelString
            (
            );
            /**Sets  the LabelString
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetLabelString
            (
                const NXString & labelString /** labelstring */ 
            );
            /**Sets  the LabelString
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            void SetLabelString
            (
                const char * labelString /** labelstring */ 
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