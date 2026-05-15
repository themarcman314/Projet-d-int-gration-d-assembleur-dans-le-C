#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_CONF=default
CND_DISTDIR=dist
TMPDIR=build/${CND_CONF}/${IMAGE_TYPE}/tmp-packaging
TMPDIRNAME=tmp-packaging
<<<<<<< HEAD
OUTPUT_PATH=dist/${CND_CONF}/${IMAGE_TYPE}/bhgfd.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
OUTPUT_BASENAME=bhgfd.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
PACKAGE_TOP_DIR=bhgfd.x/
=======
OUTPUT_PATH=dist/${CND_CONF}/${IMAGE_TYPE}/blinky.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
OUTPUT_BASENAME=blinky.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
PACKAGE_TOP_DIR=blinky.x/
>>>>>>> source_project/master

# Functions
function checkReturnCode
{
    rc=$?
    if [ $rc != 0 ]
    then
        exit $rc
    fi
}
function makeDirectory
# $1 directory path
# $2 permission (optional)
{
    mkdir -p "$1"
    checkReturnCode
    if [ "$2" != "" ]
    then
      chmod $2 "$1"
      checkReturnCode
    fi
}
function copyFileToTmpDir
# $1 from-file path
# $2 to-file path
# $3 permission
{
    cp "$1" "$2"
    checkReturnCode
    if [ "$3" != "" ]
    then
        chmod $3 "$2"
        checkReturnCode
    fi
}

# Setup
cd "${TOP}"
mkdir -p ${CND_DISTDIR}/${CND_CONF}/package
rm -rf ${TMPDIR}
mkdir -p ${TMPDIR}

# Copy files and create directories and links
cd "${TOP}"
<<<<<<< HEAD
makeDirectory ${TMPDIR}/bhgfd.x/bin
=======
makeDirectory ${TMPDIR}/blinky.x/bin
>>>>>>> source_project/master
copyFileToTmpDir "${OUTPUT_PATH}" "${TMPDIR}/${PACKAGE_TOP_DIR}bin/${OUTPUT_BASENAME}" 0755


# Generate tar file
cd "${TOP}"
<<<<<<< HEAD
rm -f ${CND_DISTDIR}/${CND_CONF}/package/bhgfd.x.tar
cd ${TMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/package/bhgfd.x.tar *
=======
rm -f ${CND_DISTDIR}/${CND_CONF}/package/blinky.x.tar
cd ${TMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/package/blinky.x.tar *
>>>>>>> source_project/master
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${TMPDIR}
