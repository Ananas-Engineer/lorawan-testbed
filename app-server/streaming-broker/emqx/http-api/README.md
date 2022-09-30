1. Access Web interface of EMQX (port `18083`), go to Dashboard -> Plugin, click start the following fields to enable MQTT authentication and ACL:
    1. `emqx_auth_http`
    2. `emqx_auth_mnesia`
2. Generate system ACL.
```
node ./initialize_acl.js
```
