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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ui/Canvas.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/render/Renderer.o \
	${OBJECTDIR}/render/Viewport.o \
	${OBJECTDIR}/ui/GLFWCanvas.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpp-game-engine.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpp-game-engine.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cpp-game-engine ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/ui/Canvas.o: ui/Canvas.cpp 
	${MKDIR} -p ${OBJECTDIR}/ui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ui/Canvas.o ui/Canvas.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/render/Renderer.o: render/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/render
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/render/Renderer.o render/Renderer.cpp

${OBJECTDIR}/render/Viewport.o: render/Viewport.cpp 
	${MKDIR} -p ${OBJECTDIR}/render
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/render/Viewport.o render/Viewport.cpp

${OBJECTDIR}/ui/GLFWCanvas.o: ui/GLFWCanvas.cpp 
	${MKDIR} -p ${OBJECTDIR}/ui
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ui/GLFWCanvas.o ui/GLFWCanvas.cpp

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
