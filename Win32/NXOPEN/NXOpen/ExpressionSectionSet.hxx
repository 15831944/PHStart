#ifndef NXOpen_EXPRESSIONSECTIONSET_HXX_INCLUDED
#define NXOpen_EXPRESSIONSECTIONSET_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     ExpressionSectionSet.ja
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
#include <NXOpen/NXObject.hxx>
#include <NXOpen/libnxopencpp_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    class ExpressionSectionSet;
    class Expression;
    class NXObject;
    class Section;
    class _ExpressionSectionSetBuilder;
    class ExpressionSectionSetImpl;
    /** An object that binds an expression with an entity section in the context of a list.
     <br> To create a new instance of this class, use @link Part::CreateEmptyExpressionSectionSet Part::CreateEmptyExpressionSectionSet@endlink  <br> 
     <br>  Created in NX5.0.0.  <br>  
    */
    class NXOPENCPPEXPORT  ExpressionSectionSet : public NXObject
    {
        private: ExpressionSectionSetImpl * m_expressionsectionset_impl;
        private: friend class  _ExpressionSectionSetBuilder;
        protected: ExpressionSectionSet();
        public: ~ExpressionSectionSet();
        /**Returns  the section
            
         <br>  Created in NX5.0.0.  <br>  
         <br> License requirements : None */
        public: NXOpen::Section * Section
        (
        );
        /**Sets  the section
            
         <br>  Created in NX5.0.0.  <br>  
         <br> License requirements : None */
        public: void SetSection
        (
            NXOpen::Section * sectionTg /** section tg */ 
        );
        /**Returns  the expression
            
         <br>  Created in NX5.0.0.  <br>  
         <br> License requirements : None */
        public: NXOpen::Expression * ItemValue
        (
        );
        /**Returns  the flip flag
            
         <br>  Created in NX5.0.0.  <br>  
         <br> License requirements : None */
        public: bool ItemFlipFlag
        (
        );
        /**Sets  the flip flag
            
         <br>  Created in NX5.0.0.  <br>  
         <br> License requirements : None */
        public: void SetItemFlipFlag
        (
            bool flip /** flip */ 
        );
        /**Returns  the index in the list
            
         <br>  Created in NX5.0.0.  <br>  
         <br> License requirements : None */
        public: int ItemIndex
        (
        );
        /**Sets  the index in the list
            
         <br>  Created in NX5.0.0.  <br>  
         <br> License requirements : None */
        public: void SetItemIndex
        (
            int index /** index */ 
        );
    };
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