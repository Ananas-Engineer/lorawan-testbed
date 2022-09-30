## How to run TTS locally?
1. Prepare installer. (Run once, or after changing `common/`)
```
node ./prepare-installer.js
```
2. Install. (Run once, or after changing `common/`)
```
bash ./install.sh
```
3. Start container.
```
docker-compose up -d
```

## How to add dev type uplink decoder?
1. Go to `tts/resources/dev-type/payload-formatter/`
2. Copy the JS script to the Payload formatters (Uplink) of corresponding end-devices on TTS Web interface.
