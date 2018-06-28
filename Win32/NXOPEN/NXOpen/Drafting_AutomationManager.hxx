#ifndef NXOpen_DRAFTING_AUTOMATIONMANAGER_HXX_INCLUDED
#define NXOpen_DRAFTING_AUTOMATIONMANAGER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Drafting_AutomationManager.ja
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
#include <NXOpen/Drafting_AnnotateViewsBuilder.hxx>
#include <NXOpen/Drafting_AttributeItemBuilder.hxx>
#include <NXOpen/Drafting_AutomationPreferencesBuilder.hxx>
#include <NXOpen/Drafting_DistributeAnnotationsBuilder.hxx>
#include <NXOpen/Drafting_DrawingCreationWizardBuilder.hxx>
#include <NXOpen/Drafting_PrimaryContentItemBuilder.hxx>
#include <NXOpen/Drafting_RulesBuilder.hxx>
#include <NXOpen/Drafting_SpecifyRuleBuilder.hxx>
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/libnxopencpp_drafting_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Drafting
    {
        class AutomationManager;
    }
    class DraftingManager;
    namespace Drafting
    {
        class AnnotateViewsBuilder;
    }
    namespace Drafting
    {
        class AttributeItemBuilder;
    }
    namespace Drafting
    {
        class AutomationPreferencesBuilder;
    }
    namespace Drafting
    {
        class DistributeAnnotationsBuilder;
    }
    namespace Drafting
    {
        class DrawingCreationWizardBuilder;
    }
    namespace Drafting
    {
        class PrimaryContentItemBuilder;
    }
    namespace Drafting
    {
        class RulesBuilder;
    }
    namespace Drafting
    {
        class SpecifyRuleBuilder;
    }
    namespace Drawings
    {
        class DrawingRegionCollection;
    }
    class Part;
    namespace Drafting
    {
        class AutomationManagerImpl;
        /**
            Represents a @link AutomationManager AutomationManager@endlink .  This class is
            used to create objects which are used in the automation of drawing creation.
             <br> Use @link DraftingManager::AutomationManager DraftingManager::AutomationManager@endlink  to get the instance of this class. <br> 
         <br>  Created in NX8.0.0.  <br>  
        */
        class NXOPENCPP_DRAFTINGEXPORT  AutomationManager
        {
            private: AutomationManagerImpl * m_automationmanager_impl;
            private: NXOpen::DraftingManager* m_owner;
            /// \cond NX_NO_DOC 
            public: explicit AutomationManager(NXOpen::DraftingManager *owner);


            /// \endcond 
            public: 
            /**Returns the tag of this object.  */
            tag_t Tag() const; 
            public: ~AutomationManager();
            /** Creates a @link Drafting::PrimaryContentItemBuilder Drafting::PrimaryContentItemBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Drafting::PrimaryContentItemBuilder * CreatePrimaryContentItemBuilder
            (
            );
            /** Creates a @link Drafting::AttributeItemBuilder Drafting::AttributeItemBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Drafting::AttributeItemBuilder * CreateAttributeItemBuilder
            (
            );
            /** Creates a @link Drafting::DrawingCreationWizardBuilder Drafting::DrawingCreationWizardBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Drafting::DrawingCreationWizardBuilder * CreateDrawingCreationWizardBuilder
            (
                bool isEditing /** If this is set to true then the builder will be configured for edit mode, otherwise it will be configured for create mode.
                                        Please see the @link Drafting::DrawingCreationWizardBuilder Drafting::DrawingCreationWizardBuilder@endlink  class documentation for more information on how
                                        to use the builder in these different modes. */
            );
            /** Creates a @link Drafting::DrawingCreationWizardBuilder Drafting::DrawingCreationWizardBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Drafting::DrawingCreationWizardBuilder * CreateDrawingCreationWizardBuilderFromRule
            (
                const NXString & className /** Drawing Booklet class used to populate the builder */
            );
            /** Creates a @link Drafting::DrawingCreationWizardBuilder Drafting::DrawingCreationWizardBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            NXOpen::Drafting::DrawingCreationWizardBuilder * CreateDrawingCreationWizardBuilderFromRule
            (
                const char * className /** Drawing Booklet class used to populate the builder */
            );
            /** Creates a @link Drafting::AutomationPreferencesBuilder Drafting::AutomationPreferencesBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : nx_drafting_plus ("DraftingPlus") */
            public: NXOpen::Drafting::AutomationPreferencesBuilder * CreatePreferencesBuilder
            (
            );
            /** Creates a @link Drafting::AnnotateViewsBuilder Drafting::AnnotateViewsBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Drafting::AnnotateViewsBuilder * CreateAnnotateViewsBuilder
            (
            );
            /** Creates a @link Drafting::RulesBuilder Drafting::RulesBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Drafting::RulesBuilder * CreateRulesBuilder
            (
            );
            /** Creates a @link Drafting::SpecifyRuleBuilder Drafting::SpecifyRuleBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Drafting::SpecifyRuleBuilder * CreateSpecifyRuleBuilder
            (
            );
            /** Creates a @link Drafting::DistributeAnnotationsBuilder Drafting::DistributeAnnotationsBuilder@endlink   @return  
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: NXOpen::Drafting::DistributeAnnotationsBuilder * CreateDistributeAnnotationsBuilder
            (
            );
            /** Returns the remaining loaded parts and remaining unloaded parts full names from the booklet 
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : None */
            public: void GetRemainingPartsOfBooklet
            (
                std::vector<NXOpen::Part *> & remainingParts /** remainingparts */ ,
                std::vector<NXString> & remainingPartFileSpecs /** remainingpartfilespecs */ 
            );


            /** Returns the RegionCollection instance  
             <br>  Created in NX8.0.0.  <br>  
            */
            public: NXOpen::Drawings::DrawingRegionCollection *DrawingRegions();
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