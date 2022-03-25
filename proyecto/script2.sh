
#!/usr/bin/bash

apikey=YK5V80N64DAMNWR6

bitcoinInUsdString=$(/usr/bin/curl -s --location --request GET 'api.coincap.io/v2/assets/bitcoin' |/usr/bin/jq '.data.priceUsd') 

bitcoinInUsd=`echo "${bitcoinInUsdString}" |bc`

echo " bitcoin in dollars: $bitcoinInUsd"

isCorrect=$(/usr/bin/curl -s https://api.thingspeak.com/update?api_key=${apikey}\&field1=${bitcoinInUsd})

if [ $isCorrect -gt 0 ]; then
	echo "valor enviado"
else
	echo "fallo el envio"

fi
