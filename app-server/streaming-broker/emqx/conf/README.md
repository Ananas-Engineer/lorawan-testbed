## Start Webhook
1. Generate `emqx_web_hook.conf` 
```
node ./emqx_web_hook.js
```
2. Copy `emqx_web_hook.conf` to the container.
```
docker cp ./emqx_web_hook.conf <container_id>:/opt/emqx/etc/plugins
```
3. go to EMQX Dashboard -> Plugins -> start `emqx_web_hook`
