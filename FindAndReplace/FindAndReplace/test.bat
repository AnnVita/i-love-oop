set PROGRAM="%~1"

%PROGRAM% > %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_invalidArgumentCount.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "string" "line"> %TEMP%\out.txt < input.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_output.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "line" "none"> %TEMP%\out.txt < input.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_output1.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "string" ""> %TEMP%\out.txt < input.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_output2.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1