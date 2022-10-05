# Web Application

## Installation

- NodeJS
- NPM
- PostgreSQL

## Implementation

In this directory, to install all node modules on web application, run: `npm install`.

Go to `lorawan-testbed/app-server/streaming-broker` directory, run `npm install` again to install all node modules supporting streaming broker.

Make sure you did configure your web application in `lorawan-testbed/app-server/common/webapp.json` file.

To start the web application, run: `npm start`.

Now, your web application started. If your web application configuration file is:

```
{
    "SERVER_ADDR": "localhost",
    "SERVER_PORT": 80
}
```

then you can access your web application by this URL: `http://localhost:80`.

