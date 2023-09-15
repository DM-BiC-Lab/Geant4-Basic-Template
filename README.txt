The following are notes on how to modify the files within this directory
in order to create a project using this template

********** DISCLAIMER **********

This template is meant to be used as a tool to assist with the
creation of Geant4 projects. It was made by one person and may
contain spelling errors, bugs, incorrect comments, among other
things. Feel free to correct any of these issues if you feel
comfortable enough to make changes

********** REQUIREMENTS **********

The following actions are REQUIRED in order for this template
to work as intended:

- Within the "run.sh" file, set the INSTALL_PATH variable to the
  absolute path of your Geant4 installation

********** GENERAL **********

By default, the project is configured to look for header files in the
"include" directory and source code files within the "src" directory, 
with the exception of the main source code file, which should be located in
the main project directory. The locations of these files may be changed,
and new directories may be added, by modifying "CMakeLists.txt". Though,
it is probably not worth making any changes unless it is necessary and
you know how to properly modify "CMakeLists.txt"

This is a basic project template for Geant4. For a larger template
that includes features such as output file generation, automation, and
output visualization, please refer to the Geant4 Extended Template

********** run.sh **********

To make building projects easier, the "run.sh" Bash script has been 
created, which can automatically create a build directory for a 
project, build, and execute a project executable. You can use 
this script by running the following inside of the project folder:
$ . run.sh	(to build and run)
$ . run.sh -rb	(to force a complete rebuild and run)

********** CMakeLists.txt **********

By default within "CMakeLists.txt", the project name, main code file, and
output executable have been named as "Geant4Template", "template.cc", and
"template" respectively. If you wish to change these, please change the
values of their corresponding variables

********** template.cc **********

Removing any of the code within "template.cc" will most likely result
in the project not building as expected. Feel free to add additional
code to this file, but note that removing code that is already there
is not advised

*********************************
