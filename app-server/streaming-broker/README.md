# How to start EMQX?
1. [Start EMQX container](emqx/run/).
2. [Add backup file to EMQX](emqx/backup/).
3. [Start MQTT authentication and ACL](emqx/http-api/).
4. [Start MQTT Bridge to Network Server](tts-bridge/using-emqx-bridge/).
5. [Start Webhook to Web Server](emqx/conf/).
6. Install libraries needed for sub-processes.
```
npm install
```
7. Start the sub-processes including Preprocessor, DB-connector.
```
npm start
```
8. To stop all the sub-processes.
```
npm stop
```
