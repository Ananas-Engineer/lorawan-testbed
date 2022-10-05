# How to start EMQX?
1. [Start EMQX container](emqx/run/).
2. [Add backup file to EMQX](emqx/backup/).
2. [Start MQTT authentication and ACL](emqx/http-api/).
3. [Start MQTT Bridge to Network Server](tts-bridge/using-emqx-bridge/).
4. [Start Webhook to Web Server](emqx/conf/).
5. Install libraries needed for sub-processes.
```
npm install
```
6. Start the sub-processes including Preprocessor, DB-connector.
```
npm start
```
7. To stop all the sub-processes.
```
npm stop
```
