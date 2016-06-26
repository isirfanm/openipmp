# Microsoft Developer Studio Project File - Name="OMADRMEncCommHandlerFactory" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=OMADRMEncCommHandlerFactory - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OMADRMEncCommHandlerFactory.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OMADRMEncCommHandlerFactory.mak" CFG="OMADRMEncCommHandlerFactory - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OMADRMEncCommHandlerFactory - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OMADRMEncCommHandlerFactory - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OMADRMEncCommHandlerFactory - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Build\Win32\VC6\Release"
# PROP Intermediate_Dir "Build\Win32\VC6\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OMADRMENCCOMMHANDLERFACTORY_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../ThreadSyncFactory" /I "../../OMADRM/OMADRMCrypto" /I "../../OMADRM/OMADRMCommon" /I "../../OMADRM/Test/OMADRMServer" /I "../../XMLFactory" /I "../../OMADRM/ROAPParser" /I "../../OMADRM/include" /I "../../OMADRM/ROAP" /I "../include" /I "../../OMADRM/Test/OMADRMMQEncCommHandler" /I "../../include" /I "../../../../ext/axis-c/include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OMADRMENCCOMMHANDLERFACTORY_EXPORTS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x41a /d "NDEBUG"
# ADD RSC /l 0x41a /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 ../../../../ext/axis-c/lib/win32/VC6/AxisClient.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "OMADRMEncCommHandlerFactory - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Build\Win32\VC6\Debug"
# PROP Intermediate_Dir "Build\Win32\VC6\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OMADRMENCCOMMHANDLERFACTORY_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../ThreadSyncFactory" /I "../../OMADRM/OMADRMCrypto" /I "../../OMADRM/OMADRMCommon" /I "../../OMADRM/Test/OMADRMServer" /I "../../XMLFactory" /I "../../OMADRM/ROAPParser" /I "../../OMADRM/include" /I "../../OMADRM/ROAP" /I "../include" /I "../../OMADRM/Test/OMADRMMQEncCommHandler" /I "../../include" /I "../../../../ext/axis-c/include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "OMADRMENCCOMMHANDLERFACTORY_EXPORTS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x41a /d "_DEBUG"
# ADD RSC /l 0x41a /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ../../../../ext/axis-c/lib/win32/VC6/AxisClient_D.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "OMADRMEncCommHandlerFactory - Win32 Release"
# Name "OMADRMEncCommHandlerFactory - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\OMADRMEncCommHandlerFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\OMADRMWS.cpp
# End Source File
# Begin Source File

SOURCE=.\OMADRMWSEncCommHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\WSAddContentKeyRequest.cpp
# End Source File
# Begin Source File

SOURCE=.\WSAddContentKeyResponse.cpp
# End Source File
# Begin Source File

SOURCE=.\WSAddDeviceRightsRequest.cpp
# End Source File
# Begin Source File

SOURCE=.\WSAddDeviceRightsResponse.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\OMADRMEncCommHandlerFactory.h
# End Source File
# Begin Source File

SOURCE=.\OMADRMWS.hpp
# End Source File
# Begin Source File

SOURCE=.\OMADRMWSEncCommHandler.h
# End Source File
# Begin Source File

SOURCE=.\WSAddContentKeyRequest.hpp
# End Source File
# Begin Source File

SOURCE=.\WSAddContentKeyResponse.hpp
# End Source File
# Begin Source File

SOURCE=.\WSAddDeviceRightsRequest.hpp
# End Source File
# Begin Source File

SOURCE=.\WSAddDeviceRightsResponse.hpp
# End Source File
# End Group
# End Target
# End Project
