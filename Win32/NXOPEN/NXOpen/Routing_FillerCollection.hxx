#ifndef NXOpen_ROUTING_FILLERCOLLECTION_HXX_INCLUDED
#define NXOpen_ROUTING_FILLERCOLLECTION_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Routing_FillerCollection.ja
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
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/TaggedObjectCollection.hxx>
#include <NXOpen/libnxopencpp_routing_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Routing
    {
        class FillerCollection;
    }
    namespace Routing
    {
        class RouteManager;
    }
    namespace Routing
    {
        class Filler;
    }
    namespace Routing
    {
        class Anchor;
    }
    namespace Routing
    {
        class CrossSection;
    }
    namespace Routing
    {
        class ISegment;
    }
    namespace Routing
    {
        class Stock;
    }
    namespace Routing
    {
        class StockData;
    }
    namespace Routing
    {
        class FillerCollectionImpl;
        /** Represents a collection of @link Routing::Stock Routing::Stock@endlink  objects.   <br> To obtain an instance of this class, refer to @link Routing::RouteManager Routing::RouteManager@endlink  <br> 
         <br>  Created in NX4.0.0.  <br>  
        */
        class NXOPENCPP_ROUTINGEXPORT  FillerCollection : public TaggedObjectCollection
        {
            private: FillerCollectionImpl * m_fillercollection_impl;
            private: NXOpen::Routing::RouteManager* m_owner;
            /// \cond NX_NO_DOC 
            public: explicit FillerCollection(NXOpen::Routing::RouteManager *owner);


            /// \endcond 
            public: 
            /**Returns the tag of this object.  */
            tag_t Tag() const; 
            public: ~FillerCollection();
            /** Iterator for accessing the contents of the collection. */
            //lint -sem(NXOpen::Routing::FillerCollection::iterator::copy,initializer)
            class iterator
            {
            public:
                /** Value type associated with iterator*/ 

                typedef Routing::Filler * value_type;
                /** Default constructor */
                iterator() : m_context(NULL), m_current(NULL_TAG)
                {
                } //lint !e1401 m_state is not initialized
                /// \cond NX_NO_DOC
                explicit iterator(NXOpen::Routing::FillerCollection *context) : m_context(context), m_current(NULL_TAG)
                {
                }//lint !e1401 m_state is not initialized
                /// \endcond
                /** Copy constructor */
                iterator(const iterator &other): m_context(NULL), m_current(NULL_TAG)
                {
                    copy(other);
                }
                /** Copy constructor */
                iterator &operator =(const iterator &other)
                {
                    if (&other != this)
                        copy(other);
                    return *this;
                }
                /** Tests if the iterator objects on the left side and the right side of the operator are equal. */
                bool operator ==(const iterator &other) const
                {
                    return m_current == other.m_current && m_context == other.m_context;
                }
                /** Tests if the iterator objects on the left side and the right side of the operator are not equal. */
                bool operator !=(const iterator &other) const
                {
                    return !operator == (other);
                }
                /** Return the element currently pointed to by the iterator. */
                NXOPENCPP_ROUTINGEXPORT  value_type operator * ();
                /** Points the iterator to next element. */
                iterator & operator ++()
                {
                    next();
                    return *this;
                }
                /** Points the iterator to next element. */
                iterator operator ++(int)
                {
                    iterator tmp(*this);
                    ++*this;
                    return tmp;
                }
            private:
                void copy(const iterator &other)
                {
                    m_context = other.m_context;
                    m_current = other.m_current;
                    for (int i = 0; i < sizeof(m_state)/sizeof(m_state[0]); i++)
                         m_state[i] = other.m_state[i];
                }
                NXOPENCPP_ROUTINGEXPORT  void next();
                NXOpen::Routing::FillerCollection *m_context;
                tag_t m_current;
                unsigned int m_state[8];
            };
            /** Returns an iterator addressing the first element. */
            iterator begin();
            /** Returns an iterator addressing one past the last element. */
            iterator end()
            {
                return iterator(this);
            }
            /** Creates a @link Routing::Filler Routing::Filler@endlink  stock object.  @return  The resulting array of newly created @link Routing::Stock Routing::Stock@endlink 
                                                        objects. 
             <br>  Created in NX4.0.0.  <br>  
             <br> License requirements : routing_harness ("Routing Harness") */
            public: std::vector<NXOpen::Routing::Stock *> CreateStock
            (
                NXOpen::Routing::StockData * stockData /** The @link Routing::StockData Routing::StockData@endlink  that defines the stock */,
                NXOpen::Routing::Anchor * anchor /** The @link Routing::Anchor Routing::Anchor@endlink  from the input 
                                                           @link Routing::StockData Routing::StockData@endlink  to use, ja_NULL is allowed for
                                                           no anchor. */,
                NXOpen::Routing::CrossSection * crossSection /** The @link Routing::CrossSection Routing::CrossSection@endlink  from the input 
                                                           @link Routing::StockData Routing::StockData@endlink  to use, ja_NULL is not allowed. */,
                const std::vector<NXOpen::Routing::ISegment *> & segments /** The array of @link Routing::ISegment Routing::ISegment@endlink  curves that
                                                                the stock must cover. */
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