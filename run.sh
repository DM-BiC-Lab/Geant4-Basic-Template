# Runs the project in the directory where this file is located

# Optional arguments:
# -rb / --rebuild = Rebuilds project entirely, then runs the project



# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
# THIS VARIABLE MUST BE SET TO THE ABSOLUTE PATH OF YOUR GEANT4 INSTALL
#* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
INSTALL_PATH="/path/to/install"
 
# Sourcing these files is required to run Geant4
source "$INSTALL_PATH/share/Geant4/geant4make/geant4make.sh"
source "$INSTALL_PATH/bin/geant4.sh"

# Reset command line argument flags
REBUILD=""
ERROR=""

# Get all command line arguments
for arg in "$@"
do
    case $arg in
        -rb|--rebuild) REBUILD="SET"            
        ;;
        *) ERROR="SET"
           echo "ERROR: Invalid argument \"$arg\" found"
        ;;
    esac
done

# If at least one erroneous argument was found, return
if [ "$ERROR" == "SET" ]
then
    return
fi

# If the build flag is set and the build directory exists...
if  [[ "$REBUILD" == "SET" && -d "./build" ]]
then
    # Remove build directory along with files inside
    rm -r ./build
fi

# If the build directory does not exist, create it
if ! [ -d "./build" ]
then
    mkdir build
fi

# Build / rebuild project
cd build
cmake ..
make
cd ..

# Get the name of the output executable from "CMakeLists.txt"
BUILD_EXE=$(grep "set(OUTPUT_EXE_NAME" CMakeLists.txt)
BUILD_EXE=${BUILD_EXE#*\"}
BUILD_EXE=${BUILD_EXE%\"*}

# If the executable exists in the build directory...
if [ -f "./build/$BUILD_EXE" ]
then
    # Run the build
    ./build/$BUILD_EXE
else
    # Otherwise, print an appropriate error message
    echo -e "\nERROR: Could not execute build. Executable not found. Try building manually?\n"
fi
