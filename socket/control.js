const SerialPort = require("serialport");

SerialPort.parsers = {
  ByteLength: require('@serialport/parser-byte-length'),
  CCTalk: require('@serialport/parser-cctalk'),
  Delimiter: require('@serialport/parser-delimiter'),
  Readline: require('@serialport/parser-readline'),
  Ready: require('@serialport/parser-ready'),
  Regex: require('@serialport/parser-regex'),
}

const Readline = SerialPort.parsers.Readline;


const port = {};


function serialControlHandler(app,server) {

  const expressWs = require('express-ws')(app,server);

  app.ws('/echo', (ws,req) =>{
    console.log("Connecting to echo...");
    ws.on('message', msg => {
      console.log("Sending message: " + msg);
      ws.emit(msg);
    })
  })

  app.ws("/control/:id", async (ws, req) => {
    const id = req.params.id;

    console.log("Requesting control", id);

    try {
      const deviceList = await SerialPort.list();

      if(!port[id]){
        port[id] = new SerialPort(deviceList[id].path);
      }

      const parser = new Readline();

      port[id].pipe(parser);

      parser.on("data",ws.send);

      ws.on('message', msg => {
        console.log("Sending message: " + msg);
        port[id].write(msg);
      })


    }
    catch (e) {

    }

  })


}

module.exports = serialControlHandler;
