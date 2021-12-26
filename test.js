const SerialPort = require("serialport");

async function t() {
  const t = await SerialPort.list();
  console.log(t);
}
// SerialPort.list().then(res => console.log(res));
//
// console.log(list);

t();
