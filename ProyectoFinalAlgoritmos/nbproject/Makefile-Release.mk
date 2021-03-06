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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Administrador.o \
	${OBJECTDIR}/Aerolinea_1.o \
	${OBJECTDIR}/Cola.o \
	${OBJECTDIR}/Drawing.o \
	${OBJECTDIR}/Grafo.o \
	${OBJECTDIR}/Itinerario.o \
	${OBJECTDIR}/ListaAerolineas.o \
	${OBJECTDIR}/Pais.o \
	${OBJECTDIR}/PaisDestino.o \
	${OBJECTDIR}/RegistrarUsuarioBusiness.o \
	${OBJECTDIR}/RegistrarUsuarioData.o \
	${OBJECTDIR}/Usuario.o \
	${OBJECTDIR}/Validar.o \
	${OBJECTDIR}/VentanaAdministracion.o \
	${OBJECTDIR}/VentanaEscogerAerolinea.o \
	${OBJECTDIR}/VentanaIniciarSesion.o \
	${OBJECTDIR}/VentanaLogAdmin.o \
	${OBJECTDIR}/VentanaPrincipal.o \
	${OBJECTDIR}/VentanaRegistrar.o \
	${OBJECTDIR}/VentanaTransito.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyectofinalalgoritmos

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyectofinalalgoritmos: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyectofinalalgoritmos ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Administrador.o: Administrador.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Administrador.o Administrador.cpp

${OBJECTDIR}/Aerolinea_1.o: Aerolinea_1.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Aerolinea_1.o Aerolinea_1.cpp

${OBJECTDIR}/Cola.o: Cola.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cola.o Cola.cpp

${OBJECTDIR}/Drawing.o: Drawing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Drawing.o Drawing.cpp

${OBJECTDIR}/Grafo.o: Grafo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grafo.o Grafo.cpp

${OBJECTDIR}/Itinerario.o: Itinerario.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Itinerario.o Itinerario.cpp

${OBJECTDIR}/ListaAerolineas.o: ListaAerolineas.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaAerolineas.o ListaAerolineas.cpp

${OBJECTDIR}/Pais.o: Pais.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pais.o Pais.cpp

${OBJECTDIR}/PaisDestino.o: PaisDestino.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PaisDestino.o PaisDestino.cpp

${OBJECTDIR}/RegistrarUsuarioBusiness.o: RegistrarUsuarioBusiness.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegistrarUsuarioBusiness.o RegistrarUsuarioBusiness.cpp

${OBJECTDIR}/RegistrarUsuarioData.o: RegistrarUsuarioData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegistrarUsuarioData.o RegistrarUsuarioData.cpp

${OBJECTDIR}/Usuario.o: Usuario.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Usuario.o Usuario.cpp

${OBJECTDIR}/Validar.o: Validar.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Validar.o Validar.cpp

${OBJECTDIR}/VentanaAdministracion.o: VentanaAdministracion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaAdministracion.o VentanaAdministracion.cpp

${OBJECTDIR}/VentanaEscogerAerolinea.o: VentanaEscogerAerolinea.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaEscogerAerolinea.o VentanaEscogerAerolinea.cpp

${OBJECTDIR}/VentanaIniciarSesion.o: VentanaIniciarSesion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaIniciarSesion.o VentanaIniciarSesion.cpp

${OBJECTDIR}/VentanaLogAdmin.o: VentanaLogAdmin.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaLogAdmin.o VentanaLogAdmin.cpp

${OBJECTDIR}/VentanaPrincipal.o: VentanaPrincipal.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaPrincipal.o VentanaPrincipal.cpp

${OBJECTDIR}/VentanaRegistrar.o: VentanaRegistrar.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaRegistrar.o VentanaRegistrar.cpp

${OBJECTDIR}/VentanaTransito.o: VentanaTransito.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaTransito.o VentanaTransito.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyectofinalalgoritmos

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
