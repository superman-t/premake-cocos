# 精简cocos2d-x 3.16
将cocos2d-x 3.16版本源码进行精简，只保留基础的ui功能，同时删除不必要的第三方库以及将第三方库使用源码代替
同时使用premake代替cmake的构建工具
一下为源码和简化后的对比
![](image/cocos2dx.png)  
external库的简化对比  
   | **三方库**   |  **cocos2d-x 3.16**  | **简化后的ui版本** |
   | :-------: | :--------------: | :------------: |
   | **external** | **android-specific<br>Box2D<br>bullet<br>chipmunk<br>clipper<br>ConvertUTF<br>curl<br>edtaa3func<br>flatbuffers<br>freetype2<br>glfw3<br>jpeg<br>json<br>linux-specific<br>md5<br>openssl<br>png<br>poly2tri<br>rapidxml<br>recast<br>spidermonkey<br>sqlite3<br>tiff<br>tinydir<br>tinyxml2<br>unzip<br>webp<br>websockets<br>win10-specific<br>win32-specific<br>xxhash<br>xxtea<br>zlib<br>**|  **clipper<br>ConvertUTF<br>edtaa3func<br>poly2tri<br>rapidxml<br>tinydir<br>tinyxml2<br>unzip<br>versions.txt<br>xxhash<br>zlib<br>** |


