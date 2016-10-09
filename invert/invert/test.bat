set PROGRAM="%~1"

%PROGRAM% > %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_invalidArgumentCount.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "not_exists.txt" > %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_inputIsMissing.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "empty_file.txt"> %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt stantart_empty.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "reading_fail.txt"> %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_readingFail.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "zero_det.txt"> %TEMP%\out.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_zeroDet.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "input.txt"> %TEMP%\out.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_output.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "input1.txt"> %TEMP%\out.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\out.txt standart_output1.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1