/*******************************************************************************
               Copyright (c) 2003 Unigraphics Solutions Inc.
                      Unpublished - All Rights Reserved


*******************************************************************************/
#ifndef NXOpen_NXEXCEPTION_HXX_INCLUDED
#define NXOpen_NXEXCEPTION_HXX_INCLUDED

#ifdef _MSC_VER
#pragma once
#endif

#include <exception>
#include <string>
#include <NXOpen/libnxopencpp_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4251)
#endif

namespace NXOpen
{
    /** A base class for exceptions thrown by NXOpen methods */
    class NXOPENCPPEXPORT NXException : public std::exception
    {
    public:
        NXException(const NXException &other);
        virtual ~NXException() throw();

        /** Creates an NXException. */
        static NXException Create(int errorCode);

        /** Creates an NXException based on a message in English.
            The error code is set to zero. */
        static NXException Create(const char* message);

        static void ThrowBadTagException();

        static void ThrowUnexpectedSuccess();

        /** Gets the error message associated with this exception. */
        const char* Message() const;

        /** <b>Deprecated</b>:<br>
        &nbsp;&nbsp;&nbsp;Use @link Message() Message@endlink instead.
        @deprecated */
        const char* GetMessage() const { return Message(); }

        /** Gets the error message associated with this exception.
        Does not throw an exception. */
        virtual const char * what () const throw () { return Message(); }

        /** Gets the error code associated with this exception. */
        int ErrorCode() const { return m_code; }

        /** <b>Deprecated</b>:<br>
        &nbsp;&nbsp;&nbsp;Use @link ErrorCode() ErrorCode@endlink instead.
        @deprecated */
        int GetErrorCode() const { return ErrorCode(); }

        /** Assert if the error code is unexpected. */
        void AssertErrorCode(int code) const;

    private:

        NXException(); // For QAZ.  Not implemented.
        NXException& operator=(const NXException&);
        explicit NXException(int errorCode);
        explicit NXException(const char *message);

        int m_code;
        mutable std::string m_message;
    };
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#undef EXPORTLIBRARY

#endif // NXEXCEPTION_HXX_INCLUDED