local platform = {}

platform.excludes = {
	"**/android/**",
	"**/apple/**", 
	"**/ios/**" ,
	"**/linux/**" ,
	"**/mac/**" ,
	"**/tizen/**" ,
	"**/win8.1-universal/**",
	"**/winrt/**",  
}

platform.src = {
	"cocos/platform/*",


	"cocos/platform/win32/*",

	"cocos/platform/desktop/*",
}

return platform