
#!/usr/bin/bash

bitcoinInUsdString=$(/usr/bin/curl -s --location --request GET 'api.coincap.io/v2/assets/bitcoin' |/usr/bin/jq '.data.priceUsd') 

bitcoinInUsd=`echo "${bitcoinInUsdString}" | /usr/bin/bc`

echo $bitcoinInUsd


