/*
    Copyright (C) 2015  Intel Corporation

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef CLOVERVIEWOPTIONS_H
#define CLOVERVIEWOPTIONS_H

#include <string>
#include "../../interfaces/ioptions.h"
#include <boost/program_options.hpp>

using namespace std;
using namespace boost::program_options;

class CloverviewOptions : public IOptions
{
private:
    string fwDnxPath;
    string fwImagePath;
    string osDnxPath;
    string osImagePath;
    string miscDnxPath;
    unsigned int gpFlags;
    unsigned int debugLevel;
    unsigned int usbdelayms;
    unsigned int targetIndex;
    int readWriteTimeout;
    string transferType;
    bool idrqEnabled;
    bool isVerbose;    
	bool wipeifwi;
    bool downloadFW;
    bool downloadOS;
    bool isActionRequired;
    void UpdateFlags();
    bool allPathsAreValid();
    void ParseLegacy(int, char*[]);
public:
    CloverviewOptions();
    void SetDefaults();
    void Parse(int, char*[]);
    void Clear();
    void PrintAllOptions();
    DeviceTransportType GetTransportType();
    const char* GetFWDnxPath();
    const char* GetFWImagePath();
    const char* GetOSDnxPath();
    const char* GetOSImagePath();
    const char* GetMiscDnxPath();
    unsigned int GetTarget();
    unsigned int GetGPFlags();
    unsigned int GetDebugLevel();
    unsigned int GetUsbdelayms();
    int GetReadWriteTimeout() {return readWriteTimeout;}
    const char* GetTransferType();
    const char* GetQuery();
    bool IsIdrqEnabled();
    bool IsFWDownload();
    bool IsOSDownload();
    bool IsQuery();
    bool IsActionRequired();
    bool IsVerbose();
    bool IsWipeIfwiEnabled();
};
#endif // CLOVERVIEWOPTIONS_H
