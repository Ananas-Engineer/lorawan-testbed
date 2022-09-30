## Start MQTT bridge

outside = host machine.  
inside = container.

1. outside > `node emqx-tts-bridge-generator.js '{tts_version}'`. `tts_version` can be `tts-os`
2. outside > `docker cp ./emqx_bridge_mqtt.conf {emqx_docker_id}:/opt/emqx/etc/plugins`
3. outside > `docker exec -it <emqx_docker_id> /bin/sh`
4. inside > `emqx_ctl plugins load emqx_bridge_mqtt`
5. inside > `emqx_ctl bridges start tts`
