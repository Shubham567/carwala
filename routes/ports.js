const express = require('express');
const router = express.Router();

const SerialPort = require("serialport");

// Get Port Listing
router.get('/', function(req, res, next) {
  SerialPort.list().then(list => {
    res.json(list);
  }).catch(err => {
    next(err);
  })
});

module.exports = router;
