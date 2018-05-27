local editor_support = {}

editor_support.src = {
	"cocos/editor-support/**.h",
	"cocos/editor-support/**.cpp",
}

editor_support.excludes = {
	"cocos/editor-support/fbs-files/**.h",
	"cocos/editor-support/fbs-files/**.cpp",
}

return editor_support