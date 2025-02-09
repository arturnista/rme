//////////////////////////////////////////////////////////////////////
// This file is part of Remere's Map Editor
//////////////////////////////////////////////////////////////////////
// Remere's Map Editor is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Remere's Map Editor is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////

#ifndef RME_MAIN_H_
#define RME_MAIN_H_

#ifdef _WIN32
#	define WIN32_LEAN_AND_MEAN
#	ifdef _WIN32_WINNT
#		undef _WIN32_WINNT
#	endif
#	define _WIN32_WINNT 0x0501
#endif

#ifdef DEBUG_MEM

#define _CRTDBG_MAP_ALLOC

#pragma warning(disable: 4291)
_Ret_bytecap_(_Size) inline void * __CRTDECL operator new(size_t _Size, const char* file, int line)
        { return ::operator new(_Size, _NORMAL_BLOCK, file, line); }
_Ret_bytecap_(_Size) inline void* __CRTDECL operator new[](size_t _Size, const char* file, int line)
        { return ::operator new[](_Size, _NORMAL_BLOCK, file, line); }
#define newd new(__FILE__, __LINE__)

#else

#define newd new

#endif

#include <wx/defs.h>
#include "definitions.h"

#include <asio.hpp>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include <wx/thread.h>
#include <wx/utils.h>
#include <wx/progdlg.h>
#include <wx/glcanvas.h>
#include <wx/debugrpt.h>
#include <wx/minifram.h>
#include <wx/gbsizer.h>
#include <wx/choicebk.h>
#include <wx/tglbtn.h>
#include <wx/dcbuffer.h>
#include <wx/aui/aui.h>
#include <wx/cmdline.h>
#include <wx/filename.h>
#include <wx/filepicker.h>
#include <wx/arrstr.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/wxhtml.h>
#include <wx/vlbox.h>
#include <wx/stdpaths.h>
#include <wx/url.h>
#include <wx/ipc.h>
#include <wx/grid.h>
#include <wx/clipbrd.h>

// PugiXML
#include "ext/pugixml.hpp"

// Libarchive, for OTGZ
#if OTGZ_SUPPORT > 0
#include <archive.h>
#include <archive_entry.h>
#endif

// This has annoyed me one time too many
#define wxANY_ID (wxID_ANY)

#include <assert.h>
#define _MSG(msg) !bool(msg)
#ifdef __DEBUG__
#   define ASSERT assert
#else
#   define ASSERT(...)
#endif

// The complete STL ?, well, almost ;)
#include <math.h>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <istream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <set>
#include <queue>
#include <stdexcept>
#include <stdlib.h>
#include <crtdbg.h>
#include <time.h>
#include <fstream>
#include <memory>
#include <exception>
#include <cmath>
#include <ranges>
#include <regex>

typedef std::vector<std::string> StringVector;
typedef wxFileName FileName;

#include "con_vector.h"
#include "common.h"
#include "threads.h"

#include "const.h"
#include "rme_forward_declarations.h"

#if wxCHECK_VERSION(3, 1, 0)
        #define FROM_DIP(widget, size) widget->FromDIP(size)
#else
        #define FROM_DIP(widget, size) size
#endif

#endif
