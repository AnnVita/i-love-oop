set PROGRAM="%~1"

%PROGRAM% test.txt %TEMP%\needle1replace1.txt "y" "1"
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\needle1replace1.txt standart_Needle1Replace1.txt
if ERRORLEVEL 1 goto err

%PROGRAM% test.txt %TEMP%\needle1replaceN.txt "," "..."
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\needle1replaceN.txt standart_Needle1ReplaceN.txt
if ERRORLEVEL 1 goto err

%PROGRAM% test.txt %TEMP%\needleNreplace1.txt "game" "1"
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\needleNreplace1.txt standart_NeedleNReplace1.txt
if ERRORLEVEL 1 goto err

%PROGRAM% test.txt %TEMP%\needleNreplaceN.txt "yesterday" "tomorrow"
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\needleNreplaceN.txt standart_NeedleNReplaceN.txt
if ERRORLEVEL 1 goto err 

%PROGRAM% test.txt %TEMP%\needleNreplaceEMPTY.txt "yesterday" ""
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\needleNreplaceEMPTY.txt standart_NeedleNReplaceEMPTY.txt
if ERRORLEVEL 1 goto err

%PROGRAM% test.txt %TEMP%\errNeedleEMPTY.txt "" "yesterday" > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt standart_errNeedleEMPTY.txt
if ERRORLEVEL 1 goto err

%PROGRAM% not-exists.txt %TEMP%\errReadFile.txt "yesterday" "1" > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt standart_errReadFile.txt
if ERRORLEVEL 1 goto err

%PROGRAM% test.txt z:\not-exists.txt "yesterday" "1" > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt standart_errWriteFile.txt
if ERRORLEVEL 1 goto err

%PROGRAM% > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt standart_errNumParameters.txt
if ERRORLEVEL 1 goto err

%PROGRAM% numtest.txt %TEMP%\numtest.txt "1231234" "sucsess"
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\numtest.txt standart_numtest.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1