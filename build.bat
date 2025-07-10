@echo off
g++ main.cpp Book.cpp User.cpp Student.cpp Library.cpp FileManager.cpp -o library.exe
if %errorlevel% neq 0 (
    echo ❌ Build failed!
) else (
    echo ✅ Build succeeded!
    library.exe
)
pause
