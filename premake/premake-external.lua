local external = {}

local postfix = {"h", "hpp", "c", "cpp", "cc"}

local thirdLib = {
	"clipper",
	"ConvertUTF",
	"edtaa3func",
	"poly2tri",
	"tinyxml2",
	"unzip",
	"xxhash",
}

external.src = {}

for _, dir in pairs(thirdLib) do
	for _, fix in pairs(postfix) do
		table.insert(external.src, "external/" .. dir .. "/**.".. fix)
	end
end

external.excludes = {

}

external.includes = {
	"external/unzip",
	"external/edtaa3func",
	"external/tinyxml2",
	"external/png/include/win32",
	"external/jpeg/include/win32",
	"external/tiff/include/win32",
	"external/webp/include/win32",
	"external/freetype/include/",
	"external/freetype/include/freetype",
	"external/win32-specific/icon/inclue",
	"external/win32-specific/zlib/include",
	"external/xxhash",
	"external/ConvertUTF",
	"external/poly2tri/common",
	"external/poly2tri/sweep",
	"external/poly2tri",
	"external",
	"external/glfw3/include/win32",
	"external/win32-specific/gles/include/OGLES",
}

return external