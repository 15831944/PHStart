#ifndef NXOpen_ERRORINFO_HXX_INCLUDED
#define NXOpen_ERRORINFO_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     ErrorInfo.ja
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
#include <NXOpen/TransientObject.hxx>
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
    class ErrorInfo;
    class NXObject;
    class ErrorInfoImpl;
    /** Contains information about an error that occurred 
     <br>  Created in NX3.0.0.  <br>  
    */
    class NXOPENCPPEXPORT  ErrorInfo : public TransientObject
    {
        private: ErrorInfoImpl * m_errorinfo_impl;
        /// \cond NX_NO_DOC 
        public: explicit ErrorInfo(void *ptr);
        /// \endcond 
        /** Frees this object from memory.  After this method is called,
            it is illegal to use the object.  In .NET, this method is automatically
            called when the object is deleted by the garbage collector.  
         <br>  Created in NX3.0.0.  <br>  
         <br> License requirements : None */
        public: virtual ~ErrorInfo();
        /**Returns  a number that represents what error occurred 
         <br>  Created in NX3.0.0.  <br>  
         <br> License requirements : None */
        public: int ErrorCode
        (
        );
        /**Returns  the object for which the error occurred. This may be NULL if the object was deleted.
             <br> 
            Note: if the object was deleted, @link ErrorObjectDescription ErrorObjectDescription@endlink  
            may be used to obtain a description of the object. 
             <br> 
            
         <br>  Created in NX3.0.0.  <br>  
         <br> License requirements : None */
        public: NXOpen::NXObject * ErrorObject
        (
        );
        /**Returns  a description of the object for which the error occurred 
         <br>  Created in NX3.0.0.  <br>  
         <br> License requirements : None */
        public: NXString ErrorObjectDescription
        (
        );
        /**Returns  a description of the error 
         <br>  Created in NX3.0.0.  <br>  
         <br> License requirements : None */
        public: NXString Description
        (
        );
    }; //lint !e1712 default constructor not defined for class  

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