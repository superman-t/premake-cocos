solution "cocos2d"
	location "build"
	language   "C++"
	cxxdialect "C++11"
	configuration {"Debug", "Release"}

	flags { "ExtraWarnings", "FatalWarnings", "RuntimeSearchPath", "Symbols" }
	objdir ( "../Temp" )

	buildoptions { "/MP" }
	defines { "_ALLOW_RTCc_IN_STL" }

if os.get() == "windows" then
	local cocos2d = require("premake-cocos")
	local cocos2d_external = require("premake-external")
	project "CocosCreatorDemo"
		uuid "c44ce759-b702-40bb-a67c-7951810c84aa"
		kind "WindowedApp"
		
		defines { "_DEBUG", "_WINDOWS", "WINDOWS","COCOS2D_DEBUG=1", "_CRT_SECURE_NO_WARNINGS",
					"_SCL_SECURE_NO_WARNINGS"
				}
		links {"libcocos2d"}
		libdirs {"Lib"}
		flags { "WinMain", "Symbols" }
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
			"/wd4503",
		}

		cocos2d.AddFiles({includes = cocos2d.includes})
		cocos2d.AddFiles({includes = cocos2d_external.includes})
		includedirs { "../tests/cpp-empty-test/Classes", "../tests/cpp-empty-test/Classes/reader" }

		files { "../tests/cpp-empty-test/Classes/**", "../tests/cpp-empty-test/proj.win32/main.**"}
		vpaths      { ["*"] = "../tests/cpp-empty-test/**" }

		cocos2d.SetTargetDirectories()

		cocos2d.CopyFiles("../external/win32/libs/glew32.dll", "Bin/glew32.dll")
		cocos2d.CopyFiles("../tests/cpp-empty-test/Resources", "Bin/Resources")

		configuration {"Debug"}
			buildoptions { "/MDd", "/Zi", "/Gm"}

		configuration {"Release"}
			buildoptions { "/MD","/Zi", "/Gm" }

	project "LuaEmetyDemo"
		uuid "fe48a1b4-8f0c-11e8-9eb6-529269fb1459"
		kind "WindowedApp"

		defines { "_DEBUG", "_WINDOWS", "WINDOWS","COCOS2D_DEBUG=1", "_CRT_SECURE_NO_WARNINGS",
					"_SCL_SECURE_NO_WARNINGS", "_USRLUASTATIC", "STRICT"
				}

		links {"libcocos2d", "libluacocos2d", "glew32", "opengl32", "ws2_32"}

		libdirs {"Lib"}
		flags { "WinMain", "Symbols"}
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
			"/wd4503",
		}

		cocos2d.AddFiles({includes = cocos2d.includes})
		cocos2d.AddFiles({includes = cocos2d_external.includes})

		includedirs { "../external/sources/lua/tolua", "../external/sources/lua/lua", "../external/sources/lua", "../external/sources/xxtea", "../cocos/scripting"}

		includedirs { "../tests/lua-empty-test/project/Classes"}
		files { "../tests/lua-empty-test/project/Classes/**", "../tests/lua-empty-test/project/proj.win32/main.**" }
		vpaths { ["*"] = "../tests/lua-empty-test/project/**"}

		cocos2d.SetTargetDirectories()

		cocos2d.CopyFiles("../external/win32/libs/glew32.dll", "Bin/glew32.dll")
		cocos2d.CopyFiles("../tests/lua-empty-test/res", "Bin/res")
		cocos2d.CopyFiles("../tests/lua-empty-test/src", "Bin/src")
		cocos2d.CopyFiles("../cocos/scripting/lua-bindings/script", "Bin/src/cocos")

		configuration {"Debug"}
			buildoptions { "/MDd", "/Zi", "/Gm"}

		configuration {"Release"}
			buildoptions { "/MD","/Zi", "/Gm" }



end