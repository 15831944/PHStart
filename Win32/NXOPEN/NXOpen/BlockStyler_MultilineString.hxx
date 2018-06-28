#ifndef NXOpen_BLOCKSTYLER_MULTILINESTRING_HXX_INCLUDED
#define NXOpen_BLOCKSTYLER_MULTILINESTRING_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     BlockStyler_MultilineString.ja
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
#include <NXOpen/BlockStyler_MultilineString.hxx>
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
        class MultilineString;
    }
    namespace BlockStyler
    {
        class UIBlock;
    }
    namespace BlockStyler
    {
        class _MultilineStringBuilder;
        class MultilineStringImpl;
        /** Represents a Multiline String block 
         <br>  Created in NX6.0.0.  <br>  
        */
        class NXOPENUICPPEXPORT  MultilineString : public BlockStyler::UIBlock
        {
            private: MultilineStringImpl * m_multilinestring_impl;
            private: friend class  _MultilineStringBuilder;
            protected: MultilineString();
            public: ~MultilineString();
            /**Returns  the Height
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: int Height
            (
            );
            /**Sets  the Height
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetHeight
            (
                int height /** height */ 
            );
            /**Returns  the Localize. If true, the Label is translated to current locale language
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: bool Localize
            (
            );
            /**Sets  the Localize. If true, the Label is translated to current locale language
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetLocalize
            (
                bool localize /** localize */ 
            );
            /**Returns  the MaximumCharactersAccepted
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: int MaximumCharactersAccepted
            (
            );
            /**Sets  the MaximumCharactersAccepted
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetMaximumCharactersAccepted
            (
                int maxChar /** max char */ 
            );
            /**Returns  the MaximumHeight
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: int MaximumHeight
            (
            );
            /**Sets  the MaximumHeight
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetMaximumHeight
            (
                int maxHeight /** max height */ 
            );
            /**Returns  the MinimumHeight
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: int MinimumHeight
            (
            );
            /**Sets  the MinimumHeight
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetMinimumHeight
            (
                int minHeight /** min height */ 
            );
            /**Returns  the ResizeHeightWithDialog. If true, height of block will dynamically change when the dialog is resized.
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: bool ResizeHeightWithDialog
            (
            );
            /**Sets  the ResizeHeightWithDialog. If true, height of block will dynamically change when the dialog is resized.
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetResizeHeightWithDialog
            (
                bool resize /** resize */ 
            );
            /**Returns  the RetainValue
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: bool RetainValue
            (
            );
            /**Sets  the RetainValue
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetRetainValue
            (
                bool retain /** retain */ 
            );
            /** Gets the Value @return  
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: std::vector<NXString> GetValue
            (
            );
            /** Sets the Value
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetValue
            (
                std::vector<NXString> & valueString /** value string */ 
            );
            /**Returns  the Width
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: int Width
            (
            );
            /**Sets  the Width
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetWidth
            (
                int width /** width */ 
            );
            /**Returns  the ValuesConcatenated. Represents single string with values in block concatenated with new-line characters.
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: NXString ValuesConcatenated
            (
            );
            /**Sets  the ValuesConcatenated. Represents single string with values in block concatenated with new-line characters.
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            public: void SetValuesConcatenated
            (
                const NXString & valueString /** value string */ 
            );
            /**Sets  the ValuesConcatenated. Represents single string with values in block concatenated with new-line characters.
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : None */
            void SetValuesConcatenated
            (
                const char * valueString /** value string */ 
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