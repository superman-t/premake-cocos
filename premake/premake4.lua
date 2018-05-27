local cocos2d = require "cocos.2d"
local base = require "cocos.base"
local deprecated = require "cocos.deprecated"
local editor_support = require "cocos.editor-support"
local math = require "cocos.math"
local platform = require "cocos.platform"
local renderer = require "cocos.renderer"
local ui = require "cocos.ui"
local extensions = require "premake-extensions"
local external = require "premake-external"

local key = ""
local function PrintTable(tb, level)
	level = level or 1
	local indent = ""
	for i = 1, level do
		indent = indent .. "  "
	end

	if key ~= "" then
		print(indent .. key .. " " .. "=" .. " " .. "{")
	else
		print(indent .. "{")
	end

	key = ""
	for k, v in pairs(tb) do
		if type(v) == "table" then
			key = k
			PrintTable(v, level + 1)
		else
			local content = string.format("%s%s = %s", indent .. "  ", tostring(k), tostring(v))
			print(content)
		end
	end
	print(indent .. "}")
end


local rootDir = "../"
function AddFiles(t) 
	local fileLists = {}
	local excludeLists = {}

	if t.src then
		for _, v in pairs(t.src) do
			table.insert(fileLists, rootDir .. v)
		end
	end

	if t.excludes then
		for _, v in pairs(t.excludes) do
			table.insert(excludeLists, rootDir .. v)
		end
	end

	files    ( fileLists )
	excludes ( excludeLists )
end

-- Adds include directories to the project.
function AddIncludes( includeDirList, rootdir )
	for _, includeDir in ipairs( includeDirList ) do
		includedirs { rootdir .."/" .. includeDir }
	end
end


local includeDirs = {
	"external/win32-specific/gles/include/OGLES",
	"external/sqlite3/include",
	"external/unzip",
	"external/edtaa3func",
	"external/tinyxml2",
	"external/png/include/win32",
	"external/jpeg/include/win32",
	"external/tiff/include/win32",
	"external/webp/include/win32",
	"external/freetype2/include/win32",
	"external/win32-specific/icon/inclue",
	"external/win32-specific/zlib/include",
	"external/xxhash",
	"external/ConvertUTF",
	"external/curl/include/win32",
	"external/websockets/include/win32",
	"external/poly2tri/common",
	"external/poly2tri/sweep",
	"external/poly2tri",
	"external/GLEW/include",
	"external",
	"cocos",
	"cocos/2d",
	"cocos/base",
	"cocos/deprecated",
	"cocos/editor-support",
	"cocos/math",
	"cocos/platform",
	"cocos/platform/win8.1-universal",
	"cocos/platform/win32",
	"cocos/renderer",
	"cocos/ui",
	"extensions",
	"external/glfw3/include/win32",
	"external/win32-specific/gles/include/OGLES",
	"external/freetype2/include/win32/freetype2",
	"external/freetype2/include/win32/",
	"external/openssl/include/win32",

}

-- Sets target output directories.
function SetTargetDirectories()
	local platformName = "Debug"

	local binLocation = "Bin/"
	local libLocation = "Lib/"

	os.mkdir (binLocation)
	os.mkdir (libLocation)

	configuration { platformName, "SharedLib or ConsoleApp or WindowedApp" }
	targetdir     ( binLocation )

	configuration { platformName, "StaticLib" }
	targetdir     ( libLocation )


	configuration { platformName, "SharedLib" }
	implibdir     ( libLocation )


end


solution "cocos2d"
	location "build"
	language   "C++"
	cxxdialect "C++11"
	configuration {"Debug", "Release"}

	flags { "ExtraWarnings", "FatalWarnings", "RuntimeSearchPath", "Symbols" }
	objdir ( "../Temp/" )
	configuration {}
		flags { "NoMinimalRebuild" }
		buildoptions { "/MP" }
		defines { "_ALLOW_RTCc_IN_STL" }


project "libcocos2d"
	uuid "ac6b5c42-0acb-454f-a44c-0f215f1d39a5"
	kind "SharedLib"
	configurations { "Debug", "Release" }
	defines {"_USRDLL", "_DEBUG", "_WIN32", "WIN32", "_WINDOWS", "WINDOWS", "_LIB", "LWS_DLL",
				"COCOS2DXWIN32_EXPORTS", "GL_GLEXT_PROTOTYPES", "COCOS2D_DEBUG=1", "_CRT_SECURE_NO_WARNINGS",
				"_SCL_SECURE_NO_WARNINGS", "_EXPORT_DLL_", "_USRSTUDIODLL", "_USREXDLL", "_USEGUIDLL",
				"_VARIADIC_MAX=10", "_WINDLL", "_UNICODE", "UNICODE"
			}

	links {"opengl32", "glew32", "libzlib", "libwebp", "freetype", "winmm", "ws2_32"}

	libdirs { "Lib"}
	includedirs { "../external/**/prebuilt/**" }
	flags { "NoMinimalRebuild" }
	linkoptions { "/NODEFAULTLIB:LIBCMT" }
	
	links {"version"}


	AddIncludes(includeDirs, "../")
	AddFiles(cocos2d)
	AddFiles(base)
	AddFiles(deprecated)
	AddFiles(editor_support)
	AddFiles(math)
	AddFiles(platform)
	AddFiles(renderer)
	AddFiles(ui)
	AddFiles(extensions)
	AddFiles(external)

	SetTargetDirectories()
	buildoptions { 
		"/wd4251",
		"/wd4244",
		"/wd4334",
		"/wd4005",
		"/wd4820",
		"/wd4710",
		"/wd4514",
		"/wd4056",
		"/wd4996",
		"/wd4099",
	}

	os.copyfile("../external/win32-specific/zlib/prebuilt/libzlib.lib", "Lib/libzlib.lib")
	os.copyfile("../external/win32-specific/gles/prebuilt/glew32.lib", "Lib/glew32.lib")
	os.copyfile("../external/win32-specific/icon/prebuilt/libiconv.lib", "Lib/libiconv.lib")
	os.copyfile("../external/webp/prebuilt/win32/libwebp.lib", "Lib/libwebp.lib")
	os.copyfile("../external/tiff/prebuilt/win32/libtiff.lib", "Lib/libtiff.lib")
	os.copyfile("../external/tiff/prebuilt/win32/libtiff-2015.lib", "Lib/libtiff-2015.lib")
	os.copyfile("../external/png/prebuilt/win32/libpng.lib", "Lib/libpng.lib")
	os.copyfile("../external/png/prebuilt/win32/libpng-2015.lib", "Lib/libpng-2015.lib")
	os.copyfile("../external/freetype2/prebuilt/win32/freetype.lib", "Lib/freetype.lib")
	os.copyfile("../external/jpeg/prebuilt/win32/libjpeg.lib", "Lib/libjpeg.lib")
	os.copyfile("../external/jpeg/prebuilt/win32/libjpeg-2015.lib", "Lib/libjpeg-2015.lib")
	os.copyfile("../external/glfw3/prebuilt/win32/glfw.lib", "Lib/glfw3.lib")
	os.copyfile("../external/glfw3/prebuilt/win32/glfw3-2015.lib", "Lib/glfw3-2015.lib")

	configuration {"Debug"}
		buildoptions { "/MDd" }

	configuration {"Release"}
		buildoptions { "/MD" }


project "CocosCreatorDemo"
	uuid "c44ce759-b702-40bb-a67c-7951810c84aa"
	kind "WindowedApp"
	
	defines { "_DEBUG", "_WINDOWS", "WINDOWS","COCOS2D_DEBUG=1", "_CRT_SECURE_NO_WARNINGS",
				"_SCL_SECURE_NO_WARNINGS"
			}
	links {"libcocos2d"}
	libdirs {"Lib"}
	AddIncludes(includeDirs, "../")
	includedirs { "../tests/cpp-empty-test/Classes", "../tests/cpp-empty-test/Classes/reader" }

	files { "../tests/cpp-empty-test/Classes/**", "../tests/cpp-empty-test/proj.win32/main.**"}
	vpaths      { ["*"] = "../tests/cpp-empty-test/**" }
	SetTargetDirectories()

	os.copyfile("../external/win32-specific/gles/prebuilt/glew32.dll", "Bin/glew32.dll")
	os.execute( 'xcopy /Q /E /Y /I ' .. "..\\tests\\cpp-empty-test\\Resources" .. ' ' .. "Bin\\Resources")

	configuration {"Debug"}
		buildoptions { "/MDd", "/DEBUG" }

	configuration {"Release"}
		buildoptions { "/MD" }
