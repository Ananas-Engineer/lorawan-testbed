## Start MQTT bridge

outside = host machine.  
inside = container.

1. outside > `node emqx-tts-bridge-generator.js '{tts_version}'`.
2. outside > `docker cp ./emqx_bridge_mqtt.conf {emqx_docker_id}:/opt/emqx/etc/plugins`
3. outside > `docker exec -it <emqx_docker_id> /bin/sh`
4. inside > `emqx_ctl plugins load emqx_bridge_mqtt`
5. inside > `emqx_ctl bridges start tts`  

`tts_version` can be empty if you choose to run AU1 cloud, or can be `tts-os` if you want to run locally.
