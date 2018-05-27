local external = {}

local postfix = {"h", "hpp", "c", "cpp", "cc"}

local thirdLib = {
	"clipper",
	"ConvertUTF",
	"edtaa3func",
	"md5",
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
	"**/tvos/**",
	"**/win10/**",	
	"**/android/**",
	"**/apple/**", 
	"**/ios/**" ,
	"**/linux/**" ,
	"**/mac/**" ,
	"**/tizen/**" ,
	"**/win8.1-universal/**",
	"**/winrt/**",  
}

return external