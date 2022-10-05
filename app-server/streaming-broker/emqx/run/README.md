## Start EMQX container
0. Change configuration related to EMQX at `common/emqx.json`, mainly `SERVER_ADDR` and connection ports.
1. Then start the EMQX container.
```
bash ./run.sh
```
2. After starting, you can access EMQX via Web browser at `http://{SERVER_ADDR}:18083`.
3. Please check other connection ports such as MQTT, WebSocket at `common/emqx.json`.
