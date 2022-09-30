## How to backup file via HTTP API
This folder contains the latest backup file including configutations, rules, and many more.

### Import
```
curl -i --basic -u {ADMIN_USERNAME}:{ADMIN_PASSWORD} -X POST "http://{SERVER_ADDR}:8081/api/v4/data/import" -d @./emqx-export-{date}.json
```

### Export
1. Export data to the container storage, you will get a file name somethings like `emqx-export-{date}.json`.
```
curl -i --basic -u {ADMIN_USERNAME}:{ADMIN_PASSWORD} -X POST "http://{SERVER_ADDR}:8081/api/v4/data/export"
```
2. Download `emqx-export-{date}.json` to the current machine.
```
curl --basic -u {ADMIN_USERNAME}:{ADMIN_PASSWORD} -X GET http://{SERVER_ADDR}:8081/api/v4/data/file/emqx-export-{date}.json -o ./emqx-export-{date}.json
```
