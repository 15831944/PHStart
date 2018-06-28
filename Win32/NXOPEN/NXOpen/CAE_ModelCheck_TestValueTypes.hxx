#ifndef NXOpen_CAE_MODELCHECK_TESTVALUETYPES_HXX_INCLUDED
#define NXOpen_CAE_MODELCHECK_TESTVALUETYPES_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     CAE_ModelCheck_TestValueTypes.ja
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
        namespace ModelCheck
        {
            class TestValueTypes;
        }
    }
    namespace CAE
    {
        namespace ModelCheck
        {
            class TestValueTypesImpl;
            /**  @brief  Represents the quality check criteria value settings  

               <br> No Creator this holds an enum  shared by other classes <br> 
             <br>  Created in NX8.5.0.  <br>  
            */
            class NXOPENCPP_CAEEXPORT  TestValueTypes
            {
                /** the test types */
                public: enum TestType
                {
                    TestTypeJacobianZero/** jacobian zero */ ,
                    TestTypeJacobianRatio/** jacobian ratio */ ,
                    TestTypeJacobianSign/** jacobian sign */ ,
                    TestTypeVolume/** volume */ ,
                    TestTypeAxisymmetricY/** axisymmetric y */ ,
                    TestTypeAxisymmetricX/** axisymmetric x */ ,
                    TestTypeAspectRatio/** aspect ratio */ ,
                    TestTypeSkewAngle/** skew angle */ ,
                    TestTypeInteriorAngleMinimum/** interior angle minimum */ ,
                    TestTypeInteriorAngleMaximum/** interior angle maximum */ ,
                    TestTypeTaper/** taper */ ,
                    TestTypeWarpFactor/** warp factor */ ,
                    TestTypeFaceWarpCoefficient/** face warp coefficient */ ,
                    TestTypeEdgePointLengthRatio/** edge point length ratio */ ,
                    TestTypeEdgePointIncludedAngle/** edge point included angle */ ,
                    TestTypeLengthRatioOffset/** length ratio offset */ ,
                    TestTypeParallelDeviation/** parallel deviation */ ,
                    TestTypeShapeFactor/** shape factor */ ,
                    TestTypeTwist/** twist */ ,
                    TestTypeLengthMinimum/** length minimum */ ,
                    TestTypeLengthMaximum/** length maximum */ ,
                    TestTypeTetCollapse/** tet collapse */ ,
                    TestTypeWarpageAngle/** warpage angle */ 
                };

                /** indicates how to compare the check result with the criteria value */
                public: enum Validator
                {
                    ValidatorNone/** indicates no criteria value defined, not necessary to compare the check result with criteria value */,
                    ValidatorGreatThan/** the check passes if the check result is great than the criteria value */,
                    ValidatorGreatThanOrEqual/** the check passes if the check result is equal or great than the criteria value */,
                    ValidatorSmallThan/** the check passes if the check result is small than the criteria value */,
                    ValidatorSmallThanOrEqual/** the check passes if the check result is equal or small than the criteria value */
                };

                /** the alert level of a criteria value */
                public: enum CriteriaType
                {
                    CriteriaTypeWarning/** reports as warning if the check result failed with the criteria value */,
                    CriteriaTypeError/** reports as error if the check result failed with the criteria value */
                };

                /** the checking result */
                public: enum Result
                {
                    ResultPassed/** indicates the test value does not violate the criteria values */,
                    ResultFailed/** indicates the test value violates the error criteria value */,
                    ResultException/** indicates there is an exception thrown during the checking */,
                    ResultNotApply/** indicates the test is not available or not done for an element  */,
                    ResultWarned/** indicates the test value violates the warning criteria value */
                };

                 /** represents an element reference definition associated with this test */
                public:
                struct  ElementReference
                {
                    public: /** the element type name, which is defined in solver specific item */NXString ElementTypeName;
                    public: /** a specified integer element property name */NXString ElementPropertyName;
                    public: /** the control value of integer element property, only valid when property name is not NULL */int ElementPropertyValue;
                    public: ElementReference() :
                        ElementTypeName(),
                        ElementPropertyName(),
                        ElementPropertyValue()
                    {
                    }
                    /** Constructor for the ElementReference struct. */ 
                    public: ElementReference(const NXString &elementTypeNameInitial /** the element type name, which is defined in solver specific item */, 
                            const NXString &elementPropertyNameInitial /** a specified integer element property name */, 
                            int elementPropertyValueInitial /** the control value of integer element property, only valid when property name is not NULL */) :
                        ElementTypeName(elementTypeNameInitial),
                        ElementPropertyName(elementPropertyNameInitial),
                        ElementPropertyValue(elementPropertyValueInitial)
                    {
                    }
                };

                private: TestValueTypesImpl * m_testvaluetypes_impl;
                public: ~TestValueTypes();
            }; //lint !e1712 default constructor not defined for class  

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