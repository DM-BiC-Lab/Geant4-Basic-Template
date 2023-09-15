// Generally required libraries
#include  <iostream>
#include <string>

// Include Geant4 headers
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"

// Include custom headers
#include "construction.hh"
#include "physics.hh"
#include "action.hh"

int main(int argc, char** argv) {


    // Construct the run manager
    G4RunManager *runManager = new G4RunManager();
    
    // Initialize a detector construction, a physics list, and an
    // action initialization within the run manager. These are
    // all required for any project to be able to build successfully
    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyPhysicsList());
    runManager->SetUserInitialization(new MyActionInitialization());
    runManager->Initialize();

    // Construct a UIExecutive (ie enables the GUI)
    G4UIExecutive *ui = new G4UIExecutive(argc, argv);

    // Construct a VisManager, which manages the visualizer in the GUI
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    
    // Construct a UImanager, which allows project commands to be called
    // through this source code file
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    
    // Run several project commands through the UImanager
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 0.25 -0.5");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");
    
    // Start the UI session (displays the GUI to the user)
    ui->SessionStart();

    return 0;
}
