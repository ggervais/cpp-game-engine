#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/render/GLRenderer.o \
	${OBJECTDIR}/timing/GLFWTimer.o \
	${OBJECTDIR}/ui/Canvas.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/math/Matrix4x4.o \
	${OBJECTDIR}/input/GLFWInput.o \
	${OBJECTDIR}/render/Renderer.o \
	${OBJECTDIR}/math/Vector3D.o \
	${OBJECTDIR}/input/Input.o \
	${OBJECTDIR}/timing/Timer.o \
	${OBJECTDIR}/render/Viewport.o \
	${OBJECTDIR}/ui/GLFWCanvas.o \
	${OBJECTDIR}/game/Game.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lglfw -lopengl32 -lglew32 -lglu32 -lfreeglut

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpp-game-engine.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpp-game-engine.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpp-game-engine ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/render/GLRenderer.o: render/GLRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/render
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/render/GLRenderer.o render/GLRenderer.cpp

${OBJECTDIR}/timing/GLFWTimer.o: timing/GLFWTimer.cpp 
	${MKDIR} -p ${OBJECTDIR}/timing
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/timing/GLFWTimer.o timing/GLFWTimer.cpp

${OBJECTDIR}/ui/Canvas.o: ui/Canvas.cpp 
	${MKDIR} -p ${OBJECTDIR}/ui
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ui/Canvas.o ui/Canvas.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/math/Matrix4x4.o: math/Matrix4x4.cpp 
	${MKDIR} -p ${OBJECTDIR}/math
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/math/Matrix4x4.o math/Matrix4x4.cpp

${OBJECTDIR}/input/GLFWInput.o: input/GLFWInput.cpp 
	${MKDIR} -p ${OBJECTDIR}/input
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/input/GLFWInput.o input/GLFWInput.cpp

${OBJECTDIR}/render/Renderer.o: render/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/render
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/render/Renderer.o render/Renderer.cpp

${OBJECTDIR}/math/Vector3D.o: math/Vector3D.cpp 
	${MKDIR} -p ${OBJECTDIR}/math
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/math/Vector3D.o math/Vector3D.cpp

${OBJECTDIR}/input/Input.o: input/Input.cpp 
	${MKDIR} -p ${OBJECTDIR}/input
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/input/Input.o input/Input.cpp

${OBJECTDIR}/timing/Timer.o: timing/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/timing
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/timing/Timer.o timing/Timer.cpp

${OBJECTDIR}/render/Viewport.o: render/Viewport.cpp 
	${MKDIR} -p ${OBJECTDIR}/render
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/render/Viewport.o render/Viewport.cpp

${OBJECTDIR}/ui/GLFWCanvas.o: ui/GLFWCanvas.cpp 
	${MKDIR} -p ${OBJECTDIR}/ui
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ui/GLFWCanvas.o ui/GLFWCanvas.cpp

${OBJECTDIR}/game/Game.o: game/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/game
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/game/Game.o game/Game.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpp-game-engine.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
