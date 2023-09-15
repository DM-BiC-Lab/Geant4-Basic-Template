#include "construction.hh"

// Empty constructor and destructor
MyDetectorConstruction::MyDetectorConstruction() { }
MyDetectorConstruction::~MyDetectorConstruction() { }

// 
G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    // Get the NIST manager (allows for access to prebuilt materials)
    G4NistManager *nist = G4NistManager::Instance();
    // Retrieve and store a material from the NIST manager
    // (list of materials in ~/Tommy/Geant4/Reference Files/ NIST_materials.txt)
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_Galactic");
    
    // Define a volume for the simulation to take place within
    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
    // Create a Logical Volume using the G4Box and G4Material
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    // Place the logical volume into the simulation by creating a physical volume
    // (I'm not sure what a lot of the parameters in the constructor are for. The most
    // important are the second, third, and fourth, which are the the position of the volume,
    // the logical volume to use when creating the physical volume, and a name for the volume)
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
    
    return physWorld;
    
}
