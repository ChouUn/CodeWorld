::IF EXIST "D:\Hexo\source\code\Template" (
::    rmdir "D:\Hexo\source\code\Template" /s /q
::)
xcopy /E /Y /I "D:\Users\Documents\WorkSpaceCpp\CodeWorld\Template" "D:\Hexo\source\code\Template"
xcopy /E /Y /I "D:\Users\Documents\WorkSpaceCpp\CodeWorld\Library" "D:\Hexo\source\code\Library"