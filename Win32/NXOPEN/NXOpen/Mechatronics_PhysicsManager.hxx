#ifndef NXOpen_MECHATRONICS_PHYSICSMANAGER_HXX_INCLUDED
#define NXOpen_MECHATRONICS_PHYSICSMANAGER_HXX_INCLUDED
//--------------------------------------------------------------------------
//  Header for C++ interface to JA API
//--------------------------------------------------------------------------
//
//  Source File:
//     Mechatronics_PhysicsManager.ja
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
#include <NXOpen/libnxopencpp_mechatronics_exports.hxx>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

namespace NXOpen
{
    namespace Mechatronics
    {
        class PhysicsManager;
    }
    class Part;
    namespace Assemblies
    {
        class Component;
    }
    namespace Mechatronics
    {
        class AdapterFormulaCollection;
    }
    namespace Mechatronics
    {
        class AdapterSignalCollection;
    }
    namespace Mechatronics
    {
        class AngularLimitJointCollection;
    }
    namespace Mechatronics
    {
        class AngularSpringJointCollection;
    }
    namespace Mechatronics
    {
        class BallJointCollection;
    }
    namespace Mechatronics
    {
        class BreakingConstraintCollection;
    }
    namespace Mechatronics
    {
        class CamCollection;
    }
    namespace Mechatronics
    {
        class ChangeMaterialCollection;
    }
    namespace Mechatronics
    {
        class CollisionBodyCollection;
    }
    namespace Mechatronics
    {
        class CollisionMaterialCollection;
    }
    namespace Mechatronics
    {
        class CollisionSensorCollection;
    }
    namespace Mechatronics
    {
        class CylindricalJointCollection;
    }
    namespace Mechatronics
    {
        class ECADExportBuilder;
    }
    namespace Mechatronics
    {
        class ECADImportBuilder;
    }
    namespace Mechatronics
    {
        class ExternalConnectionCollection;
    }
    namespace Mechatronics
    {
        class FixedJointCollection;
    }
    namespace Mechatronics
    {
        class GearCollection;
    }
    namespace Mechatronics
    {
        class GraphControlCollection;
    }
    namespace Mechatronics
    {
        class HingeJointCollection;
    }
    namespace Mechatronics
    {
        class LinearLimitJointCollection;
    }
    namespace Mechatronics
    {
        class LinearSpringJointCollection;
    }
    namespace Mechatronics
    {
        class MotionProfileCollection;
    }
    namespace Mechatronics
    {
        class OPCClientBuilder;
    }
    namespace Mechatronics
    {
        class ObjectSinkCollection;
    }
    namespace Mechatronics
    {
        class ObjectSourceCollection;
    }
    namespace Mechatronics
    {
        class PositionControlCollection;
    }
    namespace Mechatronics
    {
        class PreferencesBuilder;
    }
    namespace Mechatronics
    {
        class PreventCollisionCollection;
    }
    namespace Mechatronics
    {
        class ReplacePhysicsBuilder;
    }
    namespace Mechatronics
    {
        class RigidBodyCollection;
    }
    namespace Mechatronics
    {
        class RuntimeBehaviorCollection;
    }
    namespace Mechatronics
    {
        class RuntimeFormulaCollection;
    }
    namespace Mechatronics
    {
        class SignalAdapterCollection;
    }
    namespace Mechatronics
    {
        class SignalConnectionCollection;
    }
    namespace Mechatronics
    {
        class SignalMappingBuilder;
    }
    namespace Mechatronics
    {
        class SlidingJointCollection;
    }
    namespace Mechatronics
    {
        class SpeedControlCollection;
    }
    namespace Mechatronics
    {
        class TransportSurfaceCollection;
    }
    class NXObject;
    namespace Mechatronics
    {
        class PhysicsManagerImpl;
        /** A manager to deal with all physics objects.  <br> To obtain an instance of this class, refer to @link Part Part@endlink  <br> 
         <br>  Created in NX7.5.1.  <br>  
        */
        class NXOPENCPP_MECHATRONICSEXPORT  PhysicsManager
        {
            private: PhysicsManagerImpl * m_physicsmanager_impl;
            private: NXOpen::Part* m_owner;
            /// \cond NX_NO_DOC 
            public: explicit PhysicsManager(NXOpen::Part *owner);


            /// \endcond 
            public: 
            /**Returns the tag of this object.  */
            tag_t Tag() const; 
            public: ~PhysicsManager();
            /** Creates a @link Mechatronics::PreferencesBuilder Mechatronics::PreferencesBuilder@endlink  object.  @return  Mechatronics Preferences builder
             <br>  Created in NX7.5.1.  <br>  
             <br> License requirements : nx_mcd_core ("MECHATRONICS CONCEPT DESIGNER") */
            public: NXOpen::Mechatronics::PreferencesBuilder * CreatePreferenceBuilder
            (
            );
            /** Creates a @link Mechatronics::ReplacePhysicsBuilder Mechatronics::ReplacePhysicsBuilder@endlink  object.  @return  Mechatronics Replace Physics builder
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : nx_mcd_core ("MECHATRONICS CONCEPT DESIGNER") */
            public: NXOpen::Mechatronics::ReplacePhysicsBuilder * CreateReplacePhysicsBuilder
            (
            );
            /** Creates a @link Mechatronics::OPCClientBuilder Mechatronics::OPCClientBuilder@endlink  object.  @return  OPCClient Builder 
             <br>  Created in NX8.0.0.  <br>  
             <br> License requirements : nx_mcd_core ("MECHATRONICS CONCEPT DESIGNER") */
            public: NXOpen::Mechatronics::OPCClientBuilder * CreateOpcclientBuilder
            (
            );
            /** Remap the physics references in context
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : nx_mcd_core ("MECHATRONICS CONCEPT DESIGNER") */
            public: void RemapPhysicsReferences
            (
                NXOpen::Assemblies::Component * replacedPartOcc /** @link Assemblies::Component Assemblies::Component@endlink  object. */
            );
            /** Log to delete
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : nx_mcd_core ("MECHATRONICS CONCEPT DESIGNER") */
            public: void LogPhysicsToDelete
            (
                NXOpen::NXObject * physicsObject /** physics object */ 
            );
            /** Creates a @link Mechatronics::ECADExportBuilder Mechatronics::ECADExportBuilder@endlink  object.  @return  ECADExport Builder 
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : nx_mcd_core ("MECHATRONICS CONCEPT DESIGNER") */
            public: NXOpen::Mechatronics::ECADExportBuilder * CreateECADExportBuilder
            (
            );
            /** Creates a @link Mechatronics::ECADImportBuilder Mechatronics::ECADImportBuilder@endlink  object.  @return  ECADImport Builder 
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : nx_mcd_core ("MECHATRONICS CONCEPT DESIGNER") */
            public: NXOpen::Mechatronics::ECADImportBuilder * CreateECADImportBuilder
            (
            );
            /** Creates a @link Mechatronics::SignalMappingBuilder Mechatronics::SignalMappingBuilder@endlink .  @return  SignalMapping Builder 
             <br>  Created in NX8.5.0.  <br>  
             <br> License requirements : nx_mcd_core ("MECHATRONICS CONCEPT DESIGNER") */
            public: NXOpen::Mechatronics::SignalMappingBuilder * CreateSignalMappingBuilder
            (
            );


            /** Returns the @link Mechatronics::RigidBodyCollection  Mechatronics::RigidBodyCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::RigidBodyCollection *RigidBodies();
            /** Returns the @link Mechatronics::CollisionBodyCollection  Mechatronics::CollisionBodyCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::CollisionBodyCollection *CollisionBodies();
            /** Returns the @link Mechatronics::MotionProfileCollection  Mechatronics::MotionProfileCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::MotionProfileCollection *MotionProfiles();
            /** Returns the @link Mechatronics::RuntimeBehaviorCollection  Mechatronics::RuntimeBehaviorCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::RuntimeBehaviorCollection *RuntimeBehaviors();
            /** Returns the @link Mechatronics::CollisionMaterialCollection  Mechatronics::CollisionMaterialCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::CollisionMaterialCollection *CollisionMaterials();
            /** Returns the @link Mechatronics::TransportSurfaceCollection  Mechatronics::TransportSurfaceCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::TransportSurfaceCollection *TransportSurfaces();
            /** Returns the @link Mechatronics::HingeJointCollection  Mechatronics::HingeJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::HingeJointCollection *HingeJoints();
            /** Returns the @link Mechatronics::SpeedControlCollection  Mechatronics::SpeedControlCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::SpeedControlCollection *SpeedControls();
            /** Returns the @link Mechatronics::PositionControlCollection  Mechatronics::PositionControlCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::PositionControlCollection *PositionControls();
            /** Returns the @link Mechatronics::SlidingJointCollection  Mechatronics::SlidingJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::SlidingJointCollection *SlidingJoints();
            /** Returns the @link Mechatronics::CollisionSensorCollection  Mechatronics::CollisionSensorCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::CollisionSensorCollection *CollisionSensors();
            /** Returns the @link Mechatronics::CylindricalJointCollection  Mechatronics::CylindricalJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::CylindricalJointCollection *CylindricalJoints();
            /** Returns the @link Mechatronics::FixedJointCollection  Mechatronics::FixedJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::FixedJointCollection *FixedJoints();
            /** Returns the @link Mechatronics::BallJointCollection  Mechatronics::BallJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::BallJointCollection *BallJoints();
            /** Returns the @link Mechatronics::AngularSpringJointCollection  Mechatronics::AngularSpringJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::AngularSpringJointCollection *AngularSpringJoints();
            /** Returns the @link Mechatronics::LinearSpringJointCollection  Mechatronics::LinearSpringJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::LinearSpringJointCollection *LinearSpringJoints();
            /** Returns the @link Mechatronics::GearCollection  Mechatronics::GearCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::GearCollection *Gears();
            /** Returns the @link Mechatronics::CamCollection  Mechatronics::CamCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::CamCollection *Cams();
            /** Returns the @link Mechatronics::AngularLimitJointCollection  Mechatronics::AngularLimitJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::AngularLimitJointCollection *AngularLimitJoints();
            /** Returns the @link Mechatronics::LinearLimitJointCollection  Mechatronics::LinearLimitJointCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::LinearLimitJointCollection *LinearLimitJoints();
            /** Returns the @link Mechatronics::BreakingConstraintCollection  Mechatronics::BreakingConstraintCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::BreakingConstraintCollection *BreakingConstraints();
            /** Returns the @link Mechatronics::PreventCollisionCollection  Mechatronics::PreventCollisionCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::PreventCollisionCollection *PreventCollisions();
            /** Returns the @link Mechatronics::ChangeMaterialCollection  Mechatronics::ChangeMaterialCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::ChangeMaterialCollection *ChangeMaterials();
            /** Returns the @link Mechatronics::ObjectSourceCollection  Mechatronics::ObjectSourceCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::ObjectSourceCollection *ObjectSources();
            /** Returns the @link Mechatronics::ObjectSinkCollection  Mechatronics::ObjectSinkCollection @endlink  belonging to this part 
             <br>  Created in NX7.5.1.  <br>  
            */
            public: NXOpen::Mechatronics::ObjectSinkCollection *ObjectSinks();
            /** Returns the @link Mechatronics::GraphControlCollection  Mechatronics::GraphControlCollection @endlink  belonging to this part 
             <br>  Created in NX8.0.0.  <br>  
            */
            public: NXOpen::Mechatronics::GraphControlCollection *GraphControls();
            /** Returns the @link Mechatronics::ExternalConnectionCollection  Mechatronics::ExternalConnectionCollection @endlink  belonging to this part 
             <br>  Created in NX8.0.0.  <br>  
            */
            public: NXOpen::Mechatronics::ExternalConnectionCollection *ExternalConnections();
            /** Returns the @link Mechatronics::RuntimeFormulaCollection  Mechatronics::RuntimeFormulaCollection @endlink  belonging to this part 
             <br>  Created in NX8.5.0.  <br>  
            */
            public: NXOpen::Mechatronics::RuntimeFormulaCollection *RuntimeFormulas();
            /** Returns the @link Mechatronics::SignalAdapterCollection  Mechatronics::SignalAdapterCollection @endlink  belonging to this part 
             <br>  Created in NX8.5.0.  <br>  
            */
            public: NXOpen::Mechatronics::SignalAdapterCollection *SignalAdapters();
            /** Returns the @link Mechatronics::AdapterSignalCollection  Mechatronics::AdapterSignalCollection @endlink  belonging to this part 
             <br>  Created in NX8.5.0.  <br>  
            */
            public: NXOpen::Mechatronics::AdapterSignalCollection *AdapterSignals();
            /** Returns the @link Mechatronics::AdapterFormulaCollection  Mechatronics::AdapterFormulaCollection @endlink  belonging to this part 
             <br>  Created in NX8.5.0.  <br>  
            */
            public: NXOpen::Mechatronics::AdapterFormulaCollection *AdapterFormulas();
            /** Returns the @link Mechatronics::SignalConnectionCollection  Mechatronics::SignalConnectionCollection @endlink  belonging to this part 
             <br>  Created in NX8.5.0.  <br>  
            */
            public: NXOpen::Mechatronics::SignalConnectionCollection *SignalConnections();
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