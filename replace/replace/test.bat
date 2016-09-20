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

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1