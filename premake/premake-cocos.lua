local cocos2d = {}
local cocos2d_external = require("premake-external")

cocos2d.src = {
	"cocos/cocos2d.**",
	"cocos/**",
}

cocos2d.excludes = {
	"**tvos**",
	"**win10**",	
	"**android**",
	"**apple**", 
	"**ios**" ,
	"**linux**" ,
	"**mac**" ,
	"**tizen**" ,
	"**winrt**",  
	"**/android/**",
	"**/apple/**", 
	"**/ios/**" ,
	"**/linux/**" ,
	"**/mac/**" ,
	"**/tizen/**" ,
	"**/win8.1-universal/**",
	"**/winrt/**", 
	"**/iOS/**",
	"**/Mac/**",
}

cocos2d.includes = {
	"cocos",
	"cocos/2d",
	"cocos/base",
	"cocos/math",
	"cocos/platform",
	"cocos/platform/win32",
	"cocos/renderer",
	"cocos/ui",
}


local function AddFiles(t) 
	local rootDir = "../"
	local fileLists = {}
	local includeList = {}
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

	table.insert( includeList, rootDir)
	for _, include in pairs( t.includes ) do
		table.insert(includeList, rootDir .. include)
	end

	files    	( fileLists )
	includedirs ( includeList )
	excludes 	( excludeLists )
end
cocos2d.AddFiles = AddFiles

-- Sets target output directories.
if not SetTargetDirectories then
	function SetTargetDirectories()
		local platformName = { "Debug", "Release"}

		local binLocation = "Bin/"
		local libLocation = "Lib/"

		os.mkdir (binLocation)
		os.mkdir (libLocation)
		for _, platform in pairs (platformName) do
			configuration { platform, "SharedLib or ConsoleApp or WindowedApp" }
			targetdir     ( binLocation )

			configuration { platform, "StaticLib" }
			targetdir     ( libLocation )

			configuration { platform, "SharedLib" }
			implibdir     ( libLocation )
		end
	end
end
cocos2d.SetTargetDirectories = SetTargetDirectories

local function CopyFiles(src, des)
	if os.get() == "windows" then
		src = string.gsub(src, "/", "\\")
		des = string.gsub(des, "/", "\\")
		if os.isdir(src) then
			os.execute( "xcopy /y /s /e /q /i " .. src .. " " .. des )
		else
			os.copyfile(src, des)
		end
	else
		print("other")
		src = string.gsub(src, "\\", "/")
		des = string.gsub(des, "\\", "/")
		os.execute( "cp -rf " .. src .. " " .. des)
	end
end
cocos2d.CopyFiles = CopyFiles

project "libcocos2d"
	uuid "ac6b5c42-0acb-454f-a44c-0f215f1d39a5"
	kind "SharedLib"
	configurations { "Debug", "Release" }
	defines {"_USRDLL", "_DEBUG", "WIN32", "_WINDOWS", "WINDOWS", "_LIB", "LWS_DLL",
				"COCOS2DXWIN32_EXPORTS", "GL_GLEXT_PROTOTYPES", "COCOS2D_DEBUG=1", "_CRT_SECURE_NO_WARNINGS",
				"_SCL_SECURE_NO_WARNINGS", "_EXPORT_DLL_", "_USRSTUDIODLL", "_USREXDLL", "_USEGUIDLL",
				"_VARIADIC_MAX=10", "_WINDLL", "_UNICODE", "UNICODE"
			}

	links {"opengl32", "glew32", "libzlib", "libwebp", "freetype", "winmm", "ws2_32", "version"}
	libdirs { "Lib"}
	flags {  "Symbols" }
	linkoptions { "/NODEFAULTLIB:LIBCMT" }
	buildoptions {
		"/wd4305", 
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
	
	AddFiles(cocos2d)
	AddFiles(cocos2d_external)
	SetTargetDirectories()
	

	CopyFiles("../external/win32-specific/zlib/prebuilt/libzlib.lib", "Lib/libzlib.lib")
	CopyFiles("../external/win32-specific/gles/prebuilt/glew32.lib", "Lib/glew32.lib")
	CopyFiles("../external/win32-specific/icon/prebuilt/libiconv.lib", "Lib/libiconv.lib")
	CopyFiles("../external/webp/prebuilt/win32/libwebp.lib", "Lib/libwebp.lib")
	CopyFiles("../external/freetype2/prebuilt/win32/freetype.lib", "Lib/freetype.lib")
	if _ACTION >= "vs2015" then
		CopyFiles("../external/tiff/prebuilt/win32/libtiff-2015.lib", "Lib/libtiff-2015.lib")
		CopyFiles("../external/png/prebuilt/win32/libpng-2015.lib", "Lib/libpng-2015.lib")
		CopyFiles("../external/jpeg/prebuilt/win32/libjpeg-2015.lib", "Lib/libjpeg-2015.lib")
		CopyFiles("../external/glfw3/prebuilt/win32/glfw3-2015.lib", "Lib/glfw3-2015.lib")
	else
		CopyFiles("../external/tiff/prebuilt/win32/libtiff.lib", "Lib/libtiff.lib")
		CopyFiles("../external/png/prebuilt/win32/libpng.lib", "Lib/libpng.lib")
		CopyFiles("../external/jpeg/prebuilt/win32/libjpeg.lib", "Lib/libjpeg.lib")
		CopyFiles("../external/glfw3/prebuilt/win32/glfw.lib", "Lib/glfw3.lib")
	end

	configuration {"Debug"}
		buildoptions { "/MDd", "/Zi", "/Gm" }

	configuration {"Release"}
		buildoptions { "/MD", "/Zi", "/Gm" }

return cocos2d