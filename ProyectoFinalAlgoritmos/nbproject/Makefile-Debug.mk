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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=G++-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Aerolinea_1.o \
	${OBJECTDIR}/ListaAerolineas.o \
	${OBJECTDIR}/Pais.o \
	${OBJECTDIR}/RegistrarUsuarioBusiness.o \
	${OBJECTDIR}/RegistrarUsuarioData.o \
	${OBJECTDIR}/Usuario.o \
	${OBJECTDIR}/Validar.o \
	${OBJECTDIR}/VentanaEscogerAerolinea.o \
	${OBJECTDIR}/VentanaIniciarSesion.o \
	${OBJECTDIR}/VentanaPrincipal.o \
	${OBJECTDIR}/VentanaRegistrar.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`pkg-config gtkmm-3.0 --cflags` 
CXXFLAGS=`pkg-config gtkmm-3.0 --cflags` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyectofinalalgoritmos

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyectofinalalgoritmos: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyectofinalalgoritmos ${OBJECTFILES} ${LDLIBSOPTIONS} `pkg-config gtkmm-3.0 --libs`

${OBJECTDIR}/Aerolinea_1.o: Aerolinea_1.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Aerolinea_1.o Aerolinea_1.cpp

${OBJECTDIR}/ListaAerolineas.o: ListaAerolineas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaAerolineas.o ListaAerolineas.cpp

${OBJECTDIR}/Pais.o: Pais.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pais.o Pais.cpp

${OBJECTDIR}/RegistrarUsuarioBusiness.o: RegistrarUsuarioBusiness.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegistrarUsuarioBusiness.o RegistrarUsuarioBusiness.cpp

${OBJECTDIR}/RegistrarUsuarioData.o: RegistrarUsuarioData.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegistrarUsuarioData.o RegistrarUsuarioData.cpp

${OBJECTDIR}/Usuario.o: Usuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Usuario.o Usuario.cpp

${OBJECTDIR}/Validar.o: Validar.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Validar.o Validar.cpp

${OBJECTDIR}/VentanaEscogerAerolinea.o: VentanaEscogerAerolinea.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaEscogerAerolinea.o VentanaEscogerAerolinea.cpp

${OBJECTDIR}/VentanaIniciarSesion.o: VentanaIniciarSesion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaIniciarSesion.o VentanaIniciarSesion.cpp

${OBJECTDIR}/VentanaPrincipal.o: VentanaPrincipal.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaPrincipal.o VentanaPrincipal.cpp

${OBJECTDIR}/VentanaRegistrar.o: VentanaRegistrar.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaRegistrar.o VentanaRegistrar.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
