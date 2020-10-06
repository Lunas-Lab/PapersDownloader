@ECHO OFF
%2%
cd %3%
if exist %4% (
cd %4%
) else (
mkdir %4%
cd %4%
)
curl --ssl-no-revoke %1 --remote-name
