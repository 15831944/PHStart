#ifndef NXOpen_UISTYLER_OPTIONTOGGLE_HXX_INCLUDED
#define NXOpen_UISTYLER_OPTIONTOGGLE_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     UIStyler_OptionToggle.ja
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
#include <NXOpen/UIStyler_StylerItem.hxx>
#include <NXOpen/UIStyler_StylerItem.hxx>
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
    namespace UIStyler
    {
        class OptionToggle;
    }
    namespace UIStyler
    {
        class StylerEvent;
    }
    namespace UIStyler
    {
        class StylerItem;
    }
    namespace UIStyler
    {
        class OptionToggleImpl;
        /** Represents a OptionToggle for UI Styler 
         <br>  Created in NX5.0.0.  <br>  
        */
        class NXOPENUICPPEXPORT  OptionToggle : public UIStyler::StylerItem
        {
            public: /** Called when a dialog user selects an option from the menu  
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            typedef NXOpen::Callback1<NXOpen::UIStyler::DialogState, NXOpen::UIStyler::StylerEvent *> Activate;
            public: /**Called when a dialog user clicks on the button or presses the spacebar when the button has keyboard focus. 
                Do not terminate the dialog with a value-changed callback. The dialog should always return UF_UI_CB_CONTINUE_DIALOG. 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            typedef NXOpen::Callback1<NXOpen::UIStyler::DialogState, NXOpen::UIStyler::StylerEvent *> ValueChanged;
            private: OptionToggleImpl * m_optiontoggle_impl;
            /// \cond NX_NO_DOC 
            public: explicit OptionToggle(void *ptr);
            /// \endcond 
            /**Registers activate callback. This method should be called before calling @link  UIStyler::Dialog::Show   UIStyler::Dialog::Show @endlink  or @link  UIStyler::Dialog::RegisterWithUiMenu   UIStyler::Dialog::RegisterWithUiMenu @endlink  
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void AddActivateHandler
            (
                const NXOpen::UIStyler::OptionToggle::Activate&  activateevent /** Callback for activate event */,
                bool isDialogLaunchingEvent /** TRUE if dialog is going to launch, FALSE if not */
            );
            /**Registers value change callback. This method should be called before calling @link  UIStyler::Dialog::Show   UIStyler::Dialog::Show @endlink  or @link  UIStyler::Dialog::RegisterWithUiMenu   UIStyler::Dialog::RegisterWithUiMenu @endlink  
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void AddValueChangedHandler
            (
                const NXOpen::UIStyler::OptionToggle::ValueChanged&  valuechangedevent /** Callback for value changed event */,
                bool isDialogLaunchingEvent /** TRUE if dialog is going to launch, FALSE if not */
            );
            /** Set bitmaps 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void SetBitmaps
            (
                std::vector<NXString> & bitmaps /** An array of one or more bitmap filenames. 
                        If all bitmaps for the option menu reside in the same file, specify an array of just one entry, 
                        which contains the bitmap filename for this attribute. All existing choices for the option menu 
                        remain intact when this attribute is set. Only the bitmaps are changed. Note that the number of 
                        bitmaps must match the number of existing choices.   <br>  NOTE: The full Unicode character set is not supported for this parameter.  <br> */
            );
            /** Sets label 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void SetLabel
            (
                const NXString & strLabel /** Text to be set for the tool tip.   <br>  NOTE: The full Unicode character set is not supported for this parameter.  <br> */
            );
            /** Sets label 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            void SetLabel
            (
                const char * strLabel /** Text to be set for the tool tip.   <br>  NOTE: The full Unicode character set is not supported for this parameter.  <br> */
            );
            /** Sets items in the array 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void SetItems
            (
                std::vector<NXString> & strListArray /** An array of new choices to be used for the dialog item. 
                        Note that this removes all existing choices (both text and bitmaps).   <br>  NOTE: The full Unicode character set is not supported for this parameter.  <br> */
            );
            /** Returns the items  @return  An array of items 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: std::vector<NXString> GetItems
            (
            );
            /** Sets item value 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void SetItemValue
            (
                int subitemIndex /** Zero-based index indicating the choice to be selected. 
                        It must be in the range of existing choices.*/,
                bool setCheck /** TRUE if set, FALSE if unset. */
            );
            /** Returns item value  @return  Item value 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: int GetItemValue
            (
                bool* setCheck /** set check */ 
            );
            /** Set the sesitivity 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void SetSensitivity
            (
                int subitemIndex /** If the entire dialog item should change to the new Sensitivity state, 
                        set this field to UF_STYLER_NO_SUB_INDEX. If only one sub-item should change to the new sensitivity 
                        state, set this field to its zero-based index. */,
                bool type /** TRUE if sensitive, FALSE if insensitive */
            );
            /** Returns the sesitivity  @return  
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: bool GetSensitivity
            (
            );
            /**Sets  the visibility 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void SetVisibility
            (
                bool type /** TRUE if visible, FALSE if invisible */
            );
            /**Returns  the visibility 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: bool Visibility
            (
            );
            /** Sets default action 
             <br>  Created in NX5.0.0.  <br>  
             <br> License requirements : None */
            public: void SetDefaultAction
            (
            );
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