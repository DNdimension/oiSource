@echo off
setlocal enabledelayedexpansion
set MY=%1
set REF=%2
if "%MY%"==""  set MY=my.cpp
if "%REF%"=="" set REF=ref.cpp
set MAX_SEED=3000

g++ -O2 -std=c++17 -o gen.exe   gen.cpp   || (echo gen compile fail & exit /b 1)
g++ -O2 -std=c++17 -o brute.exe brute.cpp || (echo brute compile fail & exit /b 1)
g++ -O2 -std=c++17 -o my.exe    %MY%      || (echo my compile fail & exit /b 1)
g++ -O2 -std=c++17 -o ref.exe   %REF%     || (echo ref compile fail & exit /b 1)

for /L %%s in (0,1,%MAX_SEED%) do (
    gen.exe %%s > in.txt
    my.exe    < in.txt > out_my.txt
    ref.exe   < in.txt > out_ref.txt
    brute.exe < in.txt > out_brute.txt

    fc /b out_my.txt out_ref.txt > nul
    if errorlevel 1 (
        echo ===== seed=%%s : 你 vs 题解 不一致 =====
        echo --- 输入 ---
        type in.txt
        echo --- 你的输出 ---
        type out_my.txt
        echo --- 题解输出 ---
        type out_ref.txt
        echo --- 暴力输出 ---
        type out_brute.txt
        exit /b 1
    )
    fc /b out_ref.txt out_brute.txt > nul
    if errorlevel 1 (
        echo ===== seed=%%s : 题解 vs 暴力 不一致 =====
        echo --- 输入 ---
        type in.txt
        echo --- 题解输出 ---
        type out_ref.txt
        echo --- 暴力输出 ---
        type out_brute.txt
        exit /b 1
    )
)
echo 全部随机数据通过