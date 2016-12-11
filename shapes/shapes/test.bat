set PROGRAM="%~1"

echo search the maximum area and minimum perimeter
%PROGRAM% filesForTest\input.txt > %TEMP%\out.txt
IF ERRORLEVEL 1 GOTO err
fc.exe %TEMP%\out.txt filesForTest\output.txt
IF ERRORLEVEL 1 GOTO err

echo empty or invalid file
%PROGRAM% filesForTest\empty.txt > %TEMP%\out.txt
IF ERRORLEVEL 1 GOTO err
fc.exe %TEMP%\out.txt filesForTest\emptyOut.txt
IF ERRORLEVEL 1 GOTO err

echo invalid number of parameters
%PROGRAM% > %TEMP%\out.txt
IF NOT ERRORLEVEL 1 GOTO err
fc.exe %TEMP%\out.txt filesForTest\invalidNumberOfParameters.txt
IF ERRORLEVEL 1 GOTO err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 